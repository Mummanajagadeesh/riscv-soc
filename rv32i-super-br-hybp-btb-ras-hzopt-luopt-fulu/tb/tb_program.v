`include "defines.v"

module tb_program #(
    parameter DATA_WORD_COUNT = `DATA_MEM_WORDS
);

    reg         clk;
    reg         rst;
    wire [31:0] pc_debug;
    wire [31:0] instr_debug;
    wire [31:0] alu_result_debug;
    wire [31:0] mem_read_debug;
    wire        halted;

    integer cycle_count;
    integer instret_count;
    integer f;
    integer i;
    integer stable_pc_count;
    reg [31:0] last_pc;
    reg done;
    reg timed_out;
    localparam TRACE_EXEC = 1'b0;
    localparam DUMP_VCD   = 1'b0;
    integer max_cycles;
    integer progress_interval;
    reg     progress_enable;

    rv32i_top #(
        .INST_HEX("hex/inst_mem.hex"),
        .DATA_HEX("hex/data_mem.hex"),
        .DATA_WORD_COUNT(DATA_WORD_COUNT)
    ) uut (
        .clk(clk),
        .rst(rst),
        .pc_debug(pc_debug),
        .instr_debug(instr_debug),
        .alu_result_debug(alu_result_debug),
        .mem_read_debug(mem_read_debug),
        .halted(halted)
    );

    function [63:0] decode_mnemonic;
        input [31:0] instr;
        reg [6:0] opcode;
        reg [2:0] funct3;
        begin
            opcode = instr[6:0];
            funct3 = instr[14:12];
            case (opcode)
                7'b0110111: decode_mnemonic = "LUI     ";
                7'b0010111: decode_mnemonic = "AUIPC   ";
                7'b1101111: decode_mnemonic = "JAL     ";
                7'b1100111: decode_mnemonic = "JALR    ";
                7'b1100011: begin
                    case (funct3)
                        3'b000: decode_mnemonic = "BEQ     ";
                        3'b001: decode_mnemonic = "BNE     ";
                        3'b100: decode_mnemonic = "BLT     ";
                        3'b101: decode_mnemonic = "BGE     ";
                        3'b110: decode_mnemonic = "BLTU    ";
                        3'b111: decode_mnemonic = "BGEU    ";
                        default: decode_mnemonic = "BRANCH  ";
                    endcase
                end
                7'b0000011: begin
                    case (funct3)
                        3'b000: decode_mnemonic = "LB      ";
                        3'b001: decode_mnemonic = "LH      ";
                        3'b010: decode_mnemonic = "LW      ";
                        3'b100: decode_mnemonic = "LBU     ";
                        3'b101: decode_mnemonic = "LHU     ";
                        default: decode_mnemonic = "LOAD    ";
                    endcase
                end
                7'b0100011: begin
                    case (funct3)
                        3'b000: decode_mnemonic = "SB      ";
                        3'b001: decode_mnemonic = "SH      ";
                        3'b010: decode_mnemonic = "SW      ";
                        default: decode_mnemonic = "STORE   ";
                    endcase
                end
                7'b0010011: begin
                    case (funct3)
                        3'b000: decode_mnemonic = "ADDI    ";
                        3'b010: decode_mnemonic = "SLTI    ";
                        3'b011: decode_mnemonic = "SLTIU   ";
                        3'b100: decode_mnemonic = "XORI    ";
                        3'b110: decode_mnemonic = "ORI     ";
                        3'b111: decode_mnemonic = "ANDI    ";
                        3'b001: decode_mnemonic = "SLLI    ";
                        3'b101: decode_mnemonic = "SRLI/SRA";
                        default: decode_mnemonic = "OP-IMM  ";
                    endcase
                end
                7'b0110011: begin
                    case (funct3)
                        3'b000: decode_mnemonic = (instr[31:25]==7'b0100000) ? "SUB    " : "ADD    ";
                        3'b001: decode_mnemonic = "SLL    ";
                        3'b010: decode_mnemonic = "SLT    ";
                        3'b011: decode_mnemonic = "SLTU   ";
                        3'b100: decode_mnemonic = "XOR    ";
                        3'b101: decode_mnemonic = (instr[31:25]==7'b0100000) ? "SRA    " : "SRL    ";
                        3'b110: decode_mnemonic = "OR     ";
                        3'b111: decode_mnemonic = "AND    ";
                        default: decode_mnemonic = "OP     ";
                    endcase
                end
                7'b1110011: decode_mnemonic = (instr[31:20]==12'b0) ? "ECALL  " : "CSR    ";
                default: decode_mnemonic = "UNKWN   ";
            endcase
        end
    endfunction

    initial begin
        clk = 0;
        forever #5 clk = ~clk;
    end

    initial begin
        if (DUMP_VCD) begin
            $dumpfile("tb_program.vcd");
            $dumpvars(0, tb_program);
        end

        max_cycles = 2000000000;
        progress_interval = 0;
        progress_enable = 1'b0;
        if ($value$plusargs("max_cycles=%d", max_cycles)) begin
        end
        if ($value$plusargs("progress_interval=%d", progress_interval) && progress_interval > 0) begin
            progress_enable = 1'b1;
        end
    end

    always @(posedge clk) begin
        if (rst) begin
            cycle_count <= 0;
            instret_count <= 0;
        end else begin
            cycle_count <= cycle_count + 1;
            instret_count <= instret_count + (uut.core.mem_wb_valid0 ? 1 : 0) + (uut.core.mem_wb_valid1 ? 1 : 0);
            if (progress_enable && (cycle_count % progress_interval) == 0) begin
                $display("[PROGRESS] cyc=%0d pc=%08x halted=%0d", cycle_count, pc_debug, halted);
            end
        end
    end

    always @(posedge clk) begin
        if (TRACE_EXEC && !rst && !halted && cycle_count > 0) begin
            $display("[%4d] PC=%08x  %s  x%02d=0x%08x  x%02d=0x%08x",
                     cycle_count, pc_debug, decode_mnemonic(instr_debug),
                     instr_debug[19:15], uut.core.regs.rf[instr_debug[19:15]],
                     instr_debug[24:20], uut.core.regs.rf[instr_debug[24:20]]);
        end
    end

    initial begin
        rst = 1;
        done = 0;
        timed_out = 0;
        last_pc = 32'hffff_ffff;
        stable_pc_count = 0;
        #20;
        rst = 0;

        while (!done && cycle_count < max_cycles) begin
            @(posedge clk);
            if (!rst) begin
                if (pc_debug == last_pc) begin
                    stable_pc_count = stable_pc_count + 1;
                end else begin
                    stable_pc_count = 0;
                    last_pc = pc_debug;
                end

                if (halted || stable_pc_count > 32) begin
                    done = 1;
                end
            end
        end

        if (!done && cycle_count >= max_cycles) begin
            timed_out = 1;
        end
        #20;

        f = $fopen("tb_program_results.txt", "w");

        $fwrite(f, "============================================================\n");
        $fwrite(f, "         RV32I C-PROGRAM TEST RESULTS\n");
        $fwrite(f, "============================================================\n");
        $fwrite(f, "Total cycles: %0d\n", cycle_count);
        $fwrite(f, "Retired instructions: %0d\n", instret_count);
        $fwrite(f, "Final PC:     0x%08x\n", pc_debug);
        $fwrite(f, "Halted:       %s\n", halted ? "YES (ecall)" : "NO");
        $fwrite(f, "Timed out:    %s\n", timed_out ? "YES" : "NO");
        $fwrite(f, "Loop detected:%s\n", (!halted && done) ? " YES" : " NO");

        $fwrite(f, "\n============================================================\n");
        $fwrite(f, "              REGISTER FILE\n");
        $fwrite(f, "============================================================\n");
        $fwrite(f, "  x00=%08x    x01=%08x    x02=%08x    x03=%08x\n",
                uut.core.regs.rf[0], uut.core.regs.rf[1],
                uut.core.regs.rf[2], uut.core.regs.rf[3]);
        $fwrite(f, "  x04=%08x    x05=%08x    x06=%08x    x07=%08x\n",
                uut.core.regs.rf[4], uut.core.regs.rf[5],
                uut.core.regs.rf[6], uut.core.regs.rf[7]);
        $fwrite(f, "  x08=%08x    x09=%08x    x10=%08x    x11=%08x\n",
                uut.core.regs.rf[8], uut.core.regs.rf[9],
                uut.core.regs.rf[10], uut.core.regs.rf[11]);
        $fwrite(f, "  x12=%08x    x13=%08x    x14=%08x    x15=%08x\n",
                uut.core.regs.rf[12], uut.core.regs.rf[13],
                uut.core.regs.rf[14], uut.core.regs.rf[15]);
        $fwrite(f, "  x16=%08x    x17=%08x    x18=%08x    x19=%08x\n",
                uut.core.regs.rf[16], uut.core.regs.rf[17],
                uut.core.regs.rf[18], uut.core.regs.rf[19]);
        $fwrite(f, "  x20=%08x    x21=%08x    x22=%08x    x23=%08x\n",
                uut.core.regs.rf[20], uut.core.regs.rf[21],
                uut.core.regs.rf[22], uut.core.regs.rf[23]);
        $fwrite(f, "  x24=%08x    x25=%08x    x26=%08x    x27=%08x\n",
                uut.core.regs.rf[24], uut.core.regs.rf[25],
                uut.core.regs.rf[26], uut.core.regs.rf[27]);
        $fwrite(f, "  x28=%08x    x29=%08x    x30=%08x    x31=%08x\n",
                uut.core.regs.rf[28], uut.core.regs.rf[29],
                uut.core.regs.rf[30], uut.core.regs.rf[31]);

        $fwrite(f, "\n============================================================\n");
        $fwrite(f, "      OUTPUT WINDOW DUMP (word idx 64..127)\n");
        $fwrite(f, "============================================================\n");
        for (i = 64; i <= 127; i = i + 1) begin
            $fwrite(f, "  mem[%0d] @0x%08x = 0x%08x\n", i, i * 4, uut.mem.dmem.mem[i]);
        end

        $fwrite(f, "\n============================================================\n");
        $fwrite(f, "      DATA MEMORY DUMP (word idx 0..127, non-zero only)\n");
        $fwrite(f, "============================================================\n");
        for (i = 0; i < 128; i = i + 1) begin
            if (uut.mem.dmem.mem[i] != 32'b0) begin
                $fwrite(f, "  mem[%0d] @0x%08x = 0x%08x\n", i, i * 4, uut.mem.dmem.mem[i]);
            end
        end

        $fclose(f);

        $display("\n============================================================");
        $display("         RV32I C-PROGRAM TEST RESULTS");
        $display("============================================================");
        $display("Total cycles: %0d", cycle_count);
        $display("Retired instructions: %0d", instret_count);
        $display("Final PC:     0x%08x", pc_debug);
        $display("Halted:       %s", halted ? "YES (ecall)" : "NO");
        $display("Timed out:    %s", timed_out ? "YES" : "NO");
        $display("Loop detected:%s", (!halted && done) ? " YES" : " NO");
        $display("\nREGISTER SNAPSHOT:");
        $display("  x00=%08x x01=%08x x02=%08x x03=%08x", uut.core.regs.rf[0], uut.core.regs.rf[1], uut.core.regs.rf[2], uut.core.regs.rf[3]);
        $display("  x04=%08x x05=%08x x06=%08x x07=%08x", uut.core.regs.rf[4], uut.core.regs.rf[5], uut.core.regs.rf[6], uut.core.regs.rf[7]);
        $display("  x08=%08x x09=%08x x10=%08x x11=%08x", uut.core.regs.rf[8], uut.core.regs.rf[9], uut.core.regs.rf[10], uut.core.regs.rf[11]);
        $display("  x12=%08x x13=%08x x14=%08x x15=%08x", uut.core.regs.rf[12], uut.core.regs.rf[13], uut.core.regs.rf[14], uut.core.regs.rf[15]);
        $display("  x16=%08x x17=%08x x18=%08x x19=%08x", uut.core.regs.rf[16], uut.core.regs.rf[17], uut.core.regs.rf[18], uut.core.regs.rf[19]);
        $display("  x20=%08x x21=%08x x22=%08x x23=%08x", uut.core.regs.rf[20], uut.core.regs.rf[21], uut.core.regs.rf[22], uut.core.regs.rf[23]);
        $display("  x24=%08x x25=%08x x26=%08x x27=%08x", uut.core.regs.rf[24], uut.core.regs.rf[25], uut.core.regs.rf[26], uut.core.regs.rf[27]);
        $display("  x28=%08x x29=%08x x30=%08x x31=%08x", uut.core.regs.rf[28], uut.core.regs.rf[29], uut.core.regs.rf[30], uut.core.regs.rf[31]);

        $display("\nOUTPUT WINDOW (idx 64..127):");
        for (i = 64; i <= 127; i = i + 1) begin
            $display("  mem[%0d] @0x%08x = 0x%08x", i, i * 4, uut.mem.dmem.mem[i]);
        end

        $display("\nNON-ZERO DATA MEMORY (idx 0..127):");
        for (i = 0; i < 128; i = i + 1) begin
            if (uut.mem.dmem.mem[i] != 32'b0) begin
                $display("  mem[%0d] @0x%08x = 0x%08x", i, i * 4, uut.mem.dmem.mem[i]);
            end
        end
        $display("Full results written to tb_program_results.txt");
        $display("============================================================");

        $finish;
    end

endmodule
