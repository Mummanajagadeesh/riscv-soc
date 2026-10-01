`include "defines.v"

module tb_illegal;
    reg clk;
    reg rst;
    wire [31:0] pc_debug;
    wire [31:0] instr_debug;
    wire [31:0] alu_result_debug;
    wire [31:0] mem_read_debug;
    wire halted;
    integer cycles;

    rv32i_top #(
        .INST_HEX("build/illegal_inst.hex"),
        .DATA_HEX("build/illegal_data.hex"),
        .ECALL_HALT(1'b0)
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
        while ((uut.core.regs.rf[20] !== 32'h0000_005a) && (cycles < 500))
            @(posedge clk);
        #10;

        if (uut.core.regs.rf[20] !== 32'h0000_005a)
            $fatal(1, "illegal-instruction trap test timed out: pc=%08x", pc_debug);
        if (uut.core.regs.rf[5] !== 32'd2 || uut.core.csr_file.mcause !== 32'd2)
            $fatal(1, "wrong illegal-instruction cause: handler x5=%08x mcause=%08x",
                   uut.core.regs.rf[5], uut.core.csr_file.mcause);
        if (uut.core.regs.rf[6] !== 32'hffff_ffff ||
            uut.core.csr_file.mtval !== 32'hffff_ffff)
            $fatal(1, "illegal instruction was not reported in mtval: x6=%08x mtval=%08x",
                   uut.core.regs.rf[6], uut.core.csr_file.mtval);
        if (uut.core.regs.rf[24] !== 32'h0000_0066)
            $fatal(1, "older slot-1 result was lost before trap: snapshot=%08x", uut.core.regs.rf[24]);
        if (uut.core.regs.rf[25] !== 32'b0)
            $fatal(1, "younger slot-1 result committed before trap entry: snapshot=%08x", uut.core.regs.rf[25]);
        if (uut.core.regs.rf[19] !== 32'h0000_0077)
            $fatal(1, "MRET did not resume at instruction after fault: s3=%08x", uut.core.regs.rf[19]);
        if (uut.core.csr_file.mepc !== uut.core.regs.rf[7] + 32'd4)
            $fatal(1, "handler mepc advance was not retained: mepc=%08x original=%08x",
                   uut.core.csr_file.mepc, uut.core.regs.rf[7]);

        $display("PASS: illegal-instruction cause/mtval and precise older/younger slot handling (%0d cycles)", cycles);
        $finish;
    end
endmodule
