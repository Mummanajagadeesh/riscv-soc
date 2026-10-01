`include "defines.v"

module tb_csr_legality;
    reg clk;
    reg rst;
    wire [31:0] pc_debug;
    wire [31:0] instr_debug;
    wire [31:0] alu_result_debug;
    wire [31:0] mem_read_debug;
    wire halted;
    integer cycles;

    rv32i_top #(
        .INST_HEX("build/csr_legality_inst.hex"),
        .DATA_HEX("build/csr_legality_data.hex"),
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
        while ((uut.core.regs.rf[26] !== 32'h0000_005a) && (cycles < 800))
            @(posedge clk);
        #10;

        if (uut.core.regs.rf[26] !== 32'h0000_005a)
            $fatal(1, "CSR legality test timed out: pc=%08x", pc_debug);
        if (uut.core.regs.rf[8] !== 32'd2)
            $fatal(1, "expected exactly two CSR legality traps, count=%08x", uut.core.regs.rf[8]);
        if (uut.core.regs.rf[18] !== 32'd2 || uut.core.regs.rf[21] !== 32'd2)
            $fatal(1, "CSR access faults did not report illegal-instruction cause 2: cause snapshots=%08x/%08x",
                   uut.core.regs.rf[18], uut.core.regs.rf[21]);
        if (uut.core.regs.rf[19] !== 32'h7c00_2573 || uut.core.regs.rf[22] !== 32'hc005_9073)
            $fatal(1, "CSR access faults did not preserve offending instruction in mtval: %08x/%08x",
                   uut.core.regs.rf[19], uut.core.regs.rf[22]);
        if (uut.core.regs.rf[20] !== uut.core.regs.rf[23] - 32'd8)
            $fatal(1, "CSR faulting PCs did not advance by one instruction: %08x/%08x",
                   uut.core.regs.rf[20], uut.core.regs.rf[23]);

        $display("PASS: unsupported/read-only CSR access traps, mtval, EPC progression (%0d cycles)", cycles);
        $finish;
    end
endmodule
