.section .text.startup
.globl _start

_start:
    .option push
    .option norelax
    la gp, __global_pointer$
    .option pop
    li sp, 0x80001c00

    call main
    li a7, 93
    ecall
