.option norvc
.section .text
.globl _start
_start:
    la t0, machine_handler
    csrw mtvec, t0
    la t0, supervisor_handler
    csrw stvec, t0
    addi t0, zero, 0x100     # delegate U-mode ECALL only
    csrw medeleg, t0
    la s6, user_ecall
    la t0, user_entry
    csrw mepc, t0
    csrw mstatus, zero      # MPP=U
    mret

user_entry:
    addi s8, zero, 0x18
user_ecall:
    ecall                   # delegated to S; handler will SRET into S code
    jal zero, fail_if_user_resumed

supervisor_sbi_call:
    addi s4, zero, 0x44
    ecall                   # S-mode ECALL is not delegated; enters M handler
supervisor_after_sbi:
    csrr s3, sstatus
    addi s5, zero, 0x55
1:
    jal zero, 1b

fail_if_user_resumed:
    addi s9, zero, 0x7f
    jal zero, fail_if_user_resumed

.align 2
supervisor_handler:
    csrr s0, scause
    csrr s1, sepc
    csrr s3, sstatus
    ori s3, s3, 0x100       # request SRET to S-mode, not U-mode
    csrw sstatus, s3
    la t0, supervisor_sbi_call
    csrw sepc, t0
    sret

.align 2
machine_handler:
    csrr s2, mcause
    csrr t0, mepc
    addi t0, t0, 4
    csrw mepc, t0
    mret
