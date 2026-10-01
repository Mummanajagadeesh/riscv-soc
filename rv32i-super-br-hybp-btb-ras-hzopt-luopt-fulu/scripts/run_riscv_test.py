#!/usr/bin/env python3
import os
import sys
import subprocess

RISCV_PREFIX = "riscv64-unknown-elf-"
TEST_DIR = "/home/jagadeesh97/rv32i/rv32i-sc/test_hex"
RTL_DIR = "/home/jagadeesh97/rv32i/rv32i-sc/rtl"


def compile_test(elf_file, inst_hex, data_hex):
    sections = [".text.init", ".text"]

    inst_words = 0
    ih = open(inst_hex, "w")
    for sec in sections:
        try:
            subprocess.run(
                [
                    RISCV_PREFIX + "objcopy",
                    "-O",
                    "binary",
                    "-j",
                    sec,
                    elf_file,
                    "/tmp/rv_sec.bin",
                ],
                check=True,
                stderr=subprocess.DEVNULL,
            )
            if (
                os.path.exists("/tmp/rv_sec.bin")
                and os.path.getsize("/tmp/rv_sec.bin") > 0
            ):
                with open("/tmp/rv_sec.bin", "rb") as f:
                    data = f.read()
                for i in range(0, len(data), 4):
                    if i + 4 <= len(data):
                        word = int.from_bytes(data[i : i + 4], "little")
                        ih.write(f"{word:08x}\n")
                        inst_words += 1
        except:
            pass

    while inst_words < 2048:
        ih.write("00000000\n")
        inst_words += 1
    ih.close()

    data_words = 0
    dh = open(data_hex, "w")
    for sec in [".tohost", ".data"]:
        try:
            subprocess.run(
                [
                    RISCV_PREFIX + "objcopy",
                    "-O",
                    "binary",
                    "-j",
                    sec,
                    elf_file,
                    "/tmp/rv_sec.bin",
                ],
                check=True,
                stderr=subprocess.DEVNULL,
            )
            if (
                os.path.exists("/tmp/rv_sec.bin")
                and os.path.getsize("/tmp/rv_sec.bin") > 0
            ):
                with open("/tmp/rv_sec.bin", "rb") as f:
                    data = f.read()
                for i in range(0, len(data), 4):
                    if i + 4 <= len(data):
                        word = int.from_bytes(data[i : i + 4], "little")
                        dh.write(f"{word:08x}\n")
                        data_words += 1
        except:
            pass

    while data_words < 2048:
        dh.write("00000000\n")
        data_words += 1
    dh.close()

    return True


def run_simulation(inst_hex, data_hex):
    tb_content = f'''`include "defines.v"

module tb_run;
    reg         clk;
    reg         rst;
    wire [31:0] pc_debug;
    wire [31:0] instr_debug;
    wire [31:0] alu_result_debug;
    wire [31:0] mem_read_debug;
    wire        halted;

    integer cycle_count;

    rv32i_top #(
        .INST_HEX("{inst_hex}"),
        .DATA_HEX("{data_hex}"),
        .BASE_ADDR(32'h00000000)
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
        if (rst) cycle_count <= 0;
        else cycle_count <= cycle_count + 1;
    end

    initial begin
        rst = 1'b1;
        #20;
        rst = 1'b0;

        while (!halted && cycle_count < 10000) begin
            @(posedge clk);
        end
        #20;

        $display("RESULT: cycles=%0d pc=0x%08x halted=%s", cycle_count, pc_debug, halted ? "YES" : "NO");
        $finish;
    end
endmodule
'''
    with open("/tmp/tb_run.v", "w") as f:
        f.write(tb_content)

    compile_cmd = [
        "iverilog",
        "-g2005",
        "-o",
        "/tmp/tb_run.vvp",
        "/tmp/tb_run.v",
        f"{RTL_DIR}/top/rv32i_top.v",
        f"{RTL_DIR}/mem/mem_top.v",
        f"{RTL_DIR}/mem/inst_mem.v",
        f"{RTL_DIR}/mem/data_mem.v",
        f"{RTL_DIR}/core/core_top.v",
        f"{RTL_DIR}/core/alu.v",
        f"{RTL_DIR}/core/alu_ctrl.v",
        f"{RTL_DIR}/core/registers.v",
        f"{RTL_DIR}/core/imm_gen.v",
        f"{RTL_DIR}/core/branch_compare.v",
        f"{RTL_DIR}/core/pc_reg.v",
        f"{RTL_DIR}/core/control.v",
        f"{RTL_DIR}/core/csr_reg.v",
        f"{RTL_DIR}/../defines.v",
    ]

    result = subprocess.run(compile_cmd, capture_output=True, text=True)
    if result.returncode != 0:
        print(f"Compile error: {result.stderr}")
        return None

    result = subprocess.run(
        ["vvp", "/tmp/tb_run.vvp"], capture_output=True, text=True, timeout=30
    )
    return result.stdout + result.stderr


def run_single_test(test_name, test_elf):
    print(f"Compiling {test_name}...")
    inst_hex = f"{TEST_DIR}/test_{test_name}_inst.hex"
    data_hex = f"{TEST_DIR}/test_{test_name}_data.hex"

    if not compile_test(test_elf, inst_hex, data_hex):
        return False

    print(f"Running {test_name}...")
    output = run_simulation(inst_hex, data_hex)
    if output is None:
        return False

    if "halted=YES" in output:
        print(f"  PASS: {test_name}")
        return True
    else:
        print(f"  FAIL: {test_name}")
        for line in output.split("\n"):
            if "RESULT" in line:
                print(f"  {line}")
        return False


if __name__ == "__main__":
    if len(sys.argv) < 3:
        print("Usage: run_riscv_test.py <test_name> <test_elf>")
        sys.exit(1)

    test_name = sys.argv[1]
    test_elf = sys.argv[2]

    success = run_single_test(test_name, test_elf)
    sys.exit(0 if success else 1)
