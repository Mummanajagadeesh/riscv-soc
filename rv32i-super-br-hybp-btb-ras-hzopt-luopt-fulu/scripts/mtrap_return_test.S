.option norvc
.section .text
.globl _start
_start:
    la t0, trap_handler
    csrw mtvec, t0
    addi t1, zero, 8
    csrs mstatus, t1

    # Align so s2 is the older slot-1 instruction and ECALL is slot 0 of the
    # following fetch pair. The handler must observe s2 committed, while s3
    # (the younger slot 1) must still be unchanged on trap entry.
    .align 3
    addi zero, zero, 0
    addi s2, zero, 0x66
    ecall
    addi s3, zero, 0x77
resume:
    addi s1, t2, 0      # preserve the first trap cause (11)
    ebreak               # second trap validates breakpoint cause (3)
after_ebreak:
    addi s0, zero, 0x5a
done:
    jal zero, done

.align 2
trap_handler:
    csrr t2, mcause
    csrr t3, mepc
    csrr t4, mstatus
    bne s5, zero, 1f
    addi s6, s3, 0       # snapshot: younger slot must not have executed yet
    addi s7, s2, 0       # snapshot: older instruction must be committed
    addi s5, s5, 1
1:
    addi t3, t3, 4
    csrw mepc, t3
    mret
