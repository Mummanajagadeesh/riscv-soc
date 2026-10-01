#!/usr/bin/env python3
import argparse
import pathlib
import re
import subprocess
import sys
import time


ROOT = pathlib.Path(__file__).resolve().parent.parent
SPIKE = pathlib.Path("/home/jagadeesh97/riscv/bin/spike")


def run(cmd, timeout=None, check=True):
    return subprocess.run(cmd, cwd=ROOT, timeout=timeout, check=check)


def run_capture(cmd, timeout=None, check=True):
    return subprocess.run(
        cmd,
        cwd=ROOT,
        timeout=timeout,
        check=check,
        text=True,
        stdout=subprocess.PIPE,
        stderr=subprocess.STDOUT,
    )


def parse_tb_output_window(path, base_idx, words):
    vals = [0] * words
    txt = path.read_text(encoding="ascii", errors="ignore").splitlines()
    pat = re.compile(r"mem\[(\d+)\]\s+@0x([0-9a-fA-F]+)\s+=\s+0x([0-9a-fA-F]{8})")
    for line in txt:
        m = pat.search(line)
        if not m:
            continue
        idx = int(m.group(1))
        if base_idx <= idx < base_idx + words:
            vals[idx - base_idx] = int(m.group(3), 16)
    return vals


def qemu_dump_words(elf, out_base, words, sleep_s):
    cmd = [
        "qemu-system-riscv32",
        "-machine",
        "spike",
        "-bios",
        "none",
        "-kernel",
        str(elf),
        "-monitor",
        "stdio",
        "-display",
        "none",
        "-serial",
        "none",
        "-S",
    ]
    p = subprocess.Popen(
        cmd,
        cwd=ROOT,
        stdin=subprocess.PIPE,
        stdout=subprocess.PIPE,
        stderr=subprocess.STDOUT,
        text=True,
    )

    p.stdin.write("c\n")
    p.stdin.flush()
    time.sleep(sleep_s)
    p.stdin.write("stop\n")
    p.stdin.write(f"xp /{words}wx 0x{out_base:08x}\n")
    p.stdin.write("q\n")
    p.stdin.flush()
    out, _ = p.communicate(timeout=20)

    vals = [0] * words
    line_pat = re.compile(r"([0-9a-fA-F]{16}):\s+(.*)$")
    for line in out.splitlines():
        m = line_pat.search(line)
        if not m:
            continue
        addr = int(m.group(1), 16)
        words_hex = re.findall(r"0x([0-9a-fA-F]{8})", m.group(2))
        for i, w in enumerate(words_hex):
            a = addr + 4 * i
            if out_base <= a < out_base + 4 * words:
                vals[(a - out_base) // 4] = int(w, 16)
    return vals


def spike_dump_words(elf, out_base, words, instr_limit):
    spike_log = ROOT / "spike_crosscheck.log"
    if spike_log.exists():
        spike_log.unlink()

    run(
        [
            str(SPIKE),
            "--isa=RV32I",
            "-m0x7fff0000:0x400000,0xffff0000:0x10000",
            "-l",
            "--log-commits",
            f"--log={spike_log}",
            f"--instructions={instr_limit}",
            str(elf),
        ],
        check=False,
        timeout=30,
    )

    vals = [0] * words
    pat = re.compile(r"mem\s+0x([0-9a-fA-F]+)\s+0x([0-9a-fA-F]+)")
    for line in spike_log.read_text(encoding="ascii", errors="ignore").splitlines():
        m = pat.search(line)
        if not m:
            continue
        addr = int(m.group(1), 16)
        if out_base <= addr < out_base + 4 * words:
            vals[(addr - out_base) // 4] = int(m.group(2), 16)
    return vals


def build_qemu_spike_elf(c_src, out_base_host):
    crt = ROOT / "scripts" / "crt0_qemu_spike.S"
    crt_o = ROOT / "crt0_qemu_spike.o"
    prog_o = ROOT / "crosscheck_prog.o"
    prog_elf = ROOT / "crosscheck_prog.elf"

    run(["riscv64-unknown-elf-gcc", "-march=rv32i", "-mabi=ilp32", "-c", str(crt), "-o", str(crt_o)])
    run(
        [
            "riscv64-unknown-elf-gcc",
            "-march=rv32i",
            "-mabi=ilp32",
            "-D_start=program_main",
            f"-DOUT_BASE=0x{out_base_host:08x}u",
            "-DHALT_INSN=\"ebreak\"",
            "-c",
            str(c_src),
            "-o",
            str(prog_o),
        ]
    )
    run(
        [
            "riscv64-unknown-elf-gcc",
            "-march=rv32i",
            "-mabi=ilp32",
            "-nostdlib",
            "-Ttext",
            "0x80000000",
            "-o",
            str(prog_elf),
            str(crt_o),
            str(prog_o),
        ]
    )
    return prog_elf


def main():
    ap = argparse.ArgumentParser(description="Cross-check RV32I TB vs QEMU vs Spike for any C file")
    ap.add_argument("c_file", help="Path to C source file")
    ap.add_argument("--words", type=int, default=16, help="Number of output words to compare")
    ap.add_argument("--rtl-out-base", type=lambda x: int(x, 0), default=0x100, help="Output base used by RTL run")
    ap.add_argument("--host-out-base", type=lambda x: int(x, 0), default=0x80002000, help="Output base used by QEMU/Spike run")
    args = ap.parse_args()

    c_src = (ROOT / args.c_file).resolve() if not pathlib.Path(args.c_file).is_absolute() else pathlib.Path(args.c_file)
    if not c_src.exists():
        print(f"ERROR: C file not found: {c_src}")
        return 2

    rtl_base_idx = args.rtl_out_base // 4

    # 1) Run processor RTL flow (generic TB)
    run(["make", "c-run", f"C_SRC={c_src}", "ELF=crosscheck_rtl.elf"], check=True, timeout=240)
    tb_res = ROOT / "tb_program_results.txt"
    rtl_vals = parse_tb_output_window(tb_res, rtl_base_idx, args.words)

    # 2) Build and run QEMU and Spike with host-friendly output base
    elf = build_qemu_spike_elf(c_src, args.host_out_base)
    qemu_vals = qemu_dump_words(elf, args.host_out_base, args.words, sleep_s=2.5)
    spike_vals = spike_dump_words(elf, args.host_out_base, args.words, instr_limit=400000)

    # 3) Compare raw dumps without program-specific expectations
    print("idx  rtl         qemu        spike       all_equal")
    mismatches = 0
    for i in range(args.words):
        r = rtl_vals[i]
        q = qemu_vals[i]
        s = spike_vals[i]
        ok = (r == q == s)
        if not ok:
            mismatches += 1
        print(f"{i:03d}  0x{r:08x}  0x{q:08x}  0x{s:08x}  {ok}")

    if mismatches == 0:
        print("PASS: RTL, QEMU, and Spike dumps match for all compared words")
        return 0

    print(f"FAIL: {mismatches} word(s) mismatch")
    return 1


if __name__ == "__main__":
    sys.exit(main())
