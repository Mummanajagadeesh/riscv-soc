.section .text
.globl _start

_start:
    li sp, 0x8003fffc
    j main
