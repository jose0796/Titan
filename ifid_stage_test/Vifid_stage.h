// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _Vifid_stage_H_
#define _Vifid_stage_H_

#include "verilated.h"
class Vifid_stage__Syms;
class VerilatedVcd;

//----------

VL_MODULE(Vifid_stage) {
  public:
    // CELLS
    // Public to allow access to /*verilator_public*/ items;
    // otherwise the application code can consider these internals.
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk_i,0,0);
    VL_IN8(rst_i,0,0);
    VL_OUT8(ex_alu_op,3,0);
    VL_OUT8(ex_waddr,4,0);
    VL_OUT8(ex_we,0,0);
    VL_OUT8(ex_mem_flags,5,0);
    VL_OUT8(ex_mem_ex_sel,0,0);
    VL_OUT8(ex_jump_op,0,0);
    VL_OUT8(ex_bad_jump_addr,0,0);
    VL_OUT8(ex_branch_op,0,0);
    VL_OUT8(ex_bad_branch_addr,0,0);
    VL_OUT8(take_branch,0,0);
    VL_OUT8(ex_break_op,0,0);
    VL_OUT8(ex_syscall_op,0,0);
    VL_OUT8(ex_csr_op,2,0);
    VL_OUT8(ex_csr_imm_op,0,0);
    VL_OUT8(ex_exc_addr_if_o,0,0);
    VL_OUT8(ex_ready,0,0);
    //char	__VpadToAlign18[2];
    VL_OUT(ex_port_a,31,0);
    VL_OUT(ex_port_b,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    VL_SIG8(ifid_stage__DOT__IF__DOT__wbm_ack_i,0,0);
    VL_SIG8(ifid_stage__DOT__if_stall,0,0);
    VL_SIG8(ifid_stage__DOT__id_ready_o,0,0);
    VL_SIG8(ifid_stage__DOT__exc_addr_if,0,0);
    VL_SIG8(ifid_stage__DOT__ex_exc_addr_if,0,0);
    VL_SIG8(ifid_stage__DOT__IF__DOT__pc_sel,1,0);
    VL_SIG8(ifid_stage__DOT__IF__DOT__if_stall_,0,0);
    VL_SIG8(ifid_stage__DOT__IF__DOT__wbm_err_i,0,0);
    VL_SIG8(ifid_stage__DOT__IF__DOT__wbm_cyc_o,0,0);
    VL_SIG8(ifid_stage__DOT__IF__DOT__wbm_stb_o,0,0);
    VL_SIG8(ifid_stage__DOT__IF__DOT__wbm_ready_o,0,0);
    VL_SIG8(ifid_stage__DOT__IF__DOT__wbm_sel_o,3,0);
    VL_SIG8(ifid_stage__DOT__IF__DOT__id_exc_addr_o,0,0);
    VL_SIG8(ifid_stage__DOT__IF__DOT__LSU__DOT__abort,0,0);
    VL_SIG8(ifid_stage__DOT__IF__DOT__LSU__DOT__no_mem,0,0);
    VL_SIG8(ifid_stage__DOT__IF__DOT__LSU__DOT__mread,0,0);
    VL_SIG8(ifid_stage__DOT__IF__DOT__LSU__DOT__mwrite,0,0);
    VL_SIG8(ifid_stage__DOT__IF__DOT__LSU__DOT__mbyte,0,0);
    VL_SIG8(ifid_stage__DOT__IF__DOT__LSU__DOT__mhw,0,0);
    VL_SIG8(ifid_stage__DOT__IF__DOT__LSU__DOT__mword,0,0);
    VL_SIG8(ifid_stage__DOT__IF__DOT__LSU__DOT__munsigned,0,0);
    VL_SIG8(ifid_stage__DOT__IF__DOT__LSU__DOT__mem_stall,0,0);
    VL_SIG8(ifid_stage__DOT__IF__DOT__LSU__DOT__mem_bus_err,0,0);
    VL_SIG8(ifid_stage__DOT__IF__DOT__LSU__DOT__dack_i,0,0);
    VL_SIG8(ifid_stage__DOT__IF__DOT__LSU__DOT__derr_i,0,0);
    VL_SIG8(ifid_stage__DOT__IF__DOT__LSU__DOT__dsel_o,3,0);
    VL_SIG8(ifid_stage__DOT__IF__DOT__LSU__DOT__dcyc_o,0,0);
    VL_SIG8(ifid_stage__DOT__IF__DOT__LSU__DOT__dstb_o,0,0);
    VL_SIG8(ifid_stage__DOT__IF__DOT__LSU__DOT__dwe_o,0,0);
    VL_SIG8(ifid_stage__DOT__IF__DOT__LSU__DOT__i_state,1,0);
    VL_SIG8(ifid_stage__DOT__IF__DOT__LSU__DOT__d_state,1,0);
    VL_SIG8(ifid_stage__DOT__IF__DOT__LSU__DOT__if_stall_aux,0,0);
    VL_SIG8(ifid_stage__DOT__IF__DOT__BRAM__DOT__we_i,0,0);
    VL_SIG8(ifid_stage__DOT__IF__DOT__BRAM__DOT__b_state,0,0);
    VL_SIG8(ifid_stage__DOT__IF__DOT__BRAM__DOT__rdat,7,0);
    VL_SIG8(ifid_stage__DOT__IF__DOT__BRAM__DOT__wdat,7,0);
    VL_SIG8(ifid_stage__DOT__IF__DOT__IF_ID__DOT__flush,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__wb_address,4,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__wb_we,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__mem_stall,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__rs1,4,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__rd,4,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__comparator_op,2,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__bad_jump_address,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__ex_exc_address_if,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__DCU__DOT__mem_b,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__DCU__DOT__mem_hw,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__DCU__DOT__lui,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__DCU__DOT__auipc,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__DCU__DOT__jal,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__DCU__DOT__jalr,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__DCU__DOT__beq,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__DCU__DOT__bne,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__DCU__DOT__blt,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__DCU__DOT__bge,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__DCU__DOT__bltu,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__DCU__DOT__bgeu,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__DCU__DOT__lb,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__DCU__DOT__lh,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__DCU__DOT__lw,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__DCU__DOT__lbu,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__DCU__DOT__lhu,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__DCU__DOT__sb,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__DCU__DOT__sh,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__DCU__DOT__sw,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__DCU__DOT__addi,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__DCU__DOT__slti,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__DCU__DOT__sltiu,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__DCU__DOT__xori,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__DCU__DOT__ori,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__DCU__DOT__andi,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__DCU__DOT__slli,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__DCU__DOT__srli,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__DCU__DOT__srai,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__DCU__DOT__add,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__DCU__DOT__sub,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__DCU__DOT__sll,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__DCU__DOT__slt,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__DCU__DOT__sltu,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__DCU__DOT___xor,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__DCU__DOT__srl,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__DCU__DOT__sra,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__DCU__DOT___or,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__DCU__DOT___and,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__DCU__DOT__fence,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__DCU__DOT__rw,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__DCU__DOT__rs,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__DCU__DOT__rc,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__DCU__DOT__rwi,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__DCU__DOT__rsi,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__DCU__DOT__rci,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__DCU__DOT__is_b,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__DCU__DOT__is_imm,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__DCU__DOT__is_st,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__DCU__DOT__is_ld,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__DCU__DOT__is_add,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__DCU__DOT__is_sub,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__DCU__DOT__is_and,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__DCU__DOT__is_xor,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__DCU__DOT__is_or,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__DCU__DOT__is_sll,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__DCU__DOT__is_sr,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__DCU__DOT__is_slt,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__DCU__DOT__is_sltu,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__DCU__DOT__is_wr,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__DCU__DOT__is_alu,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__DCU__DOT__is_immop,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__DCU__DOT__is_ldu,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__DCU__DOT__is_bu,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__DCU__DOT__is_j,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__DCU__DOT__is_csr,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__DCU__DOT__is_csri,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__DCU__DOT__is_word,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__DCU__DOT__is_byte,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__DCU__DOT__is_hw,0,0);
    VL_SIG8(ifid_stage__DOT__ID__DOT__ID_EX__DOT__flush,0,0);
    VL_SIG(ifid_stage__DOT__id_pc,31,0);
    VL_SIG(ifid_stage__DOT__id_pc_add4,31,0);
    VL_SIG(ifid_stage__DOT__id_instruction,31,0);
    VL_SIG(ifid_stage__DOT__IF__DOT__pc_branch_address,31,0);
    VL_SIG(ifid_stage__DOT__IF__DOT__pc_jump_address,31,0);
    VL_SIG(ifid_stage__DOT__IF__DOT__if_pc_mux,31,0);
    VL_SIG(ifid_stage__DOT__IF__DOT__if_pc_o,31,0);
    VL_SIG(ifid_stage__DOT__IF__DOT__if_instruction_o,31,0);
    VL_SIG(ifid_stage__DOT__IF__DOT__wbm_dat_i,31,0);
    VL_SIG(ifid_stage__DOT__IF__DOT__wbm_addr_o,31,0);
    VL_SIG(ifid_stage__DOT__IF__DOT__wbm_dat_o,31,0);
    VL_SIG(ifid_stage__DOT__IF__DOT__PC_SOURCE__DOT__in3,31,0);
    VL_SIG(ifid_stage__DOT__IF__DOT__LSU__DOT__idat_o,31,0);
    VL_SIG(ifid_stage__DOT__IF__DOT__LSU__DOT__maddr_i,31,0);
    VL_SIG(ifid_stage__DOT__IF__DOT__LSU__DOT__mdat_i,31,0);
    VL_SIG(ifid_stage__DOT__IF__DOT__LSU__DOT__data_o,31,0);
    VL_SIG(ifid_stage__DOT__IF__DOT__LSU__DOT__ddat_i,31,0);
    VL_SIG(ifid_stage__DOT__IF__DOT__LSU__DOT__daddr_o,31,0);
    VL_SIG(ifid_stage__DOT__IF__DOT__LSU__DOT__ddat_o,31,0);
    VL_SIG(ifid_stage__DOT__IF__DOT__LSU__DOT__rdata,31,0);
    VL_SIG(ifid_stage__DOT__IF__DOT__LSU__DOT__wdata,31,0);
    VL_SIG(ifid_stage__DOT__IF__DOT__BRAM__DOT__dat_i,31,0);
    VL_SIG(ifid_stage__DOT__ID__DOT__wb_data,31,0);
    VL_SIG(ifid_stage__DOT__ID__DOT__forwardA,31,0);
    VL_SIG(ifid_stage__DOT__ID__DOT__forwardB,31,0);
    VL_SIG(ifid_stage__DOT__ID__DOT__drs1,31,0);
    VL_SIG(ifid_stage__DOT__ID__DOT__drs2,31,0);
    VL_SIG(ifid_stage__DOT__ID__DOT__drd,31,0);
    VL_SIG(ifid_stage__DOT__ID__DOT__immediate,31,0);
    VL_SIG(ifid_stage__DOT__ID__DOT__imm,31,0);
    VL_SIG(ifid_stage__DOT__ID__DOT___imm,31,0);
    VL_SIG(ifid_stage__DOT__ID__DOT__port_a,31,0);
    VL_SIG(ifid_stage__DOT__ID__DOT__port_b,31,0);
    VL_SIG64(ifid_stage__DOT__IF__DOT__LSU__DOT__no_rps,63,0);
    VL_SIG8(ifid_stage__DOT__IF__DOT__BRAM__DOT__memory[1025],7,0);
    //char	__VpadToAlign1313[7];
    VL_SIG(ifid_stage__DOT__ID__DOT__RF__DOT__reg_file[32],31,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    VL_SIG8(ifid_stage__DOT__IF__DOT__BRAM__DOT____Vlvbound1,7,0);
    VL_SIG8(ifid_stage__DOT__IF__DOT__BRAM__DOT____Vlvbound2,7,0);
    VL_SIG8(ifid_stage__DOT__IF__DOT__BRAM__DOT____Vlvbound3,7,0);
    VL_SIG8(ifid_stage__DOT__IF__DOT__BRAM__DOT____Vlvbound4,7,0);
    VL_SIG8(ifid_stage__DOT__IF__DOT__BRAM__DOT____Vlvbound5,7,0);
    VL_SIG8(ifid_stage__DOT__IF__DOT__BRAM__DOT____Vlvbound6,7,0);
    VL_SIG8(ifid_stage__DOT__IF__DOT__BRAM__DOT____Vlvbound7,7,0);
    VL_SIG8(ifid_stage__DOT__IF__DOT__BRAM__DOT____Vlvbound8,7,0);
    VL_SIG8(ifid_stage__DOT__IF__DOT__BRAM__DOT____Vlvbound9,7,0);
    VL_SIG8(__Vdly__ifid_stage__DOT__IF__DOT__wbm_cyc_o,0,0);
    VL_SIG8(__Vdly__ifid_stage__DOT__IF__DOT__wbm_stb_o,0,0);
    VL_SIG8(__Vdly__ifid_stage__DOT__IF__DOT__wbm_ack_i,0,0);
    VL_SIG8(__Vdly__ifid_stage__DOT__IF__DOT__BRAM__DOT__b_state,0,0);
    VL_SIG8(__VinpClk__TOP__ifid_stage__DOT__IF__DOT__wbm_ack_i,0,0);
    VL_SIG8(__Vclklast__TOP__clk_i,0,0);
    VL_SIG8(__Vclklast__TOP____VinpClk__TOP__ifid_stage__DOT__IF__DOT__wbm_ack_i,0,0);
    VL_SIG8(__Vchglast__TOP__ifid_stage__DOT__IF__DOT__wbm_ack_i,0,0);
    VL_SIG8(__Vchglast__TOP__ifid_stage__DOT__IF__DOT__wbm_cyc_o,0,0);
    VL_SIG8(__Vchglast__TOP__ifid_stage__DOT__IF__DOT__wbm_stb_o,0,0);
    //char	__VpadToAlign1471[1];
    VL_SIG(__Vm_traceActivity,31,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vifid_stage__Syms*	__VlSymsp;		// Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    Vifid_stage& operator= (const Vifid_stage&);	///< Copying not allowed
    Vifid_stage(const Vifid_stage&);	///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible WRT DPI scope names.
    Vifid_stage(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vifid_stage();
    /// Trace signals in the model; called by application code
    void trace (VerilatedVcdC* tfp, int levels, int options=0);
    
    // USER METHODS
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vifid_stage__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vifid_stage__Syms* symsp, bool first);
  private:
    static QData	_change_request(Vifid_stage__Syms* __restrict vlSymsp);
  public:
    static void	_combo__TOP__5(Vifid_stage__Syms* __restrict vlSymsp);
  private:
    void	_configure_coverage(Vifid_stage__Syms* __restrict vlSymsp, bool first);
    void	_ctor_var_reset();
  public:
    static void	_eval(Vifid_stage__Syms* __restrict vlSymsp);
    static void	_eval_initial(Vifid_stage__Syms* __restrict vlSymsp);
    static void	_eval_settle(Vifid_stage__Syms* __restrict vlSymsp);
    static void	_initial__TOP__1(Vifid_stage__Syms* __restrict vlSymsp);
    static void	_initial__TOP__4(Vifid_stage__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__2(Vifid_stage__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__6(Vifid_stage__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__8(Vifid_stage__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__9(Vifid_stage__Syms* __restrict vlSymsp);
    static void	_settle__TOP__10(Vifid_stage__Syms* __restrict vlSymsp);
    static void	_settle__TOP__3(Vifid_stage__Syms* __restrict vlSymsp);
    static void	_settle__TOP__7(Vifid_stage__Syms* __restrict vlSymsp);
    static void	traceChgThis(Vifid_stage__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__10(Vifid_stage__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__11(Vifid_stage__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__12(Vifid_stage__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__2(Vifid_stage__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__3(Vifid_stage__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__4(Vifid_stage__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__5(Vifid_stage__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__6(Vifid_stage__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__7(Vifid_stage__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__8(Vifid_stage__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__9(Vifid_stage__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceFullThis(Vifid_stage__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceFullThis__1(Vifid_stage__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceInitThis(Vifid_stage__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceInitThis__1(Vifid_stage__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceInit (VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull (VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg  (VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(128);

#endif  /*guard*/
