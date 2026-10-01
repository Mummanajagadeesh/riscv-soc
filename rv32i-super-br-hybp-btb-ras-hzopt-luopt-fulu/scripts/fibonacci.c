#ifndef OUT_BASE
#define OUT_BASE 0x00000100u
#endif

#ifndef HALT_INSN
#define HALT_INSN "ecall"
#endif

void _start() {
    volatile unsigned int *out = (volatile unsigned int *)OUT_BASE;
    unsigned int a = 0;
    unsigned int b = 1;
    unsigned int i;

    for (i = 0; i < 10; i++) {
        out[i] = a;
        {
            unsigned int next = a + b;
            a = b;
            b = next;
        }
    }

    asm volatile(HALT_INSN);

    while (1) {
    }
}
