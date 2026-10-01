#ifndef OUT_BASE
#define OUT_BASE 0x00000100u
#endif

#ifndef HALT_INSN
#define HALT_INSN "ecall"
#endif

void _start() {
    volatile unsigned int *out = (volatile unsigned int *)OUT_BASE;
    unsigned int a[10];
    unsigned int i, j, k, sum;
    
    for (i = 0; i < 10; i++) {
        a[i] = i + 1;
    }
    
    sum = 0;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            for (k = 0; k < 5; k++) {
                sum += a[i] * a[j];
            }
        }
    }
    
    out[0] = 10;
    out[1] = sum;
    out[2] = 100;
    out[3] = 500;
    
    asm volatile(HALT_INSN);
    while (1) {}
}
