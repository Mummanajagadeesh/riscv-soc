#ifndef OUT_BASE
#define OUT_BASE 0x00000100u
#endif

#ifndef HALT_INSN
#define HALT_INSN "ecall"
#endif

#define ITERATIONS 100

typedef unsigned int ee_u32;
typedef unsigned short ee_u16;
typedef unsigned char ee_u8;
typedef signed int ee_s32;
typedef signed short ee_s16;
typedef signed char ee_s8;
typedef ee_u32 ee_ptr_int;
typedef ee_u32 ee_size_t;
typedef ee_u32 CORE_TICKS;
typedef ee_u32 secs_ret;

#define ee_printf(...) ((void)0)

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

typedef struct CORE_PORTABLE_S {
    ee_u8 portable_id;
} core_portable;

extern volatile ee_s32 seed1_volatile;
extern volatile ee_s32 seed2_volatile;
extern volatile ee_s32 seed3_volatile;
extern volatile ee_s32 seed4_volatile;
extern volatile ee_s32 seed5_volatile;

void start_time(void) {}
void stop_time(void) {}
CORE_TICKS get_time(void) { return 0; }
secs_ret time_in_secs(CORE_TICKS ticks) { return 0; }

void portable_init(core_portable *p, int *argc, char *argv[]) {
    (void)argc; (void)argv;
    p->portable_id = 1;
}
void portable_fini(core_portable *p) {
    p->portable_id = 0;
}

volatile ee_s32 seed1_volatile = 0x3415;
volatile ee_s32 seed2_volatile = 0x3415;
volatile ee_s32 seed3_volatile = 0x66;
volatile ee_s32 seed4_volatile = ITERATIONS;
volatile ee_s32 seed5_volatile = 0;

ee_u32 default_num_contexts = 1;
