#ifndef OUT_BASE
#define OUT_BASE 0x00000100u
#endif

#ifndef HALT_INSN
#define HALT_INSN "ecall"
#endif

void _start(void) {
    volatile unsigned int *out = (volatile unsigned int *)OUT_BASE;
    unsigned int a = 10;
    unsigned int b = 20;
    unsigned int c = a + b;

    out[0] = c;
    out[1] = 1;

    asm volatile(HALT_INSN);

    while (1) {
    }
}
