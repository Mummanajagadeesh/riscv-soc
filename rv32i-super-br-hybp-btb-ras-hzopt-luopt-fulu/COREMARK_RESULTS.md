# rv32i-super-br-hybp-btb-ras-hzopt-luopt-fulu CoreMark Results

## What changed

This variant builds on `rv32i-super-br-hybp-btb-ras-hzopt` and adds **luopt + fulu-style behavior** inspired by the pipe final variant.

Implemented in this superscalar core:

- hzopt retained: load-use stalls only for ID-stage consumers in slot 0 (`branch` / `jalr`).
- luopt-style inter-slot memory dependency filtering:
  - replaced conservative `store->load always squash` with width+offset alias check,
  - dependency only when slot0 store and slot1 load are same width and low address bits alias.
- inter-slot control replay policy tightened using `branch_taken || branch_pred_taken` for slot0 branch control handling.
- load-aware forwarding retained on EX/MEM forwarding buses.

## Regressions run

- `make gen-test-hex && make iverilog-inst-sim` -> **31/31 PASS**
- `make hex-from-elf ELF=hello.elf && make iverilog-prog-sim` -> pass (`tb_program_results_hello_br_hybp_btb_ras_hzopt_luopt_fulu.txt`)
- `make hex-from-elf ELF=fibonacci.elf && make iverilog-prog-sim` -> pass (`tb_program_results_fibonacci_br_hybp_btb_ras_hzopt_luopt_fulu.txt`)
- `make hex-from-elf ELF=binary_search.elf && make iverilog-prog-sim` -> pass (`tb_program_results_binary_search_br_hybp_btb_ras_hzopt_luopt_fulu.txt`)

## Commands

Run from `rv32i-super-br-hybp-btb-ras-hzopt-luopt-fulu/`.

### Smoke (`-O2`, `ITERATIONS=1`)

```bash
make iverilog-prog
python3 scripts/elf2hex.py coremark_i1_o2.elf hex/inst_mem.hex hex/data_mem.hex
vvp tb_program_sim.vvp +max_cycles=1200000 +progress_interval=200000
cp tb_program_results.txt tb_program_results_from_pipe_elf_i1_o2_luopt_fulu.txt
```

### Full matrix

```bash
make verilator-prog
for opt in o2 o3 ofast; do
  for iter in 1 10 100; do
    python3 scripts/elf2hex.py coremark_i${iter}_${opt}.elf hex/inst_mem.hex hex/data_mem.hex
    ./obj_dir/Vtb_program +max_cycles=500000000
    cp tb_program_results.txt tb_program_results_from_pipe_elf_i${iter}_${opt}_luopt_fulu.txt
  done
done
```

## Results

CRC signatures match expected validation values:

- `ITER=1`: `x12 = 0x0000e3c1`
- `ITER=10`: `x12 = 0x0000c64e`
- `ITER=100`: `x12 = 0x0000844d`

| Opt | Iter | Cycles | Retired Inst | CPI | IPC | CoreMark/MHz | Score @100MHz | CRC (`x12`) |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | --- |
| O2 | 1 | 235625 | 322978 | 0.729538854 | 1.370728912 | 4.244031830 | 424.403183 | `0x0000e3c1` |
| O2 | 10 | 2267464 | 3102275 | 0.730903611 | 1.368169462 | 4.410213348 | 441.021335 | `0x0000c64e` |
| O2 | 100 | 22589232 | 30899091 | 0.731064613 | 1.367868151 | 4.426887997 | 442.688800 | `0x0000844d` |
| O3 | 1 | 223472 | 307172 | 0.727514227 | 1.374543567 | 4.474833536 | 447.483354 | `0x0000e3c1` |
| O3 | 10 | 2156218 | 2965057 | 0.727209629 | 1.375119306 | 4.637749986 | 463.774999 | `0x0000c64e` |
| O3 | 100 | 21484387 | 29546308 | 0.727142863 | 1.375245568 | 4.654542855 | 465.454286 | `0x0000844d` |
| Ofast | 1 | 223530 | 307170 | 0.727707784 | 1.374177963 | 4.473672438 | 447.367244 | `0x0000e3c1` |
| Ofast | 10 | 2156476 | 2965055 | 0.727297133 | 1.374953860 | 4.637195128 | 463.719513 | `0x0000c64e` |
| Ofast | 100 | 21489076 | 29546306 | 0.727301613 | 1.374945391 | 4.653527215 | 465.352722 | `0x0000844d` |

## Relative to `rv32i-super-br-hybp-btb-ras-hzopt`

| Opt | Iter | hzopt cycles | luopt-fulu cycles | hzopt CoreMark/MHz | luopt-fulu CoreMark/MHz | Speedup (luopt-fulu vs hzopt) |
| --- | ---: | ---: | ---: | ---: | ---: | ---: |
| O2 | 1 | 272741 | 235625 | 3.666482120 | 4.244031830 | 1.157521x |
| O2 | 10 | 2629777 | 2267464 | 3.802603795 | 4.410213348 | 1.159788x |
| O2 | 100 | 26202245 | 22589232 | 3.816466871 | 4.426887997 | 1.159944x |
| O3 | 1 | 261165 | 223472 | 3.828996994 | 4.474833536 | 1.168670x |
| O3 | 10 | 2522656 | 2156218 | 3.964075958 | 4.637749986 | 1.169945x |
| O3 | 100 | 25142329 | 21484387 | 3.977356274 | 4.654542855 | 1.170260x |
| Ofast | 1 | 261378 | 223530 | 3.825876700 | 4.473672438 | 1.169320x |
| Ofast | 10 | 2524821 | 2156476 | 3.960676816 | 4.637195128 | 1.170809x |
| Ofast | 100 | 25160989 | 21489076 | 3.974406570 | 4.653527215 | 1.170873x |

Average speedup by opt (vs hzopt):

- O2: `~1.159084x` (~15.908%)
- O3: `~1.169625x` (~16.963%)
- Ofast: `~1.170334x` (~17.033%)

## CPI / IPC improvement (O2 smoke)

Compared to `rv32i-super-br-hybp-btb-ras-hzopt` O2 i1:

- CPI: `0.844456898 -> 0.729538854` (improvement `~13.609%`)
- IPC: `1.184193062 -> 1.370728912` (gain `~15.752%`)

These changes move the superscalar core materially toward the target direction (lower CPI / higher IPC).
