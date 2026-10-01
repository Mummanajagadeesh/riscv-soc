#!/usr/bin/env python3
"""Wrap a relocation-free RISC-V text image in a bFLT v4 header."""

from __future__ import annotations

import argparse
import struct
from pathlib import Path

HEADER_SIZE = 64
FLAT_VERSION = 4
FLAT_FLAG_RAM = 0x0001
DEFAULT_STACK_SIZE = 32 * 1024


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("text", type=Path, help="raw text image, with _start at offset zero")
    parser.add_argument("output", type=Path, help="output bFLT image")
    args = parser.parse_args()

    text = args.text.read_bytes()
    if not text:
        raise SystemExit("refusing to package an empty text image")
    data_start = HEADER_SIZE + len(text)
    # bFLT header words are network-byte-order. This smoke init has no data,
    # BSS, or relocations; PC-relative assembly makes it load-address independent.
    fields = (
        FLAT_VERSION,
        HEADER_SIZE,       # entry: first instruction immediately after header
        data_start,        # text length includes the 64-byte header
        data_start,        # no initialized data
        data_start,        # no BSS
        DEFAULT_STACK_SIZE,
        data_start,        # relocation table starts at EOF; relocation count is zero
        0,
        FLAT_FLAG_RAM,
        0,                 # build date
    )
    header = b"bFLT" + struct.pack(">10I", *fields) + bytes(20)
    assert len(header) == HEADER_SIZE
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_bytes(header + text)
    print(f"wrote {args.output}: text={len(text)} bytes, image={data_start} bytes")


if __name__ == "__main__":
    main()
