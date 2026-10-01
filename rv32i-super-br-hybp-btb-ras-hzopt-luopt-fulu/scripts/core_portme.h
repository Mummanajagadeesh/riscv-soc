#ifndef CORE_PORTME_H
#define CORE_PORTME_H

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

#include <stddef.h>

typedef unsigned int ee_u32;
typedef unsigned short ee_u16;
typedef unsigned char ee_u8;
typedef signed int ee_s32;
typedef signed short ee_s16;
typedef signed char ee_s8;
typedef ee_u32 ee_ptr_int;
typedef size_t ee_size_t;

typedef ee_u32 CORE_TICKS;
typedef ee_u32 secs_ret;

#define COMPILER_VERSION "RV32I"
#define COMPILER_FLAGS "-O2"
#define MEM_LOCATION "STACK"

#define align_mem(x) (void *)(4 + (((ee_ptr_int)(x)-1) & ~3))

#define SEED_VOLATILE 2
#define MEM_STACK 2

#define ee_printf(...) ((void)0)

typedef struct CORE_PORTABLE_S {
    ee_u8 portable_id;
} core_portable;

void portable_init(core_portable *p, int *argc, char *argv[]);
void portable_fini(core_portable *p);

void start_time(void);
void stop_time(void);
CORE_TICKS get_time(void);
secs_ret time_in_secs(CORE_TICKS ticks);

volatile ee_s32 seed1_volatile;
volatile ee_s32 seed2_volatile;
volatile ee_s32 seed3_volatile;
volatile ee_s32 seed4_volatile;
volatile ee_s32 seed5_volatile;

ee_u32 default_num_contexts;

#if !defined(PROFILE_RUN) && !defined(PERFORMANCE_RUN) && !defined(VALIDATION_RUN)
#define PERFORMANCE_RUN 1
#endif

void portable_init(core_portable *p, int *argc, char *argv[]) {
    (void)argc; (void)argv;
    p->portable_id = 1;
}
void portable_fini(core_portable *p) {
    p->portable_id = 0;
}

void start_time(void) {}
void stop_time(void) {}
CORE_TICKS get_time(void) { return 0; }
secs_ret time_in_secs(CORE_TICKS ticks) { (void)ticks; return 0; }

#endif
