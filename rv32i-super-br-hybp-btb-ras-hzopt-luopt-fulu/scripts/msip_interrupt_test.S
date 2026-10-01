.option norvc
.section .text
.globl _start
_start:
    la t0, trap_handler
    csrw mtvec, t0
    addi t1, zero, 8
    csrw mie, t1            # MSIE
    csrw mip, t1            # software-pend MSIP while global MIE is clear
    addi s0, zero, 0x11     # must execute before global enable
    la s6, interrupt_point
    addi t2, zero, 8
    csrw mstatus, t2        # enable M-mode global interrupts

interrupt_point:
    addi s1, zero, 1        # slot 0: must be held for the interrupt
    addi s7, zero, 0x77     # slot 1: must also be suppressed until MRET
    addi s5, zero, 0x5a
1:
    jal zero, 1b

.align 2
trap_handler:
    csrr s2, mcause
    csrr s3, mepc
    csrr s4, mstatus
    addi s8, s7, 0          # verify younger slot had no pre-trap side effect
    csrw mip, zero          # clear software interrupt pending state
    mret
