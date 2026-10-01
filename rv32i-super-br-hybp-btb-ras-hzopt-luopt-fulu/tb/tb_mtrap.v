`include "defines.v"

module tb_mtrap;
    reg clk;
    reg rst;
    wire [31:0] pc_debug;
    wire [31:0] instr_debug;
    wire [31:0] alu_result_debug;
    wire [31:0] mem_read_debug;
    wire halted;
    integer cycles;

    rv32i_top #(
        .INST_HEX("build/mtrap_inst.hex"),
        .DATA_HEX("build/mtrap_data.hex"),
        .ECALL_HALT(1'b0)
    ) uut (
        .clk(clk),
        .rst(rst),
        .pc_debug(pc_debug),
        .instr_debug(instr_debug),
        .alu_result_debug(alu_result_debug),
        .mem_read_debug(mem_read_debug),
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
        while ((uut.core.regs.rf[8] !== 32'h0000_005a) && (cycles < 500))
            @(posedge clk);
        #10;

        if (uut.core.regs.rf[8] !== 32'h0000_005a)
            $fatal(1, "M-mode trap/return timed out: pc=%08x x8=%08x", pc_debug, uut.core.regs.rf[8]);
        if (halted)
            $fatal(1, "ECALL halted instead of trapping in ECALL_HALT=0 mode");
        if (uut.core.regs.rf[9] !== 32'd11)
            $fatal(1, "first M-mode ECALL cause was not preserved in x9: %08x", uut.core.regs.rf[9]);
        if (uut.core.regs.rf[7] !== 32'd3)
            $fatal(1, "wrong M-mode EBREAK cause in x7: %08x", uut.core.regs.rf[7]);
        if (uut.core.regs.rf[22] !== 32'b0)
            $fatal(1, "younger slot executed before ECALL trap entry: s3 snapshot=%08x", uut.core.regs.rf[22]);
        if (uut.core.regs.rf[23] !== 32'h0000_0066)
            $fatal(1, "older slot-1 instruction was not committed before trap entry: s2 snapshot=%08x", uut.core.regs.rf[23]);
        if (uut.core.regs.rf[19] !== 32'h0000_0077)
            $fatal(1, "MRET did not resume at the instruction after ECALL: s3=%08x", uut.core.regs.rf[19]);
        if (uut.core.regs.rf[21] !== 32'd1)
            $fatal(1, "trap handler snapshot was unexpectedly overwritten: s5=%08x", uut.core.regs.rf[21]);
        if (uut.core.regs.rf[29] !== 32'h0000_1880)
            $fatal(1, "wrong trap-time mstatus snapshot in x29: %08x", uut.core.regs.rf[29]);
        if (uut.core.csr_file.mcause !== 32'd3)
            $fatal(1, "EBREAK mcause not retained: %08x", uut.core.csr_file.mcause);
        if (uut.core.csr_file.mepc !== uut.core.regs.rf[28])
            $fatal(1, "MRET did not resume from adjusted mepc: mepc=%08x x28=%08x",
                   uut.core.csr_file.mepc, uut.core.regs.rf[28]);
        if (uut.core.csr_file.privilege !== 2'b11)
            $fatal(1, "MRET did not restore M privilege: mode=%b", uut.core.csr_file.privilege);
        if (uut.core.csr_file.mstatus[3] !== 1'b1 ||
            uut.core.csr_file.mstatus[7] !== 1'b1 ||
            uut.core.csr_file.mstatus[12:11] !== 2'b00)
            $fatal(1, "MRET mstatus restore/cleanup incorrect: %08x", uut.core.csr_file.mstatus);

        $display("PASS: precise older/younger ECALL ordering, EBREAK, MRET and MIE restoration (%0d cycles)", cycles);
        $finish;
    end
endmodule
