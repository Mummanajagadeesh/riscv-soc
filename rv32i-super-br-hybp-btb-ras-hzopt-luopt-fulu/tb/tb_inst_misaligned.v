`include "defines.v"

module tb_inst_misaligned;
    reg clk;
    reg rst;
    wire [31:0] pc_debug;
    wire [31:0] instr_debug;
    wire [31:0] alu_result_debug;
    wire [31:0] mem_read_debug;
    wire halted;
    integer cycles;

    rv32i_top #(
        .INST_HEX("build/inst_misaligned_inst.hex"),
        .DATA_HEX("build/inst_misaligned_data.hex"),
        .ECALL_HALT(1'b0),
        .TRAP_INST_MISALIGNED(1'b1)
    ) uut (
        .clk(clk), .rst(rst), .pc_debug(pc_debug), .instr_debug(instr_debug),
        .alu_result_debug(alu_result_debug), .mem_read_debug(mem_read_debug),
        .halted(halted)
    );

    initial begin
        clk = 1'b0;
        forever #5 clk = ~clk;
    end

    always @(posedge clk) begin
        if (rst)
            cycles <= 0;
        else
            cycles <= cycles + 1;
    end

    initial begin
        rst = 1'b1;
        cycles = 0;
        #20 rst = 1'b0;
        while ((uut.core.regs.rf[26] !== 32'h0000_005a) && (cycles < 800))
            @(posedge clk);
        #10;

        if (uut.core.regs.rf[26] !== 32'h0000_005a)
            $fatal(1, "instruction-address misalignment test timed out: pc=%08x", pc_debug);
        if (uut.core.regs.rf[20] !== 32'd0)
            $fatal(1, "wrong instruction-address misalignment cause: %08x", uut.core.regs.rf[20]);
        if (uut.core.regs.rf[21] !== uut.core.regs.rf[22] + 32'd2)
            $fatal(1, "mtval does not contain misaligned target: mtval=%08x mepc=%08x",
                   uut.core.regs.rf[21], uut.core.regs.rf[22]);
        if (uut.core.regs.rf[22][1:0] !== 2'b00)
            $fatal(1, "faulting control-transfer EPC is not instruction-aligned: %08x", uut.core.regs.rf[22]);
        if (uut.core.regs.rf[18] !== 32'h0000_0066 || uut.core.regs.rf[24] !== 32'h0000_0066 ||
            uut.core.regs.rf[25] !== 32'b0)
            $fatal(1, "slot-1 instruction misalignment was not precise: older/snapshot/younger=%08x/%08x/%08x",
                   uut.core.regs.rf[18], uut.core.regs.rf[24], uut.core.regs.rf[25]);
        if (uut.core.regs.rf[19] !== 32'h0000_0077)
            $fatal(1, "MRET did not resume after faulting JAL: s3=%08x", uut.core.regs.rf[19]);
        if (uut.core.csr_file.mcause !== 32'd0 || uut.core.csr_file.mepc !== uut.core.regs.rf[22] + 32'd4)
            $fatal(1, "instruction misalignment trap state/MRET resume incorrect: mcause=%08x mepc=%08x",
                   uut.core.csr_file.mcause, uut.core.csr_file.mepc);

        $display("PASS: instruction target misalignment cause/mtval, precise slot ordering and MRET (%0d cycles)", cycles);
        $finish;
    end
endmodule
