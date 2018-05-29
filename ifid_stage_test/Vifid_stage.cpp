// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vifid_stage.h for the primary calling header

#include "Vifid_stage.h"       // For This
#include "Vifid_stage__Syms.h"

//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vifid_stage) {
    Vifid_stage__Syms* __restrict vlSymsp = __VlSymsp = new Vifid_stage__Syms(this, name());
    Vifid_stage* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vifid_stage::__Vconfigure(Vifid_stage__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vifid_stage::~Vifid_stage() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vifid_stage::eval() {
    Vifid_stage__Syms* __restrict vlSymsp = this->__VlSymsp; // Setup global symbol table
    Vifid_stage* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    VL_DEBUG_IF(VL_PRINTF("\n----TOP Evaluate Vifid_stage::eval\n"); );
    int __VclockLoop = 0;
    QData __Vchange=1;
    while (VL_LIKELY(__Vchange)) {
	VL_DEBUG_IF(VL_PRINTF(" Clock loop\n"););
	vlSymsp->__Vm_activity = true;
	_eval(vlSymsp);
	__Vchange = _change_request(vlSymsp);
	if (++__VclockLoop > 100) vl_fatal(__FILE__,__LINE__,__FILE__,"Verilated model didn't converge");
    }
}

void Vifid_stage::_eval_initial_loop(Vifid_stage__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    int __VclockLoop = 0;
    QData __Vchange=1;
    while (VL_LIKELY(__Vchange)) {
	_eval_settle(vlSymsp);
	_eval(vlSymsp);
	__Vchange = _change_request(vlSymsp);
	if (++__VclockLoop > 100) vl_fatal(__FILE__,__LINE__,__FILE__,"Verilated model didn't DC converge");
    }
}

//--------------------
// Internal Methods

void Vifid_stage::_initial__TOP__1(Vifid_stage__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vifid_stage::_initial__TOP__1\n"); );
    Vifid_stage* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // INITIAL at ../software/bram.v:24
    vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__memory[0U] = 0U;
    vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__memory[1U] = 0U;
    vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__memory[2U] = 0x12U;
    vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__memory[3U] = 0x97U;
    vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__memory[4U] = 0U;
    vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__memory[5U] = 0xb5U;
    vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__memory[6U] = 0x70U;
    vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__memory[7U] = 0x63U;
    vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__memory[8U] = 0U;
    vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__memory[9U] = 0x11U;
    vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__memory[0xaU] = 0x22U;
    vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__memory[0xbU] = 0x23U;
    vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__memory[0xcU] = 0U;
    vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__memory[0xdU] = 0x41U;
    vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__memory[0xeU] = 0x20U;
    vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__memory[0xfU] = 0x83U;
    vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__memory[0x10U] = 0x80U;
    vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__memory[0x11U] = 2U;
    vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__memory[0x12U] = 0x82U;
    vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__memory[0x13U] = 0x93U;
    // INITIAL at ../software/lsu.v:68
    vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__idat_o = 0U;
    vlTOPp->ifid_stage__DOT__IF__DOT__wbm_sel_o = 0xfU;
    vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__no_mem = 1U;
    // INITIAL at ../software/reg_file.v:13
    vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file[0xeU] = 2U;
    vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file[0x12U] = 4U;
}

VL_INLINE_OPT void Vifid_stage::_sequent__TOP__2(Vifid_stage__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vifid_stage::_sequent__TOP__2\n"); );
    Vifid_stage* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIG8(__Vdly__ifid_stage__DOT__IF__DOT__LSU__DOT__i_state,1,0);
    VL_SIG8(__Vdly__ifid_stage__DOT__IF__DOT__wbm_ready_o,0,0);
    VL_SIG8(__Vdly__ifid_stage__DOT__IF__DOT__LSU__DOT__d_state,1,0);
    VL_SIG8(__Vdly__ifid_stage__DOT__IF__DOT__id_exc_addr_o,0,0);
    VL_SIG8(__Vdlyvdim0__ifid_stage__DOT__ID__DOT__RF__DOT__reg_file__v0,4,0);
    VL_SIG8(__Vdlyvset__ifid_stage__DOT__ID__DOT__RF__DOT__reg_file__v0,0,0);
    //char	__VpadToAlign30[2];
    VL_SIG(__Vdly__ifid_stage__DOT__IF__DOT__if_pc_o,31,0);
    VL_SIG(__Vdly__ifid_stage__DOT__id_pc,31,0);
    VL_SIG(__Vdly__ifid_stage__DOT__id_pc_add4,31,0);
    VL_SIG(__Vdly__ifid_stage__DOT__id_instruction,31,0);
    VL_SIG(__Vdlyvval__ifid_stage__DOT__ID__DOT__RF__DOT__reg_file__v0,31,0);
    //char	__VpadToAlign52[4];
    VL_SIG64(__Vdly__ifid_stage__DOT__IF__DOT__LSU__DOT__no_rps,63,0);
    // Body
    vlTOPp->__Vdly__ifid_stage__DOT__IF__DOT__BRAM__DOT__b_state 
	= vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__b_state;
    __Vdly__ifid_stage__DOT__IF__DOT__LSU__DOT__d_state 
	= vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__d_state;
    __Vdlyvset__ifid_stage__DOT__ID__DOT__RF__DOT__reg_file__v0 = 0U;
    vlTOPp->__Vdly__ifid_stage__DOT__IF__DOT__wbm_cyc_o 
	= vlTOPp->ifid_stage__DOT__IF__DOT__wbm_cyc_o;
    vlTOPp->__Vdly__ifid_stage__DOT__IF__DOT__wbm_stb_o 
	= vlTOPp->ifid_stage__DOT__IF__DOT__wbm_stb_o;
    __Vdly__ifid_stage__DOT__IF__DOT__LSU__DOT__i_state 
	= vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__i_state;
    __Vdly__ifid_stage__DOT__IF__DOT__wbm_ready_o = vlTOPp->ifid_stage__DOT__IF__DOT__wbm_ready_o;
    __Vdly__ifid_stage__DOT__IF__DOT__LSU__DOT__no_rps 
	= vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__no_rps;
    __Vdly__ifid_stage__DOT__IF__DOT__if_pc_o = vlTOPp->ifid_stage__DOT__IF__DOT__if_pc_o;
    __Vdly__ifid_stage__DOT__id_pc_add4 = vlTOPp->ifid_stage__DOT__id_pc_add4;
    __Vdly__ifid_stage__DOT__IF__DOT__id_exc_addr_o 
	= vlTOPp->ifid_stage__DOT__IF__DOT__id_exc_addr_o;
    __Vdly__ifid_stage__DOT__id_pc = vlTOPp->ifid_stage__DOT__id_pc;
    __Vdly__ifid_stage__DOT__id_instruction = vlTOPp->ifid_stage__DOT__id_instruction;
    // ALWAYS at ../software/lsu.v:138
    if (vlTOPp->rst_i) {
	vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__dsel_o = 0xfU;
	vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__ddat_o = 0U;
	vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__daddr_o = 0U;
	vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__dwe_o = 0U;
	vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__dcyc_o = 0U;
	vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__dstb_o = 0U;
	__Vdly__ifid_stage__DOT__IF__DOT__LSU__DOT__d_state = 0U;
	vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__mem_stall = 1U;
    } else {
	vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__mem_stall 
	    = (1U & (((IData)(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__mread) 
		      | (IData)(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__mwrite)) 
		     | (~ (IData)(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__dack_i))));
	if ((0U == (IData)(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__d_state))) {
	    vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__dcyc_o 
		= ((IData)(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__mread) 
		   ^ (IData)(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__mwrite));
	    vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__dstb_o 
		= ((IData)(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__mread) 
		   ^ (IData)(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__mwrite));
	    vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__dwe_o 
		= vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__mwrite;
	    vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__daddr_o 
		= vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__maddr_i;
	    __Vdly__ifid_stage__DOT__IF__DOT__LSU__DOT__d_state 
		= (((IData)(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__mread) 
		    ^ (IData)(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__mwrite))
		    ? 1U : 0U);
	} else {
	    if ((1U == (IData)(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__d_state))) {
		if (vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__dack_i) {
		    vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__dcyc_o = 0U;
		    vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__dstb_o = 0U;
		    vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__rdata 
			= vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__ddat_i;
		    vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__ddat_o 
			= vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__wdata;
		    __Vdly__ifid_stage__DOT__IF__DOT__LSU__DOT__d_state = 0U;
		} else {
		    if (vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__derr_i) {
			vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__mem_bus_err = 1U;
			__Vdly__ifid_stage__DOT__IF__DOT__LSU__DOT__d_state = 3U;
			vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__dcyc_o = 0U;
			vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__dstb_o = 0U;
		    }
		}
	    } else {
		if ((3U == (IData)(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__d_state))) {
		    vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__mem_bus_err = 0U;
		    vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__dcyc_o = 0U;
		    __Vdly__ifid_stage__DOT__IF__DOT__LSU__DOT__d_state = 0U;
		} else {
		    vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__dcyc_o = 0U;
		    vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__dstb_o = 0U;
		    __Vdly__ifid_stage__DOT__IF__DOT__LSU__DOT__d_state = 0U;
		}
	    }
	}
    }
    // ALWAYS at ../software/reg_file.v:23
    if (((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__wb_we) 
	 & (0U != (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__wb_address)))) {
	__Vdlyvval__ifid_stage__DOT__ID__DOT__RF__DOT__reg_file__v0 
	    = vlTOPp->ifid_stage__DOT__ID__DOT__wb_data;
	__Vdlyvset__ifid_stage__DOT__ID__DOT__RF__DOT__reg_file__v0 = 1U;
	__Vdlyvdim0__ifid_stage__DOT__ID__DOT__RF__DOT__reg_file__v0 
	    = vlTOPp->ifid_stage__DOT__ID__DOT__wb_address;
    }
    // ALWAYS at ../software/pc_reg.v:9
    __Vdly__ifid_stage__DOT__IF__DOT__if_pc_o = ((IData)(vlTOPp->rst_i)
						  ? 0U
						  : 
						 ((IData)(vlTOPp->ifid_stage__DOT__IF__DOT__if_stall_)
						   ? vlTOPp->ifid_stage__DOT__IF__DOT__if_pc_o
						   : vlTOPp->ifid_stage__DOT__IF__DOT__if_pc_mux));
    // ALWAYS at ../software/ifid_reg.v:20
    __Vdly__ifid_stage__DOT__id_pc = ((IData)(vlTOPp->rst_i)
				       ? 0U : ((IData)(vlTOPp->ifid_stage__DOT__IF__DOT__if_stall_)
					        ? vlTOPp->ifid_stage__DOT__id_pc
					        : vlTOPp->ifid_stage__DOT__IF__DOT__if_pc_o));
    __Vdly__ifid_stage__DOT__id_pc_add4 = ((IData)(vlTOPp->rst_i)
					    ? 0U : 
					   ((IData)(vlTOPp->ifid_stage__DOT__IF__DOT__if_stall_)
					     ? vlTOPp->ifid_stage__DOT__id_pc_add4
					     : ((IData)(4U) 
						+ vlTOPp->ifid_stage__DOT__IF__DOT__if_pc_o)));
    __Vdly__ifid_stage__DOT__IF__DOT__id_exc_addr_o 
	= ((~ (IData)(vlTOPp->rst_i)) & ((IData)(vlTOPp->ifid_stage__DOT__IF__DOT__if_stall_)
					  ? (IData)(vlTOPp->ifid_stage__DOT__IF__DOT__id_exc_addr_o)
					  : (0U != 
					     (3U & vlTOPp->ifid_stage__DOT__IF__DOT__if_pc_o))));
    __Vdly__ifid_stage__DOT__id_instruction = ((IData)(vlTOPp->rst_i)
					        ? 0x33U
					        : ((IData)(vlTOPp->ifid_stage__DOT__IF__DOT__if_stall_)
						    ? vlTOPp->ifid_stage__DOT__id_instruction
						    : vlTOPp->ifid_stage__DOT__IF__DOT__if_instruction_o));
    // ALWAYS at ../software/idex_register.v:39
    vlTOPp->ex_port_a = ((IData)(vlTOPp->rst_i) ? 0U
			  : vlTOPp->ifid_stage__DOT__ID__DOT__port_a);
    vlTOPp->ex_port_b = ((IData)(vlTOPp->rst_i) ? 0U
			  : vlTOPp->ifid_stage__DOT__ID__DOT__port_b);
    vlTOPp->ex_alu_op = ((IData)(vlTOPp->rst_i) ? 0U
			  : (((((((((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_add) 
				    | (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_sub)) 
				   | (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_and)) 
				  | (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_or)) 
				 | (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_xor)) 
				| (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_sll)) 
			       | (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_sr)) 
			      | (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_slt))
			      ? ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_add)
				  ? 0U : ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_sub)
					   ? 1U : ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_and)
						    ? 2U
						    : 
						   ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_or)
						     ? 3U
						     : 
						    ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_xor)
						      ? 4U
						      : 
						     ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_sll)
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
				  ? 9U : 0xfU)));
    vlTOPp->ex_we = ((~ (IData)(vlTOPp->rst_i)) & (
						   (0U 
						    != 
						    (0x1fU 
						     & (vlTOPp->ifid_stage__DOT__id_instruction 
							>> 7U))) 
						   & (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_wr)));
    vlTOPp->ex_mem_flags = ((IData)(vlTOPp->rst_i) ? 0U
			     : (((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_st) 
				 << 5U) | (((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_ld) 
					    << 4U) 
					   | (((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_word) 
					       << 3U) 
					      | (((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_hw) 
						  << 2U) 
						 | (((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_byte) 
						     << 1U) 
						    | (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_ldu)))))));
    vlTOPp->ex_mem_ex_sel = ((~ (IData)(vlTOPp->rst_i)) 
			     & ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_ld) 
				| (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_st)));
    vlTOPp->ex_bad_jump_addr = ((~ (IData)(vlTOPp->rst_i)) 
				& ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_j) 
				   & (0U != (2U & vlTOPp->ifid_stage__DOT__ID__DOT___imm))));
    vlTOPp->ex_bad_branch_addr = ((~ (IData)(vlTOPp->rst_i)) 
				  & ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_b) 
				     & (0U != (3U & 
					       (vlTOPp->ifid_stage__DOT__ID__DOT___imm 
						+ vlTOPp->ifid_stage__DOT__id_pc_add4)))));
    vlTOPp->ex_break_op = ((~ (IData)(vlTOPp->rst_i)) 
			   & ((0x73U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
			      & (0x2000U == (0x1ffffffU 
					     & (vlTOPp->ifid_stage__DOT__id_instruction 
						>> 7U)))));
    vlTOPp->ex_syscall_op = ((~ (IData)(vlTOPp->rst_i)) 
			     & ((0x73U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
				& (0U == (0x1ffffffU 
					  & (vlTOPp->ifid_stage__DOT__id_instruction 
					     >> 7U)))));
    vlTOPp->ex_csr_op = ((IData)(vlTOPp->rst_i) ? 0U
			  : (((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__rc) 
			      << 2U) | (((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__rs) 
					 << 1U) | (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__rw))));
    vlTOPp->ex_csr_imm_op = ((~ (IData)(vlTOPp->rst_i)) 
			     & (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_csri));
    vlTOPp->ex_waddr = (0x1fU & ((IData)(vlTOPp->rst_i)
				  ? 0U : (vlTOPp->ifid_stage__DOT__id_instruction 
					  >> 7U)));
    vlTOPp->ifid_stage__DOT__ID__DOT__ex_exc_address_if 
	= ((~ (IData)(vlTOPp->rst_i)) & (0U != (3U 
						& vlTOPp->ifid_stage__DOT__IF__DOT__if_pc_o)));
    vlTOPp->ex_ready = ((~ (IData)(vlTOPp->rst_i)) 
			& (IData)(vlTOPp->ifid_stage__DOT__id_ready_o));
    vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__d_state 
	= __Vdly__ifid_stage__DOT__IF__DOT__LSU__DOT__d_state;
    // ALWAYSPOST at ../software/reg_file.v:24
    if (__Vdlyvset__ifid_stage__DOT__ID__DOT__RF__DOT__reg_file__v0) {
	vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file[__Vdlyvdim0__ifid_stage__DOT__ID__DOT__RF__DOT__reg_file__v0] 
	    = __Vdlyvval__ifid_stage__DOT__ID__DOT__RF__DOT__reg_file__v0;
    }
    vlTOPp->ifid_stage__DOT__IF__DOT__id_exc_addr_o 
	= __Vdly__ifid_stage__DOT__IF__DOT__id_exc_addr_o;
    vlTOPp->ifid_stage__DOT__id_pc = __Vdly__ifid_stage__DOT__id_pc;
    vlTOPp->ifid_stage__DOT__id_pc_add4 = __Vdly__ifid_stage__DOT__id_pc_add4;
    vlTOPp->ifid_stage__DOT__id_instruction = __Vdly__ifid_stage__DOT__id_instruction;
    // ALWAYS at ../software/lsu.v:187
    if (vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__mread) {
	vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__data_o 
	    = ((IData)(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__mbyte)
	        ? ((0xffffff00U & (((IData)(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__munsigned)
				     ? 0U : VL_NEGATE_I((IData)(
								(1U 
								 & (vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__rdata 
								    >> 7U))))) 
				   << 8U)) | (0xffU 
					      & vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__rdata))
	        : ((IData)(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__mhw)
		    ? ((0xffff0000U & (((IData)(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__munsigned)
					 ? 0U : VL_NEGATE_I((IData)(
								    (1U 
								     & (vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__rdata 
									>> 0xfU))))) 
				       << 0x10U)) | 
		       (0xffffU & vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__rdata))
		    : vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__rdata));
    } else {
	if (vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__mwrite) {
	    if (vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__mbyte) {
		vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__wdata 
		    = (0xffU & vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__mdat_i);
		vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__dsel_o = 1U;
	    } else {
		if (vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__mhw) {
		    vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__wdata 
			= (0xffffU & vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__mdat_i);
		    vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__dsel_o = 3U;
		} else {
		    vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__wdata 
			= vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__mdat_i;
		    vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__dsel_o = 0xfU;
		}
	    }
	}
    }
    // ALWAYS at ../software/lsu.v:78
    if (vlTOPp->rst_i) {
	vlTOPp->ifid_stage__DOT__IF__DOT__wbm_sel_o = 0xfU;
	vlTOPp->ifid_stage__DOT__IF__DOT__if_stall_ = 1U;
	__Vdly__ifid_stage__DOT__IF__DOT__LSU__DOT__i_state = 0U;
	vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o = 0U;
	vlTOPp->__Vdly__ifid_stage__DOT__IF__DOT__wbm_cyc_o = 0U;
	vlTOPp->__Vdly__ifid_stage__DOT__IF__DOT__wbm_stb_o = 0U;
	vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__abort = 0U;
	__Vdly__ifid_stage__DOT__IF__DOT__wbm_ready_o = 0U;
    } else {
	__Vdly__ifid_stage__DOT__IF__DOT__wbm_ready_o 
	    = ((~ (IData)(vlTOPp->ifid_stage__DOT__IF__DOT__wbm_ready_o)) 
	       & (IData)(vlTOPp->ifid_stage__DOT__IF__DOT__wbm_ack_i));
	vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__if_stall_aux 
	    = vlTOPp->ifid_stage__DOT__IF__DOT__wbm_ack_i;
	if ((0U == (IData)(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__i_state))) {
	    vlTOPp->__Vdly__ifid_stage__DOT__IF__DOT__wbm_cyc_o 
		= (0U == (3U & vlTOPp->ifid_stage__DOT__IF__DOT__if_pc_o));
	    vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o 
		= vlTOPp->ifid_stage__DOT__IF__DOT__if_pc_o;
	    vlTOPp->__Vdly__ifid_stage__DOT__IF__DOT__wbm_stb_o 
		= (0U == (3U & vlTOPp->ifid_stage__DOT__IF__DOT__if_pc_o));
	    if (vlTOPp->ifid_stage__DOT__IF__DOT__wbm_ack_i) {
		vlTOPp->__Vdly__ifid_stage__DOT__IF__DOT__wbm_cyc_o = 0U;
		vlTOPp->__Vdly__ifid_stage__DOT__IF__DOT__wbm_stb_o = 0U;
		__Vdly__ifid_stage__DOT__IF__DOT__LSU__DOT__i_state = 0U;
		__Vdly__ifid_stage__DOT__IF__DOT__LSU__DOT__no_rps = VL_ULL(0x8000000000000000);
	    } else {
		if (vlTOPp->ifid_stage__DOT__IF__DOT__wbm_err_i) {
		    vlTOPp->__Vdly__ifid_stage__DOT__IF__DOT__wbm_cyc_o = 0U;
		    vlTOPp->__Vdly__ifid_stage__DOT__IF__DOT__wbm_stb_o = 0U;
		    __Vdly__ifid_stage__DOT__IF__DOT__LSU__DOT__i_state = 2U;
		} else {
		    __Vdly__ifid_stage__DOT__IF__DOT__LSU__DOT__no_rps 
			= (((QData)((IData)((1U & (IData)(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__no_rps)))) 
			    << 0x3fU) | (VL_ULL(0x7fffffffffffffff) 
					 & (vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__no_rps 
					    >> 1U)));
		    if ((VL_ULL(1) == vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__no_rps)) {
			vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__abort = 1U;
			vlTOPp->__Vdly__ifid_stage__DOT__IF__DOT__wbm_cyc_o = 0U;
			vlTOPp->__Vdly__ifid_stage__DOT__IF__DOT__wbm_stb_o = 0U;
			vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__no_mem = 1U;
			__Vdly__ifid_stage__DOT__IF__DOT__LSU__DOT__i_state = 1U;
		    }
		}
	    }
	} else {
	    if ((1U == (IData)(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__i_state))) {
		__Vdly__ifid_stage__DOT__IF__DOT__LSU__DOT__i_state = 1U;
	    } else {
		if ((2U == (IData)(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__i_state))) {
		    __Vdly__ifid_stage__DOT__IF__DOT__LSU__DOT__i_state = 0U;
		} else {
		    __Vdly__ifid_stage__DOT__IF__DOT__LSU__DOT__i_state = 0U;
		    vlTOPp->__Vdly__ifid_stage__DOT__IF__DOT__wbm_cyc_o = 0U;
		}
	    }
	}
    }
    // ALWAYS at ../software/ifid_reg.v:24
    vlTOPp->ifid_stage__DOT__id_ready_o = vlTOPp->ifid_stage__DOT__IF__DOT__wbm_ready_o;
    vlTOPp->ifid_stage__DOT__ID__DOT__drs2 = ((0U == 
					       (0x1fU 
						& (vlTOPp->ifid_stage__DOT__id_instruction 
						   >> 0x14U)))
					       ? 0U
					       : vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file
					      [(0x1fU 
						& (vlTOPp->ifid_stage__DOT__id_instruction 
						   >> 0x14U))]);
    // ALWAYS at ../software/dc_unit.v:143
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__rw 
	= ((0x73U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	   & (1U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__rs 
	= ((0x73U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	   & (2U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__rc 
	= ((0x73U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	   & (3U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__rwi 
	= ((0x73U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	   & (5U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__rsi 
	= ((0x73U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	   & (6U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__rci 
	= ((0x73U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	   & (7U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_csr 
	= ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__rw) 
	   | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__rs) 
	      | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__rc) 
		 | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__rwi) 
		    | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__rsi) 
		       | (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__rci))))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_csri 
	= ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__rwi) 
	   | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__rsi) 
	      | (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__rci)));
    // ALWAYS at ../software/dc_unit.v:104
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__beq 
	= ((0x63U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	   & (0U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__bne 
	= ((0x63U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	   & (1U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__blt 
	= ((0x63U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	   & (4U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__bge 
	= ((0x63U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	   & (5U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__bltu 
	= ((0x63U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	   & (6U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__bgeu 
	= ((0x63U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	   & (7U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_b 
	= ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__beq) 
	   | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__bne) 
	      | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__blt) 
		 | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__bge) 
		    | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__bltu) 
		       | (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__bgeu))))));
    // ALWAYS at ../software/dc_unit.v:98
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__lui 
	= (0x37U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__auipc 
	= (0x17U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__jal 
	= (0x6fU == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__jalr 
	= (0x67U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__lb 
	= ((3U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	   & (0U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__lh 
	= ((3U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	   & (1U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__lw 
	= ((3U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	   & (2U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__lbu 
	= ((3U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	   & (4U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__lhu 
	= ((3U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	   & (5U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__sb 
	= ((0x23U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	   & (0U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__sh 
	= ((0x23U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	   & (1U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__sw 
	= ((0x23U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	   & (2U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__addi 
	= ((0x13U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	   & (0U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__slti 
	= ((0x13U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	   & (2U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__sltiu 
	= ((0x13U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	   & (3U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__xori 
	= ((0x13U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	   & (4U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__ori 
	= ((0x13U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	   & (6U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__andi 
	= ((0x13U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	   & (7U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__slli 
	= (((0x13U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	    & (1U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			    >> 0xcU)))) & (0U == (0x7fU 
						  & (vlTOPp->ifid_stage__DOT__id_instruction 
						     >> 0x19U))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__srli 
	= (((0x13U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	    & (5U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			    >> 0xcU)))) & (0U == (0x7fU 
						  & (vlTOPp->ifid_stage__DOT__id_instruction 
						     >> 0x19U))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__srai 
	= (((0x13U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	    & (5U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			    >> 0xcU)))) & (0x20U == 
					   (0x7fU & 
					    (vlTOPp->ifid_stage__DOT__id_instruction 
					     >> 0x19U))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__add 
	= (((0x33U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	    & (0U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			    >> 0xcU)))) & (0U == (0x7fU 
						  & (vlTOPp->ifid_stage__DOT__id_instruction 
						     >> 0x19U))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__sub 
	= (((0x33U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	    & (0U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			    >> 0xcU)))) & (0x20U == 
					   (0x7fU & 
					    (vlTOPp->ifid_stage__DOT__id_instruction 
					     >> 0x19U))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__slt 
	= (((0x33U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	    & (2U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			    >> 0xcU)))) & (0U == (0x7fU 
						  & (vlTOPp->ifid_stage__DOT__id_instruction 
						     >> 0x19U))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__sltu 
	= (((0x33U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	    & (3U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			    >> 0xcU)))) & (0U == (0x7fU 
						  & (vlTOPp->ifid_stage__DOT__id_instruction 
						     >> 0x19U))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT___xor 
	= (((0x33U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	    & (4U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			    >> 0xcU)))) & (0U == (0x7fU 
						  & (vlTOPp->ifid_stage__DOT__id_instruction 
						     >> 0x19U))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT___or 
	= (((0x33U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	    & (6U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			    >> 0xcU)))) & (0U == (0x7fU 
						  & (vlTOPp->ifid_stage__DOT__id_instruction 
						     >> 0x19U))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT___and 
	= (((0x33U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	    & (7U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			    >> 0xcU)))) & (0U == (0x7fU 
						  & (vlTOPp->ifid_stage__DOT__id_instruction 
						     >> 0x19U))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__sll 
	= (((0x33U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	    & (1U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			    >> 0xcU)))) & (0U == (0x7fU 
						  & (vlTOPp->ifid_stage__DOT__id_instruction 
						     >> 0x19U))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__srl 
	= (((0x33U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	    & (5U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			    >> 0xcU)))) & (0U == (0x7fU 
						  & (vlTOPp->ifid_stage__DOT__id_instruction 
						     >> 0x19U))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__sra 
	= (((0x33U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	    & (5U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			    >> 0xcU)))) & (0x20U == 
					   (0x7fU & 
					    (vlTOPp->ifid_stage__DOT__id_instruction 
					     >> 0x19U))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_word 
	= ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__lw) 
	   | (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__sw));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_hw 
	= ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__lh) 
	   | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__lhu) 
	      | (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__sh)));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_byte 
	= ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__lb) 
	   | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__lbu) 
	      | (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__sb)));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_ldu 
	= ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__lbu) 
	   | (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__lhu));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_j 
	= ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__jal) 
	   | (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__jalr));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_st 
	= ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__sb) 
	   | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__sh) 
	      | (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__sw)));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_ld 
	= ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__lb) 
	   | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__lbu) 
	      | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__lh) 
		 | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__lhu) 
		    | (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__lw)))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_imm 
	= ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__addi) 
	   | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__slti) 
	      | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__sltiu) 
		 | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__ori) 
		    | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__andi) 
		       | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__slli) 
			  | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__srli) 
			     | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__srai) 
				| ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__xori) 
				   | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_ld) 
				      | (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__jalr)))))))))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_add 
	= ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__add) 
	   | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__addi) 
	      | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_st) 
		 | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_ld) 
		    | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__lui) 
		       | (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__auipc))))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_sub 
	= vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__sub;
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_xor 
	= ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT___xor) 
	   | (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__xori));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_and 
	= ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT___and) 
	   | (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__andi));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_or 
	= ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT___or) 
	   | (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__ori));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_sll 
	= ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__sll) 
	   | (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__slli));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_sr 
	= ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__sra) 
	   | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__srl) 
	      | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__srai) 
		 | (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__srli))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_slt 
	= ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__slt) 
	   | (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__slti));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_sltu 
	= ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__sltu) 
	   | (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__sltiu));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_alu 
	= ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__add) 
	   | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__addi) 
	      | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__sub) 
		 | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_xor) 
		    | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_and) 
		       | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_or) 
			  | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_sll) 
			     | (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_sr))))))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_immop 
	= ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__addi) 
	   | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__slti) 
	      | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__sltiu) 
		 | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__ori) 
		    | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__andi) 
		       | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__xori) 
			  | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__jalr) 
			     | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_st) 
				| ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_ld) 
				   | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__lui) 
				      | (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__auipc)))))))))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_wr 
	= ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_imm) 
	   | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_alu) 
	      | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_ld) 
		 | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__auipc) 
		    | (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__lui)))));
    vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__i_state 
	= __Vdly__ifid_stage__DOT__IF__DOT__LSU__DOT__i_state;
    vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__no_rps 
	= __Vdly__ifid_stage__DOT__IF__DOT__LSU__DOT__no_rps;
    vlTOPp->ifid_stage__DOT__IF__DOT__if_pc_o = __Vdly__ifid_stage__DOT__IF__DOT__if_pc_o;
    vlTOPp->__Vdly__ifid_stage__DOT__IF__DOT__wbm_ack_i 
	= vlTOPp->ifid_stage__DOT__IF__DOT__wbm_ack_i;
    vlTOPp->ifid_stage__DOT__IF__DOT__wbm_ready_o = __Vdly__ifid_stage__DOT__IF__DOT__wbm_ready_o;
    // ALWAYS at ../software/pc_source.v:10
    vlTOPp->ifid_stage__DOT__IF__DOT__if_pc_mux = (
						   (2U 
						    & (IData)(vlTOPp->ifid_stage__DOT__IF__DOT__pc_sel))
						    ? 
						   ((1U 
						     & (IData)(vlTOPp->ifid_stage__DOT__IF__DOT__pc_sel))
						     ? vlTOPp->ifid_stage__DOT__IF__DOT__PC_SOURCE__DOT__in3
						     : vlTOPp->ifid_stage__DOT__IF__DOT__pc_jump_address)
						    : 
						   ((1U 
						     & (IData)(vlTOPp->ifid_stage__DOT__IF__DOT__pc_sel))
						     ? vlTOPp->ifid_stage__DOT__IF__DOT__pc_branch_address
						     : 
						    ((IData)(4U) 
						     + vlTOPp->ifid_stage__DOT__IF__DOT__if_pc_o)));
}

void Vifid_stage::_settle__TOP__3(Vifid_stage__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vifid_stage::_settle__TOP__3\n"); );
    Vifid_stage* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at ../software/lsu.v:187
    if (vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__mread) {
	vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__data_o 
	    = ((IData)(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__mbyte)
	        ? ((0xffffff00U & (((IData)(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__munsigned)
				     ? 0U : VL_NEGATE_I((IData)(
								(1U 
								 & (vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__rdata 
								    >> 7U))))) 
				   << 8U)) | (0xffU 
					      & vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__rdata))
	        : ((IData)(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__mhw)
		    ? ((0xffff0000U & (((IData)(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__munsigned)
					 ? 0U : VL_NEGATE_I((IData)(
								    (1U 
								     & (vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__rdata 
									>> 0xfU))))) 
				       << 0x10U)) | 
		       (0xffffU & vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__rdata))
		    : vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__rdata));
    } else {
	if (vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__mwrite) {
	    if (vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__mbyte) {
		vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__wdata 
		    = (0xffU & vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__mdat_i);
		vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__dsel_o = 1U;
	    } else {
		if (vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__mhw) {
		    vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__wdata 
			= (0xffffU & vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__mdat_i);
		    vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__dsel_o = 3U;
		} else {
		    vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__wdata 
			= vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__mdat_i;
		    vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__dsel_o = 0xfU;
		}
	    }
	}
    }
    vlTOPp->ifid_stage__DOT__ID__DOT__drs2 = ((0U == 
					       (0x1fU 
						& (vlTOPp->ifid_stage__DOT__id_instruction 
						   >> 0x14U)))
					       ? 0U
					       : vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file
					      [(0x1fU 
						& (vlTOPp->ifid_stage__DOT__id_instruction 
						   >> 0x14U))]);
    // ALWAYS at ../software/dc_unit.v:143
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__rw 
	= ((0x73U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	   & (1U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__rs 
	= ((0x73U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	   & (2U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__rc 
	= ((0x73U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	   & (3U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__rwi 
	= ((0x73U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	   & (5U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__rsi 
	= ((0x73U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	   & (6U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__rci 
	= ((0x73U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	   & (7U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_csr 
	= ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__rw) 
	   | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__rs) 
	      | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__rc) 
		 | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__rwi) 
		    | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__rsi) 
		       | (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__rci))))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_csri 
	= ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__rwi) 
	   | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__rsi) 
	      | (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__rci)));
    // ALWAYS at ../software/dc_unit.v:104
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__beq 
	= ((0x63U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	   & (0U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__bne 
	= ((0x63U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	   & (1U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__blt 
	= ((0x63U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	   & (4U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__bge 
	= ((0x63U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	   & (5U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__bltu 
	= ((0x63U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	   & (6U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__bgeu 
	= ((0x63U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	   & (7U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_b 
	= ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__beq) 
	   | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__bne) 
	      | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__blt) 
		 | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__bge) 
		    | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__bltu) 
		       | (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__bgeu))))));
    // ALWAYS at ../software/dc_unit.v:98
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__lui 
	= (0x37U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__auipc 
	= (0x17U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__jal 
	= (0x6fU == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__jalr 
	= (0x67U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__lb 
	= ((3U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	   & (0U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__lh 
	= ((3U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	   & (1U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__lw 
	= ((3U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	   & (2U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__lbu 
	= ((3U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	   & (4U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__lhu 
	= ((3U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	   & (5U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__sb 
	= ((0x23U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	   & (0U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__sh 
	= ((0x23U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	   & (1U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__sw 
	= ((0x23U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	   & (2U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__addi 
	= ((0x13U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	   & (0U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__slti 
	= ((0x13U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	   & (2U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__sltiu 
	= ((0x13U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	   & (3U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__xori 
	= ((0x13U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	   & (4U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__ori 
	= ((0x13U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	   & (6U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__andi 
	= ((0x13U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	   & (7U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__slli 
	= (((0x13U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	    & (1U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			    >> 0xcU)))) & (0U == (0x7fU 
						  & (vlTOPp->ifid_stage__DOT__id_instruction 
						     >> 0x19U))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__srli 
	= (((0x13U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	    & (5U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			    >> 0xcU)))) & (0U == (0x7fU 
						  & (vlTOPp->ifid_stage__DOT__id_instruction 
						     >> 0x19U))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__srai 
	= (((0x13U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	    & (5U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			    >> 0xcU)))) & (0x20U == 
					   (0x7fU & 
					    (vlTOPp->ifid_stage__DOT__id_instruction 
					     >> 0x19U))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__add 
	= (((0x33U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	    & (0U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			    >> 0xcU)))) & (0U == (0x7fU 
						  & (vlTOPp->ifid_stage__DOT__id_instruction 
						     >> 0x19U))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__sub 
	= (((0x33U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	    & (0U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			    >> 0xcU)))) & (0x20U == 
					   (0x7fU & 
					    (vlTOPp->ifid_stage__DOT__id_instruction 
					     >> 0x19U))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__slt 
	= (((0x33U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	    & (2U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			    >> 0xcU)))) & (0U == (0x7fU 
						  & (vlTOPp->ifid_stage__DOT__id_instruction 
						     >> 0x19U))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__sltu 
	= (((0x33U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	    & (3U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			    >> 0xcU)))) & (0U == (0x7fU 
						  & (vlTOPp->ifid_stage__DOT__id_instruction 
						     >> 0x19U))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT___xor 
	= (((0x33U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	    & (4U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			    >> 0xcU)))) & (0U == (0x7fU 
						  & (vlTOPp->ifid_stage__DOT__id_instruction 
						     >> 0x19U))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT___or 
	= (((0x33U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	    & (6U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			    >> 0xcU)))) & (0U == (0x7fU 
						  & (vlTOPp->ifid_stage__DOT__id_instruction 
						     >> 0x19U))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT___and 
	= (((0x33U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	    & (7U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			    >> 0xcU)))) & (0U == (0x7fU 
						  & (vlTOPp->ifid_stage__DOT__id_instruction 
						     >> 0x19U))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__sll 
	= (((0x33U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	    & (1U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			    >> 0xcU)))) & (0U == (0x7fU 
						  & (vlTOPp->ifid_stage__DOT__id_instruction 
						     >> 0x19U))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__srl 
	= (((0x33U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	    & (5U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			    >> 0xcU)))) & (0U == (0x7fU 
						  & (vlTOPp->ifid_stage__DOT__id_instruction 
						     >> 0x19U))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__sra 
	= (((0x33U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
	    & (5U == (7U & (vlTOPp->ifid_stage__DOT__id_instruction 
			    >> 0xcU)))) & (0x20U == 
					   (0x7fU & 
					    (vlTOPp->ifid_stage__DOT__id_instruction 
					     >> 0x19U))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_word 
	= ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__lw) 
	   | (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__sw));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_hw 
	= ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__lh) 
	   | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__lhu) 
	      | (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__sh)));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_byte 
	= ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__lb) 
	   | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__lbu) 
	      | (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__sb)));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_ldu 
	= ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__lbu) 
	   | (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__lhu));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_j 
	= ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__jal) 
	   | (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__jalr));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_st 
	= ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__sb) 
	   | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__sh) 
	      | (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__sw)));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_ld 
	= ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__lb) 
	   | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__lbu) 
	      | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__lh) 
		 | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__lhu) 
		    | (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__lw)))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_imm 
	= ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__addi) 
	   | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__slti) 
	      | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__sltiu) 
		 | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__ori) 
		    | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__andi) 
		       | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__slli) 
			  | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__srli) 
			     | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__srai) 
				| ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__xori) 
				   | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_ld) 
				      | (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__jalr)))))))))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_add 
	= ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__add) 
	   | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__addi) 
	      | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_st) 
		 | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_ld) 
		    | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__lui) 
		       | (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__auipc))))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_sub 
	= vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__sub;
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_xor 
	= ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT___xor) 
	   | (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__xori));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_and 
	= ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT___and) 
	   | (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__andi));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_or 
	= ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT___or) 
	   | (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__ori));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_sll 
	= ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__sll) 
	   | (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__slli));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_sr 
	= ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__sra) 
	   | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__srl) 
	      | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__srai) 
		 | (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__srli))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_slt 
	= ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__slt) 
	   | (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__slti));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_sltu 
	= ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__sltu) 
	   | (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__sltiu));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_alu 
	= ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__add) 
	   | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__addi) 
	      | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__sub) 
		 | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_xor) 
		    | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_and) 
		       | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_or) 
			  | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_sll) 
			     | (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_sr))))))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_immop 
	= ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__addi) 
	   | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__slti) 
	      | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__sltiu) 
		 | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__ori) 
		    | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__andi) 
		       | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__xori) 
			  | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__jalr) 
			     | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_st) 
				| ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_ld) 
				   | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__lui) 
				      | (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__auipc)))))))))));
    vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_wr 
	= ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_imm) 
	   | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_alu) 
	      | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_ld) 
		 | ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__auipc) 
		    | (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__lui)))));
    // ALWAYS at ../software/bram.v:56
    if ((1U & (~ ((IData)(vlTOPp->ifid_stage__DOT__IF__DOT__wbm_cyc_o) 
		  & (IData)(vlTOPp->ifid_stage__DOT__IF__DOT__wbm_stb_o))))) {
	vlTOPp->ifid_stage__DOT__IF__DOT__wbm_ack_i = 0U;
    }
    // ALWAYS at ../software/pc_source.v:10
    vlTOPp->ifid_stage__DOT__IF__DOT__if_pc_mux = (
						   (2U 
						    & (IData)(vlTOPp->ifid_stage__DOT__IF__DOT__pc_sel))
						    ? 
						   ((1U 
						     & (IData)(vlTOPp->ifid_stage__DOT__IF__DOT__pc_sel))
						     ? vlTOPp->ifid_stage__DOT__IF__DOT__PC_SOURCE__DOT__in3
						     : vlTOPp->ifid_stage__DOT__IF__DOT__pc_jump_address)
						    : 
						   ((1U 
						     & (IData)(vlTOPp->ifid_stage__DOT__IF__DOT__pc_sel))
						     ? vlTOPp->ifid_stage__DOT__IF__DOT__pc_branch_address
						     : 
						    ((IData)(4U) 
						     + vlTOPp->ifid_stage__DOT__IF__DOT__if_pc_o)));
    // ALWAYS at ../software/dc_unit.v:206
    vlTOPp->ifid_stage__DOT__ID__DOT__comparator_op 
	= ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__beq)
	    ? 1U : ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__bne)
		     ? 2U : ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__blt)
			      ? 3U : ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__bge)
				       ? 4U : ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__bltu)
					        ? 5U
					        : ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__bgeu)
						    ? 6U
						    : 0U))))));
    // ALWAYS at ../software/dc_unit.v:186
    if (((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__lui) 
	 | (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__auipc))) {
	vlTOPp->ifid_stage__DOT__ID__DOT__imm = (0xfffff000U 
						 & vlTOPp->ifid_stage__DOT__id_instruction);
    } else {
	if (vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__jal) {
	    vlTOPp->ifid_stage__DOT__ID__DOT__imm = 
		((((0x80000000U & vlTOPp->ifid_stage__DOT__id_instruction)
		    ? 0xfffU : 0U) << 0x14U) | ((0x80000U 
						 & (vlTOPp->ifid_stage__DOT__id_instruction 
						    >> 0xcU)) 
						| ((0x7f800U 
						    & (vlTOPp->ifid_stage__DOT__id_instruction 
						       >> 1U)) 
						   | ((0x400U 
						       & (vlTOPp->ifid_stage__DOT__id_instruction 
							  >> 0xaU)) 
						      | (0x3ffU 
							 & (vlTOPp->ifid_stage__DOT__id_instruction 
							    >> 0x15U))))));
	} else {
	    if (vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_b) {
		vlTOPp->ifid_stage__DOT__ID__DOT__imm 
		    = ((((0x80000000U & vlTOPp->ifid_stage__DOT__id_instruction)
			  ? 0xfffffU : 0U) << 0xcU) 
		       | ((0x800U & (vlTOPp->ifid_stage__DOT__id_instruction 
				     >> 0x14U)) | (
						   (0x400U 
						    & (vlTOPp->ifid_stage__DOT__id_instruction 
						       << 3U)) 
						   | ((0x3f0U 
						       & (vlTOPp->ifid_stage__DOT__id_instruction 
							  >> 0x15U)) 
						      | (0xfU 
							 & (vlTOPp->ifid_stage__DOT__id_instruction 
							    >> 8U))))));
	    } else {
		if (vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_imm) {
		    vlTOPp->ifid_stage__DOT__ID__DOT__imm 
			= ((((0x80000000U & vlTOPp->ifid_stage__DOT__id_instruction)
			      ? 0xfffffU : 0U) << 0xcU) 
			   | (0xfffU & (vlTOPp->ifid_stage__DOT__id_instruction 
					>> 0x14U)));
		} else {
		    if (vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_st) {
			vlTOPp->ifid_stage__DOT__ID__DOT__imm 
			    = ((((0x80000000U & vlTOPp->ifid_stage__DOT__id_instruction)
				  ? 0xfffffU : 0U) 
				<< 0xcU) | ((0xfe0U 
					     & (vlTOPp->ifid_stage__DOT__id_instruction 
						>> 0x14U)) 
					    | (0x1fU 
					       & (vlTOPp->ifid_stage__DOT__id_instruction 
						  >> 7U))));
		    } else {
			if (vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_csri) {
			    vlTOPp->ifid_stage__DOT__ID__DOT__imm 
				= (0x1fU & (vlTOPp->ifid_stage__DOT__id_instruction 
					    >> 0xfU));
			}
		    }
		}
	    }
	}
    }
    vlTOPp->ifid_stage__DOT__ID__DOT__rs1 = (0x1fU 
					     & ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__lui)
						 ? 0U
						 : 
						(vlTOPp->ifid_stage__DOT__id_instruction 
						 >> 0xfU)));
}

void Vifid_stage::_initial__TOP__4(Vifid_stage__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vifid_stage::_initial__TOP__4\n"); );
    Vifid_stage* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // INITIAL at ../software/lsu.v:61
    vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__no_rps = VL_ULL(0x8000000000000000);
}

VL_INLINE_OPT void Vifid_stage::_combo__TOP__5(Vifid_stage__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vifid_stage::_combo__TOP__5\n"); );
    Vifid_stage* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at ../software/bram.v:56
    if ((1U & (~ ((IData)(vlTOPp->ifid_stage__DOT__IF__DOT__wbm_cyc_o) 
		  & (IData)(vlTOPp->ifid_stage__DOT__IF__DOT__wbm_stb_o))))) {
	vlTOPp->ifid_stage__DOT__IF__DOT__wbm_ack_i = 0U;
    }
    // ALWAYS at ../software/lsu.v:74
    vlTOPp->ifid_stage__DOT__IF__DOT__if_stall_ = (1U 
						   & ((~ (IData)(vlTOPp->ifid_stage__DOT__IF__DOT__wbm_ack_i)) 
						      | (IData)(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__if_stall_aux)));
}

VL_INLINE_OPT void Vifid_stage::_sequent__TOP__6(Vifid_stage__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vifid_stage::_sequent__TOP__6\n"); );
    Vifid_stage* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at ../software/dc_unit.v:206
    vlTOPp->ifid_stage__DOT__ID__DOT__comparator_op 
	= ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__beq)
	    ? 1U : ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__bne)
		     ? 2U : ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__blt)
			      ? 3U : ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__bge)
				       ? 4U : ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__bltu)
					        ? 5U
					        : ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__bgeu)
						    ? 6U
						    : 0U))))));
    // ALWAYS at ../software/dc_unit.v:186
    if (((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__lui) 
	 | (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__auipc))) {
	vlTOPp->ifid_stage__DOT__ID__DOT__imm = (0xfffff000U 
						 & vlTOPp->ifid_stage__DOT__id_instruction);
    } else {
	if (vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__jal) {
	    vlTOPp->ifid_stage__DOT__ID__DOT__imm = 
		((((0x80000000U & vlTOPp->ifid_stage__DOT__id_instruction)
		    ? 0xfffU : 0U) << 0x14U) | ((0x80000U 
						 & (vlTOPp->ifid_stage__DOT__id_instruction 
						    >> 0xcU)) 
						| ((0x7f800U 
						    & (vlTOPp->ifid_stage__DOT__id_instruction 
						       >> 1U)) 
						   | ((0x400U 
						       & (vlTOPp->ifid_stage__DOT__id_instruction 
							  >> 0xaU)) 
						      | (0x3ffU 
							 & (vlTOPp->ifid_stage__DOT__id_instruction 
							    >> 0x15U))))));
	} else {
	    if (vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_b) {
		vlTOPp->ifid_stage__DOT__ID__DOT__imm 
		    = ((((0x80000000U & vlTOPp->ifid_stage__DOT__id_instruction)
			  ? 0xfffffU : 0U) << 0xcU) 
		       | ((0x800U & (vlTOPp->ifid_stage__DOT__id_instruction 
				     >> 0x14U)) | (
						   (0x400U 
						    & (vlTOPp->ifid_stage__DOT__id_instruction 
						       << 3U)) 
						   | ((0x3f0U 
						       & (vlTOPp->ifid_stage__DOT__id_instruction 
							  >> 0x15U)) 
						      | (0xfU 
							 & (vlTOPp->ifid_stage__DOT__id_instruction 
							    >> 8U))))));
	    } else {
		if (vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_imm) {
		    vlTOPp->ifid_stage__DOT__ID__DOT__imm 
			= ((((0x80000000U & vlTOPp->ifid_stage__DOT__id_instruction)
			      ? 0xfffffU : 0U) << 0xcU) 
			   | (0xfffU & (vlTOPp->ifid_stage__DOT__id_instruction 
					>> 0x14U)));
		} else {
		    if (vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_st) {
			vlTOPp->ifid_stage__DOT__ID__DOT__imm 
			    = ((((0x80000000U & vlTOPp->ifid_stage__DOT__id_instruction)
				  ? 0xfffffU : 0U) 
				<< 0xcU) | ((0xfe0U 
					     & (vlTOPp->ifid_stage__DOT__id_instruction 
						>> 0x14U)) 
					    | (0x1fU 
					       & (vlTOPp->ifid_stage__DOT__id_instruction 
						  >> 7U))));
		    } else {
			if (vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_csri) {
			    vlTOPp->ifid_stage__DOT__ID__DOT__imm 
				= (0x1fU & (vlTOPp->ifid_stage__DOT__id_instruction 
					    >> 0xfU));
			}
		    }
		}
	    }
	}
    }
    vlTOPp->ifid_stage__DOT__ID__DOT__rs1 = (0x1fU 
					     & ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__lui)
						 ? 0U
						 : 
						(vlTOPp->ifid_stage__DOT__id_instruction 
						 >> 0xfU)));
    // ALWAYS at ../software/mux21.v:9
    if (vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_immop) {
	if (vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_immop) {
	    vlTOPp->ifid_stage__DOT__ID__DOT__port_b 
		= vlTOPp->ifid_stage__DOT__ID__DOT__imm;
	}
    } else {
	vlTOPp->ifid_stage__DOT__ID__DOT__port_b = vlTOPp->ifid_stage__DOT__ID__DOT__drs2;
    }
    vlTOPp->ifid_stage__DOT__ID__DOT__drs1 = ((0U == (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__rs1))
					       ? 0U
					       : vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file
					      [vlTOPp->ifid_stage__DOT__ID__DOT__rs1]);
}

void Vifid_stage::_settle__TOP__7(Vifid_stage__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vifid_stage::_settle__TOP__7\n"); );
    Vifid_stage* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at ../software/lsu.v:74
    vlTOPp->ifid_stage__DOT__IF__DOT__if_stall_ = (1U 
						   & ((~ (IData)(vlTOPp->ifid_stage__DOT__IF__DOT__wbm_ack_i)) 
						      | (IData)(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__if_stall_aux)));
    // ALWAYS at ../software/mux21.v:9
    if (vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_immop) {
	if (vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_immop) {
	    vlTOPp->ifid_stage__DOT__ID__DOT__port_b 
		= vlTOPp->ifid_stage__DOT__ID__DOT__imm;
	}
    } else {
	vlTOPp->ifid_stage__DOT__ID__DOT__port_b = vlTOPp->ifid_stage__DOT__ID__DOT__drs2;
    }
    vlTOPp->ifid_stage__DOT__ID__DOT__drs1 = ((0U == (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__rs1))
					       ? 0U
					       : vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file
					      [vlTOPp->ifid_stage__DOT__ID__DOT__rs1]);
    vlTOPp->ifid_stage__DOT__ID__DOT___imm = ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__jalr)
					       ? ((vlTOPp->ifid_stage__DOT__ID__DOT__imm 
						   << 1U) 
						  + vlTOPp->ifid_stage__DOT__ID__DOT__drs1)
					       : (vlTOPp->ifid_stage__DOT__ID__DOT__imm 
						  << 1U));
    // ALWAYS at ../software/mux21.v:9
    if (vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__auipc) {
	if (vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__auipc) {
	    vlTOPp->ifid_stage__DOT__ID__DOT__port_a 
		= vlTOPp->ifid_stage__DOT__id_pc;
	}
    } else {
	vlTOPp->ifid_stage__DOT__ID__DOT__port_a = vlTOPp->ifid_stage__DOT__ID__DOT__drs1;
    }
    // ALWAYS at ../software/comparator.v:25
    vlTOPp->take_branch = ((4U & (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__comparator_op))
			    ? ((2U & (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__comparator_op))
			        ? ((~ (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__comparator_op)) 
				   & (vlTOPp->ifid_stage__DOT__ID__DOT__drs1 
				      >= vlTOPp->ifid_stage__DOT__ID__DOT__drs2))
			        : ((1U & (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__comparator_op))
				    ? (vlTOPp->ifid_stage__DOT__ID__DOT__drs1 
				       < vlTOPp->ifid_stage__DOT__ID__DOT__drs2)
				    : VL_GTES_III(1,32,32, vlTOPp->ifid_stage__DOT__ID__DOT__drs1, vlTOPp->ifid_stage__DOT__ID__DOT__drs2)))
			    : ((2U & (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__comparator_op))
			        ? ((1U & (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__comparator_op))
				    ? VL_LTS_III(1,32,32, vlTOPp->ifid_stage__DOT__ID__DOT__drs1, vlTOPp->ifid_stage__DOT__ID__DOT__drs2)
				    : (vlTOPp->ifid_stage__DOT__ID__DOT__drs1 
				       != vlTOPp->ifid_stage__DOT__ID__DOT__drs2))
			        : ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__comparator_op) 
				   & (vlTOPp->ifid_stage__DOT__ID__DOT__drs1 
				      == vlTOPp->ifid_stage__DOT__ID__DOT__drs2))));
}

VL_INLINE_OPT void Vifid_stage::_sequent__TOP__8(Vifid_stage__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vifid_stage::_sequent__TOP__8\n"); );
    Vifid_stage* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at ../software/lsu.v:75
    vlTOPp->ifid_stage__DOT__IF__DOT__if_instruction_o 
	= vlTOPp->ifid_stage__DOT__IF__DOT__wbm_dat_i;
}

VL_INLINE_OPT void Vifid_stage::_sequent__TOP__9(Vifid_stage__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vifid_stage::_sequent__TOP__9\n"); );
    Vifid_stage* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->ifid_stage__DOT__ID__DOT___imm = ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__jalr)
					       ? ((vlTOPp->ifid_stage__DOT__ID__DOT__imm 
						   << 1U) 
						  + vlTOPp->ifid_stage__DOT__ID__DOT__drs1)
					       : (vlTOPp->ifid_stage__DOT__ID__DOT__imm 
						  << 1U));
    // ALWAYS at ../software/mux21.v:9
    if (vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__auipc) {
	if (vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__auipc) {
	    vlTOPp->ifid_stage__DOT__ID__DOT__port_a 
		= vlTOPp->ifid_stage__DOT__id_pc;
	}
    } else {
	vlTOPp->ifid_stage__DOT__ID__DOT__port_a = vlTOPp->ifid_stage__DOT__ID__DOT__drs1;
    }
    // ALWAYS at ../software/comparator.v:25
    vlTOPp->take_branch = ((4U & (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__comparator_op))
			    ? ((2U & (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__comparator_op))
			        ? ((~ (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__comparator_op)) 
				   & (vlTOPp->ifid_stage__DOT__ID__DOT__drs1 
				      >= vlTOPp->ifid_stage__DOT__ID__DOT__drs2))
			        : ((1U & (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__comparator_op))
				    ? (vlTOPp->ifid_stage__DOT__ID__DOT__drs1 
				       < vlTOPp->ifid_stage__DOT__ID__DOT__drs2)
				    : VL_GTES_III(1,32,32, vlTOPp->ifid_stage__DOT__ID__DOT__drs1, vlTOPp->ifid_stage__DOT__ID__DOT__drs2)))
			    : ((2U & (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__comparator_op))
			        ? ((1U & (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__comparator_op))
				    ? VL_LTS_III(1,32,32, vlTOPp->ifid_stage__DOT__ID__DOT__drs1, vlTOPp->ifid_stage__DOT__ID__DOT__drs2)
				    : (vlTOPp->ifid_stage__DOT__ID__DOT__drs1 
				       != vlTOPp->ifid_stage__DOT__ID__DOT__drs2))
			        : ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__comparator_op) 
				   & (vlTOPp->ifid_stage__DOT__ID__DOT__drs1 
				      == vlTOPp->ifid_stage__DOT__ID__DOT__drs2))));
    // ALWAYS at ../software/bram.v:78
    if (vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__we_i) {
	if (vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__we_i) {
	    if ((1U == (IData)(vlTOPp->ifid_stage__DOT__IF__DOT__wbm_sel_o))) {
		vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT____Vlvbound1 
		    = (0xffU & vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__dat_i);
		if ((0x400U >= (0x7ffU & vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o))) {
		    vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__memory[(0x7ffU 
									 & vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o)] 
			= vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT____Vlvbound1;
		}
	    } else {
		if ((3U == (IData)(vlTOPp->ifid_stage__DOT__IF__DOT__wbm_sel_o))) {
		    vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT____Vlvbound2 
			= (0xffU & (vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__dat_i 
				    >> 8U));
		    if ((0x400U >= (0x7ffU & vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o))) {
			vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__memory[(0x7ffU 
									     & vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o)] 
			    = vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT____Vlvbound2;
		    }
		    vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT____Vlvbound3 
			= (0xffU & vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__dat_i);
		    if ((0x400U >= (0x7ffU & ((IData)(1U) 
					      + vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o)))) {
			vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__memory[(0x7ffU 
									     & ((IData)(1U) 
										+ vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o))] 
			    = vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT____Vlvbound3;
		    }
		} else {
		    if ((0xcU == (IData)(vlTOPp->ifid_stage__DOT__IF__DOT__wbm_sel_o))) {
			vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT____Vlvbound4 
			    = (0xffU & (vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__dat_i 
					>> 0x18U));
			if ((0x400U >= (0x7ffU & vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o))) {
			    vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__memory[(0x7ffU 
										& vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o)] 
				= vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT____Vlvbound4;
			}
			vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT____Vlvbound5 
			    = (0xffU & (vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__dat_i 
					>> 0x10U));
			if ((0x400U >= (0x7ffU & ((IData)(1U) 
						  + vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o)))) {
			    vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__memory[(0x7ffU 
										& ((IData)(1U) 
										+ vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o))] 
				= vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT____Vlvbound5;
			}
		    } else {
			if ((0xfU == (IData)(vlTOPp->ifid_stage__DOT__IF__DOT__wbm_sel_o))) {
			    vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT____Vlvbound6 
				= (0xffU & (vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__dat_i 
					    >> 0x18U));
			    if ((0x400U >= (0x7ffU 
					    & vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o))) {
				vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__memory[(0x7ffU 
										& vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o)] 
				    = vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT____Vlvbound6;
			    }
			    vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT____Vlvbound7 
				= (0xffU & (vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__dat_i 
					    >> 0x10U));
			    if ((0x400U >= (0x7ffU 
					    & ((IData)(1U) 
					       + vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o)))) {
				vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__memory[(0x7ffU 
										& ((IData)(1U) 
										+ vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o))] 
				    = vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT____Vlvbound7;
			    }
			    vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT____Vlvbound8 
				= (0xffU & (vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__dat_i 
					    >> 8U));
			    if ((0x400U >= (0x7ffU 
					    & ((IData)(2U) 
					       + vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o)))) {
				vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__memory[(0x7ffU 
										& ((IData)(2U) 
										+ vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o))] 
				    = vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT____Vlvbound8;
			    }
			    vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT____Vlvbound9 
				= (0xffU & vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__dat_i);
			    if ((0x400U >= (0x7ffU 
					    & ((IData)(3U) 
					       + vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o)))) {
				vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__memory[(0x7ffU 
										& ((IData)(3U) 
										+ vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o))] 
				    = vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT____Vlvbound9;
			    }
			}
		    }
		}
	    }
	}
    } else {
	if ((8U & (IData)(vlTOPp->ifid_stage__DOT__IF__DOT__wbm_sel_o))) {
	    if ((4U & (IData)(vlTOPp->ifid_stage__DOT__IF__DOT__wbm_sel_o))) {
		if ((2U & (IData)(vlTOPp->ifid_stage__DOT__IF__DOT__wbm_sel_o))) {
		    if ((1U & (IData)(vlTOPp->ifid_stage__DOT__IF__DOT__wbm_sel_o))) {
			vlTOPp->ifid_stage__DOT__IF__DOT__wbm_dat_i 
			    = ((((0x400U >= (0x7ffU 
					     & vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o))
				  ? vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__memory
				 [(0x7ffU & vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o)]
				  : 0U) << 0x18U) | 
			       ((((0x400U >= (0x7ffU 
					      & ((IData)(1U) 
						 + vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o)))
				   ? vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__memory
				  [(0x7ffU & ((IData)(1U) 
					      + vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o))]
				   : 0U) << 0x10U) 
				| ((((0x400U >= (0x7ffU 
						 & ((IData)(2U) 
						    + vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o)))
				      ? vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__memory
				     [(0x7ffU & ((IData)(2U) 
						 + vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o))]
				      : 0U) << 8U) 
				   | ((0x400U >= (0x7ffU 
						  & ((IData)(3U) 
						     + vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o)))
				       ? vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__memory
				      [(0x7ffU & ((IData)(3U) 
						  + vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o))]
				       : 0U))));
		    } else {
			vlTOPp->ifid_stage__DOT__IF__DOT__wbm_err_i = 1U;
		    }
		} else {
		    if ((1U & (IData)(vlTOPp->ifid_stage__DOT__IF__DOT__wbm_sel_o))) {
			vlTOPp->ifid_stage__DOT__IF__DOT__wbm_err_i = 1U;
		    } else {
			vlTOPp->ifid_stage__DOT__IF__DOT__wbm_dat_i 
			    = (((((0x400U >= (0x7ffU 
					      & vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o))
				   ? vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__memory
				  [(0x7ffU & vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o)]
				   : 0U) << 0x18U) 
				| (((0x400U >= (0x7ffU 
						& ((IData)(1U) 
						   + vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o)))
				     ? vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__memory
				    [(0x7ffU & ((IData)(1U) 
						+ vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o))]
				     : 0U) << 0x10U)) 
			       | ((((0x400U >= (0x7ffU 
						& vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o))
				     ? vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__memory
				    [(0x7ffU & vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o)]
				     : 0U) << 8U) | 
				  ((0x400U >= (0x7ffU 
					       & ((IData)(1U) 
						  + vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o)))
				    ? vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__memory
				   [(0x7ffU & ((IData)(1U) 
					       + vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o))]
				    : 0U)));
		    }
		}
	    } else {
		vlTOPp->ifid_stage__DOT__IF__DOT__wbm_err_i = 1U;
	    }
	} else {
	    if ((4U & (IData)(vlTOPp->ifid_stage__DOT__IF__DOT__wbm_sel_o))) {
		vlTOPp->ifid_stage__DOT__IF__DOT__wbm_err_i = 1U;
	    } else {
		if ((2U & (IData)(vlTOPp->ifid_stage__DOT__IF__DOT__wbm_sel_o))) {
		    if ((1U & (IData)(vlTOPp->ifid_stage__DOT__IF__DOT__wbm_sel_o))) {
			vlTOPp->ifid_stage__DOT__IF__DOT__wbm_dat_i 
			    = (((((0x400U >= (0x7ffU 
					      & vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o))
				   ? vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__memory
				  [(0x7ffU & vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o)]
				   : 0U) << 0x18U) 
				| (((0x400U >= (0x7ffU 
						& ((IData)(1U) 
						   + vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o)))
				     ? vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__memory
				    [(0x7ffU & ((IData)(1U) 
						+ vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o))]
				     : 0U) << 0x10U)) 
			       | ((((0x400U >= (0x7ffU 
						& vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o))
				     ? vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__memory
				    [(0x7ffU & vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o)]
				     : 0U) << 8U) | 
				  ((0x400U >= (0x7ffU 
					       & ((IData)(1U) 
						  + vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o)))
				    ? vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__memory
				   [(0x7ffU & ((IData)(1U) 
					       + vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o))]
				    : 0U)));
		    } else {
			vlTOPp->ifid_stage__DOT__IF__DOT__wbm_err_i = 1U;
		    }
		} else {
		    if ((1U & (IData)(vlTOPp->ifid_stage__DOT__IF__DOT__wbm_sel_o))) {
			vlTOPp->ifid_stage__DOT__IF__DOT__wbm_dat_i 
			    = ((((0x400U >= (0x7ffU 
					     & vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o))
				  ? vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__memory
				 [(0x7ffU & vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o)]
				  : 0U) << 0x18U) | 
			       ((((0x400U >= (0x7ffU 
					      & vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o))
				   ? vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__memory
				  [(0x7ffU & vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o)]
				   : 0U) << 0x10U) 
				| ((((0x400U >= (0x7ffU 
						 & vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o))
				      ? vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__memory
				     [(0x7ffU & vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o)]
				      : 0U) << 8U) 
				   | ((0x400U >= (0x7ffU 
						  & vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o))
				       ? vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__memory
				      [(0x7ffU & vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o)]
				       : 0U))));
		    } else {
			vlTOPp->ifid_stage__DOT__IF__DOT__wbm_err_i = 1U;
		    }
		}
	    }
	}
    }
    // ALWAYS at ../software/bram.v:58
    if (vlTOPp->rst_i) {
	vlTOPp->ifid_stage__DOT__IF__DOT__wbm_dat_i = 0U;
	vlTOPp->__Vdly__ifid_stage__DOT__IF__DOT__wbm_ack_i = 0U;
	vlTOPp->ifid_stage__DOT__IF__DOT__wbm_err_i = 0U;
	vlTOPp->__Vdly__ifid_stage__DOT__IF__DOT__BRAM__DOT__b_state = 0U;
    } else {
	if ((1U & (~ (IData)(vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__b_state)))) {
	    vlTOPp->__Vdly__ifid_stage__DOT__IF__DOT__wbm_ack_i = 0U;
	    if (((IData)(vlTOPp->ifid_stage__DOT__IF__DOT__wbm_cyc_o) 
		 & (IData)(vlTOPp->ifid_stage__DOT__IF__DOT__wbm_stb_o))) {
		vlTOPp->__Vdly__ifid_stage__DOT__IF__DOT__wbm_ack_i = 1U;
		vlTOPp->__Vdly__ifid_stage__DOT__IF__DOT__BRAM__DOT__b_state = 0U;
	    }
	}
    }
    vlTOPp->ifid_stage__DOT__IF__DOT__wbm_cyc_o = vlTOPp->__Vdly__ifid_stage__DOT__IF__DOT__wbm_cyc_o;
    vlTOPp->ifid_stage__DOT__IF__DOT__wbm_stb_o = vlTOPp->__Vdly__ifid_stage__DOT__IF__DOT__wbm_stb_o;
    vlTOPp->ifid_stage__DOT__IF__DOT__wbm_ack_i = vlTOPp->__Vdly__ifid_stage__DOT__IF__DOT__wbm_ack_i;
    vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__b_state 
	= vlTOPp->__Vdly__ifid_stage__DOT__IF__DOT__BRAM__DOT__b_state;
}

void Vifid_stage::_settle__TOP__10(Vifid_stage__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vifid_stage::_settle__TOP__10\n"); );
    Vifid_stage* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at ../software/bram.v:78
    if (vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__we_i) {
	if (vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__we_i) {
	    if ((1U == (IData)(vlTOPp->ifid_stage__DOT__IF__DOT__wbm_sel_o))) {
		vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT____Vlvbound1 
		    = (0xffU & vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__dat_i);
		if ((0x400U >= (0x7ffU & vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o))) {
		    vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__memory[(0x7ffU 
									 & vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o)] 
			= vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT____Vlvbound1;
		}
	    } else {
		if ((3U == (IData)(vlTOPp->ifid_stage__DOT__IF__DOT__wbm_sel_o))) {
		    vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT____Vlvbound2 
			= (0xffU & (vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__dat_i 
				    >> 8U));
		    if ((0x400U >= (0x7ffU & vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o))) {
			vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__memory[(0x7ffU 
									     & vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o)] 
			    = vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT____Vlvbound2;
		    }
		    vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT____Vlvbound3 
			= (0xffU & vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__dat_i);
		    if ((0x400U >= (0x7ffU & ((IData)(1U) 
					      + vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o)))) {
			vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__memory[(0x7ffU 
									     & ((IData)(1U) 
										+ vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o))] 
			    = vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT____Vlvbound3;
		    }
		} else {
		    if ((0xcU == (IData)(vlTOPp->ifid_stage__DOT__IF__DOT__wbm_sel_o))) {
			vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT____Vlvbound4 
			    = (0xffU & (vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__dat_i 
					>> 0x18U));
			if ((0x400U >= (0x7ffU & vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o))) {
			    vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__memory[(0x7ffU 
										& vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o)] 
				= vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT____Vlvbound4;
			}
			vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT____Vlvbound5 
			    = (0xffU & (vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__dat_i 
					>> 0x10U));
			if ((0x400U >= (0x7ffU & ((IData)(1U) 
						  + vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o)))) {
			    vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__memory[(0x7ffU 
										& ((IData)(1U) 
										+ vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o))] 
				= vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT____Vlvbound5;
			}
		    } else {
			if ((0xfU == (IData)(vlTOPp->ifid_stage__DOT__IF__DOT__wbm_sel_o))) {
			    vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT____Vlvbound6 
				= (0xffU & (vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__dat_i 
					    >> 0x18U));
			    if ((0x400U >= (0x7ffU 
					    & vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o))) {
				vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__memory[(0x7ffU 
										& vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o)] 
				    = vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT____Vlvbound6;
			    }
			    vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT____Vlvbound7 
				= (0xffU & (vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__dat_i 
					    >> 0x10U));
			    if ((0x400U >= (0x7ffU 
					    & ((IData)(1U) 
					       + vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o)))) {
				vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__memory[(0x7ffU 
										& ((IData)(1U) 
										+ vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o))] 
				    = vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT____Vlvbound7;
			    }
			    vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT____Vlvbound8 
				= (0xffU & (vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__dat_i 
					    >> 8U));
			    if ((0x400U >= (0x7ffU 
					    & ((IData)(2U) 
					       + vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o)))) {
				vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__memory[(0x7ffU 
										& ((IData)(2U) 
										+ vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o))] 
				    = vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT____Vlvbound8;
			    }
			    vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT____Vlvbound9 
				= (0xffU & vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__dat_i);
			    if ((0x400U >= (0x7ffU 
					    & ((IData)(3U) 
					       + vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o)))) {
				vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__memory[(0x7ffU 
										& ((IData)(3U) 
										+ vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o))] 
				    = vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT____Vlvbound9;
			    }
			}
		    }
		}
	    }
	}
    } else {
	if ((8U & (IData)(vlTOPp->ifid_stage__DOT__IF__DOT__wbm_sel_o))) {
	    if ((4U & (IData)(vlTOPp->ifid_stage__DOT__IF__DOT__wbm_sel_o))) {
		if ((2U & (IData)(vlTOPp->ifid_stage__DOT__IF__DOT__wbm_sel_o))) {
		    if ((1U & (IData)(vlTOPp->ifid_stage__DOT__IF__DOT__wbm_sel_o))) {
			vlTOPp->ifid_stage__DOT__IF__DOT__wbm_dat_i 
			    = ((((0x400U >= (0x7ffU 
					     & vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o))
				  ? vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__memory
				 [(0x7ffU & vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o)]
				  : 0U) << 0x18U) | 
			       ((((0x400U >= (0x7ffU 
					      & ((IData)(1U) 
						 + vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o)))
				   ? vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__memory
				  [(0x7ffU & ((IData)(1U) 
					      + vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o))]
				   : 0U) << 0x10U) 
				| ((((0x400U >= (0x7ffU 
						 & ((IData)(2U) 
						    + vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o)))
				      ? vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__memory
				     [(0x7ffU & ((IData)(2U) 
						 + vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o))]
				      : 0U) << 8U) 
				   | ((0x400U >= (0x7ffU 
						  & ((IData)(3U) 
						     + vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o)))
				       ? vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__memory
				      [(0x7ffU & ((IData)(3U) 
						  + vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o))]
				       : 0U))));
		    } else {
			vlTOPp->ifid_stage__DOT__IF__DOT__wbm_err_i = 1U;
		    }
		} else {
		    if ((1U & (IData)(vlTOPp->ifid_stage__DOT__IF__DOT__wbm_sel_o))) {
			vlTOPp->ifid_stage__DOT__IF__DOT__wbm_err_i = 1U;
		    } else {
			vlTOPp->ifid_stage__DOT__IF__DOT__wbm_dat_i 
			    = (((((0x400U >= (0x7ffU 
					      & vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o))
				   ? vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__memory
				  [(0x7ffU & vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o)]
				   : 0U) << 0x18U) 
				| (((0x400U >= (0x7ffU 
						& ((IData)(1U) 
						   + vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o)))
				     ? vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__memory
				    [(0x7ffU & ((IData)(1U) 
						+ vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o))]
				     : 0U) << 0x10U)) 
			       | ((((0x400U >= (0x7ffU 
						& vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o))
				     ? vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__memory
				    [(0x7ffU & vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o)]
				     : 0U) << 8U) | 
				  ((0x400U >= (0x7ffU 
					       & ((IData)(1U) 
						  + vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o)))
				    ? vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__memory
				   [(0x7ffU & ((IData)(1U) 
					       + vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o))]
				    : 0U)));
		    }
		}
	    } else {
		vlTOPp->ifid_stage__DOT__IF__DOT__wbm_err_i = 1U;
	    }
	} else {
	    if ((4U & (IData)(vlTOPp->ifid_stage__DOT__IF__DOT__wbm_sel_o))) {
		vlTOPp->ifid_stage__DOT__IF__DOT__wbm_err_i = 1U;
	    } else {
		if ((2U & (IData)(vlTOPp->ifid_stage__DOT__IF__DOT__wbm_sel_o))) {
		    if ((1U & (IData)(vlTOPp->ifid_stage__DOT__IF__DOT__wbm_sel_o))) {
			vlTOPp->ifid_stage__DOT__IF__DOT__wbm_dat_i 
			    = (((((0x400U >= (0x7ffU 
					      & vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o))
				   ? vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__memory
				  [(0x7ffU & vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o)]
				   : 0U) << 0x18U) 
				| (((0x400U >= (0x7ffU 
						& ((IData)(1U) 
						   + vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o)))
				     ? vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__memory
				    [(0x7ffU & ((IData)(1U) 
						+ vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o))]
				     : 0U) << 0x10U)) 
			       | ((((0x400U >= (0x7ffU 
						& vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o))
				     ? vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__memory
				    [(0x7ffU & vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o)]
				     : 0U) << 8U) | 
				  ((0x400U >= (0x7ffU 
					       & ((IData)(1U) 
						  + vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o)))
				    ? vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__memory
				   [(0x7ffU & ((IData)(1U) 
					       + vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o))]
				    : 0U)));
		    } else {
			vlTOPp->ifid_stage__DOT__IF__DOT__wbm_err_i = 1U;
		    }
		} else {
		    if ((1U & (IData)(vlTOPp->ifid_stage__DOT__IF__DOT__wbm_sel_o))) {
			vlTOPp->ifid_stage__DOT__IF__DOT__wbm_dat_i 
			    = ((((0x400U >= (0x7ffU 
					     & vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o))
				  ? vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__memory
				 [(0x7ffU & vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o)]
				  : 0U) << 0x18U) | 
			       ((((0x400U >= (0x7ffU 
					      & vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o))
				   ? vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__memory
				  [(0x7ffU & vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o)]
				   : 0U) << 0x10U) 
				| ((((0x400U >= (0x7ffU 
						 & vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o))
				      ? vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__memory
				     [(0x7ffU & vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o)]
				      : 0U) << 8U) 
				   | ((0x400U >= (0x7ffU 
						  & vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o))
				       ? vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__memory
				      [(0x7ffU & vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o)]
				       : 0U))));
		    } else {
			vlTOPp->ifid_stage__DOT__IF__DOT__wbm_err_i = 1U;
		    }
		}
	    }
	}
    }
}

void Vifid_stage::_eval(Vifid_stage__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vifid_stage::_eval\n"); );
    Vifid_stage* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk_i) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk_i)))) {
	vlTOPp->_sequent__TOP__2(vlSymsp);
	vlTOPp->__Vm_traceActivity = (2U | vlTOPp->__Vm_traceActivity);
    }
    vlTOPp->_combo__TOP__5(vlSymsp);
    vlTOPp->__Vm_traceActivity = (4U | vlTOPp->__Vm_traceActivity);
    if (((IData)(vlTOPp->clk_i) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk_i)))) {
	vlTOPp->_sequent__TOP__6(vlSymsp);
	vlTOPp->__Vm_traceActivity = (8U | vlTOPp->__Vm_traceActivity);
    }
    if (((IData)(vlTOPp->__VinpClk__TOP__ifid_stage__DOT__IF__DOT__wbm_ack_i) 
	 & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__ifid_stage__DOT__IF__DOT__wbm_ack_i)))) {
	vlTOPp->_sequent__TOP__8(vlSymsp);
	vlTOPp->__Vm_traceActivity = (0x10U | vlTOPp->__Vm_traceActivity);
    }
    if (((IData)(vlTOPp->clk_i) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk_i)))) {
	vlTOPp->_sequent__TOP__9(vlSymsp);
	vlTOPp->__Vm_traceActivity = (0x20U | vlTOPp->__Vm_traceActivity);
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk_i = vlTOPp->clk_i;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__ifid_stage__DOT__IF__DOT__wbm_ack_i 
	= vlTOPp->__VinpClk__TOP__ifid_stage__DOT__IF__DOT__wbm_ack_i;
    vlTOPp->__VinpClk__TOP__ifid_stage__DOT__IF__DOT__wbm_ack_i 
	= vlTOPp->ifid_stage__DOT__IF__DOT__wbm_ack_i;
}

void Vifid_stage::_eval_initial(Vifid_stage__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vifid_stage::_eval_initial\n"); );
    Vifid_stage* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vm_traceActivity = (1U | vlTOPp->__Vm_traceActivity);
    vlTOPp->_initial__TOP__4(vlSymsp);
}

void Vifid_stage::final() {
    VL_DEBUG_IF(VL_PRINTF("    Vifid_stage::final\n"); );
    // Variables
    Vifid_stage__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vifid_stage* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vifid_stage::_eval_settle(Vifid_stage__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vifid_stage::_eval_settle\n"); );
    Vifid_stage* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__3(vlSymsp);
    vlTOPp->__Vm_traceActivity = (1U | vlTOPp->__Vm_traceActivity);
    vlTOPp->_settle__TOP__7(vlSymsp);
    vlTOPp->_settle__TOP__10(vlSymsp);
}

VL_INLINE_OPT QData Vifid_stage::_change_request(Vifid_stage__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vifid_stage::_change_request\n"); );
    Vifid_stage* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    __req |= ((vlTOPp->ifid_stage__DOT__IF__DOT__wbm_ack_i ^ vlTOPp->__Vchglast__TOP__ifid_stage__DOT__IF__DOT__wbm_ack_i)
	 | (vlTOPp->ifid_stage__DOT__IF__DOT__wbm_cyc_o ^ vlTOPp->__Vchglast__TOP__ifid_stage__DOT__IF__DOT__wbm_cyc_o)
	 | (vlTOPp->ifid_stage__DOT__IF__DOT__wbm_stb_o ^ vlTOPp->__Vchglast__TOP__ifid_stage__DOT__IF__DOT__wbm_stb_o));
    VL_DEBUG_IF( if(__req && ((vlTOPp->ifid_stage__DOT__IF__DOT__wbm_ack_i ^ vlTOPp->__Vchglast__TOP__ifid_stage__DOT__IF__DOT__wbm_ack_i))) VL_PRINTF("	CHANGE: ../software/if_stage.v:31: ifid_stage.IF.wbm_ack_i\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->ifid_stage__DOT__IF__DOT__wbm_cyc_o ^ vlTOPp->__Vchglast__TOP__ifid_stage__DOT__IF__DOT__wbm_cyc_o))) VL_PRINTF("	CHANGE: ../software/if_stage.v:33: ifid_stage.IF.wbm_cyc_o\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->ifid_stage__DOT__IF__DOT__wbm_stb_o ^ vlTOPp->__Vchglast__TOP__ifid_stage__DOT__IF__DOT__wbm_stb_o))) VL_PRINTF("	CHANGE: ../software/if_stage.v:34: ifid_stage.IF.wbm_stb_o\n"); );
    // Final
    vlTOPp->__Vchglast__TOP__ifid_stage__DOT__IF__DOT__wbm_ack_i 
	= vlTOPp->ifid_stage__DOT__IF__DOT__wbm_ack_i;
    vlTOPp->__Vchglast__TOP__ifid_stage__DOT__IF__DOT__wbm_cyc_o 
	= vlTOPp->ifid_stage__DOT__IF__DOT__wbm_cyc_o;
    vlTOPp->__Vchglast__TOP__ifid_stage__DOT__IF__DOT__wbm_stb_o 
	= vlTOPp->ifid_stage__DOT__IF__DOT__wbm_stb_o;
    return __req;
}

void Vifid_stage::_ctor_var_reset() {
    VL_DEBUG_IF(VL_PRINTF("    Vifid_stage::_ctor_var_reset\n"); );
    // Body
    clk_i = VL_RAND_RESET_I(1);
    rst_i = VL_RAND_RESET_I(1);
    ex_port_a = VL_RAND_RESET_I(32);
    ex_port_b = VL_RAND_RESET_I(32);
    ex_alu_op = VL_RAND_RESET_I(4);
    ex_waddr = VL_RAND_RESET_I(5);
    ex_we = VL_RAND_RESET_I(1);
    ex_mem_flags = VL_RAND_RESET_I(6);
    ex_mem_ex_sel = VL_RAND_RESET_I(1);
    ex_jump_op = VL_RAND_RESET_I(1);
    ex_bad_jump_addr = VL_RAND_RESET_I(1);
    ex_branch_op = VL_RAND_RESET_I(1);
    ex_bad_branch_addr = VL_RAND_RESET_I(1);
    take_branch = VL_RAND_RESET_I(1);
    ex_break_op = VL_RAND_RESET_I(1);
    ex_syscall_op = VL_RAND_RESET_I(1);
    ex_csr_op = VL_RAND_RESET_I(3);
    ex_csr_imm_op = VL_RAND_RESET_I(1);
    ex_exc_addr_if_o = VL_RAND_RESET_I(1);
    ex_ready = VL_RAND_RESET_I(1);
    ifid_stage__DOT__if_stall = VL_RAND_RESET_I(1);
    ifid_stage__DOT__id_pc = VL_RAND_RESET_I(32);
    ifid_stage__DOT__id_pc_add4 = VL_RAND_RESET_I(32);
    ifid_stage__DOT__id_instruction = VL_RAND_RESET_I(32);
    ifid_stage__DOT__id_ready_o = VL_RAND_RESET_I(1);
    ifid_stage__DOT__exc_addr_if = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ex_exc_addr_if = VL_RAND_RESET_I(1);
    ifid_stage__DOT__IF__DOT__pc_branch_address = VL_RAND_RESET_I(32);
    ifid_stage__DOT__IF__DOT__pc_jump_address = VL_RAND_RESET_I(32);
    ifid_stage__DOT__IF__DOT__pc_sel = VL_RAND_RESET_I(2);
    ifid_stage__DOT__IF__DOT__if_stall_ = VL_RAND_RESET_I(1);
    ifid_stage__DOT__IF__DOT__if_pc_mux = VL_RAND_RESET_I(32);
    ifid_stage__DOT__IF__DOT__if_pc_o = VL_RAND_RESET_I(32);
    ifid_stage__DOT__IF__DOT__if_instruction_o = VL_RAND_RESET_I(32);
    ifid_stage__DOT__IF__DOT__wbm_dat_i = VL_RAND_RESET_I(32);
    ifid_stage__DOT__IF__DOT__wbm_addr_o = VL_RAND_RESET_I(32);
    ifid_stage__DOT__IF__DOT__wbm_dat_o = VL_RAND_RESET_I(32);
    ifid_stage__DOT__IF__DOT__wbm_ack_i = VL_RAND_RESET_I(1);
    ifid_stage__DOT__IF__DOT__wbm_err_i = VL_RAND_RESET_I(1);
    ifid_stage__DOT__IF__DOT__wbm_cyc_o = VL_RAND_RESET_I(1);
    ifid_stage__DOT__IF__DOT__wbm_stb_o = VL_RAND_RESET_I(1);
    ifid_stage__DOT__IF__DOT__wbm_ready_o = VL_RAND_RESET_I(1);
    ifid_stage__DOT__IF__DOT__wbm_sel_o = VL_RAND_RESET_I(4);
    ifid_stage__DOT__IF__DOT__id_exc_addr_o = VL_RAND_RESET_I(1);
    ifid_stage__DOT__IF__DOT__PC_SOURCE__DOT__in3 = VL_RAND_RESET_I(32);
    ifid_stage__DOT__IF__DOT__LSU__DOT__idat_o = VL_RAND_RESET_I(32);
    ifid_stage__DOT__IF__DOT__LSU__DOT__abort = VL_RAND_RESET_I(1);
    ifid_stage__DOT__IF__DOT__LSU__DOT__no_mem = VL_RAND_RESET_I(1);
    ifid_stage__DOT__IF__DOT__LSU__DOT__maddr_i = VL_RAND_RESET_I(32);
    ifid_stage__DOT__IF__DOT__LSU__DOT__mdat_i = VL_RAND_RESET_I(32);
    ifid_stage__DOT__IF__DOT__LSU__DOT__mread = VL_RAND_RESET_I(1);
    ifid_stage__DOT__IF__DOT__LSU__DOT__mwrite = VL_RAND_RESET_I(1);
    ifid_stage__DOT__IF__DOT__LSU__DOT__mbyte = VL_RAND_RESET_I(1);
    ifid_stage__DOT__IF__DOT__LSU__DOT__mhw = VL_RAND_RESET_I(1);
    ifid_stage__DOT__IF__DOT__LSU__DOT__mword = VL_RAND_RESET_I(1);
    ifid_stage__DOT__IF__DOT__LSU__DOT__munsigned = VL_RAND_RESET_I(1);
    ifid_stage__DOT__IF__DOT__LSU__DOT__data_o = VL_RAND_RESET_I(32);
    ifid_stage__DOT__IF__DOT__LSU__DOT__mem_stall = VL_RAND_RESET_I(1);
    ifid_stage__DOT__IF__DOT__LSU__DOT__mem_bus_err = VL_RAND_RESET_I(1);
    ifid_stage__DOT__IF__DOT__LSU__DOT__ddat_i = VL_RAND_RESET_I(32);
    ifid_stage__DOT__IF__DOT__LSU__DOT__dack_i = VL_RAND_RESET_I(1);
    ifid_stage__DOT__IF__DOT__LSU__DOT__derr_i = VL_RAND_RESET_I(1);
    ifid_stage__DOT__IF__DOT__LSU__DOT__daddr_o = VL_RAND_RESET_I(32);
    ifid_stage__DOT__IF__DOT__LSU__DOT__ddat_o = VL_RAND_RESET_I(32);
    ifid_stage__DOT__IF__DOT__LSU__DOT__dsel_o = VL_RAND_RESET_I(4);
    ifid_stage__DOT__IF__DOT__LSU__DOT__dcyc_o = VL_RAND_RESET_I(1);
    ifid_stage__DOT__IF__DOT__LSU__DOT__dstb_o = VL_RAND_RESET_I(1);
    ifid_stage__DOT__IF__DOT__LSU__DOT__dwe_o = VL_RAND_RESET_I(1);
    ifid_stage__DOT__IF__DOT__LSU__DOT__rdata = VL_RAND_RESET_I(32);
    ifid_stage__DOT__IF__DOT__LSU__DOT__wdata = VL_RAND_RESET_I(32);
    ifid_stage__DOT__IF__DOT__LSU__DOT__no_rps = VL_RAND_RESET_Q(64);
    ifid_stage__DOT__IF__DOT__LSU__DOT__i_state = VL_RAND_RESET_I(2);
    ifid_stage__DOT__IF__DOT__LSU__DOT__d_state = VL_RAND_RESET_I(2);
    ifid_stage__DOT__IF__DOT__LSU__DOT__if_stall_aux = VL_RAND_RESET_I(1);
    ifid_stage__DOT__IF__DOT__BRAM__DOT__dat_i = VL_RAND_RESET_I(32);
    ifid_stage__DOT__IF__DOT__BRAM__DOT__we_i = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<1025; ++__Vi0) {
	    ifid_stage__DOT__IF__DOT__BRAM__DOT__memory[__Vi0] = VL_RAND_RESET_I(8);
    }}
    ifid_stage__DOT__IF__DOT__BRAM__DOT__b_state = VL_RAND_RESET_I(1);
    ifid_stage__DOT__IF__DOT__BRAM__DOT__rdat = VL_RAND_RESET_I(8);
    ifid_stage__DOT__IF__DOT__BRAM__DOT__wdat = VL_RAND_RESET_I(8);
    ifid_stage__DOT__IF__DOT__BRAM__DOT____Vlvbound1 = VL_RAND_RESET_I(8);
    ifid_stage__DOT__IF__DOT__BRAM__DOT____Vlvbound2 = VL_RAND_RESET_I(8);
    ifid_stage__DOT__IF__DOT__BRAM__DOT____Vlvbound3 = VL_RAND_RESET_I(8);
    ifid_stage__DOT__IF__DOT__BRAM__DOT____Vlvbound4 = VL_RAND_RESET_I(8);
    ifid_stage__DOT__IF__DOT__BRAM__DOT____Vlvbound5 = VL_RAND_RESET_I(8);
    ifid_stage__DOT__IF__DOT__BRAM__DOT____Vlvbound6 = VL_RAND_RESET_I(8);
    ifid_stage__DOT__IF__DOT__BRAM__DOT____Vlvbound7 = VL_RAND_RESET_I(8);
    ifid_stage__DOT__IF__DOT__BRAM__DOT____Vlvbound8 = VL_RAND_RESET_I(8);
    ifid_stage__DOT__IF__DOT__BRAM__DOT____Vlvbound9 = VL_RAND_RESET_I(8);
    ifid_stage__DOT__IF__DOT__IF_ID__DOT__flush = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__wb_data = VL_RAND_RESET_I(32);
    ifid_stage__DOT__ID__DOT__wb_address = VL_RAND_RESET_I(5);
    ifid_stage__DOT__ID__DOT__wb_we = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__mem_stall = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__forwardA = VL_RAND_RESET_I(32);
    ifid_stage__DOT__ID__DOT__forwardB = VL_RAND_RESET_I(32);
    ifid_stage__DOT__ID__DOT__rs1 = VL_RAND_RESET_I(5);
    ifid_stage__DOT__ID__DOT__rd = VL_RAND_RESET_I(5);
    ifid_stage__DOT__ID__DOT__drs1 = VL_RAND_RESET_I(32);
    ifid_stage__DOT__ID__DOT__drs2 = VL_RAND_RESET_I(32);
    ifid_stage__DOT__ID__DOT__drd = VL_RAND_RESET_I(32);
    ifid_stage__DOT__ID__DOT__comparator_op = VL_RAND_RESET_I(3);
    ifid_stage__DOT__ID__DOT__immediate = VL_RAND_RESET_I(32);
    ifid_stage__DOT__ID__DOT__imm = VL_RAND_RESET_I(32);
    ifid_stage__DOT__ID__DOT___imm = VL_RAND_RESET_I(32);
    ifid_stage__DOT__ID__DOT__port_a = VL_RAND_RESET_I(32);
    ifid_stage__DOT__ID__DOT__port_b = VL_RAND_RESET_I(32);
    ifid_stage__DOT__ID__DOT__bad_jump_address = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__ex_exc_address_if = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<32; ++__Vi0) {
	    ifid_stage__DOT__ID__DOT__RF__DOT__reg_file[__Vi0] = VL_RAND_RESET_I(32);
    }}
    ifid_stage__DOT__ID__DOT__DCU__DOT__mem_b = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__DCU__DOT__mem_hw = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__DCU__DOT__lui = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__DCU__DOT__auipc = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__DCU__DOT__jal = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__DCU__DOT__jalr = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__DCU__DOT__beq = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__DCU__DOT__bne = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__DCU__DOT__blt = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__DCU__DOT__bge = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__DCU__DOT__bltu = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__DCU__DOT__bgeu = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__DCU__DOT__lb = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__DCU__DOT__lh = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__DCU__DOT__lw = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__DCU__DOT__lbu = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__DCU__DOT__lhu = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__DCU__DOT__sb = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__DCU__DOT__sh = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__DCU__DOT__sw = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__DCU__DOT__addi = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__DCU__DOT__slti = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__DCU__DOT__sltiu = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__DCU__DOT__xori = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__DCU__DOT__ori = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__DCU__DOT__andi = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__DCU__DOT__slli = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__DCU__DOT__srli = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__DCU__DOT__srai = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__DCU__DOT__add = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__DCU__DOT__sub = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__DCU__DOT__sll = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__DCU__DOT__slt = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__DCU__DOT__sltu = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__DCU__DOT___xor = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__DCU__DOT__srl = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__DCU__DOT__sra = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__DCU__DOT___or = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__DCU__DOT___and = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__DCU__DOT__fence = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__DCU__DOT__rw = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__DCU__DOT__rs = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__DCU__DOT__rc = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__DCU__DOT__rwi = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__DCU__DOT__rsi = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__DCU__DOT__rci = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__DCU__DOT__is_b = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__DCU__DOT__is_imm = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__DCU__DOT__is_st = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__DCU__DOT__is_ld = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__DCU__DOT__is_add = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__DCU__DOT__is_sub = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__DCU__DOT__is_and = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__DCU__DOT__is_xor = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__DCU__DOT__is_or = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__DCU__DOT__is_sll = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__DCU__DOT__is_sr = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__DCU__DOT__is_slt = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__DCU__DOT__is_sltu = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__DCU__DOT__is_wr = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__DCU__DOT__is_alu = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__DCU__DOT__is_immop = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__DCU__DOT__is_ldu = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__DCU__DOT__is_bu = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__DCU__DOT__is_j = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__DCU__DOT__is_csr = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__DCU__DOT__is_csri = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__DCU__DOT__is_word = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__DCU__DOT__is_byte = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__DCU__DOT__is_hw = VL_RAND_RESET_I(1);
    ifid_stage__DOT__ID__DOT__ID_EX__DOT__flush = VL_RAND_RESET_I(1);
    __Vdly__ifid_stage__DOT__IF__DOT__wbm_cyc_o = VL_RAND_RESET_I(1);
    __Vdly__ifid_stage__DOT__IF__DOT__wbm_stb_o = VL_RAND_RESET_I(1);
    __Vdly__ifid_stage__DOT__IF__DOT__wbm_ack_i = VL_RAND_RESET_I(1);
    __Vdly__ifid_stage__DOT__IF__DOT__BRAM__DOT__b_state = VL_RAND_RESET_I(1);
    __VinpClk__TOP__ifid_stage__DOT__IF__DOT__wbm_ack_i = VL_RAND_RESET_I(1);
    __Vclklast__TOP__clk_i = VL_RAND_RESET_I(1);
    __Vclklast__TOP____VinpClk__TOP__ifid_stage__DOT__IF__DOT__wbm_ack_i = VL_RAND_RESET_I(1);
    __Vchglast__TOP__ifid_stage__DOT__IF__DOT__wbm_ack_i = VL_RAND_RESET_I(1);
    __Vchglast__TOP__ifid_stage__DOT__IF__DOT__wbm_cyc_o = VL_RAND_RESET_I(1);
    __Vchglast__TOP__ifid_stage__DOT__IF__DOT__wbm_stb_o = VL_RAND_RESET_I(1);
    __Vm_traceActivity = VL_RAND_RESET_I(32);
}

void Vifid_stage::_configure_coverage(Vifid_stage__Syms* __restrict vlSymsp, bool first) {
    VL_DEBUG_IF(VL_PRINTF("    Vifid_stage::_configure_coverage\n"); );
    // Body
    if (0 && vlSymsp && first) {} // Prevent unused
}
