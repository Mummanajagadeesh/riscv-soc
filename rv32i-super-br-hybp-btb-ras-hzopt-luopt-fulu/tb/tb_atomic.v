`timescale 1ns/1ps
module tb_atomic;
    reg clk = 1'b0;
    reg rst = 1'b1;
    wire [31:0] pc_debug, instr_debug, alu_result_debug, mem_read_debug;
    wire halted;
    integer cycles;

    always #5 clk = ~clk;

    rv32i_top #(
        .INST_HEX("build/atomic/inst.hex"),
        .DATA_HEX("build/atomic/data.hex"),
        .BASE_ADDR(32'h0000_0000),
        .ECALL_HALT(1'b1),
        .INST_WORD_COUNT(4096),
        .DATA_WORD_COUNT(2048)
    ) uut (
        .clk(clk), .rst(rst), .pc_debug(pc_debug), .instr_debug(instr_debug),
        .alu_result_debug(alu_result_debug), .mem_read_debug(mem_read_debug), .halted(halted)
    );

    initial begin
        repeat (5) @(posedge clk);
        @(negedge clk); rst = 1'b0;
        for (cycles = 0; cycles < 4000; cycles = cycles + 1) begin
            @(posedge clk);
            if (halted) begin
                if (uut.core.regs.rf[10] !== 32'h0000_0055) begin
                    $display("REGS t0=%08x t1=%08x t2=%08x t3=%08x t4=%08x t5=%08x t6=%08x mem32=%08x mem33=%08x", uut.core.regs.rf[5], uut.core.regs.rf[6], uut.core.regs.rf[7], uut.core.regs.rf[28], uut.core.regs.rf[29], uut.core.regs.rf[30], uut.core.regs.rf[31], uut.mem.dmem.mem[32], uut.mem.dmem.mem[33]);
                    $fatal(1, "FAIL: atomic program returned %08x, expected 00000055", uut.core.regs.rf[10]);
                end
                if (uut.mem.dmem.mem[32] !== 32'h0000_0002)
                    $fatal(1, "FAIL: final AMO value %08x, expected 00000002", uut.mem.dmem.mem[32]);
                if (uut.mem.dmem.mem[33] !== 32'h0000_0005)
                    $fatal(1, "FAIL: intervening store was lost (%08x)", uut.mem.dmem.mem[33]);
                $display("PASS: dual-issue RV32A LR/SC and AMO operations");
                $finish;
            end
        end
        $fatal(1, "FAIL: atomic test timeout at pc=%08x", pc_debug);
    end
endmodule
