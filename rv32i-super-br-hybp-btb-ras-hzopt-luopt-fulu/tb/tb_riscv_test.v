`include "defines.v"

module tb_riscv_test;
    reg clk;
    reg rst;
    wire [31:0] pc_debug;
    wire [31:0] instr_debug;
    wire [31:0] alu_result_debug;
    wire [31:0] mem_read_debug;
    wire halted;
    integer cycles;
    integer max_cycles;
    integer tohost_index;

    rv32i_top #(
        .INST_HEX("build/riscv_test_unified.hex"),
        .DATA_HEX("build/riscv_test_unified.hex"),
        .BASE_ADDR(32'h8000_0000),
        .ECALL_HALT(1'b0),
        .COHERENT_CODE_WRITES(1'b0),
        .UNIFIED_MEMORY(1'b1),
        .INST_WORD_COUNT(4096),
        .DATA_WORD_COUNT(4096)
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
        else begin
            cycles <= cycles + 1;
            if ($test$plusargs("trace_pipe") && (cycles >= 50) && (cycles <= 105))
                $display("PIPE c=%0d fetch=%08x ID0=%08x/%08x v%0d ID1=%08x/%08x v%0d EX0=%08x wr%0d EX1=%08x wr%0d",
                         cycles, pc_debug, uut.core.if_id_pc0, uut.core.if_id_instr0, uut.core.if_id_valid0,
                         uut.core.if_id_pc1, uut.core.if_id_instr1, uut.core.if_id_valid1,
                         uut.core.id_ex_pc0, uut.core.id_ex_mem_write0,
                         uut.core.id_ex_pc1, uut.core.id_ex_mem_write1);
            if ($test$plusargs("trace_mem")) begin
                if (uut.core.mem_write0)
                    $display("STORE s0 cycle=%0d addr=%08x data=%08x size=%b", cycles, uut.core.mem_addr0, uut.core.mem_wdata0, uut.core.mem_funct30);
                if (uut.core.mem_write1)
                    $display("STORE s1 cycle=%0d addr=%08x data=%08x size=%b", cycles, uut.core.mem_addr1, uut.core.mem_wdata1, uut.core.mem_funct31);
            end
        end
    end

    initial begin
        rst = 1'b1;
        cycles = 0;
        max_cycles = 100000;
        tohost_index = 1024;
        if ($value$plusargs("max_cycles=%d", max_cycles)) begin end
        if ($value$plusargs("tohost_index=%d", tohost_index)) begin end
        #20 rst = 1'b0;

        while ((uut.mem.dmem.mem[tohost_index] === 32'b0) && !halted && (cycles < max_cycles))
            @(posedge clk);
        #10;

        if (halted)
            $fatal(1, "unexpected ECALL halt before tohost; pc=%08x", pc_debug);
        if (uut.mem.dmem.mem[tohost_index] === 32'b0)
            $fatal(1, "timed out waiting for tohost; pc=%08x cycles=%0d", pc_debug, cycles);
        if (uut.mem.dmem.mem[tohost_index] !== 32'd1) begin
            $display("registers: gp=%08x ra=%08x a4=%08x t2=%08x",
                     uut.core.regs.rf[3], uut.core.regs.rf[1],
                     uut.core.regs.rf[14], uut.core.regs.rf[7]);
            $fatal(1, "test failed: tohost=%08x index=%0d pc=%08x cycles=%0d",
                   uut.mem.dmem.mem[tohost_index], tohost_index, pc_debug, cycles);
        end

        $display("PASS: RISC-V test signaled tohost=1 (%0d cycles)", cycles);
        $finish;
    end
endmodule
