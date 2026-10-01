.option norvc
.section .text
.globl _start
_start:
    la t0, trap_handler
    csrw mtvec, t0

    # Slot-0 misaligned word load must trap as cause 4 with mtval=1.
    .align 3
    lw t3, 1(zero)

    addi t1, zero, 0x5a
    # The older slot-0 write commits; the younger slot-1 misaligned store is
    # replayed to slot 0 and traps as cause 6. It must not alter RAM.
    .align 3
    addi s2, zero, 0x66
    sw t1, 1(zero)
    addi s3, zero, 0x77
    addi s10, zero, 0x5a
1:
    jal zero, 1b

.align 2
trap_handler:
    csrr t0, mcause
    csrr t1, mtval
    csrr t2, mepc
    addi s0, s0, 1
    addi t4, zero, 1
    beq s0, t4, 2f
    addi s7, t0, 0
    addi s8, t1, 0
    addi s9, t2, 0
    addi s11, s2, 0
    addi t5, s3, 0
    jal zero, 3f
2:
    addi s4, t0, 0
    addi s5, t1, 0
    addi s6, t2, 0
3:
    addi t2, t2, 4
    csrw mepc, t2
    mret
