#!/usr/bin/env python3
"""Create sparse instruction/data RAM images for an RV32 no-MMU Linux ELF."""
from __future__ import annotations

import argparse
import struct
import subprocess
import sys
import tempfile
from pathlib import Path

from elf2hex import dump_section_bytes, parse_sections


def make_image(elf: Path, output: Path, base: int, words: int,
               code_only: bool, overlays: list[tuple[Path, int]] | None = None) -> int:
    limit = base + words * 4
    bytes_at: dict[int, int] = {}
    sections = parse_sections(str(elf))
    with tempfile.TemporaryDirectory(prefix="rv32-linux-image-") as td:
        for n, section in enumerate(sections):
            if section["size"] == 0 or "CONTENTS" not in section["flags"] or "ALLOC" not in section["flags"]:
                continue
            is_code = "CODE" in section["flags"] or section["name"].startswith((".text", ".head.text", ".init.text", ".exit.text"))
            if is_code != code_only:
                continue
            start = section["vma"]
            end = start + section["size"]
            if start < base or end > limit:
                raise ValueError(f"{section['name']} [{start:#x},{end:#x}) outside [{base:#x},{limit:#x})")
            path = Path(td) / f"sec-{n}.bin"
            payload = dump_section_bytes(str(elf), section["name"], str(path))
            for offset, byte in enumerate(payload):
                bytes_at[start - base + offset] = byte

    if overlays and not code_only:
        for path, address in overlays:
            payload = path.read_bytes()
            if address < base or address + len(payload) > limit:
                raise ValueError(f"overlay {path} outside RAM")
            for offset, byte in enumerate(payload):
                bytes_at[address - base + offset] = byte

    words_by_index: dict[int, bytearray] = {}
    for address, value in bytes_at.items():
        word = address >> 2
        if word not in words_by_index:
            words_by_index[word] = bytearray(4)
        words_by_index[word][address & 3] = value

    output.parent.mkdir(parents=True, exist_ok=True)
    with output.open("w", encoding="ascii") as stream:
        previous = -2
        for index in sorted(words_by_index):
            if index != previous + 1:
                stream.write(f"@{index:x}\n")
            stream.write(f"{struct.unpack('<I', words_by_index[index])[0]:08x}\n")
            previous = index
    return len(words_by_index)


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("elf", type=Path)
    parser.add_argument("inst_hex", type=Path)
    parser.add_argument("data_hex", type=Path)
    parser.add_argument("--base", type=lambda x: int(x, 0), default=0x80000000)
    parser.add_argument("--inst-words", type=int, default=1 << 20)
    parser.add_argument("--data-words", type=int, default=1 << 23)
    parser.add_argument("--overlay", type=Path)
    parser.add_argument("--overlay-addr", type=lambda x: int(x, 0), default=0x80300000)
    parser.add_argument("--initrd", type=Path)
    parser.add_argument("--initrd-addr", type=lambda x: int(x, 0), default=0x81000000)
    args = parser.parse_args()
    try:
        ic = make_image(args.elf, args.inst_hex, args.base, args.inst_words, True)
        overlays = []
        if args.overlay:
            overlays.append((args.overlay, args.overlay_addr))
        if args.initrd:
            overlays.append((args.initrd, args.initrd_addr))
        dc = make_image(args.elf, args.data_hex, args.base, args.data_words, False, overlays)
    except (OSError, ValueError, RuntimeError, subprocess.SubprocessError) as error:
        print(f"elf2linux_splithex: {error}", file=sys.stderr)
        return 1
    print(f"Wrote {ic} code words and {dc} data/DTB words at physical base {args.base:#x}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
