#ifndef OUT_BASE
#define OUT_BASE 0x00000100u
#endif

#ifndef HALT_INSN
#define HALT_INSN "ecall"
#endif

#define ITERATIONS 100

#define HAS_FLOAT 0
#define HAS_TIME_H 0
#define HAS_STDIO 0
#define HAS_PRINTF 0
#define USE_CLOCK 0

#define SEED_METHOD 2
#define MEM_METHOD 2
#define MULTITHREAD 1
#define MAIN_HAS_NOARGC 1
#define MAIN_HAS_NORETURN 1
#define COMPILER_VERSION "RV32I"
#define COMPILER_FLAGS "-O2"
#define MEM_LOCATION "STACK"
#define TOTAL_DATA_SIZE 2000

#include "core_portme.h"
#include "coremark.h"

core_results results[MULTITHREAD];

void _start() {
    volatile unsigned int *out = (volatile unsigned int *)OUT_BASE;
    
    portable_init(&results[0].port, 0, 0);
    
    results[0].seed1 = 0;
    results[0].seed2 = 0;
    results[0].seed3 = 0x66;
    results[0].iterations = ITERATIONS;
    results[0].execs = ALL_ALGORITHMS_MASK;
    
    {
        ee_u8 stack_memblock[TOTAL_DATA_SIZE];
        results[0].memblock[0] = stack_memblock;
    }
    results[0].size = TOTAL_DATA_SIZE;
    results[0].err = 0;
    
    ee_u16 num_algorithms = 0;
    for (ee_u16 i = 0; i < NUM_ALGORITHMS; i++) {
        if ((1 << i) & results[0].execs)
            num_algorithms++;
    }
    results[0].size = results[0].size / num_algorithms;
    
    ee_u16 j = 0;
    for (ee_u16 i = 0; i < NUM_ALGORITHMS; i++) {
        if ((1 << i) & results[0].execs) {
            results[0].memblock[i + 1] = (char *)(results[0].memblock[0]) + results[0].size * j;
            j++;
        }
    }
    
    for (ee_u16 i = 0; i < MULTITHREAD; i++) {
        if (results[i].execs & ID_LIST) {
            results[i].list = core_list_init(results[0].size, results[i].memblock[1], results[i].seed1);
        }
        if (results[i].execs & ID_MATRIX) {
            core_init_matrix(results[0].size, results[i].memblock[2],
                (ee_s32)results[i].seed1 | (((ee_s32)results[i].seed2) << 16), &(results[i].mat));
        }
        if (results[i].execs & ID_STATE) {
            core_init_state(results[0].size, results[i].seed1, results[i].memblock[3]);
        }
    }
    
    iterate(&results[0]);
    
    out[0] = results[0].iterations;
    out[1] = results[0].crc;
    out[2] = results[0].crclist;
    out[3] = results[0].crcmatrix;
    out[4] = results[0].crcstate;
    out[5] = results[0].err;
    out[6] = TOTAL_DATA_SIZE;
    out[7] = results[0].size;
    
    portable_fini(&results[0].port);
    
    asm volatile(HALT_INSN);
    while (1) {}
}
