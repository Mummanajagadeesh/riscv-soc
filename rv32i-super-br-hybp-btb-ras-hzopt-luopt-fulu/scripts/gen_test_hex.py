#!/usr/bin/env python3
"""
Generate RV32I instruction test program and expected final register values.

Outputs:
  - test_hex/inst_mem.hex
  - test_hex/data_mem.hex
  - test_hex/expected_final.txt   (format: reg,0xvalue)
"""

import os

INST_WORDS = 2048
DATA_WORDS = 2048


def mask32(v):
    return v & 0xFFFFFFFF


def sign_extend(value, bits):
    sign = 1 << (bits - 1)
    return (value & (sign - 1)) - (value & sign)


def r_type(rd, rs1, rs2, funct3, funct7=0x00):
    return ((funct7 & 0x7F) << 25) | ((rs2 & 0x1F) << 20) | ((rs1 & 0x1F) << 15) | ((funct3 & 0x7) << 12) | ((rd & 0x1F) << 7) | 0x33


def i_type(rd, rs1, imm, funct3, opcode=0x13):
    return ((imm & 0xFFF) << 20) | ((rs1 & 0x1F) << 15) | ((funct3 & 0x7) << 12) | ((rd & 0x1F) << 7) | (opcode & 0x7F)


def s_type(rs1, rs2, imm, funct3):
    imm &= 0xFFF
    return (((imm >> 5) & 0x7F) << 25) | ((rs2 & 0x1F) << 20) | ((rs1 & 0x1F) << 15) | ((funct3 & 0x7) << 12) | ((imm & 0x1F) << 7) | 0x23


def b_type(rs1, rs2, imm, funct3):
    imm &= 0x1FFF
    bit12 = (imm >> 12) & 1
    bit11 = (imm >> 11) & 1
    bits10_5 = (imm >> 5) & 0x3F
    bits4_1 = (imm >> 1) & 0xF
    return (bit12 << 31) | (bits10_5 << 25) | ((rs2 & 0x1F) << 20) | ((rs1 & 0x1F) << 15) | ((funct3 & 0x7) << 12) | (bits4_1 << 8) | (bit11 << 7) | 0x63


def u_type(rd, imm20, opcode):
    return ((imm20 & 0xFFFFF) << 12) | ((rd & 0x1F) << 7) | (opcode & 0x7F)


def j_type(rd, imm):
    imm &= 0x1FFFFF
    bit20 = (imm >> 20) & 1
    bits10_1 = (imm >> 1) & 0x3FF
    bit11 = (imm >> 11) & 1
    bits19_12 = (imm >> 12) & 0xFF
    return (bit20 << 31) | (bits10_1 << 21) | (bit11 << 20) | (bits19_12 << 12) | ((rd & 0x1F) << 7) | 0x6F


def ecall():
    return 0x00000073


def main():
    os.makedirs("test_hex", exist_ok=True)

    inst = []
    data = [0] * DATA_WORDS
    exp = {}

    def emit(word):
        inst.append(mask32(word))
        return len(inst) - 1

    emit(i_type(1, 0, 5, 0))
    emit(i_type(2, 0, 12, 0))
    emit(u_type(3, 0x80000, 0x37))
    emit(i_type(4, 0, -1, 0))
    emit(u_type(5, 0x12345, 0x37))
    emit(i_type(5, 5, 0x678, 0))
    emit(i_type(6, 0, 4, 0))

    emit(r_type(7, 1, 2, 0, 0x00))
    emit(r_type(8, 2, 1, 0, 0x20))
    emit(r_type(9, 1, 6, 1, 0x00))
    emit(r_type(10, 4, 1, 2, 0x00))
    emit(r_type(11, 4, 3, 3, 0x00))
    emit(r_type(12, 5, 4, 4, 0x00))
    emit(r_type(13, 5, 6, 5, 0x00))
    emit(r_type(14, 3, 6, 5, 0x20))
    emit(r_type(15, 1, 2, 6, 0x00))
    emit(r_type(16, 1, 2, 7, 0x00))

    emit(i_type(17, 1, -1, 0))
    emit(i_type(18, 4, 0, 2))
    emit(i_type(19, 1, 6, 3))
    emit(i_type(20, 1, 3, 4))
    emit(i_type(21, 1, 8, 6))
    emit(i_type(22, 5, 0x0FF, 7))
    emit(i_type(23, 1, 3, 1))
    emit(i_type(24, 5, 4, 5))
    emit(i_type(25, 3, (0x20 << 5) | 4, 5))

    emit(u_type(26, 0x22222, 0x37))
    auipc1_idx = emit(u_type(27, 0x00001, 0x17))

    emit(i_type(28, 0, 0x100, 0))
    emit(s_type(28, 5, 0, 2))
    emit(i_type(29, 28, 0, 2, opcode=0x03))
    emit(s_type(28, 4, 4, 1))
    emit(i_type(30, 28, 4, 1, opcode=0x03))
    emit(i_type(31, 28, 4, 5, opcode=0x03))
    emit(s_type(28, 1, 6, 0))
    emit(i_type(3, 28, 6, 0, opcode=0x03))
    emit(i_type(4, 28, 6, 4, opcode=0x03))

    emit(i_type(1, 0, 0, 0))
    emit(b_type(3, 4, 8, 0))
    emit(i_type(1, 0, 99, 0))
    emit(i_type(1, 0, 1, 0))

    emit(i_type(2, 0, 0, 0))
    emit(b_type(3, 5, 8, 1))
    emit(i_type(2, 0, 99, 0))
    emit(i_type(2, 0, 2, 0))

    emit(i_type(6, 0, 0, 0))
    emit(b_type(30, 3, 8, 4))
    emit(i_type(6, 0, 99, 0))
    emit(i_type(6, 0, 3, 0))

    emit(i_type(17, 0, 0, 0))
    emit(b_type(5, 3, 8, 5))
    emit(i_type(17, 0, 99, 0))
    emit(i_type(17, 0, 4, 0))

    emit(i_type(18, 0, 0, 0))
    emit(b_type(3, 5, 8, 6))
    emit(i_type(18, 0, 99, 0))
    emit(i_type(18, 0, 5, 0))

    emit(i_type(19, 0, 0, 0))
    emit(b_type(5, 3, 8, 7))
    emit(i_type(19, 0, 99, 0))
    emit(i_type(19, 0, 6, 0))

    jal_idx = emit(j_type(20, 8))
    emit(i_type(21, 0, 99, 0))
    emit(i_type(21, 0, 7, 0))

    auipc2_idx = emit(u_type(22, 0x00000, 0x17))
    emit(i_type(22, 22, 16, 0))
    jalr_idx = emit(i_type(23, 22, 0, 0, opcode=0x67))
    emit(i_type(24, 0, 99, 0))
    emit(i_type(24, 0, 8, 0))

    emit(ecall())

    while len(inst) < INST_WORDS:
        inst.append(0x00000013)

    exp[1] = 1
    exp[2] = 2
    exp[3] = 5
    exp[4] = 5
    exp[5] = 0x12345678
    exp[6] = 3
    exp[7] = 17
    exp[8] = 7
    exp[9] = 80
    exp[10] = 1
    exp[11] = 0
    exp[12] = 0xEDCBA987
    exp[13] = 0x01234567
    exp[14] = 0xF8000000
    exp[15] = 13
    exp[16] = 4
    exp[17] = 4
    exp[18] = 5
    exp[19] = 6
    exp[20] = mask32(jal_idx * 4 + 4)
    exp[21] = 7
    exp[22] = mask32(auipc2_idx * 4 + 16)
    exp[23] = mask32(jalr_idx * 4 + 4)
    exp[24] = 8
    exp[25] = 0xF8000000
    exp[26] = 0x22222000
    exp[27] = mask32(auipc1_idx * 4 + 0x1000)
    exp[28] = 0x00000100
    exp[29] = 0x12345678
    exp[30] = 0xFFFFFFFF
    exp[31] = 0x0000FFFF

    with open("test_hex/inst_mem.hex", "w", encoding="ascii") as f:
        for word in inst:
            f.write(f"{word:08x}\n")

    with open("test_hex/data_mem.hex", "w", encoding="ascii") as f:
        for word in data:
            f.write(f"{word:08x}\n")

    with open("test_hex/expected_final.txt", "w", encoding="ascii") as f:
        for reg in sorted(exp.keys()):
            f.write(f"{reg},0x{exp[reg] & 0xFFFFFFFF:08x}\n")

    print(f"Generated {len(inst)} instruction words")
    print(f"Generated {len(data)} data words")
    print(f"Generated {len(exp)} final checks")


if __name__ == "__main__":
    main()
