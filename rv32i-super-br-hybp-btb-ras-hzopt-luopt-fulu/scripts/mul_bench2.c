#ifndef OUT_BASE
#define OUT_BASE 0x00000100u
#endif

#ifndef HALT_INSN
#define HALT_INSN "ecall"
#endif

void _start() {
    volatile unsigned int *out = (volatile unsigned int *)OUT_BASE;
    unsigned int sum = 0;
    unsigned int i;
    unsigned int a, b;
    
    for (i = 0; i < 100; i++) {
        a = i;
        b = i + 1;
        asm volatile ("mul %0, %1, %2" : "=r"(sum) : "r"(a), "r"(b));
        sum += a * b;
    }
    
    out[0] = 100;
    out[1] = sum;
    
    asm volatile(HALT_INSN);
    while (1) {}
}
