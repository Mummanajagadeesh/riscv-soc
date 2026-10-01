#ifndef OUT_BASE
#define OUT_BASE 0x00000100u
#endif

#ifndef HALT_INSN
#define HALT_INSN "ecall"
#endif

void _start() {
    volatile unsigned int *out = (volatile unsigned int *)OUT_BASE;
    volatile unsigned int sum = 0;
    unsigned int i, j;
    
    for (i = 0; i < 100; i++) {
        for (j = 0; j < 100; j++) {
            sum += i * j;
        }
    }
    
    out[0] = 100;
    out[1] = sum;
    
    asm volatile(HALT_INSN);
    while (1) {}
}
