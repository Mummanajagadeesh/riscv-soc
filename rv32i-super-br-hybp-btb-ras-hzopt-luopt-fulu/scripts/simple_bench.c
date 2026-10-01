volatile int result = 0;

int main() {
    int i, j;
    for (i = 0; i < 100; i++) {
        for (j = 0; j < 100; j++) {
            result = result + i - j;
        }
    }
    volatile int *out = (volatile int *)0x100;
    out[0] = result;
    out[1] = 0xDEADBEEF;
    while(1);
    return 0;
}
