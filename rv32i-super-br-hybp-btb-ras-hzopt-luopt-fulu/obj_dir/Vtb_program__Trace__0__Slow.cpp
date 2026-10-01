// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vtb_program__Syms.h"


VL_ATTR_COLD void Vtb_program___024root__trace_init_sub__TOP__0(Vtb_program___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_program___024root__trace_init_sub__TOP__0\n"); );
    Vtb_program__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    tracep->pushPrefix("tb_program", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+409,0,"clk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+6,0,"rst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+192,0,"pc_debug",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+193,0,"instr_debug",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+419,0,"alu_result_debug",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+377,0,"mem_read_debug",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+194,0,"halted",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+410,0,"cycle_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+411,0,"instret_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+7,0,"f",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+8,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+9,0,"stable_pc_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+10,0,"last_pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+11,0,"done",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+12,0,"timed_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+420,0,"TRACE_EXEC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+420,0,"DUMP_VCD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1,0,"max_cycles",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+2,0,"progress_interval",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBit(c+3,0,"progress_enable",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+421,0,"decode_mnemonic__Vstatic__opcode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+422,0,"decode_mnemonic__Vstatic__funct3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->pushPrefix("uut", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declArray(c+423,0,"INST_HEX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->declArray(c+427,0,"DATA_HEX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->declBus(c+419,0,"BASE_ADDR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+409,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+6,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+192,0,"pc_debug",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+193,0,"instr_debug",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+419,0,"alu_result_debug",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+377,0,"mem_read_debug",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+194,0,"halted",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+192,0,"pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+193,0,"instr0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+412,0,"instr1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+195,0,"mem_read0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+196,0,"mem_write0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+197,0,"mem_addr0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+198,0,"mem_wdata0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+377,0,"mem_rdata0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+199,0,"mem_funct30",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+200,0,"mem_read1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+201,0,"mem_write1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+202,0,"mem_addr1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+203,0,"mem_wdata1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+378,0,"mem_rdata1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+204,0,"mem_funct31",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+47,0,"reg_write0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+48,0,"reg_write1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+49,0,"reg_wa0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+50,0,"reg_wa1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+51,0,"reg_wd0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+52,0,"reg_wd1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+177,0,"ecall",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+194,0,"halt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("core", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+419,0,"RESET_PC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+409,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+6,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+193,0,"instr0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+412,0,"instr1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+377,0,"mem_read_data0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+195,0,"mem_read0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+196,0,"mem_write0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+197,0,"mem_addr0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+198,0,"mem_wdata0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+199,0,"mem_funct30",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+378,0,"mem_read_data1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+200,0,"mem_read1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+201,0,"mem_write1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+202,0,"mem_addr1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+203,0,"mem_wdata1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+204,0,"mem_funct31",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+192,0,"pc_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+47,0,"reg_write0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+49,0,"reg_wa0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+51,0,"reg_wd0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+48,0,"reg_write1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+50,0,"reg_wa1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+52,0,"reg_wd1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+177,0,"ecall",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+194,0,"halt",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+379,0,"stall_if",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+379,0,"stall_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+380,0,"flush_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+381,0,"flush_ex",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+382,0,"squash_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+379,0,"hz_stall_if",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+379,0,"hz_stall_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+413,0,"hz_flush_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+381,0,"hz_flush_ex",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+383,0,"id_branch_redirect0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+384,0,"id_branch_target0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+205,0,"fwd_a0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+206,0,"fwd_b0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+207,0,"fwd_a1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+208,0,"fwd_b1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+209,0,"pipe_halt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+192,0,"pc_current",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+210,0,"pc_plus4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+211,0,"pc_plus8",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+414,0,"pc_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+431,0,"HYBP_IDX_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+432,0,"HYBP_ENTRIES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+431,0,"HYBP_GHR_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+431,0,"BTB_IDX_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+432,0,"BTB_ENTRIES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+433,0,"RAS_DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+434,0,"RAS_PTR_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+53,0,"hybp_ghr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->pushPrefix("ras_stack", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+54+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+70,0,"ras_top_ptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+71,0,"ras_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+72,0,"hybp_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+73,0,"ras_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+212,0,"if_pred_pc_idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+213,0,"if_is_branch0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+214,0,"if_is_jal0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+215,0,"if_is_jalr0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+216,0,"if_rd0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+217,0,"if_rs1_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+218,0,"if_branch_imm0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+219,0,"if_jal_imm0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+220,0,"if_jalr_imm0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+221,0,"if_is_ret0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+74,0,"ras_has_entry0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+75,0,"if_ras_target0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+222,0,"if_btb_idx0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+223,0,"if_btb_hit0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+212,0,"if_local_idx0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+224,0,"if_global_idx0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+225,0,"if_local_pred_taken0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+226,0,"if_global_pred_taken0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+178,0,"if_choose_global0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+179,0,"if_pred_branch_taken0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+214,0,"if_pred_jal_taken0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+180,0,"if_pred_jalr_taken0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+227,0,"if_pred_taken0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+228,0,"if_pred_target0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+76,0,"if_id_pc0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+77,0,"if_id_pc1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+229,0,"if_id_instr0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+230,0,"if_id_instr1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+231,0,"if_id_valid0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+232,0,"if_id_valid1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+78,0,"if_id_pred_taken0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+79,0,"if_id_pred_target0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+80,0,"if_id_local_idx0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+81,0,"if_id_global_idx0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+82,0,"if_id_local_pred_taken0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+83,0,"if_id_global_pred_taken0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+233,0,"id_opcode0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+234,0,"id_funct30",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+235,0,"id_funct70",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+236,0,"id_rd0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+237,0,"id_rs1_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+238,0,"id_rs2_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+239,0,"id_csr0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBit(c+240,0,"id_use_rs1_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+241,0,"id_use_rs2_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+242,0,"id_mem_read0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+243,0,"id_mem_write0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+244,0,"id_reg_write0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+245,0,"id_mem_to_reg0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+246,0,"id_alu_src0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+247,0,"id_auipc0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+248,0,"id_is_lui0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+249,0,"id_alu_op0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+250,0,"id_imm_type0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+251,0,"id_branch0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+252,0,"id_jal0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+253,0,"id_jalr0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+254,0,"id_ecall0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+255,0,"id_halt0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+256,0,"id_csr_read0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+257,0,"id_csr_write0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+258,0,"id_imm0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+259,0,"id_opcode1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+260,0,"id_funct31",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+261,0,"id_funct71",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+262,0,"id_rd1_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+263,0,"id_rs1_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+264,0,"id_rs2_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+265,0,"id_csr1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBit(c+266,0,"id_use_rs1_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+267,0,"id_use_rs2_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+268,0,"id_mem_read1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+269,0,"id_mem_write1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+270,0,"id_reg_write1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+271,0,"id_mem_to_reg1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+272,0,"id_alu_src1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+273,0,"id_auipc1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+274,0,"id_is_lui1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+275,0,"id_alu_op1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+276,0,"id_imm_type1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+277,0,"id_branch1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+278,0,"id_jal1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+279,0,"id_jalr1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+280,0,"id_ecall1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+281,0,"id_halt1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+282,0,"id_csr_read1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+283,0,"id_csr_write1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+284,0,"id_imm1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+285,0,"id_is_rtype0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+286,0,"id_is_rtype1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+181,0,"id_rd1_raw0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+182,0,"id_rd2_raw0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+183,0,"id_rd1_raw1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+184,0,"id_rd2_raw1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+287,0,"id_rd1_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+288,0,"id_rd2_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+185,0,"id_rd1_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+186,0,"id_rd2_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+243,0,"s0_is_store",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+268,0,"s1_is_load",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+289,0,"s0_store_word",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+290,0,"s0_store_half",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+291,0,"s0_store_byte",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+292,0,"s1_load_word",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+293,0,"s1_load_half",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+294,0,"s1_load_byte",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+295,0,"s0s1_addr_alias_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+296,0,"s0s1_addr_alias_h",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+435,0,"s0s1_addr_alias_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+297,0,"s0_s1_mem_dep",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+358,0,"eff_id_mem_read1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+359,0,"eff_id_mem_write1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+360,0,"eff_id_reg_write1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+361,0,"eff_id_mem_to_reg1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+362,0,"eff_id_alu_src1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+363,0,"eff_id_alu_op1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+364,0,"eff_id_auipc1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+365,0,"eff_id_is_lui1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+366,0,"eff_id_branch1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+367,0,"eff_id_jal1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+368,0,"eff_id_jalr1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+369,0,"eff_id_ecall1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+370,0,"eff_id_halt1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+371,0,"eff_id_csr_read1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+372,0,"eff_id_csr_write1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+373,0,"eff_id_is_rtype1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+374,0,"eff_id_rd1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+84,0,"id_ex_pc0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+85,0,"id_ex_rd1_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+86,0,"id_ex_rd2_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+87,0,"id_ex_imm0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+88,0,"id_ex_rs1_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+89,0,"id_ex_rs2_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+298,0,"id_ex_rd0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+299,0,"id_ex_funct3_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+90,0,"id_ex_funct7_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+91,0,"id_ex_csr0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBit(c+300,0,"id_ex_mem_read0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+301,0,"id_ex_mem_write0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+302,0,"id_ex_reg_write0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+303,0,"id_ex_mem_to_reg0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+92,0,"id_ex_alu_src0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+93,0,"id_ex_auipc0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+94,0,"id_ex_is_lui0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+95,0,"id_ex_alu_op0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+96,0,"id_ex_branch0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+97,0,"id_ex_jal0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+98,0,"id_ex_jalr0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+304,0,"id_ex_ecall0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+305,0,"id_ex_halt0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+99,0,"id_ex_csr_read0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+100,0,"id_ex_csr_write0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+101,0,"id_ex_is_rtype0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+306,0,"id_ex_valid0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+102,0,"id_ex_pred_taken0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+103,0,"id_ex_local_idx0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+104,0,"id_ex_global_idx0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+105,0,"id_ex_local_pred_taken0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+106,0,"id_ex_global_pred_taken0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+107,0,"id_ex_pc1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+108,0,"id_ex_rd1_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+109,0,"id_ex_rd2_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+110,0,"id_ex_imm1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+111,0,"id_ex_rs1_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+112,0,"id_ex_rs2_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+307,0,"id_ex_rd1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+308,0,"id_ex_funct3_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+113,0,"id_ex_funct7_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+114,0,"id_ex_csr1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBit(c+309,0,"id_ex_mem_read1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+310,0,"id_ex_mem_write1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+311,0,"id_ex_reg_write1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+312,0,"id_ex_mem_to_reg1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+115,0,"id_ex_alu_src1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+116,0,"id_ex_auipc1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+117,0,"id_ex_is_lui1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+118,0,"id_ex_alu_op1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+119,0,"id_ex_branch1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+120,0,"id_ex_jal1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+121,0,"id_ex_jalr1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+313,0,"id_ex_ecall1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+314,0,"id_ex_halt1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+122,0,"id_ex_csr_read1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+123,0,"id_ex_csr_write1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+124,0,"id_ex_is_rtype1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+315,0,"id_ex_valid1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+385,0,"ex_mem_fwd_val0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+386,0,"ex_mem_fwd_val1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+51,0,"mem_wb_fwd_val0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+52,0,"mem_wb_fwd_val1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+125,0,"mem_wb_sel_s0_rs1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+126,0,"mem_wb_sel_s0_rs2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+387,0,"ex_rs1_fwd0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+388,0,"ex_rs2_fwd0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+389,0,"ex_alu_a0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+390,0,"ex_alu_b0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+187,0,"ex_is_shift0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+188,0,"ex_funct7_5_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+316,0,"ex_alu_ctrl0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+391,0,"ex_alu_result0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+392,0,"ex_alu_zero0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+393,0,"ex_branch_taken0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+415,0,"ex_take_branch0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+416,0,"ex_branch_mispredict0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+127,0,"ex_branch_target0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+417,0,"ex_branch_recover_pc0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+416,0,"ex_redirect0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+417,0,"ex_redirect_pc0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+128,0,"ex_link0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+13,0,"ex_csr_rdata0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+394,0,"ex_wb_val0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+129,0,"mem_wb_sel_s1_rs1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+130,0,"mem_wb_sel_s1_rs2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+395,0,"ex_rs1_fwd1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+396,0,"ex_rs2_fwd1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+397,0,"ex_alu_a1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+398,0,"ex_alu_b1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+189,0,"ex_is_shift1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+190,0,"ex_funct7_5_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+317,0,"ex_alu_ctrl1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+399,0,"ex_alu_result1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+400,0,"ex_alu_zero1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+375,0,"ex_branch_taken1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+401,0,"ex_take_branch1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+131,0,"ex_link1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+14,0,"ex_csr_rdata1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+402,0,"ex_wb_val1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+318,0,"id0_dep_ex1_rs1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+319,0,"id0_dep_ex1_rs2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+320,0,"id0_dep_ex0_rs1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+321,0,"id0_dep_ex0_rs2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+322,0,"id0_dep_mem1_rs1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+323,0,"id0_dep_mem1_rs2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+324,0,"id0_dep_mem0_rs1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+325,0,"id0_dep_mem0_rs2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+385,0,"id_mem_fwd_val0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+386,0,"id_mem_fwd_val1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+403,0,"id_branch_rs1_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+404,0,"id_branch_rs2_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+405,0,"id_branch_taken0_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+132,0,"id_branch_fallthrough0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+326,0,"id_jal_target0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+406,0,"id_jalr_target0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+327,0,"id_is_ret0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+328,0,"id_is_call0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+133,0,"id_expected_pc0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+384,0,"id_actual_pc0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+132,0,"squash_replay_pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+191,0,"id_pred_taken_ctrl0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+418,0,"squash_replay_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+197,0,"ex_mem_alu0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+198,0,"ex_mem_rs2_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+329,0,"ex_mem_wb0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+330,0,"ex_mem_rd0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+199,0,"ex_mem_funct3_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+195,0,"ex_mem_mem_read0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+196,0,"ex_mem_mem_write0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+331,0,"ex_mem_reg_write0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+332,0,"ex_mem_mem_to_reg0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+333,0,"ex_mem_ecall0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+334,0,"ex_mem_halt0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+335,0,"ex_mem_valid0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+202,0,"ex_mem_alu1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+203,0,"ex_mem_rs2_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+336,0,"ex_mem_wb1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+337,0,"ex_mem_rd1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+204,0,"ex_mem_funct3_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+200,0,"ex_mem_mem_read1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+201,0,"ex_mem_mem_write1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+338,0,"ex_mem_reg_write1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+339,0,"ex_mem_mem_to_reg1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+340,0,"ex_mem_ecall1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+341,0,"ex_mem_halt1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+342,0,"ex_mem_valid1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+134,0,"mem_wb_wb0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+135,0,"mem_wb_mem0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+49,0,"mem_wb_rd0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+47,0,"mem_wb_reg_write0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+136,0,"mem_wb_mem_to_reg0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+137,0,"mem_wb_ecall0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+343,0,"mem_wb_halt0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+344,0,"mem_wb_valid0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+138,0,"mem_wb_wb1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+139,0,"mem_wb_mem1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+50,0,"mem_wb_rd1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+48,0,"mem_wb_reg_write1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+140,0,"mem_wb_mem_to_reg1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+141,0,"mem_wb_ecall1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+345,0,"mem_wb_halt1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+346,0,"mem_wb_valid1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("ac0", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+95,0,"alu_op",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+299,0,"funct3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+90,0,"funct7",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBit(c+188,0,"funct7_5",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+101,0,"is_rtype",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+94,0,"is_lui",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+316,0,"alu_ctrl",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+142,0,"is_m_extension",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("ac1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+118,0,"alu_op",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+308,0,"funct3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+113,0,"funct7",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBit(c+190,0,"funct7_5",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+124,0,"is_rtype",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+117,0,"is_lui",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+317,0,"alu_ctrl",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+143,0,"is_m_extension",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("alu0", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+389,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+390,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+316,0,"alu_op",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+391,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+392,0,"zero",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("alu1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+397,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+398,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+317,0,"alu_op",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+399,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+400,0,"zero",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("bc0", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+387,0,"rs1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+388,0,"rs2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+299,0,"funct3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+393,0,"branch_taken",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("bc1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+395,0,"rs1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+396,0,"rs2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+308,0,"funct3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+375,0,"branch_taken",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("csr0", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+409,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+6,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+100,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+91,0,"addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+387,0,"wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+299,0,"funct3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+387,0,"rs1_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+13,0,"rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("csr", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+15+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+4,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("csr1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+409,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+6,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+123,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+114,0,"addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+395,0,"wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+308,0,"funct3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+395,0,"rs1_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+14,0,"rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("csr", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+31+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+5,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("ctrl0", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+233,0,"opcode",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+234,0,"funct3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+235,0,"funct7",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBit(c+242,0,"mem_read",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+243,0,"mem_write",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+244,0,"reg_write",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+245,0,"mem_to_reg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+246,0,"alu_src",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+249,0,"alu_op",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+247,0,"auipc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+248,0,"is_lui",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+250,0,"imm_type",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+251,0,"branch",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+252,0,"jal",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+253,0,"jalr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+254,0,"ecall",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+255,0,"halt",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+256,0,"csr_read",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+257,0,"csr_write",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("ctrl1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+259,0,"opcode",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+260,0,"funct3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+261,0,"funct7",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBit(c+268,0,"mem_read",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+269,0,"mem_write",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+270,0,"reg_write",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+271,0,"mem_to_reg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+272,0,"alu_src",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+275,0,"alu_op",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+273,0,"auipc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+274,0,"is_lui",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+276,0,"imm_type",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+277,0,"branch",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+278,0,"jal",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+279,0,"jalr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+280,0,"ecall",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+281,0,"halt",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+282,0,"csr_read",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+283,0,"csr_write",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("fwd_unit", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+88,0,"s0_id_ex_rs1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+89,0,"s0_id_ex_rs2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+111,0,"s1_id_ex_rs1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+112,0,"s1_id_ex_rs2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+330,0,"s0_ex_mem_rd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+331,0,"s0_ex_mem_reg_write",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+337,0,"s1_ex_mem_rd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+338,0,"s1_ex_mem_reg_write",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+49,0,"s0_mem_wb_rd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+47,0,"s0_mem_wb_reg_write",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+50,0,"s1_mem_wb_rd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+48,0,"s1_mem_wb_reg_write",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+298,0,"s0_ex_rd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+302,0,"s0_ex_reg_write",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+205,0,"fwd_a0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+206,0,"fwd_b0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+207,0,"fwd_a1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+208,0,"fwd_b1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->popPrefix();
    tracep->pushPrefix("hz", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+298,0,"s0_id_ex_rd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+300,0,"s0_id_ex_mem_read",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+307,0,"s1_id_ex_rd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+309,0,"s1_id_ex_mem_read",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+237,0,"s0_if_id_rs1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+238,0,"s0_if_id_rs2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+240,0,"s0_if_id_use_rs1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+241,0,"s0_if_id_use_rs2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+263,0,"s1_if_id_rs1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+264,0,"s1_if_id_rs2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+266,0,"s1_if_id_use_rs1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+267,0,"s1_if_id_use_rs2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+415,0,"s0_ex_branch_taken",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+436,0,"s0_ex_jal",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+436,0,"s0_ex_jalr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+401,0,"s1_ex_branch_taken",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+120,0,"s1_ex_jal",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+121,0,"s1_ex_jalr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+236,0,"s0_id_rd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+244,0,"s0_id_reg_write",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+263,0,"s1_id_rs1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+264,0,"s1_id_rs2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+251,0,"s0_id_branch",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+405,0,"s0_id_branch_taken",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+78,0,"s0_id_branch_pred_taken",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+252,0,"s0_id_jal",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+253,0,"s0_id_jalr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+242,0,"s0_id_mem_read",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+297,0,"s0_s1_mem_dep",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+379,0,"stall_if",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+379,0,"stall_id",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+413,0,"flush_id",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+381,0,"flush_ex",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+382,0,"squash_s1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+347,0,"s0_need_id_rs1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+251,0,"s0_need_id_rs2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+348,0,"s0_load_use",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+349,0,"s1_load_use",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+350,0,"load_use_stall",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+407,0,"do_flush",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+379,0,"eff_load_use_stall",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+351,0,"inter_slot_load_raw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+408,0,"inter_slot_ctrl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+297,0,"inter_slot_mem",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("id_br_cmp0", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+403,0,"rs1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+404,0,"rs2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+234,0,"funct3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+405,0,"branch_taken",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("ig0", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+229,0,"instr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+250,0,"imm_type",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+258,0,"imm",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("ig1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+230,0,"instr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+276,0,"imm_type",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+284,0,"imm",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("pc_counter", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+419,0,"RESET_PC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+409,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+6,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+376,0,"stall",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+414,0,"pc_next",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+192,0,"pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("regs", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+409,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+6,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+47,0,"we0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+49,0,"wa0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+51,0,"wd0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+48,0,"we1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+50,0,"wa1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+52,0,"wd1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+237,0,"ra1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+238,0,"ra2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+263,0,"ra3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+264,0,"ra4",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+181,0,"rd1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+182,0,"rd2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+183,0,"rd3",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+184,0,"rd4",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("rf", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+144+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+176,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("imem_b", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declArray(c+423,0,"HEX_FILE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->declBus(c+419,0,"BASE_ADDR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+210,0,"addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+412,0,"instruction",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+210,0,"offset_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+352,0,"idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->popPrefix();
    tracep->pushPrefix("mem", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declArray(c+423,0,"INST_HEX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->declArray(c+427,0,"DATA_HEX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->declBus(c+419,0,"BASE_ADDR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+409,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+192,0,"inst_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+193,0,"inst_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+196,0,"mem_we0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+195,0,"mem_re0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+197,0,"mem_addr0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+198,0,"mem_wdata0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+199,0,"mem_funct3_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+377,0,"mem_rdata0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+201,0,"mem_we1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+200,0,"mem_re1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+202,0,"mem_addr1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+203,0,"mem_wdata1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+204,0,"mem_funct3_1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+378,0,"mem_rdata1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("dmem", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declArray(c+427,0,"HEX_FILE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->declBus(c+419,0,"BASE_ADDR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+409,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+196,0,"we0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+195,0,"re0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+197,0,"addr0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+198,0,"write_data0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+199,0,"funct3_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+377,0,"read_data0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+201,0,"we1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+200,0,"re1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+202,0,"addr1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+203,0,"write_data1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+204,0,"funct3_1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+378,0,"read_data1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+197,0,"offset0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+202,0,"offset1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+353,0,"idx0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 10,0);
    tracep->declBus(c+354,0,"idx1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 10,0);
    tracep->declBus(c+355,0,"byte_off0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+356,0,"byte_off1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->popPrefix();
    tracep->pushPrefix("imem", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declArray(c+423,0,"HEX_FILE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->declBus(c+419,0,"BASE_ADDR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+192,0,"addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+193,0,"instruction",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+192,0,"offset_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+357,0,"idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtb_program___024root__trace_init_top(Vtb_program___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_program___024root__trace_init_top\n"); );
    Vtb_program__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_program___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtb_program___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vtb_program___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtb_program___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtb_program___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vtb_program___024root__trace_register(Vtb_program___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_program___024root__trace_register\n"); );
    Vtb_program__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vtb_program___024root__trace_const_0, 0, vlSelf);
    tracep->addFullCb(&Vtb_program___024root__trace_full_0, 0, vlSelf);
    tracep->addChgCb(&Vtb_program___024root__trace_chg_0, 0, vlSelf);
    tracep->addCleanupCb(&Vtb_program___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtb_program___024root__trace_const_0_sub_0(Vtb_program___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtb_program___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_program___024root__trace_const_0\n"); );
    // Body
    Vtb_program___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_program___024root*>(voidSelf);
    Vtb_program__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vtb_program___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtb_program___024root__trace_const_0_sub_0(Vtb_program___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_program___024root__trace_const_0_sub_0\n"); );
    Vtb_program__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlWide<4>/*127:0*/ __Vtemp_1;
    VlWide<4>/*127:0*/ __Vtemp_2;
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullIData(oldp+419,(0U),32);
    bufp->fullBit(oldp+420,(0U));
    bufp->fullCData(oldp+421,(vlSelfRef.tb_program__DOT__decode_mnemonic__Vstatic__opcode),7);
    bufp->fullCData(oldp+422,(vlSelfRef.tb_program__DOT__decode_mnemonic__Vstatic__funct3),3);
    __Vtemp_1[0U] = 0x2e686578U;
    __Vtemp_1[1U] = 0x5f6d656dU;
    __Vtemp_1[2U] = 0x696e7374U;
    __Vtemp_1[3U] = 0x6865782fU;
    bufp->fullWData(oldp+423,(__Vtemp_1),128);
    __Vtemp_2[0U] = 0x2e686578U;
    __Vtemp_2[1U] = 0x5f6d656dU;
    __Vtemp_2[2U] = 0x64617461U;
    __Vtemp_2[3U] = 0x6865782fU;
    bufp->fullWData(oldp+427,(__Vtemp_2),128);
    bufp->fullIData(oldp+431,(8U),32);
    bufp->fullIData(oldp+432,(0x00000100U),32);
    bufp->fullIData(oldp+433,(0x00000010U),32);
    bufp->fullIData(oldp+434,(4U),32);
    bufp->fullBit(oldp+435,(1U));
    bufp->fullBit(oldp+436,(0U));
}

VL_ATTR_COLD void Vtb_program___024root__trace_full_0_sub_0(Vtb_program___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtb_program___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_program___024root__trace_full_0\n"); );
    // Body
    Vtb_program___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_program___024root*>(voidSelf);
    Vtb_program__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vtb_program___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtb_program___024root__trace_full_0_sub_0(Vtb_program___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_program___024root__trace_full_0_sub_0\n"); );
    Vtb_program__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullIData(oldp+1,(vlSelfRef.tb_program__DOT__max_cycles),32);
    bufp->fullIData(oldp+2,(vlSelfRef.tb_program__DOT__progress_interval),32);
    bufp->fullBit(oldp+3,(vlSelfRef.tb_program__DOT__progress_enable));
    bufp->fullIData(oldp+4,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__i),32);
    bufp->fullIData(oldp+5,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__i),32);
    bufp->fullBit(oldp+6,(vlSelfRef.tb_program__DOT__rst));
    bufp->fullIData(oldp+7,(vlSelfRef.tb_program__DOT__f),32);
    bufp->fullIData(oldp+8,(vlSelfRef.tb_program__DOT__i),32);
    bufp->fullIData(oldp+9,(vlSelfRef.tb_program__DOT__stable_pc_count),32);
    bufp->fullIData(oldp+10,(vlSelfRef.tb_program__DOT__last_pc),32);
    bufp->fullBit(oldp+11,(vlSelfRef.tb_program__DOT__done));
    bufp->fullBit(oldp+12,(vlSelfRef.tb_program__DOT__timed_out));
    bufp->fullIData(oldp+13,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr
                             [(0x0000000fU & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_csr0))]),32);
    bufp->fullIData(oldp+14,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr
                             [(0x0000000fU & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_csr1))]),32);
    bufp->fullIData(oldp+15,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr[0]),32);
    bufp->fullIData(oldp+16,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr[1]),32);
    bufp->fullIData(oldp+17,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr[2]),32);
    bufp->fullIData(oldp+18,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr[3]),32);
    bufp->fullIData(oldp+19,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr[4]),32);
    bufp->fullIData(oldp+20,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr[5]),32);
    bufp->fullIData(oldp+21,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr[6]),32);
    bufp->fullIData(oldp+22,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr[7]),32);
    bufp->fullIData(oldp+23,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr[8]),32);
    bufp->fullIData(oldp+24,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr[9]),32);
    bufp->fullIData(oldp+25,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr[10]),32);
    bufp->fullIData(oldp+26,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr[11]),32);
    bufp->fullIData(oldp+27,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr[12]),32);
    bufp->fullIData(oldp+28,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr[13]),32);
    bufp->fullIData(oldp+29,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr[14]),32);
    bufp->fullIData(oldp+30,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr[15]),32);
    bufp->fullIData(oldp+31,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr[0]),32);
    bufp->fullIData(oldp+32,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr[1]),32);
    bufp->fullIData(oldp+33,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr[2]),32);
    bufp->fullIData(oldp+34,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr[3]),32);
    bufp->fullIData(oldp+35,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr[4]),32);
    bufp->fullIData(oldp+36,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr[5]),32);
    bufp->fullIData(oldp+37,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr[6]),32);
    bufp->fullIData(oldp+38,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr[7]),32);
    bufp->fullIData(oldp+39,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr[8]),32);
    bufp->fullIData(oldp+40,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr[9]),32);
    bufp->fullIData(oldp+41,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr[10]),32);
    bufp->fullIData(oldp+42,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr[11]),32);
    bufp->fullIData(oldp+43,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr[12]),32);
    bufp->fullIData(oldp+44,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr[13]),32);
    bufp->fullIData(oldp+45,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr[14]),32);
    bufp->fullIData(oldp+46,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr[15]),32);
    bufp->fullBit(oldp+47,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_reg_write0));
    bufp->fullBit(oldp+48,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_reg_write1));
    bufp->fullCData(oldp+49,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_rd0),5);
    bufp->fullCData(oldp+50,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_rd1),5);
    bufp->fullIData(oldp+51,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__wd0),32);
    bufp->fullIData(oldp+52,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__wd1),32);
    bufp->fullCData(oldp+53,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hybp_ghr),8);
    bufp->fullIData(oldp+54,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_stack[0]),32);
    bufp->fullIData(oldp+55,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_stack[1]),32);
    bufp->fullIData(oldp+56,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_stack[2]),32);
    bufp->fullIData(oldp+57,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_stack[3]),32);
    bufp->fullIData(oldp+58,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_stack[4]),32);
    bufp->fullIData(oldp+59,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_stack[5]),32);
    bufp->fullIData(oldp+60,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_stack[6]),32);
    bufp->fullIData(oldp+61,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_stack[7]),32);
    bufp->fullIData(oldp+62,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_stack[8]),32);
    bufp->fullIData(oldp+63,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_stack[9]),32);
    bufp->fullIData(oldp+64,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_stack[10]),32);
    bufp->fullIData(oldp+65,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_stack[11]),32);
    bufp->fullIData(oldp+66,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_stack[12]),32);
    bufp->fullIData(oldp+67,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_stack[13]),32);
    bufp->fullIData(oldp+68,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_stack[14]),32);
    bufp->fullIData(oldp+69,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_stack[15]),32);
    bufp->fullCData(oldp+70,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_top_ptr),4);
    bufp->fullCData(oldp+71,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_count),5);
    bufp->fullIData(oldp+72,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hybp_i),32);
    bufp->fullIData(oldp+73,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_i),32);
    bufp->fullBit(oldp+74,((0U != (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_count))));
    bufp->fullIData(oldp+75,(((0U != (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_count))
                               ? vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_stack
                              [vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_top_ptr]
                               : 0U)),32);
    bufp->fullIData(oldp+76,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_pc0),32);
    bufp->fullIData(oldp+77,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_pc1),32);
    bufp->fullBit(oldp+78,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_pred_taken0));
    bufp->fullIData(oldp+79,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_pred_target0),32);
    bufp->fullCData(oldp+80,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_local_idx0),8);
    bufp->fullCData(oldp+81,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_global_idx0),8);
    bufp->fullBit(oldp+82,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_local_pred_taken0));
    bufp->fullBit(oldp+83,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_global_pred_taken0));
    bufp->fullIData(oldp+84,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_pc0),32);
    bufp->fullIData(oldp+85,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rd1_0),32);
    bufp->fullIData(oldp+86,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rd2_0),32);
    bufp->fullIData(oldp+87,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_imm0),32);
    bufp->fullCData(oldp+88,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rs1_0),5);
    bufp->fullCData(oldp+89,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rs2_0),5);
    bufp->fullCData(oldp+90,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_funct7_0),7);
    bufp->fullSData(oldp+91,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_csr0),12);
    bufp->fullBit(oldp+92,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_alu_src0));
    bufp->fullBit(oldp+93,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_auipc0));
    bufp->fullBit(oldp+94,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_is_lui0));
    bufp->fullCData(oldp+95,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_alu_op0),2);
    bufp->fullBit(oldp+96,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_branch0));
    bufp->fullBit(oldp+97,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_jal0));
    bufp->fullBit(oldp+98,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_jalr0));
    bufp->fullBit(oldp+99,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_csr_read0));
    bufp->fullBit(oldp+100,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_csr_write0));
    bufp->fullBit(oldp+101,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_is_rtype0));
    bufp->fullBit(oldp+102,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_pred_taken0));
    bufp->fullCData(oldp+103,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_local_idx0),8);
    bufp->fullCData(oldp+104,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_global_idx0),8);
    bufp->fullBit(oldp+105,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_local_pred_taken0));
    bufp->fullBit(oldp+106,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_global_pred_taken0));
    bufp->fullIData(oldp+107,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_pc1),32);
    bufp->fullIData(oldp+108,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rd1_1),32);
    bufp->fullIData(oldp+109,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rd2_1),32);
    bufp->fullIData(oldp+110,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_imm1),32);
    bufp->fullCData(oldp+111,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rs1_1),5);
    bufp->fullCData(oldp+112,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rs2_1),5);
    bufp->fullCData(oldp+113,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_funct7_1),7);
    bufp->fullSData(oldp+114,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_csr1),12);
    bufp->fullBit(oldp+115,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_alu_src1));
    bufp->fullBit(oldp+116,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_auipc1));
    bufp->fullBit(oldp+117,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_is_lui1));
    bufp->fullCData(oldp+118,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_alu_op1),2);
    bufp->fullBit(oldp+119,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_branch1));
    bufp->fullBit(oldp+120,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_jal1));
    bufp->fullBit(oldp+121,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_jalr1));
    bufp->fullBit(oldp+122,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_csr_read1));
    bufp->fullBit(oldp+123,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_csr_write1));
    bufp->fullBit(oldp+124,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_is_rtype1));
    bufp->fullIData(oldp+125,(((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_10)
                                ? vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__wd1
                                : vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__wd0)),32);
    bufp->fullIData(oldp+126,(((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_11)
                                ? vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__wd1
                                : vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__wd0)),32);
    bufp->fullIData(oldp+127,((vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_imm0 
                               + vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_pc0)),32);
    bufp->fullIData(oldp+128,(((IData)(4U) + vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_pc0)),32);
    bufp->fullIData(oldp+129,(((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_12)
                                ? vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__wd1
                                : vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__wd0)),32);
    bufp->fullIData(oldp+130,(((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_13)
                                ? vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__wd1
                                : vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__wd0)),32);
    bufp->fullIData(oldp+131,(((IData)(4U) + vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_pc1)),32);
    bufp->fullIData(oldp+132,(((IData)(4U) + vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_pc0)),32);
    bufp->fullIData(oldp+133,(((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_pred_taken0)
                                ? vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_pred_target0
                                : ((IData)(4U) + vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_pc0))),32);
    bufp->fullIData(oldp+134,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_wb0),32);
    bufp->fullIData(oldp+135,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_mem0),32);
    bufp->fullBit(oldp+136,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_mem_to_reg0));
    bufp->fullBit(oldp+137,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_ecall0));
    bufp->fullIData(oldp+138,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_wb1),32);
    bufp->fullIData(oldp+139,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_mem1),32);
    bufp->fullBit(oldp+140,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_mem_to_reg1));
    bufp->fullBit(oldp+141,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_ecall1));
    bufp->fullBit(oldp+142,(((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_is_rtype0) 
                             & (1U == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_funct7_0)))));
    bufp->fullBit(oldp+143,(((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_is_rtype1) 
                             & (1U == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_funct7_1)))));
    bufp->fullIData(oldp+144,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[0]),32);
    bufp->fullIData(oldp+145,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[1]),32);
    bufp->fullIData(oldp+146,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[2]),32);
    bufp->fullIData(oldp+147,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[3]),32);
    bufp->fullIData(oldp+148,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[4]),32);
    bufp->fullIData(oldp+149,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[5]),32);
    bufp->fullIData(oldp+150,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[6]),32);
    bufp->fullIData(oldp+151,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[7]),32);
    bufp->fullIData(oldp+152,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[8]),32);
    bufp->fullIData(oldp+153,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[9]),32);
    bufp->fullIData(oldp+154,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[10]),32);
    bufp->fullIData(oldp+155,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[11]),32);
    bufp->fullIData(oldp+156,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[12]),32);
    bufp->fullIData(oldp+157,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[13]),32);
    bufp->fullIData(oldp+158,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[14]),32);
    bufp->fullIData(oldp+159,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[15]),32);
    bufp->fullIData(oldp+160,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[16]),32);
    bufp->fullIData(oldp+161,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[17]),32);
    bufp->fullIData(oldp+162,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[18]),32);
    bufp->fullIData(oldp+163,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[19]),32);
    bufp->fullIData(oldp+164,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[20]),32);
    bufp->fullIData(oldp+165,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[21]),32);
    bufp->fullIData(oldp+166,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[22]),32);
    bufp->fullIData(oldp+167,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[23]),32);
    bufp->fullIData(oldp+168,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[24]),32);
    bufp->fullIData(oldp+169,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[25]),32);
    bufp->fullIData(oldp+170,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[26]),32);
    bufp->fullIData(oldp+171,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[27]),32);
    bufp->fullIData(oldp+172,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[28]),32);
    bufp->fullIData(oldp+173,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[29]),32);
    bufp->fullIData(oldp+174,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[30]),32);
    bufp->fullIData(oldp+175,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[31]),32);
    bufp->fullIData(oldp+176,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__i),32);
    bufp->fullBit(oldp+177,((((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_ecall0) 
                              & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_valid0)) 
                             | ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_ecall1) 
                                & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_valid1)))));
    bufp->fullBit(oldp+178,((1U & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hybp_choice_pht
                                   [vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_global_idx0] 
                                   >> 1U))));
    bufp->fullBit(oldp+179,(((2U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hybp_choice_pht
                              [vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_global_idx0])
                              ? (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_global_pred_taken0)
                              : (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_local_pred_taken0))));
    bufp->fullBit(oldp+180,(((0x67U == (0x0000007fU 
                                        & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__instr0)) 
                             & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_is_ret0)
                                 ? (0U != (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_count))
                                 : (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_btb_hit0)))));
    bufp->fullIData(oldp+181,(((0U == (0x0000001fU 
                                       & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                          >> 0x0000000fU)))
                                ? 0U : vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                               [(0x0000001fU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                                >> 0x0000000fU))])),32);
    bufp->fullIData(oldp+182,(((0U == (0x0000001fU 
                                       & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                          >> 0x00000014U)))
                                ? 0U : vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                               [(0x0000001fU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                                >> 0x00000014U))])),32);
    bufp->fullIData(oldp+183,(((0U == (0x0000001fU 
                                       & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                          >> 0x0000000fU)))
                                ? 0U : vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                               [(0x0000001fU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                                >> 0x0000000fU))])),32);
    bufp->fullIData(oldp+184,(((0U == (0x0000001fU 
                                       & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                          >> 0x00000014U)))
                                ? 0U : vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                               [(0x0000001fU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                                >> 0x00000014U))])),32);
    bufp->fullIData(oldp+185,((((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_4) 
                                & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_rd1) 
                                   == (0x0000001fU 
                                       & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                          >> 0x0000000fU))))
                                ? vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__wd1
                                : (((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_5) 
                                    & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_rd0) 
                                       == (0x0000001fU 
                                           & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                              >> 0x0000000fU))))
                                    ? vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__wd0
                                    : ((0U == (0x0000001fU 
                                               & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                                  >> 0x0000000fU)))
                                        ? 0U : vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                                       [(0x0000001fU 
                                         & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                            >> 0x0000000fU))])))),32);
    bufp->fullIData(oldp+186,((((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_4) 
                                & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_rd1) 
                                   == (0x0000001fU 
                                       & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                          >> 0x00000014U))))
                                ? vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__wd1
                                : (((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_5) 
                                    & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_rd0) 
                                       == (0x0000001fU 
                                           & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                              >> 0x00000014U))))
                                    ? vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__wd0
                                    : ((0U == (0x0000001fU 
                                               & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                                  >> 0x00000014U)))
                                        ? 0U : vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                                       [(0x0000001fU 
                                         & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                            >> 0x00000014U))])))),32);
    bufp->fullBit(oldp+187,(((2U == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_alu_op0)) 
                             & (5U == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_funct3_0)))));
    bufp->fullBit(oldp+188,(((((2U == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_alu_op0)) 
                               & (5U == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_funct3_0))) 
                              | (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_is_rtype0)) 
                             & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_funct7_0) 
                                >> 5U))));
    bufp->fullBit(oldp+189,(((2U == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_alu_op1)) 
                             & (5U == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_funct3_1)))));
    bufp->fullBit(oldp+190,(((((2U == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_alu_op1)) 
                               & (5U == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_funct3_1))) 
                              | (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_is_rtype1)) 
                             & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_funct7_1) 
                                >> 5U))));
    bufp->fullBit(oldp+191,(((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_14) 
                             & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_pred_taken0))));
    bufp->fullIData(oldp+192,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__pc_current),32);
    bufp->fullIData(oldp+193,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__instr0),32);
    bufp->fullBit(oldp+194,((((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_halt0) 
                              & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_valid0)) 
                             | ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_halt1) 
                                & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_valid1)))));
    bufp->fullBit(oldp+195,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_mem_read0));
    bufp->fullBit(oldp+196,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_mem_write0));
    bufp->fullIData(oldp+197,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu0),32);
    bufp->fullIData(oldp+198,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_rs2_0),32);
    bufp->fullCData(oldp+199,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_funct3_0),3);
    bufp->fullBit(oldp+200,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_mem_read1));
    bufp->fullBit(oldp+201,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_mem_write1));
    bufp->fullIData(oldp+202,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu1),32);
    bufp->fullIData(oldp+203,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_rs2_1),32);
    bufp->fullCData(oldp+204,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_funct3_1),3);
    bufp->fullCData(oldp+205,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__fwd_unit__DOT__fwd_a0),2);
    bufp->fullCData(oldp+206,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__fwd_unit__DOT__fwd_b0),2);
    bufp->fullCData(oldp+207,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__fwd_unit__DOT__fwd_a1),3);
    bufp->fullCData(oldp+208,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__fwd_unit__DOT__fwd_b1),3);
    bufp->fullBit(oldp+209,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__pipe_halt));
    bufp->fullIData(oldp+210,(((IData)(4U) + vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__pc_current)),32);
    bufp->fullIData(oldp+211,(((IData)(8U) + vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__pc_current)),32);
    bufp->fullCData(oldp+212,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_pred_pc_idx),8);
    bufp->fullBit(oldp+213,((0x63U == (0x0000007fU 
                                       & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__instr0))));
    bufp->fullBit(oldp+214,((0x6fU == (0x0000007fU 
                                       & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__instr0))));
    bufp->fullBit(oldp+215,((0x67U == (0x0000007fU 
                                       & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__instr0))));
    bufp->fullCData(oldp+216,((0x0000001fU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__instr0 
                                              >> 7U))),5);
    bufp->fullCData(oldp+217,((0x0000001fU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__instr0 
                                              >> 0x0000000fU))),5);
    bufp->fullIData(oldp+218,((((- (IData)((vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__instr0 
                                            >> 0x0000001fU))) 
                                << 0x0000000dU) | (
                                                   (((2U 
                                                      & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__instr0 
                                                         >> 0x0000001eU)) 
                                                     | (1U 
                                                        & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__instr0 
                                                           >> 7U))) 
                                                    << 0x0000000bU) 
                                                   | ((0x000007e0U 
                                                       & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__instr0 
                                                          >> 0x00000014U)) 
                                                      | (0x0000001eU 
                                                         & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__instr0 
                                                            >> 7U)))))),32);
    bufp->fullIData(oldp+219,(((((0x00000ffeU & ((- (IData)(
                                                            (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__instr0 
                                                             >> 0x0000001fU))) 
                                                 << 1U)) 
                                 | (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__instr0 
                                    >> 0x0000001fU)) 
                                << 0x00000014U) | (
                                                   (((0x000001feU 
                                                      & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__instr0 
                                                         >> 0x0000000bU)) 
                                                     | (1U 
                                                        & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__instr0 
                                                           >> 0x00000014U))) 
                                                    << 0x0000000bU) 
                                                   | (0x000007feU 
                                                      & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__instr0 
                                                         >> 0x00000014U))))),32);
    bufp->fullIData(oldp+220,((((- (IData)((vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__instr0 
                                            >> 0x0000001fU))) 
                                << 0x0000000cU) | (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__instr0 
                                                   >> 0x00000014U))),32);
    bufp->fullBit(oldp+221,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_is_ret0));
    bufp->fullCData(oldp+222,((0x000000ffU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__pc_current 
                                              >> 2U))),8);
    bufp->fullBit(oldp+223,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_btb_hit0));
    bufp->fullCData(oldp+224,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_global_idx0),8);
    bufp->fullBit(oldp+225,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_local_pred_taken0));
    bufp->fullBit(oldp+226,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_global_pred_taken0));
    bufp->fullBit(oldp+227,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_pred_taken0));
    bufp->fullIData(oldp+228,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_pred_target0),32);
    bufp->fullIData(oldp+229,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0),32);
    bufp->fullIData(oldp+230,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1),32);
    bufp->fullBit(oldp+231,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_valid0));
    bufp->fullBit(oldp+232,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_valid1));
    bufp->fullCData(oldp+233,((0x0000007fU & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)),7);
    bufp->fullCData(oldp+234,((7U & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                     >> 0x0000000cU))),3);
    bufp->fullCData(oldp+235,((vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                               >> 0x00000019U)),7);
    bufp->fullCData(oldp+236,((0x0000001fU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                              >> 7U))),5);
    bufp->fullCData(oldp+237,((0x0000001fU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                              >> 0x0000000fU))),5);
    bufp->fullCData(oldp+238,((0x0000001fU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                              >> 0x00000014U))),5);
    bufp->fullSData(oldp+239,((vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                               >> 0x00000014U)),12);
    bufp->fullBit(oldp+240,(((3U == (0x0000007fU & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) 
                             | ((0x23U == (0x0000007fU 
                                           & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) 
                                | ((0x63U == (0x0000007fU 
                                              & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) 
                                   | ((0x67U == (0x0000007fU 
                                                 & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) 
                                      | ((0x13U == 
                                          (0x0000007fU 
                                           & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) 
                                         | ((0x33U 
                                             == (0x0000007fU 
                                                 & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) 
                                            | ((~ (
                                                   (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                                    >> 0x0000000eU) 
                                                   | (0U 
                                                      == 
                                                      (7U 
                                                       & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                                          >> 0x0000000cU))))) 
                                               & (0x73U 
                                                  == 
                                                  (0x0000007fU 
                                                   & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)))))))))));
    bufp->fullBit(oldp+241,(((0x23U == (0x0000007fU 
                                        & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) 
                             | ((0x63U == (0x0000007fU 
                                           & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) 
                                | (0x33U == (0x0000007fU 
                                             & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0))))));
    bufp->fullBit(oldp+242,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_mem_read0));
    bufp->fullBit(oldp+243,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_mem_write0));
    bufp->fullBit(oldp+244,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_reg_write0));
    bufp->fullBit(oldp+245,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_mem_to_reg0));
    bufp->fullBit(oldp+246,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_alu_src0));
    bufp->fullBit(oldp+247,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_auipc0));
    bufp->fullBit(oldp+248,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_is_lui0));
    bufp->fullCData(oldp+249,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_alu_op0),2);
    bufp->fullCData(oldp+250,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_imm_type0),3);
    bufp->fullBit(oldp+251,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_branch0));
    bufp->fullBit(oldp+252,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_jal0));
    bufp->fullBit(oldp+253,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_jalr0));
    bufp->fullBit(oldp+254,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ecall0));
    bufp->fullBit(oldp+255,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_halt0));
    bufp->fullBit(oldp+256,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_csr_read0));
    bufp->fullBit(oldp+257,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_csr_write0));
    bufp->fullIData(oldp+258,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ig0__DOT__imm),32);
    bufp->fullCData(oldp+259,((0x0000007fU & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)),7);
    bufp->fullCData(oldp+260,((7U & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                     >> 0x0000000cU))),3);
    bufp->fullCData(oldp+261,((vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                               >> 0x00000019U)),7);
    bufp->fullCData(oldp+262,((0x0000001fU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                              >> 7U))),5);
    bufp->fullCData(oldp+263,((0x0000001fU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                              >> 0x0000000fU))),5);
    bufp->fullCData(oldp+264,((0x0000001fU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                              >> 0x00000014U))),5);
    bufp->fullSData(oldp+265,((vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                               >> 0x00000014U)),12);
    bufp->fullBit(oldp+266,(((3U == (0x0000007fU & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) 
                             | ((0x23U == (0x0000007fU 
                                           & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) 
                                | ((0x63U == (0x0000007fU 
                                              & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) 
                                   | ((0x67U == (0x0000007fU 
                                                 & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) 
                                      | ((0x13U == 
                                          (0x0000007fU 
                                           & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) 
                                         | ((0x33U 
                                             == (0x0000007fU 
                                                 & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) 
                                            | ((~ (
                                                   (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                                    >> 0x0000000eU) 
                                                   | (0U 
                                                      == 
                                                      (7U 
                                                       & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                                          >> 0x0000000cU))))) 
                                               & (0x73U 
                                                  == 
                                                  (0x0000007fU 
                                                   & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)))))))))));
    bufp->fullBit(oldp+267,(((0x23U == (0x0000007fU 
                                        & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) 
                             | ((0x63U == (0x0000007fU 
                                           & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) 
                                | (0x33U == (0x0000007fU 
                                             & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1))))));
    bufp->fullBit(oldp+268,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_mem_read1));
    bufp->fullBit(oldp+269,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_mem_write1));
    bufp->fullBit(oldp+270,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_reg_write1));
    bufp->fullBit(oldp+271,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_mem_to_reg1));
    bufp->fullBit(oldp+272,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_alu_src1));
    bufp->fullBit(oldp+273,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_auipc1));
    bufp->fullBit(oldp+274,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_is_lui1));
    bufp->fullCData(oldp+275,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_alu_op1),2);
    bufp->fullCData(oldp+276,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_imm_type1),3);
    bufp->fullBit(oldp+277,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_branch1));
    bufp->fullBit(oldp+278,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_jal1));
    bufp->fullBit(oldp+279,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_jalr1));
    bufp->fullBit(oldp+280,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ecall1));
    bufp->fullBit(oldp+281,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_halt1));
    bufp->fullBit(oldp+282,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_csr_read1));
    bufp->fullBit(oldp+283,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_csr_write1));
    bufp->fullIData(oldp+284,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ig1__DOT__imm),32);
    bufp->fullBit(oldp+285,((0x33U == (0x0000007fU 
                                       & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0))));
    bufp->fullBit(oldp+286,((0x33U == (0x0000007fU 
                                       & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1))));
    bufp->fullIData(oldp+287,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_rd1_0),32);
    bufp->fullIData(oldp+288,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_rd2_0),32);
    bufp->fullBit(oldp+289,(((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_mem_write0) 
                             & (0x00002000U == (0x00007000U 
                                                & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)))));
    bufp->fullBit(oldp+290,(((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_mem_write0) 
                             & (0x00001000U == (0x00007000U 
                                                & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)))));
    bufp->fullBit(oldp+291,(((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_mem_write0) 
                             & (0U == (0x00007000U 
                                       & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)))));
    bufp->fullBit(oldp+292,(((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_mem_read1) 
                             & (0x00002000U == (0x00007000U 
                                                & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)))));
    bufp->fullBit(oldp+293,(((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_mem_read1) 
                             & ((1U == (7U & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                              >> 0x0000000cU))) 
                                | (5U == (7U & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                                >> 0x0000000cU)))))));
    bufp->fullBit(oldp+294,(((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_mem_read1) 
                             & ((0U == (7U & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                              >> 0x0000000cU))) 
                                | (4U == (7U & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                                >> 0x0000000cU)))))));
    bufp->fullBit(oldp+295,(((3U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ig0__DOT__imm) 
                             == (3U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ig1__DOT__imm))));
    bufp->fullBit(oldp+296,(((1U & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ig0__DOT__imm 
                                    >> 1U)) == (1U 
                                                & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ig1__DOT__imm 
                                                   >> 1U)))));
    bufp->fullBit(oldp+297,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__s0_s1_mem_dep));
    bufp->fullCData(oldp+298,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rd0),5);
    bufp->fullCData(oldp+299,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_funct3_0),3);
    bufp->fullBit(oldp+300,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_mem_read0));
    bufp->fullBit(oldp+301,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_mem_write0));
    bufp->fullBit(oldp+302,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_reg_write0));
    bufp->fullBit(oldp+303,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_mem_to_reg0));
    bufp->fullBit(oldp+304,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_ecall0));
    bufp->fullBit(oldp+305,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_halt0));
    bufp->fullBit(oldp+306,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_valid0));
    bufp->fullCData(oldp+307,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rd1),5);
    bufp->fullCData(oldp+308,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_funct3_1),3);
    bufp->fullBit(oldp+309,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_mem_read1));
    bufp->fullBit(oldp+310,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_mem_write1));
    bufp->fullBit(oldp+311,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_reg_write1));
    bufp->fullBit(oldp+312,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_mem_to_reg1));
    bufp->fullBit(oldp+313,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_ecall1));
    bufp->fullBit(oldp+314,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_halt1));
    bufp->fullBit(oldp+315,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_valid1));
    bufp->fullCData(oldp+316,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_alu_ctrl0),5);
    bufp->fullCData(oldp+317,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_alu_ctrl1),5);
    bufp->fullBit(oldp+318,(((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_7) 
                             & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rd1) 
                                == (0x0000001fU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                                   >> 0x0000000fU))))));
    bufp->fullBit(oldp+319,(((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_7) 
                             & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rd1) 
                                == (0x0000001fU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                                   >> 0x00000014U))))));
    bufp->fullBit(oldp+320,(((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_8) 
                             & (IData)(vlSelfRef.__VdfgRegularize_he50b618e_0_3))));
    bufp->fullBit(oldp+321,(((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_8) 
                             & (IData)(vlSelfRef.__VdfgRegularize_he50b618e_0_4))));
    bufp->fullBit(oldp+322,(((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_9) 
                             & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_rd1) 
                                == (0x0000001fU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                                   >> 0x0000000fU))))));
    bufp->fullBit(oldp+323,(((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_9) 
                             & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_rd1) 
                                == (0x0000001fU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                                   >> 0x00000014U))))));
    bufp->fullBit(oldp+324,(((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_10) 
                             & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_rd0) 
                                == (0x0000001fU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                                   >> 0x0000000fU))))));
    bufp->fullBit(oldp+325,(((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_10) 
                             & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_rd0) 
                                == (0x0000001fU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                                   >> 0x00000014U))))));
    bufp->fullIData(oldp+326,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_jal_target0),32);
    bufp->fullBit(oldp+327,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_is_ret0));
    bufp->fullBit(oldp+328,(((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_13) 
                             & ((~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_is_ret0)) 
                                & ((1U == (0x0000001fU 
                                           & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                              >> 7U))) 
                                   | (5U == (0x0000001fU 
                                             & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                                >> 7U))))))));
    bufp->fullIData(oldp+329,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_wb0),32);
    bufp->fullCData(oldp+330,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_rd0),5);
    bufp->fullBit(oldp+331,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_reg_write0));
    bufp->fullBit(oldp+332,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_mem_to_reg0));
    bufp->fullBit(oldp+333,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_ecall0));
    bufp->fullBit(oldp+334,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_halt0));
    bufp->fullBit(oldp+335,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_valid0));
    bufp->fullIData(oldp+336,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_wb1),32);
    bufp->fullCData(oldp+337,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_rd1),5);
    bufp->fullBit(oldp+338,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_reg_write1));
    bufp->fullBit(oldp+339,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_mem_to_reg1));
    bufp->fullBit(oldp+340,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_ecall1));
    bufp->fullBit(oldp+341,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_halt1));
    bufp->fullBit(oldp+342,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_valid1));
    bufp->fullBit(oldp+343,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_halt0));
    bufp->fullBit(oldp+344,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_valid0));
    bufp->fullBit(oldp+345,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_halt1));
    bufp->fullBit(oldp+346,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_valid1));
    bufp->fullBit(oldp+347,(((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_branch0) 
                             | (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_jalr0))));
    bufp->fullBit(oldp+348,(((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_mem_read0) 
                             & ((0U != (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rd0)) 
                                & (((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT____VdfgRegularize_h6b6f5558_0_0) 
                                    & (IData)(vlSelfRef.__VdfgRegularize_he50b618e_0_3)) 
                                   | ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT____VdfgRegularize_h6b6f5558_0_1) 
                                      & (IData)(vlSelfRef.__VdfgRegularize_he50b618e_0_4)))))));
    bufp->fullBit(oldp+349,(((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_mem_read1) 
                             & ((0U != (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rd1)) 
                                & (((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT____VdfgRegularize_h6b6f5558_0_0) 
                                    & ((0x0000001fU 
                                        & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                           >> 0x0000000fU)) 
                                       == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rd1))) 
                                   | ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT____VdfgRegularize_h6b6f5558_0_1) 
                                      & ((0x0000001fU 
                                          & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                             >> 0x00000014U)) 
                                         == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rd1))))))));
    bufp->fullBit(oldp+350,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__load_use_stall));
    bufp->fullBit(oldp+351,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__inter_slot_load_raw));
    bufp->fullSData(oldp+352,((0x00000fffU & (((IData)(4U) 
                                               + vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__pc_current) 
                                              >> 2U))),12);
    bufp->fullSData(oldp+353,((0x000007ffU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu0 
                                              >> 2U))),11);
    bufp->fullSData(oldp+354,((0x000007ffU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu1 
                                              >> 2U))),11);
    bufp->fullCData(oldp+355,((3U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu0)),2);
    bufp->fullCData(oldp+356,((3U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu1)),2);
    bufp->fullSData(oldp+357,((0x00000fffU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__pc_current 
                                              >> 2U))),12);
    bufp->fullBit(oldp+358,(((~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__squash_s1)) 
                             & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_mem_read1))));
    bufp->fullBit(oldp+359,(((~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__squash_s1)) 
                             & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_mem_write1))));
    bufp->fullBit(oldp+360,(((~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__squash_s1)) 
                             & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_reg_write1))));
    bufp->fullBit(oldp+361,(((~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__squash_s1)) 
                             & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_mem_to_reg1))));
    bufp->fullBit(oldp+362,(((~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__squash_s1)) 
                             & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_alu_src1))));
    bufp->fullCData(oldp+363,(((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__squash_s1)
                                ? 0U : (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_alu_op1))),2);
    bufp->fullBit(oldp+364,(((~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__squash_s1)) 
                             & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_auipc1))));
    bufp->fullBit(oldp+365,(((~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__squash_s1)) 
                             & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_is_lui1))));
    bufp->fullBit(oldp+366,(((~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__squash_s1)) 
                             & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_branch1))));
    bufp->fullBit(oldp+367,(((~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__squash_s1)) 
                             & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_jal1))));
    bufp->fullBit(oldp+368,(((~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__squash_s1)) 
                             & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_jalr1))));
    bufp->fullBit(oldp+369,(((~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__squash_s1)) 
                             & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ecall1))));
    bufp->fullBit(oldp+370,(((~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__squash_s1)) 
                             & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_halt1))));
    bufp->fullBit(oldp+371,(((~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__squash_s1)) 
                             & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_csr_read1))));
    bufp->fullBit(oldp+372,(((~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__squash_s1)) 
                             & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_csr_write1))));
    bufp->fullBit(oldp+373,(((~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__squash_s1)) 
                             & (0x33U == (0x0000007fU 
                                          & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)))));
    bufp->fullCData(oldp+374,(((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__squash_s1)
                                ? 0U : (0x0000001fU 
                                        & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                           >> 7U)))),5);
    bufp->fullBit(oldp+375,(((4U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_funct3_1))
                              ? ((2U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_funct3_1))
                                  ? ((1U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_funct3_1))
                                      ? (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc1__DOT__rs1 
                                         >= vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc1__DOT__rs2)
                                      : (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc1__DOT__rs1 
                                         < vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc1__DOT__rs2))
                                  : ((1U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_funct3_1))
                                      ? VL_GTES_III(32, vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc1__DOT__rs1, vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc1__DOT__rs2)
                                      : VL_LTS_III(32, vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc1__DOT__rs1, vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc1__DOT__rs2)))
                              : ((~ ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_funct3_1) 
                                     >> 1U)) & ((1U 
                                                 & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_funct3_1))
                                                 ? 
                                                (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc1__DOT__rs1 
                                                 != vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc1__DOT__rs2)
                                                 : 
                                                (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc1__DOT__rs1 
                                                 == vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc1__DOT__rs2))))));
    bufp->fullBit(oldp+376,(((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__stall_if) 
                             | (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__pipe_halt))));
    bufp->fullIData(oldp+377,(vlSelfRef.tb_program__DOT__uut__DOT__mem_rdata0),32);
    bufp->fullIData(oldp+378,(vlSelfRef.tb_program__DOT__uut__DOT__mem_rdata1),32);
    bufp->fullBit(oldp+379,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__stall_if));
    bufp->fullBit(oldp+380,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__flush_id));
    bufp->fullBit(oldp+381,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__flush_ex));
    bufp->fullBit(oldp+382,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__squash_s1));
    bufp->fullBit(oldp+383,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_branch_redirect0));
    bufp->fullIData(oldp+384,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_branch_target0),32);
    bufp->fullIData(oldp+385,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_fwd_val0),32);
    bufp->fullIData(oldp+386,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_fwd_val1),32);
    bufp->fullIData(oldp+387,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc0__DOT__rs1),32);
    bufp->fullIData(oldp+388,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc0__DOT__rs2),32);
    bufp->fullIData(oldp+389,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu0__DOT__a),32);
    bufp->fullIData(oldp+390,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu0__DOT__b),32);
    bufp->fullIData(oldp+391,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu0__DOT__result),32);
    bufp->fullBit(oldp+392,((0U == vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu0__DOT__result)));
    bufp->fullBit(oldp+393,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc0__DOT__branch_taken));
    bufp->fullIData(oldp+394,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_wb_val0),32);
    bufp->fullIData(oldp+395,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc1__DOT__rs1),32);
    bufp->fullIData(oldp+396,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc1__DOT__rs2),32);
    bufp->fullIData(oldp+397,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu1__DOT__a),32);
    bufp->fullIData(oldp+398,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu1__DOT__b),32);
    bufp->fullIData(oldp+399,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu1__DOT__result),32);
    bufp->fullBit(oldp+400,((0U == vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu1__DOT__result)));
    bufp->fullBit(oldp+401,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__s1_ex_branch_taken));
    bufp->fullIData(oldp+402,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_wb_val1),32);
    bufp->fullIData(oldp+403,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_br_cmp0__DOT__rs1),32);
    bufp->fullIData(oldp+404,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_br_cmp0__DOT__rs2),32);
    bufp->fullBit(oldp+405,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__s0_id_branch_taken));
    bufp->fullIData(oldp+406,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_jalr_target0),32);
    bufp->fullBit(oldp+407,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__do_flush));
    bufp->fullBit(oldp+408,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__inter_slot_ctrl));
    bufp->fullBit(oldp+409,(vlSelfRef.tb_program__DOT__clk));
    bufp->fullIData(oldp+410,(vlSelfRef.tb_program__DOT__cycle_count),32);
    bufp->fullIData(oldp+411,(vlSelfRef.tb_program__DOT__instret_count),32);
    bufp->fullIData(oldp+412,(vlSelfRef.tb_program__DOT__uut__DOT__imem_b__DOT__mem
                              [(0x00000fffU & (((IData)(4U) 
                                                + vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__pc_current) 
                                               >> 2U))]),32);
    bufp->fullBit(oldp+413,(((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__do_flush) 
                             | ((~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__stall_if)) 
                                & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__inter_slot_load_raw) 
                                   | (((~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_pred_taken0)) 
                                       & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__inter_slot_ctrl)) 
                                      | (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__s0_s1_mem_dep)))))));
    bufp->fullIData(oldp+414,((((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_branch0) 
                                & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_pred_taken0) 
                                   != (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc0__DOT__branch_taken)))
                                ? ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc0__DOT__branch_taken)
                                    ? (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_imm0 
                                       + vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_pc0)
                                    : ((IData)(4U) 
                                       + vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_pc0))
                                : ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__s1_ex_branch_taken)
                                    ? vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_15
                                    : ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_jal1)
                                        ? vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_15
                                        : ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_jalr1)
                                            ? (0xfffffffeU 
                                               & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc1__DOT__rs1 
                                                  + vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_imm1))
                                            : ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_branch_redirect0)
                                                ? vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_branch_target0
                                                : (
                                                   ((~ 
                                                     ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_14) 
                                                      & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_pred_taken0))) 
                                                    & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__squash_s1))
                                                    ? 
                                                   ((IData)(4U) 
                                                    + vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_pc0)
                                                    : 
                                                   ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_pred_taken0)
                                                     ? vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_pred_target0
                                                     : 
                                                    ((IData)(8U) 
                                                     + vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__pc_current))))))))),32);
    bufp->fullBit(oldp+415,(((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc0__DOT__branch_taken) 
                             & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_branch0))));
    bufp->fullBit(oldp+416,(((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_branch0) 
                             & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_pred_taken0) 
                                != (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc0__DOT__branch_taken)))));
    bufp->fullIData(oldp+417,(((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc0__DOT__branch_taken)
                                ? (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_imm0 
                                   + vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_pc0)
                                : ((IData)(4U) + vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_pc0))),32);
    bufp->fullBit(oldp+418,(((~ ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_14) 
                                 & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_pred_taken0))) 
                             & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__squash_s1))));
}
