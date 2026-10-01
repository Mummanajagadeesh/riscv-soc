#define NUM_ITERATIONS 10000

volatile unsigned int result = 0;

int main() {
    unsigned int i, j;
    
    for (i = 0; i < NUM_ITERATIONS; i++) {
        j = i + 7;
        j = j * 3;
        j = j - 5;
        j = j & 0xFF;
        result = j;
    }
    
    volatile unsigned int *out = (volatile unsigned int *)0x100;
    out[0] = result;
    out[1] = NUM_ITERATIONS;
    out[2] = 0xDEADBEEF;
    
    while(1);
    return 0;
}
