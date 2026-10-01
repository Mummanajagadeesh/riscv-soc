.PHONY: all iverilog verilator sim clean clean-build help iverilog-inst iverilog-prog iverilog-inst-sim iverilog-prog-sim verilator-inst verilator-prog verilator-inst-sim verilator-prog-sim c-run gen-test-hex csr-share-image csr-share-test csr-share-test-icarus mtrap-image mtrap-test mtrap-test-icarus illegal-image illegal-test illegal-test-icarus csr-legality-image csr-legality-test csr-legality-test-icarus misaligned-image misaligned-test misaligned-test-icarus msip-interrupt-image msip-interrupt-test msip-interrupt-test-icarus inst-misaligned-image inst-misaligned-test inst-misaligned-test-icarus supervisor-image supervisor-test supervisor-test-icarus atomic-image atomic-test atomic-test-icarus linux-initramfs linux-boot-vmlinux linux-boot-image linux-boot-test c-smoke-test fast-test verilator-regression coremark-fetch coremark-rtl-image coremark-rtl-program coremark-rtl-test riscv-tests-fetch riscv-tests rv32ui-tests rv32um-tests rv32ua-tests riscv-isa-tests

IVERILOG  ?= iverilog
VVP       ?= vvp
VERILATOR ?= verilator
RISCV_GCC ?= riscv64-unknown-elf-gcc
C_SRC     ?= scripts/hello.c
ELF       ?= hello.elf
BUILD_DIR ?= build
VERILATOR_DIR ?= $(BUILD_DIR)/verilator
LINUX_VMLINUX ?= /home/user/rv32i-linux-work/build-linux-rv32-nommu/vmlinux
LINUX_BOOT_VMLINUX ?= $(BUILD_DIR)/linux-boot/vmlinux-initramfs
LINUX_CMDLINE_OLD ?= root=/dev/vda rw earlycon=uart8250,mmio,0x10000000,115200n8 console=ttyS0
LINUX_CMDLINE ?= rdinit=/init earlycon=uart8250,mmio,0x10000000,115200n8 console=ttyS0
RISCV_LINUX_GCC ?= riscv64-linux-gnu-gcc
LINUX_INITRD ?= $(BUILD_DIR)/linux-boot/initramfs.cpio
LINUX_INITRD_ADDR ?= 0x81000000
LINUX_RAM_WORDS ?= 8388608
LINUX_INST_WORDS ?= 8388608
LINUX_DTB_ADDR ?= 0x80300000
LINUX_TIMER_IRQ ?= 1
LINUX_MAX_CYCLES ?= 20000000
RISCV_LINUX_OBJCOPY ?= riscv64-linux-gnu-objcopy
COREMARK_DIR ?= ../coremark
RISCV_TESTS_DIR ?= ../riscv-tests

SOURCES = \
	defines.v \
	rtl/core/alu.v \
	rtl/core/alu_ctrl.v \
	rtl/core/hazard.v \
	rtl/core/forward.v \
	rtl/core/registers.v \
	rtl/core/imm_gen.v \
	rtl/core/branch_compare.v \
	rtl/core/csr_reg.v \
	rtl/core/pc_reg.v \
	rtl/core/control.v \
	rtl/core/core_top.v \
	rtl/mem/inst_mem.v \
	rtl/mem/data_mem.v \
	rtl/mem/mem_top.v \
	rtl/top/rv32i_top.v

all: iverilog-inst
	@echo "Run 'make iverilog-inst' or 'make iverilog-prog' for iverilog"
	@echo "Run 'make verilator-inst' or 'make verilator-prog' for verilator"

iverilog-inst: clean-build
	$(IVERILOG) -g2005 -f tb/tb_instructions.f -o tb_instructions_sim.vvp 2>&1
	@echo "Build OK. Run: vvp tb_instructions_sim.vvp"

iverilog-prog: clean-build
	$(IVERILOG) -g2005 -f tb/tb_program.f -o tb_program_sim.vvp 2>&1
	@echo "Build OK. Run: vvp tb_program_sim.vvp"

iverilog-inst-sim: iverilog-inst
	$(VVP) tb_instructions_sim.vvp -vcd

iverilog-prog-sim: iverilog-prog
	$(VVP) tb_program_sim.vvp -vcd

verilator-inst: clean-build
	$(VERILATOR) --cc --trace --timing \
		-Wno-fatal \
		-f tb/tb_instructions.f \
		--Mdir $(VERILATOR_DIR)/instructions \
		--top-module tb_instructions --exe --main 2>&1
	cd $(VERILATOR_DIR)/instructions && make -f Vtb_instructions.mk -j$$(nproc) 2>&1
	@echo "Build OK. Run: $(VERILATOR_DIR)/instructions/Vtb_instructions"

verilator-prog: clean-build
	$(VERILATOR) --cc --trace --timing \
		-Wno-fatal \
		-f tb/tb_program.f \
		--Mdir $(VERILATOR_DIR)/program \
		--top-module tb_program --exe --main 2>&1
	cd $(VERILATOR_DIR)/program && make -f Vtb_program.mk -j$$(nproc) 2>&1
	@echo "Build OK. Run: $(VERILATOR_DIR)/program/Vtb_program"

verilator-inst-sim: verilator-inst
	$(VERILATOR_DIR)/instructions/Vtb_instructions 2>&1

verilator-prog-sim: verilator-prog
	$(VERILATOR_DIR)/program/Vtb_program 2>&1

wave-inst:
	@if [ -f "tb_instructions.vcd" ]; then gtkwave tb_instructions.vcd &
	elif [ -f "obj_dir/Vtb_instructions/tb_instructions_verilator.vcd" ]; then gtkwave obj_dir/Vtb_instructions/tb_instructions_verilator.vcd &
	else echo "Run 'make iverilog-inst-sim' or 'make verilator-inst-sim' first"; fi

wave-prog:
	@if [ -f "tb_program.vcd" ]; then gtkwave tb_program.vcd &
	elif [ -f "obj_dir/Vtb_program/tb_program_verilator.vcd" ]; then gtkwave obj_dir/Vtb_program/tb_program_verilator.vcd &
	else echo "Run 'make iverilog-prog-sim' or 'make verilator-prog-sim' first"; fi

c-program:
	$(RISCV_GCC) -march=rv32i -mabi=ilp32 -nostdlib -Ttext 0x0 \
		-o $(ELF) $(C_SRC) 2>&1

COREMARK_SOURCES = \
	scripts/coremark/crt0.S \
	scripts/coremark/core_main.c \
	scripts/coremark/core_list_join.c \
	scripts/coremark/core_matrix.c \
	scripts/coremark/core_state.c \
	scripts/coremark/core_util.c \
	scripts/coremark/core_portme.c

COREMARK_CFLAGS = -I scripts/coremark -DITERATIONS=10 -DVALIDATION_RUN=1 -DTOTAL_DATA_SIZE=2000

# Public EEMBC source + local bare-metal simulation port. This target checks
# correctness only; the simulated tick scale is not a reportable CoreMark score.
COREMARK_RTL_DATA_WORDS ?= 4096
COREMARK_RTL_SOURCES = \
	scripts/coremark/crt0.S \
	$(COREMARK_DIR)/core_main.c \
	$(COREMARK_DIR)/core_list_join.c \
	$(COREMARK_DIR)/core_matrix.c \
	$(COREMARK_DIR)/core_state.c \
	$(COREMARK_DIR)/core_util.c \
	scripts/coremark/core_portme.c
COREMARK_RTL_FLAGS = -O2 -fno-builtin-memset -I$(COREMARK_DIR) -Iscripts/coremark \
	-DITERATIONS=10 -DVALIDATION_RUN=1 -DTOTAL_DATA_SIZE=2000

coremark: coremark.elf coremark-hex iverilog-prog
	@echo "Build OK. Run: make coremark-run"

coremark.elf:
	$(RISCV_GCC) -march=rv32i -mabi=ilp32 -nostdlib -Ttext 0x0 \
		$(COREMARK_CFLAGS) \
		-o coremark.elf $(COREMARK_SOURCES) -lgcc 2>&1

coremark-hex:
	python3 scripts/elf2hex.py coremark.elf hex/inst_mem.hex hex/data_mem.hex

coremark-run: iverilog-prog-sim
	@cat tb_program_results.txt

coremark-rtl-image: coremark-fetch
	mkdir -p $(BUILD_DIR)/coremark-rtl
	$(RISCV_GCC) -march=rv32im_zicsr -mabi=ilp32 -nostdlib -Ttext=0 \
		-Wl,-e,_start $(COREMARK_RTL_FLAGS) -o $(BUILD_DIR)/coremark-rtl/coremark.elf \
		$(COREMARK_RTL_SOURCES) -lgcc

coremark-rtl-program:
	rm -rf $(VERILATOR_DIR)/coremark-program
	mkdir -p $(VERILATOR_DIR)/coremark-program
	$(VERILATOR) --cc --trace --timing -Wno-fatal \
		-GDATA_WORD_COUNT=$(COREMARK_RTL_DATA_WORDS) -f tb/tb_program.f \
		--Mdir $(VERILATOR_DIR)/coremark-program --top-module tb_program --exe --main
	cd $(VERILATOR_DIR)/coremark-program && make -f Vtb_program.mk -j$$(nproc)

coremark-rtl-test: coremark-rtl-image coremark-rtl-program
	python3 scripts/run_coremark_rtl.py \
		--elf $(BUILD_DIR)/coremark-rtl/coremark.elf \
		--sim $(VERILATOR_DIR)/coremark-program/Vtb_program \
		--data-words $(COREMARK_RTL_DATA_WORDS) \
		--build-dir $(BUILD_DIR)/coremark-rtl

hex-from-elf:
	python3 scripts/elf2hex.py $(ELF) hex/inst_mem.hex hex/data_mem.hex

c-run: c-program hex-from-elf iverilog-prog-sim

gen-test-hex:
	python3 scripts/gen_test_hex.py

# Shared architectural CSR-bank and dual-issue CSR serialization regression.
# Verilator is the default fast path; Icarus remains an explicit cross-check.
csr-share-image:
	mkdir -p $(BUILD_DIR)
	$(RISCV_GCC) -march=rv32im_zicsr -mabi=ilp32 -nostdlib \
		-Wl,-Ttext=0 -Wl,-e,_start -o $(BUILD_DIR)/csr_share_test.elf \
		scripts/csr_share_test.S
	python3 scripts/elf2hex.py $(BUILD_DIR)/csr_share_test.elf \
		$(BUILD_DIR)/csr_share_inst.hex $(BUILD_DIR)/csr_share_data.hex

csr-share-test: csr-share-image
	mkdir -p $(VERILATOR_DIR)/csr-share
	$(VERILATOR) --binary --timing -Wno-fatal -f tb/tb_csr_share.f \
		--Mdir $(VERILATOR_DIR)/csr-share --top-module tb_csr_share
	$(VERILATOR_DIR)/csr-share/Vtb_csr_share

csr-share-test-icarus: csr-share-image
	$(IVERILOG) -g2005 -f tb/tb_csr_share.f -o $(BUILD_DIR)/csr_share_test.vvp
	$(VVP) $(BUILD_DIR)/csr_share_test.vvp

# Directed ECALL -> M-mode trap handler -> MRET test.
mtrap-test: mtrap-image
	mkdir -p $(VERILATOR_DIR)/mtrap
	$(VERILATOR) --binary --timing -Wno-fatal -f tb/tb_mtrap.f \
		--Mdir $(VERILATOR_DIR)/mtrap --top-module tb_mtrap
	$(VERILATOR_DIR)/mtrap/Vtb_mtrap

mtrap-test-icarus: mtrap-image
	$(IVERILOG) -g2005 -f tb/tb_mtrap.f -o $(BUILD_DIR)/mtrap_test.vvp
	$(VVP) $(BUILD_DIR)/mtrap_test.vvp

mtrap-image:
	mkdir -p $(BUILD_DIR)
	$(RISCV_GCC) -march=rv32im_zicsr -mabi=ilp32 -nostdlib \
		-Wl,-Ttext=0 -Wl,-e,_start -o $(BUILD_DIR)/mtrap_return_test.elf \
		scripts/mtrap_return_test.S
	python3 scripts/elf2hex.py $(BUILD_DIR)/mtrap_return_test.elf \
		$(BUILD_DIR)/mtrap_inst.hex $(BUILD_DIR)/mtrap_data.hex

illegal-image:
	mkdir -p $(BUILD_DIR)
	$(RISCV_GCC) -march=rv32im_zicsr -mabi=ilp32 -nostdlib \
		-Wl,-Ttext=0 -Wl,-e,_start -o $(BUILD_DIR)/illegal_trap_test.elf \
		scripts/illegal_trap_test.S
	python3 scripts/elf2hex.py $(BUILD_DIR)/illegal_trap_test.elf \
		$(BUILD_DIR)/illegal_inst.hex $(BUILD_DIR)/illegal_data.hex

illegal-test: illegal-image
	mkdir -p $(VERILATOR_DIR)/illegal
	$(VERILATOR) --binary --timing -Wno-fatal -f tb/tb_illegal.f \
		--Mdir $(VERILATOR_DIR)/illegal --top-module tb_illegal
	$(VERILATOR_DIR)/illegal/Vtb_illegal

illegal-test-icarus: illegal-image
	$(IVERILOG) -g2005 -f tb/tb_illegal.f -o $(BUILD_DIR)/illegal_test.vvp
	$(VVP) $(BUILD_DIR)/illegal_test.vvp

csr-legality-image:
	mkdir -p $(BUILD_DIR)
	$(RISCV_GCC) -march=rv32im_zicsr -mabi=ilp32 -nostdlib \
		-Wl,-Ttext=0 -Wl,-e,_start -o $(BUILD_DIR)/csr_legality_test.elf \
		scripts/csr_legality_test.S
	python3 scripts/elf2hex.py $(BUILD_DIR)/csr_legality_test.elf \
		$(BUILD_DIR)/csr_legality_inst.hex $(BUILD_DIR)/csr_legality_data.hex

csr-legality-test: csr-legality-image
	mkdir -p $(VERILATOR_DIR)/csr-legality
	$(VERILATOR) --binary --timing -Wno-fatal -f tb/tb_csr_legality.f \
		--Mdir $(VERILATOR_DIR)/csr-legality --top-module tb_csr_legality
	$(VERILATOR_DIR)/csr-legality/Vtb_csr_legality

csr-legality-test-icarus: csr-legality-image
	$(IVERILOG) -g2005 -f tb/tb_csr_legality.f -o $(BUILD_DIR)/csr_legality_test.vvp
	$(VVP) $(BUILD_DIR)/csr_legality_test.vvp

misaligned-image:
	mkdir -p $(BUILD_DIR)
	$(RISCV_GCC) -march=rv32im_zicsr -mabi=ilp32 -nostdlib \
		-Wl,-Ttext=0 -Wl,-e,_start -o $(BUILD_DIR)/misaligned_trap_test.elf \
		scripts/misaligned_trap_test.S
	python3 scripts/elf2hex.py $(BUILD_DIR)/misaligned_trap_test.elf \
		$(BUILD_DIR)/misaligned_inst.hex $(BUILD_DIR)/misaligned_data.hex

misaligned-test: misaligned-image
	mkdir -p $(VERILATOR_DIR)/misaligned
	$(VERILATOR) --binary --timing -Wno-fatal -f tb/tb_misaligned.f \
		--Mdir $(VERILATOR_DIR)/misaligned --top-module tb_misaligned
	$(VERILATOR_DIR)/misaligned/Vtb_misaligned

misaligned-test-icarus: misaligned-image
	$(IVERILOG) -g2005 -f tb/tb_misaligned.f -o $(BUILD_DIR)/misaligned_test.vvp
	$(VVP) $(BUILD_DIR)/misaligned_test.vvp

msip-interrupt-image:
	mkdir -p $(BUILD_DIR)
	$(RISCV_GCC) -march=rv32im_zicsr -mabi=ilp32 -nostdlib \
		-Wl,-Ttext=0 -Wl,-e,_start -o $(BUILD_DIR)/msip_interrupt_test.elf \
		scripts/msip_interrupt_test.S
	python3 scripts/elf2hex.py $(BUILD_DIR)/msip_interrupt_test.elf \
		$(BUILD_DIR)/msip_interrupt_inst.hex $(BUILD_DIR)/msip_interrupt_data.hex

msip-interrupt-test: msip-interrupt-image
	mkdir -p $(VERILATOR_DIR)/msip-interrupt
	$(VERILATOR) --binary --timing -Wno-fatal -f tb/tb_msip_interrupt.f \
		--Mdir $(VERILATOR_DIR)/msip-interrupt --top-module tb_msip_interrupt
	$(VERILATOR_DIR)/msip-interrupt/Vtb_msip_interrupt

msip-interrupt-test-icarus: msip-interrupt-image
	$(IVERILOG) -g2005 -f tb/tb_msip_interrupt.f -o $(BUILD_DIR)/msip_interrupt_test.vvp
	$(VVP) $(BUILD_DIR)/msip_interrupt_test.vvp

inst-misaligned-image:
	mkdir -p $(BUILD_DIR)
	$(RISCV_GCC) -march=rv32im_zicsr -mabi=ilp32 -nostdlib \
		-Wl,-Ttext=0 -Wl,-e,_start -o $(BUILD_DIR)/inst_misaligned_test.elf \
		scripts/inst_misaligned_test.S
	python3 scripts/elf2hex.py $(BUILD_DIR)/inst_misaligned_test.elf \
		$(BUILD_DIR)/inst_misaligned_inst.hex $(BUILD_DIR)/inst_misaligned_data.hex

inst-misaligned-test: inst-misaligned-image
	mkdir -p $(VERILATOR_DIR)/inst-misaligned
	$(VERILATOR) --binary --timing -Wno-fatal -f tb/tb_inst_misaligned.f \
		--Mdir $(VERILATOR_DIR)/inst-misaligned --top-module tb_inst_misaligned
	$(VERILATOR_DIR)/inst-misaligned/Vtb_inst_misaligned

inst-misaligned-test-icarus: inst-misaligned-image
	$(IVERILOG) -g2005 -f tb/tb_inst_misaligned.f -o $(BUILD_DIR)/inst_misaligned_test.vvp
	$(VVP) $(BUILD_DIR)/inst_misaligned_test.vvp

atomic-image:
	mkdir -p $(BUILD_DIR)/atomic
	$(RISCV_GCC) -march=rv32ima_zicsr -mabi=ilp32 -nostdlib \
		-Wl,-Ttext=0 -Wl,-e,_start -o $(BUILD_DIR)/atomic/test.elf \
		scripts/atomic_test.S
	python3 scripts/elf2hex.py $(BUILD_DIR)/atomic/test.elf \
		$(BUILD_DIR)/atomic/inst.hex $(BUILD_DIR)/atomic/data.hex

atomic-test: atomic-image
	mkdir -p $(VERILATOR_DIR)/atomic
	$(VERILATOR) --binary --timing -Wno-fatal -f tb/tb_atomic.f \
		--Mdir $(VERILATOR_DIR)/atomic --top-module tb_atomic
	$(VERILATOR_DIR)/atomic/Vtb_atomic

atomic-test-icarus: atomic-image
	$(IVERILOG) -g2005 -f tb/tb_atomic.f -o $(BUILD_DIR)/atomic_test.vvp
	$(VVP) $(BUILD_DIR)/atomic_test.vvp

linux-initramfs: $(LINUX_INITRD)

$(LINUX_INITRD): platform/linux/init.S platform/linux/flat_init.ld scripts/pack_bflt.py
	mkdir -p $(BUILD_DIR)/linux-boot/initramfs-root/dev \
		$(BUILD_DIR)/linux-boot/initramfs-root/proc $(BUILD_DIR)/linux-boot/initramfs-root/sys
	$(RISCV_LINUX_GCC) -march=rv32ima_zicsr -mabi=ilp32 -nostdlib -static \
		-Wl,-e,_start -Wl,-T,platform/linux/flat_init.ld -Wl,--no-relax -Wl,--build-id=none \
		-o $(BUILD_DIR)/linux-boot/init.flat.elf platform/linux/init.S
	$(RISCV_LINUX_OBJCOPY) -O binary -j .text \
		$(BUILD_DIR)/linux-boot/init.flat.elf $(BUILD_DIR)/linux-boot/init.text.bin
	python3 scripts/pack_bflt.py $(BUILD_DIR)/linux-boot/init.text.bin \
		$(BUILD_DIR)/linux-boot/initramfs-root/init
	chmod 0755 $(BUILD_DIR)/linux-boot/initramfs-root/init
	cd $(BUILD_DIR)/linux-boot/initramfs-root && \
		find . -print0 | LC_ALL=C sort -z | cpio --null -o --format=newc > ../initramfs.cpio

linux-boot-vmlinux: $(LINUX_BOOT_VMLINUX)

$(LINUX_BOOT_VMLINUX): $(LINUX_VMLINUX) scripts/patch_linux_cmdline.py
	@test -f "$(LINUX_VMLINUX)" || { echo "Missing RV32 no-MMU vmlinux: $(LINUX_VMLINUX)"; exit 1; }
	python3 scripts/patch_linux_cmdline.py "$(LINUX_VMLINUX)" "$@" \
		--match "$(LINUX_CMDLINE_OLD)" --replace "$(LINUX_CMDLINE)"

linux-boot-image: $(LINUX_BOOT_VMLINUX) $(LINUX_INITRD)
	mkdir -p $(BUILD_DIR)/linux-boot
	dtc -I dts -O dtb -o $(BUILD_DIR)/linux-boot/rv32-nommu.dtb platform/linux/rv32-nommu.dts
	python3 scripts/patch_linux_dtb_initrd.py $(BUILD_DIR)/linux-boot/rv32-nommu.dtb \
		$(LINUX_INITRD) --addr $(LINUX_INITRD_ADDR)
	python3 scripts/elf2linux_splithex.py "$(LINUX_BOOT_VMLINUX)" \
		$(BUILD_DIR)/linux-boot/inst.hex $(BUILD_DIR)/linux-boot/data.hex \
		--base 0x80000000 --inst-words $(LINUX_INST_WORDS) \
		--data-words $(LINUX_RAM_WORDS) --overlay $(BUILD_DIR)/linux-boot/rv32-nommu.dtb \
		--overlay-addr $(LINUX_DTB_ADDR) --initrd $(LINUX_INITRD) \
		--initrd-addr $(LINUX_INITRD_ADDR)

linux-boot-test: linux-boot-image
	mkdir -p $(VERILATOR_DIR)/linux-boot
	$(VERILATOR) --binary --timing -Wno-fatal -f tb/tb_linux_boot.f \
		-GLINUX_INST_WORDS=$(LINUX_INST_WORDS) -GLINUX_RAM_WORDS=$(LINUX_RAM_WORDS) \
		-GLINUX_DTB_ADDR=$(LINUX_DTB_ADDR) -GLINUX_TIMER_IRQ=$(LINUX_TIMER_IRQ) \
		--Mdir $(VERILATOR_DIR)/linux-boot --top-module tb_linux_boot
	$(VERILATOR_DIR)/linux-boot/Vtb_linux_boot +max_cycles=$(LINUX_MAX_CYCLES) \
		> $(BUILD_DIR)/linux-boot/linux-boot.log 2>&1; status=$$?; cat $(BUILD_DIR)/linux-boot/linux-boot.log; \
		test $$status -eq 0 && grep -q "Linux version" $(BUILD_DIR)/linux-boot/linux-boot.log && \
		! grep -Eq "Kernel panic|Kernel BUG|Oops:" $(BUILD_DIR)/linux-boot/linux-boot.log && \
		grep -Fq "[LINUX_BOOT_SUCCESS]" $(BUILD_DIR)/linux-boot/linux-boot.log || \
		{ echo "FAIL: Linux boot not demonstrated (requires no fatal kernel error and [LINUX_BOOT_SUCCESS] from userspace init)."; exit 1; }

supervisor-image:
	mkdir -p $(BUILD_DIR)
	$(RISCV_GCC) -march=rv32im_zicsr -mabi=ilp32 -nostdlib \
		-Wl,-Ttext=0 -Wl,-e,_start -o $(BUILD_DIR)/supervisor_trap_test.elf \
		scripts/supervisor_trap_test.S
	python3 scripts/elf2hex.py $(BUILD_DIR)/supervisor_trap_test.elf \
		$(BUILD_DIR)/supervisor_trap_inst.hex $(BUILD_DIR)/supervisor_trap_data.hex

supervisor-test: supervisor-image
	mkdir -p $(VERILATOR_DIR)/supervisor
	$(VERILATOR) --binary --timing -Wno-fatal -f tb/tb_supervisor_trap.f \
		--Mdir $(VERILATOR_DIR)/supervisor --top-module tb_supervisor_trap
	$(VERILATOR_DIR)/supervisor/Vtb_supervisor_trap

supervisor-test-icarus: supervisor-image
	$(IVERILOG) -g2005 -f tb/tb_supervisor_trap.f -o $(BUILD_DIR)/supervisor_test.vvp
	$(VVP) $(BUILD_DIR)/supervisor_test.vvp

# Preserve and assert the architectural outputs from the small C smoke programs.
c-smoke-test: verilator-prog
	python3 scripts/run_c_smoke.py --gcc "$(RISCV_GCC)" \
		--sim "$(VERILATOR_DIR)/program/Vtb_program" --build-dir "$(BUILD_DIR)/c-smoke"

# Sequential by design: these recipes rebuild under the shared Verilator path.
fast-test:
	$(MAKE) gen-test-hex
	$(MAKE) verilator-inst-sim
	$(MAKE) csr-share-test
	$(MAKE) mtrap-test
	$(MAKE) illegal-test
	$(MAKE) csr-legality-test
	$(MAKE) misaligned-test
	$(MAKE) msip-interrupt-test
	$(MAKE) inst-misaligned-test
	$(MAKE) supervisor-test
	$(MAKE) atomic-test
	$(MAKE) c-smoke-test

verilator-regression: fast-test

# Fetch only public upstream source repositories; retain the pinned checkout if present.
coremark-fetch:
	@if [ -d "$(COREMARK_DIR)/.git" ]; then echo "CoreMark source present: $(COREMARK_DIR)"; \
	else git clone https://github.com/eembc/coremark.git "$(COREMARK_DIR)"; fi

riscv-tests-fetch:
	@if [ -d "$(RISCV_TESTS_DIR)/.git" ]; then echo "RISC-V tests source present: $(RISCV_TESTS_DIR)"; \
	else git clone https://github.com/riscv-software-src/riscv-tests.git "$(RISCV_TESTS_DIR)"; fi
	git -C "$(RISCV_TESTS_DIR)" submodule update --init --recursive

riscv-tests: riscv-tests-fetch
	python3 scripts/run_riscv_suite.py --repo "$(RISCV_TESTS_DIR)" --suite all

rv32ui-tests: riscv-tests-fetch
	python3 scripts/run_riscv_suite.py --repo "$(RISCV_TESTS_DIR)" --suite rv32ui

rv32um-tests: riscv-tests-fetch
	python3 scripts/run_riscv_suite.py --repo "$(RISCV_TESTS_DIR)" --suite rv32um

rv32ua-tests: riscv-tests-fetch
	python3 scripts/run_riscv_suite.py --repo "$(RISCV_TESTS_DIR)" --suite rv32ua

riscv-isa-tests: riscv-tests

spike-check:
	spike --ISA=rv32i hello.elf 2>&1 || spike pk hello.elf 2>&1 || echo "Spike not available"

spike-coremark: coremark.elf
	@echo "Running CoreMark on Spike..."
	spike --isa=rv32i coremark.elf 2>&1 || echo "Spike not available or needs PK"

verilator-coremark: coremark.elf
	python3 scripts/elf2hex.py coremark.elf hex/inst_mem.hex hex/data_mem.hex
	rm -rf $(VERILATOR_DIR)/program
	mkdir -p $(VERILATOR_DIR)/program
	$(VERILATOR) --cc --trace --timing -Wno-fatal -f tb/tb_program.f --Mdir $(VERILATOR_DIR)/program --top-module tb_program --exe --main 2>&1 | tail -3
	cd $(VERILATOR_DIR)/program && make -f Vtb_program.mk -j4 2>&1 | tail -2
	$(VERILATOR_DIR)/program/Vtb_program 2>&1 | tail -20

verilator-bench: verilator-prog-sim
	@echo "===== VERILATOR BENCHMARK RESULTS ====="
	@grep "Total cycles" tb_program_results.txt
	@echo "Final PC:     $$(grep 'Final PC' tb_program_results.txt | awk '{print $$3}')"
	@echo "========================================="

bench-fib:
	$(RISCV_GCC) -march=rv32i -mabi=ilp32 -nostdlib -Ttext 0x0 -o fib.elf scripts/fibonacci.c
	python3 scripts/elf2hex.py fib.elf hex/inst_mem.hex hex/data_mem.hex
	rm -rf $(VERILATOR_DIR)/program
	mkdir -p $(VERILATOR_DIR)/program
	$(VERILATOR) --cc --trace --timing -Wno-fatal -f tb/tb_program.f --Mdir $(VERILATOR_DIR)/program --top-module tb_program --exe --main 2>&1 | tail -3
	cd $(VERILATOR_DIR)/program && make -f Vtb_program.mk -j4 2>&1 | tail -2
	$(VERILATOR_DIR)/program/Vtb_program 2>&1 | tail -5
	@echo "===== BENCHMARK RESULTS ====="
	@grep "Total cycles" tb_program_results.txt

bench-min:
	$(RISCV_GCC) -march=rv32i -mabi=ilp32 -nostdlib -Ttext 0x0 -o min.elf scripts/min_bench.c
	python3 scripts/elf2hex.py min.elf hex/inst_mem.hex hex/data_mem.hex
	rm -rf $(VERILATOR_DIR)/program
	mkdir -p $(VERILATOR_DIR)/program
	$(VERILATOR) --cc --trace --timing -Wno-fatal -f tb/tb_program.f --Mdir $(VERILATOR_DIR)/program --top-module tb_program --exe --main 2>&1 | tail -3
	cd $(VERILATOR_DIR)/program && make -f Vtb_program.mk -j4 2>&1 | tail -2
	$(VERILATOR_DIR)/program/Vtb_program 2>&1 | tail -5
	@echo "===== BENCHMARK RESULTS ====="
	@grep "Total cycles" tb_program_results.txt

benchmark: c-run
	@echo "Running benchmark..."
	@echo "Fibonacci (10 terms):"
	@echo "Cycles: $$(grep 'Total cycles' tb_program_results.txt | awk '{print $$3}')"

clean: clean-build
	rm -f *.vcd *.log hello.elf disasm.txt
	rm -f tb_instructions_results.txt tb_program_results.txt
	rm -f tb_instructions_sim.vvp tb_program_sim.vvp

clean-build:
	rm -rf $(VERILATOR_DIR)
	mkdir -p $(VERILATOR_DIR)/instructions $(VERILATOR_DIR)/program

help:
	@echo "RV32 dual-issue in-order superscalar core"
	@echo "=============================="
	@echo "make iverilog-inst      - Build instruction tests with Icarus"
	@echo "make iverilog-prog      - Build C-program with Icarus"
	@echo "make verilator-inst     - Build instruction tests with Verilator"
	@echo "make verilator-prog     - Build C-program with Verilator"
	@echo "make iverilog-inst-sim  - Build and run instruction tests"
	@echo "make iverilog-prog-sim  - Build and run C-program"
	@echo "make verilator-inst-sim - Build and run instruction tests"
	@echo "make verilator-prog-sim - Build and run C-program"
	@echo "make c-smoke-test       - Assert hello/fibonacci/binary-search outputs"
	@echo "make wave-inst          - Open instruction test waveforms"
	@echo "make wave-prog          - Open C-program waveforms"
	@echo "make gen-test-hex       - Generate instruction test hex files"
	@echo "make csr-share-test     - Verilator CSR bank/lane serialization test"
	@echo "make mtrap-test         - Verilator M-mode trap and MRET test"
	@echo "make illegal-test       - Verilator illegal-instruction precise-trap test"
	@echo "make csr-legality-test  - Verilator CSR access legality/trap test"
	@echo "make misaligned-test    - Verilator optional load/store misalignment test"
	@echo "make msip-interrupt-test - Verilator M-mode software interrupt test"
	@echo "make inst-misaligned-test - Verilator instruction-target alignment test"
	@echo "make supervisor-test    - Verilator M/S/U transition and delegation test"
	@echo "make atomic-test        - Verilator LR/SC and AMO.W functional test"
	@echo "make linux-boot-test    - Boot the built RV32 no-MMU Linux kernel on RTL"
	@echo "make fast-test          - Run the Verilator-first directed regression"
	@echo "make csr-share-test-icarus - Optional Icarus CSR cross-check"
	@echo "make mtrap-test-icarus  - Optional Icarus M-mode cross-check"
	@echo "make illegal-test-icarus - Optional Icarus illegal-trap cross-check"
	@echo "make csr-legality-test-icarus - Optional Icarus CSR legality cross-check"
	@echo "make misaligned-test-icarus - Optional Icarus misalignment cross-check"
	@echo "make msip-interrupt-test-icarus - Optional Icarus MSIP cross-check"
	@echo "make inst-misaligned-test-icarus - Optional Icarus instruction-alignment cross-check"
	@echo "make supervisor-test-icarus - Optional Icarus supervisor-mode cross-check"
	@echo "make atomic-test-icarus   - Optional Icarus RV32A cross-check"
	@echo "make coremark-fetch     - Fetch the public EEMBC CoreMark repository"
	@echo "make coremark-rtl-test  - Run CoreMark functional validation on RTL"
	@echo "make riscv-tests-fetch  - Fetch public RISC-V tests and init env submodule"
	@echo "make riscv-tests        - Run RV32UI, RV32UM, and RV32UA suites with Verilator"
	@echo "make rv32ui-tests       - Run RV32I user ISA suite with Verilator"
	@echo "make rv32um-tests       - Run RV32M user ISA suite with Verilator"
	@echo "make rv32ua-tests       - Run RV32A user ISA suite with Verilator"
	@echo "make c-program          - Compile C test program"
	@echo "make hex-from-elf       - Convert selected ELF to hex"
	@echo "make c-run              - Compile C, convert hex, run program TB"
	@echo "  Example: make c-run C_SRC=scripts/fibonacci.c ELF=fibonacci.elf"
	@echo "make coremark           - Build CoreMark benchmark for RTL"
	@echo "make spike-coremark     - Run CoreMark on Spike (fast, accurate)"
	@echo "make riscv-isa-tests    - Alias for the RV32UI/RV32UM suite run"
	@echo "make spike-check        - Run ELF on Spike for reference"
	@echo "make clean              - Remove build artifacts"
