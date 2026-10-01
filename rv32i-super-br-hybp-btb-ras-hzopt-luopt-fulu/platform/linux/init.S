.option norvc
.section .text.start,"ax",@progbits
.globl _start
.type _start,@function
_start:
    # ABI-level userspace smoke check: arithmetic plus a direct UART write.
    li t0, 0x1234
    li t1, 0x5678
    add t2, t0, t1
    li t3, 0x68ac
    bne t2, t3, fail

    li t0, 0x10000000       # UART0 THR; no kernel syscall needed for this smoke test.
1:  auipc a1, %pcrel_hi(success_msg)
    addi a1, a1, %pcrel_lo(1b)
2:  auipc t1, %pcrel_hi(success_end)
    addi t1, t1, %pcrel_lo(2b)
write_success:
    beq a1, t1, done
    lbu t2, 0(a1)
    sb t2, 0(t0)
    addi a1, a1, 1
    j write_success

done:
    j done                   # Keep PID 1 alive after the success marker.

fail:
3:  auipc a1, %pcrel_hi(fail_msg)
    addi a1, a1, %pcrel_lo(3b)
4:  auipc t1, %pcrel_hi(fail_end)
    addi t1, t1, %pcrel_lo(4b)
write_fail:
    beq a1, t1, done
    lbu t2, 0(a1)
    sb t2, 0(t0)
    addi a1, a1, 1
    j write_fail
.size _start, .-_start

# Keep code and constant strings together in the flat text segment.
.section .rodata,"a",@progbits
success_msg:
    .ascii "[LINUX_BOOT_SUCCESS] RV32 userspace init reached\n"
success_end:
fail_msg:
    .ascii "[LINUX_INIT_FAIL] arithmetic check failed\n"
fail_end:
