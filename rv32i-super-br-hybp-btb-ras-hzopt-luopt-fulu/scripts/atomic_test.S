.section .text
.globl _start
_start:
    addi s0, zero, 128
    addi t0, zero, 5
    sw   t0, 0(s0)

    lr.w t1, (s0)
    addi t2, zero, 7
    sc.w t3, t2, (s0)
    bne  t1, t0, fail
    bne  t3, zero, fail
    lw   t4, 0(s0)
    bne  t4, t2, fail

    amoadd.w t5, t0, (s0)      # rd=7, memory=12
    addi t6, zero, 7
    bne  t5, t6, fail
    lw   t4, 0(s0)
    addi t6, zero, 12
    bne  t4, t6, fail

    amoswap.w t5, t2, (s0)     # rd=12, memory=7
    bne  t5, t6, fail
    amoor.w t5, t0, (s0)       # rd=7, memory=7
    bne  t5, t2, fail
    amoand.w t5, t0, (s0)      # rd=7, memory=5
    bne  t5, t2, fail
    amoxor.w t5, t2, (s0)      # rd=5, memory=2
    addi t6, zero, 5
    bne  t5, t6, fail
    lw   t4, 0(s0)
    addi t6, zero, 2
    bne  t4, t6, fail

    # A successful LR followed by an intervening store invalidates reservation.
    lr.w t1, (s0)
    sw   t0, 4(s0)
    sc.w t3, t2, (s0)
    addi t6, zero, 1
    bne  t3, t6, fail

    addi a0, zero, 0x55
    ecall
fail:
    addi a0, zero, 0x7f
    ecall
1:  jal zero, 1b
