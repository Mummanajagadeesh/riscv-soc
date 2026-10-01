# RV32 Dual-Issue In-Order Superscalar Core

This directory is the `rv32i-super-br-hybp-btb-ras-hzopt-luopt-fulu` variant. Its core issues up to two 32-bit instructions per cycle in an in-order pipeline, with a hybrid branch predictor, BTB, RAS, forwarding, hazard handling, and dual data-memory ports. It is **not** a single-cycle core.

The selected variant includes RTL, Icarus/Verilator testbenches, RV32 program/ELF tools, and benchmark artifacts. Keep this dual-issue design as the base for Linux bring-up.

## Current Status — RV32 no-MMU Linux Boot Demonstrated (2026-10-01)

- Latest upstream baseline: `5bce45dc7c508f4d7e6df8ce2e94572898028cc7` (`main`).
- Baseline RV32I instruction test: **31/31** under both Icarus and Verilator after fixing the Verilator expected-file reader.
- Latest Verilator C smoke runs validate architectural output as well as termination: hello **21 cycles** (`30, 1`), Fibonacci **238 cycles** (`0, 1, 1, 2, 3, 5, 8, 13, 21, 34`), and binary search **425 cycles** (`4, 7, -1, 0, pass=1`). The earlier pre-system baseline was 19/238/422 cycles; later system/target-replay serialization accounts for the additional cycles.
- Local CSR foundation: one shared machine-CSR bank, CSR-immediate source support, slot-1 replay after slot-0 CSR operations, and an interlock for back-to-back CSR dependencies. A CSR whitelist now traps unsupported addresses and read-only writes, checks encoded privilege, suppresses CSRRS/CSRRC zero-source writes, and WARL-masks selected MSTATUS/MIE/MIP bits. Software can set/clear the MSIP pending bit; the Linux test platform also wires the CLINT M-mode timer. External/PLIC interrupts and some privileged CSR/WARL semantics remain incomplete. `make csr-share-test` checks shared-state visibility/aliases and operations; `make csr-legality-test` checks unsupported and RO access traps.
- M-mode trap entry drains older pipeline work before ECALL/EBREAK, illegal-instruction, enabled load/store-misalignment, and interrupt handling or MRET. `TRAP_MISALIGNED=1` selects load/store causes 4/6 with the effective address in `mtval`; `rv32i_top` defaults to transparent unaligned RAM accesses to retain compatibility with `rv32ui/ma_data`. MSIP pending/enable, global MIE masking, cause 3, precise entry, and MRET resume are implemented and tested. Instruction fetch/data access-fault traps, external/PLIC IRQ wiring, and complete interrupt arbitration remain future work (M-mode timer IRQ is wired for the Linux test platform); `TRAP_INST_MISALIGNED=1` traps misaligned control-transfer targets with cause 0 and target `mtval` (enabled by default in `rv32i_top`).
- Machine counters expose `mcycle`/`cycle`, `minstret`/`instret`, low/high halves, and a simulation-tick `time` alias. The Linux simulation platform models a 100 MHz CLINT `mtime`/`mtimecmp` timer and UART0; this is not yet a complete board/peripheral platform.
- Initial single-hart RV32A support includes LR.W, SC.W, all nine AMO.W operations, serialized slot-1 replay, SC-status forwarding, and MISA.A. LR reservations are conservatively invalidated by any committed store; the single-hart RAM is strongly ordered, so FENCE is a no-op. The directed test checks successful/failed SC and all AMO results under Verilator and Icarus; the official RV32UA suite passes 10/10.
- `make fast-test` runs the instruction, shared-CSR/counter, precise-trap, illegal-instruction/CSR-legality, optional load/store and instruction-target misalignment traps, MSIP interrupt, supervisor-transition, RV32A atomic, and C-output regressions with Verilator. The C checks assert each program's expected memory words (not just ECALL termination) and restore the working `hex/` images afterward; the same three architectural outputs were cross-checked under Icarus. Directed Icarus cross-checks are available through `make csr-share-test-icarus`, `make mtrap-test-icarus`, `make illegal-test-icarus`, `make csr-legality-test-icarus`, `make misaligned-test-icarus`, `make msip-interrupt-test-icarus`, `make inst-misaligned-test-icarus`, `make supervisor-test-icarus`, and `make atomic-test-icarus`.
- Public upstream source checkouts are available beside this variant: EEMBC CoreMark at `../coremark` (`1f483d5`) and `riscv-tests` at `../riscv-tests` (`933a897`, with its public `env` submodule initialized). Fetch/run commands are exposed in the Makefile.
- `UNIFIED_MEMORY=1` routes both instruction-fetch lanes and both data lanes through one parameterized `data_mem.mem[]` array; split-memory mode remains the compatibility default. Linux and the official compliance testbench use unified mode. `scripts/elf2unifiedhex.py` emits sparse allocated-section images with base/range checking. The suites pass **RV32UI 42/42, RV32UM 8/8, RV32UA 10/10 (60/60)**, including runtime code fetch from the shared RAM; `satp` does not yet translate addresses.
- Public CoreMark validation now passes on the dual-issue RTL with the cloned EEMBC source and the local bare-metal port: **2,336,216 cycles, 3,167,341 retired instructions**, ten validation iterations, internal pass marker verified. This is a functional validation only—not a reportable performance result.
- **Linux boot milestone:** `make linux-boot-test` boots the RV32 no-MMU Linux 6.12 image through initramfs unpack, device initialization, and execution of a minimal bFLT PID 1. Verilator logs the explicit `[LINUX_BOOT_SUCCESS]` UART marker at 20 million cycles, and the target rejects fatal kernel messages or a missing marker. The kernel banner alone is not treated as success. See `DEBUG_LOG.md` for the run and implementation details.
- **Remaining scope:** this is not the MMU-enabled Linux path. Sv32/TLB/page faults, SBI/OpenSBI, PMP and access-fault handling, external/PLIC interrupts, and a general userspace/root filesystem remain incomplete. The test init only checks arithmetic, emits its UART marker, and stays alive.

Tool setup and reproducible baseline logs are in `/home/user/rv32i-linux-work/BASELINE.md`; staged implementation and acceptance gates are in `/home/user/rv32i-linux-work/LINUX_BRINGUP_PLAN.md`.

## Project Tree

```text
rv32i/
├── Makefile
├── defines.v
├── README.md
├── rtl/
│   ├── core/
│   │   ├── alu.v
│   │   ├── alu_ctrl.v
│   │   ├── branch_compare.v
│   │   ├── control.v
│   │   ├── core_top.v
│   │   ├── csr_reg.v
│   │   ├── imm_gen.v
│   │   ├── pc_reg.v
│   │   └── registers.v
│   ├── mem/
│   │   ├── data_mem.v
│   │   ├── inst_mem.v
│   │   └── mem_top.v
│   └── top/
│       └── rv32i_top.v
├── tb/
│   ├── tb_instructions.v
│   ├── tb_instructions.f
│   ├── tb_program.v
│   └── tb_program.f
├── scripts/
│   ├── crt0_qemu_spike.S
│   ├── elf2hex.py
│   ├── run_riscv_suite.py
│   ├── run_coremark_rtl.py
│   ├── run_c_smoke.py
│   ├── check_c_smoke.py
│   ├── crosscheck_qemu_spike.py
│   ├── gen_test_hex.py
│   ├── hello.c
│   ├── fibonacci.c
│   └── binary_search.c
├── test_hex/
│   ├── inst_mem.hex
│   ├── data_mem.hex
│   ├── expected_final.txt
│   └── link_at_0.ld
└── hex/
    ├── inst_mem.hex
    └── data_mem.hex
```

## Supported RV32I Instructions

The processor supports these RV32I instruction classes:

- U-type: lui, auipc
- Jumps: jal, jalr
- Branches: beq, bne, blt, bge, bltu, bgeu
- Loads: lb, lh, lw, lbu, lhu
- Stores: sb, sh, sw
- OP-IMM: addi, slti, sltiu, xori, ori, andi, slli, srli, srai
- OP: add, sub, sll, slt, sltu, xor, srl, sra, or, and
- System: ECALL (M-mode trap when `ECALL_HALT=0`; simulation halt by default), EBREAK (M-mode breakpoint trap), MRET, and the supported machine CSR operations (CSRRW/CSRRS/CSRRC and immediate forms). WFI currently decodes as a no-op.

## RV32IM M Extension

The processor also supports the RISC-V M extension (Multiply/Divide) in addition to RV32I.

### Supported M Extension Instructions

- mul: Multiply (lower 32 bits)
- mulh: Multiply high (signed x signed)
- mulhsu: Multiply high (signed x unsigned)
- mulhu: Multiply high (unsigned x unsigned)
- div: Divide (signed)
- divu: Divide (unsigned)
- rem: Remainder (signed)
- remu: Remainder (unsigned)

### Running RV32UM Tests

The public RV32M compliance suite is built and run by the Verilator-first runner:

```bash
make rv32um-tests
```

### M Extension Test Results

All 8 RV32UM tests pass on the latest verified run:

```
mul    - PASS
mulh   - PASS
mulhsu - PASS
mulhu  - PASS
div    - PASS
divu   - PASS
rem    - PASS
remu   - PASS
```

## Prerequisites

- iverilog and vvp
- Python 3
- RISC-V GCC toolchain (riscv64-unknown-elf-gcc or riscv32-unknown-elf-gcc)
- QEMU RISC-V system emulator (qemu-system-riscv32)
- Spike ISA simulator (spike)

## Testbench Roles

- tb/tb_instructions.v
  - Main instruction regression testbench
  - Uses generated test_hex images
  - Checks final register state against test_hex/expected_final.txt
  - Reports total checks, pass count, fail count

- tb/tb_program.v
  - Main generic C-program testbench
  - Loads hex/inst_mem.hex and hex/data_mem.hex
  - Prints instruction trace, final registers, and memory dump
  - Dumps output window mem[64..127] for easy external comparison
  - Works for any C file compiled to ELF and converted to hex

## Public ISA Tests and CoreMark

The public upstream sources are checked out beside this variant: `../riscv-tests` (including its `env` submodule) and `../coremark`. The clones remain at the revisions pinned by the parent project. Override `RISCV_TESTS_DIR` or `COREMARK_DIR` when running Make targets from a different layout.

With the RISC-V cross-compiler and Verilator installed, run:

```bash
make riscv-tests       # RV32UI + RV32UM + RV32UA suites in unified-RAM mode
make rv32ui-tests      # RV32I user suite
make rv32um-tests      # RV32M user suite
make coremark-rtl-test # CoreMark functional validation on RTL (not a score)
```

To isolate a test, use for example:

```bash
python3 scripts/run_riscv_suite.py --suite rv32ui --test sh --test ma_data
```

Latest verified result: **RV32UI 42/42 and RV32UM 8/8 pass (50/50 combined)** using `make riscv-tests`. The compliance testbench enables store-to-instruction-memory coherence, and the ELF converter mirrors initialized writable data sections into the instruction image, allowing the official self-modifying-code `fence_i` test to pass. The generic top remains Harvard-style by default to preserve existing split-image C/instruction tests; a full shared physical memory/bus is still needed for the later Linux platform.

`make coremark-rtl-test` builds the public clone's CoreMark sources with the local bare-metal simulation port, runs the 2K validation dataset/seeds for ten iterations, and checks CoreMark's internal CRC/type/timing success through a memory marker. A 16 KiB data-memory configuration keeps the program image, initialized data, and stack disjoint. The port treats simulation cycles as ticks to bypass CoreMark's ten-second reporting threshold; the test is strictly functional, and no CoreMark score or performance claim is reported. The pinned clone's `make check` has one upstream manifest mismatch: its expected MD5 for `coremark.h` differs from the file at that Git commit; the working file matches `HEAD`, and all other listed source checks pass.

## Reproduce Results

### 1) RV32I instruction regression

Generate regression images and run instruction testbench:

```bash
make gen-test-hex
make iverilog-inst-sim
```

Expected summary:

- Total checks: 31
- Passed: 31
- Failed: 0
- *** ALL TESTS PASSED ***

### 2) Generic C flow

Use this for any C source:

```bash
make c-run C_SRC=scripts/<program>.c ELF=<name>.elf
```

This does:

1. Compile C to ELF
2. Convert ELF to hex/inst_mem.hex and hex/data_mem.hex
3. Run tb_program simulation

## Verified C Programs

Run the reproducible Verilator output assertions with:

```bash
make c-smoke-test
```

This checks the result words from hello, Fibonacci, and binary search, including the binary-search pass marker; it preserves/restores the shared hex images and result file.

### Hello program

Run:

```bash
make c-run C_SRC=scripts/hello.c ELF=hello.elf
```

What to check in output:

- Program runs and reaches stable end condition
- Register and memory dump are printed

### Fibonacci program

Run:

```bash
make c-run C_SRC=scripts/fibonacci.c ELF=fibonacci.elf
```

Check memory dump (idx 64..73):

- mem[64]=0
- mem[65]=1
- mem[66]=1
- mem[67]=2
- mem[68]=3
- mem[69]=5
- mem[70]=8
- mem[71]=13
- mem[72]=21
- mem[73]=34

### Binary search program

Run:

```bash
make c-run C_SRC=scripts/binary_search.c ELF=binary_search.elf
```

Check memory dump (idx 64..68):

- mem[64]=4 for key 24
- mem[65]=7 for key 58
- mem[66]=0xffffffff for key 5 not found
- mem[67]=0 for key 3
- mem[68]=1 pass flag

## Complete Flow Summary

### Instruction regression flow

```
scripts/gen_test_hex.py
  -> test_hex/inst_mem.hex + test_hex/data_mem.hex + expected_final.txt
  -> tb_instructions.v
  -> pass/fail summary for RV32I coverage
```

### Generic C program flow

```
C source (scripts/*.c)
  -> riscv64-unknown-elf-gcc (ELF)
  -> scripts/elf2hex.py
  -> hex/inst_mem.hex + hex/data_mem.hex
  -> tb_program.v
  -> register and memory dump for manual verification
```

### Cross-check flow without program-specific expectations

Use one command to compare raw output dumps from RTL, QEMU, and Spike for any C file:

```bash
python3 scripts/crosscheck_qemu_spike.py scripts/hello.c --words 16
python3 scripts/crosscheck_qemu_spike.py scripts/fibonacci.c --words 16
python3 scripts/crosscheck_qemu_spike.py scripts/binary_search.c --words 16
```

How this works:

1. Runs RTL generic TB (tb_program) and captures output window dump.
2. Builds a host-run ELF for QEMU and Spike using scripts/crt0_qemu_spike.S.
3. Dumps the same output window from QEMU and Spike.
4. Compares word-by-word values with no program-specific check logic.

Notes:

- No algorithm-specific assertions are used in the cross-check script.
- The script compares raw memory dump words only.
- Host runs use a configurable output base (--host-out-base, default 0x80002000) to avoid overlap with program text.

### Cross-check results (examples)

Commands used:

```bash
python3 scripts/crosscheck_qemu_spike.py scripts/hello.c --words 16
python3 scripts/crosscheck_qemu_spike.py scripts/fibonacci.c --words 16
python3 scripts/crosscheck_qemu_spike.py scripts/binary_search.c --words 16
```

Observed outcome:

- Hello: RTL, QEMU, Spike word dumps matched
- Fibonacci: RTL, QEMU, Spike word dumps matched
- Binary search: RTL, QEMU, Spike word dumps matched

## Useful Commands

- make help to list all targets
- make clean to remove build artifacts
- make iverilog-inst-sim to run instruction regression
- make iverilog-prog-sim to run whatever is currently in hex/

## Notes

- tb_program is intentionally generic. It is not hardcoded for any one C program.
- tb_program_results.txt stores final simulation report for each C run.
- tb_instructions.vcd and tb_program.vcd can be viewed in GTKWave.
- The rv32ui and rv32um tests are from the official riscv-software-src/riscv-tests repository and represent the RISC-V ISA compliance test suite.
- Instruction memory is 16KB (4096 words) to support larger programs like CoreMark.
- Use -march=rv32im when compiling C programs that use multiplication or division.
