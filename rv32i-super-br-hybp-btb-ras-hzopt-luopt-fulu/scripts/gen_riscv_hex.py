#!/usr/bin/env python3
"""
Generate RV32I instruction and data memory hex files from C source.
Uses riscv32-unknown-elf-gcc to compile and riscv64-unknown-elf-objcopy to extract.
"""

import subprocess
import sys
import os
import argparse
import struct

RISCV_PREFIX = os.environ.get('RISCV', 'riscv32-unknown-elf-')
CC = RISCV_PREFIX + 'gcc'
OBJCOPY = RISCV_PREFIX + 'objcopy'
OBJDUMP = RISCV_PREFIX + 'objdump'

INST_MEM_WORDS = 2048
DATA_MEM_WORDS = 2048

def compile_c(source_file, output_elf):
    """Compile C source to RISC-V ELF."""
    compile_cmd = [
        CC, '-march=rv32i', '-mabi=ilp32', '-nostdlib',
        '-fno-pic', '-fno-builtin', '-fno-stack-protector',
        '-o', output_elf, source_file
    ]

    link_cmd = [
        CC, '-march=rv32i', '-mabi=ilp32',
        '-nostdlib', '-nostartfiles',
        '-Wl,-Ttext=0x00000000',
        '-o', output_elf, source_file
    ]

    try:
        result = subprocess.run(link_cmd, capture_output=True, text=True)
        if result.returncode != 0:
            print(f"Compilation failed: {result.stderr}", file=sys.stderr)
            return False
        return True
    except FileNotFoundError:
        print(f"Error: {CC} not found. Install RISC-V toolchain.", file=sys.stderr)
        return False

def elf_to_hex(elf_file, inst_hex, data_hex):
    """Extract text and data sections from ELF to hex files."""
    with open(inst_hex, 'w') as ih, open(data_hex, 'w') as dh:
        ih.truncate(0)
        dh.truncate(0)

        for _ in range(INST_MEM_WORDS):
            ih.write("00000000\n")
        for _ in range(DATA_MEM_WORDS):
            dh.write("00000000\n")

    result = subprocess.run(
        [OBJCOPY, '-O', 'binary', '-j', '.text', '-j', '.data',
         elf_file, '/tmp/rv32i_binary.bin'],
        capture_output=True, text=True
    )

    if result.returncode != 0:
        print(f"objcopy failed: {result.stderr}", file=sys.stderr)
        return False

    with open('/tmp/rv32i_binary.bin', 'rb') as f:
        data = f.read()

    inst_words = INST_MEM_WORDS
    data_words = DATA_MEM_WORDS

    inst_bytes = min(len(data), inst_words * 4)
    data_bytes = min(max(len(data) - inst_bytes, 0), data_words * 4)

    inst_data = data[:inst_bytes]
    extra_data = data[inst_bytes:inst_bytes + data_bytes]

    with open(inst_hex, 'w') as ih:
        words_written = 0
        for i in range(0, inst_bytes, 4):
            if i + 4 <= len(inst_data):
                word = struct.unpack('<I', inst_data[i:i+4])[0]
                ih.write(f"{word:08x}\n")
                words_written += 1

        while words_written < inst_words:
            ih.write("00000000\n")
            words_written += 1

    with open(data_hex, 'w') as dh:
        for i in range(0, data_bytes, 4):
            if i + 4 <= len(extra_data):
                word = struct.unpack('<I', extra_data[i:i+4])[0]
                dh.write(f"{word:08x}\n")

    print(f"Generated {inst_hex} ({inst_bytes} bytes of code)")
    print(f"Generated {data_hex} ({data_bytes} bytes of data)")

    try:
        dump = subprocess.run(
            [OBJDUMP, '-d', elf_file],
            capture_output=True, text=True, timeout=10
        )
        if dump.returncode == 0:
            with open('disasm.txt', 'w') as df:
                df.write(dump.stdout)
            print("Disassembly saved to disasm.txt")
    except:
        pass

    return True

def main():
    parser = argparse.ArgumentParser(description='Compile C to RV32I hex files')
    parser.add_argument('source', help='C source file')
    parser.add_argument('-o', '--output', default='a.out', help='Output ELF file')
    parser.add_argument('--inst-hex', default='hex/inst_mem.hex',
                        help='Instruction memory hex output')
    parser.add_argument('--data-hex', default='hex/data_mem.hex',
                        help='Data memory hex output')
    parser.add_argument('--text-addr', type=lambda x: int(x, 0), default=0x00000000,
                        help='Text section address')
    args = parser.parse_args()

    os.makedirs(os.path.dirname(args.inst_hex) or 'hex', exist_ok=True)

    print(f"Compiling {args.source}...")
    if not compile_c(args.source, args.output):
        return 1

    print(f"Extracting sections to hex...")
    if not elf_to_hex(args.output, args.inst_hex, args.data_hex):
        return 1

    print("Done!")
    return 0

if __name__ == '__main__':
    sys.exit(main())
