#ifndef OUT_BASE
#define OUT_BASE 0x00000100u
#endif

#ifndef HALT_INSN
#define HALT_INSN "ecall"
#endif

unsigned int mul(unsigned int a, unsigned int b) {
    return a * b;
}

void _start() {
    volatile unsigned int *out = (volatile unsigned int *)OUT_BASE;
    unsigned int sum = 0;
    unsigned int i;
    
    for (i = 0; i < 100; i++) {
        sum += mul(i, i+1);
    }
    
    out[0] = 100;
    out[1] = sum;
    
    asm volatile(HALT_INSN);
    while (1) {}
}
