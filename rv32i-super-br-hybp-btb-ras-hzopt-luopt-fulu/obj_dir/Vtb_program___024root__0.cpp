// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_program.h for the primary calling header

#include "Vtb_program__pch.h"

VL_ATTR_COLD void Vtb_program___024root___eval_initial__TOP(Vtb_program___024root* vlSelf);
VlCoroutine Vtb_program___024root___eval_initial__TOP__Vtiming__0(Vtb_program___024root* vlSelf);
VlCoroutine Vtb_program___024root___eval_initial__TOP__Vtiming__1(Vtb_program___024root* vlSelf);

void Vtb_program___024root___eval_initial(Vtb_program___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_program___024root___eval_initial\n"); );
    Vtb_program__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_program___024root___eval_initial__TOP(vlSelf);
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    Vtb_program___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb_program___024root___eval_initial__TOP__Vtiming__1(vlSelf);
}

VlCoroutine Vtb_program___024root___eval_initial__TOP__Vtiming__0(Vtb_program___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_program___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vtb_program__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_program__DOT__clk = 0U;
    while (true) {
        co_await vlSelfRef.__VdlySched.delay(5ULL, 
                                             nullptr, 
                                             "tb/tb_program.v", 
                                             115);
        vlSelfRef.tb_program__DOT__clk = (1U & (~ (IData)(vlSelfRef.tb_program__DOT__clk)));
    }
    co_return;}

VlCoroutine Vtb_program___024root___eval_initial__TOP__Vtiming__1(Vtb_program___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_program___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vtb_program__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlWide<3>/*95:0*/ __Vtemp_4;
    VlWide<3>/*95:0*/ __Vtemp_8;
    // Body
    vlSelfRef.tb_program__DOT__rst = 1U;
    vlSelfRef.tb_program__DOT__done = 0U;
    vlSelfRef.tb_program__DOT__timed_out = 0U;
    vlSelfRef.tb_program__DOT__last_pc = 0xffffffffU;
    vlSelfRef.tb_program__DOT__stable_pc_count = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x0000000000000014ULL, 
                                         nullptr, "tb/tb_program.v", 
                                         162);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb_program__DOT__rst = 0U;
    while (((~ (IData)(vlSelfRef.tb_program__DOT__done)) 
            & VL_LTS_III(32, vlSelfRef.tb_program__DOT__cycle_count, vlSelfRef.tb_program__DOT__max_cycles))) {
        co_await vlSelfRef.__VtrigSched_h52375936__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_program.clk)", 
                                                             "tb/tb_program.v", 
                                                             166);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        if ((1U & (~ (IData)(vlSelfRef.tb_program__DOT__rst)))) {
            if ((vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__pc_current 
                 == vlSelfRef.tb_program__DOT__last_pc)) {
                vlSelfRef.tb_program__DOT__stable_pc_count 
                    = ((IData)(1U) + vlSelfRef.tb_program__DOT__stable_pc_count);
            } else {
                vlSelfRef.tb_program__DOT__stable_pc_count = 0U;
                vlSelfRef.tb_program__DOT__last_pc 
                    = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__pc_current;
            }
            if (((((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_halt0) 
                   & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_valid0)) 
                  | ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_halt1) 
                     & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_valid1))) 
                 | VL_LTS_III(32, 0x00000020U, vlSelfRef.tb_program__DOT__stable_pc_count))) {
                vlSelfRef.tb_program__DOT__done = 1U;
            }
        }
    }
    if (((~ (IData)(vlSelfRef.tb_program__DOT__done)) 
         & VL_GTES_III(32, vlSelfRef.tb_program__DOT__cycle_count, vlSelfRef.tb_program__DOT__max_cycles))) {
        vlSelfRef.tb_program__DOT__timed_out = 1U;
    }
    co_await vlSelfRef.__VdlySched.delay(0x0000000000000014ULL, 
                                         nullptr, "tb/tb_program.v", 
                                         184);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb_program__DOT__f = VL_FOPEN_NN("tb_program_results.txt"s
                                               , "w"s);
    ;
    VL_FWRITEF_NX(vlSelfRef.tb_program__DOT__f,"============================================================\n         RV32I C-PROGRAM TEST RESULTS\n============================================================\nTotal cycles: %0d\nRetired instructions: %0d\nFinal PC:     0x%08x\n",0,
                  32,vlSelfRef.tb_program__DOT__cycle_count,
                  32,vlSelfRef.tb_program__DOT__instret_count,
                  32,vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__pc_current);
    if ((((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_halt0) 
          & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_valid0)) 
         | ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_halt1) 
            & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_valid1)))) {
        __Vtemp_4[0U] = 0x616c6c29U;
        __Vtemp_4[1U] = 0x20286563U;
        __Vtemp_4[2U] = 0x00594553U;
    } else {
        __Vtemp_4[0U] = 0x00004e4fU;
        __Vtemp_4[1U] = 0U;
        __Vtemp_4[2U] = 0U;
    }
    VL_FWRITEF_NX(vlSelfRef.tb_program__DOT__f,"Halted:       %s\nTimed out:    %s\nLoop detected:%s\n\n============================================================\n              REGISTER FILE\n============================================================\n  x00=%08x    x01=%08x    x02=%08x    x03=%08x\n  x04=%08x    x05=%08x    x06=%08x    x07=%08x\n  x08=%08x    x09=%08x    x10=%08x    x11=%08x\n  x12=%08x    x13=%08x    x14=%08x    x15=%08x\n  x16=%08x    x17=%08x    x18=%08x    x19=%08x\n  x20=%08x    x21=%08x    x22=%08x    x23=%08x\n",0,
                  88,__Vtemp_4.data(),24,((IData)(vlSelfRef.tb_program__DOT__timed_out)
                                           ? 0x00594553U
                                           : 0x00004e4fU),
                  32,(((~ (((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_halt0) 
                            & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_valid0)) 
                           | ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_halt1) 
                              & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_valid1)))) 
                       & (IData)(vlSelfRef.tb_program__DOT__done))
                       ? 0x20594553U : 0x00204e4fU),
                  32,vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                  [0U],32,vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                  [1U],32,vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                  [2U],32,vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                  [3U],32,vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                  [4U],32,vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                  [5U],32,vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                  [6U],32,vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                  [7U],32,vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                  [8U],32,vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                  [9U],32,vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                  [0x0aU],32,vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                  [0x0bU],32,vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                  [0x0cU],32,vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                  [0x0dU],32,vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                  [0x0eU],32,vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                  [0x0fU],32,vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                  [0x10U],32,vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                  [0x11U],32,vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                  [0x12U],32,vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                  [0x13U],32,vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                  [0x14U],32,vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                  [0x15U],32,vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                  [0x16U],32,vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                  [0x17U]);
    VL_FWRITEF_NX(vlSelfRef.tb_program__DOT__f,"  x24=%08x    x25=%08x    x26=%08x    x27=%08x\n  x28=%08x    x29=%08x    x30=%08x    x31=%08x\n\n============================================================\n      OUTPUT WINDOW DUMP (word idx 64..127)\n============================================================\n",0,
                  32,vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                  [0x18U],32,vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                  [0x19U],32,vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                  [0x1aU],32,vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                  [0x1bU],32,vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                  [0x1cU],32,vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                  [0x1dU],32,vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                  [0x1eU],32,vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                  [0x1fU]);
    vlSelfRef.tb_program__DOT__i = 0x00000040U;
    VL_FWRITEF_NX(vlSelfRef.tb_program__DOT__f,"  mem[64] @0x00000100 = 0x%08x\n",0,
                  32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                  [0x0040U]);
    vlSelfRef.tb_program__DOT__i = 0x00000041U;
    VL_FWRITEF_NX(vlSelfRef.tb_program__DOT__f,"  mem[65] @0x00000104 = 0x%08x\n",0,
                  32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                  [0x0041U]);
    vlSelfRef.tb_program__DOT__i = 0x00000042U;
    VL_FWRITEF_NX(vlSelfRef.tb_program__DOT__f,"  mem[66] @0x00000108 = 0x%08x\n",0,
                  32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                  [0x0042U]);
    vlSelfRef.tb_program__DOT__i = 0x00000043U;
    VL_FWRITEF_NX(vlSelfRef.tb_program__DOT__f,"  mem[67] @0x0000010c = 0x%08x\n",0,
                  32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                  [0x0043U]);
    vlSelfRef.tb_program__DOT__i = 0x00000044U;
    VL_FWRITEF_NX(vlSelfRef.tb_program__DOT__f,"  mem[68] @0x00000110 = 0x%08x\n",0,
                  32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                  [0x0044U]);
    vlSelfRef.tb_program__DOT__i = 0x00000045U;
    VL_FWRITEF_NX(vlSelfRef.tb_program__DOT__f,"  mem[69] @0x00000114 = 0x%08x\n",0,
                  32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                  [0x0045U]);
    vlSelfRef.tb_program__DOT__i = 0x00000046U;
    VL_FWRITEF_NX(vlSelfRef.tb_program__DOT__f,"  mem[70] @0x00000118 = 0x%08x\n",0,
                  32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                  [0x0046U]);
    vlSelfRef.tb_program__DOT__i = 0x00000047U;
    VL_FWRITEF_NX(vlSelfRef.tb_program__DOT__f,"  mem[71] @0x0000011c = 0x%08x\n",0,
                  32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                  [0x0047U]);
    vlSelfRef.tb_program__DOT__i = 0x00000048U;
    VL_FWRITEF_NX(vlSelfRef.tb_program__DOT__f,"  mem[72] @0x00000120 = 0x%08x\n",0,
                  32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                  [0x0048U]);
    vlSelfRef.tb_program__DOT__i = 0x00000049U;
    VL_FWRITEF_NX(vlSelfRef.tb_program__DOT__f,"  mem[73] @0x00000124 = 0x%08x\n",0,
                  32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                  [0x0049U]);
    vlSelfRef.tb_program__DOT__i = 0x0000004aU;
    VL_FWRITEF_NX(vlSelfRef.tb_program__DOT__f,"  mem[74] @0x00000128 = 0x%08x\n",0,
                  32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                  [0x004aU]);
    vlSelfRef.tb_program__DOT__i = 0x0000004bU;
    VL_FWRITEF_NX(vlSelfRef.tb_program__DOT__f,"  mem[75] @0x0000012c = 0x%08x\n",0,
                  32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                  [0x004bU]);
    vlSelfRef.tb_program__DOT__i = 0x0000004cU;
    VL_FWRITEF_NX(vlSelfRef.tb_program__DOT__f,"  mem[76] @0x00000130 = 0x%08x\n",0,
                  32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                  [0x004cU]);
    vlSelfRef.tb_program__DOT__i = 0x0000004dU;
    VL_FWRITEF_NX(vlSelfRef.tb_program__DOT__f,"  mem[77] @0x00000134 = 0x%08x\n",0,
                  32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                  [0x004dU]);
    vlSelfRef.tb_program__DOT__i = 0x0000004eU;
    VL_FWRITEF_NX(vlSelfRef.tb_program__DOT__f,"  mem[78] @0x00000138 = 0x%08x\n",0,
                  32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                  [0x004eU]);
    vlSelfRef.tb_program__DOT__i = 0x0000004fU;
    VL_FWRITEF_NX(vlSelfRef.tb_program__DOT__f,"  mem[79] @0x0000013c = 0x%08x\n",0,
                  32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                  [0x004fU]);
    vlSelfRef.tb_program__DOT__i = 0x00000050U;
    VL_FWRITEF_NX(vlSelfRef.tb_program__DOT__f,"  mem[80] @0x00000140 = 0x%08x\n",0,
                  32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                  [0x0050U]);
    vlSelfRef.tb_program__DOT__i = 0x00000051U;
    VL_FWRITEF_NX(vlSelfRef.tb_program__DOT__f,"  mem[81] @0x00000144 = 0x%08x\n",0,
                  32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                  [0x0051U]);
    vlSelfRef.tb_program__DOT__i = 0x00000052U;
    VL_FWRITEF_NX(vlSelfRef.tb_program__DOT__f,"  mem[82] @0x00000148 = 0x%08x\n",0,
                  32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                  [0x0052U]);
    vlSelfRef.tb_program__DOT__i = 0x00000053U;
    VL_FWRITEF_NX(vlSelfRef.tb_program__DOT__f,"  mem[83] @0x0000014c = 0x%08x\n",0,
                  32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                  [0x0053U]);
    vlSelfRef.tb_program__DOT__i = 0x00000054U;
    VL_FWRITEF_NX(vlSelfRef.tb_program__DOT__f,"  mem[84] @0x00000150 = 0x%08x\n",0,
                  32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                  [0x0054U]);
    vlSelfRef.tb_program__DOT__i = 0x00000055U;
    VL_FWRITEF_NX(vlSelfRef.tb_program__DOT__f,"  mem[85] @0x00000154 = 0x%08x\n",0,
                  32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                  [0x0055U]);
    vlSelfRef.tb_program__DOT__i = 0x00000056U;
    VL_FWRITEF_NX(vlSelfRef.tb_program__DOT__f,"  mem[86] @0x00000158 = 0x%08x\n",0,
                  32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                  [0x0056U]);
    vlSelfRef.tb_program__DOT__i = 0x00000057U;
    VL_FWRITEF_NX(vlSelfRef.tb_program__DOT__f,"  mem[87] @0x0000015c = 0x%08x\n",0,
                  32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                  [0x0057U]);
    vlSelfRef.tb_program__DOT__i = 0x00000058U;
    VL_FWRITEF_NX(vlSelfRef.tb_program__DOT__f,"  mem[88] @0x00000160 = 0x%08x\n",0,
                  32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                  [0x0058U]);
    vlSelfRef.tb_program__DOT__i = 0x00000059U;
    VL_FWRITEF_NX(vlSelfRef.tb_program__DOT__f,"  mem[89] @0x00000164 = 0x%08x\n",0,
                  32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                  [0x0059U]);
    vlSelfRef.tb_program__DOT__i = 0x0000005aU;
    VL_FWRITEF_NX(vlSelfRef.tb_program__DOT__f,"  mem[90] @0x00000168 = 0x%08x\n",0,
                  32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                  [0x005aU]);
    vlSelfRef.tb_program__DOT__i = 0x0000005bU;
    VL_FWRITEF_NX(vlSelfRef.tb_program__DOT__f,"  mem[91] @0x0000016c = 0x%08x\n",0,
                  32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                  [0x005bU]);
    vlSelfRef.tb_program__DOT__i = 0x0000005cU;
    VL_FWRITEF_NX(vlSelfRef.tb_program__DOT__f,"  mem[92] @0x00000170 = 0x%08x\n",0,
                  32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                  [0x005cU]);
    vlSelfRef.tb_program__DOT__i = 0x0000005dU;
    VL_FWRITEF_NX(vlSelfRef.tb_program__DOT__f,"  mem[93] @0x00000174 = 0x%08x\n",0,
                  32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                  [0x005dU]);
    vlSelfRef.tb_program__DOT__i = 0x0000005eU;
    VL_FWRITEF_NX(vlSelfRef.tb_program__DOT__f,"  mem[94] @0x00000178 = 0x%08x\n",0,
                  32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                  [0x005eU]);
    vlSelfRef.tb_program__DOT__i = 0x0000005fU;
    VL_FWRITEF_NX(vlSelfRef.tb_program__DOT__f,"  mem[95] @0x0000017c = 0x%08x\n",0,
                  32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                  [0x005fU]);
    vlSelfRef.tb_program__DOT__i = 0x00000060U;
    VL_FWRITEF_NX(vlSelfRef.tb_program__DOT__f,"  mem[96] @0x00000180 = 0x%08x\n",0,
                  32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                  [0x0060U]);
    vlSelfRef.tb_program__DOT__i = 0x00000061U;
    VL_FWRITEF_NX(vlSelfRef.tb_program__DOT__f,"  mem[97] @0x00000184 = 0x%08x\n",0,
                  32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                  [0x0061U]);
    vlSelfRef.tb_program__DOT__i = 0x00000062U;
    VL_FWRITEF_NX(vlSelfRef.tb_program__DOT__f,"  mem[98] @0x00000188 = 0x%08x\n",0,
                  32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                  [0x0062U]);
    vlSelfRef.tb_program__DOT__i = 0x00000063U;
    VL_FWRITEF_NX(vlSelfRef.tb_program__DOT__f,"  mem[99] @0x0000018c = 0x%08x\n",0,
                  32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                  [0x0063U]);
    vlSelfRef.tb_program__DOT__i = 0x00000064U;
    VL_FWRITEF_NX(vlSelfRef.tb_program__DOT__f,"  mem[100] @0x00000190 = 0x%08x\n",0,
                  32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                  [0x0064U]);
    vlSelfRef.tb_program__DOT__i = 0x00000065U;
    VL_FWRITEF_NX(vlSelfRef.tb_program__DOT__f,"  mem[101] @0x00000194 = 0x%08x\n",0,
                  32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                  [0x0065U]);
    vlSelfRef.tb_program__DOT__i = 0x00000066U;
    VL_FWRITEF_NX(vlSelfRef.tb_program__DOT__f,"  mem[102] @0x00000198 = 0x%08x\n",0,
                  32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                  [0x0066U]);
    vlSelfRef.tb_program__DOT__i = 0x00000067U;
    VL_FWRITEF_NX(vlSelfRef.tb_program__DOT__f,"  mem[103] @0x0000019c = 0x%08x\n",0,
                  32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                  [0x0067U]);
    vlSelfRef.tb_program__DOT__i = 0x00000068U;
    VL_FWRITEF_NX(vlSelfRef.tb_program__DOT__f,"  mem[104] @0x000001a0 = 0x%08x\n",0,
                  32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                  [0x0068U]);
    vlSelfRef.tb_program__DOT__i = 0x00000069U;
    VL_FWRITEF_NX(vlSelfRef.tb_program__DOT__f,"  mem[105] @0x000001a4 = 0x%08x\n",0,
                  32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                  [0x0069U]);
    vlSelfRef.tb_program__DOT__i = 0x0000006aU;
    VL_FWRITEF_NX(vlSelfRef.tb_program__DOT__f,"  mem[106] @0x000001a8 = 0x%08x\n",0,
                  32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                  [0x006aU]);
    vlSelfRef.tb_program__DOT__i = 0x0000006bU;
    VL_FWRITEF_NX(vlSelfRef.tb_program__DOT__f,"  mem[107] @0x000001ac = 0x%08x\n",0,
                  32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                  [0x006bU]);
    vlSelfRef.tb_program__DOT__i = 0x0000006cU;
    VL_FWRITEF_NX(vlSelfRef.tb_program__DOT__f,"  mem[108] @0x000001b0 = 0x%08x\n",0,
                  32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                  [0x006cU]);
    vlSelfRef.tb_program__DOT__i = 0x0000006dU;
    VL_FWRITEF_NX(vlSelfRef.tb_program__DOT__f,"  mem[109] @0x000001b4 = 0x%08x\n",0,
                  32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                  [0x006dU]);
    vlSelfRef.tb_program__DOT__i = 0x0000006eU;
    VL_FWRITEF_NX(vlSelfRef.tb_program__DOT__f,"  mem[110] @0x000001b8 = 0x%08x\n",0,
                  32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                  [0x006eU]);
    vlSelfRef.tb_program__DOT__i = 0x0000006fU;
    VL_FWRITEF_NX(vlSelfRef.tb_program__DOT__f,"  mem[111] @0x000001bc = 0x%08x\n",0,
                  32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                  [0x006fU]);
    vlSelfRef.tb_program__DOT__i = 0x00000070U;
    VL_FWRITEF_NX(vlSelfRef.tb_program__DOT__f,"  mem[112] @0x000001c0 = 0x%08x\n",0,
                  32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                  [0x0070U]);
    vlSelfRef.tb_program__DOT__i = 0x00000071U;
    VL_FWRITEF_NX(vlSelfRef.tb_program__DOT__f,"  mem[113] @0x000001c4 = 0x%08x\n",0,
                  32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                  [0x0071U]);
    vlSelfRef.tb_program__DOT__i = 0x00000072U;
    VL_FWRITEF_NX(vlSelfRef.tb_program__DOT__f,"  mem[114] @0x000001c8 = 0x%08x\n",0,
                  32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                  [0x0072U]);
    vlSelfRef.tb_program__DOT__i = 0x00000073U;
    VL_FWRITEF_NX(vlSelfRef.tb_program__DOT__f,"  mem[115] @0x000001cc = 0x%08x\n",0,
                  32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                  [0x0073U]);
    vlSelfRef.tb_program__DOT__i = 0x00000074U;
    VL_FWRITEF_NX(vlSelfRef.tb_program__DOT__f,"  mem[116] @0x000001d0 = 0x%08x\n",0,
                  32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                  [0x0074U]);
    vlSelfRef.tb_program__DOT__i = 0x00000075U;
    VL_FWRITEF_NX(vlSelfRef.tb_program__DOT__f,"  mem[117] @0x000001d4 = 0x%08x\n",0,
                  32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                  [0x0075U]);
    vlSelfRef.tb_program__DOT__i = 0x00000076U;
    VL_FWRITEF_NX(vlSelfRef.tb_program__DOT__f,"  mem[118] @0x000001d8 = 0x%08x\n",0,
                  32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                  [0x0076U]);
    vlSelfRef.tb_program__DOT__i = 0x00000077U;
    VL_FWRITEF_NX(vlSelfRef.tb_program__DOT__f,"  mem[119] @0x000001dc = 0x%08x\n",0,
                  32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                  [0x0077U]);
    vlSelfRef.tb_program__DOT__i = 0x00000078U;
    VL_FWRITEF_NX(vlSelfRef.tb_program__DOT__f,"  mem[120] @0x000001e0 = 0x%08x\n",0,
                  32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                  [0x0078U]);
    vlSelfRef.tb_program__DOT__i = 0x00000079U;
    VL_FWRITEF_NX(vlSelfRef.tb_program__DOT__f,"  mem[121] @0x000001e4 = 0x%08x\n",0,
                  32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                  [0x0079U]);
    vlSelfRef.tb_program__DOT__i = 0x0000007aU;
    VL_FWRITEF_NX(vlSelfRef.tb_program__DOT__f,"  mem[122] @0x000001e8 = 0x%08x\n",0,
                  32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                  [0x007aU]);
    vlSelfRef.tb_program__DOT__i = 0x0000007bU;
    VL_FWRITEF_NX(vlSelfRef.tb_program__DOT__f,"  mem[123] @0x000001ec = 0x%08x\n",0,
                  32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                  [0x007bU]);
    vlSelfRef.tb_program__DOT__i = 0x0000007cU;
    VL_FWRITEF_NX(vlSelfRef.tb_program__DOT__f,"  mem[124] @0x000001f0 = 0x%08x\n",0,
                  32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                  [0x007cU]);
    vlSelfRef.tb_program__DOT__i = 0x0000007dU;
    VL_FWRITEF_NX(vlSelfRef.tb_program__DOT__f,"  mem[125] @0x000001f4 = 0x%08x\n",0,
                  32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                  [0x007dU]);
    vlSelfRef.tb_program__DOT__i = 0x0000007eU;
    VL_FWRITEF_NX(vlSelfRef.tb_program__DOT__f,"  mem[126] @0x000001f8 = 0x%08x\n",0,
                  32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                  [0x007eU]);
    vlSelfRef.tb_program__DOT__i = 0x0000007fU;
    VL_FWRITEF_NX(vlSelfRef.tb_program__DOT__f,"  mem[127] @0x000001fc = 0x%08x\n",0,
                  32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                  [0x007fU]);
    vlSelfRef.tb_program__DOT__i = 0x00000080U;
    VL_FWRITEF_NX(vlSelfRef.tb_program__DOT__f,"\n============================================================\n      DATA MEMORY DUMP (word idx 0..127, non-zero only)\n============================================================\n",0);
    vlSelfRef.tb_program__DOT__i = 0U;
    while (VL_GTS_III(32, 0x00000080U, vlSelfRef.tb_program__DOT__i)) {
        if (VL_UNLIKELY(((0U != vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                          [(0x000007ffU & vlSelfRef.tb_program__DOT__i)])))) {
            VL_FWRITEF_NX(vlSelfRef.tb_program__DOT__f,"  mem[%0d] @0x%08x = 0x%08x\n",0,
                          32,vlSelfRef.tb_program__DOT__i,
                          32,VL_MULS_III(32, (IData)(4U), vlSelfRef.tb_program__DOT__i),
                          32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                          [(0x000007ffU & vlSelfRef.tb_program__DOT__i)]);
        }
        vlSelfRef.tb_program__DOT__i = ((IData)(1U) 
                                        + vlSelfRef.tb_program__DOT__i);
    }
    VL_FCLOSE_I(vlSelfRef.tb_program__DOT__f); VL_WRITEF_NX("\n============================================================\n         RV32I C-PROGRAM TEST RESULTS\n============================================================\nTotal cycles: %0d\nRetired instructions: %0d\nFinal PC:     0x%08x\n",0,
                                                            32,
                                                            vlSelfRef.tb_program__DOT__cycle_count,
                                                            32,
                                                            vlSelfRef.tb_program__DOT__instret_count,
                                                            32,
                                                            vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__pc_current);
    if ((((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_halt0) 
          & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_valid0)) 
         | ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_halt1) 
            & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_valid1)))) {
        __Vtemp_8[0U] = 0x616c6c29U;
        __Vtemp_8[1U] = 0x20286563U;
        __Vtemp_8[2U] = 0x00594553U;
    } else {
        __Vtemp_8[0U] = 0x00004e4fU;
        __Vtemp_8[1U] = 0U;
        __Vtemp_8[2U] = 0U;
    }
    VL_WRITEF_NX("Halted:       %s\nTimed out:    %s\nLoop detected:%s\n\nREGISTER SNAPSHOT:\n  x00=%08x x01=%08x x02=%08x x03=%08x\n  x04=%08x x05=%08x x06=%08x x07=%08x\n  x08=%08x x09=%08x x10=%08x x11=%08x\n  x12=%08x x13=%08x x14=%08x x15=%08x\n  x16=%08x x17=%08x x18=%08x x19=%08x\n  x20=%08x x21=%08x x22=%08x x23=%08x\n  x24=%08x x25=%08x x26=%08x x27=%08x\n  x28=%08x x29=%08x x30=%08x x31=%08x\n\nOUTPUT WINDOW (idx 64..127):\n",0,
                 88,__Vtemp_8.data(),24,((IData)(vlSelfRef.tb_program__DOT__timed_out)
                                          ? 0x00594553U
                                          : 0x00004e4fU),
                 32,(((~ (((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_halt0) 
                           & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_valid0)) 
                          | ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_halt1) 
                             & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_valid1)))) 
                      & (IData)(vlSelfRef.tb_program__DOT__done))
                      ? 0x20594553U : 0x00204e4fU),
                 32,vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                 [0U],32,vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                 [1U],32,vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                 [2U],32,vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                 [3U],32,vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                 [4U],32,vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                 [5U],32,vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                 [6U],32,vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                 [7U],32,vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                 [8U],32,vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                 [9U],32,vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                 [0x0aU],32,vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                 [0x0bU],32,vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                 [0x0cU],32,vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                 [0x0dU],32,vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                 [0x0eU],32,vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                 [0x0fU],32,vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                 [0x10U],32,vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                 [0x11U],32,vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                 [0x12U],32,vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                 [0x13U],32,vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                 [0x14U],32,vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                 [0x15U],32,vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                 [0x16U],32,vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                 [0x17U],32,vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                 [0x18U],32,vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                 [0x19U],32,vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                 [0x1aU],32,vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                 [0x1bU],32,vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                 [0x1cU],32,vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                 [0x1dU],32,vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                 [0x1eU],32,vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                 [0x1fU]);
    vlSelfRef.tb_program__DOT__i = 0x00000040U;
    VL_WRITEF_NX("  mem[64] @0x00000100 = 0x%08x\n",0,
                 32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                 [0x0040U]);
    vlSelfRef.tb_program__DOT__i = 0x00000041U;
    VL_WRITEF_NX("  mem[65] @0x00000104 = 0x%08x\n",0,
                 32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                 [0x0041U]);
    vlSelfRef.tb_program__DOT__i = 0x00000042U;
    VL_WRITEF_NX("  mem[66] @0x00000108 = 0x%08x\n",0,
                 32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                 [0x0042U]);
    vlSelfRef.tb_program__DOT__i = 0x00000043U;
    VL_WRITEF_NX("  mem[67] @0x0000010c = 0x%08x\n",0,
                 32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                 [0x0043U]);
    vlSelfRef.tb_program__DOT__i = 0x00000044U;
    VL_WRITEF_NX("  mem[68] @0x00000110 = 0x%08x\n",0,
                 32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                 [0x0044U]);
    vlSelfRef.tb_program__DOT__i = 0x00000045U;
    VL_WRITEF_NX("  mem[69] @0x00000114 = 0x%08x\n",0,
                 32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                 [0x0045U]);
    vlSelfRef.tb_program__DOT__i = 0x00000046U;
    VL_WRITEF_NX("  mem[70] @0x00000118 = 0x%08x\n",0,
                 32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                 [0x0046U]);
    vlSelfRef.tb_program__DOT__i = 0x00000047U;
    VL_WRITEF_NX("  mem[71] @0x0000011c = 0x%08x\n",0,
                 32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                 [0x0047U]);
    vlSelfRef.tb_program__DOT__i = 0x00000048U;
    VL_WRITEF_NX("  mem[72] @0x00000120 = 0x%08x\n",0,
                 32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                 [0x0048U]);
    vlSelfRef.tb_program__DOT__i = 0x00000049U;
    VL_WRITEF_NX("  mem[73] @0x00000124 = 0x%08x\n",0,
                 32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                 [0x0049U]);
    vlSelfRef.tb_program__DOT__i = 0x0000004aU;
    VL_WRITEF_NX("  mem[74] @0x00000128 = 0x%08x\n",0,
                 32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                 [0x004aU]);
    vlSelfRef.tb_program__DOT__i = 0x0000004bU;
    VL_WRITEF_NX("  mem[75] @0x0000012c = 0x%08x\n",0,
                 32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                 [0x004bU]);
    vlSelfRef.tb_program__DOT__i = 0x0000004cU;
    VL_WRITEF_NX("  mem[76] @0x00000130 = 0x%08x\n",0,
                 32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                 [0x004cU]);
    vlSelfRef.tb_program__DOT__i = 0x0000004dU;
    VL_WRITEF_NX("  mem[77] @0x00000134 = 0x%08x\n",0,
                 32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                 [0x004dU]);
    vlSelfRef.tb_program__DOT__i = 0x0000004eU;
    VL_WRITEF_NX("  mem[78] @0x00000138 = 0x%08x\n",0,
                 32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                 [0x004eU]);
    vlSelfRef.tb_program__DOT__i = 0x0000004fU;
    VL_WRITEF_NX("  mem[79] @0x0000013c = 0x%08x\n",0,
                 32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                 [0x004fU]);
    vlSelfRef.tb_program__DOT__i = 0x00000050U;
    VL_WRITEF_NX("  mem[80] @0x00000140 = 0x%08x\n",0,
                 32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                 [0x0050U]);
    vlSelfRef.tb_program__DOT__i = 0x00000051U;
    VL_WRITEF_NX("  mem[81] @0x00000144 = 0x%08x\n",0,
                 32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                 [0x0051U]);
    vlSelfRef.tb_program__DOT__i = 0x00000052U;
    VL_WRITEF_NX("  mem[82] @0x00000148 = 0x%08x\n",0,
                 32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                 [0x0052U]);
    vlSelfRef.tb_program__DOT__i = 0x00000053U;
    VL_WRITEF_NX("  mem[83] @0x0000014c = 0x%08x\n",0,
                 32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                 [0x0053U]);
    vlSelfRef.tb_program__DOT__i = 0x00000054U;
    VL_WRITEF_NX("  mem[84] @0x00000150 = 0x%08x\n",0,
                 32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                 [0x0054U]);
    vlSelfRef.tb_program__DOT__i = 0x00000055U;
    VL_WRITEF_NX("  mem[85] @0x00000154 = 0x%08x\n",0,
                 32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                 [0x0055U]);
    vlSelfRef.tb_program__DOT__i = 0x00000056U;
    VL_WRITEF_NX("  mem[86] @0x00000158 = 0x%08x\n",0,
                 32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                 [0x0056U]);
    vlSelfRef.tb_program__DOT__i = 0x00000057U;
    VL_WRITEF_NX("  mem[87] @0x0000015c = 0x%08x\n",0,
                 32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                 [0x0057U]);
    vlSelfRef.tb_program__DOT__i = 0x00000058U;
    VL_WRITEF_NX("  mem[88] @0x00000160 = 0x%08x\n",0,
                 32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                 [0x0058U]);
    vlSelfRef.tb_program__DOT__i = 0x00000059U;
    VL_WRITEF_NX("  mem[89] @0x00000164 = 0x%08x\n",0,
                 32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                 [0x0059U]);
    vlSelfRef.tb_program__DOT__i = 0x0000005aU;
    VL_WRITEF_NX("  mem[90] @0x00000168 = 0x%08x\n",0,
                 32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                 [0x005aU]);
    vlSelfRef.tb_program__DOT__i = 0x0000005bU;
    VL_WRITEF_NX("  mem[91] @0x0000016c = 0x%08x\n",0,
                 32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                 [0x005bU]);
    vlSelfRef.tb_program__DOT__i = 0x0000005cU;
    VL_WRITEF_NX("  mem[92] @0x00000170 = 0x%08x\n",0,
                 32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                 [0x005cU]);
    vlSelfRef.tb_program__DOT__i = 0x0000005dU;
    VL_WRITEF_NX("  mem[93] @0x00000174 = 0x%08x\n",0,
                 32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                 [0x005dU]);
    vlSelfRef.tb_program__DOT__i = 0x0000005eU;
    VL_WRITEF_NX("  mem[94] @0x00000178 = 0x%08x\n",0,
                 32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                 [0x005eU]);
    vlSelfRef.tb_program__DOT__i = 0x0000005fU;
    VL_WRITEF_NX("  mem[95] @0x0000017c = 0x%08x\n",0,
                 32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                 [0x005fU]);
    vlSelfRef.tb_program__DOT__i = 0x00000060U;
    VL_WRITEF_NX("  mem[96] @0x00000180 = 0x%08x\n",0,
                 32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                 [0x0060U]);
    vlSelfRef.tb_program__DOT__i = 0x00000061U;
    VL_WRITEF_NX("  mem[97] @0x00000184 = 0x%08x\n",0,
                 32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                 [0x0061U]);
    vlSelfRef.tb_program__DOT__i = 0x00000062U;
    VL_WRITEF_NX("  mem[98] @0x00000188 = 0x%08x\n",0,
                 32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                 [0x0062U]);
    vlSelfRef.tb_program__DOT__i = 0x00000063U;
    VL_WRITEF_NX("  mem[99] @0x0000018c = 0x%08x\n",0,
                 32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                 [0x0063U]);
    vlSelfRef.tb_program__DOT__i = 0x00000064U;
    VL_WRITEF_NX("  mem[100] @0x00000190 = 0x%08x\n",0,
                 32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                 [0x0064U]);
    vlSelfRef.tb_program__DOT__i = 0x00000065U;
    VL_WRITEF_NX("  mem[101] @0x00000194 = 0x%08x\n",0,
                 32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                 [0x0065U]);
    vlSelfRef.tb_program__DOT__i = 0x00000066U;
    VL_WRITEF_NX("  mem[102] @0x00000198 = 0x%08x\n",0,
                 32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                 [0x0066U]);
    vlSelfRef.tb_program__DOT__i = 0x00000067U;
    VL_WRITEF_NX("  mem[103] @0x0000019c = 0x%08x\n",0,
                 32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                 [0x0067U]);
    vlSelfRef.tb_program__DOT__i = 0x00000068U;
    VL_WRITEF_NX("  mem[104] @0x000001a0 = 0x%08x\n",0,
                 32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                 [0x0068U]);
    vlSelfRef.tb_program__DOT__i = 0x00000069U;
    VL_WRITEF_NX("  mem[105] @0x000001a4 = 0x%08x\n",0,
                 32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                 [0x0069U]);
    vlSelfRef.tb_program__DOT__i = 0x0000006aU;
    VL_WRITEF_NX("  mem[106] @0x000001a8 = 0x%08x\n",0,
                 32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                 [0x006aU]);
    vlSelfRef.tb_program__DOT__i = 0x0000006bU;
    VL_WRITEF_NX("  mem[107] @0x000001ac = 0x%08x\n",0,
                 32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                 [0x006bU]);
    vlSelfRef.tb_program__DOT__i = 0x0000006cU;
    VL_WRITEF_NX("  mem[108] @0x000001b0 = 0x%08x\n",0,
                 32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                 [0x006cU]);
    vlSelfRef.tb_program__DOT__i = 0x0000006dU;
    VL_WRITEF_NX("  mem[109] @0x000001b4 = 0x%08x\n",0,
                 32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                 [0x006dU]);
    vlSelfRef.tb_program__DOT__i = 0x0000006eU;
    VL_WRITEF_NX("  mem[110] @0x000001b8 = 0x%08x\n",0,
                 32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                 [0x006eU]);
    vlSelfRef.tb_program__DOT__i = 0x0000006fU;
    VL_WRITEF_NX("  mem[111] @0x000001bc = 0x%08x\n",0,
                 32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                 [0x006fU]);
    vlSelfRef.tb_program__DOT__i = 0x00000070U;
    VL_WRITEF_NX("  mem[112] @0x000001c0 = 0x%08x\n",0,
                 32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                 [0x0070U]);
    vlSelfRef.tb_program__DOT__i = 0x00000071U;
    VL_WRITEF_NX("  mem[113] @0x000001c4 = 0x%08x\n",0,
                 32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                 [0x0071U]);
    vlSelfRef.tb_program__DOT__i = 0x00000072U;
    VL_WRITEF_NX("  mem[114] @0x000001c8 = 0x%08x\n",0,
                 32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                 [0x0072U]);
    vlSelfRef.tb_program__DOT__i = 0x00000073U;
    VL_WRITEF_NX("  mem[115] @0x000001cc = 0x%08x\n",0,
                 32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                 [0x0073U]);
    vlSelfRef.tb_program__DOT__i = 0x00000074U;
    VL_WRITEF_NX("  mem[116] @0x000001d0 = 0x%08x\n",0,
                 32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                 [0x0074U]);
    vlSelfRef.tb_program__DOT__i = 0x00000075U;
    VL_WRITEF_NX("  mem[117] @0x000001d4 = 0x%08x\n",0,
                 32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                 [0x0075U]);
    vlSelfRef.tb_program__DOT__i = 0x00000076U;
    VL_WRITEF_NX("  mem[118] @0x000001d8 = 0x%08x\n",0,
                 32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                 [0x0076U]);
    vlSelfRef.tb_program__DOT__i = 0x00000077U;
    VL_WRITEF_NX("  mem[119] @0x000001dc = 0x%08x\n",0,
                 32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                 [0x0077U]);
    vlSelfRef.tb_program__DOT__i = 0x00000078U;
    VL_WRITEF_NX("  mem[120] @0x000001e0 = 0x%08x\n",0,
                 32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                 [0x0078U]);
    vlSelfRef.tb_program__DOT__i = 0x00000079U;
    VL_WRITEF_NX("  mem[121] @0x000001e4 = 0x%08x\n",0,
                 32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                 [0x0079U]);
    vlSelfRef.tb_program__DOT__i = 0x0000007aU;
    VL_WRITEF_NX("  mem[122] @0x000001e8 = 0x%08x\n",0,
                 32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                 [0x007aU]);
    vlSelfRef.tb_program__DOT__i = 0x0000007bU;
    VL_WRITEF_NX("  mem[123] @0x000001ec = 0x%08x\n",0,
                 32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                 [0x007bU]);
    vlSelfRef.tb_program__DOT__i = 0x0000007cU;
    VL_WRITEF_NX("  mem[124] @0x000001f0 = 0x%08x\n",0,
                 32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                 [0x007cU]);
    vlSelfRef.tb_program__DOT__i = 0x0000007dU;
    VL_WRITEF_NX("  mem[125] @0x000001f4 = 0x%08x\n",0,
                 32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                 [0x007dU]);
    vlSelfRef.tb_program__DOT__i = 0x0000007eU;
    VL_WRITEF_NX("  mem[126] @0x000001f8 = 0x%08x\n",0,
                 32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                 [0x007eU]);
    vlSelfRef.tb_program__DOT__i = 0x0000007fU;
    VL_WRITEF_NX("  mem[127] @0x000001fc = 0x%08x\n",0,
                 32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                 [0x007fU]);
    vlSelfRef.tb_program__DOT__i = 0x00000080U;
    VL_WRITEF_NX("\nNON-ZERO DATA MEMORY (idx 0..127):\n",0);
    vlSelfRef.tb_program__DOT__i = 0U;
    while (VL_GTS_III(32, 0x00000080U, vlSelfRef.tb_program__DOT__i)) {
        if (VL_UNLIKELY(((0U != vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                          [(0x000007ffU & vlSelfRef.tb_program__DOT__i)])))) {
            VL_WRITEF_NX("  mem[%0d] @0x%08x = 0x%08x\n",0,
                         32,vlSelfRef.tb_program__DOT__i,
                         32,VL_MULS_III(32, (IData)(4U), vlSelfRef.tb_program__DOT__i),
                         32,vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                         [(0x000007ffU & vlSelfRef.tb_program__DOT__i)]);
        }
        vlSelfRef.tb_program__DOT__i = ((IData)(1U) 
                                        + vlSelfRef.tb_program__DOT__i);
    }
    VL_WRITEF_NX("Full results written to tb_program_results.txt\n============================================================\n",0);
    VL_FINISH_MT("tb/tb_program.v", 277, "");
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_return;}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_program___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

void Vtb_program___024root___eval_triggers__act(Vtb_program___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_program___024root___eval_triggers__act\n"); );
    Vtb_program__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    ((vlSelfRef.__VdlySched.awaitingCurrentTime() 
                                                      << 2U) 
                                                     | ((((IData)(vlSelfRef.tb_program__DOT__rst) 
                                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_program__DOT__rst__0))) 
                                                         << 1U) 
                                                        | ((IData)(vlSelfRef.tb_program__DOT__clk) 
                                                           & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_program__DOT__clk__0)))))));
    vlSelfRef.__Vtrigprevexpr___TOP__tb_program__DOT__clk__0 
        = vlSelfRef.tb_program__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_program__DOT__rst__0 
        = vlSelfRef.tb_program__DOT__rst;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_program___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
}

bool Vtb_program___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_program___024root___trigger_anySet__act\n"); );
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

void Vtb_program___024root___nba_sequent__TOP__0(Vtb_program___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_program___024root___nba_sequent__TOP__0\n"); );
    Vtb_program__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*7:0*/ __Vdly__tb_program__DOT__uut__DOT__core__DOT__hybp_ghr;
    __Vdly__tb_program__DOT__uut__DOT__core__DOT__hybp_ghr = 0;
    CData/*3:0*/ __Vdly__tb_program__DOT__uut__DOT__core__DOT__ras_top_ptr;
    __Vdly__tb_program__DOT__uut__DOT__core__DOT__ras_top_ptr = 0;
    CData/*4:0*/ __Vdly__tb_program__DOT__uut__DOT__core__DOT__ras_count;
    __Vdly__tb_program__DOT__uut__DOT__core__DOT__ras_count = 0;
    CData/*0:0*/ __VdlySet__tb_program__DOT__uut__DOT__core__DOT__ras_stack__v0;
    __VdlySet__tb_program__DOT__uut__DOT__core__DOT__ras_stack__v0 = 0;
    IData/*31:0*/ __VdlyVal__tb_program__DOT__uut__DOT__core__DOT__ras_stack__v16;
    __VdlyVal__tb_program__DOT__uut__DOT__core__DOT__ras_stack__v16 = 0;
    CData/*0:0*/ __VdlySet__tb_program__DOT__uut__DOT__core__DOT__ras_stack__v16;
    __VdlySet__tb_program__DOT__uut__DOT__core__DOT__ras_stack__v16 = 0;
    IData/*31:0*/ __VdlyVal__tb_program__DOT__uut__DOT__core__DOT__ras_stack__v17;
    __VdlyVal__tb_program__DOT__uut__DOT__core__DOT__ras_stack__v17 = 0;
    CData/*3:0*/ __VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__ras_stack__v17;
    __VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__ras_stack__v17 = 0;
    CData/*0:0*/ __VdlySet__tb_program__DOT__uut__DOT__core__DOT__ras_stack__v17;
    __VdlySet__tb_program__DOT__uut__DOT__core__DOT__ras_stack__v17 = 0;
    CData/*7:0*/ __VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__hybp_local_pht__v0;
    __VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__hybp_local_pht__v0 = 0;
    CData/*7:0*/ __VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__hybp_global_pht__v0;
    __VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__hybp_global_pht__v0 = 0;
    CData/*7:0*/ __VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__hybp_choice_pht__v0;
    __VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__hybp_choice_pht__v0 = 0;
    CData/*7:0*/ __VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__btb_valid__v0;
    __VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__btb_valid__v0 = 0;
    CData/*7:0*/ __VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__btb_tag__v0;
    __VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__btb_tag__v0 = 0;
    CData/*7:0*/ __VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__btb_target__v0;
    __VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__btb_target__v0 = 0;
    CData/*1:0*/ __VdlyVal__tb_program__DOT__uut__DOT__core__DOT__hybp_local_pht__v1;
    __VdlyVal__tb_program__DOT__uut__DOT__core__DOT__hybp_local_pht__v1 = 0;
    CData/*7:0*/ __VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__hybp_local_pht__v1;
    __VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__hybp_local_pht__v1 = 0;
    CData/*1:0*/ __VdlyVal__tb_program__DOT__uut__DOT__core__DOT__hybp_global_pht__v1;
    __VdlyVal__tb_program__DOT__uut__DOT__core__DOT__hybp_global_pht__v1 = 0;
    CData/*7:0*/ __VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__hybp_global_pht__v1;
    __VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__hybp_global_pht__v1 = 0;
    CData/*1:0*/ __VdlyVal__tb_program__DOT__uut__DOT__core__DOT__hybp_choice_pht__v1;
    __VdlyVal__tb_program__DOT__uut__DOT__core__DOT__hybp_choice_pht__v1 = 0;
    CData/*7:0*/ __VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__hybp_choice_pht__v1;
    __VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__hybp_choice_pht__v1 = 0;
    CData/*7:0*/ __VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__btb_valid__v1;
    __VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__btb_valid__v1 = 0;
    IData/*31:0*/ __VdlyVal__tb_program__DOT__uut__DOT__core__DOT__btb_tag__v1;
    __VdlyVal__tb_program__DOT__uut__DOT__core__DOT__btb_tag__v1 = 0;
    CData/*7:0*/ __VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__btb_tag__v1;
    __VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__btb_tag__v1 = 0;
    IData/*31:0*/ __VdlyVal__tb_program__DOT__uut__DOT__core__DOT__btb_target__v1;
    __VdlyVal__tb_program__DOT__uut__DOT__core__DOT__btb_target__v1 = 0;
    CData/*7:0*/ __VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__btb_target__v1;
    __VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__btb_target__v1 = 0;
    CData/*7:0*/ __VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__btb_valid__v2;
    __VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__btb_valid__v2 = 0;
    IData/*31:0*/ __VdlyVal__tb_program__DOT__uut__DOT__core__DOT__btb_tag__v2;
    __VdlyVal__tb_program__DOT__uut__DOT__core__DOT__btb_tag__v2 = 0;
    CData/*7:0*/ __VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__btb_tag__v2;
    __VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__btb_tag__v2 = 0;
    IData/*31:0*/ __VdlyVal__tb_program__DOT__uut__DOT__core__DOT__btb_target__v2;
    __VdlyVal__tb_program__DOT__uut__DOT__core__DOT__btb_target__v2 = 0;
    CData/*7:0*/ __VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__btb_target__v2;
    __VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__btb_target__v2 = 0;
    CData/*7:0*/ __VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__btb_valid__v3;
    __VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__btb_valid__v3 = 0;
    IData/*31:0*/ __VdlyVal__tb_program__DOT__uut__DOT__core__DOT__btb_tag__v3;
    __VdlyVal__tb_program__DOT__uut__DOT__core__DOT__btb_tag__v3 = 0;
    CData/*7:0*/ __VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__btb_tag__v3;
    __VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__btb_tag__v3 = 0;
    IData/*31:0*/ __VdlyVal__tb_program__DOT__uut__DOT__core__DOT__btb_target__v3;
    __VdlyVal__tb_program__DOT__uut__DOT__core__DOT__btb_target__v3 = 0;
    CData/*7:0*/ __VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__btb_target__v3;
    __VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__btb_target__v3 = 0;
    CData/*0:0*/ __VdlySet__tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf__v0;
    __VdlySet__tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf__v0 = 0;
    IData/*31:0*/ __VdlyVal__tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf__v32;
    __VdlyVal__tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf__v32 = 0;
    CData/*4:0*/ __VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf__v32;
    __VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf__v32 = 0;
    CData/*0:0*/ __VdlySet__tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf__v32;
    __VdlySet__tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf__v32 = 0;
    IData/*31:0*/ __VdlyVal__tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf__v33;
    __VdlyVal__tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf__v33 = 0;
    CData/*4:0*/ __VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf__v33;
    __VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf__v33 = 0;
    CData/*0:0*/ __VdlySet__tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf__v33;
    __VdlySet__tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf__v33 = 0;
    CData/*0:0*/ __VdlySet__tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr__v0;
    __VdlySet__tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr__v0 = 0;
    IData/*31:0*/ __VdlyVal__tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr__v12;
    __VdlyVal__tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr__v12 = 0;
    CData/*3:0*/ __VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr__v12;
    __VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr__v12 = 0;
    CData/*0:0*/ __VdlySet__tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr__v12;
    __VdlySet__tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr__v12 = 0;
    CData/*0:0*/ __VdlySet__tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr__v0;
    __VdlySet__tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr__v0 = 0;
    IData/*31:0*/ __VdlyVal__tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr__v12;
    __VdlyVal__tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr__v12 = 0;
    CData/*3:0*/ __VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr__v12;
    __VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr__v12 = 0;
    CData/*0:0*/ __VdlySet__tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr__v12;
    __VdlySet__tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr__v12 = 0;
    // Body
    __Vdly__tb_program__DOT__uut__DOT__core__DOT__hybp_ghr 
        = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hybp_ghr;
    __VdlySet__tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr__v0 = 0U;
    __VdlySet__tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr__v12 = 0U;
    __Vdly__tb_program__DOT__uut__DOT__core__DOT__ras_top_ptr 
        = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_top_ptr;
    __VdlySet__tb_program__DOT__uut__DOT__core__DOT__ras_stack__v0 = 0U;
    __VdlySet__tb_program__DOT__uut__DOT__core__DOT__ras_stack__v16 = 0U;
    __VdlySet__tb_program__DOT__uut__DOT__core__DOT__ras_stack__v17 = 0U;
    __Vdly__tb_program__DOT__uut__DOT__core__DOT__ras_count 
        = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_count;
    __VdlySet__tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr__v0 = 0U;
    __VdlySet__tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr__v12 = 0U;
    vlSelfRef.__Vdly__tb_program__DOT__uut__DOT__core__DOT__ex_mem_halt1 
        = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_halt1;
    vlSelfRef.__Vdly__tb_program__DOT__uut__DOT__core__DOT__ex_mem_halt0 
        = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_halt0;
    __VdlySet__tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf__v0 = 0U;
    __VdlySet__tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf__v32 = 0U;
    __VdlySet__tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf__v33 = 0U;
    if (vlSelfRef.tb_program__DOT__rst) {
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_i = 0x00000010U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__i = 0x00000020U;
    }
    if (vlSelfRef.tb_program__DOT__rst) {
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hybp_i = 0U;
        while (VL_GTS_III(32, 0x00000100U, vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hybp_i)) {
            __VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__hybp_local_pht__v0 
                = (0x000000ffU & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hybp_i);
            vlSelfRef.__VdlyCommitQueuetb_program__DOT__uut__DOT__core__DOT__hybp_local_pht.enqueue(0U, (IData)(__VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__hybp_local_pht__v0));
            __VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__hybp_global_pht__v0 
                = (0x000000ffU & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hybp_i);
            vlSelfRef.__VdlyCommitQueuetb_program__DOT__uut__DOT__core__DOT__hybp_global_pht.enqueue(0U, (IData)(__VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__hybp_global_pht__v0));
            __VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__hybp_choice_pht__v0 
                = (0x000000ffU & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hybp_i);
            vlSelfRef.__VdlyCommitQueuetb_program__DOT__uut__DOT__core__DOT__hybp_choice_pht.enqueue(1U, (IData)(__VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__hybp_choice_pht__v0));
            __VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__btb_valid__v0 
                = (0x000000ffU & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hybp_i);
            vlSelfRef.__VdlyCommitQueuetb_program__DOT__uut__DOT__core__DOT__btb_valid.enqueue(0U, (IData)(__VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__btb_valid__v0));
            __VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__btb_tag__v0 
                = (0x000000ffU & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hybp_i);
            vlSelfRef.__VdlyCommitQueuetb_program__DOT__uut__DOT__core__DOT__btb_tag.enqueue(0U, (IData)(__VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__btb_tag__v0));
            __VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__btb_target__v0 
                = (0x000000ffU & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hybp_i);
            vlSelfRef.__VdlyCommitQueuetb_program__DOT__uut__DOT__core__DOT__btb_target.enqueue(0U, (IData)(__VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__btb_target__v0));
            vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hybp_i 
                = ((IData)(1U) + vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hybp_i);
        }
    } else if ((((~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__pipe_halt)) 
                 & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_valid0)) 
                & (~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__stall_if)))) {
        if (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_branch0) {
            __VdlyVal__tb_program__DOT__uut__DOT__core__DOT__hybp_local_pht__v1 
                = ((2U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hybp_local_pht
                    [vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_local_idx0])
                    ? ((1U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hybp_local_pht
                        [vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_local_idx0])
                        ? ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__s0_id_branch_taken)
                            ? 3U : 2U) : ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__s0_id_branch_taken)
                                           ? 3U : 1U))
                    : ((1U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hybp_local_pht
                        [vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_local_idx0])
                        ? ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__s0_id_branch_taken)
                            ? 2U : 0U) : ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__s0_id_branch_taken)
                                           ? 1U : 0U)));
            __VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__hybp_local_pht__v1 
                = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_local_idx0;
            vlSelfRef.__VdlyCommitQueuetb_program__DOT__uut__DOT__core__DOT__hybp_local_pht.enqueue(__VdlyVal__tb_program__DOT__uut__DOT__core__DOT__hybp_local_pht__v1, (IData)(__VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__hybp_local_pht__v1));
            __VdlyVal__tb_program__DOT__uut__DOT__core__DOT__hybp_global_pht__v1 
                = ((2U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hybp_global_pht
                    [vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_global_idx0])
                    ? ((1U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hybp_global_pht
                        [vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_global_idx0])
                        ? ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__s0_id_branch_taken)
                            ? 3U : 2U) : ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__s0_id_branch_taken)
                                           ? 3U : 1U))
                    : ((1U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hybp_global_pht
                        [vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_global_idx0])
                        ? ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__s0_id_branch_taken)
                            ? 2U : 0U) : ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__s0_id_branch_taken)
                                           ? 1U : 0U)));
            __VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__hybp_global_pht__v1 
                = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_global_idx0;
            vlSelfRef.__VdlyCommitQueuetb_program__DOT__uut__DOT__core__DOT__hybp_global_pht.enqueue(__VdlyVal__tb_program__DOT__uut__DOT__core__DOT__hybp_global_pht__v1, (IData)(__VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__hybp_global_pht__v1));
            if (((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_global_pred_taken0) 
                 != (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_local_pred_taken0))) {
                __VdlyVal__tb_program__DOT__uut__DOT__core__DOT__hybp_choice_pht__v1 
                    = (((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_global_pred_taken0) 
                        == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__s0_id_branch_taken))
                        ? ((2U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hybp_choice_pht
                            [vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_global_idx0])
                            ? 3U : ((1U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hybp_choice_pht
                                     [vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_global_idx0])
                                     ? 2U : 1U)) : 
                       ((2U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hybp_choice_pht
                         [vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_global_idx0])
                         ? ((1U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hybp_choice_pht
                             [vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_global_idx0])
                             ? 2U : 1U) : 0U));
                __VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__hybp_choice_pht__v1 
                    = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_global_idx0;
                vlSelfRef.__VdlyCommitQueuetb_program__DOT__uut__DOT__core__DOT__hybp_choice_pht.enqueue(__VdlyVal__tb_program__DOT__uut__DOT__core__DOT__hybp_choice_pht__v1, (IData)(__VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__hybp_choice_pht__v1));
            }
            if (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__s0_id_branch_taken) {
                __VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__btb_valid__v1 
                    = (0x000000ffU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_pc0 
                                      >> 2U));
                vlSelfRef.__VdlyCommitQueuetb_program__DOT__uut__DOT__core__DOT__btb_valid.enqueue(1U, (IData)(__VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__btb_valid__v1));
                __VdlyVal__tb_program__DOT__uut__DOT__core__DOT__btb_tag__v1 
                    = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_pc0;
                __VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__btb_tag__v1 
                    = (0x000000ffU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_pc0 
                                      >> 2U));
                vlSelfRef.__VdlyCommitQueuetb_program__DOT__uut__DOT__core__DOT__btb_tag.enqueue(__VdlyVal__tb_program__DOT__uut__DOT__core__DOT__btb_tag__v1, (IData)(__VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__btb_tag__v1));
                __VdlyVal__tb_program__DOT__uut__DOT__core__DOT__btb_target__v1 
                    = (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_pc0 
                       + vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ig0__DOT__imm);
                __VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__btb_target__v1 
                    = (0x000000ffU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_pc0 
                                      >> 2U));
                vlSelfRef.__VdlyCommitQueuetb_program__DOT__uut__DOT__core__DOT__btb_target.enqueue(__VdlyVal__tb_program__DOT__uut__DOT__core__DOT__btb_target__v1, (IData)(__VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__btb_target__v1));
            }
        } else if (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_jal0) {
            __VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__btb_valid__v2 
                = (0x000000ffU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_pc0 
                                  >> 2U));
            vlSelfRef.__VdlyCommitQueuetb_program__DOT__uut__DOT__core__DOT__btb_valid.enqueue(1U, (IData)(__VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__btb_valid__v2));
            __VdlyVal__tb_program__DOT__uut__DOT__core__DOT__btb_tag__v2 
                = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_pc0;
            __VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__btb_tag__v2 
                = (0x000000ffU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_pc0 
                                  >> 2U));
            vlSelfRef.__VdlyCommitQueuetb_program__DOT__uut__DOT__core__DOT__btb_tag.enqueue(__VdlyVal__tb_program__DOT__uut__DOT__core__DOT__btb_tag__v2, (IData)(__VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__btb_tag__v2));
            __VdlyVal__tb_program__DOT__uut__DOT__core__DOT__btb_target__v2 
                = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_jal_target0;
            __VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__btb_target__v2 
                = (0x000000ffU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_pc0 
                                  >> 2U));
            vlSelfRef.__VdlyCommitQueuetb_program__DOT__uut__DOT__core__DOT__btb_target.enqueue(__VdlyVal__tb_program__DOT__uut__DOT__core__DOT__btb_target__v2, (IData)(__VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__btb_target__v2));
        } else if (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_jalr0) {
            __VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__btb_valid__v3 
                = (0x000000ffU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_pc0 
                                  >> 2U));
            vlSelfRef.__VdlyCommitQueuetb_program__DOT__uut__DOT__core__DOT__btb_valid.enqueue(1U, (IData)(__VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__btb_valid__v3));
            __VdlyVal__tb_program__DOT__uut__DOT__core__DOT__btb_tag__v3 
                = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_pc0;
            __VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__btb_tag__v3 
                = (0x000000ffU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_pc0 
                                  >> 2U));
            vlSelfRef.__VdlyCommitQueuetb_program__DOT__uut__DOT__core__DOT__btb_tag.enqueue(__VdlyVal__tb_program__DOT__uut__DOT__core__DOT__btb_tag__v3, (IData)(__VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__btb_tag__v3));
            __VdlyVal__tb_program__DOT__uut__DOT__core__DOT__btb_target__v3 
                = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_jalr_target0;
            __VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__btb_target__v3 
                = (0x000000ffU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_pc0 
                                  >> 2U));
            vlSelfRef.__VdlyCommitQueuetb_program__DOT__uut__DOT__core__DOT__btb_target.enqueue(__VdlyVal__tb_program__DOT__uut__DOT__core__DOT__btb_target__v3, (IData)(__VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__btb_target__v3));
        }
    }
    if (((IData)(vlSelfRef.tb_program__DOT__rst) | (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__flush_ex))) {
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_branch0 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_branch1 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_local_pred_taken0 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_global_pred_taken0 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_global_idx0 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_local_idx0 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_csr_read1 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_alu_op1 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_pred_taken0 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_jal1 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_jalr1 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_alu_src1 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_auipc1 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_imm1 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_is_lui1 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_funct7_1 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_is_rtype1 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_pc1 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_csr_read0 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_alu_op0 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_jal0 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_jalr0 = 0U;
    } else if ((1U & (~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__pipe_halt)))) {
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_branch0 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_branch1 
            = ((~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__squash_s1)) 
               & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_branch1));
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_local_pred_taken0 
            = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_local_pred_taken0;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_global_pred_taken0 
            = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_global_pred_taken0;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_global_idx0 
            = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_global_idx0;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_local_idx0 
            = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_local_idx0;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_csr_read1 
            = ((~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__squash_s1)) 
               & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_csr_read1));
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_alu_op1 
            = ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__squash_s1)
                ? 0U : (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_alu_op1));
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_pred_taken0 
            = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_pred_taken0;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_jal1 
            = ((~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__squash_s1)) 
               & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_jal1));
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_jalr1 
            = ((~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__squash_s1)) 
               & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_jalr1));
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_alu_src1 
            = ((~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__squash_s1)) 
               & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_alu_src1));
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_auipc1 
            = ((~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__squash_s1)) 
               & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_auipc1));
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_imm1 
            = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ig1__DOT__imm;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_is_lui1 
            = ((~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__squash_s1)) 
               & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_is_lui1));
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_funct7_1 
            = (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
               >> 0x00000019U);
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_is_rtype1 
            = ((~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__squash_s1)) 
               & (0x33U == (0x0000007fU & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1)));
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_pc1 
            = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_pc1;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_csr_read0 
            = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_csr_read0;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_alu_op0 
            = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_alu_op0;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_jal0 
            = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_jal0;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_jalr0 
            = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_jalr0;
    }
    if (vlSelfRef.tb_program__DOT__rst) {
        __Vdly__tb_program__DOT__uut__DOT__core__DOT__hybp_ghr = 0U;
        __VdlySet__tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr__v0 = 1U;
        __Vdly__tb_program__DOT__uut__DOT__core__DOT__ras_top_ptr = 0U;
        __Vdly__tb_program__DOT__uut__DOT__core__DOT__ras_count = 0U;
        __VdlySet__tb_program__DOT__uut__DOT__core__DOT__ras_stack__v0 = 1U;
        __VdlySet__tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr__v0 = 1U;
        __VdlySet__tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf__v0 = 1U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_pred_target0 = 0U;
    } else {
        if ((((~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__pipe_halt)) 
              & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_valid0)) 
             & (~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__stall_if)))) {
            if (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_branch0) {
                __Vdly__tb_program__DOT__uut__DOT__core__DOT__hybp_ghr 
                    = ((0x000000feU & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hybp_ghr) 
                                       << 1U)) | (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__s0_id_branch_taken));
            }
            if (((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_is_ret0) 
                 & (0U != (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_count)))) {
                if ((1U == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_count))) {
                    __Vdly__tb_program__DOT__uut__DOT__core__DOT__ras_count = 0U;
                } else {
                    __Vdly__tb_program__DOT__uut__DOT__core__DOT__ras_count 
                        = (0x0000001fU & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_count) 
                                          - (IData)(1U)));
                    __Vdly__tb_program__DOT__uut__DOT__core__DOT__ras_top_ptr 
                        = (0x0000000fU & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_top_ptr) 
                                          - (IData)(1U)));
                }
            }
            if ((((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_13) 
                  & ((~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_is_ret0)) 
                     & ((1U == (0x0000001fU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                               >> 7U))) 
                        | (5U == (0x0000001fU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                                                 >> 7U)))))) 
                 & (0x10U > (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_count)))) {
                if ((0U == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_count))) {
                    __Vdly__tb_program__DOT__uut__DOT__core__DOT__ras_top_ptr = 0U;
                    __VdlyVal__tb_program__DOT__uut__DOT__core__DOT__ras_stack__v16 
                        = ((IData)(4U) + vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_pc0);
                    __VdlySet__tb_program__DOT__uut__DOT__core__DOT__ras_stack__v16 = 1U;
                } else {
                    __Vdly__tb_program__DOT__uut__DOT__core__DOT__ras_top_ptr 
                        = (0x0000000fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_top_ptr)));
                    __VdlyVal__tb_program__DOT__uut__DOT__core__DOT__ras_stack__v17 
                        = ((IData)(4U) + vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_pc0);
                    __VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__ras_stack__v17 
                        = (0x0000000fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_top_ptr)));
                    __VdlySet__tb_program__DOT__uut__DOT__core__DOT__ras_stack__v17 = 1U;
                }
                __Vdly__tb_program__DOT__uut__DOT__core__DOT__ras_count 
                    = (0x0000001fU & ((IData)(1U) + (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_count)));
            }
        }
        if (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_csr_write1) {
            __VdlyVal__tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr__v12 
                = ((1U == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_funct3_1))
                    ? vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc1__DOT__rs1
                    : ((2U == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_funct3_1))
                        ? (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr
                           [(0x0000000fU & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_csr1))] 
                           | vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc1__DOT__rs1)
                        : ((3U == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_funct3_1))
                            ? (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr
                               [(0x0000000fU & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_csr1))] 
                               & (~ vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc1__DOT__rs1))
                            : vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc1__DOT__rs1)));
            __VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr__v12 
                = (0x0000000fU & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_csr1));
            __VdlySet__tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr__v12 = 1U;
        }
        if (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_csr_write0) {
            __VdlyVal__tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr__v12 
                = ((1U == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_funct3_0))
                    ? vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc0__DOT__rs1
                    : ((2U == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_funct3_0))
                        ? (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr
                           [(0x0000000fU & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_csr0))] 
                           | vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc0__DOT__rs1)
                        : ((3U == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_funct3_0))
                            ? (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr
                               [(0x0000000fU & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_csr0))] 
                               & (~ vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc0__DOT__rs1))
                            : vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc0__DOT__rs1)));
            __VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr__v12 
                = (0x0000000fU & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_csr0));
            __VdlySet__tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr__v12 = 1U;
        }
        if (((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_reg_write0) 
             & (0U != (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_rd0)))) {
            __VdlyVal__tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf__v32 
                = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__wd0;
            __VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf__v32 
                = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_rd0;
            __VdlySet__tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf__v32 = 1U;
        }
        if (((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_reg_write1) 
             & (0U != (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_rd1)))) {
            __VdlyVal__tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf__v33 
                = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__wd1;
            __VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf__v33 
                = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_rd1;
            __VdlySet__tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf__v33 = 1U;
        }
        if (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__flush_id) {
            vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_pred_target0 = 0U;
        } else if ((1U & ((~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__stall_if)) 
                          & (~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__pipe_halt))))) {
            vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_pred_target0 
                = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_pred_target0;
        }
    }
    vlSelfRef.__VdlyCommitQueuetb_program__DOT__uut__DOT__core__DOT__btb_target.commit(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__btb_target);
    vlSelfRef.__VdlyCommitQueuetb_program__DOT__uut__DOT__core__DOT__hybp_choice_pht.commit(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hybp_choice_pht);
    vlSelfRef.__VdlyCommitQueuetb_program__DOT__uut__DOT__core__DOT__hybp_local_pht.commit(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hybp_local_pht);
    vlSelfRef.__VdlyCommitQueuetb_program__DOT__uut__DOT__core__DOT__hybp_global_pht.commit(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hybp_global_pht);
    vlSelfRef.__VdlyCommitQueuetb_program__DOT__uut__DOT__core__DOT__btb_valid.commit(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__btb_valid);
    vlSelfRef.__VdlyCommitQueuetb_program__DOT__uut__DOT__core__DOT__btb_tag.commit(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__btb_tag);
    if (((IData)(vlSelfRef.tb_program__DOT__rst) | (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__flush_ex))) {
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rs2_1 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rs1_1 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_is_rtype0 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_funct7_0 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_alu_src0 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_auipc0 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_imm0 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rd2_0 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rd1_0 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_is_lui0 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_pc0 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rs2_0 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rs1_0 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rd2_1 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rd1_1 = 0U;
    } else if ((1U & (~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__pipe_halt)))) {
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rs2_1 
            = (0x0000001fU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                              >> 0x00000014U));
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rs1_1 
            = (0x0000001fU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                              >> 0x0000000fU));
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_is_rtype0 
            = (0x33U == (0x0000007fU & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0));
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_funct7_0 
            = (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
               >> 0x00000019U);
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_alu_src0 
            = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_alu_src0;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_auipc0 
            = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_auipc0;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_imm0 
            = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ig0__DOT__imm;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rd2_0 
            = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_rd2_0;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rd1_0 
            = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_rd1_0;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_is_lui0 
            = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_is_lui0;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_pc0 
            = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_pc0;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rs2_0 
            = (0x0000001fU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                              >> 0x00000014U));
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rs1_0 
            = (0x0000001fU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                              >> 0x0000000fU));
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rd2_1 
            = (((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_4) 
                & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_rd1) 
                   == (0x0000001fU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                      >> 0x00000014U))))
                ? vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__wd1
                : (((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_5) 
                    & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_rd0) 
                       == (0x0000001fU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                          >> 0x00000014U))))
                    ? vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__wd0
                    : ((0U == (0x0000001fU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                              >> 0x00000014U)))
                        ? 0U : vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                       [(0x0000001fU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                        >> 0x00000014U))])));
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rd1_1 
            = (((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_4) 
                & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_rd1) 
                   == (0x0000001fU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                      >> 0x0000000fU))))
                ? vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__wd1
                : (((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_5) 
                    & ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_rd0) 
                       == (0x0000001fU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                          >> 0x0000000fU))))
                    ? vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__wd0
                    : ((0U == (0x0000001fU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                              >> 0x0000000fU)))
                        ? 0U : vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf
                       [(0x0000001fU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                        >> 0x0000000fU))])));
    }
    if (vlSelfRef.tb_program__DOT__rst) {
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_mem0 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_mem1 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_wb1 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_wb0 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_local_pred_taken0 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_global_pred_taken0 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_global_idx0 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_local_idx0 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_pred_taken0 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_pc1 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_pc0 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_rd0 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_rd1 = 0U;
    } else {
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_mem0 
            = vlSelfRef.tb_program__DOT__uut__DOT__mem_rdata0;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_mem1 
            = vlSelfRef.tb_program__DOT__uut__DOT__mem_rdata1;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_wb1 
            = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_wb1;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_wb0 
            = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_wb0;
        if (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__flush_id) {
            vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_local_pred_taken0 = 0U;
            vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_global_pred_taken0 = 0U;
            vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_global_idx0 = 0U;
            vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_local_idx0 = 0U;
            vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_pred_taken0 = 0U;
            vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_pc1 = 0U;
            vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_pc0 = 0U;
        } else if ((1U & ((~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__stall_if)) 
                          & (~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__pipe_halt))))) {
            vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_local_pred_taken0 
                = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_local_pred_taken0;
            vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_global_pred_taken0 
                = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_global_pred_taken0;
            vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_global_idx0 
                = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_global_idx0;
            vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_local_idx0 
                = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_pred_pc_idx;
            vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_pred_taken0 
                = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_pred_taken0;
            vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_pc1 
                = ((IData)(4U) + vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__pc_current);
            vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_pc0 
                = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__pc_current;
        }
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_rd0 
            = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_rd0;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_rd1 
            = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_rd1;
    }
    if (((IData)(vlSelfRef.tb_program__DOT__rst) | (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__flush_ex))) {
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_csr_write1 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_csr1 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_csr_write0 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_csr0 = 0U;
    } else if ((1U & (~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__pipe_halt)))) {
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_csr_write1 
            = ((~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__squash_s1)) 
               & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_csr_write1));
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_csr1 
            = (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
               >> 0x00000014U);
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_csr_write0 
            = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_csr_write0;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_csr0 
            = (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
               >> 0x00000014U);
    }
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_ecall1 
        = ((1U & (~ (IData)(vlSelfRef.tb_program__DOT__rst))) 
           && (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_ecall1));
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_ecall0 
        = ((1U & (~ (IData)(vlSelfRef.tb_program__DOT__rst))) 
           && (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_ecall0));
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_mem_to_reg1 
        = ((1U & (~ (IData)(vlSelfRef.tb_program__DOT__rst))) 
           && (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_mem_to_reg1));
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_mem_to_reg0 
        = ((1U & (~ (IData)(vlSelfRef.tb_program__DOT__rst))) 
           && (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_mem_to_reg0));
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hybp_ghr 
        = __Vdly__tb_program__DOT__uut__DOT__core__DOT__hybp_ghr;
    if (__VdlySet__tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr__v0) {
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr[0U] = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr[1U] = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr[2U] = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr[3U] = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr[4U] = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr[5U] = 0x00000100U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr[6U] = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr[7U] = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr[8U] = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr[9U] = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr[0x0aU] = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr[0x0bU] = 0U;
    }
    if (__VdlySet__tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr__v12) {
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr[__VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr__v12] 
            = __VdlyVal__tb_program__DOT__uut__DOT__core__DOT__csr1__DOT__csr__v12;
    }
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_top_ptr 
        = __Vdly__tb_program__DOT__uut__DOT__core__DOT__ras_top_ptr;
    if (__VdlySet__tb_program__DOT__uut__DOT__core__DOT__ras_stack__v0) {
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_stack[0U] = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_stack[1U] = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_stack[2U] = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_stack[3U] = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_stack[4U] = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_stack[5U] = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_stack[6U] = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_stack[7U] = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_stack[8U] = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_stack[9U] = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_stack[0x0aU] = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_stack[0x0bU] = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_stack[0x0cU] = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_stack[0x0dU] = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_stack[0x0eU] = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_stack[0x0fU] = 0U;
    }
    if (__VdlySet__tb_program__DOT__uut__DOT__core__DOT__ras_stack__v16) {
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_stack[0U] 
            = __VdlyVal__tb_program__DOT__uut__DOT__core__DOT__ras_stack__v16;
    }
    if (__VdlySet__tb_program__DOT__uut__DOT__core__DOT__ras_stack__v17) {
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_stack[__VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__ras_stack__v17] 
            = __VdlyVal__tb_program__DOT__uut__DOT__core__DOT__ras_stack__v17;
    }
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ras_count 
        = __Vdly__tb_program__DOT__uut__DOT__core__DOT__ras_count;
    if (__VdlySet__tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr__v0) {
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr[0U] = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr[1U] = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr[2U] = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr[3U] = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr[4U] = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr[5U] = 0x00000100U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr[6U] = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr[7U] = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr[8U] = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr[9U] = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr[0x0aU] = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr[0x0bU] = 0U;
    }
    if (__VdlySet__tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr__v12) {
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr[__VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr__v12] 
            = __VdlyVal__tb_program__DOT__uut__DOT__core__DOT__csr0__DOT__csr__v12;
    }
    if (__VdlySet__tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf__v0) {
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[0U] = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[1U] = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[2U] = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[3U] = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[4U] = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[5U] = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[6U] = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[7U] = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[8U] = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[9U] = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[0x0aU] = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[0x0bU] = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[0x0cU] = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[0x0dU] = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[0x0eU] = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[0x0fU] = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[0x10U] = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[0x11U] = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[0x12U] = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[0x13U] = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[0x14U] = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[0x15U] = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[0x16U] = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[0x17U] = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[0x18U] = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[0x19U] = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[0x1aU] = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[0x1bU] = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[0x1cU] = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[0x1dU] = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[0x1eU] = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[0x1fU] = 0U;
    }
    if (__VdlySet__tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf__v32) {
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[__VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf__v32] 
            = __VdlyVal__tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf__v32;
    }
    if (__VdlySet__tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf__v33) {
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf[__VdlyDim0__tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf__v33] 
            = __VdlyVal__tb_program__DOT__uut__DOT__core__DOT__regs__DOT__rf__v33;
    }
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_reg_write1 
        = ((1U & (~ (IData)(vlSelfRef.tb_program__DOT__rst))) 
           && (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_reg_write1));
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_reg_write0 
        = ((1U & (~ (IData)(vlSelfRef.tb_program__DOT__rst))) 
           && (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_reg_write0));
    vlSelfRef.__VdfgRegularize_he50b618e_0_2 = ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_jal1) 
                                                | (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_jalr1));
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_15 
        = (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_imm1 
           + vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_pc1);
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__wd1 
        = ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_mem_to_reg1)
            ? vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_mem1
            : vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_wb1);
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__regs__DOT__wd0 
        = ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_mem_to_reg0)
            ? vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_mem0
            : vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_wb0);
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_5 
        = ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_reg_write0) 
           & (0U != (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_rd0)));
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_4 
        = ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_reg_write1) 
           & (0U != (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_rd1)));
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
}

void Vtb_program___024root___nba_sequent__TOP__1(Vtb_program___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_program___024root___nba_sequent__TOP__1\n"); );
    Vtb_program__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __Vdly__tb_program__DOT__cycle_count;
    __Vdly__tb_program__DOT__cycle_count = 0;
    IData/*31:0*/ __Vdly__tb_program__DOT__instret_count;
    __Vdly__tb_program__DOT__instret_count = 0;
    CData/*7:0*/ __VdlyVal__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v0;
    __VdlyVal__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v0 = 0;
    SData/*10:0*/ __VdlyDim0__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v0;
    __VdlyDim0__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v0 = 0;
    CData/*0:0*/ __VdlySet__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v0;
    __VdlySet__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v0 = 0;
    CData/*7:0*/ __VdlyVal__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v1;
    __VdlyVal__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v1 = 0;
    SData/*10:0*/ __VdlyDim0__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v1;
    __VdlyDim0__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v1 = 0;
    CData/*0:0*/ __VdlySet__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v1;
    __VdlySet__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v1 = 0;
    CData/*7:0*/ __VdlyVal__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v2;
    __VdlyVal__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v2 = 0;
    SData/*10:0*/ __VdlyDim0__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v2;
    __VdlyDim0__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v2 = 0;
    CData/*0:0*/ __VdlySet__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v2;
    __VdlySet__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v2 = 0;
    CData/*7:0*/ __VdlyVal__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v3;
    __VdlyVal__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v3 = 0;
    SData/*10:0*/ __VdlyDim0__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v3;
    __VdlyDim0__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v3 = 0;
    CData/*0:0*/ __VdlySet__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v3;
    __VdlySet__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v3 = 0;
    SData/*15:0*/ __VdlyVal__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v4;
    __VdlyVal__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v4 = 0;
    SData/*10:0*/ __VdlyDim0__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v4;
    __VdlyDim0__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v4 = 0;
    CData/*0:0*/ __VdlySet__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v4;
    __VdlySet__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v4 = 0;
    SData/*15:0*/ __VdlyVal__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v5;
    __VdlyVal__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v5 = 0;
    SData/*10:0*/ __VdlyDim0__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v5;
    __VdlyDim0__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v5 = 0;
    CData/*0:0*/ __VdlySet__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v5;
    __VdlySet__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v5 = 0;
    IData/*31:0*/ __VdlyVal__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v6;
    __VdlyVal__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v6 = 0;
    SData/*10:0*/ __VdlyDim0__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v6;
    __VdlyDim0__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v6 = 0;
    CData/*0:0*/ __VdlySet__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v6;
    __VdlySet__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v6 = 0;
    CData/*7:0*/ __VdlyVal__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v7;
    __VdlyVal__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v7 = 0;
    SData/*10:0*/ __VdlyDim0__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v7;
    __VdlyDim0__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v7 = 0;
    CData/*0:0*/ __VdlySet__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v7;
    __VdlySet__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v7 = 0;
    CData/*7:0*/ __VdlyVal__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v8;
    __VdlyVal__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v8 = 0;
    SData/*10:0*/ __VdlyDim0__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v8;
    __VdlyDim0__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v8 = 0;
    CData/*0:0*/ __VdlySet__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v8;
    __VdlySet__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v8 = 0;
    CData/*7:0*/ __VdlyVal__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v9;
    __VdlyVal__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v9 = 0;
    SData/*10:0*/ __VdlyDim0__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v9;
    __VdlyDim0__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v9 = 0;
    CData/*0:0*/ __VdlySet__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v9;
    __VdlySet__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v9 = 0;
    CData/*7:0*/ __VdlyVal__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v10;
    __VdlyVal__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v10 = 0;
    SData/*10:0*/ __VdlyDim0__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v10;
    __VdlyDim0__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v10 = 0;
    CData/*0:0*/ __VdlySet__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v10;
    __VdlySet__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v10 = 0;
    SData/*15:0*/ __VdlyVal__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v11;
    __VdlyVal__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v11 = 0;
    SData/*10:0*/ __VdlyDim0__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v11;
    __VdlyDim0__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v11 = 0;
    CData/*0:0*/ __VdlySet__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v11;
    __VdlySet__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v11 = 0;
    SData/*15:0*/ __VdlyVal__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v12;
    __VdlyVal__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v12 = 0;
    SData/*10:0*/ __VdlyDim0__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v12;
    __VdlyDim0__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v12 = 0;
    CData/*0:0*/ __VdlySet__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v12;
    __VdlySet__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v12 = 0;
    IData/*31:0*/ __VdlyVal__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v13;
    __VdlyVal__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v13 = 0;
    SData/*10:0*/ __VdlyDim0__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v13;
    __VdlyDim0__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v13 = 0;
    CData/*0:0*/ __VdlySet__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v13;
    __VdlySet__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v13 = 0;
    // Body
    __Vdly__tb_program__DOT__cycle_count = vlSelfRef.tb_program__DOT__cycle_count;
    __Vdly__tb_program__DOT__instret_count = vlSelfRef.tb_program__DOT__instret_count;
    __VdlySet__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v0 = 0U;
    __VdlySet__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v1 = 0U;
    __VdlySet__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v2 = 0U;
    __VdlySet__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v3 = 0U;
    __VdlySet__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v4 = 0U;
    __VdlySet__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v5 = 0U;
    __VdlySet__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v6 = 0U;
    __VdlySet__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v7 = 0U;
    __VdlySet__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v8 = 0U;
    __VdlySet__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v9 = 0U;
    __VdlySet__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v10 = 0U;
    __VdlySet__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v11 = 0U;
    __VdlySet__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v12 = 0U;
    __VdlySet__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v13 = 0U;
    if (vlSelfRef.tb_program__DOT__rst) {
        __Vdly__tb_program__DOT__cycle_count = 0U;
        __Vdly__tb_program__DOT__instret_count = 0U;
    } else {
        __Vdly__tb_program__DOT__cycle_count = ((IData)(1U) 
                                                + vlSelfRef.tb_program__DOT__cycle_count);
        __Vdly__tb_program__DOT__instret_count = ((vlSelfRef.tb_program__DOT__instret_count 
                                                   + 
                                                   ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_valid0)
                                                     ? 1U
                                                     : 0U)) 
                                                  + 
                                                  ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_valid1)
                                                    ? 1U
                                                    : 0U));
        if (VL_UNLIKELY((((IData)(vlSelfRef.tb_program__DOT__progress_enable) 
                          & (0U == VL_MODDIVS_III(32, vlSelfRef.tb_program__DOT__cycle_count, vlSelfRef.tb_program__DOT__progress_interval)))))) {
            VL_WRITEF_NX("[PROGRESS] cyc=%0d pc=%08x halted=%0#\n",0,
                         32,vlSelfRef.tb_program__DOT__cycle_count,
                         32,vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__pc_current,
                         1,(((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_halt0) 
                             & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_valid0)) 
                            | ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_halt1) 
                               & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_valid1))));
        }
    }
    if (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_mem_write0) {
        if ((0U == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_funct3_0))) {
            if ((2U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu0)) {
                if ((1U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu0)) {
                    __VdlyVal__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v0 
                        = (0x000000ffU & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_rs2_0);
                    __VdlyDim0__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v0 
                        = (0x000007ffU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu0 
                                          >> 2U));
                    __VdlySet__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v0 = 1U;
                } else {
                    __VdlyVal__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v1 
                        = (0x000000ffU & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_rs2_0);
                    __VdlyDim0__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v1 
                        = (0x000007ffU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu0 
                                          >> 2U));
                    __VdlySet__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v1 = 1U;
                }
            } else if ((1U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu0)) {
                __VdlyVal__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v2 
                    = (0x000000ffU & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_rs2_0);
                __VdlyDim0__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v2 
                    = (0x000007ffU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu0 
                                      >> 2U));
                __VdlySet__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v2 = 1U;
            } else {
                __VdlyVal__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v3 
                    = (0x000000ffU & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_rs2_0);
                __VdlyDim0__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v3 
                    = (0x000007ffU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu0 
                                      >> 2U));
                __VdlySet__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v3 = 1U;
            }
        } else if ((1U == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_funct3_0))) {
            if ((2U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu0)) {
                if ((2U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu0)) {
                    __VdlyVal__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v4 
                        = (0x0000ffffU & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_rs2_0);
                    __VdlyDim0__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v4 
                        = (0x000007ffU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu0 
                                          >> 2U));
                    __VdlySet__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v4 = 1U;
                }
            } else {
                __VdlyVal__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v5 
                    = (0x0000ffffU & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_rs2_0);
                __VdlyDim0__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v5 
                    = (0x000007ffU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu0 
                                      >> 2U));
                __VdlySet__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v5 = 1U;
            }
        } else if ((2U == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_funct3_0))) {
            __VdlyVal__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v6 
                = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_rs2_0;
            __VdlyDim0__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v6 
                = (0x000007ffU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu0 
                                  >> 2U));
            __VdlySet__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v6 = 1U;
        }
    }
    if (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_mem_write1) {
        if ((0U == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_funct3_1))) {
            if ((2U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu1)) {
                if ((1U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu1)) {
                    __VdlyVal__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v7 
                        = (0x000000ffU & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_rs2_1);
                    __VdlyDim0__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v7 
                        = (0x000007ffU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu1 
                                          >> 2U));
                    __VdlySet__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v7 = 1U;
                } else {
                    __VdlyVal__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v8 
                        = (0x000000ffU & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_rs2_1);
                    __VdlyDim0__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v8 
                        = (0x000007ffU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu1 
                                          >> 2U));
                    __VdlySet__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v8 = 1U;
                }
            } else if ((1U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu1)) {
                __VdlyVal__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v9 
                    = (0x000000ffU & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_rs2_1);
                __VdlyDim0__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v9 
                    = (0x000007ffU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu1 
                                      >> 2U));
                __VdlySet__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v9 = 1U;
            } else {
                __VdlyVal__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v10 
                    = (0x000000ffU & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_rs2_1);
                __VdlyDim0__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v10 
                    = (0x000007ffU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu1 
                                      >> 2U));
                __VdlySet__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v10 = 1U;
            }
        } else if ((1U == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_funct3_1))) {
            if ((2U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu1)) {
                if ((2U & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu1)) {
                    __VdlyVal__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v11 
                        = (0x0000ffffU & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_rs2_1);
                    __VdlyDim0__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v11 
                        = (0x000007ffU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu1 
                                          >> 2U));
                    __VdlySet__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v11 = 1U;
                }
            } else {
                __VdlyVal__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v12 
                    = (0x0000ffffU & vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_rs2_1);
                __VdlyDim0__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v12 
                    = (0x000007ffU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu1 
                                      >> 2U));
                __VdlySet__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v12 = 1U;
            }
        } else if ((2U == (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_funct3_1))) {
            __VdlyVal__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v13 
                = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_rs2_1;
            __VdlyDim0__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v13 
                = (0x000007ffU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu1 
                                  >> 2U));
            __VdlySet__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v13 = 1U;
        }
    }
    vlSelfRef.tb_program__DOT__cycle_count = __Vdly__tb_program__DOT__cycle_count;
    vlSelfRef.tb_program__DOT__instret_count = __Vdly__tb_program__DOT__instret_count;
    if (__VdlySet__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v0) {
        vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem[__VdlyDim0__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v0] 
            = ((0x00ffffffU & vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                [__VdlyDim0__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v0]) 
               | ((IData)(__VdlyVal__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v0) 
                  << 0x00000018U));
    }
    if (__VdlySet__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v1) {
        vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem[__VdlyDim0__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v1] 
            = ((0xff00ffffU & vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                [__VdlyDim0__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v1]) 
               | ((IData)(__VdlyVal__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v1) 
                  << 0x00000010U));
    }
    if (__VdlySet__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v2) {
        vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem[__VdlyDim0__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v2] 
            = ((0xffff00ffU & vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                [__VdlyDim0__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v2]) 
               | ((IData)(__VdlyVal__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v2) 
                  << 8U));
    }
    if (__VdlySet__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v3) {
        vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem[__VdlyDim0__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v3] 
            = ((0xffffff00U & vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                [__VdlyDim0__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v3]) 
               | (IData)(__VdlyVal__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v3));
    }
    if (__VdlySet__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v4) {
        vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem[__VdlyDim0__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v4] 
            = ((0x0000ffffU & vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                [__VdlyDim0__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v4]) 
               | ((IData)(__VdlyVal__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v4) 
                  << 0x00000010U));
    }
    if (__VdlySet__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v5) {
        vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem[__VdlyDim0__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v5] 
            = ((0xffff0000U & vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                [__VdlyDim0__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v5]) 
               | (IData)(__VdlyVal__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v5));
    }
    if (__VdlySet__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v6) {
        vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem[__VdlyDim0__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v6] 
            = __VdlyVal__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v6;
    }
    if (__VdlySet__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v7) {
        vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem[__VdlyDim0__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v7] 
            = ((0x00ffffffU & vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                [__VdlyDim0__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v7]) 
               | ((IData)(__VdlyVal__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v7) 
                  << 0x00000018U));
    }
    if (__VdlySet__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v8) {
        vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem[__VdlyDim0__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v8] 
            = ((0xff00ffffU & vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                [__VdlyDim0__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v8]) 
               | ((IData)(__VdlyVal__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v8) 
                  << 0x00000010U));
    }
    if (__VdlySet__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v9) {
        vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem[__VdlyDim0__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v9] 
            = ((0xffff00ffU & vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                [__VdlyDim0__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v9]) 
               | ((IData)(__VdlyVal__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v9) 
                  << 8U));
    }
    if (__VdlySet__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v10) {
        vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem[__VdlyDim0__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v10] 
            = ((0xffffff00U & vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                [__VdlyDim0__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v10]) 
               | (IData)(__VdlyVal__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v10));
    }
    if (__VdlySet__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v11) {
        vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem[__VdlyDim0__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v11] 
            = ((0x0000ffffU & vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                [__VdlyDim0__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v11]) 
               | ((IData)(__VdlyVal__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v11) 
                  << 0x00000010U));
    }
    if (__VdlySet__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v12) {
        vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem[__VdlyDim0__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v12] 
            = ((0xffff0000U & vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem
                [__VdlyDim0__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v12]) 
               | (IData)(__VdlyVal__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v12));
    }
    if (__VdlySet__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v13) {
        vlSelfRef.tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem[__VdlyDim0__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v13] 
            = __VdlyVal__tb_program__DOT__uut__DOT__mem__DOT__dmem__DOT__mem__v13;
    }
}

extern const VlUnpacked<CData/*4:0*/, 256> Vtb_program__ConstPool__TABLE_hdb5c2fe0_0;

void Vtb_program___024root___nba_sequent__TOP__2(Vtb_program___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_program___024root___nba_sequent__TOP__2\n"); );
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
    // Body
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_halt0 
        = ((1U & (~ (IData)(vlSelfRef.tb_program__DOT__rst))) 
           && (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_halt0));
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_halt1 
        = ((1U & (~ (IData)(vlSelfRef.tb_program__DOT__rst))) 
           && (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_halt1));
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_valid1 
        = ((1U & (~ (IData)(vlSelfRef.tb_program__DOT__rst))) 
           && (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_valid1));
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__mem_wb_valid0 
        = ((1U & (~ (IData)(vlSelfRef.tb_program__DOT__rst))) 
           && (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_valid0));
    if (vlSelfRef.tb_program__DOT__rst) {
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu1 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_rs2_1 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_wb1 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_rd1 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_funct3_1 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_mem_read1 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_mem_write1 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_reg_write1 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_mem_to_reg1 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_ecall1 = 0U;
        vlSelfRef.__Vdly__tb_program__DOT__uut__DOT__core__DOT__ex_mem_halt1 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_valid1 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_halt1 
            = vlSelfRef.__Vdly__tb_program__DOT__uut__DOT__core__DOT__ex_mem_halt1;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu0 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_rs2_0 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_wb0 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_rd0 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_funct3_0 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_mem_read0 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_mem_write0 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_reg_write0 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_mem_to_reg0 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_ecall0 = 0U;
        vlSelfRef.__Vdly__tb_program__DOT__uut__DOT__core__DOT__ex_mem_halt0 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_valid0 = 0U;
    } else {
        if ((1U & (~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_halt1)))) {
            vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu1 
                = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu1__DOT__result;
            vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_rs2_1 
                = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc1__DOT__rs2;
            vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_wb1 
                = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_wb_val1;
            vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_rd1 
                = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rd1;
            vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_funct3_1 
                = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_funct3_1;
            vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_mem_read1 
                = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_mem_read1;
            vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_mem_write1 
                = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_mem_write1;
            vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_reg_write1 
                = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_reg_write1;
            vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_mem_to_reg1 
                = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_mem_to_reg1;
            vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_ecall1 
                = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_ecall1;
            vlSelfRef.__Vdly__tb_program__DOT__uut__DOT__core__DOT__ex_mem_halt1 
                = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_halt1;
            vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_valid1 
                = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_valid1;
        }
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_halt1 
            = vlSelfRef.__Vdly__tb_program__DOT__uut__DOT__core__DOT__ex_mem_halt1;
        if ((1U & (~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_halt0)))) {
            vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_alu0 
                = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__alu0__DOT__result;
            vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_rs2_0 
                = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__bc0__DOT__rs2;
            vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_wb0 
                = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_wb_val0;
            vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_rd0 
                = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rd0;
            vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_funct3_0 
                = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_funct3_0;
            vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_mem_read0 
                = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_mem_read0;
            vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_mem_write0 
                = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_mem_write0;
            vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_reg_write0 
                = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_reg_write0;
            vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_mem_to_reg0 
                = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_mem_to_reg0;
            vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_ecall0 
                = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_ecall0;
            vlSelfRef.__Vdly__tb_program__DOT__uut__DOT__core__DOT__ex_mem_halt0 
                = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_halt0;
            vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_valid0 
                = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_valid0;
        }
    }
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_halt0 
        = vlSelfRef.__Vdly__tb_program__DOT__uut__DOT__core__DOT__ex_mem_halt0;
    if (((IData)(vlSelfRef.tb_program__DOT__rst) | (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__flush_ex))) {
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_mem_write1 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_mem_to_reg1 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_ecall1 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_halt1 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_valid1 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_reg_write1 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_mem_read1 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_funct3_1 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rd1 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_mem_to_reg0 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_ecall0 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_halt0 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_mem_write0 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_valid0 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_mem_read0 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_reg_write0 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_funct3_0 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rd0 = 0U;
    } else if ((1U & (~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__pipe_halt)))) {
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_mem_write1 
            = ((~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__squash_s1)) 
               & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_mem_write1));
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_mem_to_reg1 
            = ((~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__squash_s1)) 
               & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_mem_to_reg1));
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_ecall1 
            = ((~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__squash_s1)) 
               & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ecall1));
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_halt1 
            = ((~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__squash_s1)) 
               & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_halt1));
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_valid1 
            = ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_valid1) 
               & (~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__squash_s1)));
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_reg_write1 
            = ((~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__squash_s1)) 
               & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_reg_write1));
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_mem_read1 
            = ((~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__squash_s1)) 
               & (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_mem_read1));
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_funct3_1 
            = (7U & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                     >> 0x0000000cU));
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rd1 
            = ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__squash_s1)
                ? 0U : (0x0000001fU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                                       >> 7U)));
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_mem_to_reg0 
            = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_mem_to_reg0;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_ecall0 
            = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ecall0;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_halt0 
            = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_halt0;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_mem_write0 
            = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_mem_write0;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_valid0 
            = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_valid0;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_mem_read0 
            = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_mem_read0;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_reg_write0 
            = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_reg_write0;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_funct3_0 
            = (7U & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                     >> 0x0000000cU));
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rd0 
            = (0x0000001fU & (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                              >> 7U));
    }
    if (vlSelfRef.tb_program__DOT__rst) {
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_valid1 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 = 0x00000013U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_valid0 = 0U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 = 0x00000013U;
        vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__pc_current = 0U;
    } else {
        if (vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__flush_id) {
            vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_valid1 = 0U;
            vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 = 0x00000013U;
            vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_valid0 = 0U;
            vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 = 0x00000013U;
        } else if ((1U & ((~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__stall_if)) 
                          & (~ (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__pipe_halt))))) {
            vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_valid1 = 1U;
            vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr1 
                = vlSelfRef.tb_program__DOT__uut__DOT__imem_b__DOT__mem
                [(0x00000fffU & (((IData)(4U) + vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__pc_current) 
                                 >> 2U))];
            vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_valid0 = 1U;
            vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__if_id_instr0 
                = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__instr0;
        }
        if ((1U & (~ ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__hz__DOT__stall_if) 
                      | (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__pipe_halt))))) {
            vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__pc_current 
                = vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__pc_counter__DOT__pc_next;
        }
    }
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_9 
        = ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_reg_write1) 
           & (0U != (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_rd1)));
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_10 
        = ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_reg_write0) 
           & (0U != (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_rd0)));
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
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT____VdfgRegularize_hde518637_0_7 
        = ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_reg_write1) 
           & (0U != (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__id_ex_rd1)));
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
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__pipe_halt 
        = ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_halt0) 
           | (IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_halt1));
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
}

void Vtb_program___024root___nba_comb__TOP__0(Vtb_program___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_program___024root___nba_comb__TOP__0\n"); );
    Vtb_program__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VdfgRegularize_h6e95ff9d_0_5;
    __VdfgRegularize_h6e95ff9d_0_5 = 0;
    IData/*31:0*/ __VdfgRegularize_h6e95ff9d_0_6;
    __VdfgRegularize_h6e95ff9d_0_6 = 0;
    IData/*31:0*/ __VdfgRegularize_h6e95ff9d_0_8;
    __VdfgRegularize_h6e95ff9d_0_8 = 0;
    IData/*31:0*/ __VdfgRegularize_h6e95ff9d_0_9;
    __VdfgRegularize_h6e95ff9d_0_9 = 0;
    // Body
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
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_fwd_val1 
        = ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_mem_to_reg1)
            ? vlSelfRef.tb_program__DOT__uut__DOT__mem_rdata1
            : vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_wb1);
    vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_fwd_val0 
        = ((IData)(vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_mem_to_reg0)
            ? vlSelfRef.tb_program__DOT__uut__DOT__mem_rdata0
            : vlSelfRef.tb_program__DOT__uut__DOT__core__DOT__ex_mem_wb0);
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

void Vtb_program___024root___eval_nba(Vtb_program___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_program___024root___eval_nba\n"); );
    Vtb_program__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtb_program___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtb_program___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtb_program___024root___nba_sequent__TOP__2(vlSelf);
        vlSelfRef.__Vm_traceActivity[4U] = 1U;
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtb_program___024root___nba_comb__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[5U] = 1U;
    }
}

void Vtb_program___024root___timing_commit(Vtb_program___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_program___024root___timing_commit\n"); );
    Vtb_program__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((! (1ULL & vlSelfRef.__VactTriggered[0U]))) {
        vlSelfRef.__VtrigSched_h52375936__0.commit(
                                                   "@(posedge tb_program.clk)");
    }
}

void Vtb_program___024root___timing_resume(Vtb_program___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_program___024root___timing_resume\n"); );
    Vtb_program__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VtrigSched_h52375936__0.resume(
                                                   "@(posedge tb_program.clk)");
    }
    if ((4ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vtb_program___024root___trigger_orInto__act(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_program___024root___trigger_orInto__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vtb_program___024root___eval_phase__act(Vtb_program___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_program___024root___eval_phase__act\n"); );
    Vtb_program__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_program___024root___eval_triggers__act(vlSelf);
    Vtb_program___024root___timing_commit(vlSelf);
    Vtb_program___024root___trigger_orInto__act(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    __VactExecute = Vtb_program___024root___trigger_anySet__act(vlSelfRef.__VactTriggered);
    if (__VactExecute) {
        Vtb_program___024root___timing_resume(vlSelf);
    }
    return (__VactExecute);
}

void Vtb_program___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_program___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vtb_program___024root___eval_phase__nba(Vtb_program___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_program___024root___eval_phase__nba\n"); );
    Vtb_program__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vtb_program___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vtb_program___024root___eval_nba(vlSelf);
        Vtb_program___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vtb_program___024root___eval(Vtb_program___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_program___024root___eval\n"); );
    Vtb_program__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtb_program___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("tb/tb_program.v", 3, "", "NBA region did not converge after 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtb_program___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("tb/tb_program.v", 3, "", "Active region did not converge after 100 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
        } while (Vtb_program___024root___eval_phase__act(vlSelf));
    } while (Vtb_program___024root___eval_phase__nba(vlSelf));
}

#ifdef VL_DEBUG
void Vtb_program___024root___eval_debug_assertions(Vtb_program___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_program___024root___eval_debug_assertions\n"); );
    Vtb_program__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
