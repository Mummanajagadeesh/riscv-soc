.option norvc
.section .text
.globl _start
_start:
    la t0, trap_handler
    csrw mtvec, t0

    # Pair the older s2 write before the fault and s3 after it. The illegal
    # instruction is slot 0; its slot-1 younger write must be killed on entry.
    .align 3
    addi s2, zero, 0x66
    .word 0xffffffff
    addi s3, zero, 0x77
    addi s4, zero, 0x5a
1:
    jal zero, 1b

.align 2
trap_handler:
    csrr t0, mcause
    csrr t1, mtval
    csrr t2, mepc
    addi s8, s2, 0
    addi s9, s3, 0
    addi t3, t2, 4
    csrw mepc, t3
    mret
