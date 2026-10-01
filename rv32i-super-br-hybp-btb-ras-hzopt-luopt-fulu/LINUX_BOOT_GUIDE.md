# Booting the RV32 no-MMU Linux image on the dual-issue RTL

This guide describes the verified **M-mode, no-MMU Linux 6.12** simulation path in this repository. It is a simulation bring-up—not an FPGA flow—and it does not use SBI. The current `/init` is a minimal bFLT userspace smoke test, not an interactive shell.

## 1. Prerequisites

Install or make available:

- `make`, Python 3, a C/C++ toolchain
- Verilator (the verified primary simulator; version 5.x was used)
- `riscv64-linux-gnu-gcc` and `riscv64-linux-gnu-objcopy`
- `dtc` (Device Tree Compiler) and `cpio`

You also need a prebuilt **RV32 no-MMU M-mode Linux `vmlinux`**. The default Makefile path is:

```text
/home/user/rv32i-linux-work/build-linux-rv32-nommu/vmlinux
```

The kernel source/build tree is not inside this repository archive. If your kernel ELF is elsewhere, pass its path through `LINUX_VMLINUX` in the commands below.

## 2. Run the boot test

From the repository root:

```bash
make linux-boot-test
```

To use a different kernel image:

```bash
make linux-boot-test LINUX_VMLINUX=/absolute/path/to/rv32-nommu/vmlinux
```

The target prepares the initramfs, patches the kernel command line for `rdinit=/init`, compiles the platform DTS, inserts the initramfs address/size into the DTB, builds sparse code/data RAM images, compiles the Verilator testbench, and runs the dual-issue RTL. Defaults include a 32 MiB physical RAM, a 100 MHz CLINT timebase, timer interrupts enabled, and a 20,000,000-cycle simulation limit.

To run the preparation stages separately:

```bash
make linux-initramfs
make linux-boot-vmlinux
make linux-boot-image
make linux-boot-test
```

To set an explicit cycle limit or timer setting:

```bash
make linux-boot-test LINUX_MAX_CYCLES=20000000 LINUX_TIMER_IRQ=1
```

The default `LINUX_TIMER_IRQ=1` is needed for Linux timekeeping. Disabling it is useful only for diagnostics; it does not demonstrate a usable Linux boot.

## 3. Check that the run really booted

The test succeeds only if the simulation exits cleanly, prints a Linux version banner, has no `Kernel panic`, `Kernel BUG`, or `Oops`, and the userspace init emits the marker:

```text
[LINUX_BOOT_SUCCESS] RV32 userspace init reached
```

The main run log is:

```text
build/linux-boot/linux-boot.log
```

Useful commands after the run:

```bash
grep -E 'Linux version|Run /init|LINUX_BOOT_SUCCESS|Kernel panic|Kernel BUG|Oops' \
  build/linux-boot/linux-boot.log
```

A version banner by itself is **not** a pass. The marker is printed by PID 1 after Linux has launched `/init` from the initramfs.

## 4. What the build creates

The source files relevant to the Linux path are:

- `platform/linux/rv32-nommu.dts` — simulated RAM, UART, and CLINT description; its timer frequency matches the 100 MHz testbench clock.
- `platform/linux/init.S` and `platform/linux/flat_init.ld` — tiny RV32 PID 1 smoke program and its linker layout.
- `scripts/pack_bflt.py` — wraps the relocation-free text as a bFLT v4 executable, which this no-MMU kernel accepts.
- `scripts/patch_linux_cmdline.py` — changes the existing kernel command line to launch `/init` and use the simulated console.
- `scripts/patch_linux_dtb_initrd.py` — adds initramfs start/end properties to the DTB.
- `scripts/elf2linux_splithex.py` — creates sparse physical code/data overlays for the simulator.
- `tb/tb_linux_boot.v` — configures unified physical RAM, timer/UART simulation, and the boot acceptance checks.

The testbench sets `UNIFIED_MEMORY=1`, so instruction fetches and data accesses share the parameterized `data_mem.mem[]` array. Runtime-loaded init code is therefore executable from the same RAM the kernel writes.

## 5. Regressions

The functional RTL regressions and C smoke tests are run with:

```bash
make fast-test
```

The upstream RV32UI, RV32UM, and RV32UA architectural suites run in unified-memory mode with Verilator:

```bash
make riscv-tests
```

The verified result is 60/60. An Icarus cross-check for unified-mode `rv32ui/ld_st` can be reproduced after running `make riscv-tests` (which builds `build/riscv-tests/rv32ui-ld_st.elf`):

```bash
python3 scripts/elf2unifiedhex.py \
  build/riscv-tests/rv32ui-ld_st.elf build/riscv_test_unified.hex \
  --base 0x80000000 --words 4096
iverilog -g2005 -f tb/tb_riscv_test.f -o build/unified_ldst_icarus.vvp
vvp build/unified_ldst_icarus.vvp +max_cycles=100000 +tohost_index=2048
```

## 6. Current limitations

- The current init prints its marker and loops. It is not a shell and does not accept keyboard input.
- UART output works for this simulation, but UART receive/host-input plumbing and UART interrupt delivery are not implemented.
- This is the no-MMU M-mode image. The separate MMU-enabled image still needs Sv32 translation/page faults and an SBI/OpenSBI path.
- The simulation platform is not a complete board model; no FPGA fitting, area, or timing work is part of this flow.
