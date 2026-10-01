// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_program.h for the primary calling header

#ifndef VERILATED_VTB_PROGRAM___024ROOT_H_
#define VERILATED_VTB_PROGRAM___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_program__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_program___024root final {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ tb_program__DOT__clk;
        CData/*0:0*/ tb_program__DOT__rst;
        CData/*0:0*/ tb_program__DOT__done;
        CData/*0:0*/ tb_program__DOT__timed_out;
        CData/*0:0*/ tb_program__DOT__progress_enable;
        CData/*6:0*/ tb_program__DOT__decode_mnemonic__Vstatic__opcode;
        CData/*2:0*/ tb_program__DOT__decode_mnemonic__Vstatic__funct3;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__flush_id;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__id_branch_redirect0;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__pipe_halt;
        CData/*7:0*/ tb_program__DOT__uut__DOT__core__DOT__hybp_ghr;
        CData/*3:0*/ tb_program__DOT__uut__DOT__core__DOT__ras_top_ptr;
        CData/*4:0*/ tb_program__DOT__uut__DOT__core__DOT__ras_count;
        CData/*7:0*/ tb_program__DOT__uut__DOT__core__DOT__if_pred_pc_idx;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__if_is_ret0;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__if_btb_hit0;
        CData/*7:0*/ tb_program__DOT__uut__DOT__core__DOT__if_global_idx0;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__if_local_pred_taken0;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__if_global_pred_taken0;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__if_pred_taken0;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__if_id_valid0;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__if_id_valid1;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__if_id_pred_taken0;
        CData/*7:0*/ tb_program__DOT__uut__DOT__core__DOT__if_id_local_idx0;
        CData/*7:0*/ tb_program__DOT__uut__DOT__core__DOT__if_id_global_idx0;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__if_id_local_pred_taken0;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__if_id_global_pred_taken0;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__id_mem_read0;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__id_mem_write0;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__id_reg_write0;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__id_mem_to_reg0;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__id_alu_src0;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__id_auipc0;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__id_is_lui0;
        CData/*1:0*/ tb_program__DOT__uut__DOT__core__DOT__id_alu_op0;
        CData/*2:0*/ tb_program__DOT__uut__DOT__core__DOT__id_imm_type0;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__id_branch0;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__id_jal0;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__id_jalr0;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__id_ecall0;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__id_halt0;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__id_csr_read0;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__id_csr_write0;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__id_mem_read1;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__id_mem_write1;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__id_reg_write1;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__id_mem_to_reg1;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__id_alu_src1;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__id_auipc1;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__id_is_lui1;
        CData/*1:0*/ tb_program__DOT__uut__DOT__core__DOT__id_alu_op1;
        CData/*2:0*/ tb_program__DOT__uut__DOT__core__DOT__id_imm_type1;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__id_branch1;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__id_jal1;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__id_jalr1;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__id_ecall1;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__id_halt1;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__id_csr_read1;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__id_csr_write1;
        CData/*4:0*/ tb_program__DOT__uut__DOT__core__DOT__id_ex_rs1_0;
        CData/*4:0*/ tb_program__DOT__uut__DOT__core__DOT__id_ex_rs2_0;
        CData/*4:0*/ tb_program__DOT__uut__DOT__core__DOT__id_ex_rd0;
        CData/*2:0*/ tb_program__DOT__uut__DOT__core__DOT__id_ex_funct3_0;
        CData/*6:0*/ tb_program__DOT__uut__DOT__core__DOT__id_ex_funct7_0;
    };
    struct {
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__id_ex_mem_read0;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__id_ex_mem_write0;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__id_ex_reg_write0;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__id_ex_mem_to_reg0;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__id_ex_alu_src0;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__id_ex_auipc0;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__id_ex_is_lui0;
        CData/*1:0*/ tb_program__DOT__uut__DOT__core__DOT__id_ex_alu_op0;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__id_ex_branch0;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__id_ex_jal0;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__id_ex_jalr0;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__id_ex_ecall0;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__id_ex_halt0;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__id_ex_csr_read0;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__id_ex_csr_write0;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__id_ex_is_rtype0;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__id_ex_valid0;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__id_ex_pred_taken0;
        CData/*7:0*/ tb_program__DOT__uut__DOT__core__DOT__id_ex_local_idx0;
        CData/*7:0*/ tb_program__DOT__uut__DOT__core__DOT__id_ex_global_idx0;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__id_ex_local_pred_taken0;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__id_ex_global_pred_taken0;
        CData/*4:0*/ tb_program__DOT__uut__DOT__core__DOT__id_ex_rs1_1;
        CData/*4:0*/ tb_program__DOT__uut__DOT__core__DOT__id_ex_rs2_1;
        CData/*4:0*/ tb_program__DOT__uut__DOT__core__DOT__id_ex_rd1;
        CData/*2:0*/ tb_program__DOT__uut__DOT__core__DOT__id_ex_funct3_1;
        CData/*6:0*/ tb_program__DOT__uut__DOT__core__DOT__id_ex_funct7_1;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__id_ex_mem_read1;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__id_ex_mem_write1;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__id_ex_reg_write1;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__id_ex_mem_to_reg1;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__id_ex_alu_src1;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__id_ex_auipc1;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__id_ex_is_lui1;
        CData/*1:0*/ tb_program__DOT__uut__DOT__core__DOT__id_ex_alu_op1;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__id_ex_branch1;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__id_ex_jal1;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__id_ex_jalr1;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__id_ex_ecall1;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__id_ex_halt1;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__id_ex_csr_read1;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__id_ex_csr_write1;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__id_ex_is_rtype1;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__id_ex_valid1;
        CData/*4:0*/ tb_program__DOT__uut__DOT__core__DOT__ex_alu_ctrl0;
        CData/*4:0*/ tb_program__DOT__uut__DOT__core__DOT__ex_alu_ctrl1;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__id_is_ret0;
        CData/*4:0*/ tb_program__DOT__uut__DOT__core__DOT__ex_mem_rd0;
        CData/*2:0*/ tb_program__DOT__uut__DOT__core__DOT__ex_mem_funct3_0;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__ex_mem_mem_read0;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__ex_mem_mem_write0;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__ex_mem_reg_write0;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__ex_mem_mem_to_reg0;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__ex_mem_ecall0;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__ex_mem_halt0;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__ex_mem_valid0;
        CData/*4:0*/ tb_program__DOT__uut__DOT__core__DOT__ex_mem_rd1;
        CData/*2:0*/ tb_program__DOT__uut__DOT__core__DOT__ex_mem_funct3_1;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__ex_mem_mem_read1;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__ex_mem_mem_write1;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__ex_mem_reg_write1;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__ex_mem_mem_to_reg1;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__ex_mem_ecall1;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__ex_mem_halt1;
    };
    struct {
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__ex_mem_valid1;
        CData/*4:0*/ tb_program__DOT__uut__DOT__core__DOT__mem_wb_rd0;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__mem_wb_reg_write0;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__mem_wb_mem_to_reg0;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__mem_wb_ecall0;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__mem_wb_halt0;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__mem_wb_valid0;
        CData/*4:0*/ tb_program__DOT__uut__DOT__core__DOT__mem_wb_rd1;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__mem_wb_reg_write1;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__mem_wb_mem_to_reg1;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__mem_wb_ecall1;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__mem_wb_halt1;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__mem_wb_valid1;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_4;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_5;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_7;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_8;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_9;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_10;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_13;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_14;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__bc0__DOT__branch_taken;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__hz__DOT__s1_ex_branch_taken;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__hz__DOT__s0_id_branch_taken;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__hz__DOT__s0_s1_mem_dep;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__hz__DOT__stall_if;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__hz__DOT__flush_ex;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__hz__DOT__squash_s1;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__hz__DOT__load_use_stall;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__hz__DOT__do_flush;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__hz__DOT__inter_slot_load_raw;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__hz__DOT__inter_slot_ctrl;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__hz__DOT____VdfgRegularize_h6b6f5558_0_0;
        CData/*0:0*/ tb_program__DOT__uut__DOT__core__DOT__hz__DOT____VdfgRegularize_h6b6f5558_0_1;
        CData/*1:0*/ tb_program__DOT__uut__DOT__core__DOT__fwd_unit__DOT__fwd_a0;
        CData/*1:0*/ tb_program__DOT__uut__DOT__core__DOT__fwd_unit__DOT__fwd_b0;
        CData/*2:0*/ tb_program__DOT__uut__DOT__core__DOT__fwd_unit__DOT__fwd_a1;
        CData/*2:0*/ tb_program__DOT__uut__DOT__core__DOT__fwd_unit__DOT__fwd_b1;
        CData/*0:0*/ __VdfgRegularize_he50b618e_0_2;
        CData/*0:0*/ __VdfgRegularize_he50b618e_0_3;
        CData/*0:0*/ __VdfgRegularize_he50b618e_0_4;
        CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_10;
        CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_11;
        CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_12;
        CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_13;
        CData/*0:0*/ __Vdly__tb_program__DOT__uut__DOT__core__DOT__ex_mem_halt0;
        CData/*0:0*/ __Vdly__tb_program__DOT__uut__DOT__core__DOT__ex_mem_halt1;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tb_program__DOT__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tb_program__DOT__rst__0;
        SData/*11:0*/ tb_program__DOT__uut__DOT__core__DOT__id_ex_csr0;
        SData/*11:0*/ tb_program__DOT__uut__DOT__core__DOT__id_ex_csr1;
        IData/*31:0*/ tb_program__DOT__cycle_count;
        IData/*31:0*/ tb_program__DOT__instret_count;
        IData/*31:0*/ tb_program__DOT__f;
        IData/*31:0*/ tb_program__DOT__i;
        IData/*31:0*/ tb_program__DOT__stable_pc_count;
        IData/*31:0*/ tb_program__DOT__last_pc;
        IData/*31:0*/ tb_program__DOT__max_cycles;
        IData/*31:0*/ tb_program__DOT__progress_interval;
        IData/*31:0*/ tb_program__DOT__uut__DOT__mem_rdata0;
        IData/*31:0*/ tb_program__DOT__uut__DOT__mem_rdata1;
        IData/*31:0*/ tb_program__DOT__uut__DOT__core__DOT__instr0;
        IData/*31:0*/ tb_program__DOT__uut__DOT__core__DOT__id_branch_target0;
    };
    struct {
        IData/*31:0*/ tb_program__DOT__uut__DOT__core__DOT__pc_current;
        IData/*31:0*/ tb_program__DOT__uut__DOT__core__DOT__hybp_i;
        IData/*31:0*/ tb_program__DOT__uut__DOT__core__DOT__ras_i;
        IData/*31:0*/ tb_program__DOT__uut__DOT__core__DOT__if_pred_target0;
        IData/*31:0*/ tb_program__DOT__uut__DOT__core__DOT__if_id_pc0;
        IData/*31:0*/ tb_program__DOT__uut__DOT__core__DOT__if_id_pc1;
        IData/*31:0*/ tb_program__DOT__uut__DOT__core__DOT__if_id_instr0;
        IData/*31:0*/ tb_program__DOT__uut__DOT__core__DOT__if_id_instr1;
        IData/*31:0*/ tb_program__DOT__uut__DOT__core__DOT__if_id_pred_target0;
        IData/*31:0*/ tb_program__DOT__uut__DOT__core__DOT__id_rd1_0;
        IData/*31:0*/ tb_program__DOT__uut__DOT__core__DOT__id_rd2_0;
        IData/*31:0*/ tb_program__DOT__uut__DOT__core__DOT__id_ex_pc0;
        IData/*31:0*/ tb_program__DOT__uut__DOT__core__DOT__id_ex_rd1_0;
        IData/*31:0*/ tb_program__DOT__uut__DOT__core__DOT__id_ex_rd2_0;
        IData/*31:0*/ tb_program__DOT__uut__DOT__core__DOT__id_ex_imm0;
        IData/*31:0*/ tb_program__DOT__uut__DOT__core__DOT__id_ex_pc1;
        IData/*31:0*/ tb_program__DOT__uut__DOT__core__DOT__id_ex_rd1_1;
        IData/*31:0*/ tb_program__DOT__uut__DOT__core__DOT__id_ex_rd2_1;
        IData/*31:0*/ tb_program__DOT__uut__DOT__core__DOT__id_ex_imm1;
        IData/*31:0*/ tb_program__DOT__uut__DOT__core__DOT__ex_mem_fwd_val0;
        IData/*31:0*/ tb_program__DOT__uut__DOT__core__DOT__ex_mem_fwd_val1;
        IData/*31:0*/ tb_program__DOT__uut__DOT__core__DOT__ex_wb_val0;
        IData/*31:0*/ tb_program__DOT__uut__DOT__core__DOT__ex_wb_val1;
        IData/*31:0*/ tb_program__DOT__uut__DOT__core__DOT__id_jal_target0;
        IData/*31:0*/ tb_program__DOT__uut__DOT__core__DOT__id_jalr_target0;
        IData/*31:0*/ tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu0;
        IData/*31:0*/ tb_program__DOT__uut__DOT__core__DOT__ex_mem_rs2_0;
        IData/*31:0*/ tb_program__DOT__uut__DOT__core__DOT__ex_mem_wb0;
        IData/*31:0*/ tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu1;
        IData/*31:0*/ tb_program__DOT__uut__DOT__core__DOT__ex_mem_rs2_1;
        IData/*31:0*/ tb_program__DOT__uut__DOT__core__DOT__ex_mem_wb1;
        IData/*31:0*/ tb_program__DOT__uut__DOT__core__DOT__mem_wb_wb0;
        IData/*31:0*/ tb_program__DOT__uut__DOT__core__DOT__mem_wb_mem0;
        IData/*31:0*/ tb_program__DOT__uut__DOT__core__DOT__mem_wb_wb1;
        IData/*31:0*/ tb_program__DOT__uut__DOT__core__DOT__mem_wb_mem1;
        IData/*31:0*/ tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_15;
        IData/*31:0*/ tb_program__DOT__uut__DOT__core__DOT__pc_counter__DOT__pc_next;
        IData/*31:0*/ tb_program__DOT__uut__DOT__core__DOT__ig0__DOT__imm;
        IData/*31:0*/ tb_program__DOT__uut__DOT__core__DOT__ig1__DOT__imm;
        IData/*31:0*/ tb_program__DOT__uut__DOT__core__DOT__regs__DOT__wd0;
        IData/*31:0*/ tb_program__DOT__uut__DOT__core__DOT__regs__DOT__wd1;
        IData/*31:0*/ tb_program__DOT__uut__DOT__core__DOT__regs__DOT__i;
        IData/*31:0*/ tb_program__DOT__uut__DOT__core__DOT__alu0__DOT__a;
        IData/*31:0*/ tb_program__DOT__uut__DOT__core__DOT__alu0__DOT__b;
        IData/*31:0*/ tb_program__DOT__uut__DOT__core__DOT__alu0__DOT__result;
        IData/*31:0*/ tb_program__DOT__uut__DOT__core__DOT__bc0__DOT__rs1;
        IData/*31:0*/ tb_program__DOT__uut__DOT__core__DOT__bc0__DOT__rs2;
        IData/*31:0*/ tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__i;
        IData/*31:0*/ tb_program__DOT__uut__DOT__core__DOT__alu1__DOT__a;
        IData/*31:0*/ tb_program__DOT__uut__DOT__core__DOT__alu1__DOT__b;
        IData/*31:0*/ tb_program__DOT__uut__DOT__core__DOT__alu1__DOT__result;
        IData/*31:0*/ tb_program__DOT__uut__DOT__core__DOT__bc1__DOT__rs1;
        IData/*31:0*/ tb_program__DOT__uut__DOT__core__DOT__bc1__DOT__rs2;
        IData/*31:0*/ tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__i;
        IData/*31:0*/ tb_program__DOT__uut__DOT__core__DOT__id_br_cmp0__DOT__rs1;
        IData/*31:0*/ tb_program__DOT__uut__DOT__core__DOT__id_br_cmp0__DOT__rs2;
        IData/*31:0*/ __VactIterCount;
        VlUnpacked<IData/*31:0*/, 4096> tb_program__DOT__uut__DOT__mem__DOT__imem__DOT__mem;
        VlUnpacked<IData/*31:0*/, 2048> tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem;
        VlUnpacked<IData/*31:0*/, 4096> tb_program__DOT__uut__DOT__imem_b__DOT__mem;
        VlUnpacked<CData/*1:0*/, 256> tb_program__DOT__uut__DOT__core__DOT__hybp_local_pht;
        VlUnpacked<CData/*1:0*/, 256> tb_program__DOT__uut__DOT__core__DOT__hybp_global_pht;
        VlUnpacked<CData/*1:0*/, 256> tb_program__DOT__uut__DOT__core__DOT__hybp_choice_pht;
        VlUnpacked<CData/*0:0*/, 256> tb_program__DOT__uut__DOT__core__DOT__btb_valid;
    };
    struct {
        VlUnpacked<IData/*31:0*/, 256> tb_program__DOT__uut__DOT__core__DOT__btb_tag;
        VlUnpacked<IData/*31:0*/, 256> tb_program__DOT__uut__DOT__core__DOT__btb_target;
        VlUnpacked<IData/*31:0*/, 16> tb_program__DOT__uut__DOT__core__DOT__ras_stack;
        VlUnpacked<IData/*31:0*/, 32> tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf;
        VlUnpacked<IData/*31:0*/, 16> tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr;
        VlUnpacked<IData/*31:0*/, 16> tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr;
        VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
        VlUnpacked<CData/*0:0*/, 6> __Vm_traceActivity;
    };
    VlNBACommitQueue<VlUnpacked<CData/*1:0*/, 256>, false, CData/*1:0*/, 1> __VdlyCommitQueuetb_program__DOT__uut__DOT__core__DOT__hybp_local_pht;
    VlNBACommitQueue<VlUnpacked<CData/*1:0*/, 256>, false, CData/*1:0*/, 1> __VdlyCommitQueuetb_program__DOT__uut__DOT__core__DOT__hybp_global_pht;
    VlNBACommitQueue<VlUnpacked<CData/*1:0*/, 256>, false, CData/*1:0*/, 1> __VdlyCommitQueuetb_program__DOT__uut__DOT__core__DOT__hybp_choice_pht;
    VlNBACommitQueue<VlUnpacked<CData/*0:0*/, 256>, false, CData/*0:0*/, 1> __VdlyCommitQueuetb_program__DOT__uut__DOT__core__DOT__btb_valid;
    VlNBACommitQueue<VlUnpacked<IData/*31:0*/, 256>, false, IData/*31:0*/, 1> __VdlyCommitQueuetb_program__DOT__uut__DOT__core__DOT__btb_tag;
    VlNBACommitQueue<VlUnpacked<IData/*31:0*/, 256>, false, IData/*31:0*/, 1> __VdlyCommitQueuetb_program__DOT__uut__DOT__core__DOT__btb_target;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h52375936__0;

    // INTERNAL VARIABLES
    Vtb_program__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vtb_program___024root(Vtb_program__Syms* symsp, const char* namep);
    ~Vtb_program___024root();
    VL_UNCOPYABLE(Vtb_program___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
