`timescale 1ns/1ps
module tb_linux_boot #(
    parameter integer LINUX_INST_WORDS = 8388608,
    parameter integer LINUX_RAM_WORDS = 8388608,
    parameter [31:0] LINUX_DTB_ADDR = 32'h8030_0000,
    parameter LINUX_TIMER_IRQ = 1'b1
);
    reg clk = 1'b0;
    reg rst = 1'b1;
    wire [31:0] pc_debug, instr_debug, alu_result_debug, mem_read_debug;
    wire halted;
    integer cycles;
    integer max_cycles;

    always #5 clk = ~clk;

    rv32i_top #(
        .INST_HEX("build/linux-boot/inst.hex"),
        .DATA_HEX("build/linux-boot/data.hex"),
        .BASE_ADDR(32'h8000_0000),
        .ECALL_HALT(1'b0),
        .TRAP_MISALIGNED(1'b0),
        .TRAP_INST_MISALIGNED(1'b1),
        .COHERENT_CODE_WRITES(1'b0),
        .UNIFIED_MEMORY(1'b1),
        .INST_WORD_COUNT(LINUX_INST_WORDS),
        .DATA_WORD_COUNT(LINUX_RAM_WORDS),
        .TIMER_IRQ_ENABLE(LINUX_TIMER_IRQ),
        .BOOT_A0(32'b0),
        .BOOT_A1(LINUX_DTB_ADDR)
    ) uut (
        .clk(clk), .rst(rst), .pc_debug(pc_debug), .instr_debug(instr_debug),
        .alu_result_debug(alu_result_debug), .mem_read_debug(mem_read_debug), .halted(halted)
    );

    initial begin
        max_cycles = 1000000;
        if ($value$plusargs("max_cycles=%d", max_cycles)) begin end
        repeat (8) @(posedge clk);
        @(negedge clk); rst = 1'b0;
        for (cycles = 0; cycles < max_cycles; cycles = cycles + 1) begin
            @(posedge clk);
            if ((cycles != 0) && ((cycles % 1000000) == 0))
                $display("[SIM PROGRESS] cycles=%0d pc=%08x", cycles, pc_debug);
            if (halted)
                $fatal(1, "Linux unexpectedly halted at pc=%08x", pc_debug);
        end
        $display("[SIM STOP] max_cycles=%0d pc=%08x gp=%08x sp=%08x cause=%08x epc=%08x mip=%08x mie=%08x timer=%b mtime=%016x cmp=%016x mstatus=%08x priv=%b", max_cycles, pc_debug, uut.core.regs.rf[3], uut.core.regs.rf[2], uut.core.csr_file.mcause, uut.core.csr_file.mepc, uut.core.machine_mip, uut.core.machine_mie, uut.timer_irq, uut.mem.clint_mtime, uut.mem.clint_mtimecmp, uut.core.machine_mstatus, uut.core.machine_privilege);
        $finish;
    end
endmodule
