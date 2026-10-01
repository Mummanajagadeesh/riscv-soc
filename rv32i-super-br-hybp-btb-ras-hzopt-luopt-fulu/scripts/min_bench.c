#define NUM_ITERATIONS 100

volatile unsigned int result = 0;

int main() {
    unsigned int i, j;
    
    for (i = 0; i < NUM_ITERATIONS; i++) {
        j = i * 3 + 7;
        j = j / 2;
        j = j * 5 - 3;
        result = j;
    }
    
    volatile unsigned int *out = (volatile unsigned int *)0x100;
    out[0] = result;
    out[1] = NUM_ITERATIONS;
    out[2] = 0xDEADBEEF;
    
    while(1);
    return 0;
}
