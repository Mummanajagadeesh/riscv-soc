`include "defines.v"

module tb_misaligned;
    reg clk;
    reg rst;
    wire [31:0] pc_debug;
    wire [31:0] instr_debug;
    wire [31:0] alu_result_debug;
    wire [31:0] mem_read_debug;
    wire halted;
    integer cycles;

    rv32i_top #(
        .INST_HEX("build/misaligned_inst.hex"),
        .DATA_HEX("build/misaligned_data.hex"),
        .ECALL_HALT(1'b0),
        .TRAP_MISALIGNED(1'b1)
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
            $fatal(1, "misaligned access test timed out: pc=%08x", pc_debug);
        if (uut.core.regs.rf[8] !== 32'd2)
            $fatal(1, "expected two misaligned access traps, count=%08x", uut.core.regs.rf[8]);
        if (uut.core.regs.rf[20] !== 32'd4 || uut.core.regs.rf[23] !== 32'd6)
            $fatal(1, "wrong load/store misalignment causes: load=%08x store=%08x",
                   uut.core.regs.rf[20], uut.core.regs.rf[23]);
        if (uut.core.regs.rf[21] !== 32'd1 || uut.core.regs.rf[24] !== 32'd1)
            $fatal(1, "misaligned effective address missing from mtval: load=%08x store=%08x",
                   uut.core.regs.rf[21], uut.core.regs.rf[24]);
        if ((uut.core.regs.rf[25] <= uut.core.regs.rf[22]) ||
            (uut.core.regs.rf[22][1:0] != 2'b00) || (uut.core.regs.rf[25][1:0] != 2'b00))
            $fatal(1, "misaligned trap EPC snapshots are not ordered/aligned: load=%08x store=%08x",
                   uut.core.regs.rf[22], uut.core.regs.rf[25]);
        if (uut.core.regs.rf[28] !== 32'b0)
            $fatal(1, "faulting misaligned load wrote its destination: x28=%08x", uut.core.regs.rf[28]);
        if (uut.core.regs.rf[18] !== 32'h0000_0066 || uut.core.regs.rf[27] !== 32'h0000_0066 ||
            uut.core.regs.rf[30] !== 32'b0)
            $fatal(1, "misaligned store was not precise: older/snapshot/younger=%08x/%08x/%08x",
                   uut.core.regs.rf[18], uut.core.regs.rf[27], uut.core.regs.rf[30]);
        if (uut.core.regs.rf[19] !== 32'h0000_0077)
            $fatal(1, "MRET did not resume at instruction after misaligned store: s3=%08x",
                   uut.core.regs.rf[19]);
        if (uut.core.csr_file.mcause !== 32'd6)
            $fatal(1, "final misaligned store cause not retained: mcause=%08x", uut.core.csr_file.mcause);
        if (uut.mem.dmem.mem[0] !== 32'b0)
            $fatal(1, "faulting misaligned store modified RAM: word0=%08x", uut.mem.dmem.mem[0]);
        if (uut.core.regs.rf[25] + 32'd4 !== uut.core.csr_file.mepc)
            $fatal(1, "MRET did not resume after the misaligned store: mepc=%08x saved EPC=%08x",
                   uut.core.csr_file.mepc, uut.core.regs.rf[25]);

        $display("PASS: load/store misalignment cause, mtval, EPC, older/younger effects (%0d cycles)", cycles);
        $finish;
    end
endmodule
