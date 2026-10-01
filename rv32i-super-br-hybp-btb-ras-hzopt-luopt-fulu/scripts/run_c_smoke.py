#!/usr/bin/env python3
"""Build/run the small RV32 C smoke programs and verify their output words."""
import argparse
import shutil
import subprocess
import sys
from pathlib import Path


PROGRAMS = ("hello", "fibonacci", "binary_search")


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--gcc", default="riscv64-unknown-elf-gcc")
    parser.add_argument("--sim", default="build/verilator/program/Vtb_program")
    parser.add_argument("--build-dir", default="build/c-smoke")
    args = parser.parse_args()

    root = Path.cwd()
    build_dir = (root / args.build_dir).resolve()
    build_dir.mkdir(parents=True, exist_ok=True)
    inst_hex = root / "hex/inst_mem.hex"
    data_hex = root / "hex/data_mem.hex"
    results = root / "tb_program_results.txt"
    backups = {inst_hex: inst_hex.read_bytes(), data_hex: data_hex.read_bytes()}
    had_results = results.exists()
    if had_results:
        backups[results] = results.read_bytes()

    try:
        for name in PROGRAMS:
            elf = build_dir / f"{name}.elf"
            result_copy = build_dir / f"{name}-results.txt"
            sim_log = build_dir / f"{name}-sim.log"
            subprocess.run(
                [args.gcc, "-march=rv32i", "-mabi=ilp32", "-nostdlib", "-Ttext=0",
                 "-o", str(elf), f"scripts/{name}.c"],
                cwd=root, check=True,
            )
            subprocess.run(
                [sys.executable, "scripts/elf2hex.py", str(elf), str(inst_hex), str(data_hex)],
                cwd=root, check=True, stdout=subprocess.DEVNULL,
            )
            with sim_log.open("w") as log:
                subprocess.run([args.sim], cwd=root, check=True, stdout=log, stderr=subprocess.STDOUT)
            shutil.copyfile(results, result_copy)
            subprocess.run(
                [sys.executable, "scripts/check_c_smoke.py", str(result_copy), name],
                cwd=root, check=True,
            )
    finally:
        for path, contents in backups.items():
            path.write_bytes(contents)
        if not had_results:
            results.unlink(missing_ok=True)

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
