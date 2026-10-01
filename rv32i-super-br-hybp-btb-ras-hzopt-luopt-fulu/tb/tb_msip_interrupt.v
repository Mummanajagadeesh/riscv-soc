`include "defines.v"

module tb_msip_interrupt;
    reg clk;
    reg rst;
    wire [31:0] pc_debug;
    wire [31:0] instr_debug;
    wire [31:0] alu_result_debug;
    wire [31:0] mem_read_debug;
    wire halted;
    integer cycles;

    rv32i_top #(
        .INST_HEX("build/msip_interrupt_inst.hex"),
        .DATA_HEX("build/msip_interrupt_data.hex"),
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
        while ((uut.core.regs.rf[21] !== 32'h0000_005a) && (cycles < 800))
            @(posedge clk);
        #10;

        if (uut.core.regs.rf[21] !== 32'h0000_005a)
            $fatal(1, "MSIP interrupt test timed out: pc=%08x", pc_debug);
        if (uut.core.regs.rf[18] !== 32'h8000_0003)
            $fatal(1, "wrong machine software interrupt cause: mcause snapshot=%08x",
                   uut.core.regs.rf[18]);
        if (uut.core.regs.rf[19] !== uut.core.regs.rf[22])
            $fatal(1, "interrupt mepc did not identify the resumed instruction: mepc=%08x expected=%08x",
                   uut.core.regs.rf[19], uut.core.regs.rf[22]);
        if (uut.core.regs.rf[20] !== 32'h0000_1880)
            $fatal(1, "interrupt entry did not save MIE/MPP into mstatus: snapshot=%08x",
                   uut.core.regs.rf[20]);
        if (uut.core.regs.rf[24] !== 32'b0)
            $fatal(1, "younger slot committed before interrupt entry: snapshot=%08x", uut.core.regs.rf[24]);
        if (uut.core.regs.rf[8] !== 32'h0000_0011 || uut.core.regs.rf[9] !== 32'd1 ||
            uut.core.regs.rf[23] !== 32'h0000_0077)
            $fatal(1, "interrupt masking/resume or slot ordering failed: s0=%08x s1=%08x s7=%08x",
                   uut.core.regs.rf[8], uut.core.regs.rf[9], uut.core.regs.rf[23]);
        if (uut.core.csr_file.mcause !== 32'h8000_0003 ||
            uut.core.csr_file.mtval !== 32'b0 || uut.core.csr_file.mip[3] !== 1'b0)
            $fatal(1, "interrupt cause/value/pending state incorrect: mcause=%08x mtval=%08x mip=%08x",
                   uut.core.csr_file.mcause, uut.core.csr_file.mtval, uut.core.csr_file.mip);
        if (uut.core.csr_file.mepc !== uut.core.regs.rf[19] ||
            uut.core.csr_file.mstatus[3] !== 1'b1 || uut.core.csr_file.mstatus[7] !== 1'b1)
            $fatal(1, "MRET did not restore MIE/resume at interrupted PC: mepc=%08x mstatus=%08x",
                   uut.core.csr_file.mepc, uut.core.csr_file.mstatus);

        $display("PASS: MSIP enable/global mask, interrupt cause, precise entry and MRET (%0d cycles)", cycles);
        $finish;
    end
endmodule
