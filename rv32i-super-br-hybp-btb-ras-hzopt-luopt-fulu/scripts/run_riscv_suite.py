#!/usr/bin/env python3
"""Build and run the official RV32UI / RV32UM / RV32UA tests on the dual-issue RTL.

The test image is loaded at 0x80000000. The test environment reports completion
through the standard `tohost` word at 0x80001000; the simulation passes only for
`tohost == 1`, not merely because the core stopped or reached a stable PC.
"""
from __future__ import annotations

import argparse
import os
import re
import shlex
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
DEFAULT_REPO = ROOT.parent / "riscv-tests"
BUILD = ROOT / "build" / "riscv-tests"
MODEL = ROOT / "build" / "verilator" / "riscv-test"


def run(cmd: list[str], *, cwd: Path = ROOT, timeout: int = 120) -> subprocess.CompletedProcess[str]:
    return subprocess.run(cmd, cwd=cwd, text=True, stdout=subprocess.PIPE,
                          stderr=subprocess.STDOUT, timeout=timeout)


def build_model(verilator: list[str]) -> None:
    MODEL.mkdir(parents=True, exist_ok=True)
    cmd = verilator + [
        "--binary", "--timing", "-Wno-fatal", "-f", "tb/tb_riscv_test.f",
        "--Mdir", str(MODEL), "--top-module", "tb_riscv_test",
    ]
    proc = run(cmd, timeout=600)
    (BUILD / "verilator-build.log").write_text(proc.stdout, encoding="utf-8")
    if proc.returncode:
        raise RuntimeError(f"Verilator build failed; see {BUILD / 'verilator-build.log'}")


def find_tohost_index(nm: list[str], elf: Path) -> int:
    proc = run(nm + ["-n", str(elf)])
    if proc.returncode:
        raise RuntimeError(f"nm failed for {elf}: {proc.stdout.strip()}")
    for line in proc.stdout.splitlines():
        fields = line.split()
        if len(fields) >= 3 and fields[-1] == "tohost":
            address = int(fields[0], 16)
            offset = (address - 0x80000000) & 0xFFFFFFFF
            return offset >> 2
    raise RuntimeError(f"tohost symbol not found in {elf}")


def compile_test(cc: list[str], repo: Path, suite: str, name: str) -> Path:
    env_dir = repo / "env"
    src = repo / "isa" / suite / f"{name}.S"
    elf = BUILD / f"{suite}-{name}.elf"
    march = {
        "rv32ui": "rv32i_zicsr_zifencei",
        "rv32um": "rv32im_zicsr_zifencei",
        "rv32ua": "rv32ia_zicsr_zifencei",
    }[suite]
    cmd = cc + [
        f"-march={march}", "-mabi=ilp32", "-nostdlib", "-nostartfiles",
        "-static", "-Wl,--build-id=none", "-T", str(env_dir / "p" / "link.ld"),
        "-I", str(env_dir / "p"), "-I", str(env_dir),
        "-I", str(repo / "isa" / "macros" / "scalar"),
        "-o", str(elf), str(src),
    ]
    proc = run(cmd)
    if proc.returncode:
        (BUILD / f"{suite}-{name}-build.log").write_text(proc.stdout, encoding="utf-8")
        raise RuntimeError(f"{suite}/{name} compile failed; see {BUILD / f'{suite}-{name}-build.log'}")
    return elf


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--repo", type=Path, default=DEFAULT_REPO,
                        help=f"riscv-tests checkout (default: {DEFAULT_REPO})")
    parser.add_argument("--suite", choices=("all", "rv32ui", "rv32um", "rv32ua"), default="all")
    parser.add_argument("--max-cycles", type=int, default=1_000_000)
    parser.add_argument("--test", action="append", default=[],
                        help="run only this test name (repeatable; accepts NAME or suite/NAME)")
    args = parser.parse_args()

    repo = args.repo.resolve()
    if not (repo / "env" / "p" / "link.ld").is_file():
        print(f"missing test environment/linker script under {repo}; run git submodule update --init --recursive",
              file=sys.stderr)
        return 2
    BUILD.mkdir(parents=True, exist_ok=True)
    cc = shlex.split(os.environ.get("RISCV_GCC", "riscv64-unknown-elf-gcc"))
    nm = shlex.split(os.environ.get("RISCV_NM", "riscv64-unknown-elf-nm"))
    verilator = shlex.split(os.environ.get("VERILATOR", "verilator"))
    suites = ("rv32ui", "rv32um", "rv32ua") if args.suite == "all" else (args.suite,)

    try:
        build_model(verilator)
    except (RuntimeError, subprocess.TimeoutExpired) as exc:
        print(exc, file=sys.stderr)
        return 2

    executable = MODEL / "Vtb_riscv_test"
    results: list[tuple[str, bool, str]] = []
    for suite in suites:
        names = sorted(p.stem for p in (repo / "isa" / suite).glob("*.S"))
        if args.test:
            names = [n for n in names if n in args.test or f"{suite}/{n}" in args.test]
        for name in names:
            test_name = f"{suite}/{name}"
            try:
                elf = compile_test(cc, repo, suite, name)
                tohost_index = find_tohost_index(nm, elf)
                convert = run([sys.executable, str(ROOT / "scripts" / "elf2unifiedhex.py"),
                               str(elf), "build/riscv_test_unified.hex",
                               "--base", "0x80000000", "--words", "4096"])
                if convert.returncode:
                    raise RuntimeError(convert.stdout.strip())
                sim = run([str(executable), f"+max_cycles={args.max_cycles}",
                           f"+tohost_index={tohost_index}"], timeout=60)
                match = re.search(r"PASS: RISC-V test signaled tohost=1 \((\d+) cycles\)", sim.stdout)
                passed = sim.returncode == 0 and match is not None
                detail = f"{match.group(1)} cycles" if match else "" 
                if not passed:
                    lines = sim.stdout.strip().splitlines()
                    detail = next((line.strip() for line in reversed(lines)
                                   if "%Fatal:" in line),
                                  next((line.strip() for line in reversed(lines)
                                        if "%Error:" in line),
                                       lines[-1] if lines else f"exit={sim.returncode}"))
                    (BUILD / f"{suite}-{name}-sim.log").write_text(sim.stdout, encoding="utf-8")
                results.append((test_name, passed, detail))
                print(f"{'PASS' if passed else 'FAIL'} {test_name:<18} {detail}", flush=True)
            except (RuntimeError, subprocess.TimeoutExpired, OSError) as exc:
                results.append((test_name, False, str(exc)))
                print(f"FAIL {test_name:<18} {exc}", flush=True)

    passed_count = sum(passed for _, passed, _ in results)
    print(f"\nRISC-V test summary: {passed_count}/{len(results)} passed")
    if passed_count != len(results):
        print("Failed tests:")
        for name, passed, detail in results:
            if not passed:
                print(f"  {name}: {detail}")
        return 1
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
