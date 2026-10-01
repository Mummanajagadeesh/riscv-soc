#!/usr/bin/env python3
import os
import re
import struct
import subprocess
import sys
import tempfile
import shutil

INST_WORDS = 4096
DATA_WORDS = 2048


def find_riscv_tool(tool):
    """Find a RISC-V binutils command across common distro prefixes.

    RISCV_OBJDUMP / RISCV_OBJCOPY may select an exact executable, or
    RISCV_PREFIX may select a toolchain prefix. Debian's cross packages use
    riscv64-unknown-elf-* even for ELF32 RV32 binaries.
    """
    env_name = "RISCV_" + tool.upper()
    explicit = os.environ.get(env_name)
    if explicit:
        if shutil.which(explicit):
            return explicit
        raise FileNotFoundError(f"{env_name}={explicit!r} was not found on PATH")

    prefix = os.environ.get("RISCV_PREFIX")
    prefixes = [prefix] if prefix else [
        "riscv32-unknown-elf-",
        "riscv64-unknown-elf-",
        "riscv64-linux-gnu-",
    ]
    for candidate_prefix in prefixes:
        candidate = candidate_prefix + tool
        if shutil.which(candidate):
            return candidate
    tried = ", ".join(p + tool for p in prefixes)
    raise FileNotFoundError(f"could not find RISC-V {tool}; tried: {tried}")


def parse_sections(elf_file):
    out = subprocess.check_output([find_riscv_tool("objdump"), "-h", elf_file], text=True)
    sections = []
    pending = None

    header_re = re.compile(
        r"^\s*(\d+)\s+(\S+)\s+([0-9a-fA-F]+)\s+([0-9a-fA-F]+)\s+"
        r"([0-9a-fA-F]+)\s+([0-9a-fA-F]+)\s+2\*\*(\d+)"
    )

    for line in out.splitlines():
        m = header_re.match(line)
        if m:
            pending = {
                "name": m.group(2),
                "size": int(m.group(3), 16),
                "vma": int(m.group(4), 16),
                "lma": int(m.group(5), 16),
                "file_off": int(m.group(6), 16),
                "flags": "",
            }
            continue

        if pending is not None:
            flags = line.strip()
            if flags:
                pending["flags"] = flags
                sections.append(pending)
                pending = None

    return sections


def dump_section_bytes(elf_file, section_name, out_path):
    subprocess.run(
        [find_riscv_tool("objcopy"), "--dump-section", f"{section_name}={out_path}", elf_file],
        check=True,
        stdout=subprocess.DEVNULL,
        stderr=subprocess.DEVNULL,
    )
    with open(out_path, "rb") as f:
        return f.read()


def place_bytes(memory, base_addr, payload):
    mem_size = len(memory)
    for i, b in enumerate(payload):
        memory[(base_addr + i) % mem_size] = b


def write_hex_words(path, memory, words):
    with open(path, "w") as f:
        for i in range(words):
            b0 = memory[i * 4 + 0]
            b1 = memory[i * 4 + 1]
            b2 = memory[i * 4 + 2]
            b3 = memory[i * 4 + 3]
            word = struct.unpack("<I", bytes([b0, b1, b2, b3]))[0]
            f.write(f"{word:08x}\n")


def elf_to_hex(elf_file, inst_hex, data_hex, data_words=DATA_WORDS):
    try:
        sections = parse_sections(elf_file)
    except Exception as e:
        print(f"Error parsing sections: {e}", file=sys.stderr)
        return False

    inst_mem = bytearray(INST_WORDS * 4)
    if data_words <= 0:
        print(f"Invalid data memory size: {data_words} words", file=sys.stderr)
        return False
    data_mem = bytearray(data_words * 4)

    # Mirror initialized data sections into the fetch image as well. This
    # supports the architectural case where code is placed in writable data
    # and then executed after a FENCE.I (for example, the official test).
    inst_prefixes = (".text", ".rodata", ".data", ".sdata")
    data_prefixes = (".data", ".sdata", ".rodata")

    try:
        with tempfile.TemporaryDirectory(prefix="elf2hex_") as td:
            for sec in sections:
                if sec["size"] == 0:
                    continue
                if "CONTENTS" not in sec["flags"]:
                    continue

                name = sec["name"]
                sec_file = os.path.join(td, f"{name.replace('/', '_')}.bin")
                payload = dump_section_bytes(elf_file, name, sec_file)

                if name.startswith(inst_prefixes):
                    place_bytes(inst_mem, sec["vma"], payload)

                if name.startswith(data_prefixes):
                    place_bytes(data_mem, sec["vma"], payload)
    except Exception as e:
        print(f"Error dumping/placing sections: {e}", file=sys.stderr)
        return False

    write_hex_words(inst_hex, inst_mem, INST_WORDS)
    write_hex_words(data_hex, data_mem, data_words)

    print(f"Generated {inst_hex} ({INST_WORDS} instruction words)")
    print(f"Generated {data_hex} ({data_words} data words)")
    return True


if __name__ == "__main__":
    if len(sys.argv) not in (4, 6) or (len(sys.argv) == 6 and sys.argv[4] != "--data-words"):
        print("Usage: elf2hex.py <elf_file> <inst_hex> <data_hex> [--data-words N]")
        sys.exit(1)
    data_words = int(sys.argv[5]) if len(sys.argv) == 6 else DATA_WORDS
    ok = elf_to_hex(sys.argv[1], sys.argv[2], sys.argv[3], data_words)
    if not ok:
        sys.exit(1)
