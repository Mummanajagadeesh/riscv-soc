#!/usr/bin/env python3
"""Create a sparse readmemh image from all allocated ELF sections."""
from __future__ import annotations

import argparse
import struct
import subprocess
import sys
import tempfile
from pathlib import Path

from elf2hex import dump_section_bytes, parse_sections


def make_image(elf: Path, output: Path, base: int, words: int) -> int:
    limit = base + words * 4
    bytes_at: dict[int, int] = {}
    sections = parse_sections(str(elf))
    with tempfile.TemporaryDirectory(prefix="rv32-unified-image-") as td:
        for number, section in enumerate(sections):
            if section["size"] == 0 or "CONTENTS" not in section["flags"] or "ALLOC" not in section["flags"]:
                continue
            start = section["vma"]
            end = start + section["size"]
            if start < base or end > limit:
                raise ValueError(
                    f"{section['name']} [{start:#x},{end:#x}) outside [{base:#x},{limit:#x})"
                )
            payload_path = Path(td) / f"section-{number}.bin"
            payload = dump_section_bytes(str(elf), section["name"], str(payload_path))
            for offset, value in enumerate(payload):
                address = start - base + offset
                previous = bytes_at.get(address)
                if previous is not None and previous != value:
                    raise ValueError(f"conflicting allocated bytes at {start + offset:#x}")
                bytes_at[address] = value

    words_by_index: dict[int, bytearray] = {}
    for address, value in bytes_at.items():
        index = address >> 2
        if index not in words_by_index:
            words_by_index[index] = bytearray(4)
        words_by_index[index][address & 3] = value

    output.parent.mkdir(parents=True, exist_ok=True)
    with output.open("w", encoding="ascii") as stream:
        previous_index = -2
        for index in sorted(words_by_index):
            if index != previous_index + 1:
                stream.write(f"@{index:x}\n")
            stream.write(f"{struct.unpack('<I', words_by_index[index])[0]:08x}\n")
            previous_index = index
    return len(words_by_index)


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("elf", type=Path)
    parser.add_argument("output", type=Path)
    parser.add_argument("--base", type=lambda value: int(value, 0), default=0x80000000)
    parser.add_argument("--words", type=int, default=1 << 20)
    args = parser.parse_args()
    try:
        count = make_image(args.elf, args.output, args.base, args.words)
    except (OSError, ValueError, RuntimeError, subprocess.SubprocessError) as error:
        print(f"elf2unifiedhex: {error}", file=sys.stderr)
        return 1
    print(f"Wrote {count} allocated words to unified image {args.output} at {args.base:#x}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
