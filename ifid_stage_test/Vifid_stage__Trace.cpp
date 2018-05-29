// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vifid_stage__Syms.h"


//======================

void Vifid_stage::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vifid_stage* t=(Vifid_stage*)userthis;
    Vifid_stage__Syms* __restrict vlSymsp = t->__VlSymsp; // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
	t->traceChgThis (vlSymsp, vcdp, code);
    }
}

//======================


void Vifid_stage::traceChgThis(Vifid_stage__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vifid_stage* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	if (VL_UNLIKELY((1U & vlTOPp->__Vm_traceActivity))) {
	    vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
			       | (vlTOPp->__Vm_traceActivity 
				  >> 1U))))) {
	    vlTOPp->traceChgThis__3(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((1U & ((vlTOPp->__Vm_traceActivity 
				| (vlTOPp->__Vm_traceActivity 
				   >> 1U)) | (vlTOPp->__Vm_traceActivity 
					      >> 2U))))) {
	    vlTOPp->traceChgThis__4(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((1U & ((vlTOPp->__Vm_traceActivity 
				| (vlTOPp->__Vm_traceActivity 
				   >> 1U)) | (vlTOPp->__Vm_traceActivity 
					      >> 5U))))) {
	    vlTOPp->traceChgThis__5(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((1U & ((vlTOPp->__Vm_traceActivity 
				| (vlTOPp->__Vm_traceActivity 
				   >> 2U)) | (vlTOPp->__Vm_traceActivity 
					      >> 5U))))) {
	    vlTOPp->traceChgThis__6(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
			       | (vlTOPp->__Vm_traceActivity 
				  >> 3U))))) {
	    vlTOPp->traceChgThis__7(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
			       | (vlTOPp->__Vm_traceActivity 
				  >> 5U))))) {
	    vlTOPp->traceChgThis__8(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((2U & vlTOPp->__Vm_traceActivity))) {
	    vlTOPp->traceChgThis__9(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((0x10U & vlTOPp->__Vm_traceActivity))) {
	    vlTOPp->traceChgThis__10(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((0x20U & vlTOPp->__Vm_traceActivity))) {
	    vlTOPp->traceChgThis__11(vlSymsp, vcdp, code);
	}
	vlTOPp->traceChgThis__12(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vifid_stage::traceChgThis__2(Vifid_stage__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vifid_stage* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+1,(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__idat_o),32);
    }
}

void Vifid_stage::traceChgThis__3(Vifid_stage__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vifid_stage* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+2,(vlTOPp->ifid_stage__DOT__IF__DOT__wbm_sel_o),4);
	vcdp->chgBit  (c+3,(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__no_mem));
	vcdp->chgBus  (c+4,(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__data_o),32);
	vcdp->chgBus  (c+5,(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__dsel_o),4);
	vcdp->chgBus  (c+6,(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__wdata),32);
	vcdp->chgQuad (c+7,(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__no_rps),64);
	vcdp->chgBus  (c+9,(vlTOPp->ifid_stage__DOT__ID__DOT__drs2),32);
	vcdp->chgBit  (c+10,(((0U != (0x1fU & (vlTOPp->ifid_stage__DOT__id_instruction 
					       >> 7U))) 
			      & (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_wr))));
	vcdp->chgBus  (c+11,((((((((((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_add) 
				     | (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_sub)) 
				    | (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_and)) 
				   | (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_or)) 
				  | (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_xor)) 
				 | (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_sll)) 
				| (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_sr)) 
			       | (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_slt))
			       ? ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_add)
				   ? 0U : ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_sub)
					    ? 1U : 
					   ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_and)
					     ? 2U : 
					    ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_or)
					      ? 3U : 
					     ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_xor)
					       ? 4U
					       : ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_sll)
						   ? 5U
						   : 
						  ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_sr)
						    ? 
						   (((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__sra) 
						     | (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__srai))
						     ? 6U
						     : 7U)
						    : 8U)))))))
			       : ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_sltu)
				   ? 9U : 0xfU))),4);
	vcdp->chgBit  (c+12,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_immop));
	vcdp->chgBit  (c+13,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__auipc));
	vcdp->chgBit  (c+14,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__jalr));
	vcdp->chgBus  (c+15,((((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_st) 
			       << 5U) | (((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_ld) 
					  << 4U) | 
					 (((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_word) 
					   << 3U) | 
					  (((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_hw) 
					    << 2U) 
					   | (((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_byte) 
					       << 1U) 
					      | (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_ldu))))))),6);
	vcdp->chgBit  (c+16,(((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_ld) 
			      | (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_st))));
	vcdp->chgBit  (c+17,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_j));
	vcdp->chgBit  (c+18,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_b));
	vcdp->chgBus  (c+19,((((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__rc) 
			       << 2U) | (((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__rs) 
					  << 1U) | (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__rw)))),3);
	vcdp->chgBit  (c+20,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_csri));
	vcdp->chgBus  (c+21,(vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file[0]),32);
	vcdp->chgBus  (c+22,(vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file[1]),32);
	vcdp->chgBus  (c+23,(vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file[2]),32);
	vcdp->chgBus  (c+24,(vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file[3]),32);
	vcdp->chgBus  (c+25,(vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file[4]),32);
	vcdp->chgBus  (c+26,(vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file[5]),32);
	vcdp->chgBus  (c+27,(vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file[6]),32);
	vcdp->chgBus  (c+28,(vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file[7]),32);
	vcdp->chgBus  (c+29,(vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file[8]),32);
	vcdp->chgBus  (c+30,(vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file[9]),32);
	vcdp->chgBus  (c+31,(vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file[10]),32);
	vcdp->chgBus  (c+32,(vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file[11]),32);
	vcdp->chgBus  (c+33,(vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file[12]),32);
	vcdp->chgBus  (c+34,(vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file[13]),32);
	vcdp->chgBus  (c+35,(vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file[14]),32);
	vcdp->chgBus  (c+36,(vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file[15]),32);
	vcdp->chgBus  (c+37,(vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file[16]),32);
	vcdp->chgBus  (c+38,(vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file[17]),32);
	vcdp->chgBus  (c+39,(vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file[18]),32);
	vcdp->chgBus  (c+40,(vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file[19]),32);
	vcdp->chgBus  (c+41,(vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file[20]),32);
	vcdp->chgBus  (c+42,(vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file[21]),32);
	vcdp->chgBus  (c+43,(vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file[22]),32);
	vcdp->chgBus  (c+44,(vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file[23]),32);
	vcdp->chgBus  (c+45,(vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file[24]),32);
	vcdp->chgBus  (c+46,(vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file[25]),32);
	vcdp->chgBus  (c+47,(vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file[26]),32);
	vcdp->chgBus  (c+48,(vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file[27]),32);
	vcdp->chgBus  (c+49,(vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file[28]),32);
	vcdp->chgBus  (c+50,(vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file[29]),32);
	vcdp->chgBus  (c+51,(vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file[30]),32);
	vcdp->chgBus  (c+52,(vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file[31]),32);
	vcdp->chgBus  (c+53,((((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_word) 
			       << 2U) | (((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_hw) 
					  << 1U) | (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_byte)))),3);
	vcdp->chgBit  (c+54,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_st));
	vcdp->chgBit  (c+55,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_ld));
	vcdp->chgBit  (c+56,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_ldu));
	vcdp->chgBit  (c+57,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__lui));
	vcdp->chgBit  (c+58,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__auipc));
	vcdp->chgBit  (c+59,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__jal));
	vcdp->chgBit  (c+60,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__beq));
	vcdp->chgBit  (c+61,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__bne));
	vcdp->chgBit  (c+62,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__blt));
	vcdp->chgBit  (c+63,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__bge));
	vcdp->chgBit  (c+64,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__bltu));
	vcdp->chgBit  (c+65,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__bgeu));
	vcdp->chgBit  (c+66,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__lb));
	vcdp->chgBit  (c+67,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__lh));
	vcdp->chgBit  (c+68,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__lw));
	vcdp->chgBit  (c+69,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__lbu));
	vcdp->chgBit  (c+70,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__lhu));
	vcdp->chgBit  (c+71,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__sb));
	vcdp->chgBit  (c+72,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__sh));
	vcdp->chgBit  (c+73,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__sw));
	vcdp->chgBit  (c+74,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__addi));
	vcdp->chgBit  (c+75,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__slti));
	vcdp->chgBit  (c+76,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__sltiu));
	vcdp->chgBit  (c+77,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__xori));
	vcdp->chgBit  (c+78,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__ori));
	vcdp->chgBit  (c+79,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__andi));
	vcdp->chgBit  (c+80,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__slli));
	vcdp->chgBit  (c+81,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__srli));
	vcdp->chgBit  (c+82,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__srai));
	vcdp->chgBit  (c+83,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__add));
	vcdp->chgBit  (c+84,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__sub));
	vcdp->chgBit  (c+85,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__sll));
	vcdp->chgBit  (c+86,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__slt));
	vcdp->chgBit  (c+87,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__sltu));
	vcdp->chgBit  (c+88,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__srl));
	vcdp->chgBit  (c+89,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__sra));
	vcdp->chgBit  (c+90,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__rw));
	vcdp->chgBit  (c+91,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__rs));
	vcdp->chgBit  (c+92,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__rc));
	vcdp->chgBit  (c+93,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__rwi));
	vcdp->chgBit  (c+94,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__rsi));
	vcdp->chgBit  (c+95,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__rci));
	vcdp->chgBit  (c+96,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_imm));
	vcdp->chgBit  (c+97,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_add));
	vcdp->chgBit  (c+98,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_sub));
	vcdp->chgBit  (c+99,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_and));
	vcdp->chgBit  (c+100,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_xor));
	vcdp->chgBit  (c+101,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_or));
	vcdp->chgBit  (c+102,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_sll));
	vcdp->chgBit  (c+103,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_sr));
	vcdp->chgBit  (c+104,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_slt));
	vcdp->chgBit  (c+105,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_sltu));
	vcdp->chgBit  (c+106,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_wr));
	vcdp->chgBit  (c+107,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_alu));
	vcdp->chgBit  (c+108,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_immop));
	vcdp->chgBit  (c+109,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_csr));
	vcdp->chgBit  (c+110,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_word));
	vcdp->chgBit  (c+111,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_byte));
	vcdp->chgBit  (c+112,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_hw));
    }
}

void Vifid_stage::traceChgThis__4(Vifid_stage__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vifid_stage* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+113,(vlTOPp->ifid_stage__DOT__IF__DOT__if_stall_));
    }
}

void Vifid_stage::traceChgThis__5(Vifid_stage__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vifid_stage* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+114,((vlTOPp->ifid_stage__DOT__ID__DOT___imm 
			       + vlTOPp->ifid_stage__DOT__id_pc_add4)),32);
	vcdp->chgBit  (c+115,(((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_j) 
			       & (0U != (2U & vlTOPp->ifid_stage__DOT__ID__DOT___imm)))));
	vcdp->chgBit  (c+116,(((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_b) 
			       & (0U != (3U & (vlTOPp->ifid_stage__DOT__ID__DOT___imm 
					       + vlTOPp->ifid_stage__DOT__id_pc_add4))))));
    }
}

void Vifid_stage::traceChgThis__6(Vifid_stage__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vifid_stage* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+117,(vlTOPp->ifid_stage__DOT__IF__DOT__wbm_ack_i));
    }
}

void Vifid_stage::traceChgThis__7(Vifid_stage__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vifid_stage* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+118,(vlTOPp->ifid_stage__DOT__ID__DOT__drs1),32);
	vcdp->chgBus  (c+119,(vlTOPp->ifid_stage__DOT__ID__DOT__rs1),5);
	vcdp->chgBus  (c+120,(vlTOPp->ifid_stage__DOT__ID__DOT__comparator_op),3);
	vcdp->chgBus  (c+121,(vlTOPp->ifid_stage__DOT__ID__DOT__imm),32);
	vcdp->chgBus  (c+122,(vlTOPp->ifid_stage__DOT__ID__DOT__port_b),32);
    }
}

void Vifid_stage::traceChgThis__8(Vifid_stage__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vifid_stage* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+123,((0xfffffffeU & vlTOPp->ifid_stage__DOT__ID__DOT___imm)),32);
	vcdp->chgBus  (c+124,(vlTOPp->ifid_stage__DOT__IF__DOT__wbm_dat_i),32);
	vcdp->chgBit  (c+125,(vlTOPp->ifid_stage__DOT__IF__DOT__wbm_err_i));
	vcdp->chgBus  (c+126,(vlTOPp->ifid_stage__DOT__ID__DOT__port_a),32);
    }
}

void Vifid_stage::traceChgThis__9(Vifid_stage__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vifid_stage* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+127,(vlTOPp->ifid_stage__DOT__id_pc),32);
	vcdp->chgBus  (c+128,(vlTOPp->ifid_stage__DOT__id_pc_add4),32);
	vcdp->chgBus  (c+129,(vlTOPp->ifid_stage__DOT__id_instruction),32);
	vcdp->chgBit  (c+130,((0U != (3U & vlTOPp->ifid_stage__DOT__IF__DOT__if_pc_o))));
	vcdp->chgBit  (c+131,(vlTOPp->ifid_stage__DOT__id_ready_o));
	vcdp->chgBus  (c+132,(((2U & (IData)(vlTOPp->ifid_stage__DOT__IF__DOT__pc_sel))
			        ? ((1U & (IData)(vlTOPp->ifid_stage__DOT__IF__DOT__pc_sel))
				    ? vlTOPp->ifid_stage__DOT__IF__DOT__PC_SOURCE__DOT__in3
				    : vlTOPp->ifid_stage__DOT__IF__DOT__pc_jump_address)
			        : ((1U & (IData)(vlTOPp->ifid_stage__DOT__IF__DOT__pc_sel))
				    ? vlTOPp->ifid_stage__DOT__IF__DOT__pc_branch_address
				    : ((IData)(4U) 
				       + vlTOPp->ifid_stage__DOT__IF__DOT__if_pc_o)))),32);
	vcdp->chgBus  (c+133,(vlTOPp->ifid_stage__DOT__IF__DOT__if_pc_o),32);
	vcdp->chgBus  (c+134,(((IData)(4U) + vlTOPp->ifid_stage__DOT__IF__DOT__if_pc_o)),32);
	vcdp->chgBus  (c+135,(vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o),32);
	vcdp->chgBit  (c+136,(vlTOPp->ifid_stage__DOT__IF__DOT__wbm_ready_o));
	vcdp->chgBit  (c+137,(vlTOPp->ifid_stage__DOT__IF__DOT__id_exc_addr_o));
	vcdp->chgBit  (c+138,(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__abort));
	vcdp->chgBit  (c+139,(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__mem_stall));
	vcdp->chgBit  (c+140,(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__mem_bus_err));
	vcdp->chgBus  (c+141,(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__daddr_o),32);
	vcdp->chgBus  (c+142,(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__ddat_o),32);
	vcdp->chgBit  (c+143,(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__dcyc_o));
	vcdp->chgBit  (c+144,(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__dstb_o));
	vcdp->chgBit  (c+145,(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__dwe_o));
	vcdp->chgBus  (c+146,(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__rdata),32);
	vcdp->chgBus  (c+147,(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__i_state),2);
	vcdp->chgBus  (c+148,(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__d_state),2);
	vcdp->chgBit  (c+149,(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__if_stall_aux));
	vcdp->chgBus  (c+150,((0x1fU & (vlTOPp->ifid_stage__DOT__id_instruction 
					>> 0x14U))),5);
	vcdp->chgBus  (c+151,((0x1fU & (vlTOPp->ifid_stage__DOT__id_instruction 
					>> 7U))),5);
	vcdp->chgBit  (c+152,(((0x73U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
			       & (0x2000U == (0x1ffffffU 
					      & (vlTOPp->ifid_stage__DOT__id_instruction 
						 >> 7U))))));
	vcdp->chgBit  (c+153,(((0x73U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
			       & (0U == (0x1ffffffU 
					 & (vlTOPp->ifid_stage__DOT__id_instruction 
					    >> 7U))))));
	vcdp->chgBit  (c+154,(vlTOPp->ifid_stage__DOT__ID__DOT__ex_exc_address_if));
	vcdp->chgBus  (c+155,((0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)),7);
	vcdp->chgBus  (c+156,((7U & (vlTOPp->ifid_stage__DOT__id_instruction 
				     >> 0xcU))),3);
	vcdp->chgBus  (c+157,((0x7fU & (vlTOPp->ifid_stage__DOT__id_instruction 
					>> 0x19U))),7);
	vcdp->chgBit  (c+158,((0x33U == vlTOPp->ifid_stage__DOT__id_instruction)));
	vcdp->chgBit  (c+159,((((0x73U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
				& (0U == (3U & (vlTOPp->ifid_stage__DOT__id_instruction 
						>> 0x1eU)))) 
			       & (0x4000U == (0x1fffffU 
					      & (vlTOPp->ifid_stage__DOT__id_instruction 
						 >> 7U))))));
    }
}

void Vifid_stage::traceChgThis__10(Vifid_stage__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vifid_stage* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+160,(vlTOPp->ifid_stage__DOT__IF__DOT__if_instruction_o),32);
    }
}

void Vifid_stage::traceChgThis__11(Vifid_stage__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vifid_stage* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+161,(vlTOPp->ifid_stage__DOT__IF__DOT__wbm_cyc_o));
	vcdp->chgBit  (c+162,(vlTOPp->ifid_stage__DOT__IF__DOT__wbm_stb_o));
	vcdp->chgBit  (c+163,(vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__b_state));
    }
}

void Vifid_stage::traceChgThis__12(Vifid_stage__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vifid_stage* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+164,(vlTOPp->clk_i));
	vcdp->chgBit  (c+165,(vlTOPp->rst_i));
	vcdp->chgBus  (c+166,(vlTOPp->ex_port_a),32);
	vcdp->chgBus  (c+167,(vlTOPp->ex_port_b),32);
	vcdp->chgBus  (c+168,(vlTOPp->ex_alu_op),4);
	vcdp->chgBus  (c+169,(vlTOPp->ex_waddr),5);
	vcdp->chgBit  (c+170,(vlTOPp->ex_we));
	vcdp->chgBus  (c+171,(vlTOPp->ex_mem_flags),6);
	vcdp->chgBit  (c+172,(vlTOPp->ex_mem_ex_sel));
	vcdp->chgBit  (c+173,(vlTOPp->ex_jump_op));
	vcdp->chgBit  (c+174,(vlTOPp->ex_bad_jump_addr));
	vcdp->chgBit  (c+175,(vlTOPp->ex_branch_op));
	vcdp->chgBit  (c+176,(vlTOPp->ex_bad_branch_addr));
	vcdp->chgBit  (c+177,(vlTOPp->take_branch));
	vcdp->chgBit  (c+178,(vlTOPp->ex_break_op));
	vcdp->chgBit  (c+179,(vlTOPp->ex_syscall_op));
	vcdp->chgBus  (c+180,(vlTOPp->ex_csr_op),3);
	vcdp->chgBit  (c+181,(vlTOPp->ex_csr_imm_op));
	vcdp->chgBit  (c+182,(vlTOPp->ex_exc_addr_if_o));
	vcdp->chgBit  (c+183,(vlTOPp->ex_ready));
    }
}
