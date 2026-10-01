#ifndef OUT_BASE
#define OUT_BASE 0x00000100u
#endif

#ifndef HALT_INSN
#define HALT_INSN "ecall"
#endif

static int binary_search(const int *arr, int n, int key);

void _start(void) {
    int data[8];
    volatile int *out = (volatile int *)OUT_BASE;
    int r0;
    int r1;
    int r2;
    int r3;
    int pass;

    data[0] = 3;
    data[1] = 7;
    data[2] = 11;
    data[3] = 19;
    data[4] = 24;
    data[5] = 31;
    data[6] = 42;
    data[7] = 58;

    r0 = binary_search(data, 8, 24);
    r1 = binary_search(data, 8, 58);
    r2 = binary_search(data, 8, 5);
    r3 = binary_search(data, 8, 3);

    out[0] = r0;
    out[1] = r1;
    out[2] = r2;
    out[3] = r3;

    pass = (r0 == 4) && (r1 == 7) && (r2 == -1) && (r3 == 0);
    out[4] = pass;

    asm volatile(HALT_INSN);

    while (1) {
    }
}

static int binary_search(const int *arr, int n, int key) {
    int lo = 0;
    int hi = n - 1;

    while (lo <= hi) {
        int mid = lo + ((hi - lo) >> 1);
        int v = arr[mid];

        if (v == key) {
            return mid;
        }
        if (v < key) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    return -1;
}
