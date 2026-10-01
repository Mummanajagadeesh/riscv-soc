#!/usr/bin/env python3
"""Run the public CoreMark validation workload on the dual-issue RTL."""
import argparse
import re
import shutil
import subprocess
import sys
from pathlib import Path

PASS_MARKER = 0xC0DECAFE
FAIL_MARKER = 0xBAD0BAD0
MAX_CYCLES = 50_000_000


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--elf", required=True)
    parser.add_argument("--sim", required=True)
    parser.add_argument("--data-words", type=int, required=True)
    parser.add_argument("--build-dir", default="build/coremark-rtl")
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
        subprocess.run(
            [sys.executable, "scripts/elf2hex.py", args.elf, str(inst_hex), str(data_hex),
             "--data-words", str(args.data_words)],
            cwd=root, check=True,
        )
        sim_log = build_dir / "sim.log"
        with sim_log.open("w") as log:
            subprocess.run(
                [args.sim, f"+max_cycles={MAX_CYCLES}"],
                cwd=root, check=True, stdout=log, stderr=subprocess.STDOUT,
            )
        result_copy = build_dir / "results.txt"
        shutil.copyfile(results, result_copy)
        text = result_copy.read_text()

        if "Halted:       YES (ecall)" not in text:
            raise RuntimeError(f"CoreMark did not reach its ECALL halt; see {sim_log}")
        if "Timed out:     NO" not in text:
            raise RuntimeError(f"CoreMark exceeded {MAX_CYCLES} cycles; see {sim_log}")

        window = text.split("OUTPUT WINDOW DUMP", 1)[1].split("DATA MEMORY DUMP", 1)[0]
        memory = {
            int(index): int(value, 16)
            for index, value in re.findall(r"mem\[(\d+)\].*= 0x([0-9a-fA-F]+)", window)
        }
        marker = memory.get(0x1FC // 4, 0)
        if marker != PASS_MARKER:
            if marker == FAIL_MARKER:
                reason = "CoreMark reported an internal CRC, type-size, timing, or seed validation error"
            else:
                reason = f"missing CoreMark success marker (got 0x{marker:08x})"
            raise RuntimeError(f"CoreMark validation failed: {reason}; see {result_copy}")

        cycles_match = re.search(r"Total cycles:\s+(\d+)", text)
        retired_match = re.search(r"Retired instructions:\s+(\d+)", text)
        cycles = cycles_match.group(1) if cycles_match else "unknown"
        retired = retired_match.group(1) if retired_match else "unknown"
        print(f"PASS CoreMark validation: marker=0x{marker:08x}, {cycles} cycles, {retired} retired instructions")
        print("Functional validation only: simulated ticks are not a reportable performance score.")
    finally:
        for path, contents in backups.items():
            path.write_bytes(contents)
        if not had_results:
            results.unlink(missing_ok=True)

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
