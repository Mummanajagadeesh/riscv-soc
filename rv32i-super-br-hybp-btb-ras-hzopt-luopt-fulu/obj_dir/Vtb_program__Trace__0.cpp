// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vtb_program__Syms.h"


void Vtb_program___024root__trace_chg_0_sub_0(Vtb_program___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtb_program___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_program___024root__trace_chg_0\n"); );
    // Body
    Vtb_program___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_program___024root*>(voidSelf);
    Vtb_program__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vtb_program___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtb_program___024root__trace_chg_0_sub_0(Vtb_program___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_program___024root__trace_chg_0_sub_0\n"); );
    Vtb_program__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U]))) {
        bufp->chgIData(oldp+0,(vlSelfRef.tb_program__DOT__max_cycles),32);
        bufp->chgIData(oldp+1,(vlSelfRef.tb_program__DOT__progress_interval),32);
        bufp->chgBit(oldp+2,(vlSelfRef.tb_program__DOT__progress_enable));
        bufp->chgIData(oldp+3,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__i),32);
        bufp->chgIData(oldp+4,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__i),32);
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[1U] 
                      | vlSelfRef.__Vm_traceActivity
                      [2U])))) {
        bufp->chgBit(oldp+5,(vlSelfRef.tb_program__DOT__rst));
        bufp->chgIData(oldp+6,(vlSelfRef.tb_program__DOT__f),32);
        bufp->chgIData(oldp+7,(vlSelfRef.tb_program__DOT__i),32);
        bufp->chgIData(oldp+8,(vlSelfRef.tb_program__DOT__stable_pc_count),32);
        bufp->chgIData(oldp+9,(vlSelfRef.tb_program__DOT__last_pc),32);
        bufp->chgBit(oldp+10,(vlSelfRef.tb_program__DOT__done));
        bufp->chgBit(oldp+11,(vlSelfRef.tb_program__DOT__timed_out));
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[1U] 
                      | vlSelfRef.__Vm_traceActivity
                      [3U])))) {
        bufp->chgIData(oldp+12,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr
                                [(0x0000000fU & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_csr0))]),32);
        bufp->chgIData(oldp+13,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr
                                [(0x0000000fU & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_csr1))]),32);
        bufp->chgIData(oldp+14,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr[0]),32);
        bufp->chgIData(oldp+15,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr[1]),32);
        bufp->chgIData(oldp+16,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr[2]),32);
        bufp->chgIData(oldp+17,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr[3]),32);
        bufp->chgIData(oldp+18,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr[4]),32);
        bufp->chgIData(oldp+19,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr[5]),32);
        bufp->chgIData(oldp+20,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr[6]),32);
        bufp->chgIData(oldp+21,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr[7]),32);
        bufp->chgIData(oldp+22,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr[8]),32);
        bufp->chgIData(oldp+23,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr[9]),32);
        bufp->chgIData(oldp+24,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr[10]),32);
        bufp->chgIData(oldp+25,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr[11]),32);
        bufp->chgIData(oldp+26,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr[12]),32);
        bufp->chgIData(oldp+27,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr[13]),32);
        bufp->chgIData(oldp+28,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr[14]),32);
        bufp->chgIData(oldp+29,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr[15]),32);
        bufp->chgIData(oldp+30,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr[0]),32);
        bufp->chgIData(oldp+31,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr[1]),32);
        bufp->chgIData(oldp+32,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr[2]),32);
        bufp->chgIData(oldp+33,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr[3]),32);
        bufp->chgIData(oldp+34,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr[4]),32);
        bufp->chgIData(oldp+35,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr[5]),32);
        bufp->chgIData(oldp+36,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr[6]),32);
        bufp->chgIData(oldp+37,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr[7]),32);
        bufp->chgIData(oldp+38,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr[8]),32);
        bufp->chgIData(oldp+39,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr[9]),32);
        bufp->chgIData(oldp+40,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr[10]),32);
        bufp->chgIData(oldp+41,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr[11]),32);
        bufp->chgIData(oldp+42,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr[12]),32);
        bufp->chgIData(oldp+43,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr[13]),32);
        bufp->chgIData(oldp+44,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr[14]),32);
        bufp->chgIData(oldp+45,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr[15]),32);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[3U]))) {
        bufp->chgBit(oldp+46,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_reg_write0));
        bufp->chgBit(oldp+47,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_reg_write1));
        bufp->chgCData(oldp+48,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_rd0),5);
        bufp->chgCData(oldp+49,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_rd1),5);
        bufp->chgIData(oldp+50,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__wd0),32);
        bufp->chgIData(oldp+51,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__wd1),32);
        bufp->chgCData(oldp+52,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hybp_ghr),8);
        bufp->chgIData(oldp+53,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_stack[0]),32);
        bufp->chgIData(oldp+54,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_stack[1]),32);
        bufp->chgIData(oldp+55,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_stack[2]),32);
        bufp->chgIData(oldp+56,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_stack[3]),32);
        bufp->chgIData(oldp+57,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_stack[4]),32);
        bufp->chgIData(oldp+58,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_stack[5]),32);
        bufp->chgIData(oldp+59,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_stack[6]),32);
        bufp->chgIData(oldp+60,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_stack[7]),32);
        bufp->chgIData(oldp+61,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_stack[8]),32);
        bufp->chgIData(oldp+62,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_stack[9]),32);
        bufp->chgIData(oldp+63,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_stack[10]),32);
        bufp->chgIData(oldp+64,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_stack[11]),32);
        bufp->chgIData(oldp+65,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_stack[12]),32);
        bufp->chgIData(oldp+66,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_stack[13]),32);
        bufp->chgIData(oldp+67,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_stack[14]),32);
        bufp->chgIData(oldp+68,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_stack[15]),32);
        bufp->chgCData(oldp+69,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_top_ptr),4);
        bufp->chgCData(oldp+70,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_count),5);
        bufp->chgIData(oldp+71,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hybp_i),32);
        bufp->chgIData(oldp+72,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_i),32);
        bufp->chgBit(oldp+73,((0U != (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_count))));
        bufp->chgIData(oldp+74,(((0U != (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_count))
                                  ? vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_stack
                                 [vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_top_ptr]
                                  : 0U)),32);
        bufp->chgIData(oldp+75,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_pc0),32);
        bufp->chgIData(oldp+76,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_pc1),32);
        bufp->chgBit(oldp+77,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_pred_taken0));
        bufp->chgIData(oldp+78,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_pred_target0),32);
        bufp->chgCData(oldp+79,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_local_idx0),8);
        bufp->chgCData(oldp+80,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_global_idx0),8);
        bufp->chgBit(oldp+81,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_local_pred_taken0));
        bufp->chgBit(oldp+82,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_global_pred_taken0));
        bufp->chgIData(oldp+83,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_pc0),32);
        bufp->chgIData(oldp+84,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rd1_0),32);
        bufp->chgIData(oldp+85,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rd2_0),32);
        bufp->chgIData(oldp+86,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_imm0),32);
        bufp->chgCData(oldp+87,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rs1_0),5);
        bufp->chgCData(oldp+88,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rs2_0),5);
        bufp->chgCData(oldp+89,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_funct7_0),7);
        bufp->chgSData(oldp+90,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_csr0),12);
        bufp->chgBit(oldp+91,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_alu_src0));
        bufp->chgBit(oldp+92,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_auipc0));
        bufp->chgBit(oldp+93,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_is_lui0));
        bufp->chgCData(oldp+94,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_alu_op0),2);
        bufp->chgBit(oldp+95,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_branch0));
        bufp->chgBit(oldp+96,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_jal0));
        bufp->chgBit(oldp+97,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_jalr0));
        bufp->chgBit(oldp+98,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_csr_read0));
        bufp->chgBit(oldp+99,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_csr_write0));
        bufp->chgBit(oldp+100,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_is_rtype0));
        bufp->chgBit(oldp+101,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_pred_taken0));
        bufp->chgCData(oldp+102,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_local_idx0),8);
        bufp->chgCData(oldp+103,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_global_idx0),8);
        bufp->chgBit(oldp+104,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_local_pred_taken0));
        bufp->chgBit(oldp+105,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_global_pred_taken0));
        bufp->chgIData(oldp+106,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_pc1),32);
        bufp->chgIData(oldp+107,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rd1_1),32);
        bufp->chgIData(oldp+108,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rd2_1),32);
        bufp->chgIData(oldp+109,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_imm1),32);
        bufp->chgCData(oldp+110,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rs1_1),5);
        bufp->chgCData(oldp+111,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rs2_1),5);
        bufp->chgCData(oldp+112,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_funct7_1),7);
        bufp->chgSData(oldp+113,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_csr1),12);
        bufp->chgBit(oldp+114,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_alu_src1));
        bufp->chgBit(oldp+115,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_auipc1));
        bufp->chgBit(oldp+116,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_is_lui1));
        bufp->chgCData(oldp+117,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_alu_op1),2);
        bufp->chgBit(oldp+118,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_branch1));
        bufp->chgBit(oldp+119,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_jal1));
        bufp->chgBit(oldp+120,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_jalr1));
        bufp->chgBit(oldp+121,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_csr_read1));
        bufp->chgBit(oldp+122,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_csr_write1));
        bufp->chgBit(oldp+123,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_is_rtype1));
        bufp->chgIData(oldp+124,(((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_10)
                                   ? vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__wd1
                                   : vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__wd0)),32);
        bufp->chgIData(oldp+125,(((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_11)
                                   ? vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__wd1
                                   : vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__wd0)),32);
        bufp->chgIData(oldp+126,((vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_imm0 
                                  + vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_pc0)),32);
        bufp->chgIData(oldp+127,(((IData)(4U) + vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_pc0)),32);
        bufp->chgIData(oldp+128,(((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_12)
                                   ? vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__wd1
                                   : vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__wd0)),32);
        bufp->chgIData(oldp+129,(((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_13)
                                   ? vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__wd1
                                   : vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__wd0)),32);
        bufp->chgIData(oldp+130,(((IData)(4U) + vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_pc1)),32);
        bufp->chgIData(oldp+131,(((IData)(4U) + vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_pc0)),32);
        bufp->chgIData(oldp+132,(((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_pred_taken0)
                                   ? vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_pred_target0
                                   : ((IData)(4U) + vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_pc0))),32);
        bufp->chgIData(oldp+133,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_wb0),32);
        bufp->chgIData(oldp+134,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_mem0),32);
        bufp->chgBit(oldp+135,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_mem_to_reg0));
        bufp->chgBit(oldp+136,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_ecall0));
        bufp->chgIData(oldp+137,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_wb1),32);
        bufp->chgIData(oldp+138,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_mem1),32);
        bufp->chgBit(oldp+139,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_mem_to_reg1));
        bufp->chgBit(oldp+140,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_ecall1));
        bufp->chgBit(oldp+141,(((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_is_rtype0) 
                                & (1U == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_funct7_0)))));
        bufp->chgBit(oldp+142,(((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_is_rtype1) 
                                & (1U == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_funct7_1)))));
        bufp->chgIData(oldp+143,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[0]),32);
        bufp->chgIData(oldp+144,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[1]),32);
        bufp->chgIData(oldp+145,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[2]),32);
        bufp->chgIData(oldp+146,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[3]),32);
        bufp->chgIData(oldp+147,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[4]),32);
        bufp->chgIData(oldp+148,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[5]),32);
        bufp->chgIData(oldp+149,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[6]),32);
        bufp->chgIData(oldp+150,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[7]),32);
        bufp->chgIData(oldp+151,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[8]),32);
        bufp->chgIData(oldp+152,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[9]),32);
        bufp->chgIData(oldp+153,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[10]),32);
        bufp->chgIData(oldp+154,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[11]),32);
        bufp->chgIData(oldp+155,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[12]),32);
        bufp->chgIData(oldp+156,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[13]),32);
        bufp->chgIData(oldp+157,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[14]),32);
        bufp->chgIData(oldp+158,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[15]),32);
        bufp->chgIData(oldp+159,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[16]),32);
        bufp->chgIData(oldp+160,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[17]),32);
        bufp->chgIData(oldp+161,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[18]),32);
        bufp->chgIData(oldp+162,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[19]),32);
        bufp->chgIData(oldp+163,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[20]),32);
        bufp->chgIData(oldp+164,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[21]),32);
        bufp->chgIData(oldp+165,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[22]),32);
        bufp->chgIData(oldp+166,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[23]),32);
        bufp->chgIData(oldp+167,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[24]),32);
        bufp->chgIData(oldp+168,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[25]),32);
        bufp->chgIData(oldp+169,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[26]),32);
        bufp->chgIData(oldp+170,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[27]),32);
        bufp->chgIData(oldp+171,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[28]),32);
        bufp->chgIData(oldp+172,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[29]),32);
        bufp->chgIData(oldp+173,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[30]),32);
        bufp->chgIData(oldp+174,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[31]),32);
        bufp->chgIData(oldp+175,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__i),32);
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[3U] 
                      | vlSelfRef.__Vm_traceActivity
                      [4U])))) {
        bufp->chgBit(oldp+176,((((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_ecall0) 
                                 & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_valid0)) 
                                | ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_ecall1) 
                                   & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_valid1)))));
        bufp->chgBit(oldp+177,((1U & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hybp_choice_pht
                                      [vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_global_idx0] 
                                      >> 1U))));
        bufp->chgBit(oldp+178,(((2U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hybp_choice_pht
                                 [vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_global_idx0])
                                 ? (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_global_pred_taken0)
                                 : (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_local_pred_taken0))));
        bufp->chgBit(oldp+179,(((0x67U == (0x0000007fU 
                                           & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__instr0)) 
                                & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_is_ret0)
                                    ? (0U != (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_count))
                                    : (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_btb_hit0)))));
        bufp->chgIData(oldp+180,(((0U == (0x0000001fU 
                                          & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                             >> 0x0000000fU)))
                                   ? 0U : vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                                  [(0x0000001fU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                                   >> 0x0000000fU))])),32);
        bufp->chgIData(oldp+181,(((0U == (0x0000001fU 
                                          & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                             >> 0x00000014U)))
                                   ? 0U : vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                                  [(0x0000001fU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                                   >> 0x00000014U))])),32);
        bufp->chgIData(oldp+182,(((0U == (0x0000001fU 
                                          & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                             >> 0x0000000fU)))
                                   ? 0U : vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                                  [(0x0000001fU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                                   >> 0x0000000fU))])),32);
        bufp->chgIData(oldp+183,(((0U == (0x0000001fU 
                                          & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                             >> 0x00000014U)))
                                   ? 0U : vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                                  [(0x0000001fU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                                   >> 0x00000014U))])),32);
        bufp->chgIData(oldp+184,((((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_4) 
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
        bufp->chgIData(oldp+185,((((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_4) 
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
        bufp->chgBit(oldp+186,(((2U == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_alu_op0)) 
                                & (5U == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_funct3_0)))));
        bufp->chgBit(oldp+187,(((((2U == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_alu_op0)) 
                                  & (5U == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_funct3_0))) 
                                 | (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_is_rtype0)) 
                                & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_funct7_0) 
                                   >> 5U))));
        bufp->chgBit(oldp+188,(((2U == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_alu_op1)) 
                                & (5U == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_funct3_1)))));
        bufp->chgBit(oldp+189,(((((2U == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_alu_op1)) 
                                  & (5U == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_funct3_1))) 
                                 | (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_is_rtype1)) 
                                & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_funct7_1) 
                                   >> 5U))));
        bufp->chgBit(oldp+190,(((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_14) 
                                & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_pred_taken0))));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[4U]))) {
        bufp->chgIData(oldp+191,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__pc_current),32);
        bufp->chgIData(oldp+192,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__instr0),32);
        bufp->chgBit(oldp+193,((((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_halt0) 
                                 & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_valid0)) 
                                | ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_halt1) 
                                   & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_valid1)))));
        bufp->chgBit(oldp+194,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_mem_read0));
        bufp->chgBit(oldp+195,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_mem_write0));
        bufp->chgIData(oldp+196,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu0),32);
        bufp->chgIData(oldp+197,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_rs2_0),32);
        bufp->chgCData(oldp+198,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_funct3_0),3);
        bufp->chgBit(oldp+199,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_mem_read1));
        bufp->chgBit(oldp+200,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_mem_write1));
        bufp->chgIData(oldp+201,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu1),32);
        bufp->chgIData(oldp+202,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_rs2_1),32);
        bufp->chgCData(oldp+203,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_funct3_1),3);
        bufp->chgCData(oldp+204,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__fwd_unit__DOT__fwd_a0),2);
        bufp->chgCData(oldp+205,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__fwd_unit__DOT__fwd_b0),2);
        bufp->chgCData(oldp+206,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__fwd_unit__DOT__fwd_a1),3);
        bufp->chgCData(oldp+207,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__fwd_unit__DOT__fwd_b1),3);
        bufp->chgBit(oldp+208,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__pipe_halt));
        bufp->chgIData(oldp+209,(((IData)(4U) + vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__pc_current)),32);
        bufp->chgIData(oldp+210,(((IData)(8U) + vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__pc_current)),32);
        bufp->chgCData(oldp+211,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_pred_pc_idx),8);
        bufp->chgBit(oldp+212,((0x63U == (0x0000007fU 
                                          & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__instr0))));
        bufp->chgBit(oldp+213,((0x6fU == (0x0000007fU 
                                          & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__instr0))));
        bufp->chgBit(oldp+214,((0x67U == (0x0000007fU 
                                          & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__instr0))));
        bufp->chgCData(oldp+215,((0x0000001fU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__instr0 
                                                 >> 7U))),5);
        bufp->chgCData(oldp+216,((0x0000001fU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__instr0 
                                                 >> 0x0000000fU))),5);
        bufp->chgIData(oldp+217,((((- (IData)((vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__instr0 
                                               >> 0x0000001fU))) 
                                   << 0x0000000dU) 
                                  | ((((2U & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__instr0 
                                              >> 0x0000001eU)) 
                                       | (1U & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__instr0 
                                                >> 7U))) 
                                      << 0x0000000bU) 
                                     | ((0x000007e0U 
                                         & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__instr0 
                                            >> 0x00000014U)) 
                                        | (0x0000001eU 
                                           & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__instr0 
                                              >> 7U)))))),32);
        bufp->chgIData(oldp+218,(((((0x00000ffeU & 
                                     ((- (IData)((vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__instr0 
                                                  >> 0x0000001fU))) 
                                      << 1U)) | (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__instr0 
                                                 >> 0x0000001fU)) 
                                   << 0x00000014U) 
                                  | ((((0x000001feU 
                                        & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__instr0 
                                           >> 0x0000000bU)) 
                                       | (1U & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__instr0 
                                                >> 0x00000014U))) 
                                      << 0x0000000bU) 
                                     | (0x000007feU 
                                        & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__instr0 
                                           >> 0x00000014U))))),32);
        bufp->chgIData(oldp+219,((((- (IData)((vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__instr0 
                                               >> 0x0000001fU))) 
                                   << 0x0000000cU) 
                                  | (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__instr0 
                                     >> 0x00000014U))),32);
        bufp->chgBit(oldp+220,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_is_ret0));
        bufp->chgCData(oldp+221,((0x000000ffU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__pc_current 
                                                 >> 2U))),8);
        bufp->chgBit(oldp+222,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_btb_hit0));
        bufp->chgCData(oldp+223,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_global_idx0),8);
        bufp->chgBit(oldp+224,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_local_pred_taken0));
        bufp->chgBit(oldp+225,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_global_pred_taken0));
        bufp->chgBit(oldp+226,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_pred_taken0));
        bufp->chgIData(oldp+227,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_pred_target0),32);
        bufp->chgIData(oldp+228,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0),32);
        bufp->chgIData(oldp+229,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1),32);
        bufp->chgBit(oldp+230,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_valid0));
        bufp->chgBit(oldp+231,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_valid1));
        bufp->chgCData(oldp+232,((0x0000007fU & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)),7);
        bufp->chgCData(oldp+233,((7U & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                        >> 0x0000000cU))),3);
        bufp->chgCData(oldp+234,((vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                  >> 0x00000019U)),7);
        bufp->chgCData(oldp+235,((0x0000001fU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                                 >> 7U))),5);
        bufp->chgCData(oldp+236,((0x0000001fU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                                 >> 0x0000000fU))),5);
        bufp->chgCData(oldp+237,((0x0000001fU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                                 >> 0x00000014U))),5);
        bufp->chgSData(oldp+238,((vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                  >> 0x00000014U)),12);
        bufp->chgBit(oldp+239,(((3U == (0x0000007fU 
                                        & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) 
                                | ((0x23U == (0x0000007fU 
                                              & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) 
                                   | ((0x63U == (0x0000007fU 
                                                 & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) 
                                      | ((0x67U == 
                                          (0x0000007fU 
                                           & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) 
                                         | ((0x13U 
                                             == (0x0000007fU 
                                                 & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) 
                                            | ((0x33U 
                                                == 
                                                (0x0000007fU 
                                                 & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) 
                                               | ((~ 
                                                   ((vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
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
        bufp->chgBit(oldp+240,(((0x23U == (0x0000007fU 
                                           & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) 
                                | ((0x63U == (0x0000007fU 
                                              & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) 
                                   | (0x33U == (0x0000007fU 
                                                & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0))))));
        bufp->chgBit(oldp+241,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_mem_read0));
        bufp->chgBit(oldp+242,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_mem_write0));
        bufp->chgBit(oldp+243,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_reg_write0));
        bufp->chgBit(oldp+244,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_mem_to_reg0));
        bufp->chgBit(oldp+245,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_alu_src0));
        bufp->chgBit(oldp+246,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_auipc0));
        bufp->chgBit(oldp+247,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_is_lui0));
        bufp->chgCData(oldp+248,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_alu_op0),2);
        bufp->chgCData(oldp+249,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_imm_type0),3);
        bufp->chgBit(oldp+250,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_branch0));
        bufp->chgBit(oldp+251,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_jal0));
        bufp->chgBit(oldp+252,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_jalr0));
        bufp->chgBit(oldp+253,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ecall0));
        bufp->chgBit(oldp+254,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_halt0));
        bufp->chgBit(oldp+255,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_csr_read0));
        bufp->chgBit(oldp+256,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_csr_write0));
        bufp->chgIData(oldp+257,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ig0__DOT__imm),32);
        bufp->chgCData(oldp+258,((0x0000007fU & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)),7);
        bufp->chgCData(oldp+259,((7U & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                        >> 0x0000000cU))),3);
        bufp->chgCData(oldp+260,((vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                  >> 0x00000019U)),7);
        bufp->chgCData(oldp+261,((0x0000001fU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                                 >> 7U))),5);
        bufp->chgCData(oldp+262,((0x0000001fU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                                 >> 0x0000000fU))),5);
        bufp->chgCData(oldp+263,((0x0000001fU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                                 >> 0x00000014U))),5);
        bufp->chgSData(oldp+264,((vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                  >> 0x00000014U)),12);
        bufp->chgBit(oldp+265,(((3U == (0x0000007fU 
                                        & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) 
                                | ((0x23U == (0x0000007fU 
                                              & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) 
                                   | ((0x63U == (0x0000007fU 
                                                 & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) 
                                      | ((0x67U == 
                                          (0x0000007fU 
                                           & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) 
                                         | ((0x13U 
                                             == (0x0000007fU 
                                                 & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) 
                                            | ((0x33U 
                                                == 
                                                (0x0000007fU 
                                                 & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) 
                                               | ((~ 
                                                   ((vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
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
        bufp->chgBit(oldp+266,(((0x23U == (0x0000007fU 
                                           & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) 
                                | ((0x63U == (0x0000007fU 
                                              & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) 
                                   | (0x33U == (0x0000007fU 
                                                & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1))))));
        bufp->chgBit(oldp+267,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_mem_read1));
        bufp->chgBit(oldp+268,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_mem_write1));
        bufp->chgBit(oldp+269,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_reg_write1));
        bufp->chgBit(oldp+270,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_mem_to_reg1));
        bufp->chgBit(oldp+271,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_alu_src1));
        bufp->chgBit(oldp+272,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_auipc1));
        bufp->chgBit(oldp+273,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_is_lui1));
        bufp->chgCData(oldp+274,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_alu_op1),2);
        bufp->chgCData(oldp+275,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_imm_type1),3);
        bufp->chgBit(oldp+276,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_branch1));
        bufp->chgBit(oldp+277,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_jal1));
        bufp->chgBit(oldp+278,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_jalr1));
        bufp->chgBit(oldp+279,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ecall1));
        bufp->chgBit(oldp+280,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_halt1));
        bufp->chgBit(oldp+281,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_csr_read1));
        bufp->chgBit(oldp+282,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_csr_write1));
        bufp->chgIData(oldp+283,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ig1__DOT__imm),32);
        bufp->chgBit(oldp+284,((0x33U == (0x0000007fU 
                                          & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0))));
        bufp->chgBit(oldp+285,((0x33U == (0x0000007fU 
                                          & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1))));
        bufp->chgIData(oldp+286,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_rd1_0),32);
        bufp->chgIData(oldp+287,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_rd2_0),32);
        bufp->chgBit(oldp+288,(((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_mem_write0) 
                                & (0x00002000U == (0x00007000U 
                                                   & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)))));
        bufp->chgBit(oldp+289,(((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_mem_write0) 
                                & (0x00001000U == (0x00007000U 
                                                   & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)))));
        bufp->chgBit(oldp+290,(((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_mem_write0) 
                                & (0U == (0x00007000U 
                                          & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)))));
        bufp->chgBit(oldp+291,(((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_mem_read1) 
                                & (0x00002000U == (0x00007000U 
                                                   & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)))));
        bufp->chgBit(oldp+292,(((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_mem_read1) 
                                & ((1U == (7U & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                                 >> 0x0000000cU))) 
                                   | (5U == (7U & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                                   >> 0x0000000cU)))))));
        bufp->chgBit(oldp+293,(((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_mem_read1) 
                                & ((0U == (7U & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                                 >> 0x0000000cU))) 
                                   | (4U == (7U & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                                   >> 0x0000000cU)))))));
        bufp->chgBit(oldp+294,(((3U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ig0__DOT__imm) 
                                == (3U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ig1__DOT__imm))));
        bufp->chgBit(oldp+295,(((1U & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ig0__DOT__imm 
                                       >> 1U)) == (1U 
                                                   & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ig1__DOT__imm 
                                                      >> 1U)))));
        bufp->chgBit(oldp+296,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__s0_s1_mem_dep));
        bufp->chgCData(oldp+297,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rd0),5);
        bufp->chgCData(oldp+298,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_funct3_0),3);
        bufp->chgBit(oldp+299,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_mem_read0));
        bufp->chgBit(oldp+300,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_mem_write0));
        bufp->chgBit(oldp+301,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_reg_write0));
        bufp->chgBit(oldp+302,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_mem_to_reg0));
        bufp->chgBit(oldp+303,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_ecall0));
        bufp->chgBit(oldp+304,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_halt0));
        bufp->chgBit(oldp+305,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_valid0));
        bufp->chgCData(oldp+306,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rd1),5);
        bufp->chgCData(oldp+307,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_funct3_1),3);
        bufp->chgBit(oldp+308,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_mem_read1));
        bufp->chgBit(oldp+309,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_mem_write1));
        bufp->chgBit(oldp+310,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_reg_write1));
        bufp->chgBit(oldp+311,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_mem_to_reg1));
        bufp->chgBit(oldp+312,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_ecall1));
        bufp->chgBit(oldp+313,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_halt1));
        bufp->chgBit(oldp+314,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_valid1));
        bufp->chgCData(oldp+315,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_alu_ctrl0),5);
        bufp->chgCData(oldp+316,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_alu_ctrl1),5);
        bufp->chgBit(oldp+317,(((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_7) 
                                & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rd1) 
                                   == (0x0000001fU 
                                       & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                          >> 0x0000000fU))))));
        bufp->chgBit(oldp+318,(((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_7) 
                                & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rd1) 
                                   == (0x0000001fU 
                                       & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                          >> 0x00000014U))))));
        bufp->chgBit(oldp+319,(((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_8) 
                                & (IData)(vlSelfRef.__VdfgRegularize_he50b618e_0_3))));
        bufp->chgBit(oldp+320,(((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_8) 
                                & (IData)(vlSelfRef.__VdfgRegularize_he50b618e_0_4))));
        bufp->chgBit(oldp+321,(((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_9) 
                                & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_rd1) 
                                   == (0x0000001fU 
                                       & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                          >> 0x0000000fU))))));
        bufp->chgBit(oldp+322,(((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_9) 
                                & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_rd1) 
                                   == (0x0000001fU 
                                       & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                          >> 0x00000014U))))));
        bufp->chgBit(oldp+323,(((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_10) 
                                & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_rd0) 
                                   == (0x0000001fU 
                                       & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                          >> 0x0000000fU))))));
        bufp->chgBit(oldp+324,(((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_10) 
                                & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_rd0) 
                                   == (0x0000001fU 
                                       & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                          >> 0x00000014U))))));
        bufp->chgIData(oldp+325,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_jal_target0),32);
        bufp->chgBit(oldp+326,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_is_ret0));
        bufp->chgBit(oldp+327,(((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_13) 
                                & ((~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_is_ret0)) 
                                   & ((1U == (0x0000001fU 
                                              & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                                 >> 7U))) 
                                      | (5U == (0x0000001fU 
                                                & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                                   >> 7U))))))));
        bufp->chgIData(oldp+328,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_wb0),32);
        bufp->chgCData(oldp+329,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_rd0),5);
        bufp->chgBit(oldp+330,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_reg_write0));
        bufp->chgBit(oldp+331,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_mem_to_reg0));
        bufp->chgBit(oldp+332,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_ecall0));
        bufp->chgBit(oldp+333,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_halt0));
        bufp->chgBit(oldp+334,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_valid0));
        bufp->chgIData(oldp+335,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_wb1),32);
        bufp->chgCData(oldp+336,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_rd1),5);
        bufp->chgBit(oldp+337,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_reg_write1));
        bufp->chgBit(oldp+338,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_mem_to_reg1));
        bufp->chgBit(oldp+339,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_ecall1));
        bufp->chgBit(oldp+340,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_halt1));
        bufp->chgBit(oldp+341,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_valid1));
        bufp->chgBit(oldp+342,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_halt0));
        bufp->chgBit(oldp+343,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_valid0));
        bufp->chgBit(oldp+344,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_halt1));
        bufp->chgBit(oldp+345,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_valid1));
        bufp->chgBit(oldp+346,(((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_branch0) 
                                | (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_jalr0))));
        bufp->chgBit(oldp+347,(((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_mem_read0) 
                                & ((0U != (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rd0)) 
                                   & (((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT____VdfgRegularize_h6b6f5558_0_0) 
                                       & (IData)(vlSelfRef.__VdfgRegularize_he50b618e_0_3)) 
                                      | ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT____VdfgRegularize_h6b6f5558_0_1) 
                                         & (IData)(vlSelfRef.__VdfgRegularize_he50b618e_0_4)))))));
        bufp->chgBit(oldp+348,(((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_mem_read1) 
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
        bufp->chgBit(oldp+349,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__load_use_stall));
        bufp->chgBit(oldp+350,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__inter_slot_load_raw));
        bufp->chgSData(oldp+351,((0x00000fffU & (((IData)(4U) 
                                                  + vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__pc_current) 
                                                 >> 2U))),12);
        bufp->chgSData(oldp+352,((0x000007ffU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu0 
                                                 >> 2U))),11);
        bufp->chgSData(oldp+353,((0x000007ffU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu1 
                                                 >> 2U))),11);
        bufp->chgCData(oldp+354,((3U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu0)),2);
        bufp->chgCData(oldp+355,((3U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu1)),2);
        bufp->chgSData(oldp+356,((0x00000fffU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__pc_current 
                                                 >> 2U))),12);
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[4U] 
                      | vlSelfRef.__Vm_traceActivity
                      [5U])))) {
        bufp->chgBit(oldp+357,(((~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__squash_s1)) 
                                & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_mem_read1))));
        bufp->chgBit(oldp+358,(((~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__squash_s1)) 
                                & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_mem_write1))));
        bufp->chgBit(oldp+359,(((~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__squash_s1)) 
                                & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_reg_write1))));
        bufp->chgBit(oldp+360,(((~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__squash_s1)) 
                                & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_mem_to_reg1))));
        bufp->chgBit(oldp+361,(((~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__squash_s1)) 
                                & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_alu_src1))));
        bufp->chgCData(oldp+362,(((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__squash_s1)
                                   ? 0U : (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_alu_op1))),2);
        bufp->chgBit(oldp+363,(((~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__squash_s1)) 
                                & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_auipc1))));
        bufp->chgBit(oldp+364,(((~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__squash_s1)) 
                                & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_is_lui1))));
        bufp->chgBit(oldp+365,(((~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__squash_s1)) 
                                & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_branch1))));
        bufp->chgBit(oldp+366,(((~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__squash_s1)) 
                                & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_jal1))));
        bufp->chgBit(oldp+367,(((~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__squash_s1)) 
                                & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_jalr1))));
        bufp->chgBit(oldp+368,(((~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__squash_s1)) 
                                & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ecall1))));
        bufp->chgBit(oldp+369,(((~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__squash_s1)) 
                                & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_halt1))));
        bufp->chgBit(oldp+370,(((~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__squash_s1)) 
                                & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_csr_read1))));
        bufp->chgBit(oldp+371,(((~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__squash_s1)) 
                                & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_csr_write1))));
        bufp->chgBit(oldp+372,(((~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__squash_s1)) 
                                & (0x33U == (0x0000007fU 
                                             & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)))));
        bufp->chgCData(oldp+373,(((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__squash_s1)
                                   ? 0U : (0x0000001fU 
                                           & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                              >> 7U)))),5);
        bufp->chgBit(oldp+374,(((4U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_funct3_1))
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
                                        >> 1U)) & (
                                                   (1U 
                                                    & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_funct3_1))
                                                    ? 
                                                   (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc1__DOT__rs1 
                                                    != vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc1__DOT__rs2)
                                                    : 
                                                   (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc1__DOT__rs1 
                                                    == vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc1__DOT__rs2))))));
        bufp->chgBit(oldp+375,(((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__stall_if) 
                                | (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__pipe_halt))));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[5U]))) {
        bufp->chgIData(oldp+376,(vlSelfRef.tb_program__DOT__uut__DOT__mem_rdata0),32);
        bufp->chgIData(oldp+377,(vlSelfRef.tb_program__DOT__uut__DOT__mem_rdata1),32);
        bufp->chgBit(oldp+378,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__stall_if));
        bufp->chgBit(oldp+379,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__flush_id));
        bufp->chgBit(oldp+380,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__flush_ex));
        bufp->chgBit(oldp+381,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__squash_s1));
        bufp->chgBit(oldp+382,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_branch_redirect0));
        bufp->chgIData(oldp+383,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_branch_target0),32);
        bufp->chgIData(oldp+384,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_fwd_val0),32);
        bufp->chgIData(oldp+385,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_fwd_val1),32);
        bufp->chgIData(oldp+386,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc0__DOT__rs1),32);
        bufp->chgIData(oldp+387,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc0__DOT__rs2),32);
        bufp->chgIData(oldp+388,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu0__DOT__a),32);
        bufp->chgIData(oldp+389,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu0__DOT__b),32);
        bufp->chgIData(oldp+390,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu0__DOT__result),32);
        bufp->chgBit(oldp+391,((0U == vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu0__DOT__result)));
        bufp->chgBit(oldp+392,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc0__DOT__branch_taken));
        bufp->chgIData(oldp+393,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_wb_val0),32);
        bufp->chgIData(oldp+394,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc1__DOT__rs1),32);
        bufp->chgIData(oldp+395,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc1__DOT__rs2),32);
        bufp->chgIData(oldp+396,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu1__DOT__a),32);
        bufp->chgIData(oldp+397,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu1__DOT__b),32);
        bufp->chgIData(oldp+398,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu1__DOT__result),32);
        bufp->chgBit(oldp+399,((0U == vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu1__DOT__result)));
        bufp->chgBit(oldp+400,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__s1_ex_branch_taken));
        bufp->chgIData(oldp+401,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_wb_val1),32);
        bufp->chgIData(oldp+402,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_br_cmp0__DOT__rs1),32);
        bufp->chgIData(oldp+403,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_br_cmp0__DOT__rs2),32);
        bufp->chgBit(oldp+404,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__s0_id_branch_taken));
        bufp->chgIData(oldp+405,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_jalr_target0),32);
        bufp->chgBit(oldp+406,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__do_flush));
        bufp->chgBit(oldp+407,(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__inter_slot_ctrl));
    }
    bufp->chgBit(oldp+408,(vlSelfRef.tb_program__DOT__clk));
    bufp->chgIData(oldp+409,(vlSelfRef.tb_program__DOT__cycle_count),32);
    bufp->chgIData(oldp+410,(vlSelfRef.tb_program__DOT__instret_count),32);
    bufp->chgIData(oldp+411,(vlSelfRef.tb_program__DOT__uut__DOT__imem_b__DOT__mem
                             [(0x00000fffU & (((IData)(4U) 
                                               + vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__pc_current) 
                                              >> 2U))]),32);
    bufp->chgBit(oldp+412,(((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__do_flush) 
                            | ((~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__stall_if)) 
                               & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__inter_slot_load_raw) 
                                  | (((~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_pred_taken0)) 
                                      & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__inter_slot_ctrl)) 
                                     | (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__s0_s1_mem_dep)))))));
    bufp->chgIData(oldp+413,((((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_branch0) 
                               & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_pred_taken0) 
                                  != (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc0__DOT__branch_taken)))
                               ? ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc0__DOT__branch_taken)
                                   ? (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_imm0 
                                      + vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_pc0)
                                   : ((IData)(4U) + vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_pc0))
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
                                               : ((
                                                   (~ 
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
    bufp->chgBit(oldp+414,(((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc0__DOT__branch_taken) 
                            & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_branch0))));
    bufp->chgBit(oldp+415,(((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_branch0) 
                            & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_pred_taken0) 
                               != (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc0__DOT__branch_taken)))));
    bufp->chgIData(oldp+416,(((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc0__DOT__branch_taken)
                               ? (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_imm0 
                                  + vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_pc0)
                               : ((IData)(4U) + vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_pc0))),32);
    bufp->chgBit(oldp+417,(((~ ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_14) 
                                & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_pred_taken0))) 
                            & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__squash_s1))));
}

void Vtb_program___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_program___024root__trace_cleanup\n"); );
    // Body
    Vtb_program___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_program___024root*>(voidSelf);
    Vtb_program__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[5U] = 0U;
}
