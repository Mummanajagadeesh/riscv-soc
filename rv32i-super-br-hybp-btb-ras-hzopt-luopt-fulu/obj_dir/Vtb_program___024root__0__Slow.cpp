// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_program.h for the primary calling header

#include "Vtb_program__pch.h"

VL_ATTR_COLD void Vtb_program___024root___eval_static(Vtb_program___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_program___024root___eval_static\n"); );
    Vtb_program__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__tb_program__DOT__clk__0 
        = vlSelfRef.tb_program__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_program__DOT__rst__0 
        = vlSelfRef.tb_program__DOT__rst;
}

VL_ATTR_COLD void Vtb_program___024root___eval_initial__TOP(Vtb_program___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_program___024root___eval_initial__TOP\n"); );
    Vtb_program__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_program__DOT__max_cycles = 0x77359400U;
    vlSelfRef.tb_program__DOT__progress_interval = 0U;
    vlSelfRef.tb_program__DOT__progress_enable = 0U;
    (void)VL_VALUEPLUSARGS_INI(32, "max_cycles=%d"s, 
                               vlSelfRef.tb_program__DOT__max_cycles);
    if ((VL_VALUEPLUSARGS_INI(32, "progress_interval=%d"s, 
                              vlSelfRef.tb_program__DOT__progress_interval) 
         && VL_LTS_III(32, 0U, vlSelfRef.tb_program__DOT__progress_interval))) {
        vlSelfRef.tb_program__DOT__progress_enable = 1U;
    }
    VL_READMEM_N(true, 32, 4096, 0, "hex/inst_mem.hex"s
                 ,  &(vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__imem__DOT__mem)
                 , 0, ~0ULL);
    VL_READMEM_N(true, 32, 2048, 0, "hex/data_mem.hex"s
                 ,  &(vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem)
                 , 0, ~0ULL);
    VL_READMEM_N(true, 32, 4096, 0, "hex/inst_mem.hex"s
                 ,  &(vlSelfRef.tb_program__DOT__uut__DOT__imem_b__DOT__mem)
                 , 0, ~0ULL);
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr[0U] = 0U;
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr[1U] = 0U;
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr[2U] = 0U;
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr[3U] = 0U;
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr[4U] = 0U;
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr[5U] = 0U;
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr[6U] = 0U;
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr[7U] = 0U;
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr[8U] = 0U;
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr[9U] = 0U;
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr[0x0aU] = 0U;
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr[0x0bU] = 0U;
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr[0x0cU] = 0U;
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr[0x0dU] = 0U;
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr[0x0eU] = 0U;
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr[0x0fU] = 0U;
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__i = 0x00000010U;
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr[0U] = 0U;
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr[1U] = 0U;
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr[0U] = 0U;
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr[1U] = 0U;
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr[2U] = 0U;
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr[3U] = 0U;
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr[4U] = 0U;
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr[5U] = 0U;
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr[6U] = 0U;
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr[7U] = 0U;
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr[8U] = 0U;
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr[9U] = 0U;
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr[0x0aU] = 0U;
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr[0x0bU] = 0U;
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr[0x0cU] = 0U;
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr[0x0dU] = 0U;
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr[0x0eU] = 0U;
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr[0x0fU] = 0U;
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__i = 0x00000010U;
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr[0U] = 0U;
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr[1U] = 0U;
}

VL_ATTR_COLD void Vtb_program___024root___eval_final(Vtb_program___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_program___024root___eval_final\n"); );
    Vtb_program__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_program___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtb_program___024root___eval_phase__stl(Vtb_program___024root* vlSelf);

VL_ATTR_COLD void Vtb_program___024root___eval_settle(Vtb_program___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_program___024root___eval_settle\n"); );
    Vtb_program__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vtb_program___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("tb/tb_program.v", 3, "", "Settle region did not converge after 100 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
    } while (Vtb_program___024root___eval_phase__stl(vlSelf));
}

VL_ATTR_COLD void Vtb_program___024root___eval_triggers__stl(Vtb_program___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_program___024root___eval_triggers__stl\n"); );
    Vtb_program__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered
                                      [0U]) | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
    vlSelfRef.__VstlFirstIteration = 0U;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_program___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
}

VL_ATTR_COLD bool Vtb_program___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_program___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_program___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vtb_program___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vtb_program___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_program___024root___trigger_anySet__stl\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

extern const VlUnpacked<CData/*4:0*/, 256> Vtb_program__ConstPool__TABLE_hdb5c2fe0_0;

VL_ATTR_COLD void Vtb_program___024root___stl_sequent__TOP__0(Vtb_program___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_program___024root___stl_sequent__TOP__0\n"); );
    Vtb_program__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*7:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*7:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    IData/*31:0*/ __VdfgRegularize_h6e95ff9d_0_1;
    __VdfgRegularize_h6e95ff9d_0_1 = 0;
    IData/*31:0*/ __VdfgRegularize_h6e95ff9d_0_3;
    __VdfgRegularize_h6e95ff9d_0_3 = 0;
    IData/*31:0*/ __VdfgRegularize_h6e95ff9d_0_5;
    __VdfgRegularize_h6e95ff9d_0_5 = 0;
    IData/*31:0*/ __VdfgRegularize_h6e95ff9d_0_6;
    __VdfgRegularize_h6e95ff9d_0_6 = 0;
    IData/*31:0*/ __VdfgRegularize_h6e95ff9d_0_8;
    __VdfgRegularize_h6e95ff9d_0_8 = 0;
    IData/*31:0*/ __VdfgRegularize_h6e95ff9d_0_9;
    __VdfgRegularize_h6e95ff9d_0_9 = 0;
    // Body
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_csr_write0 = 0U;
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_csr_read0 = 0U;
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_halt0 = 0U;
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_reg_write0 = 0U;
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_mem_to_reg0 = 0U;
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_alu_src0 = 0U;
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_alu_op0 = 0U;
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_auipc0 = 0U;
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_is_lui0 = 0U;
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ecall0 = 0U;
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_csr_write1 = 0U;
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_csr_read1 = 0U;
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_halt1 = 0U;
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_mem_write1 = 0U;
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_reg_write1 = 0U;
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_mem_to_reg1 = 0U;
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_alu_src1 = 0U;
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_alu_op1 = 0U;
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_auipc1 = 0U;
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_is_lui1 = 0U;
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_branch1 = 0U;
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_jal1 = 0U;
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_jalr1 = 0U;
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ecall1 = 0U;
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__pipe_halt 
        = ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_halt0) 
           | (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_halt1));
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_15 
        = (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_imm1 
           + vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_pc1);
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_mem_read0 = 0U;
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_mem_write0 = 0U;
    if ((1U & (~ (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                  >> 6U)))) {
        if ((1U & (~ (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                      >> 5U)))) {
            if ((1U & (~ (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                          >> 4U)))) {
                if ((1U & (~ (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                  >> 2U)))) {
                        if ((2U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) {
                            if ((1U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) {
                                vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_mem_to_reg0 = 1U;
                                vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_mem_read0 = 1U;
                            }
                        }
                    }
                }
            }
            if ((0x00000010U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) {
                if ((1U & (~ (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                              >> 3U)))) {
                    if ((4U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) {
                        if ((2U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) {
                            if ((1U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) {
                                vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_auipc0 = 1U;
                            }
                        }
                    }
                }
            }
        }
        if ((0x00000020U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) {
            if ((0x00000010U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) {
                if ((1U & (~ (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                              >> 3U)))) {
                    if ((4U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) {
                        if ((2U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) {
                            if ((1U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) {
                                vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_alu_src0 = 1U;
                                vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_is_lui0 = 1U;
                            }
                        }
                    }
                }
            } else if ((1U & (~ (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                 >> 3U)))) {
                if ((1U & (~ (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                              >> 2U)))) {
                    if ((2U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) {
                        if ((1U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) {
                            vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_alu_src0 = 1U;
                        }
                    }
                }
            }
            if ((1U & (~ (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                          >> 4U)))) {
                if ((1U & (~ (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                  >> 2U)))) {
                        if ((2U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) {
                            if ((1U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) {
                                vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_mem_write0 = 1U;
                            }
                        }
                    }
                }
            }
        } else if ((0x00000010U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) {
            if ((1U & (~ (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                          >> 3U)))) {
                if ((4U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) {
                    if ((2U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) {
                        if ((1U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) {
                            vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_alu_src0 = 1U;
                        }
                    }
                } else if ((2U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) {
                    if ((1U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) {
                        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_alu_src0 = 1U;
                    }
                }
            }
        } else if ((1U & (~ (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                             >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                          >> 2U)))) {
                if ((2U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) {
                    if ((1U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) {
                        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_alu_src0 = 1U;
                    }
                }
            }
        }
    }
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_mem_read1 = 0U;
    if ((1U & (~ (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                  >> 6U)))) {
        if ((0x00000020U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) {
            if ((1U & (~ (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                          >> 4U)))) {
                if ((1U & (~ (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                  >> 2U)))) {
                        if ((2U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) {
                            if ((1U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) {
                                vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_mem_write1 = 1U;
                            }
                        }
                    }
                }
            }
            if ((0x00000010U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) {
                if ((1U & (~ (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                              >> 3U)))) {
                    if ((4U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) {
                        if ((2U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) {
                            if ((1U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) {
                                vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_alu_src1 = 1U;
                                vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_is_lui1 = 1U;
                            }
                        }
                    }
                }
            } else if ((1U & (~ (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                 >> 3U)))) {
                if ((1U & (~ (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                              >> 2U)))) {
                    if ((2U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) {
                        if ((1U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) {
                            vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_alu_src1 = 1U;
                        }
                    }
                }
            }
        } else if ((0x00000010U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) {
            if ((1U & (~ (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                          >> 3U)))) {
                if ((4U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) {
                    if ((2U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) {
                        if ((1U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) {
                            vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_alu_src1 = 1U;
                        }
                    }
                } else if ((2U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) {
                    if ((1U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) {
                        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_alu_src1 = 1U;
                    }
                }
            }
        } else if ((1U & (~ (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                             >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                          >> 2U)))) {
                if ((2U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) {
                    if ((1U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) {
                        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_alu_src1 = 1U;
                    }
                }
            }
        }
        if ((1U & (~ (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                      >> 5U)))) {
            if ((1U & (~ (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                          >> 4U)))) {
                if ((1U & (~ (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                  >> 2U)))) {
                        if ((2U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) {
                            if ((1U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) {
                                vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_mem_to_reg1 = 1U;
                                vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_mem_read1 = 1U;
                            }
                        }
                    }
                }
            }
            if ((0x00000010U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) {
                if ((1U & (~ (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                              >> 3U)))) {
                    if ((4U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) {
                        if ((2U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) {
                            if ((1U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) {
                                vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_auipc1 = 1U;
                            }
                        }
                    }
                }
            }
        }
    }
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_imm_type1 = 0U;
    if ((0x00000040U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) {
        if ((0x00000020U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) {
            if ((0x00000010U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) {
                if ((1U & (~ (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                  >> 2U)))) {
                        if ((2U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) {
                            if ((1U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) {
                                if ((0U != (7U & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                                  >> 0x0000000cU)))) {
                                    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_csr_write1 = 1U;
                                    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_csr_read1 = 1U;
                                    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_reg_write1 = 1U;
                                }
                                if ((0U == (7U & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                                  >> 0x0000000cU)))) {
                                    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_halt1 = 1U;
                                    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ecall1 = 1U;
                                }
                            }
                        }
                    }
                }
            } else if ((8U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) {
                if ((4U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) {
                    if ((2U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) {
                        if ((1U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) {
                            vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_reg_write1 = 1U;
                        }
                    }
                }
            } else if ((4U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) {
                if ((2U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) {
                    if ((1U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) {
                        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_reg_write1 = 1U;
                    }
                }
            }
            if ((1U & (~ (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                          >> 4U)))) {
                if ((8U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) {
                    if ((4U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) {
                        if ((2U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) {
                            if ((1U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) {
                                vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_alu_op1 = 0U;
                                vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_jal1 = 1U;
                                vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_imm_type1 = 4U;
                            }
                        }
                    }
                } else if ((4U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) {
                    if ((2U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) {
                        if ((1U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) {
                            vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_alu_op1 = 0U;
                            vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_imm_type1 = 0U;
                        }
                    }
                } else if ((2U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) {
                    if ((1U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) {
                        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_alu_op1 = 1U;
                        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_imm_type1 = 2U;
                    }
                }
                if ((1U & (~ (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                  >> 2U)))) {
                        if ((2U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) {
                            if ((1U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) {
                                vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_branch1 = 1U;
                            }
                        }
                    }
                    if ((4U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) {
                        if ((2U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) {
                            if ((1U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) {
                                vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_jalr1 = 1U;
                            }
                        }
                    }
                }
            }
        }
    } else if ((0x00000020U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) {
        if ((0x00000010U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) {
            if ((1U & (~ (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                          >> 3U)))) {
                if ((4U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) {
                    if ((2U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) {
                        if ((1U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) {
                            vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_reg_write1 = 1U;
                            vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_alu_op1 = 3U;
                            vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_imm_type1 = 3U;
                        }
                    }
                } else if ((2U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) {
                    if ((1U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) {
                        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_reg_write1 = 1U;
                        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_alu_op1 = 2U;
                    }
                }
            }
        } else if ((1U & (~ (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                             >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                          >> 2U)))) {
                if ((2U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) {
                    if ((1U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) {
                        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_alu_op1 = 0U;
                        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_imm_type1 = 1U;
                    }
                }
            }
        }
    } else if ((0x00000010U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) {
        if ((1U & (~ (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                      >> 3U)))) {
            if ((4U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) {
                if ((2U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) {
                    if ((1U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) {
                        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_reg_write1 = 1U;
                        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_alu_op1 = 3U;
                        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_imm_type1 = 3U;
                    }
                }
            } else if ((2U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) {
                if ((1U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) {
                    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_reg_write1 = 1U;
                    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_alu_op1 = 2U;
                    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_imm_type1 = 0U;
                }
            }
        }
    } else if ((1U & (~ (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                         >> 3U)))) {
        if ((1U & (~ (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                      >> 2U)))) {
            if ((2U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) {
                if ((1U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) {
                    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_reg_write1 = 1U;
                    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_alu_op1 = 0U;
                    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_imm_type1 = 0U;
                }
            }
        }
    }
    __VdfgRegularize_h6e95ff9d_0_3 = (((- (IData)((vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                                   >> 0x0000001fU))) 
                                       << 0x0000000cU) 
                                      | (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                         >> 0x00000014U));
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_btb_hit0 
        = (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__btb_valid
           [(0x000000ffU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__pc_current 
                            >> 2U))] & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__btb_tag
                                        [(0x000000ffU 
                                          & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__pc_current 
                                             >> 2U))] 
                                        == vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__pc_current));
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_pred_pc_idx 
        = (0x000000ffU & ((vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__pc_current 
                           >> 2U) ^ (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__pc_current 
                                     >> 8U)));
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__instr0 
        = vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__imem__DOT__mem
        [(0x00000fffU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__pc_current 
                         >> 2U))];
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_jal0 = 0U;
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_imm_type0 = 0U;
    __VdfgRegularize_h6e95ff9d_0_1 = (((- (IData)((vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                                   >> 0x0000001fU))) 
                                       << 0x0000000cU) 
                                      | (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                         >> 0x00000014U));
    vlSelfRef.__VdfgRegularize_he50b618e_0_4 = ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rd0) 
                                                == 
                                                (0x0000001fU 
                                                 & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                                    >> 0x00000014U)));
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_jalr0 = 0U;
    vlSelfRef.__VdfgRegularize_he50b618e_0_3 = ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rd0) 
                                                == 
                                                (0x0000001fU 
                                                 & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                                    >> 0x0000000fU)));
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_branch0 = 0U;
    if ((0x00000040U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) {
        if ((0x00000020U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) {
            if ((0x00000010U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) {
                if ((1U & (~ (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                  >> 2U)))) {
                        if ((2U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) {
                            if ((1U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) {
                                if ((0U != (7U & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                                  >> 0x0000000cU)))) {
                                    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_csr_write0 = 1U;
                                    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_csr_read0 = 1U;
                                    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_reg_write0 = 1U;
                                }
                                if ((0U == (7U & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                                  >> 0x0000000cU)))) {
                                    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_halt0 = 1U;
                                    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ecall0 = 1U;
                                }
                            }
                        }
                    }
                }
            } else if ((8U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) {
                if ((4U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) {
                    if ((2U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) {
                        if ((1U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) {
                            vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_reg_write0 = 1U;
                        }
                    }
                }
            } else if ((4U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) {
                if ((2U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) {
                    if ((1U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) {
                        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_reg_write0 = 1U;
                    }
                }
            }
            if ((1U & (~ (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                          >> 4U)))) {
                if ((8U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) {
                    if ((4U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) {
                        if ((2U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) {
                            if ((1U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) {
                                vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_alu_op0 = 0U;
                                vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_jal0 = 1U;
                                vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_imm_type0 = 4U;
                            }
                        }
                    }
                } else if ((4U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) {
                    if ((2U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) {
                        if ((1U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) {
                            vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_alu_op0 = 0U;
                            vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_imm_type0 = 0U;
                        }
                    }
                } else if ((2U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) {
                    if ((1U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) {
                        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_alu_op0 = 1U;
                        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_imm_type0 = 2U;
                    }
                }
                if ((1U & (~ (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                              >> 3U)))) {
                    if ((4U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) {
                        if ((2U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) {
                            if ((1U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) {
                                vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_jalr0 = 1U;
                            }
                        }
                    }
                    if ((1U & (~ (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                  >> 2U)))) {
                        if ((2U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) {
                            if ((1U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) {
                                vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_branch0 = 1U;
                            }
                        }
                    }
                }
            }
        }
    } else if ((0x00000020U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) {
        if ((0x00000010U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) {
            if ((1U & (~ (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                          >> 3U)))) {
                if ((4U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) {
                    if ((2U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) {
                        if ((1U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) {
                            vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_reg_write0 = 1U;
                            vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_alu_op0 = 3U;
                            vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_imm_type0 = 3U;
                        }
                    }
                } else if ((2U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) {
                    if ((1U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) {
                        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_reg_write0 = 1U;
                        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_alu_op0 = 2U;
                    }
                }
            }
        } else if ((1U & (~ (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                             >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                          >> 2U)))) {
                if ((2U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) {
                    if ((1U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) {
                        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_alu_op0 = 0U;
                        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_imm_type0 = 1U;
                    }
                }
            }
        }
    } else if ((0x00000010U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) {
        if ((1U & (~ (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                      >> 3U)))) {
            if ((4U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) {
                if ((2U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) {
                    if ((1U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) {
                        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_reg_write0 = 1U;
                        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_alu_op0 = 3U;
                        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_imm_type0 = 3U;
                    }
                }
            } else if ((2U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) {
                if ((1U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) {
                    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_reg_write0 = 1U;
                    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_alu_op0 = 2U;
                    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_imm_type0 = 0U;
                }
            }
        }
    } else if ((1U & (~ (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                         >> 3U)))) {
        if ((1U & (~ (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                      >> 2U)))) {
            if ((2U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) {
                if ((1U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) {
                    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_reg_write0 = 1U;
                    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_alu_op0 = 0U;
                    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_imm_type0 = 0U;
                }
            }
        }
    }
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_7 
        = ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_reg_write1) 
           & (0U != (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rd1)));
    __Vtableidx2 = (((((((2U == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_alu_op1)) 
                         & (5U == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_funct3_1))) 
                        | (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_is_rtype1)) 
                       & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_funct7_1) 
                          >> 5U)) << 7U) | ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_funct3_1) 
                                            << 4U)) 
                    | ((((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_is_rtype1) 
                         & (1U == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_funct7_1))) 
                        << 3U) | (((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_is_lui1) 
                                   << 2U) | (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_alu_op1))));
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_alu_ctrl1 
        = Vtb_program__ConstPool__TABLE_hdb5c2fe0_0
        [__Vtableidx2];
    vlSelfRef.__VdfgRegularize_he50b618e_0_2 = ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_jal1) 
                                                | (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_jalr1));
    __Vtableidx1 = (((((((2U == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_alu_op0)) 
                         & (5U == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_funct3_0))) 
                        | (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_is_rtype0)) 
                       & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_funct7_0) 
                          >> 5U)) << 7U) | ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_funct3_0) 
                                            << 4U)) 
                    | ((((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_is_rtype0) 
                         & (1U == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_funct7_0))) 
                        << 3U) | (((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_is_lui0) 
                                   << 2U) | (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_alu_op0))));
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_alu_ctrl0 
        = Vtb_program__ConstPool__TABLE_hdb5c2fe0_0
        [__Vtableidx1];
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_8 
        = ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_reg_write0) 
           & (0U != (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rd0)));
    vlSelfRef.tb_program__DOT__uut__DOT__mem_rdata0 
        = ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_mem_read0)
            ? ((4U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_funct3_0))
                ? ((2U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_funct3_0))
                    ? vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                   [(0x000007ffU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu0 
                                    >> 2U))] : ((1U 
                                                 & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_funct3_0))
                                                 ? 
                                                ((2U 
                                                  & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu0)
                                                  ? 
                                                 (vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                                                  [
                                                  (0x000007ffU 
                                                   & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu0 
                                                      >> 2U))] 
                                                  >> 0x10U)
                                                  : 
                                                 (0x0000ffffU 
                                                  & vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                                                  [
                                                  (0x000007ffU 
                                                   & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu0 
                                                      >> 2U))]))
                                                 : 
                                                ((2U 
                                                  & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu0)
                                                  ? 
                                                 ((1U 
                                                   & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu0)
                                                   ? 
                                                  (vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                                                   [
                                                   (0x000007ffU 
                                                    & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu0 
                                                       >> 2U))] 
                                                   >> 0x18U)
                                                   : 
                                                  (0x000000ffU 
                                                   & (vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                                                      [
                                                      (0x000007ffU 
                                                       & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu0 
                                                          >> 2U))] 
                                                      >> 0x10U)))
                                                  : 
                                                 ((1U 
                                                   & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu0)
                                                   ? 
                                                  (0x000000ffU 
                                                   & (vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                                                      [
                                                      (0x000007ffU 
                                                       & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu0 
                                                          >> 2U))] 
                                                      >> 8U))
                                                   : 
                                                  (0x000000ffU 
                                                   & vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                                                   [
                                                   (0x000007ffU 
                                                    & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu0 
                                                       >> 2U))])))))
                : ((2U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_funct3_0))
                    ? ((1U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_funct3_0))
                        ? vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                       [(0x000007ffU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu0 
                                        >> 2U))] : 
                       vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                       [(0x000007ffU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu0 
                                        >> 2U))]) : 
                   ((1U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_funct3_0))
                     ? ((2U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu0)
                         ? (((- (IData)((vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                                         [(0x000007ffU 
                                           & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu0 
                                              >> 2U))] 
                                         >> 0x1fU))) 
                             << 0x00000010U) | (vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                                                [(0x000007ffU 
                                                  & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu0 
                                                     >> 2U))] 
                                                >> 0x10U))
                         : (((- (IData)((1U & (vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                                               [(0x000007ffU 
                                                 & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu0 
                                                    >> 2U))] 
                                               >> 0x0fU)))) 
                             << 0x00000010U) | (0x0000ffffU 
                                                & vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                                                [(0x000007ffU 
                                                  & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu0 
                                                     >> 2U))])))
                     : ((2U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu0)
                         ? ((1U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu0)
                             ? (((- (IData)((vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                                             [(0x000007ffU 
                                               & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu0 
                                                  >> 2U))] 
                                             >> 0x1fU))) 
                                 << 8U) | (vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                                           [(0x000007ffU 
                                             & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu0 
                                                >> 2U))] 
                                           >> 0x18U))
                             : (((- (IData)((1U & (
                                                   vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                                                   [
                                                   (0x000007ffU 
                                                    & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu0 
                                                       >> 2U))] 
                                                   >> 0x17U)))) 
                                 << 8U) | (0x000000ffU 
                                           & (vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                                              [(0x000007ffU 
                                                & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu0 
                                                   >> 2U))] 
                                              >> 0x10U))))
                         : ((1U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu0)
                             ? (((- (IData)((1U & (
                                                   vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                                                   [
                                                   (0x000007ffU 
                                                    & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu0 
                                                       >> 2U))] 
                                                   >> 0x0fU)))) 
                                 << 8U) | (0x000000ffU 
                                           & (vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                                              [(0x000007ffU 
                                                & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu0 
                                                   >> 2U))] 
                                              >> 8U)))
                             : (((- (IData)((1U & (
                                                   vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                                                   [
                                                   (0x000007ffU 
                                                    & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu0 
                                                       >> 2U))] 
                                                   >> 7U)))) 
                                 << 8U) | (0x000000ffU 
                                           & vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                                           [(0x000007ffU 
                                             & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu0 
                                                >> 2U))])))))))
            : 0U);
    vlSelfRef.tb_program__DOT__uut__DOT__mem_rdata1 
        = ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_mem_read1)
            ? ((4U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_funct3_1))
                ? ((2U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_funct3_1))
                    ? vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                   [(0x000007ffU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu1 
                                    >> 2U))] : ((1U 
                                                 & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_funct3_1))
                                                 ? 
                                                ((2U 
                                                  & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu1)
                                                  ? 
                                                 (vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                                                  [
                                                  (0x000007ffU 
                                                   & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu1 
                                                      >> 2U))] 
                                                  >> 0x10U)
                                                  : 
                                                 (0x0000ffffU 
                                                  & vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                                                  [
                                                  (0x000007ffU 
                                                   & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu1 
                                                      >> 2U))]))
                                                 : 
                                                ((2U 
                                                  & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu1)
                                                  ? 
                                                 ((1U 
                                                   & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu1)
                                                   ? 
                                                  (vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                                                   [
                                                   (0x000007ffU 
                                                    & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu1 
                                                       >> 2U))] 
                                                   >> 0x18U)
                                                   : 
                                                  (0x000000ffU 
                                                   & (vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                                                      [
                                                      (0x000007ffU 
                                                       & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu1 
                                                          >> 2U))] 
                                                      >> 0x10U)))
                                                  : 
                                                 ((1U 
                                                   & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu1)
                                                   ? 
                                                  (0x000000ffU 
                                                   & (vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                                                      [
                                                      (0x000007ffU 
                                                       & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu1 
                                                          >> 2U))] 
                                                      >> 8U))
                                                   : 
                                                  (0x000000ffU 
                                                   & vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                                                   [
                                                   (0x000007ffU 
                                                    & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu1 
                                                       >> 2U))])))))
                : ((2U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_funct3_1))
                    ? ((1U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_funct3_1))
                        ? vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                       [(0x000007ffU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu1 
                                        >> 2U))] : 
                       vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                       [(0x000007ffU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu1 
                                        >> 2U))]) : 
                   ((1U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_funct3_1))
                     ? ((2U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu1)
                         ? (((- (IData)((vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                                         [(0x000007ffU 
                                           & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu1 
                                              >> 2U))] 
                                         >> 0x1fU))) 
                             << 0x00000010U) | (vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                                                [(0x000007ffU 
                                                  & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu1 
                                                     >> 2U))] 
                                                >> 0x10U))
                         : (((- (IData)((1U & (vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                                               [(0x000007ffU 
                                                 & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu1 
                                                    >> 2U))] 
                                               >> 0x0fU)))) 
                             << 0x00000010U) | (0x0000ffffU 
                                                & vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                                                [(0x000007ffU 
                                                  & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu1 
                                                     >> 2U))])))
                     : ((2U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu1)
                         ? ((1U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu1)
                             ? (((- (IData)((vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                                             [(0x000007ffU 
                                               & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu1 
                                                  >> 2U))] 
                                             >> 0x1fU))) 
                                 << 8U) | (vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                                           [(0x000007ffU 
                                             & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu1 
                                                >> 2U))] 
                                           >> 0x18U))
                             : (((- (IData)((1U & (
                                                   vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                                                   [
                                                   (0x000007ffU 
                                                    & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu1 
                                                       >> 2U))] 
                                                   >> 0x17U)))) 
                                 << 8U) | (0x000000ffU 
                                           & (vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                                              [(0x000007ffU 
                                                & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu1 
                                                   >> 2U))] 
                                              >> 0x10U))))
                         : ((1U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu1)
                             ? (((- (IData)((1U & (
                                                   vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                                                   [
                                                   (0x000007ffU 
                                                    & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu1 
                                                       >> 2U))] 
                                                   >> 0x0fU)))) 
                                 << 8U) | (0x000000ffU 
                                           & (vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                                              [(0x000007ffU 
                                                & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu1 
                                                   >> 2U))] 
                                              >> 8U)))
                             : (((- (IData)((1U & (
                                                   vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                                                   [
                                                   (0x000007ffU 
                                                    & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu1 
                                                       >> 2U))] 
                                                   >> 7U)))) 
                                 << 8U) | (0x000000ffU 
                                           & vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                                           [(0x000007ffU 
                                             & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu1 
                                                >> 2U))])))))))
            : 0U);
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__wd0 
        = ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_mem_to_reg0)
            ? vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_mem0
            : vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_wb0);
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__wd1 
        = ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_mem_to_reg1)
            ? vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_mem1
            : vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_wb1);
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_9 
        = ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_reg_write1) 
           & (0U != (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_rd1)));
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_10 
        = ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_reg_write0) 
           & (0U != (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_rd0)));
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_5 
        = ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_reg_write0) 
           & (0U != (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_rd0)));
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_4 
        = ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_reg_write1) 
           & (0U != (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_rd1)));
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__inter_slot_load_raw 
        = ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_mem_read0) 
           & ((0U != (0x0000001fU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                     >> 7U))) & (((
                                                   (3U 
                                                    == 
                                                    (0x0000007fU 
                                                     & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) 
                                                   | ((0x23U 
                                                       == 
                                                       (0x0000007fU 
                                                        & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) 
                                                      | ((0x63U 
                                                          == 
                                                          (0x0000007fU 
                                                           & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) 
                                                         | ((0x67U 
                                                             == 
                                                             (0x0000007fU 
                                                              & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) 
                                                            | ((0x13U 
                                                                == 
                                                                (0x0000007fU 
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
                                                                         & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1))))))))) 
                                                  & ((0x0000001fU 
                                                      & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                                         >> 7U)) 
                                                     == 
                                                     (0x0000001fU 
                                                      & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                                         >> 0x0000000fU)))) 
                                                 | (((0x23U 
                                                      == 
                                                      (0x0000007fU 
                                                       & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) 
                                                     | ((0x63U 
                                                         == 
                                                         (0x0000007fU 
                                                          & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)) 
                                                        | (0x33U 
                                                           == 
                                                           (0x0000007fU 
                                                            & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)))) 
                                                    & ((0x0000001fU 
                                                        & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                                           >> 7U)) 
                                                       == 
                                                       (0x0000001fU 
                                                        & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                                           >> 0x00000014U)))))));
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ig1__DOT__imm 
        = ((4U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_imm_type1))
            ? ((2U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_imm_type1))
                ? 0U : ((1U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_imm_type1))
                         ? __VdfgRegularize_h6e95ff9d_0_3
                         : ((((0x00000ffeU & ((- (IData)(
                                                         (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                                          >> 0x0000001fU))) 
                                              << 1U)) 
                              | (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                 >> 0x0000001fU)) << 0x00000014U) 
                            | ((((0x000001feU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                                 >> 0x0000000bU)) 
                                 | (1U & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                          >> 0x00000014U))) 
                                << 0x0000000bU) | (0x000007feU 
                                                   & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                                      >> 0x00000014U))))))
            : ((2U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_imm_type1))
                ? ((1U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_imm_type1))
                    ? (0xfffff000U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)
                    : (((- (IData)((vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                    >> 0x0000001fU))) 
                        << 0x0000000dU) | ((((2U & 
                                              (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                               >> 0x0000001eU)) 
                                             | (1U 
                                                & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                                   >> 7U))) 
                                            << 0x0000000bU) 
                                           | ((0x000007e0U 
                                               & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                                  >> 0x00000014U)) 
                                              | (0x0000001eU 
                                                 & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                                    >> 7U))))))
                : ((1U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_imm_type1))
                    ? (((- (IData)((vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                    >> 0x0000001fU))) 
                        << 0x0000000cU) | ((0x00000fe0U 
                                            & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                               >> 0x00000014U)) 
                                           | (0x0000001fU 
                                              & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                                 >> 7U))))
                    : __VdfgRegularize_h6e95ff9d_0_3)));
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_local_pred_taken0 
        = (1U & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hybp_local_pht
                 [vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_pred_pc_idx] 
                 >> 1U));
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_global_idx0 
        = ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_pred_pc_idx) 
           ^ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hybp_ghr));
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_is_ret0 
        = (IData)(((0x00000067U == (0x00000fffU & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__instr0)) 
                   & (((1U == (0x0000001fU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__instr0 
                                              >> 0x0000000fU))) 
                       | (5U == (0x0000001fU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__instr0 
                                                >> 0x0000000fU)))) 
                      & (0U == (((- (IData)((vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__instr0 
                                             >> 0x0000001fU))) 
                                 << 0x0000000cU) | 
                                (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__instr0 
                                 >> 0x00000014U))))));
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ig0__DOT__imm 
        = ((4U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_imm_type0))
            ? ((2U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_imm_type0))
                ? 0U : ((1U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_imm_type0))
                         ? __VdfgRegularize_h6e95ff9d_0_1
                         : ((((0x00000ffeU & ((- (IData)(
                                                         (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                                          >> 0x0000001fU))) 
                                              << 1U)) 
                              | (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                 >> 0x0000001fU)) << 0x00000014U) 
                            | ((((0x000001feU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                                 >> 0x0000000bU)) 
                                 | (1U & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                          >> 0x00000014U))) 
                                << 0x0000000bU) | (0x000007feU 
                                                   & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                                      >> 0x00000014U))))))
            : ((2U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_imm_type0))
                ? ((1U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_imm_type0))
                    ? (0xfffff000U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)
                    : (((- (IData)((vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                    >> 0x0000001fU))) 
                        << 0x0000000dU) | ((((2U & 
                                              (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                               >> 0x0000001eU)) 
                                             | (1U 
                                                & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                                   >> 7U))) 
                                            << 0x0000000bU) 
                                           | ((0x000007e0U 
                                               & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                                  >> 0x00000014U)) 
                                              | (0x0000001eU 
                                                 & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                                    >> 7U))))))
                : ((1U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_imm_type0))
                    ? (((- (IData)((vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                    >> 0x0000001fU))) 
                        << 0x0000000cU) | ((0x00000fe0U 
                                            & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                               >> 0x00000014U)) 
                                           | (0x0000001fU 
                                              & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                                 >> 7U))))
                    : __VdfgRegularize_h6e95ff9d_0_1)));
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_13 
        = ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_jal0) 
           | (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_jalr0));
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT____VdfgRegularize_h6b6f5558_0_1 
        = ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_branch0) 
           & ((0x23U == (0x0000007fU & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) 
              | ((0x63U == (0x0000007fU & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) 
                 | (0x33U == (0x0000007fU & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)))));
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT____VdfgRegularize_h6b6f5558_0_0 
        = (((3U == (0x0000007fU & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) 
            | ((0x23U == (0x0000007fU & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) 
               | ((0x63U == (0x0000007fU & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) 
                  | ((0x67U == (0x0000007fU & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) 
                     | ((0x13U == (0x0000007fU & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) 
                        | ((0x33U == (0x0000007fU & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)) 
                           | ((~ ((vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                   >> 0x0000000eU) 
                                  | (0U == (7U & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                                  >> 0x0000000cU))))) 
                              & (0x73U == (0x0000007fU 
                                           & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0))))))))) 
           & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_branch0) 
              | (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_jalr0)));
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_fwd_val0 
        = ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_mem_to_reg0)
            ? vlSelfRef.tb_program__DOT__uut__DOT__mem_rdata0
            : vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_wb0);
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_fwd_val1 
        = ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_mem_to_reg1)
            ? vlSelfRef.tb_program__DOT__uut__DOT__mem_rdata1
            : vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_wb1);
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_rd2_0 
        = (((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_4) 
            & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_rd1) 
               == (0x0000001fU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                  >> 0x00000014U))))
            ? vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__wd1
            : (((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_5) 
                & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_rd0) 
                   == (0x0000001fU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                      >> 0x00000014U))))
                ? vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__wd0
                : ((0U == (0x0000001fU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                          >> 0x00000014U)))
                    ? 0U : vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                   [(0x0000001fU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                    >> 0x00000014U))])));
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_rd1_0 
        = (((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_4) 
            & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_rd1) 
               == (0x0000001fU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                  >> 0x0000000fU))))
            ? vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__wd1
            : (((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_5) 
                & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_rd0) 
                   == (0x0000001fU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                      >> 0x0000000fU))))
                ? vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__wd0
                : ((0U == (0x0000001fU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                          >> 0x0000000fU)))
                    ? 0U : vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                   [(0x0000001fU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                    >> 0x0000000fU))])));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_13 = ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_4) 
                                                 & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rs2_1) 
                                                    == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_rd1)));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_12 = ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_4) 
                                                 & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rs1_1) 
                                                    == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_rd1)));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_11 = ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_4) 
                                                 & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rs2_0) 
                                                    == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_rd1)));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_10 = ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_4) 
                                                 & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rs1_0) 
                                                    == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_rd1)));
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_global_pred_taken0 
        = (1U & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hybp_global_pht
                 [vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_global_idx0] 
                 >> 1U));
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_pred_target0 
        = ((0x63U == (0x0000007fU & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__instr0))
            ? ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_btb_hit0)
                ? vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__btb_target
               [(0x000000ffU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__pc_current 
                                >> 2U))] : (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__pc_current 
                                            + (((- (IData)(
                                                           (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__instr0 
                                                            >> 0x0000001fU))) 
                                                << 0x0000000dU) 
                                               | ((((2U 
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
                                                           >> 7U)))))))
            : ((0x6fU == (0x0000007fU & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__instr0))
                ? (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__pc_current 
                   + ((((0x00000ffeU & ((- (IData)(
                                                   (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__instr0 
                                                    >> 0x0000001fU))) 
                                        << 1U)) | (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__instr0 
                                                   >> 0x0000001fU)) 
                       << 0x00000014U) | ((((0x000001feU 
                                             & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__instr0 
                                                >> 0x0000000bU)) 
                                            | (1U & 
                                               (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__instr0 
                                                >> 0x00000014U))) 
                                           << 0x0000000bU) 
                                          | (0x000007feU 
                                             & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__instr0 
                                                >> 0x00000014U)))))
                : ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_is_ret0)
                    ? ((0U != (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_count))
                        ? vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_stack
                       [vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_top_ptr]
                        : 0U) : vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__btb_target
                   [(0x000000ffU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__pc_current 
                                    >> 2U))])));
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_is_ret0 
        = ((((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_jalr0) 
             & (0U == (0x00000f80U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0))) 
            & (0U == vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ig0__DOT__imm)) 
           & ((1U == (0x0000001fU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                     >> 0x0000000fU))) 
              | (5U == (0x0000001fU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                       >> 0x0000000fU)))));
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__s0_s1_mem_dep 
        = ((((((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_mem_write0) 
               & (0x00002000U == (0x00007000U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0))) 
              & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_mem_read1)) 
             & (0x00002000U == (0x00007000U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1))) 
            & ((3U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ig0__DOT__imm) 
               == (3U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ig1__DOT__imm))) 
           | (((((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_mem_write0) 
                 & (0x00001000U == (0x00007000U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0))) 
                & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_mem_read1)) 
               & (((1U == (7U & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                 >> 0x0000000cU))) 
                   | (5U == (7U & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                   >> 0x0000000cU)))) 
                  & ((1U & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ig0__DOT__imm 
                            >> 1U)) == (1U & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ig1__DOT__imm 
                                              >> 1U))))) 
              | ((((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_mem_write0) 
                   & (0U == (0x00007000U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0))) 
                  & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_mem_read1)) 
                 & ((0U == (7U & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                  >> 0x0000000cU))) 
                    | (4U == (7U & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                    >> 0x0000000cU)))))));
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_jal_target0 
        = (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ig0__DOT__imm 
           + vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_pc0);
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_14 
        = ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_valid0) 
           & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_branch0) 
              | (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_13)));
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__load_use_stall 
        = (((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_mem_read0) 
            & ((0U != (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rd0)) 
               & (((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT____VdfgRegularize_h6b6f5558_0_0) 
                   & (IData)(vlSelfRef.__VdfgRegularize_he50b618e_0_3)) 
                  | ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT____VdfgRegularize_h6b6f5558_0_1) 
                     & (IData)(vlSelfRef.__VdfgRegularize_he50b618e_0_4))))) 
           | ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_mem_read1) 
              & ((0U != (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rd1)) 
                 & (((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT____VdfgRegularize_h6b6f5558_0_0) 
                     & ((0x0000001fU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                        >> 0x0000000fU)) 
                        == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rd1))) 
                    | ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT____VdfgRegularize_h6b6f5558_0_1) 
                       & ((0x0000001fU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                          >> 0x00000014U)) 
                          == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rd1)))))));
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__fwd_unit__DOT__fwd_b1 
        = (((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_8) 
            & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rd0) 
               == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rs2_1)))
            ? 4U : (((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_9) 
                     & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_rd1) 
                        == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rs2_1)))
                     ? 3U : (((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_10) 
                              & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_rd0) 
                                 == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rs2_1)))
                              ? 2U : ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_13)
                                       ? 1U : (((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_5) 
                                                & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rs2_1) 
                                                   == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_rd0)))
                                                ? 1U
                                                : 0U)))));
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__fwd_unit__DOT__fwd_a1 
        = (((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_8) 
            & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rd0) 
               == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rs1_1)))
            ? 4U : (((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_9) 
                     & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_rd1) 
                        == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rs1_1)))
                     ? 3U : (((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_10) 
                              & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_rd0) 
                                 == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rs1_1)))
                              ? 2U : ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_12)
                                       ? 1U : (((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_5) 
                                                & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rs1_1) 
                                                   == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_rd0)))
                                                ? 1U
                                                : 0U)))));
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__fwd_unit__DOT__fwd_b0 
        = (((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_9) 
            & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_rd1) 
               == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rs2_0)))
            ? 3U : (((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_10) 
                     & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_rd0) 
                        == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rs2_0)))
                     ? 2U : ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_11)
                              ? 1U : (((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_5) 
                                       & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rs2_0) 
                                          == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_rd0)))
                                       ? 1U : 0U))));
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__fwd_unit__DOT__fwd_a0 
        = (((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_9) 
            & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_rd1) 
               == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rs1_0)))
            ? 3U : (((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_10) 
                     & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_rd0) 
                        == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rs1_0)))
                     ? 2U : ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_10)
                              ? 1U : (((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_5) 
                                       & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rs1_0) 
                                          == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_rd0)))
                                       ? 1U : 0U))));
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_pred_taken0 
        = (((0x63U == (0x0000007fU & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__instr0)) 
            & ((2U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hybp_choice_pht
                [vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_global_idx0])
                ? (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_global_pred_taken0)
                : (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_local_pred_taken0))) 
           | ((0x6fU == (0x0000007fU & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__instr0)) 
              | ((0x67U == (0x0000007fU & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__instr0)) 
                 & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_is_ret0)
                     ? (0U != (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_count))
                     : (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_btb_hit0)))));
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc0__DOT__rs2 
        = ((2U == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__fwd_unit__DOT__fwd_b0))
            ? vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_fwd_val0
            : ((3U == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__fwd_unit__DOT__fwd_b0))
                ? vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_fwd_val1
                : ((1U == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__fwd_unit__DOT__fwd_b0))
                    ? ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_11)
                        ? vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__wd1
                        : vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__wd0)
                    : vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rd2_0)));
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc0__DOT__rs1 
        = ((2U == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__fwd_unit__DOT__fwd_a0))
            ? vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_fwd_val0
            : ((3U == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__fwd_unit__DOT__fwd_a0))
                ? vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_fwd_val1
                : ((1U == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__fwd_unit__DOT__fwd_a0))
                    ? ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_10)
                        ? vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__wd1
                        : vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__wd0)
                    : vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rd1_0)));
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu0__DOT__b 
        = ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_alu_src0)
            ? vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_imm0
            : vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc0__DOT__rs2);
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc0__DOT__branch_taken 
        = ((4U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_funct3_0))
            ? ((2U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_funct3_0))
                ? ((1U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_funct3_0))
                    ? (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc0__DOT__rs1 
                       >= vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc0__DOT__rs2)
                    : (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc0__DOT__rs1 
                       < vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc0__DOT__rs2))
                : ((1U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_funct3_0))
                    ? VL_GTES_III(32, vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc0__DOT__rs1, vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc0__DOT__rs2)
                    : VL_LTS_III(32, vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc0__DOT__rs1, vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc0__DOT__rs2)))
            : ((~ ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_funct3_0) 
                   >> 1U)) & ((1U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_funct3_0))
                               ? (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc0__DOT__rs1 
                                  != vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc0__DOT__rs2)
                               : (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc0__DOT__rs1 
                                  == vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc0__DOT__rs2))));
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu0__DOT__a 
        = ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_auipc0)
            ? vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_pc0
            : ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_is_lui0)
                ? 0U : vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc0__DOT__rs1));
    __VdfgRegularize_h6e95ff9d_0_5 = VL_DIV_III(32, vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu0__DOT__a, vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu0__DOT__b);
    __VdfgRegularize_h6e95ff9d_0_6 = (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu0__DOT__a 
                                      + vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu0__DOT__b);
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu0__DOT__result 
        = ((0x00000010U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_alu_ctrl0))
            ? ((8U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_alu_ctrl0))
                ? 0U : ((4U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_alu_ctrl0))
                         ? 0U : ((2U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_alu_ctrl0))
                                  ? ((1U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_alu_ctrl0))
                                      ? ((0U != vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu0__DOT__b)
                                          ? VL_MODDIV_III(32, vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu0__DOT__a, vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu0__DOT__b)
                                          : vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu0__DOT__a)
                                      : ((0U != vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu0__DOT__b)
                                          ? VL_MODDIVS_III(32, vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu0__DOT__a, vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu0__DOT__b)
                                          : vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu0__DOT__a))
                                  : ((1U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_alu_ctrl0))
                                      ? ((0U != vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu0__DOT__b)
                                          ? __VdfgRegularize_h6e95ff9d_0_5
                                          : 1U) : (
                                                   (0U 
                                                    != vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu0__DOT__b)
                                                    ? __VdfgRegularize_h6e95ff9d_0_5
                                                    : 0xffffffffU)))))
            : ((8U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_alu_ctrl0))
                ? ((4U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_alu_ctrl0))
                    ? ((2U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_alu_ctrl0))
                        ? 0U : ((1U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_alu_ctrl0))
                                 ? VL_SHIFTRS_III(32,32,32, 
                                                  VL_MULS_III(32, vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu0__DOT__a, vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu0__DOT__b), 0x00000020U)
                                 : (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu0__DOT__a 
                                    * vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu0__DOT__b)))
                    : ((2U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_alu_ctrl0))
                        ? ((1U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_alu_ctrl0))
                            ? __VdfgRegularize_h6e95ff9d_0_6
                            : vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu0__DOT__b)
                        : ((1U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_alu_ctrl0))
                            ? ((vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu0__DOT__a 
                                < vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu0__DOT__b)
                                ? 1U : 0U) : (VL_LTS_III(32, vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu0__DOT__a, vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu0__DOT__b)
                                               ? 1U
                                               : 0U))))
                : ((4U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_alu_ctrl0))
                    ? ((2U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_alu_ctrl0))
                        ? ((1U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_alu_ctrl0))
                            ? VL_SHIFTRS_III(32,32,5, vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu0__DOT__a, 
                                             (0x0000001fU 
                                              & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu0__DOT__b))
                            : (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu0__DOT__a 
                               >> (0x0000001fU & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu0__DOT__b)))
                        : ((1U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_alu_ctrl0))
                            ? (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu0__DOT__a 
                               << (0x0000001fU & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu0__DOT__b))
                            : (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu0__DOT__a 
                               ^ vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu0__DOT__b)))
                    : ((2U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_alu_ctrl0))
                        ? ((1U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_alu_ctrl0))
                            ? (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu0__DOT__a 
                               | vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu0__DOT__b)
                            : (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu0__DOT__a 
                               & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu0__DOT__b))
                        : ((1U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_alu_ctrl0))
                            ? (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu0__DOT__a 
                               - vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu0__DOT__b)
                            : __VdfgRegularize_h6e95ff9d_0_6)))));
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_wb_val0 
        = ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_csr_read0)
            ? vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr
           [(0x0000000fU & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_csr0))]
            : (((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_jal0) 
                | (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_jalr0))
                ? ((IData)(4U) + vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_pc0)
                : vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu0__DOT__result));
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc1__DOT__rs2 
        = ((4U == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__fwd_unit__DOT__fwd_b1))
            ? vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_wb_val0
            : ((2U == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__fwd_unit__DOT__fwd_b1))
                ? vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_fwd_val0
                : ((3U == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__fwd_unit__DOT__fwd_b1))
                    ? vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_fwd_val1
                    : ((1U == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__fwd_unit__DOT__fwd_b1))
                        ? ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_13)
                            ? vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__wd1
                            : vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__wd0)
                        : vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rd2_1))));
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc1__DOT__rs1 
        = ((4U == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__fwd_unit__DOT__fwd_a1))
            ? vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_wb_val0
            : ((2U == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__fwd_unit__DOT__fwd_a1))
                ? vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_fwd_val0
                : ((3U == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__fwd_unit__DOT__fwd_a1))
                    ? vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_fwd_val1
                    : ((1U == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__fwd_unit__DOT__fwd_a1))
                        ? ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_12)
                            ? vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__wd1
                            : vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__wd0)
                        : vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rd1_1))));
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu1__DOT__b 
        = ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_alu_src1)
            ? vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_imm1
            : vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc1__DOT__rs2);
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__s1_ex_branch_taken 
        = (((4U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_funct3_1))
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
                    >> 1U)) & ((1U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_funct3_1))
                                ? (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc1__DOT__rs1 
                                   != vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc1__DOT__rs2)
                                : (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc1__DOT__rs1 
                                   == vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc1__DOT__rs2)))) 
           & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_branch1));
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu1__DOT__a 
        = ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_auipc1)
            ? vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_pc1
            : ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_is_lui1)
                ? 0U : vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc1__DOT__rs1));
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__do_flush 
        = (((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc0__DOT__branch_taken) 
            & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_branch0)) 
           | ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__s1_ex_branch_taken) 
              | (IData)(vlSelfRef.__VdfgRegularize_he50b618e_0_2)));
    __VdfgRegularize_h6e95ff9d_0_8 = VL_DIV_III(32, vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu1__DOT__a, vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu1__DOT__b);
    __VdfgRegularize_h6e95ff9d_0_9 = (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu1__DOT__a 
                                      + vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu1__DOT__b);
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__flush_ex 
        = ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__do_flush) 
           | (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__load_use_stall));
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__stall_if 
        = ((~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__do_flush)) 
           & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__load_use_stall));
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu1__DOT__result 
        = ((0x00000010U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_alu_ctrl1))
            ? ((8U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_alu_ctrl1))
                ? 0U : ((4U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_alu_ctrl1))
                         ? 0U : ((2U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_alu_ctrl1))
                                  ? ((1U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_alu_ctrl1))
                                      ? ((0U != vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu1__DOT__b)
                                          ? VL_MODDIV_III(32, vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu1__DOT__a, vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu1__DOT__b)
                                          : vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu1__DOT__a)
                                      : ((0U != vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu1__DOT__b)
                                          ? VL_MODDIVS_III(32, vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu1__DOT__a, vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu1__DOT__b)
                                          : vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu1__DOT__a))
                                  : ((1U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_alu_ctrl1))
                                      ? ((0U != vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu1__DOT__b)
                                          ? __VdfgRegularize_h6e95ff9d_0_8
                                          : 1U) : (
                                                   (0U 
                                                    != vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu1__DOT__b)
                                                    ? __VdfgRegularize_h6e95ff9d_0_8
                                                    : 0xffffffffU)))))
            : ((8U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_alu_ctrl1))
                ? ((4U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_alu_ctrl1))
                    ? ((2U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_alu_ctrl1))
                        ? 0U : ((1U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_alu_ctrl1))
                                 ? VL_SHIFTRS_III(32,32,32, 
                                                  VL_MULS_III(32, vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu1__DOT__a, vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu1__DOT__b), 0x00000020U)
                                 : (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu1__DOT__a 
                                    * vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu1__DOT__b)))
                    : ((2U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_alu_ctrl1))
                        ? ((1U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_alu_ctrl1))
                            ? __VdfgRegularize_h6e95ff9d_0_9
                            : vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu1__DOT__b)
                        : ((1U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_alu_ctrl1))
                            ? ((vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu1__DOT__a 
                                < vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu1__DOT__b)
                                ? 1U : 0U) : (VL_LTS_III(32, vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu1__DOT__a, vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu1__DOT__b)
                                               ? 1U
                                               : 0U))))
                : ((4U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_alu_ctrl1))
                    ? ((2U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_alu_ctrl1))
                        ? ((1U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_alu_ctrl1))
                            ? VL_SHIFTRS_III(32,32,5, vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu1__DOT__a, 
                                             (0x0000001fU 
                                              & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu1__DOT__b))
                            : (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu1__DOT__a 
                               >> (0x0000001fU & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu1__DOT__b)))
                        : ((1U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_alu_ctrl1))
                            ? (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu1__DOT__a 
                               << (0x0000001fU & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu1__DOT__b))
                            : (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu1__DOT__a 
                               ^ vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu1__DOT__b)))
                    : ((2U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_alu_ctrl1))
                        ? ((1U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_alu_ctrl1))
                            ? (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu1__DOT__a 
                               | vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu1__DOT__b)
                            : (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu1__DOT__a 
                               & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu1__DOT__b))
                        : ((1U & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_alu_ctrl1))
                            ? (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu1__DOT__a 
                               - vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu1__DOT__b)
                            : __VdfgRegularize_h6e95ff9d_0_9)))));
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_wb_val1 
        = ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_csr_read1)
            ? vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr
           [(0x0000000fU & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_csr1))]
            : ((IData)(vlSelfRef.__VdfgRegularize_he50b618e_0_2)
                ? ((IData)(4U) + vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_pc1)
                : vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu1__DOT__result));
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_br_cmp0__DOT__rs2 
        = (((~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_mem_read1)) 
            & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_7) 
               & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rd1) 
                  == (0x0000001fU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                     >> 0x00000014U)))))
            ? vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_wb_val1
            : (((~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_mem_read0)) 
                & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_8) 
                   & (IData)(vlSelfRef.__VdfgRegularize_he50b618e_0_4)))
                ? vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_wb_val0
                : (((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_9) 
                    & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_rd1) 
                       == (0x0000001fU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                          >> 0x00000014U))))
                    ? vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_fwd_val1
                    : (((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_10) 
                        & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_rd0) 
                           == (0x0000001fU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                              >> 0x00000014U))))
                        ? vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_fwd_val0
                        : vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_rd2_0))));
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_br_cmp0__DOT__rs1 
        = (((~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_mem_read1)) 
            & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_7) 
               & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rd1) 
                  == (0x0000001fU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                     >> 0x0000000fU)))))
            ? vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_wb_val1
            : (((~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_mem_read0)) 
                & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_8) 
                   & (IData)(vlSelfRef.__VdfgRegularize_he50b618e_0_3)))
                ? vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_wb_val0
                : (((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_9) 
                    & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_rd1) 
                       == (0x0000001fU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                          >> 0x0000000fU))))
                    ? vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_fwd_val1
                    : (((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_10) 
                        & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_rd0) 
                           == (0x0000001fU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                              >> 0x0000000fU))))
                        ? vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_fwd_val0
                        : vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_rd1_0))));
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_jalr_target0 
        = (0xfffffffeU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_br_cmp0__DOT__rs1 
                          + vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ig0__DOT__imm));
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__s0_id_branch_taken 
        = ((0x00004000U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)
            ? ((0x00002000U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)
                ? ((0x00001000U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)
                    ? (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_br_cmp0__DOT__rs1 
                       >= vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_br_cmp0__DOT__rs2)
                    : (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_br_cmp0__DOT__rs1 
                       < vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_br_cmp0__DOT__rs2))
                : ((0x00001000U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)
                    ? VL_GTES_III(32, vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_br_cmp0__DOT__rs1, vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_br_cmp0__DOT__rs2)
                    : VL_LTS_III(32, vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_br_cmp0__DOT__rs1, vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_br_cmp0__DOT__rs2)))
            : ((~ (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                   >> 0x0000000dU)) & ((0x00001000U 
                                        & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0)
                                        ? (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_br_cmp0__DOT__rs1 
                                           != vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_br_cmp0__DOT__rs2)
                                        : (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_br_cmp0__DOT__rs1 
                                           == vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_br_cmp0__DOT__rs2))));
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__inter_slot_ctrl 
        = (((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_branch0) 
            & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__s0_id_branch_taken) 
               | (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_pred_taken0))) 
           | (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_13));
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_branch_target0 
        = ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_branch0)
            ? ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__s0_id_branch_taken)
                ? vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_jal_target0
                : ((IData)(4U) + vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_pc0))
            : ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_jal0)
                ? vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_jal_target0
                : ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_jalr0)
                    ? vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_jalr_target0
                    : ((IData)(4U) + vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_pc0))));
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__squash_s1 
        = ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__inter_slot_load_raw) 
           | ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__inter_slot_ctrl) 
              | (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__s0_s1_mem_dep)));
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_branch_redirect0 
        = ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_14) 
           & ((~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__stall_if)) 
              & (((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_pred_taken0)
                   ? vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_pred_target0
                   : ((IData)(4U) + vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_pc0)) 
                 != vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_branch_target0)));
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__flush_id 
        = (((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__do_flush) 
            | ((~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__stall_if)) 
               & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__inter_slot_load_raw) 
                  | (((~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_pred_taken0)) 
                      & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__inter_slot_ctrl)) 
                     | (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__s0_s1_mem_dep))))) 
           | (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_branch_redirect0));
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__pc_counter__DOT__pc_next 
        = (((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_branch0) 
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
                        ? (0xfffffffeU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc1__DOT__rs1 
                                          + vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_imm1))
                        : ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_branch_redirect0)
                            ? vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_branch_target0
                            : (((~ ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_14) 
                                    & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_pred_taken0))) 
                                & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__squash_s1))
                                ? ((IData)(4U) + vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_pc0)
                                : ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_pred_taken0)
                                    ? vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_pred_target0
                                    : ((IData)(8U) 
                                       + vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__pc_current))))))));
}

VL_ATTR_COLD void Vtb_program___024root____Vm_traceActivitySetAll(Vtb_program___024root* vlSelf);

VL_ATTR_COLD void Vtb_program___024root___eval_stl(Vtb_program___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_program___024root___eval_stl\n"); );
    Vtb_program__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        Vtb_program___024root___stl_sequent__TOP__0(vlSelf);
        Vtb_program___024root____Vm_traceActivitySetAll(vlSelf);
    }
}

VL_ATTR_COLD bool Vtb_program___024root___eval_phase__stl(Vtb_program___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_program___024root___eval_phase__stl\n"); );
    Vtb_program__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtb_program___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = Vtb_program___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        Vtb_program___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

bool Vtb_program___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_program___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_program___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vtb_program___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge tb_program.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(posedge tb_program.rst)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_program___024root____Vm_traceActivitySetAll(Vtb_program___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_program___024root____Vm_traceActivitySetAll\n"); );
    Vtb_program__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSelfRef.__Vm_traceActivity[4U] = 1U;
    vlSelfRef.__Vm_traceActivity[5U] = 1U;
}

VL_ATTR_COLD void Vtb_program___024root___ctor_var_reset(Vtb_program___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_program___024root___ctor_var_reset\n"); );
    Vtb_program__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->tb_program__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14938299226173702668ull);
    vlSelf->tb_program__DOT__rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4436885247640552988ull);
    vlSelf->tb_program__DOT__cycle_count = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11094013390385595332ull);
    vlSelf->tb_program__DOT__instret_count = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14419974160742381625ull);
    vlSelf->tb_program__DOT__f = 0;
    vlSelf->tb_program__DOT__i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2401526468131014467ull);
    vlSelf->tb_program__DOT__stable_pc_count = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11273801823611597325ull);
    vlSelf->tb_program__DOT__last_pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6990859571591187332ull);
    vlSelf->tb_program__DOT__done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 557905993611712317ull);
    vlSelf->tb_program__DOT__timed_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7368842248869258489ull);
    vlSelf->tb_program__DOT__max_cycles = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8183449906037688076ull);
    vlSelf->tb_program__DOT__progress_interval = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7209932704514208750ull);
    vlSelf->tb_program__DOT__progress_enable = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8836020920049355116ull);
    vlSelf->tb_program__DOT__decode_mnemonic__Vstatic__opcode = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 2130414142444067502ull);
    vlSelf->tb_program__DOT__decode_mnemonic__Vstatic__funct3 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 6015888137666540855ull);
    vlSelf->tb_program__DOT__uut__DOT__mem_rdata0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6363347185756566467ull);
    vlSelf->tb_program__DOT__uut__DOT__mem_rdata1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14317148609632287695ull);
    for (int __Vi0 = 0; __Vi0 < 4096; ++__Vi0) {
        vlSelf->tb_program__DOT__uut__DOT__mem__DOT__imem__DOT__mem[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6452708925737753695ull);
    }
    for (int __Vi0 = 0; __Vi0 < 2048; ++__Vi0) {
        vlSelf->tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10860187166893708339ull);
    }
    for (int __Vi0 = 0; __Vi0 < 4096; ++__Vi0) {
        vlSelf->tb_program__DOT__uut__DOT__imem_b__DOT__mem[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14175378185233494819ull);
    }
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__instr0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8926000424534670239ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__flush_id = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13157078725857908932ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_branch_redirect0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12620480457880354163ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_branch_target0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1448256060918088688ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__pipe_halt = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7982681135902062430ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__pc_current = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17116336109909510713ull);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->tb_program__DOT__uut__DOT__core__DOT__hybp_local_pht[__Vi0] = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 3671430716712255439ull);
    }
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->tb_program__DOT__uut__DOT__core__DOT__hybp_global_pht[__Vi0] = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 752254125193567281ull);
    }
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->tb_program__DOT__uut__DOT__core__DOT__hybp_choice_pht[__Vi0] = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 2037018203804558405ull);
    }
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__hybp_ghr = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1547240048026510405ull);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->tb_program__DOT__uut__DOT__core__DOT__btb_valid[__Vi0] = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11921866029906434233ull);
    }
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->tb_program__DOT__uut__DOT__core__DOT__btb_tag[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14367081548807354516ull);
    }
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->tb_program__DOT__uut__DOT__core__DOT__btb_target[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17061157224478234047ull);
    }
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->tb_program__DOT__uut__DOT__core__DOT__ras_stack[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2206897513900620071ull);
    }
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__ras_top_ptr = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 14775324482431795301ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__ras_count = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 10623681057298612159ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__hybp_i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16381474319563301486ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__ras_i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12302438875032554708ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__if_pred_pc_idx = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9703854091611761458ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__if_is_ret0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9443232283145492004ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__if_btb_hit0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9233209503306686796ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__if_global_idx0 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5340841281213227148ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__if_local_pred_taken0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9989597324513882958ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__if_global_pred_taken0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8562456951499434033ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__if_pred_taken0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 484439607028681418ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__if_pred_target0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1844353807683231800ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__if_id_pc0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8018824850840261218ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__if_id_pc1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11003216792862168657ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3769831055430422723ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13597592301406470221ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__if_id_valid0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1027791649237801674ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__if_id_valid1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14439291215205269503ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__if_id_pred_taken0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12085383166779117296ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__if_id_pred_target0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6592561725727858840ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__if_id_local_idx0 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12345037397425158202ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__if_id_global_idx0 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14827096160195131301ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__if_id_local_pred_taken0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4217570766389761954ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__if_id_global_pred_taken0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6330428330204310840ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_mem_read0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15882252492656446410ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_mem_write0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13986509681296572177ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_reg_write0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12372069446329678831ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_mem_to_reg0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13065987769923537568ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_alu_src0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7185341248227601204ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_auipc0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15999373790333287211ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_is_lui0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3505380769799581629ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_alu_op0 = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 16426531387015483783ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_imm_type0 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 7580364170000502942ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_branch0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4953888861236738235ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_jal0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1456181795357684162ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_jalr0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16272298148614682400ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_ecall0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5929872110290092846ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_halt0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 654481503664151967ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_csr_read0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16050540332890535978ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_csr_write0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8965296630064906953ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_mem_read1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2871247712034674659ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_mem_write1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5038081374486133630ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_reg_write1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14373380598123116080ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_mem_to_reg1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13468741836249403405ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_alu_src1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14775262327626905228ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_auipc1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7389923541774175001ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_is_lui1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 332969073013968378ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_alu_op1 = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 8786424710797309722ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_imm_type1 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 10615355303861573749ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_branch1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1681395662195058008ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_jal1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16195443334905851100ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_jalr1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8613390154325724615ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_ecall1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17478016974842548168ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_halt1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12248623663011003770ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_csr_read1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9010726746426050487ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_csr_write1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17863405805652998690ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_rd1_0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10708704675369269395ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_rd2_0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8955972754933291588ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_ex_pc0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13617690778363863338ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_ex_rd1_0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5439096108187294460ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_ex_rd2_0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14007411285875198695ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_ex_imm0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16501611776910682392ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_ex_rs1_0 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 15185833678179964714ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_ex_rs2_0 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 17766924321950551658ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_ex_rd0 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 15140655018111911923ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_ex_funct3_0 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 8459789384233317169ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_ex_funct7_0 = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 4377747543471308653ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_ex_csr0 = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 16920004368530849984ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_ex_mem_read0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14916263611188793692ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_ex_mem_write0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7822420693779224520ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_ex_reg_write0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1672496726194677369ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_ex_mem_to_reg0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15444846087931046348ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_ex_alu_src0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4152533744159476251ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_ex_auipc0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7921606864216887548ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_ex_is_lui0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3649157419365550977ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_ex_alu_op0 = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 6101699115460634508ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_ex_branch0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5618031110254735859ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_ex_jal0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16716090563928216082ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_ex_jalr0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14027592622782567130ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_ex_ecall0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10630497229644702130ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_ex_halt0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12546208364536057081ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_ex_csr_read0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3866994300904953772ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_ex_csr_write0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6389680994527715779ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_ex_is_rtype0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10262005236091688215ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_ex_valid0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3276597303469683389ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_ex_pred_taken0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7292199621164042802ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_ex_local_idx0 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4259775664677890207ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_ex_global_idx0 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14882386795443902298ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_ex_local_pred_taken0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5431621295000368207ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_ex_global_pred_taken0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7066390887572804723ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_ex_pc1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9155964857309849584ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_ex_rd1_1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5373766479079624699ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_ex_rd2_1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7954857122850314011ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_ex_imm1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15395359611640176921ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_ex_rs1_1 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 664229942760352662ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_ex_rs2_1 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 14682820697084241306ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_ex_rd1 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 11118270304779890395ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_ex_funct3_1 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 2848340807374570850ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_ex_funct7_1 = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 2072666283430414838ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_ex_csr1 = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 10842928129785660127ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_ex_mem_read1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17845110071507898993ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_ex_mem_write1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18316725695901873033ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_ex_reg_write1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8190114341013943464ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_ex_mem_to_reg1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8899224719424632318ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_ex_alu_src1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17573666769801166189ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_ex_auipc1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17742462236846342487ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_ex_is_lui1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15633110577867292932ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_ex_alu_op1 = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 15682351587527588108ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_ex_branch1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16364857594744640761ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_ex_jal1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13487381238594795756ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_ex_jalr1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12836557483592846701ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_ex_ecall1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2743301507233094929ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_ex_halt1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11411575014230605225ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_ex_csr_read1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9757435454236955388ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_ex_csr_write1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16052658762968717327ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_ex_is_rtype1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9315318087682379564ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_ex_valid1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9867193014417256949ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__ex_mem_fwd_val0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5793572899633471096ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__ex_mem_fwd_val1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5153173428621629772ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__ex_alu_ctrl0 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 10940855152490712381ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__ex_wb_val0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14538144825355311876ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__ex_alu_ctrl1 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 3553234731359206926ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__ex_wb_val1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13286118944369146184ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_jal_target0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17948229458100808889ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_jalr_target0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8007477181826340982ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_is_ret0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4883494276658132203ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10254493484509056734ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__ex_mem_rs2_0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7587896020314688927ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__ex_mem_wb0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14990886962428534594ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__ex_mem_rd0 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 9814100982678881865ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__ex_mem_funct3_0 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 1316238536857403565ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__ex_mem_mem_read0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2665653210369043244ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__ex_mem_mem_write0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1435187917249520377ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__ex_mem_reg_write0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6775305443960569669ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__ex_mem_mem_to_reg0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16614725422665136773ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__ex_mem_ecall0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13499829358246908639ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__ex_mem_halt0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13306718300059862839ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__ex_mem_valid0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17485253285310888241ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10429658415547167157ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__ex_mem_rs2_1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1442115130502105359ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__ex_mem_wb1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12946513317309375849ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__ex_mem_rd1 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 5086537578876009531ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__ex_mem_funct3_1 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 14961529149548823366ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__ex_mem_mem_read1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12944881801995372098ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__ex_mem_mem_write1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6002154946869387055ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__ex_mem_reg_write1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10046442303376427108ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__ex_mem_mem_to_reg1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12654346164073309384ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__ex_mem_ecall1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2679041880802561232ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__ex_mem_halt1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11713423805294297624ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__ex_mem_valid1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1319356123614548341ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__mem_wb_wb0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10395430526133243488ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__mem_wb_mem0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3706145010240036242ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__mem_wb_rd0 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 13813907170444138286ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__mem_wb_reg_write0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2693815953226875744ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__mem_wb_mem_to_reg0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1727164536775604885ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__mem_wb_ecall0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17784097965696077130ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__mem_wb_halt0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7604319661120022489ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__mem_wb_valid0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14787361733841057277ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__mem_wb_wb1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2925943033178448398ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__mem_wb_mem1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2775915545782430669ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__mem_wb_rd1 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 10411152345148857199ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__mem_wb_reg_write1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 671931596114258646ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__mem_wb_mem_to_reg1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1510163151261138011ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__mem_wb_ecall1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4477597880467034624ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__mem_wb_halt1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6988502662488393222ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__mem_wb_valid1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 757002014622255686ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_4 = 0;
    vlSelf->tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_5 = 0;
    vlSelf->tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_7 = 0;
    vlSelf->tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_8 = 0;
    vlSelf->tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_9 = 0;
    vlSelf->tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_10 = 0;
    vlSelf->tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_13 = 0;
    vlSelf->tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_14 = 0;
    vlSelf->tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_15 = 0;
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__pc_counter__DOT__pc_next = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16349036127890862240ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__ig0__DOT__imm = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14626259907602644945ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__ig1__DOT__imm = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4555290297589581162ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__regs__DOT__wd0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18073584512552236671ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__regs__DOT__wd1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14472538950567897042ull);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16784523158070412861ull);
    }
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__regs__DOT__i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15571633581191432621ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__alu0__DOT__a = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6511638321427530170ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__alu0__DOT__b = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18114170819163198262ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__alu0__DOT__result = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11810953264386060746ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__bc0__DOT__rs1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3327358642313154136ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__bc0__DOT__rs2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14756801837801558443ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__bc0__DOT__branch_taken = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15935894544082241490ull);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7423123879202114342ull);
    }
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17142340110989247806ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__alu1__DOT__a = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4385137262906582059ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__alu1__DOT__b = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10691573115909786210ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__alu1__DOT__result = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2855470758583601023ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__bc1__DOT__rs1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1748912922442272096ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__bc1__DOT__rs2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 966954614958127741ull);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16985470011386669306ull);
    }
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10532550341705081824ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_br_cmp0__DOT__rs1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6399232367937762420ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__id_br_cmp0__DOT__rs2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6784288671010234915ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__hz__DOT__s1_ex_branch_taken = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17250689607508676742ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__hz__DOT__s0_id_branch_taken = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17156489254949053261ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__hz__DOT__s0_s1_mem_dep = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17824033656561335637ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__hz__DOT__stall_if = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14271352000880466375ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__hz__DOT__flush_ex = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16064979509387457962ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__hz__DOT__squash_s1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10616802223514313830ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__hz__DOT__load_use_stall = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13232250312793181005ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__hz__DOT__do_flush = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 466620588441693916ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__hz__DOT__inter_slot_load_raw = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6689905328904325996ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__hz__DOT__inter_slot_ctrl = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6319345645629769918ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__hz__DOT____VdfgRegularize_h6b6f5558_0_0 = 0;
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__hz__DOT____VdfgRegularize_h6b6f5558_0_1 = 0;
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__fwd_unit__DOT__fwd_a0 = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 16591583388218184014ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__fwd_unit__DOT__fwd_b0 = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 12203688354264296453ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__fwd_unit__DOT__fwd_a1 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 16234241594471706014ull);
    vlSelf->tb_program__DOT__uut__DOT__core__DOT__fwd_unit__DOT__fwd_b1 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 2931559297742708478ull);
    vlSelf->__VdfgRegularize_he50b618e_0_2 = 0;
    vlSelf->__VdfgRegularize_he50b618e_0_3 = 0;
    vlSelf->__VdfgRegularize_he50b618e_0_4 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_10 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_11 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_12 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_13 = 0;
    vlSelf->__Vdly__tb_program__DOT__uut__DOT__core__DOT__ex_mem_halt0 = 0;
    vlSelf->__Vdly__tb_program__DOT__uut__DOT__core__DOT__ex_mem_halt1 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__tb_program__DOT__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__tb_program__DOT__rst__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 6; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
