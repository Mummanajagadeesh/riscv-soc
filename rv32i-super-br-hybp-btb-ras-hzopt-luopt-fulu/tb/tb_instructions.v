`include "defines.v"

module tb_instructions;

    reg         clk;
    reg         rst;
    wire [31:0] pc_debug;
    wire [31:0] instr_debug;
    wire [31:0] alu_result_debug;
    wire [31:0] mem_read_debug;
    wire        halted;

    integer cycle_count;
    integer passes;
    integer errors;
    integer fd;
    integer c;
    integer num_expected;
    integer idx;
    integer exp_reg_tmp;
    reg [31:0] exp_val_tmp;

    reg [4:0]  exp_reg [0:127];
    reg [31:0] exp_val [0:127];

    rv32i_top #(
        .INST_HEX("test_hex/inst_mem.hex"),
        .DATA_HEX("test_hex/data_mem.hex"),
        .COHERENT_CODE_WRITES(1'b0)
    ) uut (
        .clk(clk),
        .rst(rst),
        .pc_debug(pc_debug),
        .instr_debug(instr_debug),
        .alu_result_debug(alu_result_debug),
        .mem_read_debug(mem_read_debug),
        .halted(halted)
    );

    function [31:0] get_reg_value;
        input [4:0] reg_num;
        begin
            case (reg_num)
                0:  get_reg_value = uut.core.regs.rf[0];
                1:  get_reg_value = uut.core.regs.rf[1];
                2:  get_reg_value = uut.core.regs.rf[2];
                3:  get_reg_value = uut.core.regs.rf[3];
                4:  get_reg_value = uut.core.regs.rf[4];
                5:  get_reg_value = uut.core.regs.rf[5];
                6:  get_reg_value = uut.core.regs.rf[6];
                7:  get_reg_value = uut.core.regs.rf[7];
                8:  get_reg_value = uut.core.regs.rf[8];
                9:  get_reg_value = uut.core.regs.rf[9];
                10: get_reg_value = uut.core.regs.rf[10];
                11: get_reg_value = uut.core.regs.rf[11];
                12: get_reg_value = uut.core.regs.rf[12];
                13: get_reg_value = uut.core.regs.rf[13];
                14: get_reg_value = uut.core.regs.rf[14];
                15: get_reg_value = uut.core.regs.rf[15];
                16: get_reg_value = uut.core.regs.rf[16];
                17: get_reg_value = uut.core.regs.rf[17];
                18: get_reg_value = uut.core.regs.rf[18];
                19: get_reg_value = uut.core.regs.rf[19];
                20: get_reg_value = uut.core.regs.rf[20];
                21: get_reg_value = uut.core.regs.rf[21];
                22: get_reg_value = uut.core.regs.rf[22];
                23: get_reg_value = uut.core.regs.rf[23];
                24: get_reg_value = uut.core.regs.rf[24];
                25: get_reg_value = uut.core.regs.rf[25];
                26: get_reg_value = uut.core.regs.rf[26];
                27: get_reg_value = uut.core.regs.rf[27];
                28: get_reg_value = uut.core.regs.rf[28];
                29: get_reg_value = uut.core.regs.rf[29];
                30: get_reg_value = uut.core.regs.rf[30];
                31: get_reg_value = uut.core.regs.rf[31];
            endcase
        end
    endfunction

    task check_expected;
        input [4:0] reg_num;
        input [31:0] expected;
        reg [31:0] actual;
        begin
            actual = get_reg_value(reg_num);
            if (actual == expected) begin
                $display("  PASS  x%02d=0x%08x", reg_num, actual);
                passes = passes + 1;
            end else begin
                $display("  FAIL  x%02d: expected 0x%08x, got 0x%08x", reg_num, expected, actual);
                errors = errors + 1;
            end
        end
    endtask

    initial begin
        clk = 1'b0;
        forever #5 clk = ~clk;
    end

    initial begin
        $dumpfile("tb_instructions.vcd");
        $dumpvars(0, tb_instructions);
    end

    always @(posedge clk) begin
        if (rst) begin
            cycle_count <= 0;
        end else begin
            cycle_count <= cycle_count + 1;
        end
    end

    initial begin
        passes = 0;
        errors = 0;
        num_expected = 0;

        fd = $fopen("test_hex/expected_final.txt", "r");
        if (fd == 0) begin
            $display("ERROR: Could not open test_hex/expected_final.txt");
        end else begin
            // Read each record directly. Verilator's $fgets+$sscanf handling
            // of a packed line buffer differs from Icarus and used to load 0
            // checks while still exiting successfully.
            c = $fscanf(fd, "%d,0x%h\n", exp_reg_tmp, exp_val_tmp);
            while ((c == 2) && (num_expected < 128)) begin
                exp_reg[num_expected] = exp_reg_tmp[4:0];
                exp_val[num_expected] = exp_val_tmp;
                num_expected = num_expected + 1;
                c = $fscanf(fd, "%d,0x%h\n", exp_reg_tmp, exp_val_tmp);
            end
            $fclose(fd);
        end

        $display("Loaded %0d final register checks", num_expected);
    end

    initial begin
        rst = 1'b1;
        #20;
        rst = 1'b0;

        while (!halted && cycle_count < 2000) begin
            @(posedge clk);
        end
        #20;

        $display("\n============================================================");
        $display("         RV32I INSTRUCTION TEST RESULTS");
        $display("============================================================");
        $display("Cycles: %0d", cycle_count);
        $display("Final PC: 0x%08x", pc_debug);
        $display("Halted: %s", halted ? "YES" : "NO (timeout)");

        $display("\n============================================================");
        $display("         FINAL REGISTER CHECKS");
        $display("============================================================");
        for (idx = 0; idx < num_expected; idx = idx + 1) begin
            check_expected(exp_reg[idx], exp_val[idx]);
        end

        $display("\n============================================================");
        $display("         SUMMARY");
        $display("============================================================");
        $display("Total checks: %0d", passes + errors);
        $display("Passed: %0d", passes);
        $display("Failed: %0d", errors);
        if (!halted) begin
            $display("\n*** FAIL: PROGRAM DID NOT HALT WITH ECALL ***");
            $fatal(1, "instruction regression did not halt");
        end else if (num_expected == 0) begin
            $display("\n*** FAIL: NO EXPECTED REGISTER CHECKS WERE LOADED ***");
            $fatal(1, "instruction regression has no checks");
        end else if (errors != 0) begin
            $display("\n*** SOME TESTS FAILED ***");
            $fatal(1, "instruction regression failed %0d checks", errors);
        end else begin
            $display("\n*** ALL TESTS PASSED ***");
        end
        $display("============================================================");

        $finish;
    end
    

endmodule
