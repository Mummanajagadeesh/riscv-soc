.option norvc
.section .text
.globl _start
_start:
    la t0, trap_handler
    csrw mtvec, t0

    # Unsupported CSR address: CSRRS with x0 requests a read only.
    .align 3
    .word 0x7c002573       # csrrs a0, 0x7c0, zero

    # The user counter alias is read-only: CSRRW x0 still attempts a write.
    .align 3
    .word 0xc0059073       # csrrw zero, cycle, a1

    addi s10, zero, 0x5a
1:
    jal zero, 1b

.align 2
trap_handler:
    csrr t0, mcause
    csrr t1, mtval
    csrr t2, mepc
    addi s0, s0, 1
    addi t3, zero, 1
    beq s0, t3, 2f
    addi s5, t0, 0
    addi s6, t1, 0
    addi s7, t2, 0
    jal zero, 3f
2:
    addi s2, t0, 0
    addi s3, t1, 0
    addi s4, t2, 0
3:
    addi t2, t2, 4
    csrw mepc, t2
    mret
