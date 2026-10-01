#include "coremark.h"
#include "core_portme.h"

#if VALIDATION_RUN
volatile ee_s32 seed1_volatile = 0x3415;
volatile ee_s32 seed2_volatile = 0x3415;
volatile ee_s32 seed3_volatile = 0x66;
#endif
#if PERFORMANCE_RUN
volatile ee_s32 seed1_volatile = 0x0;
volatile ee_s32 seed2_volatile = 0x0;
volatile ee_s32 seed3_volatile = 0x66;
#endif
#if PROFILE_RUN
volatile ee_s32 seed1_volatile = 0x8;
volatile ee_s32 seed2_volatile = 0x8;
volatile ee_s32 seed3_volatile = 0x8;
#endif
volatile ee_s32 seed4_volatile = ITERATIONS;
volatile ee_s32 seed5_volatile = 0;

/*
 * This port is for functional simulation only, not a reportable performance
 * run.  Each cycle is treated as a tick so CoreMark's ten-second reporting
 * gate does not require an impractical 100-million-cycle RTL simulation.
 */
#define CLOCKS_PER_SEC 1
#define GETMYTIME(_t)              (*_t = barebones_clock())
#define MYTIMEDIFF(fin, ini)       ((fin) - (ini))
#define TIMER_RES_DIVIDER          1
#define SAMPLE_TIME_IMPLEMENTATION 1
#define EE_TICKS_PER_SEC           (CLOCKS_PER_SEC / TIMER_RES_DIVIDER)

#define COREMARK_STATUS_ADDR 0x000001fcu
#define COREMARK_STATUS_PASS 0xc0decafeu
#define COREMARK_STATUS_FAIL 0xbad0bad0u
#define COREMARK_STATUS \
    (*(volatile ee_u32 *)(ee_ptr_int)COREMARK_STATUS_ADDR)

static CORETIMETYPE start_time_val, stop_time_val;

static CORETIMETYPE read_cycle_counter(void) {
    CORETIMETYPE value;
    __asm__ volatile ("rdcycle %0" : "=r"(value));
    return value;
}

__attribute__((noinline))
CORETIMETYPE barebones_clock(void) {
    return read_cycle_counter();
}

void start_time(void) {
    start_time_val = barebones_clock();
}

void stop_time(void) {
    stop_time_val = barebones_clock();
}

CORE_TICKS get_time(void) {
    return (CORE_TICKS)(stop_time_val - start_time_val);
}

/* A simulation tick is intentionally not a wall-clock second. */
secs_ret time_in_secs(CORE_TICKS ticks) {
    return (secs_ret)ticks;
}

ee_u32 default_num_contexts = 1;

void portable_init(core_portable *p, int *argc, char *argv[]) {
    (void)argc;
    (void)argv;

    COREMARK_STATUS = 0;
    if (sizeof(ee_ptr_int) != sizeof(ee_u8 *)) {
        ee_printf("ERROR! Please define ee_ptr_int to a type that holds a pointer!\n");
    }
    if (sizeof(ee_u32) != 4) {
        ee_printf("ERROR! Please define ee_u32 to a 32b unsigned type!\n");
    }
    p->portable_id = 1;
}

void portable_fini(core_portable *p) {
    p->portable_id = 0;
}

static int contains_text(const char *text, const char *needle) {
    const char *start;
    const char *scan;
    if (*needle == '\0')
        return 1;
    for (; *text != '\0'; text++) {
        start = text;
        scan = needle;
        while (*start != '\0' && *scan != '\0' && *start == *scan) {
            start++;
            scan++;
        }
        if (*scan == '\0')
            return 1;
    }
    return 0;
}

int ee_printf(const char *fmt, ...) {
    if (contains_text(fmt, "ERROR!") ||
        contains_text(fmt, "Errors detected") ||
        contains_text(fmt, "Cannot validate operation")) {
        COREMARK_STATUS = COREMARK_STATUS_FAIL;
    } else if (contains_text(fmt, "Correct operation validated.")) {
        COREMARK_STATUS = COREMARK_STATUS_PASS;
    }
    return 0;
}

volatile unsigned int cycles;

void __attribute__((noinline)) inc_cycles(void) {
    cycles++;
}

/* The bare-metal RTL image has no C library; CoreMark's state init uses memset. */
void *memset(void *destination, int value, size_t count) {
    volatile ee_u8 *bytes = (volatile ee_u8 *)destination;
    size_t i;
    for (i = 0; i < count; i++)
        bytes[i] = (ee_u8)value;
    return destination;
}
