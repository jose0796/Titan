// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


//======================

void Vtop::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback(&Vtop::traceInit, &Vtop::traceFull, &Vtop::traceChg, this);
}
void Vtop::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    Vtop* t=(Vtop*)userthis;
    Vtop__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) {
	VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vcdp->scopeEscape(' ');
    t->traceInitThis(vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void Vtop::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vtop* t=(Vtop*)userthis;
    Vtop__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    t->traceFullThis(vlSymsp, vcdp, code);
}

//======================


void Vtop::traceInitThis(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name());  // Setup signal names
    // Body
    {
	vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void Vtop::traceFullThis(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vtop::traceInitThis__1(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->declBit  (c+269,"clk_i",-1);
	vcdp->declBit  (c+270,"rst_i",-1);
	vcdp->declBus  (c+273,"top HART_ID",-1,31,0);
	vcdp->declBus  (c+274,"top RESET_ADDR",-1,31,0);
	vcdp->declBus  (c+275,"top ENABLE_COUNTERS",-1,0,0);
	vcdp->declBus  (c+275,"top ENABLE_M_ISA",-1,0,0);
	vcdp->declBus  (c+276,"top MEM_SIZE",-1,31,0);
	vcdp->declBit  (c+269,"top clk_i",-1);
	vcdp->declBit  (c+270,"top rst_i",-1);
	vcdp->declBus  (c+139,"top dwbm_addr",-1,31,0);
	vcdp->declBit  (c+140,"top dwbm_cyc",-1);
	vcdp->declBus  (c+141,"top dwbm_dat_o",-1,31,0);
	vcdp->declBus  (c+1,"top dwbm_dat_i",-1,31,0);
	vcdp->declBus  (c+142,"top dwbm_sel",-1,3,0);
	vcdp->declBit  (c+143,"top dwbm_stb",-1);
	vcdp->declBit  (c+144,"top dwbm_we",-1);
	vcdp->declBus  (c+145,"top iwbm_addr",-1,31,0);
	vcdp->declBit  (c+146,"top iwbm_cyc",-1);
	vcdp->declBus  (c+2,"top iwbm_dat",-1,31,0);
	vcdp->declBit  (c+147,"top iwbm_stb",-1);
	vcdp->declBit  (c+148,"top iwbm_ack",-1);
	vcdp->declBit  (c+123,"top dwbm_ack",-1);
	vcdp->declBus  (c+273,"top cpu HART_ID",-1,31,0);
	vcdp->declBus  (c+274,"top cpu RESET_ADDR",-1,31,0);
	vcdp->declBus  (c+275,"top cpu ENABLE_COUNTERS",-1,0,0);
	vcdp->declBus  (c+275,"top cpu ENABLE_M_ISA",-1,0,0);
	vcdp->declBus  (c+277,"top cpu UCONTROL",-1,0,0);
	vcdp->declBit  (c+269,"top cpu clk_i",-1);
	vcdp->declBit  (c+270,"top cpu rst_i",-1);
	vcdp->declBus  (c+145,"top cpu iwbm_addr_o",-1,31,0);
	vcdp->declBit  (c+146,"top cpu iwbm_cyc_o",-1);
	vcdp->declBit  (c+147,"top cpu iwbm_stb_o",-1);
	vcdp->declBus  (c+2,"top cpu iwbm_dat_i",-1,31,0);
	vcdp->declBit  (c+278,"top cpu iwbm_err_i",-1);
	vcdp->declBit  (c+148,"top cpu iwbm_ack_i",-1);
	vcdp->declBus  (c+1,"top cpu dwbm_dat_i",-1,31,0);
	vcdp->declBit  (c+278,"top cpu dwbm_err_i",-1);
	vcdp->declBit  (c+123,"top cpu dwbm_ack_i",-1);
	vcdp->declBus  (c+139,"top cpu dwbm_addr_o",-1,31,0);
	vcdp->declBit  (c+140,"top cpu dwbm_cyc_o",-1);
	vcdp->declBit  (c+143,"top cpu dwbm_stb_o",-1);
	vcdp->declBus  (c+141,"top cpu dwbm_dat_o",-1,31,0);
	vcdp->declBit  (c+144,"top cpu dwbm_we_o",-1);
	vcdp->declBus  (c+142,"top cpu dwbm_sel_o",-1,3,0);
	vcdp->declBit  (c+278,"top cpu xint_meip_i",-1);
	vcdp->declBit  (c+278,"top cpu xint_mtip_i",-1);
	vcdp->declBit  (c+278,"top cpu xint_msip_i",-1);
	vcdp->declBit  (c+271,"top cpu if_stall",-1);
	vcdp->declBit  (c+124,"top cpu if_flush",-1);
	vcdp->declBus  (c+145,"top cpu if_pc",-1,31,0);
	vcdp->declBus  (c+129,"top cpu if_pc_sel",-1,1,0);
	vcdp->declBus  (c+2,"top cpu if_instruction",-1,31,0);
	vcdp->declBus  (c+149,"top cpu id_instruction",-1,31,0);
	vcdp->declBus  (c+150,"top cpu id_pc",-1,31,0);
	vcdp->declBit  (c+151,"top cpu id_exc_addr_if",-1);
	vcdp->declBit  (c+152,"top cpu id_inst_access_fault",-1);
	vcdp->declBus  (c+153,"top cpu wb_waddr",-1,4,0);
	vcdp->declBit  (c+154,"top cpu wb_we",-1);
	vcdp->declBit  (c+125,"top cpu id_stall",-1);
	vcdp->declBit  (c+270,"top cpu id_flush",-1);
	vcdp->declBus  (c+3,"top cpu ex_fwd_drd",-1,31,0);
	vcdp->declBus  (c+130,"top cpu mem_fwd_drd",-1,31,0);
	vcdp->declBus  (c+4,"top cpu forward_a_sel",-1,1,0);
	vcdp->declBus  (c+5,"top cpu forward_b_sel",-1,1,0);
	vcdp->declBus  (c+6,"top cpu id_rs1",-1,4,0);
	vcdp->declBus  (c+155,"top cpu id_rs2",-1,4,0);
	vcdp->declBus  (c+7,"top cpu pc_jump_addr",-1,31,0);
	vcdp->declBus  (c+8,"top cpu pc_branch_addr",-1,31,0);
	vcdp->declBit  (c+131,"top cpu take_branch",-1);
	vcdp->declBit  (c+9,"top cpu take_jump",-1);
	vcdp->declBus  (c+156,"top cpu ex_pc",-1,31,0);
	vcdp->declBus  (c+157,"top cpu ex_instruction",-1,31,0);
	vcdp->declBus  (c+158,"top cpu ex_port_a",-1,31,0);
	vcdp->declBus  (c+159,"top cpu ex_port_b",-1,31,0);
	vcdp->declBus  (c+160,"top cpu ex_alu_op",-1,3,0);
	vcdp->declBus  (c+161,"top cpu ex_waddr",-1,4,0);
	vcdp->declBit  (c+162,"top cpu ex_we",-1);
	vcdp->declBus  (c+163,"top cpu ex_mem_flags",-1,5,0);
	vcdp->declBit  (c+164,"top cpu ex_mem_ex_sel",-1);
	vcdp->declBit  (c+165,"top cpu ex_bad_jump_addr",-1);
	vcdp->declBit  (c+166,"top cpu ex_bad_branch_addr",-1);
	vcdp->declBit  (c+167,"top cpu ex_break_op",-1);
	vcdp->declBit  (c+168,"top cpu ex_syscall_op",-1);
	vcdp->declBus  (c+169,"top cpu ex_csr_op",-1,2,0);
	vcdp->declBus  (c+170,"top cpu ex_csr_data",-1,31,0);
	vcdp->declBus  (c+171,"top cpu ex_csr_addr",-1,11,0);
	vcdp->declBit  (c+172,"top cpu ex_exc_addr_if",-1);
	vcdp->declBit  (c+173,"top cpu ex_inst_access_fault",-1);
	vcdp->declBit  (c+125,"top cpu ex_stall",-1);
	vcdp->declBit  (c+270,"top cpu ex_flush",-1);
	vcdp->declBus  (c+174,"top cpu mem_pc",-1,31,0);
	vcdp->declBus  (c+175,"top cpu mem_instruction",-1,31,0);
	vcdp->declBus  (c+176,"top cpu mem_result",-1,31,0);
	vcdp->declBus  (c+177,"top cpu mem_waddr",-1,4,0);
	vcdp->declBit  (c+178,"top cpu mem_we",-1);
	vcdp->declBus  (c+262,"top cpu mem_mem_flags",-1,5,0);
	vcdp->declBit  (c+179,"top cpu mem_mem_ex_sel",-1);
	vcdp->declBus  (c+180,"top cpu mem_csr_data",-1,31,0);
	vcdp->declBus  (c+181,"top cpu mem_csr_op",-1,2,0);
	vcdp->declBus  (c+182,"top cpu mem_csr_addr",-1,11,0);
	vcdp->declBit  (c+183,"top cpu mem_exc_addr_if",-1);
	vcdp->declBit  (c+184,"top cpu mem_inst_access_fault",-1);
	vcdp->declBit  (c+185,"top cpu mem_bad_jump_addr",-1);
	vcdp->declBit  (c+186,"top cpu mem_bad_branch_addr",-1);
	vcdp->declBit  (c+187,"top cpu mem_break_op",-1);
	vcdp->declBit  (c+188,"top cpu mem_syscall_op",-1);
	vcdp->declBit  (c+263,"top cpu mwrite",-1);
	vcdp->declBit  (c+264,"top cpu mread",-1);
	vcdp->declBit  (c+265,"top cpu mword",-1);
	vcdp->declBit  (c+266,"top cpu mhw",-1);
	vcdp->declBit  (c+267,"top cpu mbyte",-1);
	vcdp->declBit  (c+268,"top cpu munsigned",-1);
	vcdp->declBit  (c+125,"top cpu mem_stall",-1);
	vcdp->declBit  (c+270,"top cpu mem_flush",-1);
	vcdp->declBus  (c+189,"top cpu mem_store_data",-1,31,0);
	vcdp->declBus  (c+132,"top cpu mem_load_data",-1,31,0);
	vcdp->declBus  (c+190,"top cpu wb_pc",-1,31,0);
	vcdp->declBus  (c+191,"top cpu wb_instruction",-1,31,0);
	vcdp->declBus  (c+192,"top cpu wb_result",-1,31,0);
	vcdp->declBus  (c+193,"top cpu wb_csr_data",-1,31,0);
	vcdp->declBus  (c+194,"top cpu wb_csr_addr",-1,11,0);
	vcdp->declBus  (c+195,"top cpu wb_csr_op",-1,2,0);
	vcdp->declBit  (c+196,"top cpu wb_exc_addr_if",-1);
	vcdp->declBit  (c+197,"top cpu wb_inst_access_fault",-1);
	vcdp->declBit  (c+198,"top cpu wb_mem_access_fault",-1);
	vcdp->declBit  (c+199,"top cpu wb_bad_jump_addr",-1);
	vcdp->declBit  (c+200,"top cpu wb_bad_branch_addr",-1);
	vcdp->declBit  (c+201,"top cpu wb_break_op",-1);
	vcdp->declBit  (c+202,"top cpu wb_syscall_op",-1);
	vcdp->declBit  (c+279,"top cpu wb_fence_op",-1);
	vcdp->declBit  (c+280,"top cpu wb_ret_op",-1);
	vcdp->declBit  (c+10,"top cpu ld_dependence",-1);
	vcdp->declBit  (c+9,"top cpu jump_flush_req",-1);
	vcdp->declBit  (c+131,"top cpu branch_flush_req",-1);
	vcdp->declBit  (c+272,"top cpu if_stall_req",-1);
	vcdp->declBit  (c+125,"top cpu mem_stall_req",-1);
	vcdp->declBit  (c+10,"top cpu fwd_stall_req",-1);
	vcdp->declBit  (c+10,"top cpu ex_nop",-1);
	vcdp->declBit  (c+133,"top cpu if_kill",-1);
	vcdp->declBit  (c+281,"top cpu trap_valid",-1);
	vcdp->declBus  (c+282,"top cpu exception_code",-1,3,0);
	vcdp->declBit  (c+283,"top cpu interrupt_code",-1);
	vcdp->declBit  (c+284,"top cpu intruction_ret",-1);
	vcdp->declBus  (c+11,"top cpu csr_data_o",-1,31,0);
	vcdp->declBus  (c+274,"top cpu IF RESET_ADDR",-1,31,0);
	vcdp->declBit  (c+269,"top cpu IF clk_i",-1);
	vcdp->declBit  (c+270,"top cpu IF rst_i",-1);
	vcdp->declBit  (c+126,"top cpu IF if_stall",-1);
	vcdp->declBit  (c+125,"top cpu IF id_stall",-1);
	vcdp->declBit  (c+124,"top cpu IF if_flush",-1);
	vcdp->declBus  (c+2,"top cpu IF if_instruction_i",-1,31,0);
	vcdp->declBus  (c+8,"top cpu IF pc_branch_address_i",-1,31,0);
	vcdp->declBus  (c+7,"top cpu IF pc_jump_address_i",-1,31,0);
	vcdp->declBus  (c+129,"top cpu IF if_pc_sel_i",-1,1,0);
	vcdp->declBit  (c+278,"top cpu IF if_bus_access_fault_i",-1);
	vcdp->declBus  (c+145,"top cpu IF if_pc_o",-1,31,0);
	vcdp->declBus  (c+149,"top cpu IF id_instruction_o",-1,31,0);
	vcdp->declBus  (c+150,"top cpu IF id_pc_o",-1,31,0);
	vcdp->declBit  (c+151,"top cpu IF id_exc_addr_if_o",-1);
	vcdp->declBit  (c+152,"top cpu IF id_bus_access_fault_o",-1);
	vcdp->declBus  (c+120,"top cpu IF if_pc_mux",-1,31,0);
	vcdp->declBus  (c+203,"top cpu IF if_pc_add4",-1,31,0);
	vcdp->declBit  (c+204,"top cpu IF if_exc_addr_if_i",-1);
	vcdp->declBus  (c+274,"top cpu IF PC_REG RESET_ADDR",-1,31,0);
	vcdp->declBit  (c+269,"top cpu IF PC_REG clk_i",-1);
	vcdp->declBit  (c+270,"top cpu IF PC_REG rst_i",-1);
	vcdp->declBit  (c+126,"top cpu IF PC_REG stall",-1);
	vcdp->declBus  (c+120,"top cpu IF PC_REG pc_i",-1,31,0);
	vcdp->declBus  (c+145,"top cpu IF PC_REG pc_o",-1,31,0);
	vcdp->declBus  (c+145,"top cpu IF PC_ADD pc",-1,31,0);
	vcdp->declBus  (c+203,"top cpu IF PC_ADD pc_next",-1,31,0);
	vcdp->declBus  (c+203,"top cpu IF PC_SOURCE in0",-1,31,0);
	vcdp->declBus  (c+8,"top cpu IF PC_SOURCE in1",-1,31,0);
	vcdp->declBus  (c+7,"top cpu IF PC_SOURCE in2",-1,31,0);
	vcdp->declBus  (c+285,"top cpu IF PC_SOURCE in3",-1,31,0);
	vcdp->declBus  (c+129,"top cpu IF PC_SOURCE sel",-1,1,0);
	vcdp->declBus  (c+120,"top cpu IF PC_SOURCE out",-1,31,0);
	vcdp->declBit  (c+269,"top cpu IF IF_ID clk",-1);
	vcdp->declBit  (c+270,"top cpu IF IF_ID rst",-1);
	vcdp->declBit  (c+124,"top cpu IF IF_ID flush",-1);
	vcdp->declBit  (c+126,"top cpu IF IF_ID if_stall",-1);
	vcdp->declBit  (c+125,"top cpu IF IF_ID id_stall",-1);
	vcdp->declBus  (c+145,"top cpu IF IF_ID if_pc",-1,31,0);
	vcdp->declBit  (c+204,"top cpu IF IF_ID if_exc_addr_if",-1);
	vcdp->declBit  (c+278,"top cpu IF IF_ID if_bus_access_fault",-1);
	vcdp->declBus  (c+2,"top cpu IF IF_ID if_inst",-1,31,0);
	vcdp->declBus  (c+150,"top cpu IF IF_ID id_pc",-1,31,0);
	vcdp->declBit  (c+151,"top cpu IF IF_ID id_exc_addr_if",-1);
	vcdp->declBus  (c+149,"top cpu IF IF_ID id_inst",-1,31,0);
	vcdp->declBit  (c+152,"top cpu IF IF_ID id_bus_access_fault",-1);
	vcdp->declBit  (c+269,"top cpu ID clk_i",-1);
	vcdp->declBit  (c+270,"top cpu ID rst_i",-1);
	vcdp->declBit  (c+125,"top cpu ID id_stall_i",-1);
	vcdp->declBit  (c+270,"top cpu ID id_flush_i",-1);
	vcdp->declBus  (c+150,"top cpu ID id_pc_i",-1,31,0);
	vcdp->declBus  (c+149,"top cpu ID id_instruction_i",-1,31,0);
	vcdp->declBit  (c+151,"top cpu ID id_exc_address_if_i",-1);
	vcdp->declBit  (c+152,"top cpu ID id_bus_access_fault_i",-1);
	vcdp->declBus  (c+192,"top cpu ID wb_data_i",-1,31,0);
	vcdp->declBus  (c+153,"top cpu ID wb_address_i",-1,4,0);
	vcdp->declBit  (c+154,"top cpu ID wb_we_i",-1);
	vcdp->declBus  (c+3,"top cpu ID ex_fwd_drd_i",-1,31,0);
	vcdp->declBus  (c+130,"top cpu ID mem_fwd_drd_i",-1,31,0);
	vcdp->declBus  (c+192,"top cpu ID wb_fwd_drd_i",-1,31,0);
	vcdp->declBus  (c+4,"top cpu ID forward_a_sel_i",-1,1,0);
	vcdp->declBus  (c+5,"top cpu ID forward_b_sel_i",-1,1,0);
	vcdp->declBus  (c+6,"top cpu ID id_rs1_o",-1,4,0);
	vcdp->declBus  (c+155,"top cpu ID id_rs2_o",-1,4,0);
	vcdp->declBus  (c+8,"top cpu ID pc_branch_address_o",-1,31,0);
	vcdp->declBus  (c+7,"top cpu ID pc_jump_address_o",-1,31,0);
	vcdp->declBit  (c+131,"top cpu ID take_branch_o",-1);
	vcdp->declBit  (c+9,"top cpu ID take_jump_o",-1);
	vcdp->declBus  (c+156,"top cpu ID ex_pc_o",-1,31,0);
	vcdp->declBus  (c+157,"top cpu ID ex_instruction_o",-1,31,0);
	vcdp->declBus  (c+158,"top cpu ID ex_port_a_o",-1,31,0);
	vcdp->declBus  (c+159,"top cpu ID ex_port_b_o",-1,31,0);
	vcdp->declBus  (c+160,"top cpu ID ex_alu_op_o",-1,3,0);
	vcdp->declBus  (c+161,"top cpu ID ex_waddr_o",-1,4,0);
	vcdp->declBit  (c+162,"top cpu ID ex_we_o",-1);
	vcdp->declBus  (c+163,"top cpu ID ex_mem_flags_o",-1,5,0);
	vcdp->declBit  (c+164,"top cpu ID ex_mem_ex_sel_o",-1);
	vcdp->declBit  (c+165,"top cpu ID ex_bad_jump_addr_o",-1);
	vcdp->declBit  (c+166,"top cpu ID ex_bad_branch_addr_o",-1);
	vcdp->declBit  (c+167,"top cpu ID ex_break_op_o",-1);
	vcdp->declBit  (c+168,"top cpu ID ex_syscall_op_o",-1);
	vcdp->declBus  (c+170,"top cpu ID ex_csr_data_o",-1,31,0);
	vcdp->declBus  (c+169,"top cpu ID ex_csr_op_o",-1,2,0);
	vcdp->declBus  (c+171,"top cpu ID ex_csr_addr_o",-1,11,0);
	vcdp->declBit  (c+172,"top cpu ID ex_exc_addr_if_o",-1);
	vcdp->declBit  (c+173,"top cpu ID ex_bus_access_fault_o",-1);
	vcdp->declBus  (c+134,"top cpu ID muxa_i",-1,31,0);
	vcdp->declBus  (c+135,"top cpu ID muxb_i",-1,31,0);
	vcdp->declBus  (c+6,"top cpu ID rs1",-1,4,0);
	vcdp->declBus  (c+155,"top cpu ID rs2",-1,4,0);
	vcdp->declBus  (c+12,"top cpu ID drs1",-1,31,0);
	vcdp->declBus  (c+13,"top cpu ID drs2",-1,31,0);
	vcdp->declBit  (c+14,"top cpu ID we",-1);
	vcdp->declBus  (c+15,"top cpu ID alu_op",-1,3,0);
	vcdp->declBus  (c+16,"top cpu ID comparator_op",-1,2,0);
	vcdp->declBus  (c+17,"top cpu ID imm",-1,31,0);
	// Tracing: top cpu ID _imm // Ignored: Inlined leading underscore at hardware/titan_id_stage.v:62
	vcdp->declBus  (c+18,"top cpu ID waddr",-1,4,0);
	vcdp->declBit  (c+19,"top cpu ID portb_sel",-1);
	vcdp->declBit  (c+20,"top cpu ID porta_sel",-1);
	vcdp->declBus  (c+136,"top cpu ID port_a",-1,31,0);
	vcdp->declBus  (c+137,"top cpu ID port_b",-1,31,0);
	vcdp->declBit  (c+21,"top cpu ID jalr_op",-1);
	vcdp->declBus  (c+22,"top cpu ID mem_flags",-1,5,0);
	vcdp->declBit  (c+23,"top cpu ID mem_ex_sel",-1);
	vcdp->declBit  (c+9,"top cpu ID jump_op",-1);
	vcdp->declBus  (c+24,"top cpu ID pc_jump",-1,31,0);
	vcdp->declBit  (c+25,"top cpu ID bad_jump_addr",-1);
	vcdp->declBit  (c+26,"top cpu ID branch_op",-1);
	vcdp->declBit  (c+27,"top cpu ID bad_branch_addr",-1);
	vcdp->declBit  (c+121,"top cpu ID take_branch",-1);
	vcdp->declBit  (c+205,"top cpu ID break_op",-1);
	vcdp->declBit  (c+206,"top cpu ID syscall_op",-1);
	vcdp->declBus  (c+122,"top cpu ID csr_data",-1,31,0);
	vcdp->declBus  (c+207,"top cpu ID csr_addr",-1,11,0);
	vcdp->declBus  (c+208,"top cpu ID csr_op",-1,2,0);
	vcdp->declBit  (c+28,"top cpu ID csr_imm_op",-1);
	vcdp->declBus  (c+134,"top cpu ID PORT_A_MUX in_0",-1,31,0);
	vcdp->declBus  (c+150,"top cpu ID PORT_A_MUX in_1",-1,31,0);
	vcdp->declBit  (c+20,"top cpu ID PORT_A_MUX sel",-1);
	vcdp->declBus  (c+136,"top cpu ID PORT_A_MUX out",-1,31,0);
	vcdp->declBus  (c+135,"top cpu ID PORT_B_MUX in_0",-1,31,0);
	vcdp->declBus  (c+17,"top cpu ID PORT_B_MUX in_1",-1,31,0);
	vcdp->declBit  (c+19,"top cpu ID PORT_B_MUX sel",-1);
	vcdp->declBus  (c+137,"top cpu ID PORT_B_MUX out",-1,31,0);
	vcdp->declBus  (c+12,"top cpu ID FORWARD_A_MUX in_0",-1,31,0);
	vcdp->declBus  (c+3,"top cpu ID FORWARD_A_MUX in_1",-1,31,0);
	vcdp->declBus  (c+130,"top cpu ID FORWARD_A_MUX in_2",-1,31,0);
	vcdp->declBus  (c+192,"top cpu ID FORWARD_A_MUX in_3",-1,31,0);
	vcdp->declBus  (c+4,"top cpu ID FORWARD_A_MUX sel",-1,1,0);
	vcdp->declBus  (c+134,"top cpu ID FORWARD_A_MUX out",-1,31,0);
	vcdp->declBus  (c+13,"top cpu ID FORWARD_B_MUX in_0",-1,31,0);
	vcdp->declBus  (c+3,"top cpu ID FORWARD_B_MUX in_1",-1,31,0);
	vcdp->declBus  (c+130,"top cpu ID FORWARD_B_MUX in_2",-1,31,0);
	vcdp->declBus  (c+192,"top cpu ID FORWARD_B_MUX in_3",-1,31,0);
	vcdp->declBus  (c+5,"top cpu ID FORWARD_B_MUX sel",-1,1,0);
	vcdp->declBus  (c+135,"top cpu ID FORWARD_B_MUX out",-1,31,0);
	vcdp->declBus  (c+16,"top cpu ID BP sel",-1,2,0);
	vcdp->declBus  (c+134,"top cpu ID BP drs1",-1,31,0);
	vcdp->declBus  (c+135,"top cpu ID BP drs2",-1,31,0);
	vcdp->declBit  (c+121,"top cpu ID BP take_branch",-1);
	vcdp->declBus  (c+134,"top cpu ID BP sdrs1",-1,31,0);
	vcdp->declBus  (c+135,"top cpu ID BP sdrs2",-1,31,0);
	vcdp->declBus  (c+134,"top cpu ID BP udrs1",-1,31,0);
	vcdp->declBus  (c+135,"top cpu ID BP udrs2",-1,31,0);
	vcdp->declBus  (c+286,"top cpu ID BP beq",-1,2,0);
	vcdp->declBus  (c+287,"top cpu ID BP bne",-1,2,0);
	vcdp->declBus  (c+288,"top cpu ID BP blt",-1,2,0);
	vcdp->declBus  (c+289,"top cpu ID BP bge",-1,2,0);
	vcdp->declBus  (c+290,"top cpu ID BP bltu",-1,2,0);
	vcdp->declBus  (c+291,"top cpu ID BP bgeu",-1,2,0);
	vcdp->declBus  (c+292,"top cpu ID BP nop",-1,2,0);
	vcdp->declBit  (c+269,"top cpu ID RF clk",-1);
	vcdp->declBus  (c+6,"top cpu ID RF raddr_rs1",-1,4,0);
	vcdp->declBus  (c+155,"top cpu ID RF raddr_rs2",-1,4,0);
	vcdp->declBus  (c+153,"top cpu ID RF waddr_rd",-1,4,0);
	vcdp->declBus  (c+192,"top cpu ID RF wdata_rd",-1,31,0);
	vcdp->declBit  (c+154,"top cpu ID RF we",-1);
	vcdp->declBus  (c+12,"top cpu ID RF rdata_rs1",-1,31,0);
	vcdp->declBus  (c+13,"top cpu ID RF rdata_rs2",-1,31,0);
	{int i; for (i=0; i<32; i++) {
		vcdp->declBus  (c+29+i*1,"top cpu ID RF reg_file",(i+0),31,0);}}
	vcdp->declBus  (c+149,"top cpu ID DCU instruction",-1,31,0);
	vcdp->declBus  (c+6,"top cpu ID DCU rs1",-1,4,0);
	vcdp->declBus  (c+155,"top cpu ID DCU rs2",-1,4,0);
	vcdp->declBus  (c+18,"top cpu ID DCU rd",-1,4,0);
	vcdp->declBit  (c+14,"top cpu ID DCU reg_write",-1);
	vcdp->declBus  (c+16,"top cpu ID DCU comparator_op",-1,2,0);
	vcdp->declBus  (c+22,"top cpu ID DCU mem_flags",-1,5,0);
	vcdp->declBit  (c+23,"top cpu ID DCU mem_ex_sel",-1);
	vcdp->declBus  (c+15,"top cpu ID DCU alu_op",-1,3,0);
	vcdp->declBus  (c+17,"top cpu ID DCU imm",-1,31,0);
	vcdp->declBit  (c+19,"top cpu ID DCU portb_sel",-1);
	vcdp->declBit  (c+20,"top cpu ID DCU porta_sel",-1);
	vcdp->declBit  (c+206,"top cpu ID DCU syscall_op",-1);
	vcdp->declBit  (c+26,"top cpu ID DCU branch_op",-1);
	vcdp->declBit  (c+9,"top cpu ID DCU jump_op",-1);
	vcdp->declBit  (c+21,"top cpu ID DCU jalr_op",-1);
	vcdp->declBit  (c+205,"top cpu ID DCU break_op",-1);
	vcdp->declBit  (c+28,"top cpu ID DCU csr_imm_op",-1);
	vcdp->declBus  (c+208,"top cpu ID DCU csr_op",-1,2,0);
	vcdp->declBus  (c+207,"top cpu ID DCU csr_addr",-1,11,0);
	vcdp->declBus  (c+209,"top cpu ID DCU opcode",-1,6,0);
	vcdp->declBus  (c+61,"top cpu ID DCU mem_access",-1,2,0);
	vcdp->declBit  (c+62,"top cpu ID DCU mem_wr",-1);
	vcdp->declBit  (c+23,"top cpu ID DCU mem_r",-1);
	vcdp->declBit  (c+23,"top cpu ID DCU mem_ex_s",-1);
	vcdp->declBit  (c+63,"top cpu ID DCU mem_unsigned",-1);
	vcdp->declBus  (c+149,"top cpu ID DCU inst",-1,31,0);
	vcdp->declBus  (c+210,"top cpu ID DCU func3",-1,2,0);
	vcdp->declBus  (c+211,"top cpu ID DCU func7",-1,6,0);
	vcdp->declBit  (c+64,"top cpu ID DCU lui",-1);
	vcdp->declBit  (c+65,"top cpu ID DCU auipc",-1);
	vcdp->declBit  (c+66,"top cpu ID DCU jal",-1);
	vcdp->declBit  (c+21,"top cpu ID DCU jalr",-1);
	vcdp->declBit  (c+67,"top cpu ID DCU beq",-1);
	vcdp->declBit  (c+68,"top cpu ID DCU bne",-1);
	vcdp->declBit  (c+69,"top cpu ID DCU blt",-1);
	vcdp->declBit  (c+70,"top cpu ID DCU bge",-1);
	vcdp->declBit  (c+71,"top cpu ID DCU bltu",-1);
	vcdp->declBit  (c+72,"top cpu ID DCU bgeu",-1);
	vcdp->declBit  (c+73,"top cpu ID DCU lb",-1);
	vcdp->declBit  (c+74,"top cpu ID DCU lh",-1);
	vcdp->declBit  (c+75,"top cpu ID DCU lw",-1);
	vcdp->declBit  (c+76,"top cpu ID DCU lbu",-1);
	vcdp->declBit  (c+77,"top cpu ID DCU lhu",-1);
	vcdp->declBit  (c+78,"top cpu ID DCU sb",-1);
	vcdp->declBit  (c+79,"top cpu ID DCU sh",-1);
	vcdp->declBit  (c+80,"top cpu ID DCU sw",-1);
	vcdp->declBit  (c+81,"top cpu ID DCU addi",-1);
	vcdp->declBit  (c+82,"top cpu ID DCU slti",-1);
	vcdp->declBit  (c+83,"top cpu ID DCU sltiu",-1);
	vcdp->declBit  (c+84,"top cpu ID DCU xori",-1);
	vcdp->declBit  (c+85,"top cpu ID DCU ori",-1);
	vcdp->declBit  (c+86,"top cpu ID DCU andi",-1);
	vcdp->declBit  (c+87,"top cpu ID DCU slli",-1);
	vcdp->declBit  (c+88,"top cpu ID DCU srli",-1);
	vcdp->declBit  (c+89,"top cpu ID DCU srai",-1);
	vcdp->declBit  (c+90,"top cpu ID DCU add",-1);
	vcdp->declBit  (c+91,"top cpu ID DCU sub",-1);
	vcdp->declBit  (c+92,"top cpu ID DCU sll",-1);
	vcdp->declBit  (c+93,"top cpu ID DCU slt",-1);
	vcdp->declBit  (c+94,"top cpu ID DCU sltu",-1);
	// Tracing: top cpu ID DCU _xor // Ignored: Inlined leading underscore at hardware/titan_dc_unit.v:73
	vcdp->declBit  (c+95,"top cpu ID DCU srl",-1);
	vcdp->declBit  (c+96,"top cpu ID DCU sra",-1);
	// Tracing: top cpu ID DCU _or // Ignored: Inlined leading underscore at hardware/titan_dc_unit.v:73
	// Tracing: top cpu ID DCU _and // Ignored: Inlined leading underscore at hardware/titan_dc_unit.v:73
	vcdp->declBit  (c+212,"top cpu ID DCU rw",-1);
	vcdp->declBit  (c+213,"top cpu ID DCU rs",-1);
	vcdp->declBit  (c+214,"top cpu ID DCU rc",-1);
	vcdp->declBit  (c+97,"top cpu ID DCU rwi",-1);
	vcdp->declBit  (c+98,"top cpu ID DCU rsi",-1);
	vcdp->declBit  (c+99,"top cpu ID DCU rci",-1);
	vcdp->declBit  (c+206,"top cpu ID DCU call",-1);
	// Tracing: top cpu ID DCU _break // Ignored: Inlined leading underscore at hardware/titan_dc_unit.v:76
	vcdp->declBit  (c+26,"top cpu ID DCU is_b",-1);
	vcdp->declBit  (c+100,"top cpu ID DCU is_imm",-1);
	vcdp->declBit  (c+62,"top cpu ID DCU is_st",-1);
	vcdp->declBit  (c+23,"top cpu ID DCU is_ld",-1);
	vcdp->declBit  (c+101,"top cpu ID DCU is_add",-1);
	vcdp->declBit  (c+102,"top cpu ID DCU is_sub",-1);
	vcdp->declBit  (c+103,"top cpu ID DCU is_and",-1);
	vcdp->declBit  (c+104,"top cpu ID DCU is_xor",-1);
	vcdp->declBit  (c+105,"top cpu ID DCU is_or",-1);
	vcdp->declBit  (c+106,"top cpu ID DCU is_sll",-1);
	vcdp->declBit  (c+107,"top cpu ID DCU is_sr",-1);
	vcdp->declBit  (c+108,"top cpu ID DCU is_slt",-1);
	vcdp->declBit  (c+109,"top cpu ID DCU is_sltu",-1);
	vcdp->declBit  (c+110,"top cpu ID DCU is_wr",-1);
	vcdp->declBit  (c+111,"top cpu ID DCU is_alu",-1);
	vcdp->declBit  (c+112,"top cpu ID DCU is_immop",-1);
	vcdp->declBit  (c+63,"top cpu ID DCU is_ldu",-1);
	vcdp->declBit  (c+9,"top cpu ID DCU is_j",-1);
	vcdp->declBit  (c+28,"top cpu ID DCU is_csri",-1);
	vcdp->declBit  (c+113,"top cpu ID DCU is_word",-1);
	vcdp->declBit  (c+114,"top cpu ID DCU is_byte",-1);
	vcdp->declBit  (c+115,"top cpu ID DCU is_hw",-1);
	vcdp->declBit  (c+269,"top cpu ID ID_EX clk",-1);
	vcdp->declBit  (c+270,"top cpu ID ID_EX rst",-1);
	vcdp->declBit  (c+125,"top cpu ID ID_EX stall",-1);
	vcdp->declBit  (c+270,"top cpu ID ID_EX flush",-1);
	vcdp->declBus  (c+150,"top cpu ID ID_EX id_pc",-1,31,0);
	vcdp->declBus  (c+149,"top cpu ID ID_EX id_instruction",-1,31,0);
	vcdp->declBus  (c+136,"top cpu ID ID_EX id_porta",-1,31,0);
	vcdp->declBus  (c+137,"top cpu ID ID_EX id_portb",-1,31,0);
	vcdp->declBus  (c+15,"top cpu ID ID_EX id_alu_op",-1,3,0);
	vcdp->declBit  (c+14,"top cpu ID ID_EX id_we",-1);
	vcdp->declBus  (c+22,"top cpu ID ID_EX id_mem_flags",-1,5,0);
	vcdp->declBit  (c+23,"top cpu ID ID_EX id_mem_ex_sel",-1);
	vcdp->declBit  (c+25,"top cpu ID ID_EX id_bad_jump_addr",-1);
	vcdp->declBit  (c+27,"top cpu ID ID_EX id_bad_branch_addr",-1);
	vcdp->declBit  (c+205,"top cpu ID ID_EX id_break_op",-1);
	vcdp->declBit  (c+206,"top cpu ID ID_EX id_syscall_op",-1);
	vcdp->declBus  (c+122,"top cpu ID ID_EX id_csr_data",-1,31,0);
	vcdp->declBus  (c+208,"top cpu ID ID_EX id_csr_op",-1,2,0);
	vcdp->declBus  (c+207,"top cpu ID ID_EX id_csr_addr",-1,11,0);
	vcdp->declBus  (c+18,"top cpu ID ID_EX id_waddr",-1,4,0);
	vcdp->declBit  (c+151,"top cpu ID ID_EX id_exc_addr_if",-1);
	vcdp->declBit  (c+152,"top cpu ID ID_EX id_bus_access_fault",-1);
	vcdp->declBus  (c+156,"top cpu ID ID_EX ex_pc",-1,31,0);
	vcdp->declBus  (c+157,"top cpu ID ID_EX ex_instruction",-1,31,0);
	vcdp->declBus  (c+158,"top cpu ID ID_EX ex_porta",-1,31,0);
	vcdp->declBus  (c+159,"top cpu ID ID_EX ex_portb",-1,31,0);
	vcdp->declBus  (c+160,"top cpu ID ID_EX ex_alu_op",-1,3,0);
	vcdp->declBit  (c+162,"top cpu ID ID_EX ex_we",-1);
	vcdp->declBus  (c+163,"top cpu ID ID_EX ex_mem_flags",-1,5,0);
	vcdp->declBit  (c+164,"top cpu ID ID_EX ex_mem_ex_sel",-1);
	vcdp->declBit  (c+165,"top cpu ID ID_EX ex_bad_jump_addr",-1);
	vcdp->declBit  (c+166,"top cpu ID ID_EX ex_bad_branch_addr",-1);
	vcdp->declBit  (c+167,"top cpu ID ID_EX ex_break_op",-1);
	vcdp->declBit  (c+168,"top cpu ID ID_EX ex_syscall_op",-1);
	vcdp->declBus  (c+170,"top cpu ID ID_EX ex_csr_data",-1,31,0);
	vcdp->declBus  (c+171,"top cpu ID ID_EX ex_csr_addr",-1,11,0);
	vcdp->declBus  (c+169,"top cpu ID ID_EX ex_csr_op",-1,2,0);
	vcdp->declBus  (c+161,"top cpu ID ID_EX ex_waddr",-1,4,0);
	vcdp->declBit  (c+172,"top cpu ID ID_EX ex_exc_addr_if",-1);
	vcdp->declBit  (c+173,"top cpu ID ID_EX ex_bus_access_fault",-1);
	vcdp->declBit  (c+269,"top cpu EX clk_i",-1);
	vcdp->declBit  (c+270,"top cpu EX rst_i",-1);
	vcdp->declBit  (c+125,"top cpu EX ex_stall_i",-1);
	vcdp->declBit  (c+127,"top cpu EX ex_flush_i",-1);
	vcdp->declBus  (c+156,"top cpu EX ex_pc_i",-1,31,0);
	vcdp->declBus  (c+157,"top cpu EX ex_instruction_i",-1,31,0);
	vcdp->declBus  (c+158,"top cpu EX ex_port_a_i",-1,31,0);
	vcdp->declBus  (c+159,"top cpu EX ex_port_b_i",-1,31,0);
	vcdp->declBus  (c+160,"top cpu EX ex_alu_op_i",-1,3,0);
	vcdp->declBus  (c+161,"top cpu EX ex_waddr_i",-1,4,0);
	vcdp->declBit  (c+162,"top cpu EX ex_we_i",-1);
	vcdp->declBus  (c+163,"top cpu EX ex_mem_flags_i",-1,5,0);
	vcdp->declBit  (c+164,"top cpu EX ex_mem_ex_sel_i",-1);
	vcdp->declBit  (c+165,"top cpu EX ex_bad_jump_addr_i",-1);
	vcdp->declBit  (c+166,"top cpu EX ex_bad_branch_addr_i",-1);
	vcdp->declBit  (c+167,"top cpu EX ex_break_op_i",-1);
	vcdp->declBit  (c+168,"top cpu EX ex_syscall_op_i",-1);
	vcdp->declBus  (c+170,"top cpu EX ex_csr_data_i",-1,31,0);
	vcdp->declBus  (c+171,"top cpu EX ex_csr_addr_i",-1,11,0);
	vcdp->declBus  (c+169,"top cpu EX ex_csr_op_i",-1,2,0);
	vcdp->declBit  (c+172,"top cpu EX ex_exc_addr_if_i",-1);
	vcdp->declBit  (c+173,"top cpu EX ex_bus_access_fault_i",-1);
	vcdp->declBus  (c+174,"top cpu EX mem_pc_o",-1,31,0);
	vcdp->declBus  (c+175,"top cpu EX mem_instruction_o",-1,31,0);
	vcdp->declBus  (c+3,"top cpu EX ex_fwd_dat_o",-1,31,0);
	vcdp->declBus  (c+189,"top cpu EX mem_store_data_o",-1,31,0);
	vcdp->declBus  (c+176,"top cpu EX mem_result_o",-1,31,0);
	vcdp->declBus  (c+177,"top cpu EX mem_waddr_o",-1,4,0);
	vcdp->declBit  (c+178,"top cpu EX mem_we_o",-1);
	vcdp->declBus  (c+262,"top cpu EX mem_mem_flags_o",-1,5,0);
	vcdp->declBit  (c+179,"top cpu EX mem_mem_ex_sel_o",-1);
	vcdp->declBit  (c+185,"top cpu EX mem_bad_jump_addr_o",-1);
	vcdp->declBit  (c+186,"top cpu EX mem_bad_branch_addr_o",-1);
	vcdp->declBit  (c+187,"top cpu EX mem_break_op_o",-1);
	vcdp->declBit  (c+188,"top cpu EX mem_syscall_op_o",-1);
	vcdp->declBus  (c+180,"top cpu EX mem_csr_data_o",-1,31,0);
	vcdp->declBus  (c+181,"top cpu EX mem_csr_op_o",-1,2,0);
	vcdp->declBus  (c+182,"top cpu EX mem_csr_addr_o",-1,11,0);
	vcdp->declBit  (c+183,"top cpu EX mem_exc_addr_if_o",-1);
	vcdp->declBit  (c+184,"top cpu EX mem_bus_access_fault_o",-1);
	vcdp->declBus  (c+3,"top cpu EX ex_result",-1,31,0);
	vcdp->declBus  (c+159,"top cpu EX ex_store_data",-1,31,0);
	vcdp->declBus  (c+158,"top cpu EX ALU port_a",-1,31,0);
	vcdp->declBus  (c+159,"top cpu EX ALU port_b",-1,31,0);
	vcdp->declBus  (c+160,"top cpu EX ALU alu_op",-1,3,0);
	vcdp->declBus  (c+3,"top cpu EX ALU result",-1,31,0);
	vcdp->declBus  (c+158,"top cpu EX ALU sa",-1,31,0);
	vcdp->declBus  (c+158,"top cpu EX ALU a",-1,31,0);
	vcdp->declBus  (c+159,"top cpu EX ALU sb",-1,31,0);
	vcdp->declBus  (c+159,"top cpu EX ALU b",-1,31,0);
	vcdp->declBit  (c+269,"top cpu EX EX_MEM clk",-1);
	vcdp->declBit  (c+270,"top cpu EX EX_MEM rst",-1);
	vcdp->declBit  (c+125,"top cpu EX EX_MEM stall",-1);
	vcdp->declBit  (c+127,"top cpu EX EX_MEM flush",-1);
	vcdp->declBus  (c+156,"top cpu EX EX_MEM ex_pc",-1,31,0);
	vcdp->declBus  (c+157,"top cpu EX EX_MEM ex_instruction",-1,31,0);
	vcdp->declBus  (c+3,"top cpu EX EX_MEM ex_result",-1,31,0);
	vcdp->declBus  (c+161,"top cpu EX EX_MEM ex_waddr",-1,4,0);
	vcdp->declBit  (c+162,"top cpu EX EX_MEM ex_we",-1);
	vcdp->declBus  (c+163,"top cpu EX EX_MEM ex_mem_flags",-1,5,0);
	vcdp->declBus  (c+159,"top cpu EX EX_MEM ex_store_data",-1,31,0);
	vcdp->declBit  (c+164,"top cpu EX EX_MEM ex_mem_ex_sel",-1);
	vcdp->declBit  (c+165,"top cpu EX EX_MEM ex_bad_jump_addr",-1);
	vcdp->declBit  (c+166,"top cpu EX EX_MEM ex_bad_branch_addr",-1);
	vcdp->declBit  (c+167,"top cpu EX EX_MEM ex_break_op",-1);
	vcdp->declBit  (c+168,"top cpu EX EX_MEM ex_syscall_op",-1);
	vcdp->declBus  (c+170,"top cpu EX EX_MEM ex_csr_data",-1,31,0);
	vcdp->declBus  (c+169,"top cpu EX EX_MEM ex_csr_op",-1,2,0);
	vcdp->declBus  (c+171,"top cpu EX EX_MEM ex_csr_addr",-1,11,0);
	vcdp->declBit  (c+172,"top cpu EX EX_MEM ex_exc_addr_if",-1);
	vcdp->declBit  (c+173,"top cpu EX EX_MEM ex_bus_access_fault",-1);
	vcdp->declBus  (c+174,"top cpu EX EX_MEM mem_pc",-1,31,0);
	vcdp->declBus  (c+175,"top cpu EX EX_MEM mem_instruction",-1,31,0);
	vcdp->declBus  (c+176,"top cpu EX EX_MEM mem_result",-1,31,0);
	vcdp->declBus  (c+177,"top cpu EX EX_MEM mem_waddr",-1,4,0);
	vcdp->declBit  (c+178,"top cpu EX EX_MEM mem_we",-1);
	vcdp->declBus  (c+262,"top cpu EX EX_MEM mem_mem_flags",-1,5,0);
	vcdp->declBus  (c+189,"top cpu EX EX_MEM mem_store_data",-1,31,0);
	vcdp->declBit  (c+179,"top cpu EX EX_MEM mem_mem_ex_sel",-1);
	vcdp->declBit  (c+185,"top cpu EX EX_MEM mem_bad_jump_addr",-1);
	vcdp->declBit  (c+186,"top cpu EX EX_MEM mem_bad_branch_addr",-1);
	vcdp->declBit  (c+187,"top cpu EX EX_MEM mem_break_op",-1);
	vcdp->declBit  (c+188,"top cpu EX EX_MEM mem_syscall_op",-1);
	vcdp->declBus  (c+180,"top cpu EX EX_MEM mem_csr_data",-1,31,0);
	vcdp->declBus  (c+181,"top cpu EX EX_MEM mem_csr_op",-1,2,0);
	vcdp->declBus  (c+182,"top cpu EX EX_MEM mem_csr_addr",-1,11,0);
	vcdp->declBit  (c+183,"top cpu EX EX_MEM mem_exc_addr_if",-1);
	vcdp->declBit  (c+184,"top cpu EX EX_MEM mem_bus_access_fault",-1);
	vcdp->declBit  (c+269,"top cpu MEM clk_i",-1);
	vcdp->declBit  (c+270,"top cpu MEM rst_i",-1);
	vcdp->declBit  (c+125,"top cpu MEM stall",-1);
	vcdp->declBit  (c+270,"top cpu MEM flush",-1);
	vcdp->declBus  (c+130,"top cpu MEM forward_mem_dat_o",-1,31,0);
	vcdp->declBus  (c+174,"top cpu MEM mem_pc_i",-1,31,0);
	vcdp->declBus  (c+175,"top cpu MEM mem_instruction_i",-1,31,0);
	vcdp->declBus  (c+176,"top cpu MEM mem_result_i",-1,31,0);
	vcdp->declBus  (c+177,"top cpu MEM mem_waddr_i",-1,4,0);
	vcdp->declBit  (c+178,"top cpu MEM mem_we_i",-1);
	vcdp->declBus  (c+262,"top cpu MEM mem_mem_flags_i",-1,5,0);
	vcdp->declBit  (c+179,"top cpu MEM mem_mem_ex_sel_i",-1);
	vcdp->declBus  (c+180,"top cpu MEM mem_csr_data_i",-1,31,0);
	vcdp->declBus  (c+182,"top cpu MEM mem_csr_addr_i",-1,11,0);
	vcdp->declBus  (c+181,"top cpu MEM mem_csr_op_i",-1,2,0);
	vcdp->declBit  (c+183,"top cpu MEM mem_exc_addr_if_i",-1);
	vcdp->declBit  (c+184,"top cpu MEM mem_bus_access_fault_i",-1);
	vcdp->declBit  (c+278,"top cpu MEM mem_mbus_access_fault_i",-1);
	vcdp->declBit  (c+185,"top cpu MEM mem_bad_jump_addr_i",-1);
	vcdp->declBit  (c+186,"top cpu MEM mem_bad_branch_addr_i",-1);
	vcdp->declBit  (c+187,"top cpu MEM mem_break_op_i",-1);
	vcdp->declBit  (c+188,"top cpu MEM mem_syscall_op_i",-1);
	vcdp->declBus  (c+132,"top cpu MEM mem_data_i",-1,31,0);
	vcdp->declBit  (c+140,"top cpu MEM mem_cyc_i",-1);
	vcdp->declBit  (c+123,"top cpu MEM mem_ack_i",-1);
	vcdp->declBit  (c+264,"top cpu MEM mem_mread_o",-1);
	vcdp->declBit  (c+263,"top cpu MEM mem_mwrite_o",-1);
	vcdp->declBit  (c+267,"top cpu MEM mem_mbyte_o",-1);
	vcdp->declBit  (c+266,"top cpu MEM mem_mhw_o",-1);
	vcdp->declBit  (c+265,"top cpu MEM mem_mword_o",-1);
	vcdp->declBit  (c+268,"top cpu MEM mem_munsigned_o",-1);
	vcdp->declBit  (c+125,"top cpu MEM mem_request_stall_o",-1);
	vcdp->declBus  (c+190,"top cpu MEM wb_pc_o",-1,31,0);
	vcdp->declBus  (c+191,"top cpu MEM wb_instruction_o",-1,31,0);
	vcdp->declBus  (c+192,"top cpu MEM wb_result_o",-1,31,0);
	vcdp->declBus  (c+153,"top cpu MEM wb_waddr_o",-1,4,0);
	vcdp->declBit  (c+154,"top cpu MEM wb_we_o",-1);
	vcdp->declBus  (c+193,"top cpu MEM wb_csr_data_o",-1,31,0);
	vcdp->declBus  (c+194,"top cpu MEM wb_csr_addr_o",-1,11,0);
	vcdp->declBus  (c+195,"top cpu MEM wb_csr_op_o",-1,2,0);
	vcdp->declBit  (c+196,"top cpu MEM wb_exc_addr_if_o",-1);
	vcdp->declBit  (c+199,"top cpu MEM wb_bad_jump_addr_o",-1);
	vcdp->declBit  (c+200,"top cpu MEM wb_bad_branch_addr_o",-1);
	vcdp->declBit  (c+201,"top cpu MEM wb_break_op_o",-1);
	vcdp->declBit  (c+202,"top cpu MEM wb_syscall_op_o",-1);
	vcdp->declBit  (c+197,"top cpu MEM wb_bus_access_fault_o",-1);
	vcdp->declBit  (c+198,"top cpu MEM wb_mbus_access_fault_o",-1);
	vcdp->declBus  (c+130,"top cpu MEM mem_result",-1,31,0);
	vcdp->declBus  (c+6,"top cpu FWD id_rs1_i",-1,4,0);
	vcdp->declBus  (c+155,"top cpu FWD id_rs2_i",-1,4,0);
	vcdp->declBit  (c+162,"top cpu FWD ex_we_i",-1);
	vcdp->declBit  (c+178,"top cpu FWD mem_we_i",-1);
	vcdp->declBit  (c+154,"top cpu FWD wb_we_i",-1);
	vcdp->declBit  (c+164,"top cpu FWD ls_op_i",-1);
	vcdp->declBus  (c+161,"top cpu FWD ex_rd_i",-1,4,0);
	vcdp->declBus  (c+177,"top cpu FWD mem_rd_i",-1,4,0);
	vcdp->declBus  (c+153,"top cpu FWD wb_rd_i",-1,4,0);
	vcdp->declBus  (c+4,"top cpu FWD fwd_sel_a_o",-1,1,0);
	vcdp->declBus  (c+5,"top cpu FWD fwd_sel_b_o",-1,1,0);
	vcdp->declBit  (c+10,"top cpu FWD ld_dependence_o",-1);
	vcdp->declBit  (c+116,"top cpu FWD ex_fwd_a",-1);
	vcdp->declBit  (c+117,"top cpu FWD ex_fwd_b",-1);
	vcdp->declBit  (c+118,"top cpu FWD mem_fwd_a",-1);
	vcdp->declBit  (c+215,"top cpu FWD mem_fwd_b",-1);
	vcdp->declBit  (c+119,"top cpu FWD wb_fwd_a",-1);
	vcdp->declBit  (c+216,"top cpu FWD wb_fwd_b",-1);
	vcdp->declBit  (c+269,"top cpu LSU clk_i",-1);
	vcdp->declBit  (c+270,"top cpu LSU rst_i",-1);
	vcdp->declBus  (c+145,"top cpu LSU pc",-1,31,0);
	vcdp->declBus  (c+2,"top cpu LSU instruction",-1,31,0);
	vcdp->declBit  (c+133,"top cpu LSU ikill_i",-1);
	vcdp->declBus  (c+2,"top cpu LSU idat_i",-1,31,0);
	vcdp->declBit  (c+148,"top cpu LSU iack_i",-1);
	vcdp->declBit  (c+278,"top cpu LSU ierr_i",-1);
	vcdp->declBus  (c+145,"top cpu LSU iaddr_o",-1,31,0);
	vcdp->declBit  (c+146,"top cpu LSU icyc_o",-1);
	vcdp->declBit  (c+147,"top cpu LSU istb_o",-1);
	vcdp->declBit  (c+272,"top cpu LSU istall_o",-1);
	vcdp->declBus  (c+176,"top cpu LSU maddr_i",-1,31,0);
	vcdp->declBus  (c+189,"top cpu LSU mdat_i",-1,31,0);
	vcdp->declBit  (c+264,"top cpu LSU mread_i",-1);
	vcdp->declBit  (c+263,"top cpu LSU mwrite_i",-1);
	vcdp->declBit  (c+267,"top cpu LSU mbyte_i",-1);
	vcdp->declBit  (c+266,"top cpu LSU mhw_i",-1);
	vcdp->declBit  (c+265,"top cpu LSU mword_i",-1);
	vcdp->declBit  (c+268,"top cpu LSU munsigned_i",-1);
	vcdp->declBus  (c+132,"top cpu LSU data_o",-1,31,0);
	vcdp->declBus  (c+1,"top cpu LSU ddat_i",-1,31,0);
	vcdp->declBit  (c+123,"top cpu LSU dack_i",-1);
	vcdp->declBit  (c+278,"top cpu LSU derr_i",-1);
	vcdp->declBus  (c+139,"top cpu LSU daddr_o",-1,31,0);
	vcdp->declBus  (c+141,"top cpu LSU ddat_o",-1,31,0);
	vcdp->declBus  (c+142,"top cpu LSU dsel_o",-1,3,0);
	vcdp->declBit  (c+140,"top cpu LSU dcyc_o",-1);
	vcdp->declBit  (c+143,"top cpu LSU dstb_o",-1);
	vcdp->declBit  (c+144,"top cpu LSU dwe_o",-1);
	vcdp->declBus  (c+293,"top cpu LSU i_str",-1,1,0);
	vcdp->declBus  (c+294,"top cpu LSU i_ab",-1,1,0);
	vcdp->declBus  (c+295,"top cpu LSU i_kill",-1,1,0);
	vcdp->declBus  (c+293,"top cpu LSU d_str",-1,1,0);
	vcdp->declBus  (c+294,"top cpu LSU d_trx",-1,1,0);
	vcdp->declBus  (c+217,"top cpu LSU rdata",-1,31,0);
	vcdp->declBus  (c+138,"top cpu LSU wdata",-1,31,0);
	vcdp->declBus  (c+128,"top cpu LSU wsel_o",-1,3,0);
	vcdp->declBus  (c+260,"top cpu LSU rsel_o",-1,3,0);
	vcdp->declBit  (c+261,"top cpu LSU runsigned",-1);
	vcdp->declBus  (c+218,"top cpu LSU i_state",-1,1,0);
	vcdp->declBus  (c+219,"top cpu LSU d_state",-1,1,0);
	vcdp->declBit  (c+220,"top cpu LSU kill",-1);
	vcdp->declBit  (c+270,"top cpu CU rst_i",-1);
	vcdp->declBit  (c+131,"top cpu CU branch_flush_req_i",-1);
	vcdp->declBit  (c+9,"top cpu CU jump_flush_req_i",-1);
	vcdp->declBit  (c+272,"top cpu CU if_stall_req_i",-1);
	vcdp->declBit  (c+125,"top cpu CU mem_stall_req_i",-1);
	vcdp->declBit  (c+10,"top cpu CU fwd_stall_req_i",-1);
	vcdp->declBit  (c+133,"top cpu CU if_kill_o",-1);
	vcdp->declBus  (c+129,"top cpu CU if_pc_sel_o",-1,1,0);
	vcdp->declBit  (c+271,"top cpu CU if_stall_o",-1);
	vcdp->declBit  (c+125,"top cpu CU id_stall_o",-1);
	vcdp->declBit  (c+125,"top cpu CU ex_stall_o",-1);
	vcdp->declBit  (c+125,"top cpu CU mem_stall_o",-1);
	vcdp->declBit  (c+124,"top cpu CU if_flush_o",-1);
	vcdp->declBit  (c+270,"top cpu CU id_flush_o",-1);
	vcdp->declBit  (c+270,"top cpu CU ex_flush_o",-1);
	vcdp->declBit  (c+270,"top cpu CU mem_flush_o",-1);
	vcdp->declBit  (c+10,"top cpu CU ex_nop_o",-1);
	vcdp->declBus  (c+275,"top cpu CSR ENABLE_COUNTERS",-1,0,0);
	vcdp->declBus  (c+274,"top cpu CSR RESET_ADDR",-1,31,0);
	vcdp->declBit  (c+269,"top cpu CSR clk_i",-1);
	vcdp->declBit  (c+270,"top cpu CSR rst_i",-1);
	vcdp->declBit  (c+278,"top cpu CSR xint_meip_i",-1);
	vcdp->declBit  (c+278,"top cpu CSR xint_mtip_i",-1);
	vcdp->declBit  (c+278,"top cpu CSR xint_msip_i",-1);
	vcdp->declBus  (c+194,"top cpu CSR csr_addr_i",-1,11,0);
	vcdp->declBus  (c+193,"top cpu CSR csr_dat_i",-1,31,0);
	vcdp->declBus  (c+195,"top cpu CSR csr_op_i",-1,2,0);
	vcdp->declBus  (c+153,"top cpu CSR csr_rd_i",-1,4,0);
	vcdp->declBus  (c+190,"top cpu CSR exception_pc_i",-1,31,0);
	vcdp->declBus  (c+191,"top cpu CSR exception_inst_i",-1,31,0);
	vcdp->declBit  (c+281,"top cpu CSR trap_valid_i",-1);
	vcdp->declBus  (c+282,"top cpu CSR exception_code_i",-1,3,0);
	vcdp->declBit  (c+283,"top cpu CSR interrupt_code_i",-1);
	vcdp->declBit  (c+284,"top cpu CSR instruction_ret_i",-1);
	vcdp->declBit  (c+279,"top cpu CSR inst_fence",-1);
	vcdp->declBit  (c+280,"top cpu CSR inst_xret",-1);
	vcdp->declBit  (c+202,"top cpu CSR xcall",-1);
	vcdp->declBit  (c+201,"top cpu CSR xbreak",-1);
	vcdp->declBus  (c+11,"top cpu CSR csr_dat_o",-1,31,0);
	vcdp->declBus  (c+285,"top cpu CSR HART_ID",-1,31,0);
	vcdp->declBus  (c+296,"top cpu CSR MHARTID",-1,11,0);
	vcdp->declBus  (c+297,"top cpu CSR MVENDORID",-1,11,0);
	vcdp->declBus  (c+298,"top cpu CSR MARCHID",-1,11,0);
	vcdp->declBus  (c+296,"top cpu CSR MIMPID",-1,11,0);
	vcdp->declBus  (c+299,"top cpu CSR MSTATUS",-1,11,0);
	vcdp->declBus  (c+300,"top cpu CSR MISA",-1,11,0);
	vcdp->declBus  (c+301,"top cpu CSR MEDELEG",-1,11,0);
	vcdp->declBus  (c+302,"top cpu CSR MIDELEG",-1,11,0);
	vcdp->declBus  (c+303,"top cpu CSR MIE",-1,11,0);
	vcdp->declBus  (c+304,"top cpu CSR MTVEC",-1,11,0);
	vcdp->declBus  (c+305,"top cpu CSR MCOUNTEREN",-1,11,0);
	vcdp->declBus  (c+306,"top cpu CSR MSCRATCH",-1,11,0);
	vcdp->declBus  (c+307,"top cpu CSR MEPC",-1,11,0);
	vcdp->declBus  (c+308,"top cpu CSR MCAUSE",-1,11,0);
	vcdp->declBus  (c+309,"top cpu CSR MTVAL",-1,11,0);
	vcdp->declBus  (c+310,"top cpu CSR MIP",-1,11,0);
	vcdp->declBus  (c+311,"top cpu CSR MCYCLE",-1,11,0);
	vcdp->declBus  (c+312,"top cpu CSR MINSTRET",-1,11,0);
	vcdp->declBus  (c+313,"top cpu CSR MCYCLEH",-1,11,0);
	vcdp->declBus  (c+314,"top cpu CSR MINSTRETH",-1,11,0);
	vcdp->declBus  (c+315,"top cpu CSR INST_ADDR_MISALIGNED",-1,3,0);
	vcdp->declBus  (c+316,"top cpu CSR INST_ACCESS_FAULT",-1,3,0);
	vcdp->declBus  (c+317,"top cpu CSR ILLEGAL_INST",-1,3,0);
	vcdp->declBus  (c+318,"top cpu CSR BREAKPOINT",-1,3,0);
	vcdp->declBus  (c+319,"top cpu CSR LOAD_ADDR_MISALIGNED",-1,3,0);
	vcdp->declBus  (c+320,"top cpu CSR LOAD_ACCESS_FAULT",-1,3,0);
	vcdp->declBus  (c+321,"top cpu CSR STORE_ADDR_MISALIGNED",-1,3,0);
	vcdp->declBus  (c+322,"top cpu CSR STORE_ACCESS_FAULT",-1,3,0);
	vcdp->declBus  (c+323,"top cpu CSR MCALL",-1,3,0);
	vcdp->declBus  (c+318,"top cpu CSR I_SOFTWARE",-1,3,0);
	vcdp->declBus  (c+322,"top cpu CSR I_TIMER",-1,3,0);
	vcdp->declBus  (c+323,"top cpu CSR I_EXTERNAL",-1,3,0);
	vcdp->declBus  (c+221,"top cpu CSR csr_wdata",-1,31,0);
	vcdp->declBus  (c+222,"top cpu CSR mstatus",-1,31,0);
	vcdp->declBus  (c+223,"top cpu CSR mie",-1,31,0);
	vcdp->declBus  (c+224,"top cpu CSR mtvec",-1,31,0);
	vcdp->declBus  (c+225,"top cpu CSR mscratch",-1,31,0);
	vcdp->declBus  (c+226,"top cpu CSR mepc",-1,31,0);
	vcdp->declBus  (c+227,"top cpu CSR mcause",-1,31,0);
	vcdp->declBus  (c+228,"top cpu CSR mtval",-1,31,0);
	vcdp->declBus  (c+273,"top cpu CSR mip",-1,31,0);
	vcdp->declQuad (c+229,"top cpu CSR mcycle",-1,63,0);
	vcdp->declQuad (c+231,"top cpu CSR minstret",-1,63,0);
	vcdp->declBit  (c+233,"top cpu CSR wen",-1);
	vcdp->declBit  (c+324,"top cpu CSR undef_register",-1);
	vcdp->declBit  (c+234,"top cpu CSR mstatus_mpie",-1);
	vcdp->declBit  (c+235,"top cpu CSR mstatus_mie",-1);
	vcdp->declBit  (c+236,"top cpu CSR mie_meie",-1);
	vcdp->declBit  (c+237,"top cpu CSR mie_mtie",-1);
	vcdp->declBit  (c+238,"top cpu CSR mie_msie",-1);
	vcdp->declBit  (c+239,"top cpu CSR mcause_int",-1);
	vcdp->declBus  (c+240,"top cpu CSR mcause_exc",-1,3,0);
	vcdp->declBit  (c+241,"top cpu CSR is_misa",-1);
	vcdp->declBit  (c+242,"top cpu CSR is_mhartid",-1);
	vcdp->declBit  (c+243,"top cpu CSR is_mvendorid",-1);
	vcdp->declBit  (c+244,"top cpu CSR is_marchid",-1);
	vcdp->declBit  (c+242,"top cpu CSR is_mimpid",-1);
	vcdp->declBit  (c+245,"top cpu CSR is_mstatus",-1);
	vcdp->declBit  (c+246,"top cpu CSR is_mie",-1);
	vcdp->declBit  (c+247,"top cpu CSR is_mtvec",-1);
	vcdp->declBit  (c+248,"top cpu CSR is_mepc",-1);
	vcdp->declBit  (c+249,"top cpu CSR is_mcause",-1);
	vcdp->declBit  (c+250,"top cpu CSR is_mtval",-1);
	vcdp->declBit  (c+251,"top cpu CSR is_mip",-1);
	vcdp->declBit  (c+252,"top cpu CSR is_mcycle",-1);
	vcdp->declBit  (c+253,"top cpu CSR is_minstret",-1);
	vcdp->declBit  (c+254,"top cpu CSR is_mcycleh",-1);
	vcdp->declBit  (c+255,"top cpu CSR is_minstreth",-1);
	vcdp->declBit  (c+325,"top cpu CSR is_mscratch",-1);
	vcdp->declBus  (c+326,"top memory ADDR_WIDTH",-1,31,0);
	vcdp->declBus  (c+274,"top memory BASE_ADDR",-1,31,0);
	vcdp->declBus  (c+145,"top memory iwbs_addr_i",-1,31,0);
	vcdp->declBit  (c+146,"top memory iwbs_cyc_i",-1);
	vcdp->declBit  (c+147,"top memory iwbs_stb_i",-1);
	vcdp->declBus  (c+2,"top memory iwbs_dat_o",-1,31,0);
	vcdp->declBit  (c+148,"top memory iwbs_ack_o",-1);
	vcdp->declBus  (c+139,"top memory dwbs_addr_i",-1,31,0);
	vcdp->declBus  (c+141,"top memory dwbs_dat_i",-1,31,0);
	vcdp->declBus  (c+142,"top memory dwbs_sel_i",-1,3,0);
	vcdp->declBit  (c+140,"top memory dwbs_cyc_i",-1);
	vcdp->declBit  (c+143,"top memory dwbs_stb_i",-1);
	vcdp->declBit  (c+144,"top memory dwbs_we_i",-1);
	vcdp->declBus  (c+1,"top memory dwbs_dat_o",-1,31,0);
	vcdp->declBit  (c+123,"top memory dwbs_ack_o",-1);
	vcdp->declBus  (c+327,"top memory BYTES",-1,31,0);
	// Tracing: top memory mem // Ignored: Wide memory > --trace-max-array ents at tests/verilator/ram.v:51
	vcdp->declBus  (c+256,"top memory i_addr",-1,23,0);
	vcdp->declBus  (c+257,"top memory d_addr",-1,23,0);
	vcdp->declBit  (c+258,"top memory i_access",-1);
	vcdp->declBit  (c+259,"top memory d_access",-1);
    }
}

void Vtop::traceFullThis__1(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->fullBus  (c+1,(vlTOPp->top__DOT__dwbm_dat_i),32);
	vcdp->fullBus  (c+2,(vlTOPp->top__DOT__iwbm_dat),32);
	vcdp->fullBus  (c+3,(vlTOPp->top__DOT__cpu__DOT__EX__DOT__ex_result),32);
	vcdp->fullBus  (c+4,(vlTOPp->top__DOT__cpu__DOT__forward_a_sel),2);
	vcdp->fullBus  (c+5,(vlTOPp->top__DOT__cpu__DOT__forward_b_sel),2);
	vcdp->fullBus  (c+6,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__rs1),5);
	vcdp->fullBus  (c+7,((0xfffffffeU & vlTOPp->top__DOT__cpu__DOT__ID__DOT__pc_jump)),32);
	vcdp->fullBus  (c+8,(vlTOPp->top__DOT__cpu__DOT__pc_branch_addr),32);
	vcdp->fullBit  (c+9,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_j));
	vcdp->fullBit  (c+10,(vlTOPp->top__DOT__cpu__DOT__ld_dependence));
	vcdp->fullBus  (c+11,(vlTOPp->top__DOT__cpu__DOT__csr_data_o),32);
	vcdp->fullBus  (c+12,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__drs1),32);
	vcdp->fullBus  (c+13,(((0U == (0x1fU & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
						>> 0x14U)))
			        ? 0U : vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file
			       [(0x1fU & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
					  >> 0x14U))])),32);
	vcdp->fullBit  (c+14,(((0U != (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__waddr)) 
			       & (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_wr))));
	vcdp->fullBus  (c+15,((((((((((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_add) 
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
					       ? 3U
					       : ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_xor)
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
			        : ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_sltu)
				    ? 9U : 0xfU))),4);
	vcdp->fullBus  (c+16,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__comparator_op),3);
	vcdp->fullBus  (c+17,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__imm),32);
	vcdp->fullBus  (c+18,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__waddr),5);
	vcdp->fullBit  (c+19,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_immop));
	vcdp->fullBit  (c+20,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__auipc));
	vcdp->fullBit  (c+21,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__jalr));
	vcdp->fullBus  (c+22,((((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_st) 
				<< 5U) | (((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_ld) 
					   << 4U) | 
					  (((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_word) 
					    << 3U) 
					   | (((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_hw) 
					       << 2U) 
					      | (((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_byte) 
						  << 1U) 
						 | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_ldu))))))),6);
	vcdp->fullBit  (c+23,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_ld));
	vcdp->fullBus  (c+24,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__pc_jump),32);
	vcdp->fullBit  (c+25,(((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_j) 
			       & (0U != (2U & vlTOPp->top__DOT__cpu__DOT__ID__DOT__pc_jump)))));
	vcdp->fullBit  (c+26,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_b));
	vcdp->fullBit  (c+27,(((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_b) 
			       & (0U != (3U & vlTOPp->top__DOT__cpu__DOT__pc_branch_addr)))));
	vcdp->fullBit  (c+28,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_csri));
	vcdp->fullBus  (c+29,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[0]),32);
	vcdp->fullBus  (c+30,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[1]),32);
	vcdp->fullBus  (c+31,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[2]),32);
	vcdp->fullBus  (c+32,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[3]),32);
	vcdp->fullBus  (c+33,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[4]),32);
	vcdp->fullBus  (c+34,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[5]),32);
	vcdp->fullBus  (c+35,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[6]),32);
	vcdp->fullBus  (c+36,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[7]),32);
	vcdp->fullBus  (c+37,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[8]),32);
	vcdp->fullBus  (c+38,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[9]),32);
	vcdp->fullBus  (c+39,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[10]),32);
	vcdp->fullBus  (c+40,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[11]),32);
	vcdp->fullBus  (c+41,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[12]),32);
	vcdp->fullBus  (c+42,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[13]),32);
	vcdp->fullBus  (c+43,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[14]),32);
	vcdp->fullBus  (c+44,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[15]),32);
	vcdp->fullBus  (c+45,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[16]),32);
	vcdp->fullBus  (c+46,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[17]),32);
	vcdp->fullBus  (c+47,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[18]),32);
	vcdp->fullBus  (c+48,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[19]),32);
	vcdp->fullBus  (c+49,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[20]),32);
	vcdp->fullBus  (c+50,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[21]),32);
	vcdp->fullBus  (c+51,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[22]),32);
	vcdp->fullBus  (c+52,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[23]),32);
	vcdp->fullBus  (c+53,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[24]),32);
	vcdp->fullBus  (c+54,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[25]),32);
	vcdp->fullBus  (c+55,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[26]),32);
	vcdp->fullBus  (c+56,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[27]),32);
	vcdp->fullBus  (c+57,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[28]),32);
	vcdp->fullBus  (c+58,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[29]),32);
	vcdp->fullBus  (c+59,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[30]),32);
	vcdp->fullBus  (c+60,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[31]),32);
	vcdp->fullBus  (c+61,((((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_word) 
				<< 2U) | (((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_hw) 
					   << 1U) | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_byte)))),3);
	vcdp->fullBit  (c+62,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_st));
	vcdp->fullBit  (c+63,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_ldu));
	vcdp->fullBit  (c+64,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__lui));
	vcdp->fullBit  (c+65,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__auipc));
	vcdp->fullBit  (c+66,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__jal));
	vcdp->fullBit  (c+67,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__beq));
	vcdp->fullBit  (c+68,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__bne));
	vcdp->fullBit  (c+69,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__blt));
	vcdp->fullBit  (c+70,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__bge));
	vcdp->fullBit  (c+71,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__bltu));
	vcdp->fullBit  (c+72,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__bgeu));
	vcdp->fullBit  (c+73,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__lb));
	vcdp->fullBit  (c+74,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__lh));
	vcdp->fullBit  (c+75,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__lw));
	vcdp->fullBit  (c+76,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__lbu));
	vcdp->fullBit  (c+77,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__lhu));
	vcdp->fullBit  (c+78,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sb));
	vcdp->fullBit  (c+79,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sh));
	vcdp->fullBit  (c+80,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sw));
	vcdp->fullBit  (c+81,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__addi));
	vcdp->fullBit  (c+82,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__slti));
	vcdp->fullBit  (c+83,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sltiu));
	vcdp->fullBit  (c+84,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__xori));
	vcdp->fullBit  (c+85,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__ori));
	vcdp->fullBit  (c+86,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__andi));
	vcdp->fullBit  (c+87,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__slli));
	vcdp->fullBit  (c+88,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__srli));
	vcdp->fullBit  (c+89,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__srai));
	vcdp->fullBit  (c+90,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__add));
	vcdp->fullBit  (c+91,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sub));
	vcdp->fullBit  (c+92,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sll));
	vcdp->fullBit  (c+93,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__slt));
	vcdp->fullBit  (c+94,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sltu));
	vcdp->fullBit  (c+95,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__srl));
	vcdp->fullBit  (c+96,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sra));
	vcdp->fullBit  (c+97,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__rwi));
	vcdp->fullBit  (c+98,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__rsi));
	vcdp->fullBit  (c+99,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__rci));
	vcdp->fullBit  (c+100,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_imm));
	vcdp->fullBit  (c+101,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_add));
	vcdp->fullBit  (c+102,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_sub));
	vcdp->fullBit  (c+103,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_and));
	vcdp->fullBit  (c+104,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_xor));
	vcdp->fullBit  (c+105,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_or));
	vcdp->fullBit  (c+106,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_sll));
	vcdp->fullBit  (c+107,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_sr));
	vcdp->fullBit  (c+108,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_slt));
	vcdp->fullBit  (c+109,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_sltu));
	vcdp->fullBit  (c+110,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_wr));
	vcdp->fullBit  (c+111,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_alu));
	vcdp->fullBit  (c+112,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_immop));
	vcdp->fullBit  (c+113,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_word));
	vcdp->fullBit  (c+114,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_byte));
	vcdp->fullBit  (c+115,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_hw));
	vcdp->fullBit  (c+116,(vlTOPp->top__DOT__cpu__DOT__FWD__DOT__ex_fwd_a));
	vcdp->fullBit  (c+117,(vlTOPp->top__DOT__cpu__DOT__FWD__DOT__ex_fwd_b));
	vcdp->fullBit  (c+118,((((IData)(vlTOPp->top__DOT__cpu__DOT__mem_waddr) 
				 == (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__rs1)) 
				& (IData)(vlTOPp->top__DOT__cpu__DOT__mem_we))));
	vcdp->fullBit  (c+119,((((IData)(vlTOPp->top__DOT__cpu__DOT__wb_waddr) 
				 == (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__rs1)) 
				& (IData)(vlTOPp->top__DOT__cpu__DOT__wb_we))));
	vcdp->fullBus  (c+120,(((2U & (IData)(vlTOPp->top__DOT__cpu__DOT__if_pc_sel))
				 ? ((1U & (IData)(vlTOPp->top__DOT__cpu__DOT__if_pc_sel))
				     ? 0U : (0xfffffffeU 
					     & vlTOPp->top__DOT__cpu__DOT__ID__DOT__pc_jump))
				 : ((1U & (IData)(vlTOPp->top__DOT__cpu__DOT__if_pc_sel))
				     ? vlTOPp->top__DOT__cpu__DOT__pc_branch_addr
				     : ((IData)(4U) 
					+ vlTOPp->top__DOT__cpu__DOT__if_pc)))),32);
	vcdp->fullBit  (c+121,(((4U & (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__comparator_op))
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
	vcdp->fullBus  (c+122,(((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_csri)
				 ? vlTOPp->top__DOT__cpu__DOT__ID__DOT__port_b
				 : vlTOPp->top__DOT__cpu__DOT__ID__DOT__port_a)),32);
	vcdp->fullBit  (c+123,(vlTOPp->top__DOT__dwbm_ack));
	vcdp->fullBit  (c+124,(vlTOPp->top__DOT__cpu__DOT__if_flush));
	vcdp->fullBit  (c+125,(vlTOPp->top__DOT__cpu__DOT__mem_stall_req));
	vcdp->fullBit  (c+126,(vlTOPp->top__DOT__cpu__DOT____Vcellinp__IF__if_stall));
	vcdp->fullBit  (c+127,(vlTOPp->top__DOT__cpu__DOT____Vcellinp__EX__ex_flush_i));
	vcdp->fullBus  (c+128,(vlTOPp->top__DOT__cpu__DOT__LSU__DOT__wsel_o),4);
	vcdp->fullBus  (c+129,(vlTOPp->top__DOT__cpu__DOT__if_pc_sel),2);
	vcdp->fullBus  (c+130,(vlTOPp->top__DOT__cpu__DOT__MEM__DOT__mem_result),32);
	vcdp->fullBit  (c+131,(vlTOPp->top__DOT__cpu__DOT__take_branch));
	vcdp->fullBus  (c+132,(vlTOPp->top__DOT__cpu__DOT__mem_load_data),32);
	vcdp->fullBit  (c+133,(vlTOPp->top__DOT__cpu__DOT__if_kill));
	vcdp->fullBus  (c+134,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__muxa_i),32);
	vcdp->fullBus  (c+135,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__muxb_i),32);
	vcdp->fullBus  (c+136,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__port_a),32);
	vcdp->fullBus  (c+137,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__port_b),32);
	vcdp->fullBus  (c+138,(vlTOPp->top__DOT__cpu__DOT__LSU__DOT__wdata),32);
	vcdp->fullBus  (c+139,(vlTOPp->top__DOT__dwbm_addr),32);
	vcdp->fullBit  (c+140,(vlTOPp->top__DOT__dwbm_cyc));
	vcdp->fullBus  (c+141,(vlTOPp->top__DOT__dwbm_dat_o),32);
	vcdp->fullBus  (c+142,(vlTOPp->top__DOT__dwbm_sel),4);
	vcdp->fullBit  (c+143,(vlTOPp->top__DOT__dwbm_stb));
	vcdp->fullBit  (c+144,(vlTOPp->top__DOT__dwbm_we));
	vcdp->fullBus  (c+145,(vlTOPp->top__DOT__cpu__DOT__if_pc),32);
	vcdp->fullBit  (c+146,(vlTOPp->top__DOT__iwbm_cyc));
	vcdp->fullBit  (c+147,(vlTOPp->top__DOT__iwbm_stb));
	vcdp->fullBit  (c+148,((((IData)(vlTOPp->top__DOT__iwbm_cyc) 
				 & (IData)(vlTOPp->top__DOT__iwbm_stb)) 
				& (0x80U == (0xffU 
					     & (vlTOPp->top__DOT__cpu__DOT__if_pc 
						>> 0x18U))))));
	vcdp->fullBus  (c+149,(vlTOPp->top__DOT__cpu__DOT__id_instruction),32);
	vcdp->fullBus  (c+150,(vlTOPp->top__DOT__cpu__DOT__id_pc),32);
	vcdp->fullBit  (c+151,(vlTOPp->top__DOT__cpu__DOT__id_exc_addr_if));
	vcdp->fullBit  (c+152,(vlTOPp->top__DOT__cpu__DOT__id_inst_access_fault));
	vcdp->fullBus  (c+153,(vlTOPp->top__DOT__cpu__DOT__wb_waddr),5);
	vcdp->fullBit  (c+154,(vlTOPp->top__DOT__cpu__DOT__wb_we));
	vcdp->fullBus  (c+155,((0x1fU & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
					 >> 0x14U))),5);
	vcdp->fullBus  (c+156,(vlTOPp->top__DOT__cpu__DOT__ex_pc),32);
	vcdp->fullBus  (c+157,(vlTOPp->top__DOT__cpu__DOT__ex_instruction),32);
	vcdp->fullBus  (c+158,(vlTOPp->top__DOT__cpu__DOT__ex_port_a),32);
	vcdp->fullBus  (c+159,(vlTOPp->top__DOT__cpu__DOT__ex_port_b),32);
	vcdp->fullBus  (c+160,(vlTOPp->top__DOT__cpu__DOT__ex_alu_op),4);
	vcdp->fullBus  (c+161,(vlTOPp->top__DOT__cpu__DOT__ex_waddr),5);
	vcdp->fullBit  (c+162,(vlTOPp->top__DOT__cpu__DOT__ex_we));
	vcdp->fullBus  (c+163,(vlTOPp->top__DOT__cpu__DOT__ex_mem_flags),6);
	vcdp->fullBit  (c+164,(vlTOPp->top__DOT__cpu__DOT__ex_mem_ex_sel));
	vcdp->fullBit  (c+165,(vlTOPp->top__DOT__cpu__DOT__ex_bad_jump_addr));
	vcdp->fullBit  (c+166,(vlTOPp->top__DOT__cpu__DOT__ex_bad_branch_addr));
	vcdp->fullBit  (c+167,(vlTOPp->top__DOT__cpu__DOT__ex_break_op));
	vcdp->fullBit  (c+168,(vlTOPp->top__DOT__cpu__DOT__ex_syscall_op));
	vcdp->fullBus  (c+169,(vlTOPp->top__DOT__cpu__DOT__ex_csr_op),3);
	vcdp->fullBus  (c+170,(vlTOPp->top__DOT__cpu__DOT__ex_csr_data),32);
	vcdp->fullBus  (c+171,(vlTOPp->top__DOT__cpu__DOT__ex_csr_addr),12);
	vcdp->fullBit  (c+172,(vlTOPp->top__DOT__cpu__DOT__ex_exc_addr_if));
	vcdp->fullBit  (c+173,(vlTOPp->top__DOT__cpu__DOT__ex_inst_access_fault));
	vcdp->fullBus  (c+174,(vlTOPp->top__DOT__cpu__DOT__mem_pc),32);
	vcdp->fullBus  (c+175,(vlTOPp->top__DOT__cpu__DOT__mem_instruction),32);
	vcdp->fullBus  (c+176,(vlTOPp->top__DOT__cpu__DOT__mem_result),32);
	vcdp->fullBus  (c+177,(vlTOPp->top__DOT__cpu__DOT__mem_waddr),5);
	vcdp->fullBit  (c+178,(vlTOPp->top__DOT__cpu__DOT__mem_we));
	vcdp->fullBit  (c+179,(vlTOPp->top__DOT__cpu__DOT__mem_mem_ex_sel));
	vcdp->fullBus  (c+180,(vlTOPp->top__DOT__cpu__DOT__mem_csr_data),32);
	vcdp->fullBus  (c+181,(vlTOPp->top__DOT__cpu__DOT__mem_csr_op),3);
	vcdp->fullBus  (c+182,(vlTOPp->top__DOT__cpu__DOT__mem_csr_addr),12);
	vcdp->fullBit  (c+183,(vlTOPp->top__DOT__cpu__DOT__mem_exc_addr_if));
	vcdp->fullBit  (c+184,(vlTOPp->top__DOT__cpu__DOT__mem_inst_access_fault));
	vcdp->fullBit  (c+185,(vlTOPp->top__DOT__cpu__DOT__mem_bad_jump_addr));
	vcdp->fullBit  (c+186,(vlTOPp->top__DOT__cpu__DOT__mem_bad_branch_addr));
	vcdp->fullBit  (c+187,(vlTOPp->top__DOT__cpu__DOT__mem_break_op));
	vcdp->fullBit  (c+188,(vlTOPp->top__DOT__cpu__DOT__mem_syscall_op));
	vcdp->fullBus  (c+189,(vlTOPp->top__DOT__cpu__DOT__mem_store_data),32);
	vcdp->fullBus  (c+190,(vlTOPp->top__DOT__cpu__DOT__wb_pc),32);
	vcdp->fullBus  (c+191,(vlTOPp->top__DOT__cpu__DOT__wb_instruction),32);
	vcdp->fullBus  (c+192,(vlTOPp->top__DOT__cpu__DOT__wb_result),32);
	vcdp->fullBus  (c+193,(vlTOPp->top__DOT__cpu__DOT__wb_csr_data),32);
	vcdp->fullBus  (c+194,(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr),12);
	vcdp->fullBus  (c+195,(vlTOPp->top__DOT__cpu__DOT__wb_csr_op),3);
	vcdp->fullBit  (c+196,(vlTOPp->top__DOT__cpu__DOT__wb_exc_addr_if));
	vcdp->fullBit  (c+197,(vlTOPp->top__DOT__cpu__DOT__wb_inst_access_fault));
	vcdp->fullBit  (c+198,(vlTOPp->top__DOT__cpu__DOT__wb_mem_access_fault));
	vcdp->fullBit  (c+199,(vlTOPp->top__DOT__cpu__DOT__wb_bad_jump_addr));
	vcdp->fullBit  (c+200,(vlTOPp->top__DOT__cpu__DOT__wb_bad_branch_addr));
	vcdp->fullBit  (c+201,(vlTOPp->top__DOT__cpu__DOT__wb_break_op));
	vcdp->fullBit  (c+202,(vlTOPp->top__DOT__cpu__DOT__wb_syscall_op));
	vcdp->fullBus  (c+203,(((IData)(4U) + vlTOPp->top__DOT__cpu__DOT__if_pc)),32);
	vcdp->fullBit  (c+204,((0U == (3U & vlTOPp->top__DOT__cpu__DOT__if_pc))));
	vcdp->fullBit  (c+205,(((0x73U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
				& (0x2000U == (0x1ffffffU 
					       & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
						  >> 7U))))));
	vcdp->fullBit  (c+206,(((0x73U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
				& (0U == (0x1ffffffU 
					  & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
					     >> 7U))))));
	vcdp->fullBus  (c+207,((0xfffU & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
					  >> 0x14U))),12);
	vcdp->fullBus  (c+208,(((((0x73U == (0x7fU 
					     & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
				  & (3U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
						  >> 0xcU)))) 
				 << 2U) | ((((0x73U 
					      == (0x7fU 
						  & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
					     & (2U 
						== 
						(7U 
						 & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
						    >> 0xcU)))) 
					    << 1U) 
					   | ((0x73U 
					       == (0x7fU 
						   & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
					      & (1U 
						 == 
						 (7U 
						  & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
						     >> 0xcU))))))),3);
	vcdp->fullBus  (c+209,((0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)),7);
	vcdp->fullBus  (c+210,((7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
				      >> 0xcU))),3);
	vcdp->fullBus  (c+211,((0x7fU & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
					 >> 0x19U))),7);
	vcdp->fullBit  (c+212,(((0x73U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
				& (1U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
						>> 0xcU))))));
	vcdp->fullBit  (c+213,(((0x73U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
				& (2U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
						>> 0xcU))))));
	vcdp->fullBit  (c+214,(((0x73U == (0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)) 
				& (3U == (7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
						>> 0xcU))))));
	vcdp->fullBit  (c+215,((((IData)(vlTOPp->top__DOT__cpu__DOT__mem_waddr) 
				 == (0x1fU & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
					      >> 0x14U))) 
				& (IData)(vlTOPp->top__DOT__cpu__DOT__mem_we))));
	vcdp->fullBit  (c+216,((((IData)(vlTOPp->top__DOT__cpu__DOT__wb_waddr) 
				 == (0x1fU & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
					      >> 0x14U))) 
				& (IData)(vlTOPp->top__DOT__cpu__DOT__wb_we))));
	vcdp->fullBus  (c+217,(vlTOPp->top__DOT__cpu__DOT__LSU__DOT__rdata),32);
	vcdp->fullBus  (c+218,(vlTOPp->top__DOT__cpu__DOT__LSU__DOT__i_state),2);
	vcdp->fullBus  (c+219,(vlTOPp->top__DOT__cpu__DOT__LSU__DOT__d_state),2);
	vcdp->fullBit  (c+220,(vlTOPp->top__DOT__cpu__DOT__LSU__DOT__kill));
	vcdp->fullBus  (c+221,(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__csr_wdata),32);
	vcdp->fullBus  (c+222,((0x1800U | (((IData)(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mstatus_mpie) 
					    << 7U) 
					   | ((IData)(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mstatus_mie) 
					      << 3U)))),32);
	vcdp->fullBus  (c+223,((((IData)(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mie_meie) 
				 << 0xbU) | (((IData)(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mie_mtie) 
					      << 7U) 
					     | ((IData)(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mie_msie) 
						<< 3U)))),32);
	vcdp->fullBus  (c+224,(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mtvec),32);
	vcdp->fullBus  (c+225,(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mscratch),32);
	vcdp->fullBus  (c+226,(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mepc),32);
	vcdp->fullBus  (c+227,((((IData)(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mcause_int) 
				 << 0x1fU) | (IData)(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mcause_exc))),32);
	vcdp->fullBus  (c+228,(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mtval),32);
	vcdp->fullQuad (c+229,(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mcycle),64);
	vcdp->fullQuad (c+231,(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__minstret),64);
	vcdp->fullBit  (c+233,((0U != (IData)(vlTOPp->top__DOT__cpu__DOT__wb_waddr))));
	vcdp->fullBit  (c+234,(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mstatus_mpie));
	vcdp->fullBit  (c+235,(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mstatus_mie));
	vcdp->fullBit  (c+236,(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mie_meie));
	vcdp->fullBit  (c+237,(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mie_mtie));
	vcdp->fullBit  (c+238,(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mie_msie));
	vcdp->fullBit  (c+239,(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mcause_int));
	vcdp->fullBus  (c+240,(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mcause_exc),4);
	vcdp->fullBit  (c+241,((0x301U == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))));
	vcdp->fullBit  (c+242,((0xf14U == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))));
	vcdp->fullBit  (c+243,((0xf11U == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))));
	vcdp->fullBit  (c+244,((0xf12U == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))));
	vcdp->fullBit  (c+245,((0x300U == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))));
	vcdp->fullBit  (c+246,((0x304U == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))));
	vcdp->fullBit  (c+247,((0x340U == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))));
	vcdp->fullBit  (c+248,((0x341U == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))));
	vcdp->fullBit  (c+249,((0x342U == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))));
	vcdp->fullBit  (c+250,((0x343U == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))));
	vcdp->fullBit  (c+251,((0x344U == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))));
	vcdp->fullBit  (c+252,((0xb00U == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))));
	vcdp->fullBit  (c+253,((0xb02U == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))));
	vcdp->fullBit  (c+254,((0xb80U == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))));
	vcdp->fullBit  (c+255,((0xb82U == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))));
	vcdp->fullBus  (c+256,((0xfffffcU & vlTOPp->top__DOT__cpu__DOT__if_pc)),24);
	vcdp->fullBus  (c+257,((0xfffffcU & vlTOPp->top__DOT__dwbm_addr)),24);
	vcdp->fullBit  (c+258,((0x80U == (0xffU & (vlTOPp->top__DOT__cpu__DOT__if_pc 
						   >> 0x18U)))));
	vcdp->fullBit  (c+259,((0x80U == (0xffU & (vlTOPp->top__DOT__dwbm_addr 
						   >> 0x18U)))));
	vcdp->fullBus  (c+260,(vlTOPp->top__DOT__cpu__DOT__LSU__DOT__rsel_o),4);
	vcdp->fullBit  (c+261,(vlTOPp->top__DOT__cpu__DOT__LSU__DOT__runsigned));
	vcdp->fullBus  (c+262,(vlTOPp->top__DOT__cpu__DOT__mem_mem_flags),6);
	vcdp->fullBit  (c+263,((1U & (IData)(vlTOPp->top__DOT__cpu__DOT__mem_mem_flags))));
	vcdp->fullBit  (c+264,((1U & ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_mem_flags) 
				      >> 1U))));
	vcdp->fullBit  (c+265,((1U & ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_mem_flags) 
				      >> 2U))));
	vcdp->fullBit  (c+266,((1U & ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_mem_flags) 
				      >> 3U))));
	vcdp->fullBit  (c+267,((1U & ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_mem_flags) 
				      >> 4U))));
	vcdp->fullBit  (c+268,((1U & ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_mem_flags) 
				      >> 5U))));
	vcdp->fullBit  (c+269,(vlTOPp->clk_i));
	vcdp->fullBit  (c+270,(vlTOPp->rst_i));
	vcdp->fullBit  (c+271,(((((~ (IData)(vlTOPp->rst_i)) 
				  & (IData)(vlTOPp->top__DOT__cpu__DOT__LSU__DOT__kill)) 
				 | (IData)(vlTOPp->top__DOT__cpu__DOT__mem_stall_req)) 
				| (IData)(vlTOPp->top__DOT__cpu__DOT__ld_dependence))));
	vcdp->fullBit  (c+272,(((~ (IData)(vlTOPp->rst_i)) 
				& (IData)(vlTOPp->top__DOT__cpu__DOT__LSU__DOT__kill))));
	vcdp->fullBus  (c+273,(0U),32);
	vcdp->fullBus  (c+274,(0x80000000U),32);
	vcdp->fullBit  (c+275,(1U));
	vcdp->fullBus  (c+276,(0x1000000U),32);
	vcdp->fullBit  (c+277,(0U));
	vcdp->fullBit  (c+278,(0U));
	vcdp->fullBit  (c+279,(vlTOPp->top__DOT__cpu__DOT__wb_fence_op));
	vcdp->fullBit  (c+280,(vlTOPp->top__DOT__cpu__DOT__wb_ret_op));
	vcdp->fullBit  (c+281,(vlTOPp->top__DOT__cpu__DOT__trap_valid));
	vcdp->fullBus  (c+282,(vlTOPp->top__DOT__cpu__DOT__exception_code),4);
	vcdp->fullBit  (c+283,(vlTOPp->top__DOT__cpu__DOT__interrupt_code));
	vcdp->fullBit  (c+284,(vlTOPp->top__DOT__cpu__DOT__intruction_ret));
	vcdp->fullBus  (c+285,(0U),32);
	vcdp->fullBus  (c+286,(1U),3);
	vcdp->fullBus  (c+287,(2U),3);
	vcdp->fullBus  (c+288,(3U),3);
	vcdp->fullBus  (c+289,(4U),3);
	vcdp->fullBus  (c+290,(5U),3);
	vcdp->fullBus  (c+291,(6U),3);
	vcdp->fullBus  (c+292,(0U),3);
	vcdp->fullBus  (c+293,(0U),2);
	vcdp->fullBus  (c+294,(1U),2);
	vcdp->fullBus  (c+295,(2U),2);
	vcdp->fullBus  (c+296,(0xf14U),12);
	vcdp->fullBus  (c+297,(0xf11U),12);
	vcdp->fullBus  (c+298,(0xf12U),12);
	vcdp->fullBus  (c+299,(0x300U),12);
	vcdp->fullBus  (c+300,(0x301U),12);
	vcdp->fullBus  (c+301,(0x302U),12);
	vcdp->fullBus  (c+302,(0x303U),12);
	vcdp->fullBus  (c+303,(0x304U),12);
	vcdp->fullBus  (c+304,(0x305U),12);
	vcdp->fullBus  (c+305,(0x306U),12);
	vcdp->fullBus  (c+306,(0x340U),12);
	vcdp->fullBus  (c+307,(0x341U),12);
	vcdp->fullBus  (c+308,(0x342U),12);
	vcdp->fullBus  (c+309,(0x343U),12);
	vcdp->fullBus  (c+310,(0x344U),12);
	vcdp->fullBus  (c+311,(0xb00U),12);
	vcdp->fullBus  (c+312,(0xb02U),12);
	vcdp->fullBus  (c+313,(0xb80U),12);
	vcdp->fullBus  (c+314,(0xb82U),12);
	vcdp->fullBus  (c+315,(0U),4);
	vcdp->fullBus  (c+316,(1U),4);
	vcdp->fullBus  (c+317,(2U),4);
	vcdp->fullBus  (c+318,(3U),4);
	vcdp->fullBus  (c+319,(4U),4);
	vcdp->fullBus  (c+320,(5U),4);
	vcdp->fullBus  (c+321,(6U),4);
	vcdp->fullBus  (c+322,(7U),4);
	vcdp->fullBus  (c+323,(0xbU),4);
	vcdp->fullBit  (c+324,(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__undef_register));
	vcdp->fullBit  (c+325,(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__is_mscratch));
	vcdp->fullBus  (c+326,(0x18U),32);
	vcdp->fullBus  (c+327,(0x1000000U),32);
    }
}
