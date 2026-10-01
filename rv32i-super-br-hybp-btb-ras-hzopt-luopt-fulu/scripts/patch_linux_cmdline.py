#!/usr/bin/env python3
"""Copy a prebuilt ELF and replace its fixed-length CONFIG_CMDLINE string."""
from __future__ import annotations

import argparse
from pathlib import Path


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("source", type=Path)
    parser.add_argument("output", type=Path)
    parser.add_argument("--match", required=True, help="exact old NUL-terminated command line")
    parser.add_argument("--replace", required=True, help="new command line (must fit the old string)")
    args = parser.parse_args()

    original = args.match.encode("ascii")
    replacement = args.replace.encode("ascii")
    image = bytearray(args.source.read_bytes())
    if len(replacement) > len(original):
        parser.error("replacement command line is longer than the matched string")
    needle = original + b"\0"
    locations = [i for i in range(len(image)) if image.startswith(needle, i)]
    if len(locations) != 1:
        parser.error(f"expected exactly one fixed kernel command line, found {len(locations)}")
    padded = replacement + (b" " * (len(original) - len(replacement))) + b"\0"
    image[locations[0]:locations[0] + len(needle)] = padded
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_bytes(image)
    print(f"Patched Linux command line in {args.output}: {args.replace}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
