.option norvc
.section .text
.globl _start
_start:
    addi t0, zero, 0x5a
    csrrw zero, mscratch, t0
    csrrs t1, mscratch, zero
    csrrw zero, mtvec, t0
    csrrs t2, mhartid, zero     # distinct implemented CSR must not alias mtvec
    addi zero, zero, 0          # allow the next CSR to exercise slot 1
    csrrwi t4, mscratch, 7     # slot-1 immediate source is zimm, not x7
    csrrs t5, mscratch, zero
    addi zero, zero, 0
    csrrsi zero, mscratch, 8   # slot 1: 7 -> 15
    addi zero, zero, 0
    csrrci zero, mscratch, 1   # slot 1: 15 -> 14
    csrrs t6, mscratch, zero
    addi t3, zero, 0x2a
    csrr s2, cycle
    csrr s3, time
    csrr s4, instret
    csrr s5, mcycle
    csrr s6, minstret
    csrr s7, cycleh
    csrr s8, instreth
    ecall
