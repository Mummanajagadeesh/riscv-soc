# Linux bring-up debug log

This is the running incident log for the selected dual-issue RV32 core. Each entry records what failed or looked suspicious, how it was observed, the fix, and the verification loop. New issues should be appended here as work proceeds.

## 2026-09-30 — Baseline and tooling

### 1. Host tools were not on PATH in the resumed workspace

- **Observed:** the first repository build failed with `/bin/sh: iverilog: not found`, although an earlier session had reported the package installed.
- **Diagnosis:** the resumed shell did not contain the prior system package state.
- **Fix:** reran `bash /home/user/rv32i-linux-work/setup/install-host-tools.sh` and then `bash /home/user/rv32i-linux-work/scripts/check-env.sh`.
- **Re-test:** smoke check passed for Verilator, Icarus, RV32 cross-compilers, QEMU `virt`, and DTC.

### 2. ELF conversion assumed a toolchain executable name that was absent

- **Observed:** `make c-run` compiled the C program, then `scripts/elf2hex.py` failed looking for `riscv32-unknown-elf-objdump`.
- **Diagnosis:** Debian provides `riscv64-unknown-elf-*` commands here; these tools still process ELF32 RV32 files.
- **Fix:** added prefix discovery and `RISCV_OBJDUMP`, `RISCV_OBJCOPY`, and `RISCV_PREFIX` overrides.
- **Re-test:** the unmodified `make c-run` flow now converts and runs hello/fibonacci/binary-search without aliases.

### 3. Verilator silently ran the instruction test with zero assertions

- **Observed:** `make verilator-inst-sim` returned success but printed `Loaded 0 final register checks` and `SOME TESTS FAILED`; Icarus loaded all 31 checks.
- **Diagnosis:** Verilator's behavior differed for the testbench's packed-line `$fgets` followed by `$sscanf` parser. The testbench also ended with `$finish`, so a failed/empty test looked like a successful process exit.
- **Fix:** read each CSV record directly with `$fscanf`; use `$fatal` when the file is empty, the program fails to halt, or any expected value mismatches.
- **Re-test:** both simulators loaded 31 expectations and reported 31/31. Failed/empty runs now return nonzero.

### 4. The original Verilator build recipe could remove tracked artifacts

- **Observed:** `clean-build` recursively deleted `obj_dir`, which contains 31 tracked generated files.
- **Diagnosis:** source build products and committed repository artifacts shared the same path.
- **Fix:** directed Verilator into ignored `build/verilator/` subdirectories and made `clean-build` remove only that build area.
- **Re-test:** instruction and CSR tests build/run from the new directory; all 31 tracked `obj_dir` files remain present.

## 2026-09-30 — First architectural CSR slice

### 5. CSR state was duplicated by issue lane and indexed by only four address bits

- **Observed:** RTL inspection found separate `csr_reg` instances for slot 0 and slot 1; the CSR array indexed `addr[3:0]`. A write from one lane could be invisible to the other, and unrelated CSRs could alias.
- **Fix:** replaced the lane-local arrays with one shared machine CSR bank, decoded implemented CSR addresses across all 12 address bits, and serialized/replayed slot 1 when slot 0 contains a CSR operation.
- **Re-test:** `tb_csr_share` verifies a slot-1 write is visible to a later slot-0 read and that an unimplemented CSR address does not alias `mtvec`.

### 6. CSR immediate instructions initially used the wrong source

- **Observed:** directed assembly includes `CSRRWI`, `CSRRSI`, and `CSRRCI`, because the old datapath selected the integer register value instead of the encoded five-bit `zimm` for immediate forms.
- **Fix:** select `zimm` from the instruction's `rs1` field for immediate CSR operations; retain the forwarded integer source for register forms.
- **Re-test:** check old/new CSR values and CSRRSI/CSRRCI masks in both simulators.

### 7. Back-to-back CSR operations exposed a stale-value ordering issue

- **Observed:** after adding adjacent immediate set/clear operations, `make csr-share-test` failed: expected `x31=0x0000000e`, got `x31=0x00000006`. A focused Verilator/Icarus signal trace showed the following CSR operation could observe the preceding CSR value before the single CSR write port had updated.
- **Fix:** added an inter-CSR dependency interlock: hold IF/ID and inject a bubble while a CSR is in decode and an older CSR is in execute. Normal arithmetic dual issue remains enabled.
- **Re-test:** CSR test passes in both simulators in 23 cycles, including `7 -> 15 -> 14`; instruction and C-program regressions retain their previous results.

## Current workflow preference

Use Verilator as the primary simulator for new architectural tests and long-running programs. Icarus remains a secondary cross-check for small directed tests or simulator-specific debugging. Keep the testbench's `$fatal` checks enabled so a fast run cannot silently pass with zero assertions.

## 2026-09-30 — M-mode synchronous trap/return slice

### 8. The resumed workspace did not retain the cross-toolchain packages

- **Observed:** the first `make mtrap-test` attempt stopped at `riscv64-unknown-elf-gcc: No such file or directory`; shell lookup found no cross-compiler even though the earlier environment log recorded a successful setup.
- **Diagnosis:** host packages were absent in this resumed environment, not a source/build-rule problem.
- **Fix:** reran `/home/user/rv32i-linux-work/setup/install-host-tools.sh` successfully; this installed the RISC-V toolchains, Verilator, and Icarus again.
- **Re-test:** `make mtrap-test` compiled and ran; a subsequent full `make fast-test` also completed.

### 9. SYSTEM opcode aliases were not enough for real trap entry/return

- **Observed:** M-mode bring-up needed ECALL/EBREAK to update architectural trap CSRs and redirect fetch, and MRET to restore status and resume at `mepc`; previously ECALL was only a simulation halt.
- **Fix:** added exact SYSTEM immediate decoding for ECALL, EBREAK, MRET and WFI; added one shared M-mode state path for `mtvec`, `mepc`, `mcause`, `mtval`, `mstatus` and current privilege; connected ID-stage synchronous traps and MRET redirects to that state. Synchronous traps use direct-mode `mtvec`, align `mepc` to 4 bytes, and implement the MIE/MPIE/MPP stack. A new `ECALL_HALT` top-level parameter defaults to `1` to retain old program-test termination, while the trap test sets it to `0`. System/CSR instructions are serialized across issue lanes and behind an older CSR write.
- **Re-test:** new assembly/testbench exercises slot-1 ECALL replay, ECALL cause 11, a slot-1 EBREAK replay, breakpoint cause 3, handler CSR reads, adjusted `mepc`, MRET, and MIE/MPIE/MPP restoration. `make mtrap-test` passes under Verilator in 37 cycles; `make mtrap-test-icarus` also passes in 37 cycles.

### 10. Verilator-first regression after M-mode changes

- **Re-test:** `make fast-test` passes the 31/31 instruction checks, shared-CSR/immediate/replay test (25 cycles), and ECALL/EBREAK/MRET test (37 cycles). Optional `make csr-share-test-icarus` passes (25 cycles).
- **C smoke tests:** Verilator runs halted normally for hello (21 cycles), Fibonacci (238), and binary search (424). Relative to the older logged counts (19/238/422), hello and binary search each used two more cycles after SYSTEM lane serialization; functional halt was confirmed. Source `hex/` and tracked result artifacts were restored after the run.

## 2026-09-30 — upstream ISA suites and byte-memory fixes

### 11. Public benchmark and compliance sources fetched

- **Action:** cloned the requested public repositories beside the design: `eembc/coremark` at `1f483d5b8316753a742cbf5590caf5bd0a4e4777` and `riscv-software-src/riscv-tests` at `933a897d8631773f385d45938facc466dddc7514`; initialized the RISC-V tests `env` submodule at `6de71edb142be36319e380ce782c3d1830c65d68`.
- **Build integration:** added `coremark-fetch`, `riscv-tests-fetch`, `riscv-tests`, `rv32ui-tests`, and `rv32um-tests` Make targets. The Verilator suite runner discovers ELF `tohost` through the symbol table (the address varies by test), reports architectural fatal messages on failure, and supports selecting individual tests.

### 12. RV32UI byte accesses exposed same-pair store/load hazards

- **Observed:** official `sh` and `ma_data` failed around unaligned and mixed-width stores/loads. `ma_data` exposed accesses that cross aligned word boundaries; `sh` exercised a younger load paired with an older store.
- **Fix:** data memory now assembles and writes accesses byte-by-byte and forwards each overlapping byte from the older slot-0 store to the younger slot-1 load within the same issue pair.
- **Re-test:** targeted `sh` and `ma_data` pass (371 and 347 cycles). Full RV32UI then passes **41/42**; all tests except `fence_i` pass. `fence_i` remains blocked by the current separate instruction/data memories and is deferred until the unified/coherent memory phase.

### 13. RV32M division and high-product fixes

- **Observed:** initial RV32UM was 3/8. A standalone ALU check showed signed `-20 / 6` returning the unsigned quotient `0x2aaaaaa7` for both DIV and DIVU. The conditional operator caused Verilog to propagate unsignedness into its signed expression. DIVU-by-zero also returned `1`, and high-half multiply operands/products were not explicitly 64-bit.
- **Fix:** DIV/REM cases now use explicit procedural branches for zero/overflow corner cases; DIVU-by-zero returns `0xffffffff`. MULH/MULHSU/MULHU use explicit 64-bit sign/zero-extended operands and select product bits `[63:32]`.
- **Re-test:** full RV32UM passes **8/8** (`div`, `divu`, `mul`, `mulh`, `mulhsu`, `mulhu`, `rem`, `remu`). `make riscv-tests` now verifies the complete combined result: **49/50** across RV32UI+RV32UM. The only failure is `fence_i`, which does not reach `tohost` before the 1,000,001-cycle timeout (PC `0x80e3f154`), consistent with the absent instruction/data coherence. The runner now reports this fatal reason directly.

### 14. Final regression after width cleanup

- **Cleanup:** made the 5-bit ALU operation encodings explicit for the RV32M operations and zero-extended byte offsets used by the new data-memory path, eliminating the width-expansion warnings from those edits.
- **Re-test:** latest `make fast-test` passes 31/31 instruction checks, the CSR replay test (25 cycles), and the M-trap test (37 cycles). A small optional Icarus ALU cross-check also passes signed divide/remainder, divide-by-zero, signed overflow, and MULH/MULHSU/MULHU cases. Latest `make riscv-tests` confirms **49/50**; the one expected/deferred `fence_i` timeout is recorded above. The overall Make target returns nonzero on this still-unimplemented coherence test, as it should.

## 2026-09-30 — M-mode ordering, counters, and FENCE.I bring-up

### 15. Host tool packages were absent again in the resumed workspace

- **Observed:** the first runs of `make csr-share-test` and `make mtrap-test` stopped because `riscv64-unknown-elf-gcc` was not on PATH.
- **Fix:** reran `/home/user/rv32i-linux-work/setup/install-host-tools.sh` successfully before continuing.

### 16. ID-stage trap and return events could kill older in-flight work

- **Observed:** the earlier ECALL/EBREAK path fired from ID immediately and flushed ID/EX; an older ordinary instruction in ID/EX could therefore be lost. MRET also needed to wait for handler-side effects to drain.
- **Fix:** trap, MRET, and later FENCE.I events now hold IF/ID and inject bubbles into ID/EX while older ID/EX, EX/MEM, and MEM/WB entries drain. EX/MEM and WB continue, so older stores/register writes commit. The IF/ID serial-flush condition was adjusted to preserve the held event during drain.
- **Directed verification:** the M-trap test aligns an older slot-1 register write before an ECALL and a younger slot-1 write after it. The handler verifies the older value is visible and the younger value is still zero; MRET drain/return, EBREAK cause, EPC, MSTATUS are also checked. `make mtrap-test` and `make mtrap-test-icarus` pass in 51 cycles.

### 17. Machine counters added and exercised

- **Fix:** implemented 64-bit `mcycle`/`minstret`, machine low/high CSRs, read-only `cycle`/`time`/`instret` aliases, and high halves. Until a timer device exists, `time` is a documented alias of simulation cycle ticks. The retire count includes valid dual-issue WB instructions and the serialized MRET/FENCE.I events; ECALL trap/halt is excluded.
- **Verification:** CSR assembly reads cycle/time/instret and machine aliases, checks monotonic values and zero high halves. Verilator and Icarus CSR tests pass (37 cycles each).

### 18. FENCE.I and self-modifying code now pass the official test

- **Observed:** store-to-instruction mirroring alone was insufficient because `rv32ui/fence_i` deliberately jumps into initialized code located in `.data`; the return instruction there was missing from the instruction image. The instruction regression also uses overlapping Harvard test images, so unconditional instruction writes corrupted that unrelated test.
- **Fix:** decode and serialize FENCE.I, drain older memory effects, then flush/refetch from `PC+4`. Added byte-store mirroring to both instruction-read copies behind `COHERENT_CODE_WRITES`; it defaults off for the generic Harvard-style top and is enabled by the official compliance testbench. `elf2hex.py` now places initialized `.data`/`.sdata` in the instruction image as well as the data image, for executable data-section cases.
- **Verification:** targeted `fence_i` passes in 423 cycles. Full `make riscv-tests` passes **50/50** (RV32UI 42/42, RV32UM 8/8). Latest `make fast-test` passes 31/31 instruction checks, the CSR/counter test (37 cycles), and the precise M-trap test (51 cycles). The Icarus CSR and M-trap cross-checks also pass.

### 19. C smoke output checks caught a taken-branch/slot-1 replay loss

- **Observed:** an experiment making coherent code writes the generic top default caused binary search's pass marker to change from `1` to `0`; the Harvard smoke programs intentionally write results around `0x100`, which overlaps the fetch image. Coherence therefore remains **off by default** for `rv32i_top`; `tb_riscv_test` explicitly enables it for the official `fence_i` test. This is not a substitute for shared physical RAM.
- **Observed:** once the C output was checked rather than merely observing ECALL, Fibonacci exposed incorrect words after its second loop iteration (`mem[66]` became `0x2200`). Pipeline tracing showed that a predicted-taken loop branch held in ID during a hazard stall had a younger ECALL in slot 1. The slot-1 system squash then flushed IF/ID after the branch target group was already at the fetch PC, dropping the target's slot-0 load and its dependent SLLI. A stale index consequently generated unaligned output stores.
- **Fix:** when slot 1 is a privileged/system instruction younger than a predicted-taken slot-0 control transfer, squash the younger instruction but do not flush the incoming IF group; retain the predicted branch target fetch. Mispredicted branches still use the redirect/flush path.
- **Regression:** added `scripts/check_c_smoke.py`, `scripts/run_c_smoke.py`, and `make c-smoke-test`; included this output-checking target in `make fast-test`. The runner restores prior `hex/` images and `tb_program_results.txt` even if a program fails.
- **Verification:** final `make fast-test` passes the 31/31 instruction test, shared CSR/counter test (37 cycles), precise M-trap test (51 cycles), and all three asserted C outputs: hello 21 cycles (`30,1`), Fibonacci 238 cycles (`0,1,1,2,3,5,8,13,21,34`), binary search 424 cycles (`4,7,0xffffffff,0,1`). The same three output assertions also pass under Icarus (21/238/424 cycles). Final `make riscv-tests` passes **50/50** (RV32UI 42/42; RV32UM 8/8), including `fence_i` at 423 cycles. Icarus CSR/M-trap cross-checks pass at 37/51 cycles.

### 20. Public CoreMark required a bare-metal clock/marker port and larger data RAM

- **Observed:** linking the public CoreMark sources with `-nostdlib` failed on `memset`; the custom port's clock stub also never advanced, and its no-op `ee_printf` gave the testbench no way to distinguish a validated run from a failed one. The default 8 KiB data RAM also wrapped the ELF's `.rodata`/`.data` over the high-address stack region.
- **Fix:** added a local-only bare-metal `memset`, reads of the architectural `rdcycle` CSR, and a simulation-only `ee_printf` validation marker (success is emitted only after CoreMark's own seed/CRC/type checks; its error reports set a failure marker). Parameterized data RAM depth and ELF-to-hex output size; CoreMark uses 4096 words/16 KiB so its code image, data, and stack do not alias. The port labels ticks as simulation units, explicitly not seconds/score data.
- **Integration:** `make coremark-rtl-test` builds the **cloned public CoreMark sources** with the local platform port and Verilator, uses the validation seed/data-size configuration, enforces a 50M-cycle timeout, checks the success marker, and restores existing hex/results files.
- **Verification:** `make coremark-rtl-test` passes internal CoreMark validation: marker `0xc0decafe`, **2,336,216 cycles**, **3,167,341 retired instructions**. This is a correctness workload only; no performance score is claimed.
- **Source-integrity check:** `make -C ../coremark check` reports every listed source except `coremark.h` OK. The manifest's expected digest for `coremark.h` does not match the pinned commit's tracked file; `git show HEAD:coremark.h` and the working file match each other, and the upstream core source files are not modified. This is a stale/inconsistent upstream checksum manifest, not an RTL validation failure.

### 21. Unsupported and invalid instruction encodings needed architectural illegal-instruction traps

- **Observed:** the control decoder did not distinguish unsupported opcodes or invalid encodings of otherwise recognized instructions from executable decode paths, so these could flow onward rather than raising the M-mode illegal-instruction exception.
- **Fix:** strict legality checks now produce an illegal indication for unsupported opcodes/encodings. The core traps through slot 0 with `mcause=2`, records the 32-bit instruction in `mtval`, and uses the existing precise trap drain/squash path. Added an illegal-instruction directed program and Verilator/Icarus testbenches. The test checks cause and trap value, that an older slot-1 write is committed before trap handling, that a younger slot-1 write is suppressed at the handler, and that MRET resumes correctly. Added `make illegal-test` to `fast-test` and an `illegal-test-icarus` cross-check.
- **Verification:** `make illegal-test` and `make illegal-test-icarus` pass (28 cycles); the updated full `make fast-test` passes shared CSR/counters (37 cycles), precise ECALL/EBREAK/MRET (51), illegal trap (28), and all three C smoke output assertions (21/238/424 cycles). `make riscv-tests` after decoder integration passed 50/50 (RV32UI 42/42, RV32UM 8/8).
- **Scope:** this is partial Milestone 1 progress only. Misalignment/access exceptions, complete CSR/system access legality, interrupt state and priority remain unfinished; no S-mode or atomic support is implied.

### 22. CSR access needed architectural address, privilege, and write-intent checks

- **Observed:** unsupported CSR numbers silently read as zero, writes to read-only CSRs were not trapped, and CSRRS/CSRRC with a zero source still asserted the internal CSR write port (which could suppress automatic counter increment). MSTATUS/MIE also accepted unimplemented/reserved bits without WARL masking.
- **Fix:** added a whitelist for implemented CSR addresses, privilege checks from CSR address bits `[9:8]`, read-only write-attempt checks from `[11:10]`, and M-mode-only MRET legality. CSRRS/CSRRC(I) now write only when the source/zimm is nonzero; CSRRS zero remains a read. MSTATUS/MIE writes mask to implemented architectural fields; MIP currently supports only software-pending bit 3. Updated the CSR alias test to use an implemented distinct address and added directed unknown-CSR and read-only-cycle write trap coverage.
- **Verification:** `make csr-legality-test` and `make csr-legality-test-icarus` pass (54 cycles), checking cause 2, offending CSR instruction in `mtval`, and EPC progression. Updated `make fast-test` passes its CSR, ECALL/MRET, illegal-instruction, CSR-legality, and C-output tests. `make riscv-tests` passes **50/50** after these decoder/CSR changes.
- **Scope:** CSR/system legality is improved but not complete; this does not implement S-mode CSRs, delegation, all privileged WARL behavior, interrupt arbitration, or the remaining synchronous access/alignment exceptions.

### 23. Load/store misalignment traps had to be configurable to preserve supported unaligned accesses

- **Observed:** adding load/store alignment exceptions unconditionally caused the upstream `rv32ui/ma_data` workload to fail. That suite intentionally exercises unaligned accesses, and this core's byte-addressable RAM already supports them transparently.
- **Fix:** added `TRAP_MISALIGNED`. The core can raise load-misaligned cause 4 or store-misaligned cause 6 with the effective address in `mtval`, after precise pipeline drain; slot-1 memory ops with unresolved address dependencies replay, and a slot-0 load-use address check waits for the correct forwarded base before classifying the access. `rv32i_top` defaults to transparent unaligned support for compatibility; tests or a Linux-oriented configuration can enable trap behavior explicitly.
- **Verification:** `make misaligned-test` and its Icarus cross-check pass (55 cycles), checking causes 4/6, `mtval=1`, aligned/ordered EPCs, no destination/store effect from the faulting operation, older slot commit, younger effect suppression, and MRET resume. Final `make fast-test` passes, with C smoke outputs unchanged at 21/238/424 cycles. `make riscv-tests` again passes **50/50**, including `ma_data`.
- **Scope:** this implements configurable load/store misalignment traps only. Instruction-address misalignment, access faults, interrupt entry/priority, and complete M-mode behavior remain outstanding.

### 24. Machine software interrupts had pending/enable state but no precise trap entry

- **Observed:** MIP/MSIP, MIE/MSIE, and `mstatus.MIE` state could be accessed, but an enabled pending MSIP did not interrupt execution.
- **Fix:** exposed machine interrupt state to the core, added machine interrupt eligibility (global MIE in M-mode; enabled in lower privilege), and feed an interrupt candidate through the existing precise drain/squash/trap path. Cause encoding follows machine priority order (external, software, timer); only the software pending bit is currently writable and wired, so only MSIP is functionally testable. Interrupt entry records the interrupted ID PC, sets interrupt cause 3, zeroes `mtval`, and uses existing MIE/MPIE/MPP save/restore. The handler clears MSIP through `mip` and returns with MRET.
- **Verification:** `make msip-interrupt-test` and `make msip-interrupt-test-icarus` pass (34 cycles), checking global interrupt masking while pending, cause/EPC/`mtval`, MSTATUS entry state, younger slot suppression before handler, pending-bit clear, and resumed retirement after MRET. Latest full `make fast-test` passes all directed tests and C outputs; `make riscv-tests` passes **50/50**.
- **Scope:** timer/external interrupt inputs, priority collisions, delegation and interrupt nesting are not implemented/tested; this is an initial M-mode software interrupt slice only.

### 25. Misaligned control-transfer targets were silently truncated by word-addressed fetch

- **Observed:** RV32I has no compressed extension, so a taken branch/JAL/JALR target not divisible by four must raise instruction-address-misaligned cause 0. The dual fetch path indexes words and previously ignored target bit 1.
- **Fix:** added selectable `TRAP_INST_MISALIGNED` (enabled by default in `rv32i_top`). Slot-0 taken branches/JAL/JALR validate their resolved target in ID, trap with `mepc` at the control instruction and `mtval` equal to the bad target, and suppress the redirect. Potentially misaligned slot-1 direct controls, plus slot-1 JALR, replay to slot 0 for precise resolution without replacing the dual-issue core.
- **Verification:** `make inst-misaligned-test` and its Icarus cross-check pass (30 cycles), proving cause 0, target `mtval`, older slot-0 commit, younger slot suppression, and MRET resume. Latest `make fast-test` passes all directed checks and C outputs (hello 21, Fibonacci 238, binary search 425 cycles); `make riscv-tests` passes **50/50**.
- **Scope:** this covers instruction-target alignment only, not instruction fetch access faults or memory access faults.

### 26. S-mode delegation and return paths were absent, blocking supervisor handoff

- **Observed:** the core could only trap into M-mode and had no supervisor CSR bank, `SRET`, or delegation controls. This prevented the first M-to-S/U-to-S trap path and S-to-M SBI-style ECALL path.
- **Fix:** added SSTATUS/SIE/STVEC/SSCRATCH/SEPC/SCAUSE/STVAL/SIP/SATP CSRs, `MEDELEG`/`MIDELEG`, U/S/M MPP restoration, delegated exception/interrupt vector selection (including vectored `stvec`/`mtvec`), `SRET`, and privileged `SFENCE.VMA` decode/serialization (translation flush remains a no-op until a TLB exists). MISA now reports S. Interrupt arbitration orders MEI, MSI, MTI, SEI, SSI, STI; platform timer/external pending sources remain unwired.
- **Verification:** added `make supervisor-test` and Icarus cross-check. At 61 cycles it passes MRET M-to-U, delegated U-mode ECALL to S, SRET to S, S-mode SBI ECALL to M, MRET back to S, and the expected privilege/cause/CSR checks. Full `make fast-test` passes, and `make riscv-tests` passes 50/50. Corrected Verilator width warnings in trap-vector offsets and the RAS depth comparison; final Verilator and Icarus supervisor tests both pass without width warnings.
- **Scope:** this is only privilege/trap plumbing. `satp` is stored/read but does not translate addresses. PMP, timer/external interrupt inputs, Sv32/TLB, access faults, atomic instructions, and the boot platform are still missing; Linux does not boot yet.

### 27. Linux bring-up required RV32A atomics, including precise LR/SC ordering

- **Observed:** the core reported M/S but no A extension and treated opcode `0101111` as illegal. This blocked Linux-style locks and the official RV32UA suite.
- **Fix:** added RV32A decode for LR.W, SC.W, and all nine AMO.W operations. Atomics are serialized behind older pipeline work; slot-1 atomics replay through slot 0; the single-hart reservation monitor returns SC success/failure, conservatively invalidates on stores, and the AMO path returns the old word while committing the selected new value. Added SC-status bypass for a following ID-stage branch, and protected an atomic held during serial drain from being lost to the generic inter-slot load-use flush. `FENCE` remains a no-op for this in-order, strongly ordered RAM model. MISA now reports A.
- **Directed verification:** `make atomic-test` and `make atomic-test-icarus` pass at 65 cycles. Checks LR data, successful then failed SC, AMOADD/SWAP/XOR/OR/AND/MIN/MAX/MINU/MAXU values, final memory, and MISA.A.
- **Architectural verification:** expanded `scripts/run_riscv_suite.py` and Makefile targets to include upstream RV32UA. `make riscv-tests` now passes **60/60**: RV32UI 42/42, RV32UM 8/8, RV32UA 10/10, including the 13,463-cycle `lrsc` test. `make fast-test` also passes the integrated Verilator A test plus existing tests and C outputs.
- **Scope:** this is initial single-hart functionality, not a multicore/coherent atomic bus. AMO accesses are word-only; platform faults and Sv32 are not present. Linux still does not boot.

### 28. Linux and ISA suites now use parameterized unified physical RAM

- **RTL:** added opt-in `UNIFIED_MEMORY=1` through `rv32i_top` and `mem_top`. In this mode, `data_mem.mem[]` is the one backing store for both data ports and both instruction-fetch lanes; initialized sparse data/DTB/initrd and code images are merged into it, and runtime code stores are immediately visible to instruction fetch. `DATA_WORD_COUNT` sets the physical RAM size. Split-memory compatibility remains the default for older directed tests.
- **Image/tooling:** added `scripts/elf2unifiedhex.py` to merge allocated ELF sections into a sparse `$readmemh` image with physical base and size checks. The compliance runner and `tb_riscv_test.v` now use unified mode; their RAM was enlarged to include the official suite's code and `tohost` sections.
- **Verification:** `make riscv-tests` passes **60/60** in unified mode across RV32UI/UM/UA, and `make fast-test` passes the directed Verilator checks and C smoke programs. The Linux testbench also runs with `UNIFIED_MEMORY=1` and a 32 MiB array. Icarus cross-checks the unified-mode `rv32ui/ld_st` case (936 cycles) via `tb_riscv_test.v`.

### 29. Linux kernfs linkage advanced past the self-link, then exposed a stack-canary failure

- **Observed:** the timer-enabled Linux trace previously ended with a self-referential kernfs pointer. In the focused trace, an asynchronous interrupt could coincide with a slot-0 branch/jump in ID. The kernfs store missing from the earlier snapshot subsequently committed to the expected parent (`0x804383d0`) after interrupt entry was deferred across slot-0 control-transfer instructions. The root/sibling links then updated, so the old self-link is no longer the immediate observed failure.
- **RTL changes:** async IRQ eligibility now waits through slot-0 branch/JAL/JALR resolution; pending interrupts are serviced at the next clean ID boundary. Slot-0 EX branch redirect/taken-flush remain disabled because branches are recovered in ID. Trap entry no longer flushes older ID/EX work from advancing into EX/MEM; it bubbles the current IF/ID instruction while preserving the older operation. The testbench's one-off IRQ/CLINT/kernfs/pipeline monitors were removed after extracting the relevant evidence.
- **New failure:** the clean UART log reaches Linux 6.12 early init, maps the CLINT timer/clocksource, initializes devtmpfs, then panics at about 0.125 seconds: `stack-protector: Kernel stack is corrupted in: 0x8018f7f4` (`add_device_randomness` epilogue). The latest timer-enabled 3M-cycle run reproduces it with `mepc=0x8018f7a4`; a 5M run also reproduced the same failure. Linux does not reach userspace or mount a root filesystem. The more recent trap-drain RTL change did not remove this panic.
- **Verification:** `make fast-test` passes after the latest trap-drain edit, including the misaligned-store precision check and C smoke outputs. `make mtrap-test-icarus` (51 cycles) and `make misaligned-test-icarus` (55 cycles) cross-check the trap/drain behavior. Fixed the RV32A suite-runner omission (suite selection and `rv32ia` march); `make riscv-tests` now exercises RV32UI+UM+UA and passes **60/60** after the latest core changes. `make linux-boot-test LINUX_MAX_CYCLES=3000000` correctly returns nonzero on the panic/no-userspace marker.
- **Diagnostic comparison:** a 3M-cycle run with `LINUX_TIMER_IRQ=0` avoids the stack-protector panic (stops at PC `0x800052ac`, no usable Linux/userspace boot), while the default timer-enabled run reproduces it. This implicates timer/trap-dependent execution but does not identify the corrupting RTL operation. File-based tracing showed the local canary is stored correctly at `sp+12` (`0x80419e8c`) and often compares correctly; in the failing invocation that word is zero while `tp+584` still contains `0x31f20d54`. The trace also records valid class-registration stack stores to the same physical word (`class_register` around `0x8019c7e0`, `class_interface_register` around `0x8019ce7c`) at other points. Their relationship to the failing dynamic stack frame is unproven; correlate call/stack lifetimes and exact timer-handler commits before attributing the overwrite.
- **Additional RTL guard:** gated data-memory read/write/AMO outputs by their EX/MEM valid bits and register-file writes by MEM/WB valid bits, so invalid pipeline bubbles cannot cause architectural side effects. This is a correctness hardening, not a confirmed Linux fix: the clean 3M timer-enabled run still panics at the same canary check.
- **Latest regressions:** `make fast-test` passes after validity gating, and `make riscv-tests` passes **60/60** (UI+UM+UA). The Icarus M-trap (51 cycles), misalignment (55 cycles), and atomic tests also pass after the gates. The Linux testbench's temporary file-based trace was removed; `LINUX_TIMER_IRQ` remains a testbench/Makefile parameter for reproducible timer-on/off diagnostics, defaulting to enabled.
- **Acceptance guard at this historical point:** the Linux target required no `Kernel panic`/`Kernel BUG`/`Oops` plus a `[LINUX_BOOT_SUCCESS]` marker. At the time of this entry, the initramfs did not yet emit that marker and Linux had not reached userspace; this was resolved by entry 30.

### 30. RV32 no-MMU Linux boots to a userspace init marker on the dual-issue RTL

- **Timer/platform correction:** the CLINT model increments `mtime` once per 10 ns testbench clock edge (100 MHz), while the DT had advertised 10 MHz. Changed `timebase-frequency` to 100 MHz so Linux's compare programming matches modeled time. With the corrected clock, the earlier `do_one_initcall returned with disabled interrupts`/fatal exception no longer reproduces, and Linux proceeds through initramfs unpack and device initialization.
- **Executable initramfs:** the no-MMU Linux config has `CONFIG_BINFMT_FLAT=y`, so the previous ordinary RV32 ELF `/init` was rejected with `ENOEXEC`. Added a minimal, relocation-free RV32 bFLT v4 init image (`platform/linux/init.S`, `platform/linux/flat_init.ld`, `scripts/pack_bflt.py`). It checks arithmetic, writes `[LINUX_BOOT_SUCCESS]` directly to UART0 from userspace, and stays alive as PID 1. Direct UART avoids requiring a libc/syscall runtime for this first milestone.
- **Unified physical RAM:** Linux loads the flat init into RAM at runtime, so the testbench now sets `UNIFIED_MEMORY=1`. Both fetch lanes read the same `data_mem.mem[]` array written by the kernel loader; sparse code, data, DTB, and initrd images share the 32 MiB physical RAM. This avoids split-array code-store mirroring and models the intended unified byte-addressed RAM.
- **Demonstrated boot:** `make linux-boot-test` completed successfully under Verilator at 20,000,000 cycles. The log contains Linux 6.12, the Arena platform model, CLINT at 100 MHz, `Run /init as init process`, and `[LINUX_BOOT_SUCCESS] RV32 userspace init reached`; the target's guard also confirmed no `Kernel panic`, `Kernel BUG`, or `Oops`. Final simulation state is in `build/linux-boot/linux-boot.log` and the unified-RAM command output in `build/linux-boot/linux-boot-unified-ram.out`.
- **Regression checks after the Linux changes:** `make riscv-tests` passes 60/60 (RV32UI 42, RV32UM 8, RV32UA 10) in unified mode; `make fast-test` passes directed Verilator checks and C smoke programs (hello 21 cycles, Fibonacci 238, binary search 425); Icarus passes unified-mode `rv32ui/ld_st` (936 cycles) and `make atomic-test-icarus`.
- **Scope/remaining platform work:** this is the requested first M-mode, no-MMU Linux boot milestone, not the MMU-enabled image/Sv32/SBI path. The userspace init is intentionally tiny and there is no shell, storage driver, or general userspace runtime. Broader address/access-fault behavior and full Sv32/TLB/SBI support remain follow-up work. CoreMark functional validation is not a performance score. No FPGA fitting, area, or timing work has been performed.

## Current known blockers

The requested first Linux boot milestone is demonstrated on the dual-issue RTL, and `UNIFIED_MEMORY=1` now provides one parameterized physical RAM array for fetch/data in the Linux and RISC-V compliance testbenches. Remaining scope is beyond that milestone: the userspace environment is only a minimal PID 1 smoke test, and the previously built MMU-enabled image still needs Sv32 translation/page faults, SBI/OpenSBI, and broader platform support. The 100 MHz CLINT/UART is a simulation platform, not a complete board platform. No FPGA fitting, area, or timing work has been performed.
