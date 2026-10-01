.section .text
.globl _start

_start:
    li sp, 0x8003fffc
    call program_main
1:
    j 1b
