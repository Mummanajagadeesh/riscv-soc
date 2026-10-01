#!/usr/bin/env python3
"""Set the chosen-node initrd bounds in a compiled device tree."""
from __future__ import annotations

import argparse
import subprocess
from pathlib import Path


def cells(value: int) -> list[str]:
    return [f"{(value >> 32) & 0xffffffff:x}", f"{value & 0xffffffff:x}"]


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("dtb", type=Path)
    parser.add_argument("initrd", type=Path)
    parser.add_argument("--addr", type=lambda x: int(x, 0), required=True)
    args = parser.parse_args()
    start = args.addr
    end = start + args.initrd.stat().st_size
    for prop, value in (("linux,initrd-start", start), ("linux,initrd-end", end)):
        subprocess.run(["fdtput", "-t", "x", str(args.dtb), "/chosen", prop, *cells(value)], check=True)
    print(f"Set /chosen initrd range [{start:#x}, {end:#x}) from {args.initrd}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
