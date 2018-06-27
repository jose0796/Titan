// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop.h"              // For This
#include "Vtop__Syms.h"

#include "verilated_dpi.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vtop) {
    Vtop__Syms* __restrict vlSymsp = __VlSymsp = new Vtop__Syms(this, name());
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vtop::__Vconfigure(Vtop__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vtop::~Vtop() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vtop::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtop::eval\n"); );
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
	VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
	vlSymsp->__Vm_activity = true;
	_eval(vlSymsp);
	if (VL_UNLIKELY(++__VclockLoop > 100)) {
	    // About to fail, so enable debug to see what's not settling.
	    // Note you must run make with OPT=-DVL_DEBUG for debug prints.
	    int __Vsaved_debug = Verilated::debug();
	    Verilated::debug(1);
	    __Vchange = _change_request(vlSymsp);
	    Verilated::debug(__Vsaved_debug);
	    VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Verilated model didn't converge");
	} else {
	    __Vchange = _change_request(vlSymsp);
	}
    } while (VL_UNLIKELY(__Vchange));
}

void Vtop::_eval_initial_loop(Vtop__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
	_eval_settle(vlSymsp);
	_eval(vlSymsp);
	if (VL_UNLIKELY(++__VclockLoop > 100)) {
	    // About to fail, so enable debug to see what's not settling.
	    // Note you must run make with OPT=-DVL_DEBUG for debug prints.
	    int __Vsaved_debug = Verilated::debug();
	    Verilated::debug(1);
	    __Vchange = _change_request(vlSymsp);
	    Verilated::debug(__Vsaved_debug);
	    VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Verilated model didn't DC converge");
	} else {
	    __Vchange = _change_request(vlSymsp);
	}
    } while (VL_UNLIKELY(__Vchange));
}

//--------------------
// Internal Methods

VL_INLINE_OPT void Vtop::__Vdpiimwrap_top__DOT__memory__DOT__c_load_mem__Vdpioc2_TOP(CData (& mem)[16777216], const std::string& filename) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::__Vdpiimwrap_top__DOT__memory__DOT__c_load_mem__Vdpioc2_TOP\n"); );
    // Body
    static const VerilatedVarProps mem__Vopenprops(VLVT_UINT8, VLVD_IN|VLVF_DPI_CLAY, VerilatedVarProps::Packed(), 7, 0, VerilatedVarProps::Unpacked(), 0, 16777215);
    VerilatedDpiOpenVar mem__Vopenarray (&mem__Vopenprops, &mem);
    const char* filename__Vcvt;
    filename__Vcvt = filename.c_str();
    c_load_mem(&mem__Vopenarray, filename__Vcvt);
}

void Vtop::__Vdpiexp_top__DOT__memory__DOT__dpi_read_word_TOP(Vtop__Syms* __restrict vlSymsp, IData address, IData& dpi_read_word__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::__Vdpiexp_top__DOT__memory__DOT__dpi_read_word_TOP\n"); );
    // Variables
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
	if (VL_UNLIKELY((0x80U != (0xffU & (address 
					    >> 0x18U))))) {
	    VL_WRITEF("[RAM read word] Bad address: %x. Abort.\n\n",
		      32,address);
	    VL_FINISH_MT("tests/verilator/ram.v",100,"");
	}
	dpi_read_word__Vfuncrtn = ((vlTOPp->top__DOT__memory__DOT__mem
				    [(0xffffffU & ((IData)(3U) 
						   + address))] 
				    << 0x18U) | ((vlTOPp->top__DOT__memory__DOT__mem
						  [
						  (0xffffffU 
						   & ((IData)(2U) 
						      + address))] 
						  << 0x10U) 
						 | ((vlTOPp->top__DOT__memory__DOT__mem
						     [
						     (0xffffffU 
						      & ((IData)(1U) 
							 + address))] 
						     << 8U) 
						    | vlTOPp->top__DOT__memory__DOT__mem
						    [
						    (0xffffffU 
						     & address)])));
	goto __Vlabel1;
    }
    __Vlabel1: ;
}

void Vtop::__Vdpiexp_top__DOT__memory__DOT__dpi_read_byte_TOP(Vtop__Syms* __restrict vlSymsp, IData address, CData& dpi_read_byte__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::__Vdpiexp_top__DOT__memory__DOT__dpi_read_byte_TOP\n"); );
    // Variables
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
	if (VL_UNLIKELY((0x80U != (0xffU & (address 
					    >> 0x18U))))) {
	    VL_WRITEF("[RAM read byte] Bad address: %x. Abort.\n\n",
		      32,address);
	    VL_FINISH_MT("tests/verilator/ram.v",111,"");
	}
	dpi_read_byte__Vfuncrtn = vlTOPp->top__DOT__memory__DOT__mem
	    [(0xffffffU & address)];
	goto __Vlabel2;
    }
    __Vlabel2: ;
}

void Vtop::__Vdpiexp_top__DOT__memory__DOT__dpi_write_word_TOP(Vtop__Syms* __restrict vlSymsp, IData address, IData data) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::__Vdpiexp_top__DOT__memory__DOT__dpi_write_word_TOP\n"); );
    // Variables
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (VL_UNLIKELY((0x80U != (0xffU & (address >> 0x18U))))) {
	VL_WRITEF("[RAM write word] Bad address: %x. Abort.\n\n",
		  32,address);
	VL_FINISH_MT("tests/verilator/ram.v",119,"");
    }
    vlTOPp->top__DOT__memory__DOT__mem[(0xffffffU & address)] 
	= (0xffU & data);
    vlTOPp->top__DOT__memory__DOT__mem[(0xffffffU & 
					((IData)(1U) 
					 + address))] 
	= (0xffU & (data >> 8U));
    vlTOPp->top__DOT__memory__DOT__mem[(0xffffffU & 
					((IData)(2U) 
					 + address))] 
	= (0xffU & (data >> 0x10U));
    vlTOPp->top__DOT__memory__DOT__mem[(0xffffffU & 
					((IData)(3U) 
					 + address))] 
	= (0xffU & (data >> 0x18U));
}

void Vtop::__Vdpiexp_top__DOT__memory__DOT__dpi_load_mem_TOP(Vtop__Syms* __restrict vlSymsp, const std::string& filename) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::__Vdpiexp_top__DOT__memory__DOT__dpi_load_mem_TOP\n"); );
    // Variables
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Function: c_load_mem__Vdpioc2 at tests/verilator/ram.v:128
    vlTOPp->__Vdpiimwrap_top__DOT__memory__DOT__c_load_mem__Vdpioc2_TOP(vlTOPp->top__DOT__memory__DOT__mem, filename);
}

int Vtop::dpi_read_word(int address) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::dpi_read_word\n"); );
    // Variables
    VL_SIG(address__Vcvt,31,0);
    VL_SIG(dpi_read_word__Vfuncrtn__Vcvt,31,0);
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum==-1)) { __Vfuncnum = Verilated::exportFuncNum("dpi_read_word"); }
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    Vtop__Vcb_dpi_read_word_t __Vcb = (Vtop__Vcb_dpi_read_word_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    address__Vcvt = address;
    (*__Vcb)((Vtop__Syms*)(__Vscopep->symsp()), address__Vcvt, dpi_read_word__Vfuncrtn__Vcvt);
    int dpi_read_word__Vfuncrtn;
    dpi_read_word__Vfuncrtn = dpi_read_word__Vfuncrtn__Vcvt;
    return dpi_read_word__Vfuncrtn;
}

char Vtop::dpi_read_byte(int address) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::dpi_read_byte\n"); );
    // Variables
    VL_SIG8(dpi_read_byte__Vfuncrtn__Vcvt,7,0);
    VL_SIG(address__Vcvt,31,0);
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum==-1)) { __Vfuncnum = Verilated::exportFuncNum("dpi_read_byte"); }
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    Vtop__Vcb_dpi_read_byte_t __Vcb = (Vtop__Vcb_dpi_read_byte_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    address__Vcvt = address;
    (*__Vcb)((Vtop__Syms*)(__Vscopep->symsp()), address__Vcvt, dpi_read_byte__Vfuncrtn__Vcvt);
    char dpi_read_byte__Vfuncrtn;
    dpi_read_byte__Vfuncrtn = dpi_read_byte__Vfuncrtn__Vcvt;
    return dpi_read_byte__Vfuncrtn;
}

void Vtop::dpi_write_word(int address, int data) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::dpi_write_word\n"); );
    // Variables
    VL_SIG(address__Vcvt,31,0);
    VL_SIG(data__Vcvt,31,0);
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum==-1)) { __Vfuncnum = Verilated::exportFuncNum("dpi_write_word"); }
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    Vtop__Vcb_dpi_write_word_t __Vcb = (Vtop__Vcb_dpi_write_word_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    address__Vcvt = address;
    data__Vcvt = data;
    (*__Vcb)((Vtop__Syms*)(__Vscopep->symsp()), address__Vcvt, data__Vcvt);
}

void Vtop::dpi_load_mem(const char* filename) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::dpi_load_mem\n"); );
    // Variables
    std::string filename__Vcvt;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum==-1)) { __Vfuncnum = Verilated::exportFuncNum("dpi_load_mem"); }
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    Vtop__Vcb_dpi_load_mem_t __Vcb = (Vtop__Vcb_dpi_load_mem_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    filename__Vcvt = filename;
    (*__Vcb)((Vtop__Syms*)(__Vscopep->symsp()), filename__Vcvt);
}

void Vtop::_initial__TOP__1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_initial__TOP__1\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // INITIAL at hardware/titan_reg_file.v:13
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[0xeU] = 2U;
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[0x12U] = 4U;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__2(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__2\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIG8(__Vdly__top__DOT__cpu__DOT__id_inst_access_fault,0,0);
    VL_SIG8(__Vdly__top__DOT__cpu__DOT__id_inst_addr_misaligned,0,0);
    VL_SIG8(__Vdlyvdim0__top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file__v0,4,0);
    VL_SIG8(__Vdlyvset__top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file__v0,0,0);
    VL_SIG8(__Vdly__top__DOT__cpu__DOT__ex_alu_op,3,0);
    VL_SIG8(__Vdly__top__DOT__cpu__DOT__ex_we,0,0);
    VL_SIG8(__Vdly__top__DOT__cpu__DOT__ex_mem_flags,5,0);
    VL_SIG8(__Vdly__top__DOT__cpu__DOT__ex_mem_ex_sel,0,0);
    VL_SIG8(__Vdly__top__DOT__cpu__DOT__ex_illegal_inst,0,0);
    VL_SIG8(__Vdly__top__DOT__cpu__DOT__ex_inst_addr_misaligned,0,0);
    VL_SIG8(__Vdly__top__DOT__cpu__DOT__ex_inst_access_fault,0,0);
    VL_SIG8(__Vdly__top__DOT__cpu__DOT__ex_fence_op,0,0);
    VL_SIG8(__Vdly__top__DOT__cpu__DOT__ex_xret_op,0,0);
    VL_SIG8(__Vdly__top__DOT__cpu__DOT__ex_break_op,0,0);
    VL_SIG8(__Vdly__top__DOT__cpu__DOT__ex_syscall_op,0,0);
    VL_SIG8(__Vdly__top__DOT__cpu__DOT__ex_csr_op,2,0);
    VL_SIG8(__Vdly__top__DOT__cpu__DOT__ex_waddr,4,0);
    VL_SIG8(__Vdly__top__DOT__cpu__DOT__ex_rs1,4,0);
    VL_SIG8(__Vdly__top__DOT__cpu__DOT__mem_rs1,4,0);
    VL_SIG8(__Vdly__top__DOT__cpu__DOT__mem_waddr,4,0);
    VL_SIG8(__Vdly__top__DOT__cpu__DOT__mem_we,0,0);
    VL_SIG8(__Vdly__top__DOT__cpu__DOT__mem_mem_flags,5,0);
    VL_SIG8(__Vdly__top__DOT__cpu__DOT__mem_mem_ex_sel,0,0);
    VL_SIG8(__Vdly__top__DOT__cpu__DOT__mem_csr_op,2,0);
    VL_SIG8(__Vdly__top__DOT__cpu__DOT__mem_illegal_inst,0,0);
    VL_SIG8(__Vdly__top__DOT__cpu__DOT__mem_inst_addr_misaligned,0,0);
    VL_SIG8(__Vdly__top__DOT__cpu__DOT__mem_inst_access_fault,0,0);
    VL_SIG8(__Vdly__top__DOT__cpu__DOT__mem_syscall_op,0,0);
    VL_SIG8(__Vdly__top__DOT__cpu__DOT__mem_break_op,0,0);
    VL_SIG8(__Vdly__top__DOT__cpu__DOT__mem_fence_op,0,0);
    VL_SIG8(__Vdly__top__DOT__cpu__DOT__mem_xret_op,0,0);
    VL_SIG8(__Vdly__top__DOT__cpu__DOT__LSU__DOT__i_state,1,0);
    VL_SIG8(__Vdly__top__DOT__cpu__DOT__LSU__DOT__d_state,1,0);
    VL_SIG8(__Vdly__top__DOT__cpu__DOT__CSR__DOT__exception_stall,0,0);
    VL_SIG8(__Vdly__top__DOT__cpu__DOT__CSR__DOT__mstatus_mpie,0,0);
    VL_SIG8(__Vdly__top__DOT__cpu__DOT__CSR__DOT__mstatus_mie,0,0);
    VL_SIG16(__Vdly__top__DOT__cpu__DOT__ex_csr_addr,11,0);
    VL_SIG16(__Vdly__top__DOT__cpu__DOT__mem_csr_addr,11,0);
    VL_SIG(__Vdly__top__DOT__cpu__DOT__if_pc,31,0);
    VL_SIG(__Vdly__top__DOT__cpu__DOT__id_pc,31,0);
    VL_SIG(__Vdly__top__DOT__cpu__DOT__id_instruction,31,0);
    VL_SIG(__Vdlyvval__top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file__v0,31,0);
    VL_SIG(__Vdly__top__DOT__cpu__DOT__ex_instruction,31,0);
    VL_SIG(__Vdly__top__DOT__cpu__DOT__ex_pc,31,0);
    VL_SIG(__Vdly__top__DOT__cpu__DOT__ex_port_a,31,0);
    VL_SIG(__Vdly__top__DOT__cpu__DOT__ex_port_b,31,0);
    VL_SIG(__Vdly__top__DOT__cpu__DOT__ex_store_data,31,0);
    VL_SIG(__Vdly__top__DOT__cpu__DOT__ex_csr_data,31,0);
    VL_SIG(__Vdly__top__DOT__cpu__DOT__mem_pc,31,0);
    VL_SIG(__Vdly__top__DOT__cpu__DOT__mem_instruction,31,0);
    VL_SIG(__Vdly__top__DOT__cpu__DOT__mem_result,31,0);
    VL_SIG(__Vdly__top__DOT__cpu__DOT__mem_store_data,31,0);
    VL_SIG(__Vdly__top__DOT__cpu__DOT__mem_csr_data,31,0);
    VL_SIG64(__Vdly__top__DOT__cpu__DOT__CSR__DOT__mcycle,63,0);
    VL_SIG64(__Vdly__top__DOT__cpu__DOT__CSR__DOT__minstret,63,0);
    // Body
    __Vdly__top__DOT__cpu__DOT__if_pc = vlTOPp->top__DOT__cpu__DOT__if_pc;
    __Vdly__top__DOT__cpu__DOT__LSU__DOT__i_state = vlTOPp->top__DOT__cpu__DOT__LSU__DOT__i_state;
    __Vdly__top__DOT__cpu__DOT__CSR__DOT__exception_stall 
	= vlTOPp->top__DOT__cpu__DOT__CSR__DOT__exception_stall;
    __Vdly__top__DOT__cpu__DOT__LSU__DOT__d_state = vlTOPp->top__DOT__cpu__DOT__LSU__DOT__d_state;
    __Vdly__top__DOT__cpu__DOT__id_inst_addr_misaligned 
	= vlTOPp->top__DOT__cpu__DOT__id_inst_addr_misaligned;
    __Vdly__top__DOT__cpu__DOT__id_inst_access_fault 
	= vlTOPp->top__DOT__cpu__DOT__id_inst_access_fault;
    __Vdly__top__DOT__cpu__DOT__id_pc = vlTOPp->top__DOT__cpu__DOT__id_pc;
    __Vdly__top__DOT__cpu__DOT__mem_xret_op = vlTOPp->top__DOT__cpu__DOT__mem_xret_op;
    __Vdly__top__DOT__cpu__DOT__mem_fence_op = vlTOPp->top__DOT__cpu__DOT__mem_fence_op;
    __Vdly__top__DOT__cpu__DOT__mem_break_op = vlTOPp->top__DOT__cpu__DOT__mem_break_op;
    __Vdly__top__DOT__cpu__DOT__mem_syscall_op = vlTOPp->top__DOT__cpu__DOT__mem_syscall_op;
    __Vdly__top__DOT__cpu__DOT__mem_inst_access_fault 
	= vlTOPp->top__DOT__cpu__DOT__mem_inst_access_fault;
    __Vdly__top__DOT__cpu__DOT__mem_inst_addr_misaligned 
	= vlTOPp->top__DOT__cpu__DOT__mem_inst_addr_misaligned;
    __Vdly__top__DOT__cpu__DOT__mem_illegal_inst = vlTOPp->top__DOT__cpu__DOT__mem_illegal_inst;
    __Vdly__top__DOT__cpu__DOT__mem_csr_addr = vlTOPp->top__DOT__cpu__DOT__mem_csr_addr;
    __Vdly__top__DOT__cpu__DOT__mem_csr_op = vlTOPp->top__DOT__cpu__DOT__mem_csr_op;
    __Vdly__top__DOT__cpu__DOT__mem_csr_data = vlTOPp->top__DOT__cpu__DOT__mem_csr_data;
    __Vdly__top__DOT__cpu__DOT__mem_rs1 = vlTOPp->top__DOT__cpu__DOT__mem_rs1;
    __Vdly__top__DOT__cpu__DOT__mem_instruction = vlTOPp->top__DOT__cpu__DOT__mem_instruction;
    __Vdly__top__DOT__cpu__DOT__mem_pc = vlTOPp->top__DOT__cpu__DOT__mem_pc;
    __Vdly__top__DOT__cpu__DOT__mem_mem_ex_sel = vlTOPp->top__DOT__cpu__DOT__mem_mem_ex_sel;
    __Vdly__top__DOT__cpu__DOT__mem_waddr = vlTOPp->top__DOT__cpu__DOT__mem_waddr;
    __Vdly__top__DOT__cpu__DOT__mem_we = vlTOPp->top__DOT__cpu__DOT__mem_we;
    __Vdly__top__DOT__cpu__DOT__mem_store_data = vlTOPp->top__DOT__cpu__DOT__mem_store_data;
    __Vdly__top__DOT__cpu__DOT__mem_result = vlTOPp->top__DOT__cpu__DOT__mem_result;
    __Vdlyvset__top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file__v0 = 0U;
    __Vdly__top__DOT__cpu__DOT__CSR__DOT__mcycle = vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mcycle;
    __Vdly__top__DOT__cpu__DOT__id_instruction = vlTOPp->top__DOT__cpu__DOT__id_instruction;
    __Vdly__top__DOT__cpu__DOT__mem_mem_flags = vlTOPp->top__DOT__cpu__DOT__mem_mem_flags;
    __Vdly__top__DOT__cpu__DOT__CSR__DOT__mstatus_mpie 
	= vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mstatus_mpie;
    __Vdly__top__DOT__cpu__DOT__CSR__DOT__mstatus_mie 
	= vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mstatus_mie;
    __Vdly__top__DOT__cpu__DOT__CSR__DOT__minstret 
	= vlTOPp->top__DOT__cpu__DOT__CSR__DOT__minstret;
    __Vdly__top__DOT__cpu__DOT__ex_rs1 = vlTOPp->top__DOT__cpu__DOT__ex_rs1;
    __Vdly__top__DOT__cpu__DOT__ex_csr_data = vlTOPp->top__DOT__cpu__DOT__ex_csr_data;
    __Vdly__top__DOT__cpu__DOT__ex_csr_addr = vlTOPp->top__DOT__cpu__DOT__ex_csr_addr;
    __Vdly__top__DOT__cpu__DOT__ex_csr_op = vlTOPp->top__DOT__cpu__DOT__ex_csr_op;
    __Vdly__top__DOT__cpu__DOT__ex_syscall_op = vlTOPp->top__DOT__cpu__DOT__ex_syscall_op;
    __Vdly__top__DOT__cpu__DOT__ex_break_op = vlTOPp->top__DOT__cpu__DOT__ex_break_op;
    __Vdly__top__DOT__cpu__DOT__ex_xret_op = vlTOPp->top__DOT__cpu__DOT__ex_xret_op;
    __Vdly__top__DOT__cpu__DOT__ex_fence_op = vlTOPp->top__DOT__cpu__DOT__ex_fence_op;
    __Vdly__top__DOT__cpu__DOT__ex_inst_access_fault 
	= vlTOPp->top__DOT__cpu__DOT__ex_inst_access_fault;
    __Vdly__top__DOT__cpu__DOT__ex_inst_addr_misaligned 
	= vlTOPp->top__DOT__cpu__DOT__ex_inst_addr_misaligned;
    __Vdly__top__DOT__cpu__DOT__ex_illegal_inst = vlTOPp->top__DOT__cpu__DOT__ex_illegal_inst;
    __Vdly__top__DOT__cpu__DOT__ex_mem_flags = vlTOPp->top__DOT__cpu__DOT__ex_mem_flags;
    __Vdly__top__DOT__cpu__DOT__ex_store_data = vlTOPp->top__DOT__cpu__DOT__ex_store_data;
    __Vdly__top__DOT__cpu__DOT__ex_pc = vlTOPp->top__DOT__cpu__DOT__ex_pc;
    __Vdly__top__DOT__cpu__DOT__ex_instruction = vlTOPp->top__DOT__cpu__DOT__ex_instruction;
    __Vdly__top__DOT__cpu__DOT__ex_alu_op = vlTOPp->top__DOT__cpu__DOT__ex_alu_op;
    __Vdly__top__DOT__cpu__DOT__ex_port_b = vlTOPp->top__DOT__cpu__DOT__ex_port_b;
    __Vdly__top__DOT__cpu__DOT__ex_port_a = vlTOPp->top__DOT__cpu__DOT__ex_port_a;
    __Vdly__top__DOT__cpu__DOT__ex_mem_ex_sel = vlTOPp->top__DOT__cpu__DOT__ex_mem_ex_sel;
    __Vdly__top__DOT__cpu__DOT__ex_waddr = vlTOPp->top__DOT__cpu__DOT__ex_waddr;
    __Vdly__top__DOT__cpu__DOT__ex_we = vlTOPp->top__DOT__cpu__DOT__ex_we;
    // ALWAYS at hardware/titan_pc_reg.v:11
    __Vdly__top__DOT__cpu__DOT__if_pc = ((IData)(vlTOPp->rst_i)
					  ? 0x80000000U
					  : ((IData)(vlTOPp->top__DOT__cpu__DOT____Vcellinp__IF__if_stall)
					      ? vlTOPp->top__DOT__cpu__DOT__if_pc
					      : vlTOPp->top__DOT__cpu__DOT__IF__DOT__if_pc_mux));
    // ALWAYS at hardware/titan_mem_stage.v:100
    vlTOPp->top__DOT__cpu__DOT__wb_store_access_fault = 0U;
    // ALWAYS at hardware/titan_mem_stage.v:100
    vlTOPp->top__DOT__cpu__DOT__wb_load_access_fault = 0U;
    // ALWAYS at hardware/titan_lsu.v:67
    if (vlTOPp->rst_i) {
	__Vdly__top__DOT__cpu__DOT__LSU__DOT__i_state = 0U;
	vlTOPp->top__DOT__iwbm_cyc = 0U;
	vlTOPp->top__DOT__iwbm_stb = 0U;
	vlTOPp->top__DOT__cpu__DOT__LSU__DOT__kill = 1U;
    } else {
	if ((0U == (IData)(vlTOPp->top__DOT__cpu__DOT__LSU__DOT__i_state))) {
	    vlTOPp->top__DOT__iwbm_cyc = (0U == (3U 
						 & vlTOPp->top__DOT__cpu__DOT__if_pc));
	    vlTOPp->top__DOT__iwbm_stb = (0U == (3U 
						 & vlTOPp->top__DOT__cpu__DOT__if_pc));
	    vlTOPp->top__DOT__cpu__DOT__LSU__DOT__kill = 0U;
	    if (vlTOPp->top__DOT__cpu__DOT__if_kill) {
		__Vdly__top__DOT__cpu__DOT__LSU__DOT__i_state = 2U;
		vlTOPp->top__DOT__cpu__DOT__LSU__DOT__kill = 1U;
	    } else {
		if (vlTOPp->top__DOT__iwbm_ack) {
		    vlTOPp->top__DOT__iwbm_stb = 0U;
		    __Vdly__top__DOT__cpu__DOT__LSU__DOT__i_state = 0U;
		}
	    }
	} else {
	    if ((2U == (IData)(vlTOPp->top__DOT__cpu__DOT__LSU__DOT__i_state))) {
		__Vdly__top__DOT__cpu__DOT__LSU__DOT__i_state = 0U;
		vlTOPp->top__DOT__cpu__DOT__LSU__DOT__kill = 0U;
	    } else {
		__Vdly__top__DOT__cpu__DOT__LSU__DOT__i_state = 0U;
		vlTOPp->top__DOT__iwbm_cyc = 0U;
	    }
	}
    }
    // ALWAYS at hardware/titan_csr_exception_unit.v:185
    vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mstatus = 
	(0x1800U | (((IData)(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mstatus_mpie) 
		     << 7U) | ((IData)(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mstatus_mie) 
			       << 3U)));
    // ALWAYS at hardware/titan_csr_exception_unit.v:185
    vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mip = 0U;
    // ALWAYS at hardware/titan_csr_exception_unit.v:147
    if (vlTOPp->rst_i) {
	__Vdly__top__DOT__cpu__DOT__CSR__DOT__exception_stall = 0U;
    } else {
	if (((IData)(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__exception_stall) 
	     & (~ (IData)(vlTOPp->top__DOT__cpu__DOT__wb_xret_op)))) {
	    __Vdly__top__DOT__cpu__DOT__CSR__DOT__exception_stall = 0U;
	} else {
	    if (vlTOPp->top__DOT__cpu__DOT__wb_xret_op) {
		__Vdly__top__DOT__cpu__DOT__CSR__DOT__exception_stall = 1U;
	    }
	}
    }
    // ALWAYS at hardware/titan_lsu.v:115
    if (vlTOPp->rst_i) {
	vlTOPp->top__DOT__dwbm_dat_o = 0xffffffffU;
	vlTOPp->top__DOT__dwbm_we = 0U;
	vlTOPp->top__DOT__dwbm_cyc = 0U;
	vlTOPp->top__DOT__dwbm_stb = 0U;
	__Vdly__top__DOT__cpu__DOT__LSU__DOT__d_state = 0U;
    } else {
	if ((0U == (IData)(vlTOPp->top__DOT__cpu__DOT__LSU__DOT__d_state))) {
	    vlTOPp->top__DOT__dwbm_cyc = (1U & (((IData)(vlTOPp->top__DOT__cpu__DOT__mem_mem_flags) 
						 >> 4U) 
						^ ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_mem_flags) 
						   >> 5U)));
	    vlTOPp->top__DOT__dwbm_we = (1U & ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_mem_flags) 
					       >> 5U));
	    vlTOPp->top__DOT__dwbm_dat_o = vlTOPp->top__DOT__cpu__DOT__LSU__DOT__wdata;
	    vlTOPp->top__DOT__dwbm_sel = vlTOPp->top__DOT__cpu__DOT__LSU__DOT__wsel_o;
	    vlTOPp->top__DOT__dwbm_stb = (1U & (((IData)(vlTOPp->top__DOT__cpu__DOT__mem_mem_flags) 
						 >> 4U) 
						^ ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_mem_flags) 
						   >> 5U)));
	    __Vdly__top__DOT__cpu__DOT__LSU__DOT__d_state = 0U;
	    if (vlTOPp->top__DOT__dwbm_ack) {
		vlTOPp->top__DOT__dwbm_cyc = 0U;
		vlTOPp->top__DOT__dwbm_stb = 0U;
		__Vdly__top__DOT__cpu__DOT__LSU__DOT__d_state = 0U;
	    }
	} else {
	    vlTOPp->top__DOT__dwbm_cyc = 0U;
	    vlTOPp->top__DOT__dwbm_stb = 0U;
	    __Vdly__top__DOT__cpu__DOT__LSU__DOT__d_state = 0U;
	}
    }
    // ALWAYS at hardware/titan_reg_file.v:23
    if (((IData)(vlTOPp->top__DOT__cpu__DOT__wb_we) 
	 & (0U != (IData)(vlTOPp->top__DOT__cpu__DOT__wb_waddr)))) {
	__Vdlyvval__top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file__v0 
	    = vlTOPp->top__DOT__cpu__DOT__wb_result;
	__Vdlyvset__top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file__v0 = 1U;
	__Vdlyvdim0__top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file__v0 
	    = vlTOPp->top__DOT__cpu__DOT__wb_waddr;
    }
    // ALWAYS at hardware/titan_csr_exception_unit.v:232
    if (vlTOPp->rst_i) {
	__Vdly__top__DOT__cpu__DOT__CSR__DOT__mcycle = VL_ULL(0);
    } else {
	if (((0U != (IData)(vlTOPp->top__DOT__cpu__DOT__wb_rs1)) 
	     & (0xb00U == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr)))) {
	    __Vdly__top__DOT__cpu__DOT__CSR__DOT__mcycle 
		= ((VL_ULL(0xffffffff00000000) & __Vdly__top__DOT__cpu__DOT__CSR__DOT__mcycle) 
		   | (IData)((IData)(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__csr_wdata)));
	} else {
	    if (((0U != (IData)(vlTOPp->top__DOT__cpu__DOT__wb_rs1)) 
		 & (0xb80U == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr)))) {
		__Vdly__top__DOT__cpu__DOT__CSR__DOT__mcycle 
		    = ((VL_ULL(0xffffffff) & __Vdly__top__DOT__cpu__DOT__CSR__DOT__mcycle) 
		       | ((QData)((IData)(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__csr_wdata)) 
			  << 0x20U));
	    } else {
		__Vdly__top__DOT__cpu__DOT__CSR__DOT__mcycle 
		    = (VL_ULL(1) + vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mcycle);
	    }
	}
    }
    // ALWAYS at hardware/titan_csr_exception_unit.v:323
    if (vlTOPp->rst_i) {
	vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mtvec = 0x80000000U;
    } else {
	if ((0U != (IData)(vlTOPp->top__DOT__cpu__DOT__wb_rs1))) {
	    if ((0x305U == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))) {
		vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mtvec 
		    = vlTOPp->top__DOT__cpu__DOT__CSR__DOT__csr_wdata;
	    } else {
		if ((0x340U == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))) {
		    vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mscratch 
			= vlTOPp->top__DOT__cpu__DOT__CSR__DOT__csr_wdata;
		}
	    }
	}
    }
    // ALWAYS at hardware/titan_ifid_reg.v:18
    __Vdly__top__DOT__cpu__DOT__id_pc = (((IData)(vlTOPp->rst_i) 
					  | (IData)(vlTOPp->top__DOT__cpu__DOT__if_flush))
					  ? 0U : ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_stall_req)
						   ? vlTOPp->top__DOT__cpu__DOT__id_pc
						   : 
						  ((IData)(vlTOPp->top__DOT__cpu__DOT____Vcellinp__IF__if_stall)
						    ? 0U
						    : vlTOPp->top__DOT__cpu__DOT__if_pc)));
    __Vdly__top__DOT__cpu__DOT__id_instruction = (((IData)(vlTOPp->rst_i) 
						   | (IData)(vlTOPp->top__DOT__cpu__DOT__if_flush))
						   ? 0x33U
						   : 
						  ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_stall_req)
						    ? vlTOPp->top__DOT__cpu__DOT__id_instruction
						    : 
						   ((IData)(vlTOPp->top__DOT__cpu__DOT____Vcellinp__IF__if_stall)
						     ? 0x33U
						     : vlTOPp->top__DOT__iwbm_dat)));
    __Vdly__top__DOT__cpu__DOT__id_inst_access_fault 
	= ((~ ((IData)(vlTOPp->rst_i) | (IData)(vlTOPp->top__DOT__cpu__DOT__if_flush))) 
	   & ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_stall_req) 
	      & (IData)(vlTOPp->top__DOT__cpu__DOT__id_inst_access_fault)));
    __Vdly__top__DOT__cpu__DOT__id_inst_addr_misaligned 
	= ((~ ((IData)(vlTOPp->rst_i) | (IData)(vlTOPp->top__DOT__cpu__DOT__if_flush))) 
	   & ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_stall_req)
	       ? (IData)(vlTOPp->top__DOT__cpu__DOT__id_inst_addr_misaligned)
	       : ((~ (IData)(vlTOPp->top__DOT__cpu__DOT____Vcellinp__IF__if_stall)) 
		  & (0U != (3U & vlTOPp->top__DOT__cpu__DOT__if_pc)))));
    // ALWAYS at hardware/titan_exmem_register.v:49
    __Vdly__top__DOT__cpu__DOT__mem_pc = (((IData)(vlTOPp->rst_i) 
					   | (IData)(vlTOPp->top__DOT__cpu__DOT____Vcellinp__EX__ex_flush_i))
					   ? 0U : ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_stall_req)
						    ? vlTOPp->top__DOT__cpu__DOT__mem_pc
						    : vlTOPp->top__DOT__cpu__DOT__ex_pc));
    __Vdly__top__DOT__cpu__DOT__mem_instruction = (
						   ((IData)(vlTOPp->rst_i) 
						    | (IData)(vlTOPp->top__DOT__cpu__DOT____Vcellinp__EX__ex_flush_i))
						    ? 0x33U
						    : 
						   ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_stall_req)
						     ? vlTOPp->top__DOT__cpu__DOT__mem_instruction
						     : vlTOPp->top__DOT__cpu__DOT__ex_instruction));
    __Vdly__top__DOT__cpu__DOT__mem_result = (((IData)(vlTOPp->rst_i) 
					       | (IData)(vlTOPp->top__DOT__cpu__DOT____Vcellinp__EX__ex_flush_i))
					       ? 0U
					       : ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_stall_req)
						   ? vlTOPp->top__DOT__cpu__DOT__mem_result
						   : vlTOPp->top__DOT__cpu__DOT__EX__DOT__ex_result));
    __Vdly__top__DOT__cpu__DOT__mem_rs1 = (((IData)(vlTOPp->rst_i) 
					    | (IData)(vlTOPp->top__DOT__cpu__DOT____Vcellinp__EX__ex_flush_i))
					    ? 0U : 
					   ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_stall_req)
					     ? (IData)(vlTOPp->top__DOT__cpu__DOT__mem_rs1)
					     : (IData)(vlTOPp->top__DOT__cpu__DOT__ex_rs1)));
    __Vdly__top__DOT__cpu__DOT__mem_waddr = (((IData)(vlTOPp->rst_i) 
					      | (IData)(vlTOPp->top__DOT__cpu__DOT____Vcellinp__EX__ex_flush_i))
					      ? 0U : 
					     ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_stall_req)
					       ? (IData)(vlTOPp->top__DOT__cpu__DOT__mem_waddr)
					       : (IData)(vlTOPp->top__DOT__cpu__DOT__ex_waddr)));
    __Vdly__top__DOT__cpu__DOT__mem_we = ((~ ((IData)(vlTOPp->rst_i) 
					      | (IData)(vlTOPp->top__DOT__cpu__DOT____Vcellinp__EX__ex_flush_i))) 
					  & ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_stall_req)
					      ? (IData)(vlTOPp->top__DOT__cpu__DOT__mem_we)
					      : (IData)(vlTOPp->top__DOT__cpu__DOT__ex_we)));
    __Vdly__top__DOT__cpu__DOT__mem_mem_flags = (((IData)(vlTOPp->rst_i) 
						  | (IData)(vlTOPp->top__DOT__cpu__DOT____Vcellinp__EX__ex_flush_i))
						  ? 0U
						  : 
						 ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_stall_req)
						   ? (IData)(vlTOPp->top__DOT__cpu__DOT__mem_mem_flags)
						   : (IData)(vlTOPp->top__DOT__cpu__DOT__ex_mem_flags)));
    __Vdly__top__DOT__cpu__DOT__mem_store_data = (((IData)(vlTOPp->rst_i) 
						   | (IData)(vlTOPp->top__DOT__cpu__DOT____Vcellinp__EX__ex_flush_i))
						   ? 0U
						   : 
						  ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_stall_req)
						    ? vlTOPp->top__DOT__cpu__DOT__mem_store_data
						    : vlTOPp->top__DOT__cpu__DOT__ex_store_data));
    __Vdly__top__DOT__cpu__DOT__mem_mem_ex_sel = ((~ 
						   ((IData)(vlTOPp->rst_i) 
						    | (IData)(vlTOPp->top__DOT__cpu__DOT____Vcellinp__EX__ex_flush_i))) 
						  & ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_stall_req)
						      ? (IData)(vlTOPp->top__DOT__cpu__DOT__mem_mem_ex_sel)
						      : (IData)(vlTOPp->top__DOT__cpu__DOT__ex_mem_ex_sel)));
    __Vdly__top__DOT__cpu__DOT__mem_csr_data = (((IData)(vlTOPp->rst_i) 
						 | (IData)(vlTOPp->top__DOT__cpu__DOT____Vcellinp__EX__ex_flush_i))
						 ? 0U
						 : 
						((IData)(vlTOPp->top__DOT__cpu__DOT__mem_stall_req)
						  ? vlTOPp->top__DOT__cpu__DOT__mem_csr_data
						  : vlTOPp->top__DOT__cpu__DOT__ex_csr_data));
    __Vdly__top__DOT__cpu__DOT__mem_csr_op = (((IData)(vlTOPp->rst_i) 
					       | (IData)(vlTOPp->top__DOT__cpu__DOT____Vcellinp__EX__ex_flush_i))
					       ? 0U
					       : ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_stall_req)
						   ? (IData)(vlTOPp->top__DOT__cpu__DOT__mem_csr_op)
						   : (IData)(vlTOPp->top__DOT__cpu__DOT__ex_csr_op)));
    __Vdly__top__DOT__cpu__DOT__mem_csr_addr = (((IData)(vlTOPp->rst_i) 
						 | (IData)(vlTOPp->top__DOT__cpu__DOT____Vcellinp__EX__ex_flush_i))
						 ? 0U
						 : 
						((IData)(vlTOPp->top__DOT__cpu__DOT__mem_stall_req)
						  ? (IData)(vlTOPp->top__DOT__cpu__DOT__mem_csr_addr)
						  : (IData)(vlTOPp->top__DOT__cpu__DOT__ex_csr_addr)));
    __Vdly__top__DOT__cpu__DOT__mem_illegal_inst = 
	((~ ((IData)(vlTOPp->rst_i) | (IData)(vlTOPp->top__DOT__cpu__DOT____Vcellinp__EX__ex_flush_i))) 
	 & ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_stall_req)
	     ? (IData)(vlTOPp->top__DOT__cpu__DOT__mem_illegal_inst)
	     : (IData)(vlTOPp->top__DOT__cpu__DOT__ex_illegal_inst)));
    __Vdly__top__DOT__cpu__DOT__mem_inst_addr_misaligned 
	= ((~ ((IData)(vlTOPp->rst_i) | (IData)(vlTOPp->top__DOT__cpu__DOT____Vcellinp__EX__ex_flush_i))) 
	   & ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_stall_req)
	       ? (IData)(vlTOPp->top__DOT__cpu__DOT__mem_inst_addr_misaligned)
	       : (IData)(vlTOPp->top__DOT__cpu__DOT__ex_inst_addr_misaligned)));
    __Vdly__top__DOT__cpu__DOT__mem_inst_access_fault 
	= ((~ ((IData)(vlTOPp->rst_i) | (IData)(vlTOPp->top__DOT__cpu__DOT____Vcellinp__EX__ex_flush_i))) 
	   & ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_stall_req)
	       ? (IData)(vlTOPp->top__DOT__cpu__DOT__mem_inst_access_fault)
	       : (IData)(vlTOPp->top__DOT__cpu__DOT__ex_inst_access_fault)));
    __Vdly__top__DOT__cpu__DOT__mem_syscall_op = ((~ 
						   ((IData)(vlTOPp->rst_i) 
						    | (IData)(vlTOPp->top__DOT__cpu__DOT____Vcellinp__EX__ex_flush_i))) 
						  & ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_stall_req)
						      ? (IData)(vlTOPp->top__DOT__cpu__DOT__mem_syscall_op)
						      : (IData)(vlTOPp->top__DOT__cpu__DOT__ex_syscall_op)));
    __Vdly__top__DOT__cpu__DOT__mem_break_op = ((~ 
						 ((IData)(vlTOPp->rst_i) 
						  | (IData)(vlTOPp->top__DOT__cpu__DOT____Vcellinp__EX__ex_flush_i))) 
						& ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_stall_req)
						    ? (IData)(vlTOPp->top__DOT__cpu__DOT__mem_break_op)
						    : (IData)(vlTOPp->top__DOT__cpu__DOT__ex_break_op)));
    __Vdly__top__DOT__cpu__DOT__mem_fence_op = ((~ 
						 ((IData)(vlTOPp->rst_i) 
						  | (IData)(vlTOPp->top__DOT__cpu__DOT____Vcellinp__EX__ex_flush_i))) 
						& ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_stall_req)
						    ? (IData)(vlTOPp->top__DOT__cpu__DOT__mem_fence_op)
						    : (IData)(vlTOPp->top__DOT__cpu__DOT__ex_fence_op)));
    __Vdly__top__DOT__cpu__DOT__mem_xret_op = ((~ ((IData)(vlTOPp->rst_i) 
						   | (IData)(vlTOPp->top__DOT__cpu__DOT____Vcellinp__EX__ex_flush_i))) 
					       & ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_stall_req)
						   ? (IData)(vlTOPp->top__DOT__cpu__DOT__mem_xret_op)
						   : (IData)(vlTOPp->top__DOT__cpu__DOT__ex_xret_op)));
    // ALWAYS at hardware/titan_csr_exception_unit.v:268
    if (vlTOPp->rst_i) {
	__Vdly__top__DOT__cpu__DOT__CSR__DOT__mstatus_mpie = 0U;
	__Vdly__top__DOT__cpu__DOT__CSR__DOT__mstatus_mie = 0U;
    } else {
	if (vlTOPp->top__DOT__cpu__DOT__CSR__DOT__trap_valid) {
	    __Vdly__top__DOT__cpu__DOT__CSR__DOT__mstatus_mpie 
		= vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mstatus_mie;
	    __Vdly__top__DOT__cpu__DOT__CSR__DOT__mstatus_mie = 0U;
	} else {
	    if (vlTOPp->top__DOT__cpu__DOT__wb_xret_op) {
		__Vdly__top__DOT__cpu__DOT__CSR__DOT__mstatus_mie 
		    = vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mstatus_mpie;
		__Vdly__top__DOT__cpu__DOT__CSR__DOT__mstatus_mpie = 1U;
	    } else {
		if (((0U != (IData)(vlTOPp->top__DOT__cpu__DOT__wb_rs1)) 
		     & (0x300U == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr)))) {
		    __Vdly__top__DOT__cpu__DOT__CSR__DOT__mstatus_mpie 
			= (1U & (vlTOPp->top__DOT__cpu__DOT__CSR__DOT__csr_wdata 
				 >> 7U));
		    __Vdly__top__DOT__cpu__DOT__CSR__DOT__mstatus_mie 
			= (1U & (vlTOPp->top__DOT__cpu__DOT__CSR__DOT__csr_wdata 
				 >> 3U));
		}
	    }
	}
    }
    // ALWAYS at hardware/titan_csr_exception_unit.v:303
    if (vlTOPp->top__DOT__cpu__DOT__CSR__DOT__trap_valid) {
	vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mtval 
	    = vlTOPp->top__DOT__cpu__DOT__wb_instruction;
    } else {
	if (((0U != (IData)(vlTOPp->top__DOT__cpu__DOT__wb_rs1)) 
	     & (0x343U == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr)))) {
	    vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mtval 
		= vlTOPp->top__DOT__cpu__DOT__CSR__DOT__csr_wdata;
	}
    }
    // ALWAYS at hardware/titan_csr_exception_unit.v:284
    if (vlTOPp->rst_i) {
	vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mepc = 0U;
    } else {
	if (vlTOPp->top__DOT__cpu__DOT__CSR__DOT__trap_valid) {
	    vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mepc 
		= (0xfffffffcU & vlTOPp->top__DOT__cpu__DOT__wb_pc);
	} else {
	    if (((0U != (IData)(vlTOPp->top__DOT__cpu__DOT__wb_rs1)) 
		 & (0x341U == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr)))) {
		vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mepc 
		    = (0xfffffffcU & vlTOPp->top__DOT__cpu__DOT__CSR__DOT__csr_wdata);
	    }
	}
    }
    // ALWAYS at hardware/titan_csr_exception_unit.v:185
    vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mcause = 
	(((IData)(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mcause_int) 
	  << 0x1fU) | (IData)(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mcause_exc));
    // ALWAYS at hardware/titan_csr_exception_unit.v:248
    if (vlTOPp->rst_i) {
	__Vdly__top__DOT__cpu__DOT__CSR__DOT__minstret = VL_ULL(0);
    } else {
	if (((0U != (IData)(vlTOPp->top__DOT__cpu__DOT__wb_rs1)) 
	     & (0xb02U == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr)))) {
	    __Vdly__top__DOT__cpu__DOT__CSR__DOT__minstret 
		= ((VL_ULL(0xffffffff00000000) & __Vdly__top__DOT__cpu__DOT__CSR__DOT__minstret) 
		   | (IData)((IData)(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__csr_wdata)));
	} else {
	    if (((0U != (IData)(vlTOPp->top__DOT__cpu__DOT__wb_rs1)) 
		 & (0xb82U == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr)))) {
		__Vdly__top__DOT__cpu__DOT__CSR__DOT__minstret 
		    = ((VL_ULL(0xffffffff) & __Vdly__top__DOT__cpu__DOT__CSR__DOT__minstret) 
		       | ((QData)((IData)(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__csr_wdata)) 
			  << 0x20U));
	    } else {
		if (vlTOPp->top__DOT__cpu__DOT__wb_fence_op) {
		    __Vdly__top__DOT__cpu__DOT__CSR__DOT__minstret 
			= (VL_ULL(1) + vlTOPp->top__DOT__cpu__DOT__CSR__DOT__minstret);
		} else {
		    if (vlTOPp->top__DOT__cpu__DOT__wb_xret_op) {
			__Vdly__top__DOT__cpu__DOT__CSR__DOT__minstret 
			    = (VL_ULL(1) + vlTOPp->top__DOT__cpu__DOT__CSR__DOT__minstret);
		    } else {
			if (((IData)(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__trap_valid) 
			     & ((IData)(vlTOPp->top__DOT__cpu__DOT__wb_syscall_op) 
				| (IData)(vlTOPp->top__DOT__cpu__DOT__wb_break_op)))) {
			    __Vdly__top__DOT__cpu__DOT__CSR__DOT__minstret 
				= (VL_ULL(1) + vlTOPp->top__DOT__cpu__DOT__CSR__DOT__minstret);
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at hardware/titan_csr_exception_unit.v:185
    vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mie = (((IData)(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mie_meie) 
						  << 0xbU) 
						 | (((IData)(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mie_mtie) 
						     << 7U) 
						    | ((IData)(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mie_msie) 
						       << 3U)));
    // ALWAYS at hardware/titan_idex_register.v:52
    __Vdly__top__DOT__cpu__DOT__ex_instruction = (((IData)(vlTOPp->rst_i) 
						   | (IData)(vlTOPp->top__DOT__cpu__DOT__id_flush))
						   ? 0x33U
						   : 
						  ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_stall_req)
						    ? vlTOPp->top__DOT__cpu__DOT__ex_instruction
						    : vlTOPp->top__DOT__cpu__DOT__id_instruction));
    __Vdly__top__DOT__cpu__DOT__ex_pc = (((IData)(vlTOPp->rst_i) 
					  | (IData)(vlTOPp->top__DOT__cpu__DOT__id_flush))
					  ? 0U : ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_stall_req)
						   ? vlTOPp->top__DOT__cpu__DOT__ex_pc
						   : vlTOPp->top__DOT__cpu__DOT__id_pc));
    __Vdly__top__DOT__cpu__DOT__ex_port_a = (((IData)(vlTOPp->rst_i) 
					      | (IData)(vlTOPp->top__DOT__cpu__DOT__id_flush))
					      ? 0U : 
					     ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_stall_req)
					       ? vlTOPp->top__DOT__cpu__DOT__ex_port_a
					       : vlTOPp->top__DOT__cpu__DOT__ID__DOT__port_a));
    __Vdly__top__DOT__cpu__DOT__ex_port_b = (((IData)(vlTOPp->rst_i) 
					      | (IData)(vlTOPp->top__DOT__cpu__DOT__id_flush))
					      ? 0U : 
					     ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_stall_req)
					       ? vlTOPp->top__DOT__cpu__DOT__ex_port_b
					       : vlTOPp->top__DOT__cpu__DOT__ID__DOT__port_b));
    __Vdly__top__DOT__cpu__DOT__ex_alu_op = (((IData)(vlTOPp->rst_i) 
					      | (IData)(vlTOPp->top__DOT__cpu__DOT__id_flush))
					      ? 0U : 
					     ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_stall_req)
					       ? (IData)(vlTOPp->top__DOT__cpu__DOT__ex_alu_op)
					       : ((
						   (((((((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_add) 
							 | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_sub)) 
							| (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_and)) 
						       | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_or)) 
						      | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_xor)) 
						     | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_sll)) 
						    | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_sr)) 
						   | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_slt))
						   ? 
						  ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_add)
						    ? 0U
						    : 
						   ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_sub)
						     ? 1U
						     : 
						    ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_and)
						      ? 2U
						      : 
						     ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_or)
						       ? 3U
						       : 
						      ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_xor)
						        ? 4U
						        : 
						       ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_sll)
							 ? 5U
							 : 
							((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_sr)
							  ? 
							 (((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sra) 
							   | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__srai))
							   ? 6U
							   : 7U)
							  : 8U)))))))
						   : 
						  ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_sltu)
						    ? 9U
						    : 0xfU))));
    __Vdly__top__DOT__cpu__DOT__ex_we = ((~ ((IData)(vlTOPp->rst_i) 
					     | (IData)(vlTOPp->top__DOT__cpu__DOT__id_flush))) 
					 & ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_stall_req)
					     ? (IData)(vlTOPp->top__DOT__cpu__DOT__ex_we)
					     : ((0U 
						 != (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__waddr)) 
						& (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_wr))));
    __Vdly__top__DOT__cpu__DOT__ex_store_data = (((IData)(vlTOPp->rst_i) 
						  | (IData)(vlTOPp->top__DOT__cpu__DOT__id_flush))
						  ? 0U
						  : 
						 ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_stall_req)
						   ? vlTOPp->top__DOT__cpu__DOT__ex_store_data
						   : vlTOPp->top__DOT__cpu__DOT__ID__DOT__muxb_i));
    __Vdly__top__DOT__cpu__DOT__ex_mem_flags = (((IData)(vlTOPp->rst_i) 
						 | (IData)(vlTOPp->top__DOT__cpu__DOT__id_flush))
						 ? 0U
						 : 
						((IData)(vlTOPp->top__DOT__cpu__DOT__mem_stall_req)
						  ? (IData)(vlTOPp->top__DOT__cpu__DOT__ex_mem_flags)
						  : 
						 (((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_st) 
						   << 5U) 
						  | (((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_ld) 
						      << 4U) 
						     | (((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_word) 
							 << 3U) 
							| (((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_hw) 
							    << 2U) 
							   | (((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_byte) 
							       << 1U) 
							      | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_ldu))))))));
    __Vdly__top__DOT__cpu__DOT__ex_mem_ex_sel = ((~ 
						  ((IData)(vlTOPp->rst_i) 
						   | (IData)(vlTOPp->top__DOT__cpu__DOT__id_flush))) 
						 & ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_stall_req)
						     ? (IData)(vlTOPp->top__DOT__cpu__DOT__ex_mem_ex_sel)
						     : (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_ld)));
    __Vdly__top__DOT__cpu__DOT__ex_illegal_inst = (
						   (~ 
						    ((IData)(vlTOPp->rst_i) 
						     | (IData)(vlTOPp->top__DOT__cpu__DOT__id_flush))) 
						   & ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_stall_req)
						       ? (IData)(vlTOPp->top__DOT__cpu__DOT__ex_illegal_inst)
						       : (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__illegal)));
    __Vdly__top__DOT__cpu__DOT__ex_inst_addr_misaligned 
	= ((~ ((IData)(vlTOPp->rst_i) | (IData)(vlTOPp->top__DOT__cpu__DOT__id_flush))) 
	   & ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_stall_req)
	       ? (IData)(vlTOPp->top__DOT__cpu__DOT__ex_inst_addr_misaligned)
	       : (IData)(vlTOPp->top__DOT__cpu__DOT__id_inst_addr_misaligned)));
    __Vdly__top__DOT__cpu__DOT__ex_inst_access_fault 
	= ((~ ((IData)(vlTOPp->rst_i) | (IData)(vlTOPp->top__DOT__cpu__DOT__id_flush))) 
	   & ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_stall_req)
	       ? (IData)(vlTOPp->top__DOT__cpu__DOT__ex_inst_access_fault)
	       : (IData)(vlTOPp->top__DOT__cpu__DOT__id_inst_access_fault)));
    __Vdly__top__DOT__cpu__DOT__ex_fence_op = ((~ ((IData)(vlTOPp->rst_i) 
						   | (IData)(vlTOPp->top__DOT__cpu__DOT__id_flush))) 
					       & ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_stall_req)
						   ? (IData)(vlTOPp->top__DOT__cpu__DOT__ex_fence_op)
						   : 
						  ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__fence) 
						   & (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__fencei))));
    __Vdly__top__DOT__cpu__DOT__ex_xret_op = ((~ ((IData)(vlTOPp->rst_i) 
						  | (IData)(vlTOPp->top__DOT__cpu__DOT__id_flush))) 
					      & ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_stall_req)
						  ? (IData)(vlTOPp->top__DOT__cpu__DOT__ex_xret_op)
						  : (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__xret)));
    __Vdly__top__DOT__cpu__DOT__ex_break_op = ((~ ((IData)(vlTOPp->rst_i) 
						   | (IData)(vlTOPp->top__DOT__cpu__DOT__id_flush))) 
					       & ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_stall_req)
						   ? (IData)(vlTOPp->top__DOT__cpu__DOT__ex_break_op)
						   : (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT___break)));
    __Vdly__top__DOT__cpu__DOT__ex_syscall_op = ((~ 
						  ((IData)(vlTOPp->rst_i) 
						   | (IData)(vlTOPp->top__DOT__cpu__DOT__id_flush))) 
						 & ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_stall_req)
						     ? (IData)(vlTOPp->top__DOT__cpu__DOT__ex_syscall_op)
						     : (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__call)));
    __Vdly__top__DOT__cpu__DOT__ex_csr_op = (((IData)(vlTOPp->rst_i) 
					      | (IData)(vlTOPp->top__DOT__cpu__DOT__id_flush))
					      ? 0U : 
					     ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_stall_req)
					       ? (IData)(vlTOPp->top__DOT__cpu__DOT__ex_csr_op)
					       : (((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__rc) 
						   << 2U) 
						  | (((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__rs) 
						      << 1U) 
						     | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__rw)))));
    __Vdly__top__DOT__cpu__DOT__ex_csr_addr = (0xfffU 
					       & (((IData)(vlTOPp->rst_i) 
						   | (IData)(vlTOPp->top__DOT__cpu__DOT__id_flush))
						   ? 0U
						   : 
						  ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_stall_req)
						    ? (IData)(vlTOPp->top__DOT__cpu__DOT__ex_csr_addr)
						    : 
						   (vlTOPp->top__DOT__cpu__DOT__id_instruction 
						    >> 0x14U))));
    __Vdly__top__DOT__cpu__DOT__ex_csr_data = (((IData)(vlTOPp->rst_i) 
						| (IData)(vlTOPp->top__DOT__cpu__DOT__id_flush))
					        ? 0U
					        : ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_stall_req)
						    ? vlTOPp->top__DOT__cpu__DOT__ex_csr_data
						    : 
						   ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_csri)
						     ? (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__rs1)
						     : vlTOPp->top__DOT__cpu__DOT__ID__DOT__port_a)));
    __Vdly__top__DOT__cpu__DOT__ex_waddr = (((IData)(vlTOPp->rst_i) 
					     | (IData)(vlTOPp->top__DOT__cpu__DOT__id_flush))
					     ? 0U : 
					    ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_stall_req)
					      ? (IData)(vlTOPp->top__DOT__cpu__DOT__ex_waddr)
					      : (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__waddr)));
    __Vdly__top__DOT__cpu__DOT__ex_rs1 = (((IData)(vlTOPp->rst_i) 
					   | (IData)(vlTOPp->top__DOT__cpu__DOT__id_flush))
					   ? 0U : ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_stall_req)
						    ? (IData)(vlTOPp->top__DOT__cpu__DOT__ex_rs1)
						    : (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__rs1)));
    vlTOPp->top__DOT__cpu__DOT__LSU__DOT__i_state = __Vdly__top__DOT__cpu__DOT__LSU__DOT__i_state;
    vlTOPp->top__DOT__cpu__DOT__CSR__DOT__exception_stall 
	= __Vdly__top__DOT__cpu__DOT__CSR__DOT__exception_stall;
    vlTOPp->top__DOT__cpu__DOT__LSU__DOT__d_state = __Vdly__top__DOT__cpu__DOT__LSU__DOT__d_state;
    // ALWAYSPOST at hardware/titan_reg_file.v:24
    if (__Vdlyvset__top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file__v0) {
	vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[__Vdlyvdim0__top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file__v0] 
	    = __Vdlyvval__top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file__v0;
    }
    vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mcycle = __Vdly__top__DOT__cpu__DOT__CSR__DOT__mcycle;
    vlTOPp->top__DOT__cpu__DOT__if_pc = __Vdly__top__DOT__cpu__DOT__if_pc;
    vlTOPp->top__DOT__cpu__DOT__mem_mem_ex_sel = __Vdly__top__DOT__cpu__DOT__mem_mem_ex_sel;
    vlTOPp->top__DOT__cpu__DOT__mem_store_data = __Vdly__top__DOT__cpu__DOT__mem_store_data;
    vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mstatus_mpie 
	= __Vdly__top__DOT__cpu__DOT__CSR__DOT__mstatus_mpie;
    vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mstatus_mie 
	= __Vdly__top__DOT__cpu__DOT__CSR__DOT__mstatus_mie;
    vlTOPp->top__DOT__cpu__DOT__CSR__DOT__minstret 
	= __Vdly__top__DOT__cpu__DOT__CSR__DOT__minstret;
    vlTOPp->top__DOT__cpu__DOT__ex_instruction = __Vdly__top__DOT__cpu__DOT__ex_instruction;
    vlTOPp->top__DOT__cpu__DOT__ex_pc = __Vdly__top__DOT__cpu__DOT__ex_pc;
    vlTOPp->top__DOT__cpu__DOT__ex_store_data = __Vdly__top__DOT__cpu__DOT__ex_store_data;
    vlTOPp->top__DOT__cpu__DOT__ex_mem_flags = __Vdly__top__DOT__cpu__DOT__ex_mem_flags;
    vlTOPp->top__DOT__cpu__DOT__ex_illegal_inst = __Vdly__top__DOT__cpu__DOT__ex_illegal_inst;
    vlTOPp->top__DOT__cpu__DOT__ex_inst_addr_misaligned 
	= __Vdly__top__DOT__cpu__DOT__ex_inst_addr_misaligned;
    vlTOPp->top__DOT__cpu__DOT__id_inst_addr_misaligned 
	= __Vdly__top__DOT__cpu__DOT__id_inst_addr_misaligned;
    vlTOPp->top__DOT__cpu__DOT__ex_inst_access_fault 
	= __Vdly__top__DOT__cpu__DOT__ex_inst_access_fault;
    vlTOPp->top__DOT__cpu__DOT__id_inst_access_fault 
	= __Vdly__top__DOT__cpu__DOT__id_inst_access_fault;
    vlTOPp->top__DOT__cpu__DOT__ex_fence_op = __Vdly__top__DOT__cpu__DOT__ex_fence_op;
    vlTOPp->top__DOT__cpu__DOT__ex_xret_op = __Vdly__top__DOT__cpu__DOT__ex_xret_op;
    vlTOPp->top__DOT__cpu__DOT__ex_break_op = __Vdly__top__DOT__cpu__DOT__ex_break_op;
    vlTOPp->top__DOT__cpu__DOT__ex_syscall_op = __Vdly__top__DOT__cpu__DOT__ex_syscall_op;
    vlTOPp->top__DOT__cpu__DOT__ex_csr_op = __Vdly__top__DOT__cpu__DOT__ex_csr_op;
    vlTOPp->top__DOT__cpu__DOT__ex_csr_addr = __Vdly__top__DOT__cpu__DOT__ex_csr_addr;
    vlTOPp->top__DOT__cpu__DOT__ex_csr_data = __Vdly__top__DOT__cpu__DOT__ex_csr_data;
    vlTOPp->top__DOT__cpu__DOT__ex_rs1 = __Vdly__top__DOT__cpu__DOT__ex_rs1;
    vlTOPp->top__DOT__cpu__DOT__id_pc = __Vdly__top__DOT__cpu__DOT__id_pc;
    vlTOPp->top__DOT__cpu__DOT__ex_port_a = __Vdly__top__DOT__cpu__DOT__ex_port_a;
    vlTOPp->top__DOT__cpu__DOT__ex_port_b = __Vdly__top__DOT__cpu__DOT__ex_port_b;
    vlTOPp->top__DOT__cpu__DOT__ex_alu_op = __Vdly__top__DOT__cpu__DOT__ex_alu_op;
    vlTOPp->top__DOT__cpu__DOT__ex_mem_ex_sel = __Vdly__top__DOT__cpu__DOT__ex_mem_ex_sel;
    vlTOPp->top__DOT__cpu__DOT__ex_waddr = __Vdly__top__DOT__cpu__DOT__ex_waddr;
    vlTOPp->top__DOT__cpu__DOT__ex_we = __Vdly__top__DOT__cpu__DOT__ex_we;
    vlTOPp->top__DOT__cpu__DOT__id_instruction = __Vdly__top__DOT__cpu__DOT__id_instruction;
    // ALWAYS at tests/verilator/ram.v:60
    vlTOPp->top__DOT__iwbm_ack = (((IData)(vlTOPp->top__DOT__iwbm_cyc) 
				   & (IData)(vlTOPp->top__DOT__iwbm_stb)) 
				  & (0x80U == (0xffU 
					       & (vlTOPp->top__DOT__cpu__DOT__if_pc 
						  >> 0x18U))));
    // ALWAYS at hardware/titan_csr_exception_unit.v:290
    if (vlTOPp->rst_i) {
	vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mcause_int = 0U;
	vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mcause_exc = 2U;
    } else {
	if (vlTOPp->top__DOT__cpu__DOT__CSR__DOT__trap_valid) {
	    vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mcause_int 
		= vlTOPp->top__DOT__cpu__DOT__CSR__DOT__interrupt;
	    vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mcause_exc 
		= vlTOPp->top__DOT__cpu__DOT__CSR__DOT__exception_code;
	} else {
	    if (((0U != (IData)(vlTOPp->top__DOT__cpu__DOT__wb_rs1)) 
		 & (0x342U == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr)))) {
		vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mcause_int 
		    = (1U & (vlTOPp->top__DOT__cpu__DOT__CSR__DOT__csr_wdata 
			     >> 0x1fU));
		vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mcause_exc 
		    = (0xfU & vlTOPp->top__DOT__cpu__DOT__CSR__DOT__csr_wdata);
	    }
	}
    }
    // ALWAYS at hardware/titan_csr_exception_unit.v:311
    if (vlTOPp->rst_i) {
	vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mie_meie = 0U;
	vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mie_mtie = 0U;
	vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mie_msie = 0U;
    } else {
	if (((0U != (IData)(vlTOPp->top__DOT__cpu__DOT__wb_rs1)) 
	     & (0x304U == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr)))) {
	    vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mie_meie 
		= (1U & (vlTOPp->top__DOT__cpu__DOT__CSR__DOT__csr_wdata 
			 >> 0xbU));
	    vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mie_mtie 
		= (1U & (vlTOPp->top__DOT__cpu__DOT__CSR__DOT__csr_wdata 
			 >> 7U));
	    vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mie_msie 
		= (1U & (vlTOPp->top__DOT__cpu__DOT__CSR__DOT__csr_wdata 
			 >> 3U));
	}
    }
    // ALWAYS at hardware/titan_exu.v:19
    vlTOPp->top__DOT__cpu__DOT__EX__DOT__ex_result 
	= ((8U & (IData)(vlTOPp->top__DOT__cpu__DOT__ex_alu_op))
	    ? ((4U & (IData)(vlTOPp->top__DOT__cpu__DOT__ex_alu_op))
	        ? 0U : ((2U & (IData)(vlTOPp->top__DOT__cpu__DOT__ex_alu_op))
			 ? 0U : ((1U & (IData)(vlTOPp->top__DOT__cpu__DOT__ex_alu_op))
				  ? (vlTOPp->top__DOT__cpu__DOT__ex_port_a 
				     < vlTOPp->top__DOT__cpu__DOT__ex_port_b)
				  : VL_LTS_III(32,32,32, vlTOPp->top__DOT__cpu__DOT__ex_port_a, vlTOPp->top__DOT__cpu__DOT__ex_port_b))))
	    : ((4U & (IData)(vlTOPp->top__DOT__cpu__DOT__ex_alu_op))
	        ? ((2U & (IData)(vlTOPp->top__DOT__cpu__DOT__ex_alu_op))
		    ? ((1U & (IData)(vlTOPp->top__DOT__cpu__DOT__ex_alu_op))
		        ? ((0x1fU >= vlTOPp->top__DOT__cpu__DOT__ex_port_b)
			    ? (vlTOPp->top__DOT__cpu__DOT__ex_port_a 
			       >> vlTOPp->top__DOT__cpu__DOT__ex_port_b)
			    : 0U) : ((0x1fU >= vlTOPp->top__DOT__cpu__DOT__ex_port_b)
				      ? VL_SHIFTRS_III(32,32,32, vlTOPp->top__DOT__cpu__DOT__ex_port_a, vlTOPp->top__DOT__cpu__DOT__ex_port_b)
				      : VL_NEGATE_I(
						    (vlTOPp->top__DOT__cpu__DOT__ex_port_a 
						     >> 0x1fU))))
		    : ((1U & (IData)(vlTOPp->top__DOT__cpu__DOT__ex_alu_op))
		        ? ((0x1fU >= vlTOPp->top__DOT__cpu__DOT__ex_port_b)
			    ? (vlTOPp->top__DOT__cpu__DOT__ex_port_a 
			       << vlTOPp->top__DOT__cpu__DOT__ex_port_b)
			    : 0U) : (vlTOPp->top__DOT__cpu__DOT__ex_port_a 
				     ^ vlTOPp->top__DOT__cpu__DOT__ex_port_b)))
	        : ((2U & (IData)(vlTOPp->top__DOT__cpu__DOT__ex_alu_op))
		    ? ((1U & (IData)(vlTOPp->top__DOT__cpu__DOT__ex_alu_op))
		        ? (vlTOPp->top__DOT__cpu__DOT__ex_port_a 
			   | vlTOPp->top__DOT__cpu__DOT__ex_port_b)
		        : (vlTOPp->top__DOT__cpu__DOT__ex_port_a 
			   & vlTOPp->top__DOT__cpu__DOT__ex_port_b))
		    : ((1U & (IData)(vlTOPp->top__DOT__cpu__DOT__ex_alu_op))
		        ? (vlTOPp->top__DOT__cpu__DOT__ex_port_a 
			   - vlTOPp->top__DOT__cpu__DOT__ex_port_b)
		        : (vlTOPp->top__DOT__cpu__DOT__ex_port_a 
			   + vlTOPp->top__DOT__cpu__DOT__ex_port_b)))));
    vlTOPp->top__DOT__cpu__DOT__FWD__DOT__ex_fwd_b 
	= (((IData)(vlTOPp->top__DOT__cpu__DOT__ex_waddr) 
	    == (0x1fU & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			 >> 0x14U))) & (IData)(vlTOPp->top__DOT__cpu__DOT__ex_we));
    // ALWAYS at hardware/titan_dc_unit.v:92
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__lui 
	= (0x37U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__auipc 
	= (0x17U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__jal 
	= (0x6fU == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__jalr 
	= (0x67U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__beq 
	= ((0x63U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	   & (0U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__bne 
	= ((0x63U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	   & (1U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__blt 
	= ((0x63U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	   & (4U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__bge 
	= ((0x63U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	   & (5U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__bltu 
	= ((0x63U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	   & (6U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__bgeu 
	= ((0x63U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	   & (7U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__lb 
	= ((3U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	   & (0U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__lh 
	= ((3U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	   & (1U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__lw 
	= ((3U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	   & (2U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__lbu 
	= ((3U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	   & (4U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__lhu 
	= ((3U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	   & (5U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sb 
	= ((0x23U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	   & (0U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sh 
	= ((0x23U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	   & (1U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sw 
	= ((0x23U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	   & (2U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__addi 
	= ((0x13U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	   & (0U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__slti 
	= ((0x13U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	   & (2U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sltiu 
	= ((0x13U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	   & (3U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__xori 
	= ((0x13U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	   & (4U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__ori 
	= ((0x13U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	   & (6U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__andi 
	= ((0x13U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	   & (7U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__slli 
	= (((0x13U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	    & (1U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			    >> 0xcU)))) & (0U == (0x7fU 
						  & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
						     >> 0x19U))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__srli 
	= (((0x13U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	    & (5U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			    >> 0xcU)))) & (0U == (0x7fU 
						  & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
						     >> 0x19U))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__srai 
	= (((0x13U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	    & (5U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			    >> 0xcU)))) & (0x20U == 
					   (0x7fU & 
					    (vlTOPp->top__DOT__cpu__DOT__id_instruction 
					     >> 0x19U))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__add 
	= (((0x33U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	    & (0U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			    >> 0xcU)))) & (0U == (0x7fU 
						  & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
						     >> 0x19U))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sub 
	= (((0x33U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	    & (0U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			    >> 0xcU)))) & (0x20U == 
					   (0x7fU & 
					    (vlTOPp->top__DOT__cpu__DOT__id_instruction 
					     >> 0x19U))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__slt 
	= (((0x33U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	    & (2U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			    >> 0xcU)))) & (0U == (0x7fU 
						  & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
						     >> 0x19U))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sltu 
	= (((0x33U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	    & (3U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			    >> 0xcU)))) & (0U == (0x7fU 
						  & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
						     >> 0x19U))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT___xor 
	= (((0x33U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	    & (4U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			    >> 0xcU)))) & (0U == (0x7fU 
						  & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
						     >> 0x19U))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT___or 
	= (((0x33U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	    & (6U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			    >> 0xcU)))) & (0U == (0x7fU 
						  & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
						     >> 0x19U))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT___and 
	= (((0x33U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	    & (7U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			    >> 0xcU)))) & (0U == (0x7fU 
						  & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
						     >> 0x19U))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sll 
	= (((0x33U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	    & (1U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			    >> 0xcU)))) & (0U == (0x7fU 
						  & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
						     >> 0x19U))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__srl 
	= (((0x33U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	    & (5U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			    >> 0xcU)))) & (0U == (0x7fU 
						  & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
						     >> 0x19U))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sra 
	= (((0x33U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	    & (5U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			    >> 0xcU)))) & (0x20U == 
					   (0x7fU & 
					    (vlTOPp->top__DOT__cpu__DOT__id_instruction 
					     >> 0x19U))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__fence 
	= ((0xfU == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	   & (0U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__fencei 
	= ((0xfU == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	   & (1U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__rw 
	= ((0x73U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	   & (1U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__rs 
	= ((0x73U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	   & (2U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__rc 
	= ((0x73U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	   & (3U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__rwi 
	= ((0x73U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	   & (5U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__rsi 
	= ((0x73U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	   & (6U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__rci 
	= ((0x73U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	   & (7U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__call 
	= ((0x73U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	   & (0U == (0x1ffffffU & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
				   >> 7U))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT___break 
	= ((0x73U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	   & (0x2000U == (0x1ffffffU & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
					>> 7U))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__xret 
	= (((0x73U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	    & (0U == (3U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			    >> 0x1eU)))) & (0x4000U 
					    == (0x1fffffU 
						& (vlTOPp->top__DOT__cpu__DOT__id_instruction 
						   >> 7U))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__uimp 
	= (0U == vlTOPp->top__DOT__cpu__DOT__id_instruction);
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_word 
	= ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__lw) 
	   | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sw));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_hw 
	= ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__lh) 
	   | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__lhu) 
	      | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sh)));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_byte 
	= ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__lb) 
	   | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__lbu) 
	      | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sb)));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_csri 
	= ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__rwi) 
	   | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__rsi) 
	      | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__rci)));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_ldu 
	= ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__lbu) 
	   | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__lhu));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_j 
	= ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__jal) 
	   | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__jalr));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_st 
	= ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sb) 
	   | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sh) 
	      | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sw)));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_b 
	= ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__beq) 
	   | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__bne) 
	      | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__blt) 
		 | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__bge) 
		    | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__bltu) 
		       | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__bgeu))))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_ld 
	= ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__lb) 
	   | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__lbu) 
	      | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__lh) 
		 | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__lhu) 
		    | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__lw)))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_imm 
	= ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__addi) 
	   | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__slti) 
	      | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sltiu) 
		 | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__ori) 
		    | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__andi) 
		       | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__slli) 
			  | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__srli) 
			     | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__srai) 
				| ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__xori) 
				   | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_ld) 
				      | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__jalr)))))))))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_add 
	= ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__add) 
	   | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__addi) 
	      | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_st) 
		 | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_ld) 
		    | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__lui) 
		       | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__auipc))))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_sub 
	= vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sub;
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_xor 
	= ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT___xor) 
	   | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__xori));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_and 
	= ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT___and) 
	   | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__andi));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_or 
	= ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT___or) 
	   | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__ori));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_sll 
	= ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sll) 
	   | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__slli));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_sr 
	= ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sra) 
	   | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__srl) 
	      | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__srai) 
		 | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__srli))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_slt 
	= ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__slt) 
	   | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__slti));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_sltu 
	= ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sltu) 
	   | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sltiu));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_alu 
	= ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__add) 
	   | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__addi) 
	      | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sub) 
		 | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_xor) 
		    | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_and) 
		       | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_or) 
			  | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_sll) 
			     | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_sr) 
				| ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_slt) 
				   | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_sltu))))))))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_csr 
	= ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__rw) 
	   | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__rs) 
	      | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__rc) 
		 | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_csri))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_immop 
	= ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__addi) 
	   | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__slli) 
	      | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__srai) 
		 | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__srli) 
		    | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__slti) 
		       | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sltiu) 
			  | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__ori) 
			     | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__andi) 
				| ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__xori) 
				   | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__jalr) 
				      | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_st) 
					 | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_ld) 
					    | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__lui) 
					       | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__auipc) 
						  | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_csri)))))))))))))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_wr 
	= ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_imm) 
	   | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_alu) 
	      | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_ld) 
		 | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__auipc) 
		    | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__lui) 
		       | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_csr))))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_fence 
	= ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__fence) 
	   | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__fencei));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__illegal 
	= (1U & (~ ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_j) 
		    | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_b) 
		       | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_add) 
			  | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_sub) 
			     | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_xor) 
				| ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_and) 
				   | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_or) 
				      | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_sll) 
					 | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_sr) 
					    | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_slt) 
					       | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_sltu) 
						  | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_csr) 
						     | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_fence) 
							| ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT___break) 
							   | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__call) 
							      | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__xret) 
								 | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__uimp)))))))))))))))))));
    // ALWAYS at hardware/titan_csr_exception_unit.v:194
    vlTOPp->top__DOT__cpu__DOT__CSR__DOT__pend_int 
	= ((IData)(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mstatus_mie)
	    ? (vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mip 
	       & vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mie)
	    : 0U);
    vlTOPp->top__DOT__cpu__DOT__CSR__DOT__interrupt 
	= (1U & ((vlTOPp->top__DOT__cpu__DOT__CSR__DOT__pend_int 
		  >> 0xbU) | ((vlTOPp->top__DOT__cpu__DOT__CSR__DOT__pend_int 
			       >> 7U) | (vlTOPp->top__DOT__cpu__DOT__CSR__DOT__pend_int 
					 >> 3U))));
    // ALWAYS at hardware/titan_dc_unit.v:184
    if (((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__lui) 
	 | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__auipc))) {
	vlTOPp->top__DOT__cpu__DOT__ID__DOT__imm = 
	    (0xfffff000U & vlTOPp->top__DOT__cpu__DOT__id_instruction);
    } else {
	if (vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__jal) {
	    vlTOPp->top__DOT__cpu__DOT__ID__DOT__imm 
		= ((((0x80000000U & vlTOPp->top__DOT__cpu__DOT__id_instruction)
		      ? 0xfffU : 0U) << 0x14U) | ((0x80000U 
						   & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
						      >> 0xcU)) 
						  | ((0x7f800U 
						      & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
							 >> 1U)) 
						     | ((0x400U 
							 & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
							    >> 0xaU)) 
							| (0x3ffU 
							   & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
							      >> 0x15U))))));
	} else {
	    if (vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_b) {
		vlTOPp->top__DOT__cpu__DOT__ID__DOT__imm 
		    = ((((0x80000000U & vlTOPp->top__DOT__cpu__DOT__id_instruction)
			  ? 0xfffffU : 0U) << 0xcU) 
		       | ((0x800U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
				     >> 0x14U)) | (
						   (0x400U 
						    & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
						       << 3U)) 
						   | ((0x3f0U 
						       & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
							  >> 0x15U)) 
						      | (0xfU 
							 & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
							    >> 8U))))));
	    } else {
		if (vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_imm) {
		    vlTOPp->top__DOT__cpu__DOT__ID__DOT__imm 
			= ((((0x80000000U & vlTOPp->top__DOT__cpu__DOT__id_instruction)
			      ? 0xfffffU : 0U) << 0xcU) 
			   | (0xfffU & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
					>> 0x14U)));
		} else {
		    if (vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_st) {
			vlTOPp->top__DOT__cpu__DOT__ID__DOT__imm 
			    = ((((0x80000000U & vlTOPp->top__DOT__cpu__DOT__id_instruction)
				  ? 0xfffffU : 0U) 
				<< 0xcU) | ((0xfe0U 
					     & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
						>> 0x14U)) 
					    | (0x1fU 
					       & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
						  >> 7U))));
		    } else {
			if (vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_csri) {
			    vlTOPp->top__DOT__cpu__DOT__ID__DOT__imm 
				= (0x1fU & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
					    >> 0xfU));
			}
		    }
		}
	    }
	}
    }
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__waddr = (0x1fU 
						  & ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_st)
						      ? 0U
						      : 
						     (vlTOPp->top__DOT__cpu__DOT__id_instruction 
						      >> 7U)));
    // ALWAYS at hardware/titan_dc_unit.v:204
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__comparator_op 
	= ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__beq)
	    ? 1U : ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__bne)
		     ? 2U : ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__blt)
			      ? 3U : ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__bge)
				       ? 4U : ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__bltu)
					        ? 5U
					        : ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__bgeu)
						    ? 6U
						    : 0U))))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__rs1 = (0x1fU 
						& ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__lui)
						    ? 0U
						    : 
						   (vlTOPp->top__DOT__cpu__DOT__id_instruction 
						    >> 0xfU)));
    // ALWAYS at hardware/titan_csr_exception_unit.v:173
    if (vlTOPp->top__DOT__cpu__DOT__CSR__DOT__interrupt) {
	if ((0x800U & vlTOPp->top__DOT__cpu__DOT__CSR__DOT__pend_int)) {
	    vlTOPp->top__DOT__cpu__DOT__CSR__DOT__exception_code = 3U;
	} else {
	    if ((0x80U & vlTOPp->top__DOT__cpu__DOT__CSR__DOT__pend_int)) {
		vlTOPp->top__DOT__cpu__DOT__CSR__DOT__exception_code = 7U;
	    } else {
		if ((8U & vlTOPp->top__DOT__cpu__DOT__CSR__DOT__pend_int)) {
		    vlTOPp->top__DOT__cpu__DOT__CSR__DOT__exception_code = 0xbU;
		}
	    }
	}
    }
    // ALWAYS at hardware/titan_mem_stage.v:100
    vlTOPp->top__DOT__cpu__DOT__wb_pc = (((IData)(vlTOPp->rst_i) 
					  | (IData)(vlTOPp->top__DOT__cpu__DOT__mem_flush))
					  ? 0U : vlTOPp->top__DOT__cpu__DOT__mem_pc);
    vlTOPp->top__DOT__cpu__DOT__wb_instruction = (((IData)(vlTOPp->rst_i) 
						   | (IData)(vlTOPp->top__DOT__cpu__DOT__mem_flush))
						   ? 0x33U
						   : vlTOPp->top__DOT__cpu__DOT__mem_instruction);
    vlTOPp->top__DOT__cpu__DOT__wb_result_mem = (((IData)(vlTOPp->rst_i) 
						  | (IData)(vlTOPp->top__DOT__cpu__DOT__mem_flush))
						  ? 0U
						  : vlTOPp->top__DOT__cpu__DOT__MEM__DOT__mem_result);
    vlTOPp->top__DOT__cpu__DOT__wb_rs1 = (((IData)(vlTOPp->rst_i) 
					   | (IData)(vlTOPp->top__DOT__cpu__DOT__mem_flush))
					   ? 0U : (IData)(vlTOPp->top__DOT__cpu__DOT__mem_rs1));
    vlTOPp->top__DOT__cpu__DOT__wb_waddr = (((IData)(vlTOPp->rst_i) 
					     | (IData)(vlTOPp->top__DOT__cpu__DOT__mem_flush))
					     ? 0U : (IData)(vlTOPp->top__DOT__cpu__DOT__mem_waddr));
    vlTOPp->top__DOT__cpu__DOT__wb_we = ((~ ((IData)(vlTOPp->rst_i) 
					     | (IData)(vlTOPp->top__DOT__cpu__DOT__mem_flush))) 
					 & (IData)(vlTOPp->top__DOT__cpu__DOT__mem_we));
    vlTOPp->top__DOT__cpu__DOT__wb_csr_data = (((IData)(vlTOPp->rst_i) 
						| (IData)(vlTOPp->top__DOT__cpu__DOT__mem_flush))
					        ? 0U
					        : vlTOPp->top__DOT__cpu__DOT__mem_csr_data);
    vlTOPp->top__DOT__cpu__DOT__wb_csr_addr = (((IData)(vlTOPp->rst_i) 
						| (IData)(vlTOPp->top__DOT__cpu__DOT__mem_flush))
					        ? 0U
					        : (IData)(vlTOPp->top__DOT__cpu__DOT__mem_csr_addr));
    vlTOPp->top__DOT__cpu__DOT__wb_csr_op = (((IData)(vlTOPp->rst_i) 
					      | (IData)(vlTOPp->top__DOT__cpu__DOT__mem_flush))
					      ? 0U : (IData)(vlTOPp->top__DOT__cpu__DOT__mem_csr_op));
    vlTOPp->top__DOT__cpu__DOT__wb_inst_addr_misaligned 
	= ((~ ((IData)(vlTOPp->rst_i) | (IData)(vlTOPp->top__DOT__cpu__DOT__mem_flush))) 
	   & (IData)(vlTOPp->top__DOT__cpu__DOT__mem_inst_addr_misaligned));
    vlTOPp->top__DOT__cpu__DOT__wb_load_addr_misaligned 
	= (1U & ((~ ((IData)(vlTOPp->rst_i) | (IData)(vlTOPp->top__DOT__cpu__DOT__mem_flush))) 
		 & ((1U & (((IData)(vlTOPp->top__DOT__cpu__DOT__mem_mem_flags) 
			    >> 4U) & ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_mem_flags) 
				      >> 3U))) ? (0U 
						  != 
						  (3U 
						   & vlTOPp->top__DOT__cpu__DOT__mem_result))
		     : ((((IData)(vlTOPp->top__DOT__cpu__DOT__mem_mem_flags) 
			  >> 4U) & ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_mem_flags) 
				    >> 2U)) & vlTOPp->top__DOT__cpu__DOT__mem_result))));
    vlTOPp->top__DOT__cpu__DOT__wb_store_addr_misaligned 
	= (1U & ((~ ((IData)(vlTOPp->rst_i) | (IData)(vlTOPp->top__DOT__cpu__DOT__mem_flush))) 
		 & ((1U & (((IData)(vlTOPp->top__DOT__cpu__DOT__mem_mem_flags) 
			    >> 5U) & ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_mem_flags) 
				      >> 3U))) ? (0U 
						  != 
						  (3U 
						   & vlTOPp->top__DOT__cpu__DOT__mem_result))
		     : ((((IData)(vlTOPp->top__DOT__cpu__DOT__mem_mem_flags) 
			  >> 5U) & ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_mem_flags) 
				    >> 2U)) & vlTOPp->top__DOT__cpu__DOT__mem_result))));
    vlTOPp->top__DOT__cpu__DOT__wb_inst_access_fault 
	= ((~ ((IData)(vlTOPp->rst_i) | (IData)(vlTOPp->top__DOT__cpu__DOT__mem_flush))) 
	   & (IData)(vlTOPp->top__DOT__cpu__DOT__mem_inst_access_fault));
    vlTOPp->top__DOT__cpu__DOT__wb_illegal_inst = (
						   (~ 
						    ((IData)(vlTOPp->rst_i) 
						     | (IData)(vlTOPp->top__DOT__cpu__DOT__mem_flush))) 
						   & (IData)(vlTOPp->top__DOT__cpu__DOT__mem_illegal_inst));
    vlTOPp->top__DOT__cpu__DOT__wb_fence_op = ((~ ((IData)(vlTOPp->rst_i) 
						   | (IData)(vlTOPp->top__DOT__cpu__DOT__mem_flush))) 
					       & (IData)(vlTOPp->top__DOT__cpu__DOT__mem_fence_op));
    vlTOPp->top__DOT__cpu__DOT__wb_xret_op = ((~ ((IData)(vlTOPp->rst_i) 
						  | (IData)(vlTOPp->top__DOT__cpu__DOT__mem_flush))) 
					      & (IData)(vlTOPp->top__DOT__cpu__DOT__mem_xret_op));
    vlTOPp->top__DOT__cpu__DOT__wb_break_op = ((~ ((IData)(vlTOPp->rst_i) 
						   | (IData)(vlTOPp->top__DOT__cpu__DOT__mem_flush))) 
					       & (IData)(vlTOPp->top__DOT__cpu__DOT__mem_break_op));
    vlTOPp->top__DOT__cpu__DOT__wb_syscall_op = ((~ 
						  ((IData)(vlTOPp->rst_i) 
						   | (IData)(vlTOPp->top__DOT__cpu__DOT__mem_flush))) 
						 & (IData)(vlTOPp->top__DOT__cpu__DOT__mem_syscall_op));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__drs1 = ((0U 
						  == (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__rs1))
						  ? 0U
						  : 
						 vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file
						 [vlTOPp->top__DOT__cpu__DOT__ID__DOT__rs1]);
    vlTOPp->top__DOT__cpu__DOT__FWD__DOT__ex_fwd_a 
	= (((~ (IData)(vlTOPp->top__DOT__cpu__DOT__ex_mem_ex_sel)) 
	    & ((IData)(vlTOPp->top__DOT__cpu__DOT__ex_waddr) 
	       == (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__rs1))) 
	   & (IData)(vlTOPp->top__DOT__cpu__DOT__ex_we));
    vlTOPp->top__DOT__cpu__DOT__mem_pc = __Vdly__top__DOT__cpu__DOT__mem_pc;
    vlTOPp->top__DOT__cpu__DOT__mem_instruction = __Vdly__top__DOT__cpu__DOT__mem_instruction;
    vlTOPp->top__DOT__cpu__DOT__mem_rs1 = __Vdly__top__DOT__cpu__DOT__mem_rs1;
    vlTOPp->top__DOT__cpu__DOT__mem_csr_data = __Vdly__top__DOT__cpu__DOT__mem_csr_data;
    vlTOPp->top__DOT__cpu__DOT__mem_csr_addr = __Vdly__top__DOT__cpu__DOT__mem_csr_addr;
    vlTOPp->top__DOT__cpu__DOT__mem_csr_op = __Vdly__top__DOT__cpu__DOT__mem_csr_op;
    vlTOPp->top__DOT__cpu__DOT__mem_inst_addr_misaligned 
	= __Vdly__top__DOT__cpu__DOT__mem_inst_addr_misaligned;
    vlTOPp->top__DOT__cpu__DOT__mem_inst_access_fault 
	= __Vdly__top__DOT__cpu__DOT__mem_inst_access_fault;
    vlTOPp->top__DOT__cpu__DOT__mem_illegal_inst = __Vdly__top__DOT__cpu__DOT__mem_illegal_inst;
    vlTOPp->top__DOT__cpu__DOT__mem_fence_op = __Vdly__top__DOT__cpu__DOT__mem_fence_op;
    vlTOPp->top__DOT__cpu__DOT__mem_xret_op = __Vdly__top__DOT__cpu__DOT__mem_xret_op;
    vlTOPp->top__DOT__cpu__DOT__mem_break_op = __Vdly__top__DOT__cpu__DOT__mem_break_op;
    vlTOPp->top__DOT__cpu__DOT__mem_syscall_op = __Vdly__top__DOT__cpu__DOT__mem_syscall_op;
    vlTOPp->top__DOT__cpu__DOT__mem_waddr = __Vdly__top__DOT__cpu__DOT__mem_waddr;
    vlTOPp->top__DOT__cpu__DOT__mem_we = __Vdly__top__DOT__cpu__DOT__mem_we;
    vlTOPp->top__DOT__cpu__DOT__mem_result = __Vdly__top__DOT__cpu__DOT__mem_result;
    vlTOPp->top__DOT__cpu__DOT__mem_mem_flags = __Vdly__top__DOT__cpu__DOT__mem_mem_flags;
    vlTOPp->top__DOT__cpu__DOT__ID__DOT___imm = ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__jalr)
						  ? 
						 ((vlTOPp->top__DOT__cpu__DOT__ID__DOT__imm 
						   << 1U) 
						  + vlTOPp->top__DOT__cpu__DOT__ID__DOT__drs1)
						  : 
						 (vlTOPp->top__DOT__cpu__DOT__ID__DOT__imm 
						  << 1U));
    // ALWAYS at hardware/titan_csr_exception_unit.v:121
    vlTOPp->top__DOT__cpu__DOT__CSR__DOT__exception_code 
	= ((IData)(vlTOPp->top__DOT__cpu__DOT__wb_inst_addr_misaligned)
	    ? 0U : ((IData)(vlTOPp->top__DOT__cpu__DOT__wb_inst_access_fault)
		     ? 1U : ((IData)(vlTOPp->top__DOT__cpu__DOT__wb_illegal_inst)
			      ? 2U : ((IData)(vlTOPp->top__DOT__cpu__DOT__wb_syscall_op)
				       ? 0xbU : ((IData)(vlTOPp->top__DOT__cpu__DOT__wb_break_op)
						  ? 3U
						  : 
						 ((IData)(vlTOPp->top__DOT__cpu__DOT__wb_load_access_fault)
						   ? 5U
						   : 
						  ((IData)(vlTOPp->top__DOT__cpu__DOT__wb_load_addr_misaligned)
						    ? 4U
						    : 
						   ((IData)(vlTOPp->top__DOT__cpu__DOT__wb_store_access_fault)
						     ? 7U
						     : 
						    ((IData)(vlTOPp->top__DOT__cpu__DOT__wb_store_addr_misaligned)
						      ? 6U
						      : 0U)))))))));
    vlTOPp->top__DOT__cpu__DOT__exception_stall_req 
	= ((IData)(vlTOPp->top__DOT__cpu__DOT__wb_syscall_op) 
	   | (IData)(vlTOPp->top__DOT__cpu__DOT__wb_xret_op));
    vlTOPp->top__DOT__cpu__DOT__ld_dependence = ((((IData)(vlTOPp->top__DOT__cpu__DOT__FWD__DOT__ex_fwd_a) 
						   | (IData)(vlTOPp->top__DOT__cpu__DOT__FWD__DOT__ex_fwd_b)) 
						  & (IData)(vlTOPp->top__DOT__cpu__DOT__ex_mem_ex_sel)) 
						 & (IData)(vlTOPp->top__DOT__cpu__DOT__mem_we));
    // ALWAYS at hardware/titan_forwarding_unit.v:33
    vlTOPp->top__DOT__cpu__DOT__forward_a_sel = ((IData)(vlTOPp->top__DOT__cpu__DOT__FWD__DOT__ex_fwd_a)
						  ? 1U
						  : 
						 ((((IData)(vlTOPp->top__DOT__cpu__DOT__mem_waddr) 
						    == (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__rs1)) 
						   & (IData)(vlTOPp->top__DOT__cpu__DOT__mem_we))
						   ? 2U
						   : 
						  ((((IData)(vlTOPp->top__DOT__cpu__DOT__wb_waddr) 
						     == (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__rs1)) 
						    & (IData)(vlTOPp->top__DOT__cpu__DOT__wb_we))
						    ? 3U
						    : 0U)));
    // ALWAYS at hardware/titan_forwarding_unit.v:42
    vlTOPp->top__DOT__cpu__DOT__forward_b_sel = ((IData)(vlTOPp->top__DOT__cpu__DOT__FWD__DOT__ex_fwd_b)
						  ? 
						 ((IData)(vlTOPp->top__DOT__cpu__DOT__ex_we)
						   ? 1U
						   : 0U)
						  : 
						 ((((IData)(vlTOPp->top__DOT__cpu__DOT__mem_waddr) 
						    == 
						    (0x1fU 
						     & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
							>> 0x14U))) 
						   & (IData)(vlTOPp->top__DOT__cpu__DOT__mem_we))
						   ? 
						  ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_we)
						    ? 2U
						    : 0U)
						   : 
						  ((((IData)(vlTOPp->top__DOT__cpu__DOT__wb_waddr) 
						     == 
						     (0x1fU 
						      & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
							 >> 0x14U))) 
						    & (IData)(vlTOPp->top__DOT__cpu__DOT__wb_we))
						    ? 
						   ((IData)(vlTOPp->top__DOT__cpu__DOT__wb_we)
						     ? 3U
						     : 0U)
						    : 0U)));
    // ALWAYS at hardware/titan_csr_exception_unit.v:334
    vlTOPp->top__DOT__cpu__DOT__csr_data_o = ((((((
						   (((0x301U 
						      == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr)) 
						     | (0xf14U 
							== (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))) 
						    | ((0xf11U 
							== (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr)) 
						       | ((0xf12U 
							   == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr)) 
							  | (0xf14U 
							     == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))))) 
						   | (0x300U 
						      == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))) 
						  | (0x304U 
						     == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))) 
						 | (0x305U 
						    == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))) 
						| (0x340U 
						   == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))) 
					       | (0x341U 
						  == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr)))
					       ? ((0x301U 
						   == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))
						   ? 0x40000080U
						   : 
						  ((0xf14U 
						    == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))
						    ? 0U
						    : 
						   (((0xf11U 
						      == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr)) 
						     | ((0xf12U 
							 == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr)) 
							| (0xf14U 
							   == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))))
						     ? 0U
						     : 
						    ((0x300U 
						      == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))
						      ? vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mstatus
						      : 
						     ((0x304U 
						       == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))
						       ? vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mie
						       : 
						      ((0x305U 
							== (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))
						        ? vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mtvec
						        : 
						       ((0x340U 
							 == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))
							 ? vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mscratch
							 : vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mepc)))))))
					       : ((0x342U 
						   == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))
						   ? vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mcause
						   : 
						  ((0x343U 
						    == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))
						    ? vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mtval
						    : 
						   ((0x344U 
						     == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))
						     ? vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mip
						     : 
						    (((0xb00U 
						       == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr)) 
						      | (0xb80U 
							 == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr)))
						      ? 
						     ((0xb00U 
						       == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))
						       ? (IData)(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mcycle)
						       : (IData)(
								 (vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mcycle 
								  >> 0x20U)))
						      : 
						     (((0xb02U 
							== (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr)) 
						       | (0xb82U 
							  == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr)))
						       ? 
						      ((0xb02U 
							== (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))
						        ? (IData)(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__minstret)
						        : (IData)(
								  (vlTOPp->top__DOT__cpu__DOT__CSR__DOT__minstret 
								   >> 0x20U)))
						       : 0U))))));
    // ALWAYS at tests/verilator/ram.v:74
    vlTOPp->top__DOT__dwbm_ack = (((IData)(vlTOPp->top__DOT__dwbm_cyc) 
				   & (IData)(vlTOPp->top__DOT__dwbm_stb)) 
				  & (0x80U == (0xffU 
					       & (vlTOPp->top__DOT__cpu__DOT__mem_result 
						  >> 0x18U))));
    // ALWAYS at tests/verilator/ram.v:74
    vlTOPp->top__DOT__dwbm_dat_i = 0xffffffffU;
    if (((IData)(vlTOPp->top__DOT__dwbm_we) & (0x80U 
					       == (0xffU 
						   & (vlTOPp->top__DOT__cpu__DOT__mem_result 
						      >> 0x18U))))) {
	if ((1U & (IData)(vlTOPp->top__DOT__dwbm_sel))) {
	    vlTOPp->top__DOT__memory__DOT__mem[(0xfffffcU 
						& vlTOPp->top__DOT__cpu__DOT__mem_result)] 
		= (0xffU & vlTOPp->top__DOT__dwbm_dat_o);
	}
	if ((2U & (IData)(vlTOPp->top__DOT__dwbm_sel))) {
	    vlTOPp->top__DOT__memory__DOT__mem[(0xffffffU 
						& ((IData)(1U) 
						   + 
						   (0xfffffcU 
						    & vlTOPp->top__DOT__cpu__DOT__mem_result)))] 
		= (0xffU & (vlTOPp->top__DOT__dwbm_dat_o 
			    >> 8U));
	}
	if ((4U & (IData)(vlTOPp->top__DOT__dwbm_sel))) {
	    vlTOPp->top__DOT__memory__DOT__mem[(0xffffffU 
						& ((IData)(2U) 
						   + 
						   (0xfffffcU 
						    & vlTOPp->top__DOT__cpu__DOT__mem_result)))] 
		= (0xffU & (vlTOPp->top__DOT__dwbm_dat_o 
			    >> 0x10U));
	}
	if ((8U & (IData)(vlTOPp->top__DOT__dwbm_sel))) {
	    vlTOPp->top__DOT__memory__DOT__mem[(0xffffffU 
						& ((IData)(3U) 
						   + 
						   (0xfffffcU 
						    & vlTOPp->top__DOT__cpu__DOT__mem_result)))] 
		= (0xffU & (vlTOPp->top__DOT__dwbm_dat_o 
			    >> 0x18U));
	}
    } else {
	vlTOPp->top__DOT__dwbm_dat_i = ((0xffffff00U 
					 & vlTOPp->top__DOT__dwbm_dat_i) 
					| vlTOPp->top__DOT__memory__DOT__mem
					[(0xfffffcU 
					  & vlTOPp->top__DOT__cpu__DOT__mem_result)]);
	vlTOPp->top__DOT__dwbm_dat_i = ((0xffff00ffU 
					 & vlTOPp->top__DOT__dwbm_dat_i) 
					| (vlTOPp->top__DOT__memory__DOT__mem
					   [(0xffffffU 
					     & ((IData)(1U) 
						+ (0xfffffcU 
						   & vlTOPp->top__DOT__cpu__DOT__mem_result)))] 
					   << 8U));
	vlTOPp->top__DOT__dwbm_dat_i = ((0xff00ffffU 
					 & vlTOPp->top__DOT__dwbm_dat_i) 
					| (vlTOPp->top__DOT__memory__DOT__mem
					   [(0xffffffU 
					     & ((IData)(2U) 
						+ (0xfffffcU 
						   & vlTOPp->top__DOT__cpu__DOT__mem_result)))] 
					   << 0x10U));
	vlTOPp->top__DOT__dwbm_dat_i = ((0xffffffU 
					 & vlTOPp->top__DOT__dwbm_dat_i) 
					| (vlTOPp->top__DOT__memory__DOT__mem
					   [(0xffffffU 
					     & ((IData)(3U) 
						+ (0xfffffcU 
						   & vlTOPp->top__DOT__cpu__DOT__mem_result)))] 
					   << 0x18U));
    }
    // ALWAYS at hardware/titan_lsu.v:151
    if ((8U & (IData)(vlTOPp->top__DOT__cpu__DOT__mem_mem_flags))) {
	vlTOPp->top__DOT__cpu__DOT__LSU__DOT__wsel_o = 0xfU;
    } else {
	if ((4U & (IData)(vlTOPp->top__DOT__cpu__DOT__mem_mem_flags))) {
	    vlTOPp->top__DOT__cpu__DOT__LSU__DOT__wsel_o = 3U;
	} else {
	    if ((2U & (IData)(vlTOPp->top__DOT__cpu__DOT__mem_mem_flags))) {
		vlTOPp->top__DOT__cpu__DOT__LSU__DOT__wsel_o = 1U;
	    }
	}
    }
    // ALWAYS at hardware/titan_lsu.v:159
    if ((0x10U & (IData)(vlTOPp->top__DOT__cpu__DOT__mem_mem_flags))) {
	if ((8U & (IData)(vlTOPp->top__DOT__cpu__DOT__mem_mem_flags))) {
	    vlTOPp->top__DOT__cpu__DOT__LSU__DOT__rsel_o = 0xfU;
	} else {
	    if ((4U & (IData)(vlTOPp->top__DOT__cpu__DOT__mem_mem_flags))) {
		vlTOPp->top__DOT__cpu__DOT__LSU__DOT__rsel_o = 3U;
	    } else {
		if ((2U & (IData)(vlTOPp->top__DOT__cpu__DOT__mem_mem_flags))) {
		    vlTOPp->top__DOT__cpu__DOT__LSU__DOT__rsel_o = 1U;
		}
	    }
	}
	vlTOPp->top__DOT__cpu__DOT__LSU__DOT__runsigned 
	    = (1U & (IData)(vlTOPp->top__DOT__cpu__DOT__mem_mem_flags));
    }
    // ALWAYS at hardware/titan_csr_exception_unit.v:161
    if (((0U != (IData)(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__exception_code)) 
	 | (IData)(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__interrupt))) {
	vlTOPp->top__DOT__cpu__DOT__CSR__DOT__trap_valid = 1U;
	vlTOPp->top__DOT__cpu__DOT__exception_pc = vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mtvec;
    } else {
	if (vlTOPp->top__DOT__cpu__DOT__wb_xret_op) {
	    vlTOPp->top__DOT__cpu__DOT__exception_pc 
		= vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mepc;
	    vlTOPp->top__DOT__cpu__DOT__CSR__DOT__trap_valid = 0U;
	} else {
	    vlTOPp->top__DOT__cpu__DOT__CSR__DOT__trap_valid = 0U;
	}
    }
    // ALWAYS at hardware/titan_csr_exception_unit.v:222
    vlTOPp->top__DOT__cpu__DOT__CSR__DOT__csr_wdata 
	= ((1U == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_op))
	    ? vlTOPp->top__DOT__cpu__DOT__wb_csr_data
	    : ((2U == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_op))
	        ? (vlTOPp->top__DOT__cpu__DOT__csr_data_o 
		   | vlTOPp->top__DOT__cpu__DOT__wb_csr_data)
	        : ((4U == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_op))
		    ? (vlTOPp->top__DOT__cpu__DOT__csr_data_o 
		       & (~ vlTOPp->top__DOT__cpu__DOT__wb_csr_data))
		    : 0U)));
    // ALWAYS at hardware/titan_mux21.v:9
    if ((0U != (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_op))) {
	if ((0U != (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_op))) {
	    vlTOPp->top__DOT__cpu__DOT__wb_result = vlTOPp->top__DOT__cpu__DOT__csr_data_o;
	}
    } else {
	vlTOPp->top__DOT__cpu__DOT__wb_result = vlTOPp->top__DOT__cpu__DOT__wb_result_mem;
    }
    vlTOPp->top__DOT__cpu__DOT__mem_stall_req = (1U 
						 & ((((IData)(vlTOPp->top__DOT__cpu__DOT__mem_mem_flags) 
						      >> 4U) 
						     ^ 
						     ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_mem_flags) 
						      >> 5U)) 
						    & (~ (IData)(vlTOPp->top__DOT__dwbm_ack))));
    // ALWAYS at tests/verilator/ram.v:60
    vlTOPp->top__DOT__iwbm_dat = 0xffffffffU;
    if ((0x80U == (0xffU & (vlTOPp->top__DOT__cpu__DOT__if_pc 
			    >> 0x18U)))) {
	vlTOPp->top__DOT__iwbm_dat = ((0xffffff00U 
				       & vlTOPp->top__DOT__iwbm_dat) 
				      | vlTOPp->top__DOT__memory__DOT__mem
				      [(0xfffffcU & vlTOPp->top__DOT__cpu__DOT__if_pc)]);
	vlTOPp->top__DOT__iwbm_dat = ((0xffff00ffU 
				       & vlTOPp->top__DOT__iwbm_dat) 
				      | (vlTOPp->top__DOT__memory__DOT__mem
					 [(0xffffffU 
					   & ((IData)(1U) 
					      + (0xfffffcU 
						 & vlTOPp->top__DOT__cpu__DOT__if_pc)))] 
					 << 8U));
	vlTOPp->top__DOT__iwbm_dat = ((0xff00ffffU 
				       & vlTOPp->top__DOT__iwbm_dat) 
				      | (vlTOPp->top__DOT__memory__DOT__mem
					 [(0xffffffU 
					   & ((IData)(2U) 
					      + (0xfffffcU 
						 & vlTOPp->top__DOT__cpu__DOT__if_pc)))] 
					 << 0x10U));
	vlTOPp->top__DOT__iwbm_dat = ((0xffffffU & vlTOPp->top__DOT__iwbm_dat) 
				      | (vlTOPp->top__DOT__memory__DOT__mem
					 [(0xffffffU 
					   & ((IData)(3U) 
					      + (0xfffffcU 
						 & vlTOPp->top__DOT__cpu__DOT__if_pc)))] 
					 << 0x18U));
    }
    // ALWAYS at hardware/titan_lsu.v:171
    if ((0x10U & (IData)(vlTOPp->top__DOT__cpu__DOT__mem_mem_flags))) {
	vlTOPp->top__DOT__cpu__DOT__mem_load_data = 
	    ((1U == (IData)(vlTOPp->top__DOT__cpu__DOT__LSU__DOT__rsel_o))
	      ? ((0xffffff00U & (((IData)(vlTOPp->top__DOT__cpu__DOT__LSU__DOT__runsigned)
				   ? 0U : VL_NEGATE_I((IData)(
							      (1U 
							       & (vlTOPp->top__DOT__dwbm_dat_i 
								  >> 7U))))) 
				 << 8U)) | (0xffU & vlTOPp->top__DOT__dwbm_dat_i))
	      : ((3U == (IData)(vlTOPp->top__DOT__cpu__DOT__LSU__DOT__rsel_o))
		  ? ((0xffff0000U & (((IData)(vlTOPp->top__DOT__cpu__DOT__LSU__DOT__runsigned)
				       ? 0U : VL_NEGATE_I((IData)(
								  (1U 
								   & (vlTOPp->top__DOT__dwbm_dat_i 
								      >> 0xfU))))) 
				     << 0x10U)) | (0xffffU 
						   & vlTOPp->top__DOT__dwbm_dat_i))
		  : vlTOPp->top__DOT__dwbm_dat_i));
    } else {
	if ((0x20U & (IData)(vlTOPp->top__DOT__cpu__DOT__mem_mem_flags))) {
	    vlTOPp->top__DOT__cpu__DOT__LSU__DOT__wdata 
		= ((1U == (IData)(vlTOPp->top__DOT__cpu__DOT__LSU__DOT__wsel_o))
		    ? (0xffU & vlTOPp->top__DOT__cpu__DOT__mem_store_data)
		    : ((3U == (IData)(vlTOPp->top__DOT__cpu__DOT__LSU__DOT__wsel_o))
		        ? (0xffffU & vlTOPp->top__DOT__cpu__DOT__mem_store_data)
		        : vlTOPp->top__DOT__cpu__DOT__mem_store_data));
	}
    }
    // ALWAYS at hardware/titan_mem_stage.v:90
    if (vlTOPp->top__DOT__cpu__DOT__mem_mem_ex_sel) {
	if (vlTOPp->top__DOT__cpu__DOT__mem_mem_ex_sel) {
	    vlTOPp->top__DOT__cpu__DOT__MEM__DOT__mem_result 
		= vlTOPp->top__DOT__cpu__DOT__mem_load_data;
	}
    } else {
	vlTOPp->top__DOT__cpu__DOT__MEM__DOT__mem_result 
	    = vlTOPp->top__DOT__cpu__DOT__mem_result;
    }
    // ALWAYS at hardware/titan_mux41.v:11
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__muxa_i = (
						   (2U 
						    & (IData)(vlTOPp->top__DOT__cpu__DOT__forward_a_sel))
						    ? 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__cpu__DOT__forward_a_sel))
						     ? vlTOPp->top__DOT__cpu__DOT__wb_result
						     : vlTOPp->top__DOT__cpu__DOT__MEM__DOT__mem_result)
						    : 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__cpu__DOT__forward_a_sel))
						     ? vlTOPp->top__DOT__cpu__DOT__EX__DOT__ex_result
						     : vlTOPp->top__DOT__cpu__DOT__ID__DOT__drs1));
    // ALWAYS at hardware/titan_mux41.v:11
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__muxb_i = (
						   (2U 
						    & (IData)(vlTOPp->top__DOT__cpu__DOT__forward_b_sel))
						    ? 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__cpu__DOT__forward_b_sel))
						     ? vlTOPp->top__DOT__cpu__DOT__wb_result
						     : vlTOPp->top__DOT__cpu__DOT__MEM__DOT__mem_result)
						    : 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__cpu__DOT__forward_b_sel))
						     ? vlTOPp->top__DOT__cpu__DOT__EX__DOT__ex_result
						     : 
						    ((0U 
						      == 
						      (0x1fU 
						       & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
							  >> 0x14U)))
						      ? 0U
						      : 
						     vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file
						     [
						     (0x1fU 
						      & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
							 >> 0x14U))])));
    // ALWAYS at hardware/titan_mux21.v:9
    if (vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__auipc) {
	if (vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__auipc) {
	    vlTOPp->top__DOT__cpu__DOT__ID__DOT__port_a 
		= vlTOPp->top__DOT__cpu__DOT__id_pc;
	}
    } else {
	vlTOPp->top__DOT__cpu__DOT__ID__DOT__port_a 
	    = vlTOPp->top__DOT__cpu__DOT__ID__DOT__muxa_i;
    }
    // ALWAYS at hardware/titan_mux21.v:9
    if (vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_immop) {
	if (vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_immop) {
	    vlTOPp->top__DOT__cpu__DOT__ID__DOT__port_b 
		= vlTOPp->top__DOT__cpu__DOT__ID__DOT__imm;
	}
    } else {
	vlTOPp->top__DOT__cpu__DOT__ID__DOT__port_b 
	    = vlTOPp->top__DOT__cpu__DOT__ID__DOT__muxb_i;
    }
    vlTOPp->top__DOT__cpu__DOT__take_branch = ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_b) 
					       & ((4U 
						   & (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__comparator_op))
						   ? 
						  ((2U 
						    & (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__comparator_op))
						    ? 
						   ((~ (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__comparator_op)) 
						    & (vlTOPp->top__DOT__cpu__DOT__ID__DOT__muxa_i 
						       >= vlTOPp->top__DOT__cpu__DOT__ID__DOT__muxb_i))
						    : 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__comparator_op))
						     ? 
						    (vlTOPp->top__DOT__cpu__DOT__ID__DOT__muxa_i 
						     < vlTOPp->top__DOT__cpu__DOT__ID__DOT__muxb_i)
						     : 
						    VL_GTES_III(1,32,32, vlTOPp->top__DOT__cpu__DOT__ID__DOT__muxa_i, vlTOPp->top__DOT__cpu__DOT__ID__DOT__muxb_i)))
						   : 
						  ((2U 
						    & (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__comparator_op))
						    ? 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__comparator_op))
						     ? 
						    VL_LTS_III(1,32,32, vlTOPp->top__DOT__cpu__DOT__ID__DOT__muxa_i, vlTOPp->top__DOT__cpu__DOT__ID__DOT__muxb_i)
						     : 
						    (vlTOPp->top__DOT__cpu__DOT__ID__DOT__muxa_i 
						     != vlTOPp->top__DOT__cpu__DOT__ID__DOT__muxb_i))
						    : 
						   ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__comparator_op) 
						    & (vlTOPp->top__DOT__cpu__DOT__ID__DOT__muxa_i 
						       == vlTOPp->top__DOT__cpu__DOT__ID__DOT__muxb_i)))));
    // ALWAYS at hardware/titan_control_unit.v:39
    vlTOPp->top__DOT__cpu__DOT__if_pc_sel = ((IData)(vlTOPp->top__DOT__cpu__DOT__take_branch)
					      ? 1U : 
					     ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_j)
					       ? 2U
					       : ((IData)(vlTOPp->top__DOT__cpu__DOT__exception_stall_req)
						   ? 3U
						   : 0U)));
    vlTOPp->top__DOT__cpu__DOT__if_kill = ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_j) 
					   | (IData)(vlTOPp->top__DOT__cpu__DOT__take_branch));
    // ALWAYS at hardware/titan_pc_source.v:10
    vlTOPp->top__DOT__cpu__DOT__IF__DOT__if_pc_mux 
	= ((2U & (IData)(vlTOPp->top__DOT__cpu__DOT__if_pc_sel))
	    ? ((1U & (IData)(vlTOPp->top__DOT__cpu__DOT__if_pc_sel))
	        ? vlTOPp->top__DOT__cpu__DOT__exception_pc
	        : (0xfffffffeU & (vlTOPp->top__DOT__cpu__DOT__id_pc 
				  + vlTOPp->top__DOT__cpu__DOT__ID__DOT___imm)))
	    : ((1U & (IData)(vlTOPp->top__DOT__cpu__DOT__if_pc_sel))
	        ? (vlTOPp->top__DOT__cpu__DOT__ID__DOT___imm 
		   + vlTOPp->top__DOT__cpu__DOT__id_pc)
	        : ((IData)(4U) + vlTOPp->top__DOT__cpu__DOT__if_pc)));
}

void Vtop::_settle__TOP__3(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_settle__TOP__3\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at tests/verilator/ram.v:60
    vlTOPp->top__DOT__iwbm_ack = (((IData)(vlTOPp->top__DOT__iwbm_cyc) 
				   & (IData)(vlTOPp->top__DOT__iwbm_stb)) 
				  & (0x80U == (0xffU 
					       & (vlTOPp->top__DOT__cpu__DOT__if_pc 
						  >> 0x18U))));
    // ALWAYS at hardware/titan_exu.v:19
    vlTOPp->top__DOT__cpu__DOT__EX__DOT__ex_result 
	= ((8U & (IData)(vlTOPp->top__DOT__cpu__DOT__ex_alu_op))
	    ? ((4U & (IData)(vlTOPp->top__DOT__cpu__DOT__ex_alu_op))
	        ? 0U : ((2U & (IData)(vlTOPp->top__DOT__cpu__DOT__ex_alu_op))
			 ? 0U : ((1U & (IData)(vlTOPp->top__DOT__cpu__DOT__ex_alu_op))
				  ? (vlTOPp->top__DOT__cpu__DOT__ex_port_a 
				     < vlTOPp->top__DOT__cpu__DOT__ex_port_b)
				  : VL_LTS_III(32,32,32, vlTOPp->top__DOT__cpu__DOT__ex_port_a, vlTOPp->top__DOT__cpu__DOT__ex_port_b))))
	    : ((4U & (IData)(vlTOPp->top__DOT__cpu__DOT__ex_alu_op))
	        ? ((2U & (IData)(vlTOPp->top__DOT__cpu__DOT__ex_alu_op))
		    ? ((1U & (IData)(vlTOPp->top__DOT__cpu__DOT__ex_alu_op))
		        ? ((0x1fU >= vlTOPp->top__DOT__cpu__DOT__ex_port_b)
			    ? (vlTOPp->top__DOT__cpu__DOT__ex_port_a 
			       >> vlTOPp->top__DOT__cpu__DOT__ex_port_b)
			    : 0U) : ((0x1fU >= vlTOPp->top__DOT__cpu__DOT__ex_port_b)
				      ? VL_SHIFTRS_III(32,32,32, vlTOPp->top__DOT__cpu__DOT__ex_port_a, vlTOPp->top__DOT__cpu__DOT__ex_port_b)
				      : VL_NEGATE_I(
						    (vlTOPp->top__DOT__cpu__DOT__ex_port_a 
						     >> 0x1fU))))
		    : ((1U & (IData)(vlTOPp->top__DOT__cpu__DOT__ex_alu_op))
		        ? ((0x1fU >= vlTOPp->top__DOT__cpu__DOT__ex_port_b)
			    ? (vlTOPp->top__DOT__cpu__DOT__ex_port_a 
			       << vlTOPp->top__DOT__cpu__DOT__ex_port_b)
			    : 0U) : (vlTOPp->top__DOT__cpu__DOT__ex_port_a 
				     ^ vlTOPp->top__DOT__cpu__DOT__ex_port_b)))
	        : ((2U & (IData)(vlTOPp->top__DOT__cpu__DOT__ex_alu_op))
		    ? ((1U & (IData)(vlTOPp->top__DOT__cpu__DOT__ex_alu_op))
		        ? (vlTOPp->top__DOT__cpu__DOT__ex_port_a 
			   | vlTOPp->top__DOT__cpu__DOT__ex_port_b)
		        : (vlTOPp->top__DOT__cpu__DOT__ex_port_a 
			   & vlTOPp->top__DOT__cpu__DOT__ex_port_b))
		    : ((1U & (IData)(vlTOPp->top__DOT__cpu__DOT__ex_alu_op))
		        ? (vlTOPp->top__DOT__cpu__DOT__ex_port_a 
			   - vlTOPp->top__DOT__cpu__DOT__ex_port_b)
		        : (vlTOPp->top__DOT__cpu__DOT__ex_port_a 
			   + vlTOPp->top__DOT__cpu__DOT__ex_port_b)))));
    vlTOPp->top__DOT__cpu__DOT__FWD__DOT__ex_fwd_b 
	= (((IData)(vlTOPp->top__DOT__cpu__DOT__ex_waddr) 
	    == (0x1fU & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			 >> 0x14U))) & (IData)(vlTOPp->top__DOT__cpu__DOT__ex_we));
    // ALWAYS at hardware/titan_dc_unit.v:92
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__lui 
	= (0x37U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__auipc 
	= (0x17U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__jal 
	= (0x6fU == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__jalr 
	= (0x67U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__beq 
	= ((0x63U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	   & (0U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__bne 
	= ((0x63U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	   & (1U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__blt 
	= ((0x63U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	   & (4U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__bge 
	= ((0x63U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	   & (5U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__bltu 
	= ((0x63U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	   & (6U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__bgeu 
	= ((0x63U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	   & (7U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__lb 
	= ((3U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	   & (0U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__lh 
	= ((3U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	   & (1U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__lw 
	= ((3U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	   & (2U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__lbu 
	= ((3U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	   & (4U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__lhu 
	= ((3U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	   & (5U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sb 
	= ((0x23U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	   & (0U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sh 
	= ((0x23U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	   & (1U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sw 
	= ((0x23U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	   & (2U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__addi 
	= ((0x13U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	   & (0U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__slti 
	= ((0x13U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	   & (2U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sltiu 
	= ((0x13U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	   & (3U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__xori 
	= ((0x13U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	   & (4U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__ori 
	= ((0x13U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	   & (6U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__andi 
	= ((0x13U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	   & (7U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__slli 
	= (((0x13U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	    & (1U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			    >> 0xcU)))) & (0U == (0x7fU 
						  & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
						     >> 0x19U))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__srli 
	= (((0x13U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	    & (5U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			    >> 0xcU)))) & (0U == (0x7fU 
						  & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
						     >> 0x19U))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__srai 
	= (((0x13U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	    & (5U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			    >> 0xcU)))) & (0x20U == 
					   (0x7fU & 
					    (vlTOPp->top__DOT__cpu__DOT__id_instruction 
					     >> 0x19U))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__add 
	= (((0x33U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	    & (0U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			    >> 0xcU)))) & (0U == (0x7fU 
						  & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
						     >> 0x19U))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sub 
	= (((0x33U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	    & (0U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			    >> 0xcU)))) & (0x20U == 
					   (0x7fU & 
					    (vlTOPp->top__DOT__cpu__DOT__id_instruction 
					     >> 0x19U))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__slt 
	= (((0x33U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	    & (2U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			    >> 0xcU)))) & (0U == (0x7fU 
						  & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
						     >> 0x19U))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sltu 
	= (((0x33U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	    & (3U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			    >> 0xcU)))) & (0U == (0x7fU 
						  & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
						     >> 0x19U))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT___xor 
	= (((0x33U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	    & (4U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			    >> 0xcU)))) & (0U == (0x7fU 
						  & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
						     >> 0x19U))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT___or 
	= (((0x33U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	    & (6U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			    >> 0xcU)))) & (0U == (0x7fU 
						  & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
						     >> 0x19U))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT___and 
	= (((0x33U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	    & (7U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			    >> 0xcU)))) & (0U == (0x7fU 
						  & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
						     >> 0x19U))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sll 
	= (((0x33U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	    & (1U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			    >> 0xcU)))) & (0U == (0x7fU 
						  & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
						     >> 0x19U))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__srl 
	= (((0x33U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	    & (5U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			    >> 0xcU)))) & (0U == (0x7fU 
						  & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
						     >> 0x19U))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sra 
	= (((0x33U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	    & (5U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			    >> 0xcU)))) & (0x20U == 
					   (0x7fU & 
					    (vlTOPp->top__DOT__cpu__DOT__id_instruction 
					     >> 0x19U))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__fence 
	= ((0xfU == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	   & (0U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__fencei 
	= ((0xfU == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	   & (1U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__rw 
	= ((0x73U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	   & (1U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__rs 
	= ((0x73U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	   & (2U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__rc 
	= ((0x73U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	   & (3U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__rwi 
	= ((0x73U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	   & (5U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__rsi 
	= ((0x73U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	   & (6U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__rci 
	= ((0x73U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	   & (7U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			   >> 0xcU))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__call 
	= ((0x73U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	   & (0U == (0x1ffffffU & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
				   >> 7U))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT___break 
	= ((0x73U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	   & (0x2000U == (0x1ffffffU & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
					>> 7U))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__xret 
	= (((0x73U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
	    & (0U == (3U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
			    >> 0x1eU)))) & (0x4000U 
					    == (0x1fffffU 
						& (vlTOPp->top__DOT__cpu__DOT__id_instruction 
						   >> 7U))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__uimp 
	= (0U == vlTOPp->top__DOT__cpu__DOT__id_instruction);
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_word 
	= ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__lw) 
	   | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sw));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_hw 
	= ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__lh) 
	   | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__lhu) 
	      | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sh)));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_byte 
	= ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__lb) 
	   | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__lbu) 
	      | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sb)));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_csri 
	= ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__rwi) 
	   | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__rsi) 
	      | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__rci)));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_ldu 
	= ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__lbu) 
	   | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__lhu));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_j 
	= ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__jal) 
	   | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__jalr));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_st 
	= ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sb) 
	   | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sh) 
	      | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sw)));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_b 
	= ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__beq) 
	   | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__bne) 
	      | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__blt) 
		 | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__bge) 
		    | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__bltu) 
		       | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__bgeu))))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_ld 
	= ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__lb) 
	   | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__lbu) 
	      | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__lh) 
		 | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__lhu) 
		    | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__lw)))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_imm 
	= ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__addi) 
	   | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__slti) 
	      | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sltiu) 
		 | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__ori) 
		    | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__andi) 
		       | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__slli) 
			  | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__srli) 
			     | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__srai) 
				| ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__xori) 
				   | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_ld) 
				      | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__jalr)))))))))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_add 
	= ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__add) 
	   | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__addi) 
	      | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_st) 
		 | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_ld) 
		    | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__lui) 
		       | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__auipc))))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_sub 
	= vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sub;
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_xor 
	= ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT___xor) 
	   | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__xori));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_and 
	= ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT___and) 
	   | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__andi));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_or 
	= ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT___or) 
	   | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__ori));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_sll 
	= ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sll) 
	   | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__slli));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_sr 
	= ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sra) 
	   | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__srl) 
	      | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__srai) 
		 | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__srli))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_slt 
	= ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__slt) 
	   | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__slti));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_sltu 
	= ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sltu) 
	   | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sltiu));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_alu 
	= ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__add) 
	   | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__addi) 
	      | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sub) 
		 | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_xor) 
		    | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_and) 
		       | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_or) 
			  | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_sll) 
			     | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_sr) 
				| ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_slt) 
				   | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_sltu))))))))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_csr 
	= ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__rw) 
	   | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__rs) 
	      | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__rc) 
		 | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_csri))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_immop 
	= ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__addi) 
	   | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__slli) 
	      | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__srai) 
		 | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__srli) 
		    | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__slti) 
		       | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sltiu) 
			  | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__ori) 
			     | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__andi) 
				| ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__xori) 
				   | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__jalr) 
				      | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_st) 
					 | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_ld) 
					    | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__lui) 
					       | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__auipc) 
						  | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_csri)))))))))))))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_wr 
	= ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_imm) 
	   | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_alu) 
	      | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_ld) 
		 | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__auipc) 
		    | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__lui) 
		       | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_csr))))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_fence 
	= ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__fence) 
	   | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__fencei));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__illegal 
	= (1U & (~ ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_j) 
		    | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_b) 
		       | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_add) 
			  | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_sub) 
			     | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_xor) 
				| ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_and) 
				   | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_or) 
				      | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_sll) 
					 | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_sr) 
					    | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_slt) 
					       | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_sltu) 
						  | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_csr) 
						     | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_fence) 
							| ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT___break) 
							   | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__call) 
							      | ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__xret) 
								 | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__uimp)))))))))))))))))));
    // ALWAYS at hardware/titan_csr_exception_unit.v:194
    vlTOPp->top__DOT__cpu__DOT__CSR__DOT__pend_int 
	= ((IData)(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mstatus_mie)
	    ? (vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mip 
	       & vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mie)
	    : 0U);
    vlTOPp->top__DOT__cpu__DOT__CSR__DOT__interrupt 
	= (1U & ((vlTOPp->top__DOT__cpu__DOT__CSR__DOT__pend_int 
		  >> 0xbU) | ((vlTOPp->top__DOT__cpu__DOT__CSR__DOT__pend_int 
			       >> 7U) | (vlTOPp->top__DOT__cpu__DOT__CSR__DOT__pend_int 
					 >> 3U))));
    // ALWAYS at tests/verilator/ram.v:74
    vlTOPp->top__DOT__dwbm_ack = (((IData)(vlTOPp->top__DOT__dwbm_cyc) 
				   & (IData)(vlTOPp->top__DOT__dwbm_stb)) 
				  & (0x80U == (0xffU 
					       & (vlTOPp->top__DOT__cpu__DOT__mem_result 
						  >> 0x18U))));
    // ALWAYS at hardware/titan_csr_exception_unit.v:121
    vlTOPp->top__DOT__cpu__DOT__CSR__DOT__exception_code 
	= ((IData)(vlTOPp->top__DOT__cpu__DOT__wb_inst_addr_misaligned)
	    ? 0U : ((IData)(vlTOPp->top__DOT__cpu__DOT__wb_inst_access_fault)
		     ? 1U : ((IData)(vlTOPp->top__DOT__cpu__DOT__wb_illegal_inst)
			      ? 2U : ((IData)(vlTOPp->top__DOT__cpu__DOT__wb_syscall_op)
				       ? 0xbU : ((IData)(vlTOPp->top__DOT__cpu__DOT__wb_break_op)
						  ? 3U
						  : 
						 ((IData)(vlTOPp->top__DOT__cpu__DOT__wb_load_access_fault)
						   ? 5U
						   : 
						  ((IData)(vlTOPp->top__DOT__cpu__DOT__wb_load_addr_misaligned)
						    ? 4U
						    : 
						   ((IData)(vlTOPp->top__DOT__cpu__DOT__wb_store_access_fault)
						     ? 7U
						     : 
						    ((IData)(vlTOPp->top__DOT__cpu__DOT__wb_store_addr_misaligned)
						      ? 6U
						      : 0U)))))))));
    vlTOPp->top__DOT__cpu__DOT__exception_stall_req 
	= ((IData)(vlTOPp->top__DOT__cpu__DOT__wb_syscall_op) 
	   | (IData)(vlTOPp->top__DOT__cpu__DOT__wb_xret_op));
    // ALWAYS at hardware/titan_csr_exception_unit.v:334
    vlTOPp->top__DOT__cpu__DOT__csr_data_o = ((((((
						   (((0x301U 
						      == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr)) 
						     | (0xf14U 
							== (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))) 
						    | ((0xf11U 
							== (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr)) 
						       | ((0xf12U 
							   == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr)) 
							  | (0xf14U 
							     == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))))) 
						   | (0x300U 
						      == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))) 
						  | (0x304U 
						     == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))) 
						 | (0x305U 
						    == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))) 
						| (0x340U 
						   == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))) 
					       | (0x341U 
						  == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr)))
					       ? ((0x301U 
						   == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))
						   ? 0x40000080U
						   : 
						  ((0xf14U 
						    == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))
						    ? 0U
						    : 
						   (((0xf11U 
						      == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr)) 
						     | ((0xf12U 
							 == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr)) 
							| (0xf14U 
							   == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))))
						     ? 0U
						     : 
						    ((0x300U 
						      == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))
						      ? vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mstatus
						      : 
						     ((0x304U 
						       == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))
						       ? vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mie
						       : 
						      ((0x305U 
							== (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))
						        ? vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mtvec
						        : 
						       ((0x340U 
							 == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))
							 ? vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mscratch
							 : vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mepc)))))))
					       : ((0x342U 
						   == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))
						   ? vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mcause
						   : 
						  ((0x343U 
						    == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))
						    ? vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mtval
						    : 
						   ((0x344U 
						     == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))
						     ? vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mip
						     : 
						    (((0xb00U 
						       == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr)) 
						      | (0xb80U 
							 == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr)))
						      ? 
						     ((0xb00U 
						       == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))
						       ? (IData)(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mcycle)
						       : (IData)(
								 (vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mcycle 
								  >> 0x20U)))
						      : 
						     (((0xb02U 
							== (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr)) 
						       | (0xb82U 
							  == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr)))
						       ? 
						      ((0xb02U 
							== (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))
						        ? (IData)(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__minstret)
						        : (IData)(
								  (vlTOPp->top__DOT__cpu__DOT__CSR__DOT__minstret 
								   >> 0x20U)))
						       : 0U))))));
    // ALWAYS at hardware/titan_lsu.v:151
    if ((8U & (IData)(vlTOPp->top__DOT__cpu__DOT__mem_mem_flags))) {
	vlTOPp->top__DOT__cpu__DOT__LSU__DOT__wsel_o = 0xfU;
    } else {
	if ((4U & (IData)(vlTOPp->top__DOT__cpu__DOT__mem_mem_flags))) {
	    vlTOPp->top__DOT__cpu__DOT__LSU__DOT__wsel_o = 3U;
	} else {
	    if ((2U & (IData)(vlTOPp->top__DOT__cpu__DOT__mem_mem_flags))) {
		vlTOPp->top__DOT__cpu__DOT__LSU__DOT__wsel_o = 1U;
	    }
	}
    }
    // ALWAYS at tests/verilator/ram.v:74
    vlTOPp->top__DOT__dwbm_dat_i = 0xffffffffU;
    if (((IData)(vlTOPp->top__DOT__dwbm_we) & (0x80U 
					       == (0xffU 
						   & (vlTOPp->top__DOT__cpu__DOT__mem_result 
						      >> 0x18U))))) {
	if ((1U & (IData)(vlTOPp->top__DOT__dwbm_sel))) {
	    vlTOPp->top__DOT__memory__DOT__mem[(0xfffffcU 
						& vlTOPp->top__DOT__cpu__DOT__mem_result)] 
		= (0xffU & vlTOPp->top__DOT__dwbm_dat_o);
	}
	if ((2U & (IData)(vlTOPp->top__DOT__dwbm_sel))) {
	    vlTOPp->top__DOT__memory__DOT__mem[(0xffffffU 
						& ((IData)(1U) 
						   + 
						   (0xfffffcU 
						    & vlTOPp->top__DOT__cpu__DOT__mem_result)))] 
		= (0xffU & (vlTOPp->top__DOT__dwbm_dat_o 
			    >> 8U));
	}
	if ((4U & (IData)(vlTOPp->top__DOT__dwbm_sel))) {
	    vlTOPp->top__DOT__memory__DOT__mem[(0xffffffU 
						& ((IData)(2U) 
						   + 
						   (0xfffffcU 
						    & vlTOPp->top__DOT__cpu__DOT__mem_result)))] 
		= (0xffU & (vlTOPp->top__DOT__dwbm_dat_o 
			    >> 0x10U));
	}
	if ((8U & (IData)(vlTOPp->top__DOT__dwbm_sel))) {
	    vlTOPp->top__DOT__memory__DOT__mem[(0xffffffU 
						& ((IData)(3U) 
						   + 
						   (0xfffffcU 
						    & vlTOPp->top__DOT__cpu__DOT__mem_result)))] 
		= (0xffU & (vlTOPp->top__DOT__dwbm_dat_o 
			    >> 0x18U));
	}
    } else {
	vlTOPp->top__DOT__dwbm_dat_i = ((0xffffff00U 
					 & vlTOPp->top__DOT__dwbm_dat_i) 
					| vlTOPp->top__DOT__memory__DOT__mem
					[(0xfffffcU 
					  & vlTOPp->top__DOT__cpu__DOT__mem_result)]);
	vlTOPp->top__DOT__dwbm_dat_i = ((0xffff00ffU 
					 & vlTOPp->top__DOT__dwbm_dat_i) 
					| (vlTOPp->top__DOT__memory__DOT__mem
					   [(0xffffffU 
					     & ((IData)(1U) 
						+ (0xfffffcU 
						   & vlTOPp->top__DOT__cpu__DOT__mem_result)))] 
					   << 8U));
	vlTOPp->top__DOT__dwbm_dat_i = ((0xff00ffffU 
					 & vlTOPp->top__DOT__dwbm_dat_i) 
					| (vlTOPp->top__DOT__memory__DOT__mem
					   [(0xffffffU 
					     & ((IData)(2U) 
						+ (0xfffffcU 
						   & vlTOPp->top__DOT__cpu__DOT__mem_result)))] 
					   << 0x10U));
	vlTOPp->top__DOT__dwbm_dat_i = ((0xffffffU 
					 & vlTOPp->top__DOT__dwbm_dat_i) 
					| (vlTOPp->top__DOT__memory__DOT__mem
					   [(0xffffffU 
					     & ((IData)(3U) 
						+ (0xfffffcU 
						   & vlTOPp->top__DOT__cpu__DOT__mem_result)))] 
					   << 0x18U));
    }
    // ALWAYS at hardware/titan_lsu.v:159
    if ((0x10U & (IData)(vlTOPp->top__DOT__cpu__DOT__mem_mem_flags))) {
	if ((8U & (IData)(vlTOPp->top__DOT__cpu__DOT__mem_mem_flags))) {
	    vlTOPp->top__DOT__cpu__DOT__LSU__DOT__rsel_o = 0xfU;
	} else {
	    if ((4U & (IData)(vlTOPp->top__DOT__cpu__DOT__mem_mem_flags))) {
		vlTOPp->top__DOT__cpu__DOT__LSU__DOT__rsel_o = 3U;
	    } else {
		if ((2U & (IData)(vlTOPp->top__DOT__cpu__DOT__mem_mem_flags))) {
		    vlTOPp->top__DOT__cpu__DOT__LSU__DOT__rsel_o = 1U;
		}
	    }
	}
	vlTOPp->top__DOT__cpu__DOT__LSU__DOT__runsigned 
	    = (1U & (IData)(vlTOPp->top__DOT__cpu__DOT__mem_mem_flags));
    }
    // ALWAYS at hardware/titan_forwarding_unit.v:42
    vlTOPp->top__DOT__cpu__DOT__forward_b_sel = ((IData)(vlTOPp->top__DOT__cpu__DOT__FWD__DOT__ex_fwd_b)
						  ? 
						 ((IData)(vlTOPp->top__DOT__cpu__DOT__ex_we)
						   ? 1U
						   : 0U)
						  : 
						 ((((IData)(vlTOPp->top__DOT__cpu__DOT__mem_waddr) 
						    == 
						    (0x1fU 
						     & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
							>> 0x14U))) 
						   & (IData)(vlTOPp->top__DOT__cpu__DOT__mem_we))
						   ? 
						  ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_we)
						    ? 2U
						    : 0U)
						   : 
						  ((((IData)(vlTOPp->top__DOT__cpu__DOT__wb_waddr) 
						     == 
						     (0x1fU 
						      & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
							 >> 0x14U))) 
						    & (IData)(vlTOPp->top__DOT__cpu__DOT__wb_we))
						    ? 
						   ((IData)(vlTOPp->top__DOT__cpu__DOT__wb_we)
						     ? 3U
						     : 0U)
						    : 0U)));
    // ALWAYS at hardware/titan_dc_unit.v:184
    if (((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__lui) 
	 | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__auipc))) {
	vlTOPp->top__DOT__cpu__DOT__ID__DOT__imm = 
	    (0xfffff000U & vlTOPp->top__DOT__cpu__DOT__id_instruction);
    } else {
	if (vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__jal) {
	    vlTOPp->top__DOT__cpu__DOT__ID__DOT__imm 
		= ((((0x80000000U & vlTOPp->top__DOT__cpu__DOT__id_instruction)
		      ? 0xfffU : 0U) << 0x14U) | ((0x80000U 
						   & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
						      >> 0xcU)) 
						  | ((0x7f800U 
						      & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
							 >> 1U)) 
						     | ((0x400U 
							 & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
							    >> 0xaU)) 
							| (0x3ffU 
							   & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
							      >> 0x15U))))));
	} else {
	    if (vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_b) {
		vlTOPp->top__DOT__cpu__DOT__ID__DOT__imm 
		    = ((((0x80000000U & vlTOPp->top__DOT__cpu__DOT__id_instruction)
			  ? 0xfffffU : 0U) << 0xcU) 
		       | ((0x800U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
				     >> 0x14U)) | (
						   (0x400U 
						    & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
						       << 3U)) 
						   | ((0x3f0U 
						       & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
							  >> 0x15U)) 
						      | (0xfU 
							 & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
							    >> 8U))))));
	    } else {
		if (vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_imm) {
		    vlTOPp->top__DOT__cpu__DOT__ID__DOT__imm 
			= ((((0x80000000U & vlTOPp->top__DOT__cpu__DOT__id_instruction)
			      ? 0xfffffU : 0U) << 0xcU) 
			   | (0xfffU & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
					>> 0x14U)));
		} else {
		    if (vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_st) {
			vlTOPp->top__DOT__cpu__DOT__ID__DOT__imm 
			    = ((((0x80000000U & vlTOPp->top__DOT__cpu__DOT__id_instruction)
				  ? 0xfffffU : 0U) 
				<< 0xcU) | ((0xfe0U 
					     & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
						>> 0x14U)) 
					    | (0x1fU 
					       & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
						  >> 7U))));
		    } else {
			if (vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_csri) {
			    vlTOPp->top__DOT__cpu__DOT__ID__DOT__imm 
				= (0x1fU & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
					    >> 0xfU));
			}
		    }
		}
	    }
	}
    }
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__waddr = (0x1fU 
						  & ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_st)
						      ? 0U
						      : 
						     (vlTOPp->top__DOT__cpu__DOT__id_instruction 
						      >> 7U)));
    // ALWAYS at hardware/titan_dc_unit.v:204
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__comparator_op 
	= ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__beq)
	    ? 1U : ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__bne)
		     ? 2U : ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__blt)
			      ? 3U : ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__bge)
				       ? 4U : ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__bltu)
					        ? 5U
					        : ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__bgeu)
						    ? 6U
						    : 0U))))));
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__rs1 = (0x1fU 
						& ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__lui)
						    ? 0U
						    : 
						   (vlTOPp->top__DOT__cpu__DOT__id_instruction 
						    >> 0xfU)));
    // ALWAYS at hardware/titan_csr_exception_unit.v:173
    if (vlTOPp->top__DOT__cpu__DOT__CSR__DOT__interrupt) {
	if ((0x800U & vlTOPp->top__DOT__cpu__DOT__CSR__DOT__pend_int)) {
	    vlTOPp->top__DOT__cpu__DOT__CSR__DOT__exception_code = 3U;
	} else {
	    if ((0x80U & vlTOPp->top__DOT__cpu__DOT__CSR__DOT__pend_int)) {
		vlTOPp->top__DOT__cpu__DOT__CSR__DOT__exception_code = 7U;
	    } else {
		if ((8U & vlTOPp->top__DOT__cpu__DOT__CSR__DOT__pend_int)) {
		    vlTOPp->top__DOT__cpu__DOT__CSR__DOT__exception_code = 0xbU;
		}
	    }
	}
    }
    vlTOPp->top__DOT__cpu__DOT__mem_stall_req = (1U 
						 & ((((IData)(vlTOPp->top__DOT__cpu__DOT__mem_mem_flags) 
						      >> 4U) 
						     ^ 
						     ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_mem_flags) 
						      >> 5U)) 
						    & (~ (IData)(vlTOPp->top__DOT__dwbm_ack))));
    vlTOPp->top__DOT__cpu__DOT__id_flush = ((IData)(vlTOPp->rst_i) 
					    | (IData)(vlTOPp->top__DOT__cpu__DOT__exception_stall_req));
    vlTOPp->top__DOT__cpu__DOT__mem_flush = ((IData)(vlTOPp->rst_i) 
					     | (IData)(vlTOPp->top__DOT__cpu__DOT__exception_stall_req));
    // ALWAYS at hardware/titan_csr_exception_unit.v:222
    vlTOPp->top__DOT__cpu__DOT__CSR__DOT__csr_wdata 
	= ((1U == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_op))
	    ? vlTOPp->top__DOT__cpu__DOT__wb_csr_data
	    : ((2U == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_op))
	        ? (vlTOPp->top__DOT__cpu__DOT__csr_data_o 
		   | vlTOPp->top__DOT__cpu__DOT__wb_csr_data)
	        : ((4U == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_op))
		    ? (vlTOPp->top__DOT__cpu__DOT__csr_data_o 
		       & (~ vlTOPp->top__DOT__cpu__DOT__wb_csr_data))
		    : 0U)));
    // ALWAYS at hardware/titan_mux21.v:9
    if ((0U != (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_op))) {
	if ((0U != (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_op))) {
	    vlTOPp->top__DOT__cpu__DOT__wb_result = vlTOPp->top__DOT__cpu__DOT__csr_data_o;
	}
    } else {
	vlTOPp->top__DOT__cpu__DOT__wb_result = vlTOPp->top__DOT__cpu__DOT__wb_result_mem;
    }
    // ALWAYS at tests/verilator/ram.v:60
    vlTOPp->top__DOT__iwbm_dat = 0xffffffffU;
    if ((0x80U == (0xffU & (vlTOPp->top__DOT__cpu__DOT__if_pc 
			    >> 0x18U)))) {
	vlTOPp->top__DOT__iwbm_dat = ((0xffffff00U 
				       & vlTOPp->top__DOT__iwbm_dat) 
				      | vlTOPp->top__DOT__memory__DOT__mem
				      [(0xfffffcU & vlTOPp->top__DOT__cpu__DOT__if_pc)]);
	vlTOPp->top__DOT__iwbm_dat = ((0xffff00ffU 
				       & vlTOPp->top__DOT__iwbm_dat) 
				      | (vlTOPp->top__DOT__memory__DOT__mem
					 [(0xffffffU 
					   & ((IData)(1U) 
					      + (0xfffffcU 
						 & vlTOPp->top__DOT__cpu__DOT__if_pc)))] 
					 << 8U));
	vlTOPp->top__DOT__iwbm_dat = ((0xff00ffffU 
				       & vlTOPp->top__DOT__iwbm_dat) 
				      | (vlTOPp->top__DOT__memory__DOT__mem
					 [(0xffffffU 
					   & ((IData)(2U) 
					      + (0xfffffcU 
						 & vlTOPp->top__DOT__cpu__DOT__if_pc)))] 
					 << 0x10U));
	vlTOPp->top__DOT__iwbm_dat = ((0xffffffU & vlTOPp->top__DOT__iwbm_dat) 
				      | (vlTOPp->top__DOT__memory__DOT__mem
					 [(0xffffffU 
					   & ((IData)(3U) 
					      + (0xfffffcU 
						 & vlTOPp->top__DOT__cpu__DOT__if_pc)))] 
					 << 0x18U));
    }
    // ALWAYS at hardware/titan_lsu.v:171
    if ((0x10U & (IData)(vlTOPp->top__DOT__cpu__DOT__mem_mem_flags))) {
	vlTOPp->top__DOT__cpu__DOT__mem_load_data = 
	    ((1U == (IData)(vlTOPp->top__DOT__cpu__DOT__LSU__DOT__rsel_o))
	      ? ((0xffffff00U & (((IData)(vlTOPp->top__DOT__cpu__DOT__LSU__DOT__runsigned)
				   ? 0U : VL_NEGATE_I((IData)(
							      (1U 
							       & (vlTOPp->top__DOT__dwbm_dat_i 
								  >> 7U))))) 
				 << 8U)) | (0xffU & vlTOPp->top__DOT__dwbm_dat_i))
	      : ((3U == (IData)(vlTOPp->top__DOT__cpu__DOT__LSU__DOT__rsel_o))
		  ? ((0xffff0000U & (((IData)(vlTOPp->top__DOT__cpu__DOT__LSU__DOT__runsigned)
				       ? 0U : VL_NEGATE_I((IData)(
								  (1U 
								   & (vlTOPp->top__DOT__dwbm_dat_i 
								      >> 0xfU))))) 
				     << 0x10U)) | (0xffffU 
						   & vlTOPp->top__DOT__dwbm_dat_i))
		  : vlTOPp->top__DOT__dwbm_dat_i));
    } else {
	if ((0x20U & (IData)(vlTOPp->top__DOT__cpu__DOT__mem_mem_flags))) {
	    vlTOPp->top__DOT__cpu__DOT__LSU__DOT__wdata 
		= ((1U == (IData)(vlTOPp->top__DOT__cpu__DOT__LSU__DOT__wsel_o))
		    ? (0xffU & vlTOPp->top__DOT__cpu__DOT__mem_store_data)
		    : ((3U == (IData)(vlTOPp->top__DOT__cpu__DOT__LSU__DOT__wsel_o))
		        ? (0xffffU & vlTOPp->top__DOT__cpu__DOT__mem_store_data)
		        : vlTOPp->top__DOT__cpu__DOT__mem_store_data));
	}
    }
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__drs1 = ((0U 
						  == (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__rs1))
						  ? 0U
						  : 
						 vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file
						 [vlTOPp->top__DOT__cpu__DOT__ID__DOT__rs1]);
    vlTOPp->top__DOT__cpu__DOT__FWD__DOT__ex_fwd_a 
	= (((~ (IData)(vlTOPp->top__DOT__cpu__DOT__ex_mem_ex_sel)) 
	    & ((IData)(vlTOPp->top__DOT__cpu__DOT__ex_waddr) 
	       == (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__rs1))) 
	   & (IData)(vlTOPp->top__DOT__cpu__DOT__ex_we));
    // ALWAYS at hardware/titan_csr_exception_unit.v:161
    if (((0U != (IData)(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__exception_code)) 
	 | (IData)(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__interrupt))) {
	vlTOPp->top__DOT__cpu__DOT__CSR__DOT__trap_valid = 1U;
	vlTOPp->top__DOT__cpu__DOT__exception_pc = vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mtvec;
    } else {
	if (vlTOPp->top__DOT__cpu__DOT__wb_xret_op) {
	    vlTOPp->top__DOT__cpu__DOT__exception_pc 
		= vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mepc;
	    vlTOPp->top__DOT__cpu__DOT__CSR__DOT__trap_valid = 0U;
	} else {
	    vlTOPp->top__DOT__cpu__DOT__CSR__DOT__trap_valid = 0U;
	}
    }
    // ALWAYS at hardware/titan_mem_stage.v:90
    if (vlTOPp->top__DOT__cpu__DOT__mem_mem_ex_sel) {
	if (vlTOPp->top__DOT__cpu__DOT__mem_mem_ex_sel) {
	    vlTOPp->top__DOT__cpu__DOT__MEM__DOT__mem_result 
		= vlTOPp->top__DOT__cpu__DOT__mem_load_data;
	}
    } else {
	vlTOPp->top__DOT__cpu__DOT__MEM__DOT__mem_result 
	    = vlTOPp->top__DOT__cpu__DOT__mem_result;
    }
    vlTOPp->top__DOT__cpu__DOT__ID__DOT___imm = ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__jalr)
						  ? 
						 ((vlTOPp->top__DOT__cpu__DOT__ID__DOT__imm 
						   << 1U) 
						  + vlTOPp->top__DOT__cpu__DOT__ID__DOT__drs1)
						  : 
						 (vlTOPp->top__DOT__cpu__DOT__ID__DOT__imm 
						  << 1U));
    vlTOPp->top__DOT__cpu__DOT__ld_dependence = ((((IData)(vlTOPp->top__DOT__cpu__DOT__FWD__DOT__ex_fwd_a) 
						   | (IData)(vlTOPp->top__DOT__cpu__DOT__FWD__DOT__ex_fwd_b)) 
						  & (IData)(vlTOPp->top__DOT__cpu__DOT__ex_mem_ex_sel)) 
						 & (IData)(vlTOPp->top__DOT__cpu__DOT__mem_we));
    // ALWAYS at hardware/titan_forwarding_unit.v:33
    vlTOPp->top__DOT__cpu__DOT__forward_a_sel = ((IData)(vlTOPp->top__DOT__cpu__DOT__FWD__DOT__ex_fwd_a)
						  ? 1U
						  : 
						 ((((IData)(vlTOPp->top__DOT__cpu__DOT__mem_waddr) 
						    == (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__rs1)) 
						   & (IData)(vlTOPp->top__DOT__cpu__DOT__mem_we))
						   ? 2U
						   : 
						  ((((IData)(vlTOPp->top__DOT__cpu__DOT__wb_waddr) 
						     == (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__rs1)) 
						    & (IData)(vlTOPp->top__DOT__cpu__DOT__wb_we))
						    ? 3U
						    : 0U)));
    // ALWAYS at hardware/titan_mux41.v:11
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__muxb_i = (
						   (2U 
						    & (IData)(vlTOPp->top__DOT__cpu__DOT__forward_b_sel))
						    ? 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__cpu__DOT__forward_b_sel))
						     ? vlTOPp->top__DOT__cpu__DOT__wb_result
						     : vlTOPp->top__DOT__cpu__DOT__MEM__DOT__mem_result)
						    : 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__cpu__DOT__forward_b_sel))
						     ? vlTOPp->top__DOT__cpu__DOT__EX__DOT__ex_result
						     : 
						    ((0U 
						      == 
						      (0x1fU 
						       & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
							  >> 0x14U)))
						      ? 0U
						      : 
						     vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file
						     [
						     (0x1fU 
						      & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
							 >> 0x14U))])));
    vlTOPp->top__DOT__cpu__DOT____Vcellinp__EX__ex_flush_i 
	= (((IData)(vlTOPp->rst_i) | (IData)(vlTOPp->top__DOT__cpu__DOT__exception_stall_req)) 
	   | (IData)(vlTOPp->top__DOT__cpu__DOT__ld_dependence));
    // ALWAYS at hardware/titan_mux41.v:11
    vlTOPp->top__DOT__cpu__DOT__ID__DOT__muxa_i = (
						   (2U 
						    & (IData)(vlTOPp->top__DOT__cpu__DOT__forward_a_sel))
						    ? 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__cpu__DOT__forward_a_sel))
						     ? vlTOPp->top__DOT__cpu__DOT__wb_result
						     : vlTOPp->top__DOT__cpu__DOT__MEM__DOT__mem_result)
						    : 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__cpu__DOT__forward_a_sel))
						     ? vlTOPp->top__DOT__cpu__DOT__EX__DOT__ex_result
						     : vlTOPp->top__DOT__cpu__DOT__ID__DOT__drs1));
    // ALWAYS at hardware/titan_mux21.v:9
    if (vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_immop) {
	if (vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_immop) {
	    vlTOPp->top__DOT__cpu__DOT__ID__DOT__port_b 
		= vlTOPp->top__DOT__cpu__DOT__ID__DOT__imm;
	}
    } else {
	vlTOPp->top__DOT__cpu__DOT__ID__DOT__port_b 
	    = vlTOPp->top__DOT__cpu__DOT__ID__DOT__muxb_i;
    }
    // ALWAYS at hardware/titan_mux21.v:9
    if (vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__auipc) {
	if (vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__auipc) {
	    vlTOPp->top__DOT__cpu__DOT__ID__DOT__port_a 
		= vlTOPp->top__DOT__cpu__DOT__id_pc;
	}
    } else {
	vlTOPp->top__DOT__cpu__DOT__ID__DOT__port_a 
	    = vlTOPp->top__DOT__cpu__DOT__ID__DOT__muxa_i;
    }
    vlTOPp->top__DOT__cpu__DOT__take_branch = ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_b) 
					       & ((4U 
						   & (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__comparator_op))
						   ? 
						  ((2U 
						    & (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__comparator_op))
						    ? 
						   ((~ (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__comparator_op)) 
						    & (vlTOPp->top__DOT__cpu__DOT__ID__DOT__muxa_i 
						       >= vlTOPp->top__DOT__cpu__DOT__ID__DOT__muxb_i))
						    : 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__comparator_op))
						     ? 
						    (vlTOPp->top__DOT__cpu__DOT__ID__DOT__muxa_i 
						     < vlTOPp->top__DOT__cpu__DOT__ID__DOT__muxb_i)
						     : 
						    VL_GTES_III(1,32,32, vlTOPp->top__DOT__cpu__DOT__ID__DOT__muxa_i, vlTOPp->top__DOT__cpu__DOT__ID__DOT__muxb_i)))
						   : 
						  ((2U 
						    & (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__comparator_op))
						    ? 
						   ((1U 
						     & (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__comparator_op))
						     ? 
						    VL_LTS_III(1,32,32, vlTOPp->top__DOT__cpu__DOT__ID__DOT__muxa_i, vlTOPp->top__DOT__cpu__DOT__ID__DOT__muxb_i)
						     : 
						    (vlTOPp->top__DOT__cpu__DOT__ID__DOT__muxa_i 
						     != vlTOPp->top__DOT__cpu__DOT__ID__DOT__muxb_i))
						    : 
						   ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__comparator_op) 
						    & (vlTOPp->top__DOT__cpu__DOT__ID__DOT__muxa_i 
						       == vlTOPp->top__DOT__cpu__DOT__ID__DOT__muxb_i)))));
    // ALWAYS at hardware/titan_control_unit.v:39
    vlTOPp->top__DOT__cpu__DOT__if_pc_sel = ((IData)(vlTOPp->top__DOT__cpu__DOT__take_branch)
					      ? 1U : 
					     ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_j)
					       ? 2U
					       : ((IData)(vlTOPp->top__DOT__cpu__DOT__exception_stall_req)
						   ? 3U
						   : 0U)));
    vlTOPp->top__DOT__cpu__DOT__if_kill = ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_j) 
					   | (IData)(vlTOPp->top__DOT__cpu__DOT__take_branch));
    // ALWAYS at hardware/titan_pc_source.v:10
    vlTOPp->top__DOT__cpu__DOT__IF__DOT__if_pc_mux 
	= ((2U & (IData)(vlTOPp->top__DOT__cpu__DOT__if_pc_sel))
	    ? ((1U & (IData)(vlTOPp->top__DOT__cpu__DOT__if_pc_sel))
	        ? vlTOPp->top__DOT__cpu__DOT__exception_pc
	        : (0xfffffffeU & (vlTOPp->top__DOT__cpu__DOT__id_pc 
				  + vlTOPp->top__DOT__cpu__DOT__ID__DOT___imm)))
	    : ((1U & (IData)(vlTOPp->top__DOT__cpu__DOT__if_pc_sel))
	        ? (vlTOPp->top__DOT__cpu__DOT__ID__DOT___imm 
		   + vlTOPp->top__DOT__cpu__DOT__id_pc)
	        : ((IData)(4U) + vlTOPp->top__DOT__cpu__DOT__if_pc)));
    vlTOPp->top__DOT__cpu__DOT__if_flush = ((IData)(vlTOPp->rst_i) 
					    | ((IData)(vlTOPp->top__DOT__cpu__DOT__if_kill) 
					       | (IData)(vlTOPp->top__DOT__cpu__DOT__exception_stall_req)));
    vlTOPp->top__DOT__cpu__DOT____Vcellinp__IF__if_stall 
	= (1U & ((((((~ (IData)(vlTOPp->rst_i)) & (~ (IData)(vlTOPp->top__DOT__iwbm_ack))) 
		    | (IData)(vlTOPp->top__DOT__cpu__DOT__LSU__DOT__kill)) 
		   | (IData)(vlTOPp->top__DOT__cpu__DOT__mem_stall_req)) 
		  | (IData)(vlTOPp->top__DOT__cpu__DOT__ld_dependence)) 
		 & (~ (IData)(vlTOPp->top__DOT__cpu__DOT__if_kill))));
}

VL_INLINE_OPT void Vtop::_combo__TOP__4(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_combo__TOP__4\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__cpu__DOT__id_flush = ((IData)(vlTOPp->rst_i) 
					    | (IData)(vlTOPp->top__DOT__cpu__DOT__exception_stall_req));
    vlTOPp->top__DOT__cpu__DOT__mem_flush = ((IData)(vlTOPp->rst_i) 
					     | (IData)(vlTOPp->top__DOT__cpu__DOT__exception_stall_req));
    vlTOPp->top__DOT__cpu__DOT____Vcellinp__EX__ex_flush_i 
	= (((IData)(vlTOPp->rst_i) | (IData)(vlTOPp->top__DOT__cpu__DOT__exception_stall_req)) 
	   | (IData)(vlTOPp->top__DOT__cpu__DOT__ld_dependence));
    vlTOPp->top__DOT__cpu__DOT__if_flush = ((IData)(vlTOPp->rst_i) 
					    | ((IData)(vlTOPp->top__DOT__cpu__DOT__if_kill) 
					       | (IData)(vlTOPp->top__DOT__cpu__DOT__exception_stall_req)));
    vlTOPp->top__DOT__cpu__DOT____Vcellinp__IF__if_stall 
	= (1U & ((((((~ (IData)(vlTOPp->rst_i)) & (~ (IData)(vlTOPp->top__DOT__iwbm_ack))) 
		    | (IData)(vlTOPp->top__DOT__cpu__DOT__LSU__DOT__kill)) 
		   | (IData)(vlTOPp->top__DOT__cpu__DOT__mem_stall_req)) 
		  | (IData)(vlTOPp->top__DOT__cpu__DOT__ld_dependence)) 
		 & (~ (IData)(vlTOPp->top__DOT__cpu__DOT__if_kill))));
}

void Vtop::_eval(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk_i) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk_i)))) {
	vlTOPp->_sequent__TOP__2(vlSymsp);
	vlTOPp->__Vm_traceActivity = (2U | vlTOPp->__Vm_traceActivity);
    }
    vlTOPp->_combo__TOP__4(vlSymsp);
    vlTOPp->__Vm_traceActivity = (4U | vlTOPp->__Vm_traceActivity);
    // Final
    vlTOPp->__Vclklast__TOP__clk_i = vlTOPp->clk_i;
}

void Vtop::_eval_initial(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_initial\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vm_traceActivity = (1U | vlTOPp->__Vm_traceActivity);
}

void Vtop::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::final\n"); );
    // Variables
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vtop::_eval_settle(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_settle\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__3(vlSymsp);
    vlTOPp->__Vm_traceActivity = (1U | vlTOPp->__Vm_traceActivity);
}

VL_INLINE_OPT QData Vtop::_change_request(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_change_request\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vtop::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk_i & 0xfeU))) {
	Verilated::overWidthError("clk_i");}
    if (VL_UNLIKELY((rst_i & 0xfeU))) {
	Verilated::overWidthError("rst_i");}
}
#endif // VL_DEBUG

void Vtop::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_ctor_var_reset\n"); );
    // Body
    clk_i = VL_RAND_RESET_I(1);
    rst_i = VL_RAND_RESET_I(1);
    top__DOT__dwbm_cyc = VL_RAND_RESET_I(1);
    top__DOT__dwbm_dat_o = VL_RAND_RESET_I(32);
    top__DOT__dwbm_dat_i = VL_RAND_RESET_I(32);
    top__DOT__dwbm_sel = VL_RAND_RESET_I(4);
    top__DOT__dwbm_stb = VL_RAND_RESET_I(1);
    top__DOT__dwbm_we = VL_RAND_RESET_I(1);
    top__DOT__iwbm_cyc = VL_RAND_RESET_I(1);
    top__DOT__iwbm_dat = VL_RAND_RESET_I(32);
    top__DOT__iwbm_stb = VL_RAND_RESET_I(1);
    top__DOT__iwbm_ack = VL_RAND_RESET_I(1);
    top__DOT__dwbm_ack = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__if_flush = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__if_pc = VL_RAND_RESET_I(32);
    top__DOT__cpu__DOT__if_pc_sel = VL_RAND_RESET_I(2);
    top__DOT__cpu__DOT__id_instruction = VL_RAND_RESET_I(32);
    top__DOT__cpu__DOT__id_pc = VL_RAND_RESET_I(32);
    top__DOT__cpu__DOT__wb_waddr = VL_RAND_RESET_I(5);
    top__DOT__cpu__DOT__wb_we = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__id_flush = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__forward_a_sel = VL_RAND_RESET_I(2);
    top__DOT__cpu__DOT__forward_b_sel = VL_RAND_RESET_I(2);
    top__DOT__cpu__DOT__id_inst_addr_misaligned = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__id_inst_access_fault = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ex_rs1 = VL_RAND_RESET_I(5);
    top__DOT__cpu__DOT__take_branch = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ex_pc = VL_RAND_RESET_I(32);
    top__DOT__cpu__DOT__ex_instruction = VL_RAND_RESET_I(32);
    top__DOT__cpu__DOT__ex_port_a = VL_RAND_RESET_I(32);
    top__DOT__cpu__DOT__ex_port_b = VL_RAND_RESET_I(32);
    top__DOT__cpu__DOT__ex_alu_op = VL_RAND_RESET_I(4);
    top__DOT__cpu__DOT__ex_waddr = VL_RAND_RESET_I(5);
    top__DOT__cpu__DOT__ex_we = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ex_mem_flags = VL_RAND_RESET_I(6);
    top__DOT__cpu__DOT__ex_mem_ex_sel = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ex_break_op = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ex_syscall_op = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ex_csr_op = VL_RAND_RESET_I(3);
    top__DOT__cpu__DOT__ex_csr_data = VL_RAND_RESET_I(32);
    top__DOT__cpu__DOT__ex_csr_addr = VL_RAND_RESET_I(12);
    top__DOT__cpu__DOT__ex_fence_op = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ex_xret_op = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ex_inst_addr_misaligned = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ex_inst_access_fault = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ex_illegal_inst = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ex_store_data = VL_RAND_RESET_I(32);
    top__DOT__cpu__DOT__mem_pc = VL_RAND_RESET_I(32);
    top__DOT__cpu__DOT__mem_instruction = VL_RAND_RESET_I(32);
    top__DOT__cpu__DOT__mem_result = VL_RAND_RESET_I(32);
    top__DOT__cpu__DOT__mem_waddr = VL_RAND_RESET_I(5);
    top__DOT__cpu__DOT__mem_rs1 = VL_RAND_RESET_I(5);
    top__DOT__cpu__DOT__mem_we = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__mem_mem_flags = VL_RAND_RESET_I(6);
    top__DOT__cpu__DOT__mem_mem_ex_sel = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__mem_csr_data = VL_RAND_RESET_I(32);
    top__DOT__cpu__DOT__mem_csr_op = VL_RAND_RESET_I(3);
    top__DOT__cpu__DOT__mem_csr_addr = VL_RAND_RESET_I(12);
    top__DOT__cpu__DOT__mem_break_op = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__mem_syscall_op = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__mem_flush = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__mem_store_data = VL_RAND_RESET_I(32);
    top__DOT__cpu__DOT__mem_load_data = VL_RAND_RESET_I(32);
    top__DOT__cpu__DOT__mem_fence_op = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__mem_xret_op = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__mem_inst_addr_misaligned = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__mem_inst_access_fault = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__mem_illegal_inst = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__wb_result_mem = VL_RAND_RESET_I(32);
    top__DOT__cpu__DOT__wb_pc = VL_RAND_RESET_I(32);
    top__DOT__cpu__DOT__wb_instruction = VL_RAND_RESET_I(32);
    top__DOT__cpu__DOT__wb_result = VL_RAND_RESET_I(32);
    top__DOT__cpu__DOT__wb_rs1 = VL_RAND_RESET_I(5);
    top__DOT__cpu__DOT__wb_csr_data = VL_RAND_RESET_I(32);
    top__DOT__cpu__DOT__wb_csr_addr = VL_RAND_RESET_I(12);
    top__DOT__cpu__DOT__wb_csr_op = VL_RAND_RESET_I(3);
    top__DOT__cpu__DOT__wb_break_op = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__wb_syscall_op = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__wb_fence_op = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__wb_xret_op = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__wb_inst_addr_misaligned = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__wb_inst_access_fault = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__wb_illegal_inst = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__wb_load_addr_misaligned = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__wb_store_addr_misaligned = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__wb_load_access_fault = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__wb_store_access_fault = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ld_dependence = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__mem_stall_req = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__if_kill = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__exception_pc = VL_RAND_RESET_I(32);
    top__DOT__cpu__DOT__exception_stall_req = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__exception_sel_flag = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__csr_data_o = VL_RAND_RESET_I(32);
    top__DOT__cpu__DOT____Vcellinp__IF__if_stall = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT____Vcellinp__EX__ex_flush_i = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__IF__DOT__if_pc_mux = VL_RAND_RESET_I(32);
    top__DOT__cpu__DOT__ID__DOT__muxa_i = VL_RAND_RESET_I(32);
    top__DOT__cpu__DOT__ID__DOT__muxb_i = VL_RAND_RESET_I(32);
    top__DOT__cpu__DOT__ID__DOT__rs1 = VL_RAND_RESET_I(5);
    top__DOT__cpu__DOT__ID__DOT__drs1 = VL_RAND_RESET_I(32);
    top__DOT__cpu__DOT__ID__DOT__comparator_op = VL_RAND_RESET_I(3);
    top__DOT__cpu__DOT__ID__DOT__imm = VL_RAND_RESET_I(32);
    top__DOT__cpu__DOT__ID__DOT___imm = VL_RAND_RESET_I(32);
    top__DOT__cpu__DOT__ID__DOT__waddr = VL_RAND_RESET_I(5);
    top__DOT__cpu__DOT__ID__DOT__port_a = VL_RAND_RESET_I(32);
    top__DOT__cpu__DOT__ID__DOT__port_b = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<32; ++__Vi0) {
	    top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[__Vi0] = VL_RAND_RESET_I(32);
    }}
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT__lui = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT__auipc = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT__jal = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT__jalr = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT__beq = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT__bne = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT__blt = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT__bge = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT__bltu = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT__bgeu = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT__lb = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT__lh = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT__lw = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT__lbu = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT__lhu = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sb = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sh = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sw = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT__addi = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT__slti = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sltiu = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT__xori = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT__ori = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT__andi = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT__slli = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT__srli = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT__srai = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT__add = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sub = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sll = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT__slt = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sltu = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT___xor = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT__srl = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sra = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT___or = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT___and = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT__fence = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT__fencei = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT__xret = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT__rw = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT__rs = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT__rc = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT__rwi = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT__rsi = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT__rci = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT__call = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT___break = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_b = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_imm = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_st = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_ld = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_add = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_sub = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_and = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_xor = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_or = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_sll = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_sr = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_slt = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_sltu = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_wr = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_alu = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_immop = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_ldu = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_j = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_csri = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_csr = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_fence = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_word = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_byte = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_hw = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT__illegal = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__ID__DOT__DCU__DOT__uimp = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__EX__DOT__ex_result = VL_RAND_RESET_I(32);
    top__DOT__cpu__DOT__MEM__DOT__mem_result = VL_RAND_RESET_I(32);
    top__DOT__cpu__DOT__FWD__DOT__ex_fwd_a = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__FWD__DOT__ex_fwd_b = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__LSU__DOT__wdata = VL_RAND_RESET_I(32);
    top__DOT__cpu__DOT__LSU__DOT__wsel_o = VL_RAND_RESET_I(4);
    top__DOT__cpu__DOT__LSU__DOT__rsel_o = VL_RAND_RESET_I(4);
    top__DOT__cpu__DOT__LSU__DOT__runsigned = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__LSU__DOT__i_state = VL_RAND_RESET_I(2);
    top__DOT__cpu__DOT__LSU__DOT__d_state = VL_RAND_RESET_I(2);
    top__DOT__cpu__DOT__LSU__DOT__kill = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__CSR__DOT__csr_wdata = VL_RAND_RESET_I(32);
    top__DOT__cpu__DOT__CSR__DOT__mstatus = VL_RAND_RESET_I(32);
    top__DOT__cpu__DOT__CSR__DOT__mie = VL_RAND_RESET_I(32);
    top__DOT__cpu__DOT__CSR__DOT__mtvec = VL_RAND_RESET_I(32);
    top__DOT__cpu__DOT__CSR__DOT__mscratch = VL_RAND_RESET_I(32);
    top__DOT__cpu__DOT__CSR__DOT__mepc = VL_RAND_RESET_I(32);
    top__DOT__cpu__DOT__CSR__DOT__mcause = VL_RAND_RESET_I(32);
    top__DOT__cpu__DOT__CSR__DOT__mtval = VL_RAND_RESET_I(32);
    top__DOT__cpu__DOT__CSR__DOT__mip = VL_RAND_RESET_I(32);
    top__DOT__cpu__DOT__CSR__DOT__mcycle = VL_RAND_RESET_Q(64);
    top__DOT__cpu__DOT__CSR__DOT__minstret = VL_RAND_RESET_Q(64);
    top__DOT__cpu__DOT__CSR__DOT__undef_register = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__CSR__DOT__mstatus_mpie = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__CSR__DOT__mstatus_mie = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__CSR__DOT__mie_meie = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__CSR__DOT__mie_mtie = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__CSR__DOT__mie_msie = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__CSR__DOT__pend_int = VL_RAND_RESET_I(32);
    top__DOT__cpu__DOT__CSR__DOT__interrupt = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__CSR__DOT__mcause_int = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__CSR__DOT__mcause_exc = VL_RAND_RESET_I(4);
    top__DOT__cpu__DOT__CSR__DOT__trap_valid = VL_RAND_RESET_I(1);
    top__DOT__cpu__DOT__CSR__DOT__exception_code = VL_RAND_RESET_I(4);
    top__DOT__cpu__DOT__CSR__DOT__exception_stall = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<16777216; ++__Vi0) {
	    top__DOT__memory__DOT__mem[__Vi0] = 0;
    }}
    __Vclklast__TOP__clk_i = VL_RAND_RESET_I(1);
    __Vm_traceActivity = VL_RAND_RESET_I(32);
}
