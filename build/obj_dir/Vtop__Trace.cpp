// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


//======================

void Vtop::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vtop* t=(Vtop*)userthis;
    Vtop__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
	t->traceChgThis(vlSymsp, vcdp, code);
    }
}

//======================


void Vtop::traceChgThis(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
			       | (vlTOPp->__Vm_traceActivity 
				  >> 1U))))) {
	    vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((1U & ((vlTOPp->__Vm_traceActivity 
				| (vlTOPp->__Vm_traceActivity 
				   >> 1U)) | (vlTOPp->__Vm_traceActivity 
					      >> 5U))))) {
	    vlTOPp->traceChgThis__3(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
			       | (vlTOPp->__Vm_traceActivity 
				  >> 2U))))) {
	    vlTOPp->traceChgThis__4(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
			       | (vlTOPp->__Vm_traceActivity 
				  >> 4U))))) {
	    vlTOPp->traceChgThis__5(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
			       | (vlTOPp->__Vm_traceActivity 
				  >> 5U))))) {
	    vlTOPp->traceChgThis__6(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((2U & vlTOPp->__Vm_traceActivity))) {
	    vlTOPp->traceChgThis__7(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((8U & vlTOPp->__Vm_traceActivity))) {
	    vlTOPp->traceChgThis__8(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((0x10U & vlTOPp->__Vm_traceActivity))) {
	    vlTOPp->traceChgThis__9(vlSymsp, vcdp, code);
	}
	vlTOPp->traceChgThis__10(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vtop::traceChgThis__2(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+1,(vlTOPp->top__DOT__dwbm_dat_i),32);
	vcdp->chgBus  (c+2,(vlTOPp->top__DOT__iwbm_dat),32);
	vcdp->chgBus  (c+3,(vlTOPp->top__DOT__cpu__DOT__EX__DOT__ex_result),32);
	vcdp->chgBus  (c+4,(vlTOPp->top__DOT__cpu__DOT__forward_a_sel),2);
	vcdp->chgBus  (c+5,(vlTOPp->top__DOT__cpu__DOT__forward_b_sel),2);
	vcdp->chgBus  (c+6,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__rs1),5);
	vcdp->chgBus  (c+7,((0xfffffffeU & vlTOPp->top__DOT__cpu__DOT__ID__DOT__pc_jump)),32);
	vcdp->chgBus  (c+8,(vlTOPp->top__DOT__cpu__DOT__pc_branch_addr),32);
	vcdp->chgBit  (c+9,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_j));
	vcdp->chgBit  (c+10,(vlTOPp->top__DOT__cpu__DOT__ld_dependence));
	vcdp->chgBus  (c+11,(vlTOPp->top__DOT__cpu__DOT__csr_data_o),32);
	vcdp->chgBus  (c+12,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__drs1),32);
	vcdp->chgBus  (c+13,(((0U == (0x1fU & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
					       >> 0x14U)))
			       ? 0U : vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file
			      [(0x1fU & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
					 >> 0x14U))])),32);
	vcdp->chgBit  (c+14,(((0U != (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__waddr)) 
			      & (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_wr))));
	vcdp->chgBus  (c+15,((((((((((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_add) 
				     | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_sub)) 
				    | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_and)) 
				   | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_or)) 
				  | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_xor)) 
				 | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_sll)) 
				| (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_sr)) 
			       | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_slt))
			       ? ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_add)
				   ? 0U : ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_sub)
					    ? 1U : 
					   ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_and)
					     ? 2U : 
					    ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_or)
					      ? 3U : 
					     ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_xor)
					       ? 4U
					       : ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_sll)
						   ? 5U
						   : 
						  ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_sr)
						    ? 
						   (((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sra) 
						     | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__srai))
						     ? 6U
						     : 7U)
						    : 8U)))))))
			       : ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_sltu)
				   ? 9U : 0xfU))),4);
	vcdp->chgBus  (c+16,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__comparator_op),3);
	vcdp->chgBus  (c+17,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__imm),32);
	vcdp->chgBus  (c+18,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__waddr),5);
	vcdp->chgBit  (c+19,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_immop));
	vcdp->chgBit  (c+20,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__auipc));
	vcdp->chgBit  (c+21,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__jalr));
	vcdp->chgBus  (c+22,((((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_st) 
			       << 5U) | (((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_ld) 
					  << 4U) | 
					 (((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_word) 
					   << 3U) | 
					  (((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_hw) 
					    << 2U) 
					   | (((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_byte) 
					       << 1U) 
					      | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_ldu))))))),6);
	vcdp->chgBit  (c+23,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_ld));
	vcdp->chgBus  (c+24,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__pc_jump),32);
	vcdp->chgBit  (c+25,(((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_j) 
			      & (0U != (2U & vlTOPp->top__DOT__cpu__DOT__ID__DOT__pc_jump)))));
	vcdp->chgBit  (c+26,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_b));
	vcdp->chgBit  (c+27,(((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_b) 
			      & (0U != (3U & vlTOPp->top__DOT__cpu__DOT__pc_branch_addr)))));
	vcdp->chgBit  (c+28,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_csri));
	vcdp->chgBus  (c+29,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[0]),32);
	vcdp->chgBus  (c+30,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[1]),32);
	vcdp->chgBus  (c+31,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[2]),32);
	vcdp->chgBus  (c+32,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[3]),32);
	vcdp->chgBus  (c+33,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[4]),32);
	vcdp->chgBus  (c+34,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[5]),32);
	vcdp->chgBus  (c+35,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[6]),32);
	vcdp->chgBus  (c+36,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[7]),32);
	vcdp->chgBus  (c+37,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[8]),32);
	vcdp->chgBus  (c+38,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[9]),32);
	vcdp->chgBus  (c+39,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[10]),32);
	vcdp->chgBus  (c+40,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[11]),32);
	vcdp->chgBus  (c+41,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[12]),32);
	vcdp->chgBus  (c+42,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[13]),32);
	vcdp->chgBus  (c+43,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[14]),32);
	vcdp->chgBus  (c+44,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[15]),32);
	vcdp->chgBus  (c+45,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[16]),32);
	vcdp->chgBus  (c+46,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[17]),32);
	vcdp->chgBus  (c+47,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[18]),32);
	vcdp->chgBus  (c+48,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[19]),32);
	vcdp->chgBus  (c+49,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[20]),32);
	vcdp->chgBus  (c+50,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[21]),32);
	vcdp->chgBus  (c+51,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[22]),32);
	vcdp->chgBus  (c+52,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[23]),32);
	vcdp->chgBus  (c+53,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[24]),32);
	vcdp->chgBus  (c+54,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[25]),32);
	vcdp->chgBus  (c+55,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[26]),32);
	vcdp->chgBus  (c+56,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[27]),32);
	vcdp->chgBus  (c+57,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[28]),32);
	vcdp->chgBus  (c+58,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[29]),32);
	vcdp->chgBus  (c+59,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[30]),32);
	vcdp->chgBus  (c+60,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[31]),32);
	vcdp->chgBus  (c+61,((((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_word) 
			       << 2U) | (((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_hw) 
					  << 1U) | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_byte)))),3);
	vcdp->chgBit  (c+62,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_st));
	vcdp->chgBit  (c+63,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_ldu));
	vcdp->chgBit  (c+64,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__lui));
	vcdp->chgBit  (c+65,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__auipc));
	vcdp->chgBit  (c+66,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__jal));
	vcdp->chgBit  (c+67,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__beq));
	vcdp->chgBit  (c+68,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__bne));
	vcdp->chgBit  (c+69,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__blt));
	vcdp->chgBit  (c+70,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__bge));
	vcdp->chgBit  (c+71,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__bltu));
	vcdp->chgBit  (c+72,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__bgeu));
	vcdp->chgBit  (c+73,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__lb));
	vcdp->chgBit  (c+74,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__lh));
	vcdp->chgBit  (c+75,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__lw));
	vcdp->chgBit  (c+76,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__lbu));
	vcdp->chgBit  (c+77,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__lhu));
	vcdp->chgBit  (c+78,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sb));
	vcdp->chgBit  (c+79,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sh));
	vcdp->chgBit  (c+80,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sw));
	vcdp->chgBit  (c+81,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__addi));
	vcdp->chgBit  (c+82,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__slti));
	vcdp->chgBit  (c+83,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sltiu));
	vcdp->chgBit  (c+84,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__xori));
	vcdp->chgBit  (c+85,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__ori));
	vcdp->chgBit  (c+86,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__andi));
	vcdp->chgBit  (c+87,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__slli));
	vcdp->chgBit  (c+88,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__srli));
	vcdp->chgBit  (c+89,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__srai));
	vcdp->chgBit  (c+90,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__add));
	vcdp->chgBit  (c+91,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sub));
	vcdp->chgBit  (c+92,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sll));
	vcdp->chgBit  (c+93,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__slt));
	vcdp->chgBit  (c+94,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sltu));
	vcdp->chgBit  (c+95,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__srl));
	vcdp->chgBit  (c+96,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sra));
	vcdp->chgBit  (c+97,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__rwi));
	vcdp->chgBit  (c+98,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__rsi));
	vcdp->chgBit  (c+99,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__rci));
	vcdp->chgBit  (c+100,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_imm));
	vcdp->chgBit  (c+101,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_add));
	vcdp->chgBit  (c+102,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_sub));
	vcdp->chgBit  (c+103,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_and));
	vcdp->chgBit  (c+104,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_xor));
	vcdp->chgBit  (c+105,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_or));
	vcdp->chgBit  (c+106,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_sll));
	vcdp->chgBit  (c+107,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_sr));
	vcdp->chgBit  (c+108,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_slt));
	vcdp->chgBit  (c+109,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_sltu));
	vcdp->chgBit  (c+110,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_wr));
	vcdp->chgBit  (c+111,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_alu));
	vcdp->chgBit  (c+112,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_immop));
	vcdp->chgBit  (c+113,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_word));
	vcdp->chgBit  (c+114,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_byte));
	vcdp->chgBit  (c+115,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_hw));
	vcdp->chgBit  (c+116,(vlTOPp->top__DOT__cpu__DOT__FWD__DOT__ex_fwd_a));
	vcdp->chgBit  (c+117,(vlTOPp->top__DOT__cpu__DOT__FWD__DOT__ex_fwd_b));
	vcdp->chgBit  (c+118,((((IData)(vlTOPp->top__DOT__cpu__DOT__mem_waddr) 
				== (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__rs1)) 
			       & (IData)(vlTOPp->top__DOT__cpu__DOT__mem_we))));
	vcdp->chgBit  (c+119,((((IData)(vlTOPp->top__DOT__cpu__DOT__wb_waddr) 
				== (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__rs1)) 
			       & (IData)(vlTOPp->top__DOT__cpu__DOT__wb_we))));
    }
}

void Vtop::traceChgThis__3(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+120,(((2U & (IData)(vlTOPp->top__DOT__cpu__DOT__if_pc_sel))
			        ? ((1U & (IData)(vlTOPp->top__DOT__cpu__DOT__if_pc_sel))
				    ? 0U : (0xfffffffeU 
					    & vlTOPp->top__DOT__cpu__DOT__ID__DOT__pc_jump))
			        : ((1U & (IData)(vlTOPp->top__DOT__cpu__DOT__if_pc_sel))
				    ? vlTOPp->top__DOT__cpu__DOT__pc_branch_addr
				    : ((IData)(4U) 
				       + vlTOPp->top__DOT__cpu__DOT__if_pc)))),32);
	vcdp->chgBit  (c+121,(((4U & (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__comparator_op))
			        ? ((2U & (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__comparator_op))
				    ? ((~ (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__comparator_op)) 
				       & (vlTOPp->top__DOT__cpu__DOT__ID__DOT__muxa_i 
					  >= vlTOPp->top__DOT__cpu__DOT__ID__DOT__muxb_i))
				    : ((1U & (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__comparator_op))
				        ? (vlTOPp->top__DOT__cpu__DOT__ID__DOT__muxa_i 
					   < vlTOPp->top__DOT__cpu__DOT__ID__DOT__muxb_i)
				        : VL_GTES_III(1,32,32, vlTOPp->top__DOT__cpu__DOT__ID__DOT__muxa_i, vlTOPp->top__DOT__cpu__DOT__ID__DOT__muxb_i)))
			        : ((2U & (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__comparator_op))
				    ? ((1U & (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__comparator_op))
				        ? VL_LTS_III(1,32,32, vlTOPp->top__DOT__cpu__DOT__ID__DOT__muxa_i, vlTOPp->top__DOT__cpu__DOT__ID__DOT__muxb_i)
				        : (vlTOPp->top__DOT__cpu__DOT__ID__DOT__muxa_i 
					   != vlTOPp->top__DOT__cpu__DOT__ID__DOT__muxb_i))
				    : ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__comparator_op) 
				       & (vlTOPp->top__DOT__cpu__DOT__ID__DOT__muxa_i 
					  == vlTOPp->top__DOT__cpu__DOT__ID__DOT__muxb_i))))));
	vcdp->chgBus  (c+122,(((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_csri)
			        ? vlTOPp->top__DOT__cpu__DOT__ID__DOT__port_b
			        : vlTOPp->top__DOT__cpu__DOT__ID__DOT__port_a)),32);
    }
}

void Vtop::traceChgThis__4(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+123,(vlTOPp->top__DOT__dwbm_ack));
	vcdp->chgBit  (c+124,(vlTOPp->top__DOT__cpu__DOT__if_flush));
	vcdp->chgBit  (c+125,(vlTOPp->top__DOT__cpu__DOT__mem_stall_req));
	vcdp->chgBit  (c+126,(vlTOPp->top__DOT__cpu__DOT____Vcellinp__IF__if_stall));
	vcdp->chgBit  (c+127,(vlTOPp->top__DOT__cpu__DOT____Vcellinp__EX__ex_flush_i));
    }
}

void Vtop::traceChgThis__5(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+128,(vlTOPp->top__DOT__cpu__DOT__LSU__DOT__wsel_o),4);
    }
}

void Vtop::traceChgThis__6(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+129,(vlTOPp->top__DOT__cpu__DOT__if_pc_sel),2);
	vcdp->chgBus  (c+130,(vlTOPp->top__DOT__cpu__DOT__MEM__DOT__mem_result),32);
	vcdp->chgBit  (c+131,(vlTOPp->top__DOT__cpu__DOT__take_branch));
	vcdp->chgBus  (c+132,(vlTOPp->top__DOT__cpu__DOT__mem_load_data),32);
	vcdp->chgBit  (c+133,(vlTOPp->top__DOT__cpu__DOT__if_kill));
	vcdp->chgBus  (c+134,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__muxa_i),32);
	vcdp->chgBus  (c+135,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__muxb_i),32);
	vcdp->chgBus  (c+136,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__port_a),32);
	vcdp->chgBus  (c+137,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__port_b),32);
	vcdp->chgBus  (c+138,(vlTOPp->top__DOT__cpu__DOT__LSU__DOT__wdata),32);
    }
}

void Vtop::traceChgThis__7(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+139,(vlTOPp->top__DOT__dwbm_addr),32);
	vcdp->chgBit  (c+140,(vlTOPp->top__DOT__dwbm_cyc));
	vcdp->chgBus  (c+141,(vlTOPp->top__DOT__dwbm_dat_o),32);
	vcdp->chgBus  (c+142,(vlTOPp->top__DOT__dwbm_sel),4);
	vcdp->chgBit  (c+143,(vlTOPp->top__DOT__dwbm_stb));
	vcdp->chgBit  (c+144,(vlTOPp->top__DOT__dwbm_we));
	vcdp->chgBus  (c+145,(vlTOPp->top__DOT__cpu__DOT__if_pc),32);
	vcdp->chgBit  (c+146,(vlTOPp->top__DOT__iwbm_cyc));
	vcdp->chgBit  (c+147,(vlTOPp->top__DOT__iwbm_stb));
	vcdp->chgBit  (c+148,((((IData)(vlTOPp->top__DOT__iwbm_cyc) 
				& (IData)(vlTOPp->top__DOT__iwbm_stb)) 
			       & (0x80U == (0xffU & 
					    (vlTOPp->top__DOT__cpu__DOT__if_pc 
					     >> 0x18U))))));
	vcdp->chgBus  (c+149,(vlTOPp->top__DOT__cpu__DOT__id_instruction),32);
	vcdp->chgBus  (c+150,(vlTOPp->top__DOT__cpu__DOT__id_pc),32);
	vcdp->chgBit  (c+151,(vlTOPp->top__DOT__cpu__DOT__id_exc_addr_if));
	vcdp->chgBit  (c+152,(vlTOPp->top__DOT__cpu__DOT__id_inst_access_fault));
	vcdp->chgBus  (c+153,(vlTOPp->top__DOT__cpu__DOT__wb_waddr),5);
	vcdp->chgBit  (c+154,(vlTOPp->top__DOT__cpu__DOT__wb_we));
	vcdp->chgBus  (c+155,((0x1fU & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
					>> 0x14U))),5);
	vcdp->chgBus  (c+156,(vlTOPp->top__DOT__cpu__DOT__ex_pc),32);
	vcdp->chgBus  (c+157,(vlTOPp->top__DOT__cpu__DOT__ex_instruction),32);
	vcdp->chgBus  (c+158,(vlTOPp->top__DOT__cpu__DOT__ex_port_a),32);
	vcdp->chgBus  (c+159,(vlTOPp->top__DOT__cpu__DOT__ex_port_b),32);
	vcdp->chgBus  (c+160,(vlTOPp->top__DOT__cpu__DOT__ex_alu_op),4);
	vcdp->chgBus  (c+161,(vlTOPp->top__DOT__cpu__DOT__ex_waddr),5);
	vcdp->chgBit  (c+162,(vlTOPp->top__DOT__cpu__DOT__ex_we));
	vcdp->chgBus  (c+163,(vlTOPp->top__DOT__cpu__DOT__ex_mem_flags),6);
	vcdp->chgBit  (c+164,(vlTOPp->top__DOT__cpu__DOT__ex_mem_ex_sel));
	vcdp->chgBit  (c+165,(vlTOPp->top__DOT__cpu__DOT__ex_bad_jump_addr));
	vcdp->chgBit  (c+166,(vlTOPp->top__DOT__cpu__DOT__ex_bad_branch_addr));
	vcdp->chgBit  (c+167,(vlTOPp->top__DOT__cpu__DOT__ex_break_op));
	vcdp->chgBit  (c+168,(vlTOPp->top__DOT__cpu__DOT__ex_syscall_op));
	vcdp->chgBus  (c+169,(vlTOPp->top__DOT__cpu__DOT__ex_csr_op),3);
	vcdp->chgBus  (c+170,(vlTOPp->top__DOT__cpu__DOT__ex_csr_data),32);
	vcdp->chgBus  (c+171,(vlTOPp->top__DOT__cpu__DOT__ex_csr_addr),12);
	vcdp->chgBit  (c+172,(vlTOPp->top__DOT__cpu__DOT__ex_exc_addr_if));
	vcdp->chgBit  (c+173,(vlTOPp->top__DOT__cpu__DOT__ex_inst_access_fault));
	vcdp->chgBus  (c+174,(vlTOPp->top__DOT__cpu__DOT__mem_pc),32);
	vcdp->chgBus  (c+175,(vlTOPp->top__DOT__cpu__DOT__mem_instruction),32);
	vcdp->chgBus  (c+176,(vlTOPp->top__DOT__cpu__DOT__mem_result),32);
	vcdp->chgBus  (c+177,(vlTOPp->top__DOT__cpu__DOT__mem_waddr),5);
	vcdp->chgBit  (c+178,(vlTOPp->top__DOT__cpu__DOT__mem_we));
	vcdp->chgBit  (c+179,(vlTOPp->top__DOT__cpu__DOT__mem_mem_ex_sel));
	vcdp->chgBus  (c+180,(vlTOPp->top__DOT__cpu__DOT__mem_csr_data),32);
	vcdp->chgBus  (c+181,(vlTOPp->top__DOT__cpu__DOT__mem_csr_op),3);
	vcdp->chgBus  (c+182,(vlTOPp->top__DOT__cpu__DOT__mem_csr_addr),12);
	vcdp->chgBit  (c+183,(vlTOPp->top__DOT__cpu__DOT__mem_exc_addr_if));
	vcdp->chgBit  (c+184,(vlTOPp->top__DOT__cpu__DOT__mem_inst_access_fault));
	vcdp->chgBit  (c+185,(vlTOPp->top__DOT__cpu__DOT__mem_bad_jump_addr));
	vcdp->chgBit  (c+186,(vlTOPp->top__DOT__cpu__DOT__mem_bad_branch_addr));
	vcdp->chgBit  (c+187,(vlTOPp->top__DOT__cpu__DOT__mem_break_op));
	vcdp->chgBit  (c+188,(vlTOPp->top__DOT__cpu__DOT__mem_syscall_op));
	vcdp->chgBus  (c+189,(vlTOPp->top__DOT__cpu__DOT__mem_store_data),32);
	vcdp->chgBus  (c+190,(vlTOPp->top__DOT__cpu__DOT__wb_pc),32);
	vcdp->chgBus  (c+191,(vlTOPp->top__DOT__cpu__DOT__wb_instruction),32);
	vcdp->chgBus  (c+192,(vlTOPp->top__DOT__cpu__DOT__wb_result),32);
	vcdp->chgBus  (c+193,(vlTOPp->top__DOT__cpu__DOT__wb_csr_data),32);
	vcdp->chgBus  (c+194,(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr),12);
	vcdp->chgBus  (c+195,(vlTOPp->top__DOT__cpu__DOT__wb_csr_op),3);
	vcdp->chgBit  (c+196,(vlTOPp->top__DOT__cpu__DOT__wb_exc_addr_if));
	vcdp->chgBit  (c+197,(vlTOPp->top__DOT__cpu__DOT__wb_inst_access_fault));
	vcdp->chgBit  (c+198,(vlTOPp->top__DOT__cpu__DOT__wb_mem_access_fault));
	vcdp->chgBit  (c+199,(vlTOPp->top__DOT__cpu__DOT__wb_bad_jump_addr));
	vcdp->chgBit  (c+200,(vlTOPp->top__DOT__cpu__DOT__wb_bad_branch_addr));
	vcdp->chgBit  (c+201,(vlTOPp->top__DOT__cpu__DOT__wb_break_op));
	vcdp->chgBit  (c+202,(vlTOPp->top__DOT__cpu__DOT__wb_syscall_op));
	vcdp->chgBus  (c+203,(((IData)(4U) + vlTOPp->top__DOT__cpu__DOT__if_pc)),32);
	vcdp->chgBit  (c+204,((0U == (3U & vlTOPp->top__DOT__cpu__DOT__if_pc))));
	vcdp->chgBit  (c+205,(((0x73U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
			       & (0x2000U == (0x1ffffffU 
					      & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
						 >> 7U))))));
	vcdp->chgBit  (c+206,(((0x73U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
			       & (0U == (0x1ffffffU 
					 & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
					    >> 7U))))));
	vcdp->chgBus  (c+207,((0xfffU & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
					 >> 0x14U))),12);
	vcdp->chgBus  (c+208,(((((0x73U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
				 & (3U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
						 >> 0xcU)))) 
				<< 2U) | ((((0x73U 
					     == (0x7fU 
						 & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
					    & (2U == 
					       (7U 
						& (vlTOPp->top__DOT__cpu__DOT__id_instruction 
						   >> 0xcU)))) 
					   << 1U) | 
					  ((0x73U == 
					    (0x7fU 
					     & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
					   & (1U == 
					      (7U & 
					       (vlTOPp->top__DOT__cpu__DOT__id_instruction 
						>> 0xcU))))))),3);
	vcdp->chgBus  (c+209,((0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)),7);
	vcdp->chgBus  (c+210,((7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
				     >> 0xcU))),3);
	vcdp->chgBus  (c+211,((0x7fU & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
					>> 0x19U))),7);
	vcdp->chgBit  (c+212,(((0x73U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
			       & (1U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
					       >> 0xcU))))));
	vcdp->chgBit  (c+213,(((0x73U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
			       & (2U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
					       >> 0xcU))))));
	vcdp->chgBit  (c+214,(((0x73U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
			       & (3U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
					       >> 0xcU))))));
	vcdp->chgBit  (c+215,((((IData)(vlTOPp->top__DOT__cpu__DOT__mem_waddr) 
				== (0x1fU & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
					     >> 0x14U))) 
			       & (IData)(vlTOPp->top__DOT__cpu__DOT__mem_we))));
	vcdp->chgBit  (c+216,((((IData)(vlTOPp->top__DOT__cpu__DOT__wb_waddr) 
				== (0x1fU & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
					     >> 0x14U))) 
			       & (IData)(vlTOPp->top__DOT__cpu__DOT__wb_we))));
	vcdp->chgBus  (c+217,(vlTOPp->top__DOT__cpu__DOT__LSU__DOT__rdata),32);
	vcdp->chgBus  (c+218,(vlTOPp->top__DOT__cpu__DOT__LSU__DOT__i_state),2);
	vcdp->chgBus  (c+219,(vlTOPp->top__DOT__cpu__DOT__LSU__DOT__d_state),2);
	vcdp->chgBit  (c+220,(vlTOPp->top__DOT__cpu__DOT__LSU__DOT__kill));
	vcdp->chgBus  (c+221,(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__csr_wdata),32);
	vcdp->chgBus  (c+222,((0x1800U | (((IData)(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mstatus_mpie) 
					   << 7U) | 
					  ((IData)(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mstatus_mie) 
					   << 3U)))),32);
	vcdp->chgBus  (c+223,((((IData)(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mie_meie) 
				<< 0xbU) | (((IData)(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mie_mtie) 
					     << 7U) 
					    | ((IData)(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mie_msie) 
					       << 3U)))),32);
	vcdp->chgBus  (c+224,(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mtvec),32);
	vcdp->chgBus  (c+225,(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mscratch),32);
	vcdp->chgBus  (c+226,(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mepc),32);
	vcdp->chgBus  (c+227,((((IData)(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mcause_int) 
				<< 0x1fU) | (IData)(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mcause_exc))),32);
	vcdp->chgBus  (c+228,(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mtval),32);
	vcdp->chgQuad (c+229,(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mcycle),64);
	vcdp->chgQuad (c+231,(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__minstret),64);
	vcdp->chgBit  (c+233,((0U != (IData)(vlTOPp->top__DOT__cpu__DOT__wb_waddr))));
	vcdp->chgBit  (c+234,(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mstatus_mpie));
	vcdp->chgBit  (c+235,(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mstatus_mie));
	vcdp->chgBit  (c+236,(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mie_meie));
	vcdp->chgBit  (c+237,(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mie_mtie));
	vcdp->chgBit  (c+238,(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mie_msie));
	vcdp->chgBit  (c+239,(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mcause_int));
	vcdp->chgBus  (c+240,(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mcause_exc),4);
	vcdp->chgBit  (c+241,((0x301U == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))));
	vcdp->chgBit  (c+242,((0xf14U == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))));
	vcdp->chgBit  (c+243,((0xf11U == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))));
	vcdp->chgBit  (c+244,((0xf12U == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))));
	vcdp->chgBit  (c+245,((0x300U == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))));
	vcdp->chgBit  (c+246,((0x304U == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))));
	vcdp->chgBit  (c+247,((0x340U == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))));
	vcdp->chgBit  (c+248,((0x341U == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))));
	vcdp->chgBit  (c+249,((0x342U == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))));
	vcdp->chgBit  (c+250,((0x343U == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))));
	vcdp->chgBit  (c+251,((0x344U == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))));
	vcdp->chgBit  (c+252,((0xb00U == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))));
	vcdp->chgBit  (c+253,((0xb02U == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))));
	vcdp->chgBit  (c+254,((0xb80U == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))));
	vcdp->chgBit  (c+255,((0xb82U == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))));
	vcdp->chgBus  (c+256,((0xfffffcU & vlTOPp->top__DOT__cpu__DOT__if_pc)),24);
	vcdp->chgBus  (c+257,((0xfffffcU & vlTOPp->top__DOT__dwbm_addr)),24);
	vcdp->chgBit  (c+258,((0x80U == (0xffU & (vlTOPp->top__DOT__cpu__DOT__if_pc 
						  >> 0x18U)))));
	vcdp->chgBit  (c+259,((0x80U == (0xffU & (vlTOPp->top__DOT__dwbm_addr 
						  >> 0x18U)))));
    }
}

void Vtop::traceChgThis__8(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+260,(vlTOPp->top__DOT__cpu__DOT__LSU__DOT__rsel_o),4);
	vcdp->chgBit  (c+261,(vlTOPp->top__DOT__cpu__DOT__LSU__DOT__runsigned));
    }
}

void Vtop::traceChgThis__9(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+262,(vlTOPp->top__DOT__cpu__DOT__mem_mem_flags),6);
	vcdp->chgBit  (c+263,((1U & (IData)(vlTOPp->top__DOT__cpu__DOT__mem_mem_flags))));
	vcdp->chgBit  (c+264,((1U & ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_mem_flags) 
				     >> 1U))));
	vcdp->chgBit  (c+265,((1U & ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_mem_flags) 
				     >> 2U))));
	vcdp->chgBit  (c+266,((1U & ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_mem_flags) 
				     >> 3U))));
	vcdp->chgBit  (c+267,((1U & ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_mem_flags) 
				     >> 4U))));
	vcdp->chgBit  (c+268,((1U & ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_mem_flags) 
				     >> 5U))));
    }
}

void Vtop::traceChgThis__10(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+269,(vlTOPp->clk_i));
	vcdp->chgBit  (c+270,(vlTOPp->rst_i));
	vcdp->chgBit  (c+271,(((((~ (IData)(vlTOPp->rst_i)) 
				 & (IData)(vlTOPp->top__DOT__cpu__DOT__LSU__DOT__kill)) 
				| (IData)(vlTOPp->top__DOT__cpu__DOT__mem_stall_req)) 
			       | (IData)(vlTOPp->top__DOT__cpu__DOT__ld_dependence))));
	vcdp->chgBit  (c+272,(((~ (IData)(vlTOPp->rst_i)) 
			       & (IData)(vlTOPp->top__DOT__cpu__DOT__LSU__DOT__kill))));
    }
}
