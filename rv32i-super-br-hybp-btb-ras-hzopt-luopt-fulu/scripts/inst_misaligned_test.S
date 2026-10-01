.option norvc
.section .text
.globl _start
_start:
    la t0, trap_handler
    csrw mtvec, t0

    # Slot 0 commits before the younger slot-1 JAL is replayed and trapped.
    .align 3
    addi s2, zero, 0x66
    .word 0x0020006f       # jal zero, +2: target is not 4-byte aligned
    addi s3, zero, 0x77
    addi s10, zero, 0x5a
1:
    jal zero, 1b

.align 2
trap_handler:
    csrr t0, mcause
    csrr t1, mtval
    csrr t2, mepc
    addi s4, t0, 0
    addi s5, t1, 0
    addi s6, t2, 0
    addi s8, s2, 0
    addi s9, s3, 0
    addi t2, t2, 4
    csrw mepc, t2
    mret
