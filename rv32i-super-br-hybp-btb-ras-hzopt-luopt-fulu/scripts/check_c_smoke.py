#!/usr/bin/env python3
"""Assert architectural output from the small RV32 C smoke programs."""
import re
import sys
from pathlib import Path

EXPECTED = {
    "hello": {64: 0x1E, 65: 0x1},
    "fibonacci": {
        64: 0, 65: 1, 66: 1, 67: 2, 68: 3,
        69: 5, 70: 8, 71: 13, 72: 21, 73: 34,
    },
    "binary_search": {64: 4, 65: 7, 66: 0xFFFFFFFF, 67: 0, 68: 1},
}


def main() -> int:
    if len(sys.argv) != 3 or sys.argv[2] not in EXPECTED:
        print("Usage: check_c_smoke.py <tb_program_results.txt> <hello|fibonacci|binary_search>", file=sys.stderr)
        return 2

    result_path = Path(sys.argv[1])
    name = sys.argv[2]
    text = result_path.read_text()
    if "Halted:       YES (ecall)" not in text:
        raise SystemExit(f"FAIL {name}: did not halt via ECALL ({result_path})")
    if "Timed out:     NO" not in text:
        raise SystemExit(f"FAIL {name}: timed out ({result_path})")

    match = re.search(r"Total cycles:\s+(\d+)", text)
    if not match:
        raise SystemExit(f"FAIL {name}: missing cycle count ({result_path})")
    cycles = int(match.group(1))

    try:
        window = text.split("OUTPUT WINDOW DUMP", 1)[1].split("DATA MEMORY DUMP", 1)[0]
    except IndexError:
        raise SystemExit(f"FAIL {name}: output memory window is absent ({result_path})")
    values = {
        int(index): int(value, 16)
        for index, value in re.findall(r"mem\[(\d+)\].*= 0x([0-9a-fA-F]+)", window)
    }
    expected = EXPECTED[name]
    actual = {index: values.get(index) for index in expected}
    if actual != expected:
        formatted = {index: (f"0x{value:08x}" if value is not None else None) for index, value in actual.items()}
        raise SystemExit(f"FAIL {name}: output mismatch {formatted}; expected {expected}")

    print(f"PASS {name}: output values verified, ECALL halt, {cycles} cycles")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
