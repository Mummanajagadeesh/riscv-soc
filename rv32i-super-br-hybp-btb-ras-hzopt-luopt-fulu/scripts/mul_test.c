#ifndef OUT_BASE
#define OUT_BASE 0x00000100u
#endif

#ifndef HALT_INSN
#define HALT_INSN "ecall"
#endif

void _start() {
    volatile unsigned int *out = (volatile unsigned int *)OUT_BASE;
    unsigned int a, b, r;
    
    a = 10;
    b = 20;
    r = a * b;
    
    out[0] = a;
    out[1] = b;
    out[2] = r;
    
    asm volatile(HALT_INSN);
    while (1) {}
}
