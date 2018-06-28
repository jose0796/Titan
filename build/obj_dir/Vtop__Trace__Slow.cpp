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
	vcdp->declBit  (c+313,"clk_i",-1);
	vcdp->declBit  (c+314,"rst_i",-1);
	vcdp->declBus  (c+318,"top HART_ID",-1,31,0);
	vcdp->declBus  (c+319,"top RESET_ADDR",-1,31,0);
	vcdp->declBus  (c+320,"top ENABLE_COUNTERS",-1,0,0);
	vcdp->declBus  (c+320,"top ENABLE_M_ISA",-1,0,0);
	vcdp->declBus  (c+321,"top MEM_SIZE",-1,31,0);
	vcdp->declBit  (c+313,"top clk_i",-1);
	vcdp->declBit  (c+314,"top rst_i",-1);
	vcdp->declBus  (c+178,"top dwbm_addr",-1,31,0);
	vcdp->declBit  (c+179,"top dwbm_cyc",-1);
	vcdp->declBus  (c+180,"top dwbm_dat_o",-1,31,0);
	vcdp->declBus  (c+1,"top dwbm_dat_i",-1,31,0);
	vcdp->declBus  (c+181,"top dwbm_sel",-1,3,0);
	vcdp->declBit  (c+182,"top dwbm_stb",-1);
	vcdp->declBit  (c+183,"top dwbm_we",-1);
	vcdp->declBus  (c+184,"top iwbm_addr",-1,31,0);
	vcdp->declBit  (c+185,"top iwbm_cyc",-1);
	vcdp->declBus  (c+2,"top iwbm_dat",-1,31,0);
	vcdp->declBit  (c+186,"top iwbm_stb",-1);
	vcdp->declBit  (c+3,"top iwbm_ack",-1);
	vcdp->declBit  (c+4,"top dwbm_ack",-1);
	vcdp->declBus  (c+318,"top cpu HART_ID",-1,31,0);
	vcdp->declBus  (c+319,"top cpu RESET_ADDR",-1,31,0);
	vcdp->declBus  (c+320,"top cpu ENABLE_COUNTERS",-1,0,0);
	vcdp->declBus  (c+320,"top cpu ENABLE_M_ISA",-1,0,0);
	vcdp->declBus  (c+322,"top cpu UCONTROL",-1,0,0);
	vcdp->declBit  (c+313,"top cpu clk_i",-1);
	vcdp->declBit  (c+314,"top cpu rst_i",-1);
	vcdp->declBus  (c+184,"top cpu iwbm_addr_o",-1,31,0);
	vcdp->declBit  (c+185,"top cpu iwbm_cyc_o",-1);
	vcdp->declBit  (c+186,"top cpu iwbm_stb_o",-1);
	vcdp->declBus  (c+2,"top cpu iwbm_dat_i",-1,31,0);
	vcdp->declBit  (c+323,"top cpu iwbm_err_i",-1);
	vcdp->declBit  (c+3,"top cpu iwbm_ack_i",-1);
	vcdp->declBus  (c+1,"top cpu dwbm_dat_i",-1,31,0);
	vcdp->declBit  (c+323,"top cpu dwbm_err_i",-1);
	vcdp->declBit  (c+4,"top cpu dwbm_ack_i",-1);
	vcdp->declBus  (c+178,"top cpu dwbm_addr_o",-1,31,0);
	vcdp->declBit  (c+179,"top cpu dwbm_cyc_o",-1);
	vcdp->declBit  (c+182,"top cpu dwbm_stb_o",-1);
	vcdp->declBus  (c+180,"top cpu dwbm_dat_o",-1,31,0);
	vcdp->declBit  (c+183,"top cpu dwbm_we_o",-1);
	vcdp->declBus  (c+181,"top cpu dwbm_sel_o",-1,3,0);
	vcdp->declBit  (c+323,"top cpu xint_meip_i",-1);
	vcdp->declBit  (c+323,"top cpu xint_mtip_i",-1);
	vcdp->declBit  (c+323,"top cpu xint_msip_i",-1);
	vcdp->declBit  (c+315,"top cpu if_stall",-1);
	vcdp->declBit  (c+173,"top cpu if_flush",-1);
	vcdp->declBus  (c+184,"top cpu if_pc",-1,31,0);
	vcdp->declBus  (c+5,"top cpu if_pc_sel",-1,1,0);
	vcdp->declBus  (c+2,"top cpu if_instruction",-1,31,0);
	vcdp->declBus  (c+187,"top cpu id_instruction",-1,31,0);
	vcdp->declBus  (c+188,"top cpu id_pc",-1,31,0);
	vcdp->declBus  (c+189,"top cpu wb_waddr",-1,4,0);
	vcdp->declBit  (c+190,"top cpu wb_we",-1);
	vcdp->declBit  (c+6,"top cpu id_stall",-1);
	vcdp->declBit  (c+316,"top cpu id_flush",-1);
	vcdp->declBus  (c+7,"top cpu ex_fwd_drd",-1,31,0);
	vcdp->declBus  (c+8,"top cpu mem_fwd_drd",-1,31,0);
	vcdp->declBus  (c+9,"top cpu forward_a_sel",-1,1,0);
	vcdp->declBus  (c+10,"top cpu forward_b_sel",-1,1,0);
	vcdp->declBit  (c+191,"top cpu id_inst_addr_misaligned",-1);
	vcdp->declBit  (c+192,"top cpu id_inst_access_fault",-1);
	vcdp->declBus  (c+11,"top cpu id_rs1",-1,4,0);
	vcdp->declBus  (c+12,"top cpu id_rs2",-1,4,0);
	vcdp->declBit  (c+13,"top cpu id_syscall_op",-1);
	vcdp->declBit  (c+14,"top cpu id_break_op",-1);
	vcdp->declBus  (c+193,"top cpu ex_rs1",-1,4,0);
	vcdp->declBus  (c+15,"top cpu pc_jump_addr",-1,31,0);
	vcdp->declBus  (c+16,"top cpu pc_branch_addr",-1,31,0);
	vcdp->declBit  (c+17,"top cpu take_branch",-1);
	vcdp->declBit  (c+18,"top cpu take_jump",-1);
	vcdp->declBus  (c+194,"top cpu ex_pc",-1,31,0);
	vcdp->declBus  (c+195,"top cpu ex_instruction",-1,31,0);
	vcdp->declBus  (c+196,"top cpu ex_port_a",-1,31,0);
	vcdp->declBus  (c+197,"top cpu ex_port_b",-1,31,0);
	vcdp->declBus  (c+198,"top cpu ex_alu_op",-1,3,0);
	vcdp->declBus  (c+199,"top cpu ex_waddr",-1,4,0);
	vcdp->declBit  (c+200,"top cpu ex_we",-1);
	vcdp->declBus  (c+201,"top cpu ex_mem_flags",-1,5,0);
	vcdp->declBit  (c+202,"top cpu ex_mem_ex_sel",-1);
	vcdp->declBit  (c+203,"top cpu ex_break_op",-1);
	vcdp->declBit  (c+204,"top cpu ex_syscall_op",-1);
	vcdp->declBus  (c+205,"top cpu ex_csr_op",-1,2,0);
	vcdp->declBus  (c+206,"top cpu ex_csr_data",-1,31,0);
	vcdp->declBus  (c+207,"top cpu ex_csr_addr",-1,11,0);
	vcdp->declBit  (c+19,"top cpu ex_stall",-1);
	vcdp->declBit  (c+174,"top cpu ex_flush",-1);
	vcdp->declBit  (c+208,"top cpu ex_fence_op",-1);
	vcdp->declBit  (c+209,"top cpu ex_xret_op",-1);
	vcdp->declBit  (c+210,"top cpu ex_inst_addr_misaligned",-1);
	vcdp->declBit  (c+211,"top cpu ex_inst_access_fault",-1);
	vcdp->declBit  (c+212,"top cpu ex_illegal_inst",-1);
	vcdp->declBus  (c+213,"top cpu ex_store_data",-1,31,0);
	vcdp->declBus  (c+214,"top cpu mem_pc",-1,31,0);
	vcdp->declBus  (c+215,"top cpu mem_instruction",-1,31,0);
	vcdp->declBus  (c+178,"top cpu mem_result",-1,31,0);
	vcdp->declBus  (c+216,"top cpu mem_waddr",-1,4,0);
	vcdp->declBus  (c+217,"top cpu mem_rs1",-1,4,0);
	vcdp->declBit  (c+218,"top cpu mem_we",-1);
	vcdp->declBus  (c+219,"top cpu mem_mem_flags",-1,5,0);
	vcdp->declBit  (c+220,"top cpu mem_mem_ex_sel",-1);
	vcdp->declBus  (c+221,"top cpu mem_csr_data",-1,31,0);
	vcdp->declBus  (c+222,"top cpu mem_csr_op",-1,2,0);
	vcdp->declBus  (c+223,"top cpu mem_csr_addr",-1,11,0);
	vcdp->declBit  (c+224,"top cpu mem_break_op",-1);
	vcdp->declBit  (c+225,"top cpu mem_syscall_op",-1);
	vcdp->declBit  (c+226,"top cpu mwrite",-1);
	vcdp->declBit  (c+227,"top cpu mread",-1);
	vcdp->declBit  (c+228,"top cpu mword",-1);
	vcdp->declBit  (c+229,"top cpu mhw",-1);
	vcdp->declBit  (c+230,"top cpu mbyte",-1);
	vcdp->declBit  (c+231,"top cpu munsigned",-1);
	vcdp->declBit  (c+323,"top cpu mem_stall",-1);
	vcdp->declBit  (c+175,"top cpu mem_flush",-1);
	vcdp->declBus  (c+232,"top cpu mem_store_data",-1,31,0);
	vcdp->declBus  (c+20,"top cpu mem_load_data",-1,31,0);
	vcdp->declBit  (c+233,"top cpu mem_fence_op",-1);
	vcdp->declBit  (c+234,"top cpu mem_xret_op",-1);
	vcdp->declBit  (c+235,"top cpu mem_inst_addr_misaligned",-1);
	vcdp->declBit  (c+236,"top cpu mem_inst_access_fault",-1);
	vcdp->declBit  (c+237,"top cpu mem_illegal_inst",-1);
	vcdp->declBus  (c+238,"top cpu wb_result_mem",-1,31,0);
	vcdp->declBus  (c+239,"top cpu wb_pc",-1,31,0);
	vcdp->declBus  (c+240,"top cpu wb_instruction",-1,31,0);
	vcdp->declBus  (c+21,"top cpu wb_result",-1,31,0);
	vcdp->declBus  (c+241,"top cpu wb_rs1",-1,4,0);
	vcdp->declBus  (c+242,"top cpu wb_csr_data",-1,31,0);
	vcdp->declBus  (c+243,"top cpu wb_csr_addr",-1,11,0);
	vcdp->declBus  (c+244,"top cpu wb_csr_op",-1,2,0);
	vcdp->declBit  (c+245,"top cpu wb_break_op",-1);
	vcdp->declBit  (c+246,"top cpu wb_syscall_op",-1);
	vcdp->declBit  (c+247,"top cpu wb_fence_op",-1);
	vcdp->declBit  (c+248,"top cpu wb_xret_op",-1);
	vcdp->declBit  (c+249,"top cpu wb_inst_addr_misaligned",-1);
	vcdp->declBit  (c+250,"top cpu wb_inst_access_fault",-1);
	vcdp->declBit  (c+251,"top cpu wb_illegal_inst",-1);
	vcdp->declBit  (c+252,"top cpu wb_load_addr_misaligned",-1);
	vcdp->declBit  (c+253,"top cpu wb_store_addr_misaligned",-1);
	vcdp->declBit  (c+254,"top cpu wb_load_access_fault",-1);
	vcdp->declBit  (c+255,"top cpu wb_store_access_fault",-1);
	vcdp->declBit  (c+324,"top cpu csr_dependence",-1);
	vcdp->declBit  (c+325,"top cpu ld_dependence",-1);
	vcdp->declBit  (c+18,"top cpu jump_flush_req",-1);
	vcdp->declBit  (c+17,"top cpu branch_flush_req",-1);
	vcdp->declBit  (c+317,"top cpu if_stall_req",-1);
	vcdp->declBit  (c+19,"top cpu mem_stall_req",-1);
	vcdp->declBit  (c+325,"top cpu fwd_stall_req",-1);
	vcdp->declBit  (c+22,"top cpu ex_nop",-1);
	vcdp->declBit  (c+23,"top cpu if_kill",-1);
	vcdp->declBit  (c+24,"top cpu hazard",-1);
	vcdp->declBit  (c+25,"top cpu en_fwd",-1);
	vcdp->declBit  (c+26,"top cpu csr_stall_req",-1);
	vcdp->declBit  (c+27,"top cpu ld_stall_req",-1);
	vcdp->declBit  (c+28,"top cpu xcall_break_stall_req",-1);
	vcdp->declBus  (c+29,"top cpu exception_pc",-1,31,0);
	vcdp->declBit  (c+30,"top cpu exception_stall_req",-1);
	vcdp->declBit  (c+326,"top cpu exception_sel_flag",-1);
	vcdp->declBus  (c+31,"top cpu csr_data_o",-1,31,0);
	vcdp->declBus  (c+319,"top cpu IF RESET_ADDR",-1,31,0);
	vcdp->declBit  (c+313,"top cpu IF clk_i",-1);
	vcdp->declBit  (c+314,"top cpu IF rst_i",-1);
	vcdp->declBit  (c+176,"top cpu IF if_stall",-1);
	vcdp->declBit  (c+6,"top cpu IF id_stall",-1);
	vcdp->declBit  (c+173,"top cpu IF if_flush",-1);
	vcdp->declBus  (c+2,"top cpu IF if_instruction_i",-1,31,0);
	vcdp->declBus  (c+16,"top cpu IF pc_branch_address_i",-1,31,0);
	vcdp->declBus  (c+15,"top cpu IF pc_jump_address_i",-1,31,0);
	vcdp->declBus  (c+29,"top cpu IF exception_pc_i",-1,31,0);
	vcdp->declBus  (c+5,"top cpu IF if_pc_sel_i",-1,1,0);
	vcdp->declBit  (c+323,"top cpu IF if_inst_access_fault_i",-1);
	vcdp->declBus  (c+184,"top cpu IF if_pc_o",-1,31,0);
	vcdp->declBus  (c+187,"top cpu IF id_instruction_o",-1,31,0);
	vcdp->declBus  (c+188,"top cpu IF id_pc_o",-1,31,0);
	vcdp->declBit  (c+191,"top cpu IF id_inst_addr_misaligned_o",-1);
	vcdp->declBit  (c+192,"top cpu IF id_inst_access_fault_o",-1);
	vcdp->declBus  (c+32,"top cpu IF if_pc_mux",-1,31,0);
	vcdp->declBus  (c+256,"top cpu IF if_pc_add4",-1,31,0);
	vcdp->declBit  (c+257,"top cpu IF if_inst_addr_misaligned",-1);
	vcdp->declBus  (c+319,"top cpu IF PC_REG RESET_ADDR",-1,31,0);
	vcdp->declBit  (c+313,"top cpu IF PC_REG clk_i",-1);
	vcdp->declBit  (c+314,"top cpu IF PC_REG rst_i",-1);
	vcdp->declBit  (c+176,"top cpu IF PC_REG stall",-1);
	vcdp->declBus  (c+32,"top cpu IF PC_REG pc_i",-1,31,0);
	vcdp->declBus  (c+184,"top cpu IF PC_REG pc_o",-1,31,0);
	vcdp->declBus  (c+184,"top cpu IF PC_ADD pc",-1,31,0);
	vcdp->declBus  (c+256,"top cpu IF PC_ADD pc_next",-1,31,0);
	vcdp->declBus  (c+256,"top cpu IF PC_SOURCE in0",-1,31,0);
	vcdp->declBus  (c+16,"top cpu IF PC_SOURCE in1",-1,31,0);
	vcdp->declBus  (c+15,"top cpu IF PC_SOURCE in2",-1,31,0);
	vcdp->declBus  (c+29,"top cpu IF PC_SOURCE in3",-1,31,0);
	vcdp->declBus  (c+5,"top cpu IF PC_SOURCE sel",-1,1,0);
	vcdp->declBus  (c+32,"top cpu IF PC_SOURCE out",-1,31,0);
	vcdp->declBit  (c+313,"top cpu IF IF_ID clk",-1);
	vcdp->declBit  (c+314,"top cpu IF IF_ID rst",-1);
	vcdp->declBit  (c+173,"top cpu IF IF_ID flush",-1);
	vcdp->declBit  (c+176,"top cpu IF IF_ID if_stall",-1);
	vcdp->declBit  (c+6,"top cpu IF IF_ID id_stall",-1);
	vcdp->declBus  (c+184,"top cpu IF IF_ID if_pc",-1,31,0);
	vcdp->declBit  (c+257,"top cpu IF IF_ID if_inst_addr_misaligned",-1);
	vcdp->declBit  (c+323,"top cpu IF IF_ID if_inst_access_fault",-1);
	vcdp->declBus  (c+2,"top cpu IF IF_ID if_inst",-1,31,0);
	vcdp->declBus  (c+188,"top cpu IF IF_ID id_pc",-1,31,0);
	vcdp->declBit  (c+191,"top cpu IF IF_ID id_inst_addr_misaligned",-1);
	vcdp->declBus  (c+187,"top cpu IF IF_ID id_inst",-1,31,0);
	vcdp->declBit  (c+192,"top cpu IF IF_ID id_inst_access_fault",-1);
	vcdp->declBit  (c+313,"top cpu ID clk_i",-1);
	vcdp->declBit  (c+314,"top cpu ID rst_i",-1);
	vcdp->declBit  (c+6,"top cpu ID id_stall_i",-1);
	vcdp->declBit  (c+177,"top cpu ID id_flush_i",-1);
	vcdp->declBus  (c+188,"top cpu ID id_pc_i",-1,31,0);
	vcdp->declBus  (c+187,"top cpu ID id_instruction_i",-1,31,0);
	vcdp->declBit  (c+191,"top cpu ID id_inst_addr_misaligned_i",-1);
	vcdp->declBit  (c+192,"top cpu ID id_inst_access_fault_i",-1);
	vcdp->declBus  (c+21,"top cpu ID wb_data_i",-1,31,0);
	vcdp->declBus  (c+189,"top cpu ID wb_address_i",-1,4,0);
	vcdp->declBit  (c+190,"top cpu ID wb_we_i",-1);
	vcdp->declBus  (c+7,"top cpu ID ex_fwd_drd_i",-1,31,0);
	vcdp->declBus  (c+8,"top cpu ID mem_fwd_drd_i",-1,31,0);
	vcdp->declBus  (c+21,"top cpu ID wb_fwd_drd_i",-1,31,0);
	vcdp->declBus  (c+9,"top cpu ID forward_a_sel_i",-1,1,0);
	vcdp->declBus  (c+10,"top cpu ID forward_b_sel_i",-1,1,0);
	vcdp->declBus  (c+11,"top cpu ID id_rs1_o",-1,4,0);
	vcdp->declBus  (c+12,"top cpu ID id_rs2_o",-1,4,0);
	vcdp->declBus  (c+16,"top cpu ID pc_branch_address_o",-1,31,0);
	vcdp->declBus  (c+15,"top cpu ID pc_jump_address_o",-1,31,0);
	vcdp->declBit  (c+17,"top cpu ID take_branch_o",-1);
	vcdp->declBit  (c+18,"top cpu ID take_jump_o",-1);
	vcdp->declBit  (c+13,"top cpu ID id_syscall_op_o",-1);
	vcdp->declBit  (c+14,"top cpu ID id_break_op_o",-1);
	vcdp->declBus  (c+194,"top cpu ID ex_pc_o",-1,31,0);
	vcdp->declBus  (c+195,"top cpu ID ex_instruction_o",-1,31,0);
	vcdp->declBus  (c+196,"top cpu ID ex_port_a_o",-1,31,0);
	vcdp->declBus  (c+197,"top cpu ID ex_port_b_o",-1,31,0);
	vcdp->declBus  (c+198,"top cpu ID ex_alu_op_o",-1,3,0);
	vcdp->declBus  (c+193,"top cpu ID ex_rs1_o",-1,4,0);
	vcdp->declBus  (c+199,"top cpu ID ex_waddr_o",-1,4,0);
	vcdp->declBit  (c+200,"top cpu ID ex_we_o",-1);
	vcdp->declBus  (c+213,"top cpu ID ex_store_data_o",-1,31,0);
	vcdp->declBus  (c+201,"top cpu ID ex_mem_flags_o",-1,5,0);
	vcdp->declBit  (c+202,"top cpu ID ex_mem_ex_sel_o",-1);
	vcdp->declBit  (c+212,"top cpu ID ex_illegal_inst_o",-1);
	vcdp->declBit  (c+210,"top cpu ID ex_inst_addr_misaligned_o",-1);
	vcdp->declBit  (c+211,"top cpu ID ex_inst_access_fault_o",-1);
	vcdp->declBit  (c+208,"top cpu ID ex_fence_op_o",-1);
	vcdp->declBit  (c+209,"top cpu ID ex_xret_op_o",-1);
	vcdp->declBit  (c+203,"top cpu ID ex_break_op_o",-1);
	vcdp->declBit  (c+204,"top cpu ID ex_syscall_op_o",-1);
	vcdp->declBus  (c+206,"top cpu ID ex_csr_data_o",-1,31,0);
	vcdp->declBus  (c+205,"top cpu ID ex_csr_op_o",-1,2,0);
	vcdp->declBus  (c+207,"top cpu ID ex_csr_addr_o",-1,11,0);
	vcdp->declBus  (c+33,"top cpu ID muxa_i",-1,31,0);
	vcdp->declBus  (c+34,"top cpu ID muxb_i",-1,31,0);
	vcdp->declBus  (c+11,"top cpu ID rs1",-1,4,0);
	vcdp->declBus  (c+12,"top cpu ID rs2",-1,4,0);
	vcdp->declBus  (c+35,"top cpu ID drs1",-1,31,0);
	vcdp->declBus  (c+36,"top cpu ID drs2",-1,31,0);
	vcdp->declBit  (c+37,"top cpu ID we",-1);
	vcdp->declBus  (c+38,"top cpu ID alu_op",-1,3,0);
	vcdp->declBus  (c+39,"top cpu ID comparator_op",-1,2,0);
	vcdp->declBus  (c+40,"top cpu ID imm",-1,31,0);
	// Tracing: top cpu ID _imm // Ignored: Inlined leading underscore at hardware/titan_id_stage.v:67
	vcdp->declBus  (c+41,"top cpu ID waddr",-1,4,0);
	vcdp->declBit  (c+42,"top cpu ID portb_sel",-1);
	vcdp->declBit  (c+43,"top cpu ID porta_sel",-1);
	vcdp->declBus  (c+44,"top cpu ID port_a",-1,31,0);
	vcdp->declBus  (c+45,"top cpu ID port_b",-1,31,0);
	// Tracing: top cpu ID _port_b // Ignored: Inlined leading underscore at hardware/titan_id_stage.v:73
	vcdp->declBit  (c+46,"top cpu ID jalr_op",-1);
	vcdp->declBus  (c+47,"top cpu ID mem_flags",-1,5,0);
	vcdp->declBit  (c+48,"top cpu ID mem_ex_sel",-1);
	vcdp->declBit  (c+18,"top cpu ID jump_op",-1);
	vcdp->declBus  (c+49,"top cpu ID pc_jump",-1,31,0);
	vcdp->declBit  (c+50,"top cpu ID branch_op",-1);
	vcdp->declBit  (c+51,"top cpu ID take_branch",-1);
	vcdp->declBit  (c+14,"top cpu ID break_op",-1);
	vcdp->declBit  (c+13,"top cpu ID syscall_op",-1);
	vcdp->declBus  (c+52,"top cpu ID csr_data",-1,31,0);
	vcdp->declBus  (c+258,"top cpu ID csr_addr",-1,11,0);
	vcdp->declBus  (c+53,"top cpu ID csr_op",-1,2,0);
	vcdp->declBit  (c+54,"top cpu ID csr_imm_op",-1);
	vcdp->declBit  (c+55,"top cpu ID fence_op",-1);
	vcdp->declBit  (c+56,"top cpu ID xret_op",-1);
	vcdp->declBit  (c+57,"top cpu ID illegal_inst",-1);
	vcdp->declBus  (c+34,"top cpu ID id_store_data",-1,31,0);
	vcdp->declBit  (c+58,"top cpu ID shift_op",-1);
	vcdp->declBus  (c+59,"top cpu ID pc_mux",-1,31,0);
	vcdp->declBit  (c+48,"top cpu ID load_store_op",-1);
	vcdp->declBus  (c+60,"top cpu ID SRA_MUX in_0",-1,31,0);
	vcdp->declBus  (c+61,"top cpu ID SRA_MUX in_1",-1,31,0);
	vcdp->declBit  (c+58,"top cpu ID SRA_MUX sel",-1);
	vcdp->declBus  (c+45,"top cpu ID SRA_MUX out",-1,31,0);
	vcdp->declBus  (c+33,"top cpu ID PORT_A_MUX in_0",-1,31,0);
	vcdp->declBus  (c+59,"top cpu ID PORT_A_MUX in_1",-1,31,0);
	vcdp->declBit  (c+43,"top cpu ID PORT_A_MUX sel",-1);
	vcdp->declBus  (c+44,"top cpu ID PORT_A_MUX out",-1,31,0);
	vcdp->declBus  (c+34,"top cpu ID PORT_B_MUX in_0",-1,31,0);
	vcdp->declBus  (c+40,"top cpu ID PORT_B_MUX in_1",-1,31,0);
	vcdp->declBit  (c+42,"top cpu ID PORT_B_MUX sel",-1);
	vcdp->declBus  (c+60,"top cpu ID PORT_B_MUX out",-1,31,0);
	vcdp->declBus  (c+35,"top cpu ID FORWARD_A_MUX in_0",-1,31,0);
	vcdp->declBus  (c+7,"top cpu ID FORWARD_A_MUX in_1",-1,31,0);
	vcdp->declBus  (c+8,"top cpu ID FORWARD_A_MUX in_2",-1,31,0);
	vcdp->declBus  (c+21,"top cpu ID FORWARD_A_MUX in_3",-1,31,0);
	vcdp->declBus  (c+9,"top cpu ID FORWARD_A_MUX sel",-1,1,0);
	vcdp->declBus  (c+33,"top cpu ID FORWARD_A_MUX out",-1,31,0);
	vcdp->declBus  (c+36,"top cpu ID FORWARD_B_MUX in_0",-1,31,0);
	vcdp->declBus  (c+7,"top cpu ID FORWARD_B_MUX in_1",-1,31,0);
	vcdp->declBus  (c+8,"top cpu ID FORWARD_B_MUX in_2",-1,31,0);
	vcdp->declBus  (c+21,"top cpu ID FORWARD_B_MUX in_3",-1,31,0);
	vcdp->declBus  (c+10,"top cpu ID FORWARD_B_MUX sel",-1,1,0);
	vcdp->declBus  (c+34,"top cpu ID FORWARD_B_MUX out",-1,31,0);
	vcdp->declBus  (c+39,"top cpu ID BP sel",-1,2,0);
	vcdp->declBus  (c+33,"top cpu ID BP drs1",-1,31,0);
	vcdp->declBus  (c+34,"top cpu ID BP drs2",-1,31,0);
	vcdp->declBit  (c+51,"top cpu ID BP take_branch",-1);
	vcdp->declBus  (c+33,"top cpu ID BP sdrs1",-1,31,0);
	vcdp->declBus  (c+34,"top cpu ID BP sdrs2",-1,31,0);
	vcdp->declBus  (c+33,"top cpu ID BP udrs1",-1,31,0);
	vcdp->declBus  (c+34,"top cpu ID BP udrs2",-1,31,0);
	vcdp->declBus  (c+327,"top cpu ID BP beq",-1,2,0);
	vcdp->declBus  (c+328,"top cpu ID BP bne",-1,2,0);
	vcdp->declBus  (c+329,"top cpu ID BP blt",-1,2,0);
	vcdp->declBus  (c+330,"top cpu ID BP bge",-1,2,0);
	vcdp->declBus  (c+331,"top cpu ID BP bltu",-1,2,0);
	vcdp->declBus  (c+332,"top cpu ID BP bgeu",-1,2,0);
	vcdp->declBus  (c+333,"top cpu ID BP nop",-1,2,0);
	vcdp->declBit  (c+313,"top cpu ID RF clk",-1);
	vcdp->declBus  (c+11,"top cpu ID RF raddr_rs1",-1,4,0);
	vcdp->declBus  (c+12,"top cpu ID RF raddr_rs2",-1,4,0);
	vcdp->declBus  (c+189,"top cpu ID RF waddr_rd",-1,4,0);
	vcdp->declBus  (c+21,"top cpu ID RF wdata_rd",-1,31,0);
	vcdp->declBit  (c+190,"top cpu ID RF we",-1);
	vcdp->declBus  (c+35,"top cpu ID RF rdata_rs1",-1,31,0);
	vcdp->declBus  (c+36,"top cpu ID RF rdata_rs2",-1,31,0);
	{int i; for (i=0; i<32; i++) {
		vcdp->declBus  (c+62+i*1,"top cpu ID RF reg_file",(i+0),31,0);}}
	vcdp->declBus  (c+187,"top cpu ID DCU instruction",-1,31,0);
	vcdp->declBus  (c+11,"top cpu ID DCU rs1",-1,4,0);
	vcdp->declBus  (c+12,"top cpu ID DCU rs2",-1,4,0);
	vcdp->declBus  (c+41,"top cpu ID DCU rd",-1,4,0);
	vcdp->declBit  (c+37,"top cpu ID DCU reg_write",-1);
	vcdp->declBus  (c+39,"top cpu ID DCU comparator_op",-1,2,0);
	vcdp->declBus  (c+47,"top cpu ID DCU mem_flags",-1,5,0);
	vcdp->declBit  (c+48,"top cpu ID DCU mem_ex_sel",-1);
	vcdp->declBus  (c+38,"top cpu ID DCU alu_op",-1,3,0);
	vcdp->declBus  (c+40,"top cpu ID DCU imm",-1,31,0);
	vcdp->declBit  (c+42,"top cpu ID DCU portb_sel",-1);
	vcdp->declBit  (c+43,"top cpu ID DCU porta_sel",-1);
	vcdp->declBit  (c+57,"top cpu ID DCU illegal_inst",-1);
	vcdp->declBit  (c+56,"top cpu ID DCU xret_op",-1);
	vcdp->declBit  (c+48,"top cpu ID DCU load_store_op",-1);
	vcdp->declBit  (c+55,"top cpu ID DCU fence_op",-1);
	vcdp->declBit  (c+58,"top cpu ID DCU shift_op",-1);
	vcdp->declBit  (c+13,"top cpu ID DCU syscall_op",-1);
	vcdp->declBit  (c+50,"top cpu ID DCU branch_op",-1);
	vcdp->declBit  (c+18,"top cpu ID DCU jump_op",-1);
	vcdp->declBit  (c+46,"top cpu ID DCU jalr_op",-1);
	vcdp->declBit  (c+14,"top cpu ID DCU break_op",-1);
	vcdp->declBit  (c+54,"top cpu ID DCU csr_imm_op",-1);
	vcdp->declBus  (c+53,"top cpu ID DCU csr_op",-1,2,0);
	vcdp->declBus  (c+258,"top cpu ID DCU csr_addr",-1,11,0);
	vcdp->declBus  (c+259,"top cpu ID DCU opcode",-1,6,0);
	vcdp->declBus  (c+94,"top cpu ID DCU mem_access",-1,2,0);
	vcdp->declBit  (c+95,"top cpu ID DCU mem_wr",-1);
	vcdp->declBit  (c+48,"top cpu ID DCU mem_r",-1);
	vcdp->declBit  (c+48,"top cpu ID DCU mem_ex_s",-1);
	vcdp->declBit  (c+96,"top cpu ID DCU mem_unsigned",-1);
	vcdp->declBus  (c+187,"top cpu ID DCU inst",-1,31,0);
	vcdp->declBus  (c+260,"top cpu ID DCU func3",-1,2,0);
	vcdp->declBus  (c+261,"top cpu ID DCU func7",-1,6,0);
	vcdp->declBit  (c+97,"top cpu ID DCU lui",-1);
	vcdp->declBit  (c+98,"top cpu ID DCU auipc",-1);
	vcdp->declBit  (c+99,"top cpu ID DCU jal",-1);
	vcdp->declBit  (c+46,"top cpu ID DCU jalr",-1);
	vcdp->declBit  (c+100,"top cpu ID DCU beq",-1);
	vcdp->declBit  (c+101,"top cpu ID DCU bne",-1);
	vcdp->declBit  (c+102,"top cpu ID DCU blt",-1);
	vcdp->declBit  (c+103,"top cpu ID DCU bge",-1);
	vcdp->declBit  (c+104,"top cpu ID DCU bltu",-1);
	vcdp->declBit  (c+105,"top cpu ID DCU bgeu",-1);
	vcdp->declBit  (c+106,"top cpu ID DCU lb",-1);
	vcdp->declBit  (c+107,"top cpu ID DCU lh",-1);
	vcdp->declBit  (c+108,"top cpu ID DCU lw",-1);
	vcdp->declBit  (c+109,"top cpu ID DCU lbu",-1);
	vcdp->declBit  (c+110,"top cpu ID DCU lhu",-1);
	vcdp->declBit  (c+111,"top cpu ID DCU sb",-1);
	vcdp->declBit  (c+112,"top cpu ID DCU sh",-1);
	vcdp->declBit  (c+113,"top cpu ID DCU sw",-1);
	vcdp->declBit  (c+114,"top cpu ID DCU addi",-1);
	vcdp->declBit  (c+115,"top cpu ID DCU slti",-1);
	vcdp->declBit  (c+116,"top cpu ID DCU sltiu",-1);
	vcdp->declBit  (c+117,"top cpu ID DCU xori",-1);
	vcdp->declBit  (c+118,"top cpu ID DCU ori",-1);
	vcdp->declBit  (c+119,"top cpu ID DCU andi",-1);
	vcdp->declBit  (c+120,"top cpu ID DCU slli",-1);
	vcdp->declBit  (c+121,"top cpu ID DCU srli",-1);
	vcdp->declBit  (c+122,"top cpu ID DCU srai",-1);
	vcdp->declBit  (c+123,"top cpu ID DCU add",-1);
	vcdp->declBit  (c+124,"top cpu ID DCU sub",-1);
	vcdp->declBit  (c+125,"top cpu ID DCU sll",-1);
	vcdp->declBit  (c+126,"top cpu ID DCU slt",-1);
	vcdp->declBit  (c+127,"top cpu ID DCU sltu",-1);
	// Tracing: top cpu ID DCU _xor // Ignored: Inlined leading underscore at hardware/titan_dc_unit.v:81
	vcdp->declBit  (c+128,"top cpu ID DCU srl",-1);
	vcdp->declBit  (c+129,"top cpu ID DCU sra",-1);
	// Tracing: top cpu ID DCU _or // Ignored: Inlined leading underscore at hardware/titan_dc_unit.v:81
	// Tracing: top cpu ID DCU _and // Ignored: Inlined leading underscore at hardware/titan_dc_unit.v:81
	vcdp->declBit  (c+130,"top cpu ID DCU fence",-1);
	vcdp->declBit  (c+131,"top cpu ID DCU fencei",-1);
	vcdp->declBit  (c+56,"top cpu ID DCU xret",-1);
	vcdp->declBit  (c+132,"top cpu ID DCU rw",-1);
	vcdp->declBit  (c+133,"top cpu ID DCU rs",-1);
	vcdp->declBit  (c+134,"top cpu ID DCU rc",-1);
	vcdp->declBit  (c+135,"top cpu ID DCU rwi",-1);
	vcdp->declBit  (c+136,"top cpu ID DCU rsi",-1);
	vcdp->declBit  (c+137,"top cpu ID DCU rci",-1);
	vcdp->declBit  (c+13,"top cpu ID DCU call",-1);
	// Tracing: top cpu ID DCU _break // Ignored: Inlined leading underscore at hardware/titan_dc_unit.v:85
	vcdp->declBit  (c+50,"top cpu ID DCU is_b",-1);
	vcdp->declBit  (c+138,"top cpu ID DCU is_imm",-1);
	vcdp->declBit  (c+95,"top cpu ID DCU is_st",-1);
	vcdp->declBit  (c+48,"top cpu ID DCU is_ld",-1);
	vcdp->declBit  (c+139,"top cpu ID DCU is_add",-1);
	vcdp->declBit  (c+140,"top cpu ID DCU is_sub",-1);
	vcdp->declBit  (c+141,"top cpu ID DCU is_and",-1);
	vcdp->declBit  (c+142,"top cpu ID DCU is_xor",-1);
	vcdp->declBit  (c+143,"top cpu ID DCU is_or",-1);
	vcdp->declBit  (c+144,"top cpu ID DCU is_sll",-1);
	vcdp->declBit  (c+145,"top cpu ID DCU is_sr",-1);
	vcdp->declBit  (c+58,"top cpu ID DCU is_shift",-1);
	vcdp->declBit  (c+146,"top cpu ID DCU is_slt",-1);
	vcdp->declBit  (c+147,"top cpu ID DCU is_sltu",-1);
	vcdp->declBit  (c+148,"top cpu ID DCU is_wr",-1);
	vcdp->declBit  (c+149,"top cpu ID DCU is_alu",-1);
	vcdp->declBit  (c+150,"top cpu ID DCU is_immop",-1);
	vcdp->declBit  (c+96,"top cpu ID DCU is_ldu",-1);
	vcdp->declBit  (c+18,"top cpu ID DCU is_j",-1);
	vcdp->declBit  (c+54,"top cpu ID DCU is_csri",-1);
	vcdp->declBit  (c+151,"top cpu ID DCU is_csr",-1);
	vcdp->declBit  (c+152,"top cpu ID DCU is_fence",-1);
	vcdp->declBit  (c+153,"top cpu ID DCU is_word",-1);
	vcdp->declBit  (c+154,"top cpu ID DCU is_byte",-1);
	vcdp->declBit  (c+155,"top cpu ID DCU is_hw",-1);
	vcdp->declBit  (c+57,"top cpu ID DCU illegal",-1);
	vcdp->declBit  (c+156,"top cpu ID DCU uimp",-1);
	vcdp->declBit  (c+313,"top cpu ID ID_EX clk",-1);
	vcdp->declBit  (c+314,"top cpu ID ID_EX rst",-1);
	vcdp->declBit  (c+6,"top cpu ID ID_EX stall",-1);
	vcdp->declBit  (c+177,"top cpu ID ID_EX flush",-1);
	vcdp->declBus  (c+188,"top cpu ID ID_EX id_pc",-1,31,0);
	vcdp->declBus  (c+187,"top cpu ID ID_EX id_instruction",-1,31,0);
	vcdp->declBus  (c+44,"top cpu ID ID_EX id_porta",-1,31,0);
	vcdp->declBus  (c+45,"top cpu ID ID_EX id_portb",-1,31,0);
	vcdp->declBus  (c+38,"top cpu ID ID_EX id_alu_op",-1,3,0);
	vcdp->declBus  (c+11,"top cpu ID ID_EX id_rs1",-1,4,0);
	vcdp->declBus  (c+34,"top cpu ID ID_EX id_store_data",-1,31,0);
	vcdp->declBit  (c+37,"top cpu ID ID_EX id_we",-1);
	vcdp->declBus  (c+47,"top cpu ID ID_EX id_mem_flags",-1,5,0);
	vcdp->declBit  (c+48,"top cpu ID ID_EX id_mem_ex_sel",-1);
	vcdp->declBus  (c+52,"top cpu ID ID_EX id_csr_data",-1,31,0);
	vcdp->declBus  (c+53,"top cpu ID ID_EX id_csr_op",-1,2,0);
	vcdp->declBus  (c+258,"top cpu ID ID_EX id_csr_addr",-1,11,0);
	vcdp->declBus  (c+41,"top cpu ID ID_EX id_waddr",-1,4,0);
	vcdp->declBit  (c+191,"top cpu ID ID_EX id_inst_addr_misaligned",-1);
	vcdp->declBit  (c+192,"top cpu ID ID_EX id_inst_access_fault",-1);
	vcdp->declBit  (c+57,"top cpu ID ID_EX id_illegal_inst",-1);
	vcdp->declBit  (c+14,"top cpu ID ID_EX id_break_op",-1);
	vcdp->declBit  (c+13,"top cpu ID ID_EX id_syscall_op",-1);
	vcdp->declBit  (c+55,"top cpu ID ID_EX id_fence_op",-1);
	vcdp->declBit  (c+56,"top cpu ID ID_EX id_xret_op",-1);
	vcdp->declBus  (c+194,"top cpu ID ID_EX ex_pc",-1,31,0);
	vcdp->declBus  (c+195,"top cpu ID ID_EX ex_instruction",-1,31,0);
	vcdp->declBus  (c+196,"top cpu ID ID_EX ex_porta",-1,31,0);
	vcdp->declBus  (c+197,"top cpu ID ID_EX ex_portb",-1,31,0);
	vcdp->declBus  (c+198,"top cpu ID ID_EX ex_alu_op",-1,3,0);
	vcdp->declBus  (c+193,"top cpu ID ID_EX ex_rs1",-1,4,0);
	vcdp->declBus  (c+213,"top cpu ID ID_EX ex_store_data",-1,31,0);
	vcdp->declBit  (c+200,"top cpu ID ID_EX ex_we",-1);
	vcdp->declBus  (c+201,"top cpu ID ID_EX ex_mem_flags",-1,5,0);
	vcdp->declBit  (c+202,"top cpu ID ID_EX ex_mem_ex_sel",-1);
	vcdp->declBit  (c+210,"top cpu ID ID_EX ex_inst_addr_misaligned",-1);
	vcdp->declBit  (c+211,"top cpu ID ID_EX ex_inst_access_fault",-1);
	vcdp->declBit  (c+212,"top cpu ID ID_EX ex_illegal_inst",-1);
	vcdp->declBit  (c+208,"top cpu ID ID_EX ex_fence_op",-1);
	vcdp->declBit  (c+209,"top cpu ID ID_EX ex_xret_op",-1);
	vcdp->declBit  (c+203,"top cpu ID ID_EX ex_break_op",-1);
	vcdp->declBit  (c+204,"top cpu ID ID_EX ex_syscall_op",-1);
	vcdp->declBus  (c+206,"top cpu ID ID_EX ex_csr_data",-1,31,0);
	vcdp->declBus  (c+207,"top cpu ID ID_EX ex_csr_addr",-1,11,0);
	vcdp->declBus  (c+205,"top cpu ID ID_EX ex_csr_op",-1,2,0);
	vcdp->declBus  (c+199,"top cpu ID ID_EX ex_waddr",-1,4,0);
	vcdp->declBit  (c+313,"top cpu EX clk_i",-1);
	vcdp->declBit  (c+314,"top cpu EX rst_i",-1);
	vcdp->declBit  (c+19,"top cpu EX ex_stall_i",-1);
	vcdp->declBit  (c+174,"top cpu EX ex_flush_i",-1);
	vcdp->declBus  (c+194,"top cpu EX ex_pc_i",-1,31,0);
	vcdp->declBus  (c+195,"top cpu EX ex_instruction_i",-1,31,0);
	vcdp->declBus  (c+196,"top cpu EX ex_port_a_i",-1,31,0);
	vcdp->declBus  (c+197,"top cpu EX ex_port_b_i",-1,31,0);
	vcdp->declBus  (c+198,"top cpu EX ex_alu_op_i",-1,3,0);
	vcdp->declBus  (c+193,"top cpu EX ex_rs1_i",-1,4,0);
	vcdp->declBus  (c+213,"top cpu EX ex_store_data_i",-1,31,0);
	vcdp->declBus  (c+199,"top cpu EX ex_waddr_i",-1,4,0);
	vcdp->declBit  (c+200,"top cpu EX ex_we_i",-1);
	vcdp->declBus  (c+201,"top cpu EX ex_mem_flags_i",-1,5,0);
	vcdp->declBit  (c+202,"top cpu EX ex_mem_ex_sel_i",-1);
	vcdp->declBit  (c+210,"top cpu EX ex_inst_addr_misaligned_i",-1);
	vcdp->declBit  (c+211,"top cpu EX ex_inst_access_fault_i",-1);
	vcdp->declBit  (c+212,"top cpu EX ex_illegal_inst_i",-1);
	vcdp->declBit  (c+209,"top cpu EX ex_xret_op_i",-1);
	vcdp->declBit  (c+208,"top cpu EX ex_fence_op_i",-1);
	vcdp->declBit  (c+203,"top cpu EX ex_break_op_i",-1);
	vcdp->declBit  (c+204,"top cpu EX ex_syscall_op_i",-1);
	vcdp->declBus  (c+206,"top cpu EX ex_csr_data_i",-1,31,0);
	vcdp->declBus  (c+207,"top cpu EX ex_csr_addr_i",-1,11,0);
	vcdp->declBus  (c+205,"top cpu EX ex_csr_op_i",-1,2,0);
	vcdp->declBus  (c+214,"top cpu EX mem_pc_o",-1,31,0);
	vcdp->declBus  (c+215,"top cpu EX mem_instruction_o",-1,31,0);
	vcdp->declBus  (c+217,"top cpu EX mem_rs1_o",-1,4,0);
	vcdp->declBus  (c+7,"top cpu EX ex_fwd_dat_o",-1,31,0);
	vcdp->declBus  (c+232,"top cpu EX mem_store_data_o",-1,31,0);
	vcdp->declBus  (c+178,"top cpu EX mem_result_o",-1,31,0);
	vcdp->declBus  (c+216,"top cpu EX mem_waddr_o",-1,4,0);
	vcdp->declBit  (c+218,"top cpu EX mem_we_o",-1);
	vcdp->declBus  (c+219,"top cpu EX mem_mem_flags_o",-1,5,0);
	vcdp->declBit  (c+220,"top cpu EX mem_mem_ex_sel_o",-1);
	vcdp->declBit  (c+235,"top cpu EX mem_inst_addr_misaligned_o",-1);
	vcdp->declBit  (c+236,"top cpu EX mem_inst_access_fault_o",-1);
	vcdp->declBit  (c+237,"top cpu EX mem_illegal_inst_o",-1);
	vcdp->declBit  (c+234,"top cpu EX mem_xret_op_o",-1);
	vcdp->declBit  (c+233,"top cpu EX mem_fence_op_o",-1);
	vcdp->declBit  (c+224,"top cpu EX mem_break_op_o",-1);
	vcdp->declBit  (c+225,"top cpu EX mem_syscall_op_o",-1);
	vcdp->declBus  (c+221,"top cpu EX mem_csr_data_o",-1,31,0);
	vcdp->declBus  (c+222,"top cpu EX mem_csr_op_o",-1,2,0);
	vcdp->declBus  (c+223,"top cpu EX mem_csr_addr_o",-1,11,0);
	vcdp->declBus  (c+7,"top cpu EX ex_result",-1,31,0);
	vcdp->declBus  (c+196,"top cpu EX ALU port_a",-1,31,0);
	vcdp->declBus  (c+197,"top cpu EX ALU port_b",-1,31,0);
	vcdp->declBus  (c+198,"top cpu EX ALU alu_op",-1,3,0);
	vcdp->declBus  (c+7,"top cpu EX ALU result",-1,31,0);
	vcdp->declBus  (c+196,"top cpu EX ALU sa",-1,31,0);
	vcdp->declBus  (c+196,"top cpu EX ALU a",-1,31,0);
	vcdp->declBus  (c+197,"top cpu EX ALU sb",-1,31,0);
	vcdp->declBus  (c+197,"top cpu EX ALU b",-1,31,0);
	vcdp->declBit  (c+313,"top cpu EX EX_MEM clk",-1);
	vcdp->declBit  (c+314,"top cpu EX EX_MEM rst",-1);
	vcdp->declBit  (c+19,"top cpu EX EX_MEM stall",-1);
	vcdp->declBit  (c+174,"top cpu EX EX_MEM flush",-1);
	vcdp->declBus  (c+194,"top cpu EX EX_MEM ex_pc",-1,31,0);
	vcdp->declBus  (c+195,"top cpu EX EX_MEM ex_instruction",-1,31,0);
	vcdp->declBus  (c+7,"top cpu EX EX_MEM ex_result",-1,31,0);
	vcdp->declBus  (c+199,"top cpu EX EX_MEM ex_waddr",-1,4,0);
	vcdp->declBus  (c+193,"top cpu EX EX_MEM ex_rs1",-1,4,0);
	vcdp->declBit  (c+200,"top cpu EX EX_MEM ex_we",-1);
	vcdp->declBus  (c+201,"top cpu EX EX_MEM ex_mem_flags",-1,5,0);
	vcdp->declBus  (c+213,"top cpu EX EX_MEM ex_store_data",-1,31,0);
	vcdp->declBit  (c+202,"top cpu EX EX_MEM ex_mem_ex_sel",-1);
	vcdp->declBus  (c+206,"top cpu EX EX_MEM ex_csr_data",-1,31,0);
	vcdp->declBus  (c+205,"top cpu EX EX_MEM ex_csr_op",-1,2,0);
	vcdp->declBus  (c+207,"top cpu EX EX_MEM ex_csr_addr",-1,11,0);
	vcdp->declBit  (c+212,"top cpu EX EX_MEM ex_illegal_inst",-1);
	vcdp->declBit  (c+210,"top cpu EX EX_MEM ex_inst_addr_misaligned",-1);
	vcdp->declBit  (c+211,"top cpu EX EX_MEM ex_inst_access_fault",-1);
	vcdp->declBit  (c+203,"top cpu EX EX_MEM ex_break_op",-1);
	vcdp->declBit  (c+204,"top cpu EX EX_MEM ex_syscall_op",-1);
	vcdp->declBit  (c+208,"top cpu EX EX_MEM ex_fence_op",-1);
	vcdp->declBit  (c+209,"top cpu EX EX_MEM ex_xret_op",-1);
	vcdp->declBus  (c+214,"top cpu EX EX_MEM mem_pc",-1,31,0);
	vcdp->declBus  (c+215,"top cpu EX EX_MEM mem_instruction",-1,31,0);
	vcdp->declBus  (c+178,"top cpu EX EX_MEM mem_result",-1,31,0);
	vcdp->declBus  (c+216,"top cpu EX EX_MEM mem_waddr",-1,4,0);
	vcdp->declBus  (c+217,"top cpu EX EX_MEM mem_rs1",-1,4,0);
	vcdp->declBit  (c+218,"top cpu EX EX_MEM mem_we",-1);
	vcdp->declBus  (c+219,"top cpu EX EX_MEM mem_mem_flags",-1,5,0);
	vcdp->declBus  (c+232,"top cpu EX EX_MEM mem_store_data",-1,31,0);
	vcdp->declBit  (c+220,"top cpu EX EX_MEM mem_mem_ex_sel",-1);
	vcdp->declBus  (c+221,"top cpu EX EX_MEM mem_csr_data",-1,31,0);
	vcdp->declBus  (c+222,"top cpu EX EX_MEM mem_csr_op",-1,2,0);
	vcdp->declBus  (c+223,"top cpu EX EX_MEM mem_csr_addr",-1,11,0);
	vcdp->declBit  (c+237,"top cpu EX EX_MEM mem_illegal_inst",-1);
	vcdp->declBit  (c+235,"top cpu EX EX_MEM mem_inst_addr_misaligned",-1);
	vcdp->declBit  (c+236,"top cpu EX EX_MEM mem_inst_access_fault",-1);
	vcdp->declBit  (c+234,"top cpu EX EX_MEM mem_xret_op",-1);
	vcdp->declBit  (c+233,"top cpu EX EX_MEM mem_fence_op",-1);
	vcdp->declBit  (c+224,"top cpu EX EX_MEM mem_break_op",-1);
	vcdp->declBit  (c+225,"top cpu EX EX_MEM mem_syscall_op",-1);
	vcdp->declBit  (c+313,"top cpu MEM clk_i",-1);
	vcdp->declBit  (c+314,"top cpu MEM rst_i",-1);
	vcdp->declBit  (c+323,"top cpu MEM stall",-1);
	vcdp->declBit  (c+175,"top cpu MEM flush",-1);
	vcdp->declBus  (c+8,"top cpu MEM forward_mem_dat_o",-1,31,0);
	vcdp->declBus  (c+214,"top cpu MEM mem_pc_i",-1,31,0);
	vcdp->declBus  (c+215,"top cpu MEM mem_instruction_i",-1,31,0);
	vcdp->declBus  (c+178,"top cpu MEM mem_result_i",-1,31,0);
	vcdp->declBus  (c+216,"top cpu MEM mem_waddr_i",-1,4,0);
	vcdp->declBus  (c+217,"top cpu MEM mem_rs1_i",-1,4,0);
	vcdp->declBit  (c+218,"top cpu MEM mem_we_i",-1);
	vcdp->declBus  (c+219,"top cpu MEM mem_mem_flags_i",-1,5,0);
	vcdp->declBit  (c+220,"top cpu MEM mem_mem_ex_sel_i",-1);
	vcdp->declBus  (c+221,"top cpu MEM mem_csr_data_i",-1,31,0);
	vcdp->declBus  (c+223,"top cpu MEM mem_csr_addr_i",-1,11,0);
	vcdp->declBus  (c+222,"top cpu MEM mem_csr_op_i",-1,2,0);
	vcdp->declBit  (c+235,"top cpu MEM mem_inst_addr_misaligned_i",-1);
	vcdp->declBit  (c+236,"top cpu MEM mem_inst_access_fault_i",-1);
	vcdp->declBit  (c+237,"top cpu MEM mem_illegal_inst_i",-1);
	vcdp->declBit  (c+233,"top cpu MEM mem_fence_op_i",-1);
	vcdp->declBit  (c+234,"top cpu MEM mem_xret_op_i",-1);
	vcdp->declBit  (c+224,"top cpu MEM mem_break_op_i",-1);
	vcdp->declBit  (c+225,"top cpu MEM mem_syscall_op_i",-1);
	vcdp->declBus  (c+20,"top cpu MEM mem_data_i",-1,31,0);
	vcdp->declBit  (c+323,"top cpu MEM mem_err_i",-1);
	vcdp->declBit  (c+227,"top cpu MEM mem_mread_o",-1);
	vcdp->declBit  (c+226,"top cpu MEM mem_mwrite_o",-1);
	vcdp->declBit  (c+230,"top cpu MEM mem_mbyte_o",-1);
	vcdp->declBit  (c+229,"top cpu MEM mem_mhw_o",-1);
	vcdp->declBit  (c+228,"top cpu MEM mem_mword_o",-1);
	vcdp->declBit  (c+231,"top cpu MEM mem_munsigned_o",-1);
	vcdp->declBus  (c+239,"top cpu MEM wb_pc_o",-1,31,0);
	vcdp->declBus  (c+240,"top cpu MEM wb_instruction_o",-1,31,0);
	vcdp->declBus  (c+238,"top cpu MEM wb_result_o",-1,31,0);
	vcdp->declBus  (c+189,"top cpu MEM wb_waddr_o",-1,4,0);
	vcdp->declBit  (c+190,"top cpu MEM wb_we_o",-1);
	vcdp->declBus  (c+242,"top cpu MEM wb_csr_data_o",-1,31,0);
	vcdp->declBus  (c+243,"top cpu MEM wb_csr_addr_o",-1,11,0);
	vcdp->declBus  (c+244,"top cpu MEM wb_csr_op_o",-1,2,0);
	vcdp->declBus  (c+241,"top cpu MEM wb_rs1_o",-1,4,0);
	vcdp->declBit  (c+249,"top cpu MEM wb_inst_addr_misaligned_o",-1);
	vcdp->declBit  (c+252,"top cpu MEM wb_load_addr_misaligned_o",-1);
	vcdp->declBit  (c+253,"top cpu MEM wb_store_addr_misaligned_o",-1);
	vcdp->declBit  (c+250,"top cpu MEM wb_inst_access_fault_o",-1);
	vcdp->declBit  (c+254,"top cpu MEM wb_load_access_fault_o",-1);
	vcdp->declBit  (c+255,"top cpu MEM wb_store_access_fault_o",-1);
	vcdp->declBit  (c+251,"top cpu MEM wb_illegal_inst_o",-1);
	vcdp->declBit  (c+247,"top cpu MEM wb_fence_op_o",-1);
	vcdp->declBit  (c+248,"top cpu MEM wb_xret_op_o",-1);
	vcdp->declBit  (c+245,"top cpu MEM wb_break_op_o",-1);
	vcdp->declBit  (c+246,"top cpu MEM wb_syscall_op_o",-1);
	vcdp->declBit  (c+262,"top cpu MEM mem_load_addr_misaligned_i",-1);
	vcdp->declBit  (c+263,"top cpu MEM mem_store_addr_misaligned_i",-1);
	vcdp->declBit  (c+323,"top cpu MEM mem_load_access_fault_i",-1);
	vcdp->declBit  (c+323,"top cpu MEM mem_store_access_fault_i",-1);
	vcdp->declBus  (c+8,"top cpu MEM mem_result",-1,31,0);
	vcdp->declBus  (c+238,"top cpu mux21 in_0",-1,31,0);
	vcdp->declBus  (c+31,"top cpu mux21 in_1",-1,31,0);
	vcdp->declBit  (c+264,"top cpu mux21 sel",-1);
	vcdp->declBus  (c+21,"top cpu mux21 out",-1,31,0);
	vcdp->declBus  (c+11,"top cpu FWD id_rs1_i",-1,4,0);
	vcdp->declBus  (c+12,"top cpu FWD id_rs2_i",-1,4,0);
	vcdp->declBit  (c+200,"top cpu FWD ex_we_i",-1);
	vcdp->declBus  (c+199,"top cpu FWD ex_rd_i",-1,4,0);
	vcdp->declBit  (c+218,"top cpu FWD mem_we_i",-1);
	vcdp->declBus  (c+216,"top cpu FWD mem_rd_i",-1,4,0);
	vcdp->declBit  (c+190,"top cpu FWD wb_we_i",-1);
	vcdp->declBus  (c+189,"top cpu FWD wb_rd_i",-1,4,0);
	vcdp->declBit  (c+25,"top cpu FWD enable_fwd_i",-1);
	vcdp->declBus  (c+9,"top cpu FWD fwd_sel_a_o",-1,1,0);
	vcdp->declBus  (c+10,"top cpu FWD fwd_sel_b_o",-1,1,0);
	vcdp->declBit  (c+24,"top cpu FWD hazard_o",-1);
	vcdp->declBit  (c+157,"top cpu FWD ex_fwd_a",-1);
	vcdp->declBit  (c+158,"top cpu FWD ex_fwd_b",-1);
	vcdp->declBit  (c+159,"top cpu FWD mem_fwd_a",-1);
	vcdp->declBit  (c+160,"top cpu FWD mem_fwd_b",-1);
	vcdp->declBit  (c+161,"top cpu FWD wb_fwd_a",-1);
	vcdp->declBit  (c+162,"top cpu FWD wb_fwd_b",-1);
	vcdp->declBit  (c+313,"top cpu LSU clk_i",-1);
	vcdp->declBit  (c+314,"top cpu LSU rst_i",-1);
	vcdp->declBus  (c+184,"top cpu LSU pc",-1,31,0);
	vcdp->declBus  (c+2,"top cpu LSU instruction",-1,31,0);
	vcdp->declBit  (c+23,"top cpu LSU ikill_i",-1);
	vcdp->declBus  (c+2,"top cpu LSU idat_i",-1,31,0);
	vcdp->declBit  (c+3,"top cpu LSU iack_i",-1);
	vcdp->declBit  (c+323,"top cpu LSU ierr_i",-1);
	vcdp->declBus  (c+184,"top cpu LSU iaddr_o",-1,31,0);
	vcdp->declBit  (c+185,"top cpu LSU icyc_o",-1);
	vcdp->declBit  (c+186,"top cpu LSU istb_o",-1);
	vcdp->declBit  (c+317,"top cpu LSU istall_o",-1);
	vcdp->declBus  (c+178,"top cpu LSU maddr_i",-1,31,0);
	vcdp->declBus  (c+232,"top cpu LSU mdat_i",-1,31,0);
	vcdp->declBit  (c+227,"top cpu LSU mread_i",-1);
	vcdp->declBit  (c+226,"top cpu LSU mwrite_i",-1);
	vcdp->declBit  (c+230,"top cpu LSU mbyte_i",-1);
	vcdp->declBit  (c+229,"top cpu LSU mhw_i",-1);
	vcdp->declBit  (c+228,"top cpu LSU mword_i",-1);
	vcdp->declBit  (c+231,"top cpu LSU munsigned_i",-1);
	vcdp->declBit  (c+19,"top cpu LSU dstall_o",-1);
	vcdp->declBus  (c+20,"top cpu LSU data_o",-1,31,0);
	vcdp->declBus  (c+1,"top cpu LSU ddat_i",-1,31,0);
	vcdp->declBit  (c+4,"top cpu LSU dack_i",-1);
	vcdp->declBit  (c+323,"top cpu LSU derr_i",-1);
	vcdp->declBus  (c+178,"top cpu LSU daddr_o",-1,31,0);
	vcdp->declBus  (c+180,"top cpu LSU ddat_o",-1,31,0);
	vcdp->declBus  (c+181,"top cpu LSU dsel_o",-1,3,0);
	vcdp->declBit  (c+179,"top cpu LSU dcyc_o",-1);
	vcdp->declBit  (c+182,"top cpu LSU dstb_o",-1);
	vcdp->declBit  (c+183,"top cpu LSU dwe_o",-1);
	vcdp->declBus  (c+334,"top cpu LSU i_str",-1,1,0);
	vcdp->declBus  (c+335,"top cpu LSU i_ab",-1,1,0);
	vcdp->declBus  (c+336,"top cpu LSU i_kill",-1,1,0);
	vcdp->declBus  (c+334,"top cpu LSU d_str",-1,1,0);
	vcdp->declBus  (c+335,"top cpu LSU d_trx",-1,1,0);
	vcdp->declBus  (c+1,"top cpu LSU rdata",-1,31,0);
	vcdp->declBus  (c+163,"top cpu LSU wdata",-1,31,0);
	vcdp->declBus  (c+164,"top cpu LSU wsel_o",-1,3,0);
	vcdp->declBus  (c+165,"top cpu LSU rsel_o",-1,3,0);
	vcdp->declBit  (c+166,"top cpu LSU runsigned",-1);
	vcdp->declBus  (c+265,"top cpu LSU i_state",-1,1,0);
	vcdp->declBus  (c+266,"top cpu LSU d_state",-1,1,0);
	vcdp->declBit  (c+267,"top cpu LSU kill",-1);
	vcdp->declBit  (c+167,"top cpu HZ id_xcall_break_i",-1);
	vcdp->declBit  (c+268,"top cpu HZ ex_xcall_break_i",-1);
	vcdp->declBit  (c+269,"top cpu HZ mem_xcall_break_i",-1);
	vcdp->declBit  (c+270,"top cpu HZ ex_csr_op_i",-1);
	vcdp->declBit  (c+271,"top cpu HZ mem_csr_op_i",-1);
	vcdp->declBit  (c+202,"top cpu HZ ex_ld_op_i",-1);
	vcdp->declBit  (c+220,"top cpu HZ mem_ld_op_i",-1);
	vcdp->declBit  (c+24,"top cpu HZ hazard_i",-1);
	vcdp->declBit  (c+25,"top cpu HZ enable_fwd_o",-1);
	vcdp->declBit  (c+26,"top cpu HZ csr_stall_req_o",-1);
	vcdp->declBit  (c+27,"top cpu HZ ld_stall_req_o",-1);
	vcdp->declBit  (c+28,"top cpu HZ xcall_break_stall_req_o",-1);
	vcdp->declBit  (c+26,"top cpu HZ csr",-1);
	vcdp->declBit  (c+27,"top cpu HZ ld",-1);
	vcdp->declBit  (c+28,"top cpu HZ xcall_break",-1);
	vcdp->declBit  (c+314,"top cpu CU rst_i",-1);
	vcdp->declBit  (c+317,"top cpu CU if_stall_req_i",-1);
	vcdp->declBit  (c+19,"top cpu CU mem_stall_req_i",-1);
	vcdp->declBit  (c+324,"top cpu CU csr_stall_req_i",-1);
	vcdp->declBit  (c+27,"top cpu CU ld_stall_req_i",-1);
	vcdp->declBit  (c+28,"top cpu CU xcall_break_stall_req_i",-1);
	vcdp->declBit  (c+17,"top cpu CU branch_flush_req_i",-1);
	vcdp->declBit  (c+18,"top cpu CU jump_flush_req_i",-1);
	vcdp->declBit  (c+30,"top cpu CU exception_stall_req_i",-1);
	vcdp->declBit  (c+23,"top cpu CU if_kill_o",-1);
	vcdp->declBus  (c+5,"top cpu CU if_pc_sel_o",-1,1,0);
	vcdp->declBit  (c+315,"top cpu CU if_stall_o",-1);
	vcdp->declBit  (c+6,"top cpu CU id_stall_o",-1);
	vcdp->declBit  (c+19,"top cpu CU ex_stall_o",-1);
	vcdp->declBit  (c+323,"top cpu CU mem_stall_o",-1);
	vcdp->declBit  (c+173,"top cpu CU if_flush_o",-1);
	vcdp->declBit  (c+316,"top cpu CU id_flush_o",-1);
	vcdp->declBit  (c+174,"top cpu CU ex_flush_o",-1);
	vcdp->declBit  (c+175,"top cpu CU mem_flush_o",-1);
	vcdp->declBit  (c+22,"top cpu CU ex_nop_o",-1);
	vcdp->declBus  (c+320,"top cpu CSR ENABLE_COUNTERS",-1,0,0);
	vcdp->declBus  (c+319,"top cpu CSR RESET_ADDR",-1,31,0);
	vcdp->declBit  (c+313,"top cpu CSR clk_i",-1);
	vcdp->declBit  (c+314,"top cpu CSR rst_i",-1);
	vcdp->declBus  (c+243,"top cpu CSR csr_addr_i",-1,11,0);
	vcdp->declBus  (c+242,"top cpu CSR csr_dat_i",-1,31,0);
	vcdp->declBus  (c+244,"top cpu CSR csr_op_i",-1,2,0);
	vcdp->declBus  (c+241,"top cpu CSR csr_rs1_i",-1,4,0);
	vcdp->declBit  (c+323,"top cpu CSR xint_meip_i",-1);
	vcdp->declBit  (c+323,"top cpu CSR xint_mtip_i",-1);
	vcdp->declBit  (c+323,"top cpu CSR xint_msip_i",-1);
	vcdp->declBus  (c+239,"top cpu CSR exception_pc_i",-1,31,0);
	vcdp->declBus  (c+240,"top cpu CSR exception_inst_i",-1,31,0);
	vcdp->declBit  (c+246,"top cpu CSR xcall_i",-1);
	vcdp->declBit  (c+245,"top cpu CSR xbreak_i",-1);
	vcdp->declBit  (c+249,"top cpu CSR inst_addr_misaligned_i",-1);
	vcdp->declBit  (c+250,"top cpu CSR inst_access_fault_i",-1);
	vcdp->declBit  (c+252,"top cpu CSR load_addr_misaligned_i",-1);
	vcdp->declBit  (c+254,"top cpu CSR load_access_fault_i",-1);
	vcdp->declBit  (c+253,"top cpu CSR store_addr_misaligned_i",-1);
	vcdp->declBit  (c+255,"top cpu CSR store_access_fault_i",-1);
	vcdp->declBit  (c+251,"top cpu CSR illegal_inst_i",-1);
	vcdp->declBit  (c+247,"top cpu CSR inst_fence_i",-1);
	vcdp->declBit  (c+248,"top cpu CSR inst_xret_i",-1);
	vcdp->declBit  (c+30,"top cpu CSR exception_stall_req_o",-1);
	vcdp->declBus  (c+29,"top cpu CSR exception_pc_o",-1,31,0);
	vcdp->declBit  (c+326,"top cpu CSR exception_sel_flag_o",-1);
	vcdp->declBus  (c+31,"top cpu CSR csr_dat_o",-1,31,0);
	vcdp->declBus  (c+337,"top cpu CSR HART_ID",-1,31,0);
	vcdp->declBus  (c+338,"top cpu CSR MHARTID",-1,11,0);
	vcdp->declBus  (c+339,"top cpu CSR MVENDORID",-1,11,0);
	vcdp->declBus  (c+340,"top cpu CSR MARCHID",-1,11,0);
	vcdp->declBus  (c+338,"top cpu CSR MIMPID",-1,11,0);
	vcdp->declBus  (c+341,"top cpu CSR MSTATUS",-1,11,0);
	vcdp->declBus  (c+342,"top cpu CSR MISA",-1,11,0);
	vcdp->declBus  (c+343,"top cpu CSR MEDELEG",-1,11,0);
	vcdp->declBus  (c+344,"top cpu CSR MIDELEG",-1,11,0);
	vcdp->declBus  (c+345,"top cpu CSR MIE",-1,11,0);
	vcdp->declBus  (c+346,"top cpu CSR MTVEC",-1,11,0);
	vcdp->declBus  (c+347,"top cpu CSR MCOUNTEREN",-1,11,0);
	vcdp->declBus  (c+348,"top cpu CSR MSCRATCH",-1,11,0);
	vcdp->declBus  (c+349,"top cpu CSR MEPC",-1,11,0);
	vcdp->declBus  (c+350,"top cpu CSR MCAUSE",-1,11,0);
	vcdp->declBus  (c+351,"top cpu CSR MTVAL",-1,11,0);
	vcdp->declBus  (c+352,"top cpu CSR MIP",-1,11,0);
	vcdp->declBus  (c+353,"top cpu CSR MCYCLE",-1,11,0);
	vcdp->declBus  (c+354,"top cpu CSR MINSTRET",-1,11,0);
	vcdp->declBus  (c+355,"top cpu CSR MCYCLEH",-1,11,0);
	vcdp->declBus  (c+356,"top cpu CSR MINSTRETH",-1,11,0);
	vcdp->declBus  (c+357,"top cpu CSR INST_ADDR_MISALIGNED",-1,3,0);
	vcdp->declBus  (c+358,"top cpu CSR INST_ACCESS_FAULT",-1,3,0);
	vcdp->declBus  (c+359,"top cpu CSR ILLEGAL_INST",-1,3,0);
	vcdp->declBus  (c+360,"top cpu CSR BREAKPOINT",-1,3,0);
	vcdp->declBus  (c+361,"top cpu CSR LOAD_ADDR_MISALIGNED",-1,3,0);
	vcdp->declBus  (c+362,"top cpu CSR LOAD_ACCESS_FAULT",-1,3,0);
	vcdp->declBus  (c+363,"top cpu CSR STORE_ADDR_MISALIGNED",-1,3,0);
	vcdp->declBus  (c+364,"top cpu CSR STORE_ACCESS_FAULT",-1,3,0);
	vcdp->declBus  (c+365,"top cpu CSR MCALL",-1,3,0);
	vcdp->declBus  (c+360,"top cpu CSR I_SOFTWARE",-1,3,0);
	vcdp->declBus  (c+364,"top cpu CSR I_TIMER",-1,3,0);
	vcdp->declBus  (c+365,"top cpu CSR I_EXTERNAL",-1,3,0);
	vcdp->declBus  (c+168,"top cpu CSR csr_wdata",-1,31,0);
	vcdp->declBus  (c+272,"top cpu CSR mstatus",-1,31,0);
	vcdp->declBus  (c+273,"top cpu CSR mie",-1,31,0);
	vcdp->declBus  (c+274,"top cpu CSR mtvec",-1,31,0);
	vcdp->declBus  (c+275,"top cpu CSR mscratch",-1,31,0);
	vcdp->declBus  (c+276,"top cpu CSR mepc",-1,31,0);
	vcdp->declBus  (c+277,"top cpu CSR mcause",-1,31,0);
	vcdp->declBus  (c+278,"top cpu CSR mtval",-1,31,0);
	vcdp->declBus  (c+279,"top cpu CSR mip",-1,31,0);
	vcdp->declQuad (c+280,"top cpu CSR mcycle",-1,63,0);
	vcdp->declQuad (c+282,"top cpu CSR minstret",-1,63,0);
	vcdp->declBit  (c+284,"top cpu CSR wen",-1);
	vcdp->declBit  (c+366,"top cpu CSR undef_register",-1);
	vcdp->declBit  (c+285,"top cpu CSR mstatus_mpie",-1);
	vcdp->declBit  (c+286,"top cpu CSR mstatus_mie",-1);
	vcdp->declBit  (c+287,"top cpu CSR mie_meie",-1);
	vcdp->declBit  (c+288,"top cpu CSR mie_mtie",-1);
	vcdp->declBit  (c+289,"top cpu CSR mie_msie",-1);
	vcdp->declBus  (c+169,"top cpu CSR pend_int",-1,31,0);
	vcdp->declBit  (c+170,"top cpu CSR interrupt",-1);
	vcdp->declBit  (c+290,"top cpu CSR mcause_int",-1);
	vcdp->declBus  (c+291,"top cpu CSR mcause_exc",-1,3,0);
	vcdp->declBit  (c+292,"top cpu CSR is_misa",-1);
	vcdp->declBit  (c+293,"top cpu CSR is_mhartid",-1);
	vcdp->declBit  (c+294,"top cpu CSR is_mvendorid",-1);
	vcdp->declBit  (c+295,"top cpu CSR is_marchid",-1);
	vcdp->declBit  (c+293,"top cpu CSR is_mimpid",-1);
	vcdp->declBit  (c+296,"top cpu CSR is_mstatus",-1);
	vcdp->declBit  (c+297,"top cpu CSR is_mie",-1);
	vcdp->declBit  (c+298,"top cpu CSR is_mtvec",-1);
	vcdp->declBit  (c+299,"top cpu CSR is_mepc",-1);
	vcdp->declBit  (c+300,"top cpu CSR is_mcause",-1);
	vcdp->declBit  (c+301,"top cpu CSR is_mtval",-1);
	vcdp->declBit  (c+302,"top cpu CSR is_mip",-1);
	vcdp->declBit  (c+303,"top cpu CSR is_mcycle",-1);
	vcdp->declBit  (c+304,"top cpu CSR is_minstret",-1);
	vcdp->declBit  (c+305,"top cpu CSR is_mcycleh",-1);
	vcdp->declBit  (c+306,"top cpu CSR is_minstreth",-1);
	vcdp->declBit  (c+307,"top cpu CSR is_mscratch",-1);
	vcdp->declBit  (c+171,"top cpu CSR trap_valid",-1);
	vcdp->declBus  (c+172,"top cpu CSR exception_code",-1,3,0);
	vcdp->declBit  (c+308,"top cpu CSR exception_stall",-1);
	vcdp->declBus  (c+367,"top memory ADDR_WIDTH",-1,31,0);
	vcdp->declBus  (c+319,"top memory BASE_ADDR",-1,31,0);
	vcdp->declBus  (c+184,"top memory iwbs_addr_i",-1,31,0);
	vcdp->declBit  (c+185,"top memory iwbs_cyc_i",-1);
	vcdp->declBit  (c+186,"top memory iwbs_stb_i",-1);
	vcdp->declBus  (c+2,"top memory iwbs_dat_o",-1,31,0);
	vcdp->declBit  (c+3,"top memory iwbs_ack_o",-1);
	vcdp->declBus  (c+178,"top memory dwbs_addr_i",-1,31,0);
	vcdp->declBus  (c+180,"top memory dwbs_dat_i",-1,31,0);
	vcdp->declBus  (c+181,"top memory dwbs_sel_i",-1,3,0);
	vcdp->declBit  (c+179,"top memory dwbs_cyc_i",-1);
	vcdp->declBit  (c+182,"top memory dwbs_stb_i",-1);
	vcdp->declBit  (c+183,"top memory dwbs_we_i",-1);
	vcdp->declBus  (c+1,"top memory dwbs_dat_o",-1,31,0);
	vcdp->declBit  (c+4,"top memory dwbs_ack_o",-1);
	vcdp->declBus  (c+368,"top memory BYTES",-1,31,0);
	// Tracing: top memory mem // Ignored: Wide memory > --trace-max-array ents at tests/verilator/ram.v:51
	vcdp->declBus  (c+309,"top memory i_addr",-1,23,0);
	vcdp->declBus  (c+310,"top memory d_addr",-1,23,0);
	vcdp->declBit  (c+311,"top memory i_access",-1);
	vcdp->declBit  (c+312,"top memory d_access",-1);
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
	vcdp->fullBit  (c+3,(vlTOPp->top__DOT__iwbm_ack));
	vcdp->fullBit  (c+4,(vlTOPp->top__DOT__dwbm_ack));
	vcdp->fullBus  (c+5,(vlTOPp->top__DOT__cpu__DOT__if_pc_sel),2);
	vcdp->fullBit  (c+6,(vlTOPp->top__DOT__cpu__DOT__id_stall));
	vcdp->fullBus  (c+7,(vlTOPp->top__DOT__cpu__DOT__EX__DOT__ex_result),32);
	vcdp->fullBus  (c+8,(vlTOPp->top__DOT__cpu__DOT__MEM__DOT__mem_result),32);
	vcdp->fullBus  (c+9,(vlTOPp->top__DOT__cpu__DOT__forward_a_sel),2);
	vcdp->fullBus  (c+10,(vlTOPp->top__DOT__cpu__DOT__forward_b_sel),2);
	vcdp->fullBus  (c+11,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__rs1),5);
	vcdp->fullBus  (c+12,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__rs2),5);
	vcdp->fullBit  (c+13,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__call));
	vcdp->fullBit  (c+14,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT___break));
	vcdp->fullBus  (c+15,((0xfffffffeU & ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__jalr)
					       ? vlTOPp->top__DOT__cpu__DOT__ID__DOT___imm
					       : (vlTOPp->top__DOT__cpu__DOT__id_pc 
						  + vlTOPp->top__DOT__cpu__DOT__ID__DOT___imm)))),32);
	vcdp->fullBus  (c+16,((vlTOPp->top__DOT__cpu__DOT__ID__DOT___imm 
			       + vlTOPp->top__DOT__cpu__DOT__id_pc)),32);
	vcdp->fullBit  (c+17,(vlTOPp->top__DOT__cpu__DOT__take_branch));
	vcdp->fullBit  (c+18,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_j));
	vcdp->fullBit  (c+19,(vlTOPp->top__DOT__cpu__DOT__mem_stall_req));
	vcdp->fullBus  (c+20,(vlTOPp->top__DOT__cpu__DOT__mem_load_data),32);
	vcdp->fullBus  (c+21,(vlTOPp->top__DOT__cpu__DOT__wb_result),32);
	vcdp->fullBit  (c+22,(vlTOPp->top__DOT__cpu__DOT__ex_nop));
	vcdp->fullBit  (c+23,(vlTOPp->top__DOT__cpu__DOT__if_kill));
	vcdp->fullBit  (c+24,(vlTOPp->top__DOT__cpu__DOT__hazard));
	vcdp->fullBit  (c+25,(vlTOPp->top__DOT__cpu__DOT__en_fwd));
	vcdp->fullBit  (c+26,(((IData)(vlTOPp->top__DOT__cpu__DOT__hazard) 
			       & ((0U != (IData)(vlTOPp->top__DOT__cpu__DOT__ex_csr_op)) 
				  | (0U != (IData)(vlTOPp->top__DOT__cpu__DOT__mem_csr_op))))));
	vcdp->fullBit  (c+27,(vlTOPp->top__DOT__cpu__DOT__HZ__DOT__ld));
	vcdp->fullBit  (c+28,(vlTOPp->top__DOT__cpu__DOT__HZ__DOT__xcall_break));
	vcdp->fullBus  (c+29,(vlTOPp->top__DOT__cpu__DOT__exception_pc),32);
	vcdp->fullBit  (c+30,(vlTOPp->top__DOT__cpu__DOT__exception_stall_req));
	vcdp->fullBus  (c+31,(vlTOPp->top__DOT__cpu__DOT__csr_data_o),32);
	vcdp->fullBus  (c+32,(((2U & (IData)(vlTOPp->top__DOT__cpu__DOT__if_pc_sel))
			        ? ((1U & (IData)(vlTOPp->top__DOT__cpu__DOT__if_pc_sel))
				    ? vlTOPp->top__DOT__cpu__DOT__exception_pc
				    : (0xfffffffeU 
				       & ((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__jalr)
					   ? vlTOPp->top__DOT__cpu__DOT__ID__DOT___imm
					   : (vlTOPp->top__DOT__cpu__DOT__id_pc 
					      + vlTOPp->top__DOT__cpu__DOT__ID__DOT___imm))))
			        : ((1U & (IData)(vlTOPp->top__DOT__cpu__DOT__if_pc_sel))
				    ? (vlTOPp->top__DOT__cpu__DOT__ID__DOT___imm 
				       + vlTOPp->top__DOT__cpu__DOT__id_pc)
				    : ((IData)(4U) 
				       + vlTOPp->top__DOT__cpu__DOT__if_pc)))),32);
	vcdp->fullBus  (c+33,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__muxa_i),32);
	vcdp->fullBus  (c+34,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__muxb_i),32);
	vcdp->fullBus  (c+35,(((0U == (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__rs1))
			        ? 0U : vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file
			       [vlTOPp->top__DOT__cpu__DOT__ID__DOT__rs1])),32);
	vcdp->fullBus  (c+36,(((0U == (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__rs2))
			        ? 0U : vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file
			       [vlTOPp->top__DOT__cpu__DOT__ID__DOT__rs2])),32);
	vcdp->fullBit  (c+37,(((0U != (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__waddr)) 
			       & (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_wr))));
	vcdp->fullBus  (c+38,((((((((((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_add) 
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
	vcdp->fullBus  (c+39,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__comparator_op),3);
	vcdp->fullBus  (c+40,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__imm),32);
	vcdp->fullBus  (c+41,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__waddr),5);
	vcdp->fullBit  (c+42,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_immop));
	vcdp->fullBit  (c+43,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__porta_sel));
	vcdp->fullBus  (c+44,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__port_a),32);
	vcdp->fullBus  (c+45,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__port_b),32);
	vcdp->fullBit  (c+46,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__jalr));
	vcdp->fullBus  (c+47,((((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_st) 
				<< 5U) | (((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_ld) 
					   << 4U) | 
					  (((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_word) 
					    << 3U) 
					   | (((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_hw) 
					       << 2U) 
					      | (((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_byte) 
						  << 1U) 
						 | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_ldu))))))),6);
	vcdp->fullBit  (c+48,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_ld));
	vcdp->fullBus  (c+49,(((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__jalr)
			        ? vlTOPp->top__DOT__cpu__DOT__ID__DOT___imm
			        : (vlTOPp->top__DOT__cpu__DOT__id_pc 
				   + vlTOPp->top__DOT__cpu__DOT__ID__DOT___imm))),32);
	vcdp->fullBit  (c+50,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_b));
	vcdp->fullBit  (c+51,(((4U & (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__comparator_op))
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
	vcdp->fullBus  (c+52,(((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_csri)
			        ? (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__rs1)
			        : vlTOPp->top__DOT__cpu__DOT__ID__DOT__port_a)),32);
	vcdp->fullBus  (c+53,((((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__rc) 
				<< 2U) | (((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__rs) 
					   << 1U) | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__rw)))),3);
	vcdp->fullBit  (c+54,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_csri));
	vcdp->fullBit  (c+55,(((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__fence) 
			       & (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__fencei))));
	vcdp->fullBit  (c+56,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__xret));
	vcdp->fullBit  (c+57,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__illegal));
	vcdp->fullBit  (c+58,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_shift));
	vcdp->fullBus  (c+59,(((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_j)
			        ? ((IData)(4U) + vlTOPp->top__DOT__cpu__DOT__id_pc)
			        : vlTOPp->top__DOT__cpu__DOT__id_pc)),32);
	vcdp->fullBus  (c+60,(vlTOPp->top__DOT__cpu__DOT__ID__DOT___port_b),32);
	vcdp->fullBus  (c+61,((0x1fU & vlTOPp->top__DOT__cpu__DOT__ID__DOT___port_b)),32);
	vcdp->fullBus  (c+62,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[0]),32);
	vcdp->fullBus  (c+63,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[1]),32);
	vcdp->fullBus  (c+64,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[2]),32);
	vcdp->fullBus  (c+65,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[3]),32);
	vcdp->fullBus  (c+66,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[4]),32);
	vcdp->fullBus  (c+67,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[5]),32);
	vcdp->fullBus  (c+68,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[6]),32);
	vcdp->fullBus  (c+69,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[7]),32);
	vcdp->fullBus  (c+70,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[8]),32);
	vcdp->fullBus  (c+71,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[9]),32);
	vcdp->fullBus  (c+72,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[10]),32);
	vcdp->fullBus  (c+73,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[11]),32);
	vcdp->fullBus  (c+74,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[12]),32);
	vcdp->fullBus  (c+75,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[13]),32);
	vcdp->fullBus  (c+76,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[14]),32);
	vcdp->fullBus  (c+77,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[15]),32);
	vcdp->fullBus  (c+78,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[16]),32);
	vcdp->fullBus  (c+79,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[17]),32);
	vcdp->fullBus  (c+80,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[18]),32);
	vcdp->fullBus  (c+81,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[19]),32);
	vcdp->fullBus  (c+82,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[20]),32);
	vcdp->fullBus  (c+83,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[21]),32);
	vcdp->fullBus  (c+84,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[22]),32);
	vcdp->fullBus  (c+85,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[23]),32);
	vcdp->fullBus  (c+86,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[24]),32);
	vcdp->fullBus  (c+87,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[25]),32);
	vcdp->fullBus  (c+88,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[26]),32);
	vcdp->fullBus  (c+89,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[27]),32);
	vcdp->fullBus  (c+90,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[28]),32);
	vcdp->fullBus  (c+91,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[29]),32);
	vcdp->fullBus  (c+92,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[30]),32);
	vcdp->fullBus  (c+93,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__RF__DOT__reg_file[31]),32);
	vcdp->fullBus  (c+94,((((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_word) 
				<< 2U) | (((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_hw) 
					   << 1U) | (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_byte)))),3);
	vcdp->fullBit  (c+95,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_st));
	vcdp->fullBit  (c+96,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_ldu));
	vcdp->fullBit  (c+97,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__lui));
	vcdp->fullBit  (c+98,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__auipc));
	vcdp->fullBit  (c+99,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__jal));
	vcdp->fullBit  (c+100,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__beq));
	vcdp->fullBit  (c+101,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__bne));
	vcdp->fullBit  (c+102,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__blt));
	vcdp->fullBit  (c+103,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__bge));
	vcdp->fullBit  (c+104,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__bltu));
	vcdp->fullBit  (c+105,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__bgeu));
	vcdp->fullBit  (c+106,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__lb));
	vcdp->fullBit  (c+107,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__lh));
	vcdp->fullBit  (c+108,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__lw));
	vcdp->fullBit  (c+109,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__lbu));
	vcdp->fullBit  (c+110,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__lhu));
	vcdp->fullBit  (c+111,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sb));
	vcdp->fullBit  (c+112,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sh));
	vcdp->fullBit  (c+113,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sw));
	vcdp->fullBit  (c+114,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__addi));
	vcdp->fullBit  (c+115,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__slti));
	vcdp->fullBit  (c+116,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sltiu));
	vcdp->fullBit  (c+117,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__xori));
	vcdp->fullBit  (c+118,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__ori));
	vcdp->fullBit  (c+119,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__andi));
	vcdp->fullBit  (c+120,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__slli));
	vcdp->fullBit  (c+121,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__srli));
	vcdp->fullBit  (c+122,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__srai));
	vcdp->fullBit  (c+123,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__add));
	vcdp->fullBit  (c+124,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sub));
	vcdp->fullBit  (c+125,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sll));
	vcdp->fullBit  (c+126,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__slt));
	vcdp->fullBit  (c+127,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sltu));
	vcdp->fullBit  (c+128,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__srl));
	vcdp->fullBit  (c+129,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__sra));
	vcdp->fullBit  (c+130,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__fence));
	vcdp->fullBit  (c+131,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__fencei));
	vcdp->fullBit  (c+132,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__rw));
	vcdp->fullBit  (c+133,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__rs));
	vcdp->fullBit  (c+134,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__rc));
	vcdp->fullBit  (c+135,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__rwi));
	vcdp->fullBit  (c+136,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__rsi));
	vcdp->fullBit  (c+137,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__rci));
	vcdp->fullBit  (c+138,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_imm));
	vcdp->fullBit  (c+139,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_add));
	vcdp->fullBit  (c+140,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_sub));
	vcdp->fullBit  (c+141,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_and));
	vcdp->fullBit  (c+142,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_xor));
	vcdp->fullBit  (c+143,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_or));
	vcdp->fullBit  (c+144,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_sll));
	vcdp->fullBit  (c+145,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_sr));
	vcdp->fullBit  (c+146,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_slt));
	vcdp->fullBit  (c+147,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_sltu));
	vcdp->fullBit  (c+148,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_wr));
	vcdp->fullBit  (c+149,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_alu));
	vcdp->fullBit  (c+150,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_immop));
	vcdp->fullBit  (c+151,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_csr));
	vcdp->fullBit  (c+152,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_fence));
	vcdp->fullBit  (c+153,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_word));
	vcdp->fullBit  (c+154,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_byte));
	vcdp->fullBit  (c+155,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__is_hw));
	vcdp->fullBit  (c+156,(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__uimp));
	vcdp->fullBit  (c+157,(vlTOPp->top__DOT__cpu__DOT__FWD__DOT__ex_fwd_a));
	vcdp->fullBit  (c+158,(vlTOPp->top__DOT__cpu__DOT__FWD__DOT__ex_fwd_b));
	vcdp->fullBit  (c+159,(vlTOPp->top__DOT__cpu__DOT__FWD__DOT__mem_fwd_a));
	vcdp->fullBit  (c+160,(vlTOPp->top__DOT__cpu__DOT__FWD__DOT__mem_fwd_b));
	vcdp->fullBit  (c+161,(vlTOPp->top__DOT__cpu__DOT__FWD__DOT__wb_fwd_a));
	vcdp->fullBit  (c+162,(vlTOPp->top__DOT__cpu__DOT__FWD__DOT__wb_fwd_b));
	vcdp->fullBus  (c+163,(vlTOPp->top__DOT__cpu__DOT__LSU__DOT__wdata),32);
	vcdp->fullBus  (c+164,(vlTOPp->top__DOT__cpu__DOT__LSU__DOT__wsel_o),4);
	vcdp->fullBus  (c+165,(vlTOPp->top__DOT__cpu__DOT__LSU__DOT__rsel_o),4);
	vcdp->fullBit  (c+166,(vlTOPp->top__DOT__cpu__DOT__LSU__DOT__runsigned));
	vcdp->fullBit  (c+167,(((IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT__call) 
				| (IData)(vlTOPp->top__DOT__cpu__DOT__ID__DOT__DCU__DOT___break))));
	vcdp->fullBus  (c+168,(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__csr_wdata),32);
	vcdp->fullBus  (c+169,(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__pend_int),32);
	vcdp->fullBit  (c+170,(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__interrupt));
	vcdp->fullBit  (c+171,(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__trap_valid));
	vcdp->fullBus  (c+172,(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__exception_code),4);
	vcdp->fullBit  (c+173,(vlTOPp->top__DOT__cpu__DOT__if_flush));
	vcdp->fullBit  (c+174,(vlTOPp->top__DOT__cpu__DOT__ex_flush));
	vcdp->fullBit  (c+175,(vlTOPp->top__DOT__cpu__DOT__mem_flush));
	vcdp->fullBit  (c+176,(vlTOPp->top__DOT__cpu__DOT____Vcellinp__IF__if_stall));
	vcdp->fullBit  (c+177,(vlTOPp->top__DOT__cpu__DOT____Vcellinp__ID__id_flush_i));
	vcdp->fullBus  (c+178,(vlTOPp->top__DOT__cpu__DOT__mem_result),32);
	vcdp->fullBit  (c+179,(vlTOPp->top__DOT__dwbm_cyc));
	vcdp->fullBus  (c+180,(vlTOPp->top__DOT__dwbm_dat_o),32);
	vcdp->fullBus  (c+181,(vlTOPp->top__DOT__dwbm_sel),4);
	vcdp->fullBit  (c+182,(vlTOPp->top__DOT__dwbm_stb));
	vcdp->fullBit  (c+183,(vlTOPp->top__DOT__dwbm_we));
	vcdp->fullBus  (c+184,(vlTOPp->top__DOT__cpu__DOT__if_pc),32);
	vcdp->fullBit  (c+185,(vlTOPp->top__DOT__iwbm_cyc));
	vcdp->fullBit  (c+186,(vlTOPp->top__DOT__iwbm_stb));
	vcdp->fullBus  (c+187,(vlTOPp->top__DOT__cpu__DOT__id_instruction),32);
	vcdp->fullBus  (c+188,(vlTOPp->top__DOT__cpu__DOT__id_pc),32);
	vcdp->fullBus  (c+189,(vlTOPp->top__DOT__cpu__DOT__wb_waddr),5);
	vcdp->fullBit  (c+190,(vlTOPp->top__DOT__cpu__DOT__wb_we));
	vcdp->fullBit  (c+191,(vlTOPp->top__DOT__cpu__DOT__id_inst_addr_misaligned));
	vcdp->fullBit  (c+192,(vlTOPp->top__DOT__cpu__DOT__id_inst_access_fault));
	vcdp->fullBus  (c+193,(vlTOPp->top__DOT__cpu__DOT__ex_rs1),5);
	vcdp->fullBus  (c+194,(vlTOPp->top__DOT__cpu__DOT__ex_pc),32);
	vcdp->fullBus  (c+195,(vlTOPp->top__DOT__cpu__DOT__ex_instruction),32);
	vcdp->fullBus  (c+196,(vlTOPp->top__DOT__cpu__DOT__ex_port_a),32);
	vcdp->fullBus  (c+197,(vlTOPp->top__DOT__cpu__DOT__ex_port_b),32);
	vcdp->fullBus  (c+198,(vlTOPp->top__DOT__cpu__DOT__ex_alu_op),4);
	vcdp->fullBus  (c+199,(vlTOPp->top__DOT__cpu__DOT__ex_waddr),5);
	vcdp->fullBit  (c+200,(vlTOPp->top__DOT__cpu__DOT__ex_we));
	vcdp->fullBus  (c+201,(vlTOPp->top__DOT__cpu__DOT__ex_mem_flags),6);
	vcdp->fullBit  (c+202,(vlTOPp->top__DOT__cpu__DOT__ex_mem_ex_sel));
	vcdp->fullBit  (c+203,(vlTOPp->top__DOT__cpu__DOT__ex_break_op));
	vcdp->fullBit  (c+204,(vlTOPp->top__DOT__cpu__DOT__ex_syscall_op));
	vcdp->fullBus  (c+205,(vlTOPp->top__DOT__cpu__DOT__ex_csr_op),3);
	vcdp->fullBus  (c+206,(vlTOPp->top__DOT__cpu__DOT__ex_csr_data),32);
	vcdp->fullBus  (c+207,(vlTOPp->top__DOT__cpu__DOT__ex_csr_addr),12);
	vcdp->fullBit  (c+208,(vlTOPp->top__DOT__cpu__DOT__ex_fence_op));
	vcdp->fullBit  (c+209,(vlTOPp->top__DOT__cpu__DOT__ex_xret_op));
	vcdp->fullBit  (c+210,(vlTOPp->top__DOT__cpu__DOT__ex_inst_addr_misaligned));
	vcdp->fullBit  (c+211,(vlTOPp->top__DOT__cpu__DOT__ex_inst_access_fault));
	vcdp->fullBit  (c+212,(vlTOPp->top__DOT__cpu__DOT__ex_illegal_inst));
	vcdp->fullBus  (c+213,(vlTOPp->top__DOT__cpu__DOT__ex_store_data),32);
	vcdp->fullBus  (c+214,(vlTOPp->top__DOT__cpu__DOT__mem_pc),32);
	vcdp->fullBus  (c+215,(vlTOPp->top__DOT__cpu__DOT__mem_instruction),32);
	vcdp->fullBus  (c+216,(vlTOPp->top__DOT__cpu__DOT__mem_waddr),5);
	vcdp->fullBus  (c+217,(vlTOPp->top__DOT__cpu__DOT__mem_rs1),5);
	vcdp->fullBit  (c+218,(vlTOPp->top__DOT__cpu__DOT__mem_we));
	vcdp->fullBus  (c+219,(vlTOPp->top__DOT__cpu__DOT__mem_mem_flags),6);
	vcdp->fullBit  (c+220,(vlTOPp->top__DOT__cpu__DOT__mem_mem_ex_sel));
	vcdp->fullBus  (c+221,(vlTOPp->top__DOT__cpu__DOT__mem_csr_data),32);
	vcdp->fullBus  (c+222,(vlTOPp->top__DOT__cpu__DOT__mem_csr_op),3);
	vcdp->fullBus  (c+223,(vlTOPp->top__DOT__cpu__DOT__mem_csr_addr),12);
	vcdp->fullBit  (c+224,(vlTOPp->top__DOT__cpu__DOT__mem_break_op));
	vcdp->fullBit  (c+225,(vlTOPp->top__DOT__cpu__DOT__mem_syscall_op));
	vcdp->fullBit  (c+226,((1U & ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_mem_flags) 
				      >> 5U))));
	vcdp->fullBit  (c+227,((1U & ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_mem_flags) 
				      >> 4U))));
	vcdp->fullBit  (c+228,((1U & ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_mem_flags) 
				      >> 3U))));
	vcdp->fullBit  (c+229,((1U & ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_mem_flags) 
				      >> 2U))));
	vcdp->fullBit  (c+230,((1U & ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_mem_flags) 
				      >> 1U))));
	vcdp->fullBit  (c+231,((1U & (IData)(vlTOPp->top__DOT__cpu__DOT__mem_mem_flags))));
	vcdp->fullBus  (c+232,(vlTOPp->top__DOT__cpu__DOT__mem_store_data),32);
	vcdp->fullBit  (c+233,(vlTOPp->top__DOT__cpu__DOT__mem_fence_op));
	vcdp->fullBit  (c+234,(vlTOPp->top__DOT__cpu__DOT__mem_xret_op));
	vcdp->fullBit  (c+235,(vlTOPp->top__DOT__cpu__DOT__mem_inst_addr_misaligned));
	vcdp->fullBit  (c+236,(vlTOPp->top__DOT__cpu__DOT__mem_inst_access_fault));
	vcdp->fullBit  (c+237,(vlTOPp->top__DOT__cpu__DOT__mem_illegal_inst));
	vcdp->fullBus  (c+238,(vlTOPp->top__DOT__cpu__DOT__wb_result_mem),32);
	vcdp->fullBus  (c+239,(vlTOPp->top__DOT__cpu__DOT__wb_pc),32);
	vcdp->fullBus  (c+240,(vlTOPp->top__DOT__cpu__DOT__wb_instruction),32);
	vcdp->fullBus  (c+241,(vlTOPp->top__DOT__cpu__DOT__wb_rs1),5);
	vcdp->fullBus  (c+242,(vlTOPp->top__DOT__cpu__DOT__wb_csr_data),32);
	vcdp->fullBus  (c+243,(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr),12);
	vcdp->fullBus  (c+244,(vlTOPp->top__DOT__cpu__DOT__wb_csr_op),3);
	vcdp->fullBit  (c+245,(vlTOPp->top__DOT__cpu__DOT__wb_break_op));
	vcdp->fullBit  (c+246,(vlTOPp->top__DOT__cpu__DOT__wb_syscall_op));
	vcdp->fullBit  (c+247,(vlTOPp->top__DOT__cpu__DOT__wb_fence_op));
	vcdp->fullBit  (c+248,(vlTOPp->top__DOT__cpu__DOT__wb_xret_op));
	vcdp->fullBit  (c+249,(vlTOPp->top__DOT__cpu__DOT__wb_inst_addr_misaligned));
	vcdp->fullBit  (c+250,(vlTOPp->top__DOT__cpu__DOT__wb_inst_access_fault));
	vcdp->fullBit  (c+251,(vlTOPp->top__DOT__cpu__DOT__wb_illegal_inst));
	vcdp->fullBit  (c+252,(vlTOPp->top__DOT__cpu__DOT__wb_load_addr_misaligned));
	vcdp->fullBit  (c+253,(vlTOPp->top__DOT__cpu__DOT__wb_store_addr_misaligned));
	vcdp->fullBit  (c+254,(vlTOPp->top__DOT__cpu__DOT__wb_load_access_fault));
	vcdp->fullBit  (c+255,(vlTOPp->top__DOT__cpu__DOT__wb_store_access_fault));
	vcdp->fullBus  (c+256,(((IData)(4U) + vlTOPp->top__DOT__cpu__DOT__if_pc)),32);
	vcdp->fullBit  (c+257,((0U != (3U & vlTOPp->top__DOT__cpu__DOT__if_pc))));
	vcdp->fullBus  (c+258,((0xfffU & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
					  >> 0x14U))),12);
	vcdp->fullBus  (c+259,((0x7fU & vlTOPp->top__DOT__cpu__DOT__id_instruction)),7);
	vcdp->fullBus  (c+260,((7U & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
				      >> 0xcU))),3);
	vcdp->fullBus  (c+261,((0x7fU & (vlTOPp->top__DOT__cpu__DOT__id_instruction 
					 >> 0x19U))),7);
	vcdp->fullBit  (c+262,((1U & ((1U & (((IData)(vlTOPp->top__DOT__cpu__DOT__mem_mem_flags) 
					      >> 4U) 
					     & ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_mem_flags) 
						>> 3U)))
				       ? (0U != (3U 
						 & vlTOPp->top__DOT__cpu__DOT__mem_result))
				       : ((((IData)(vlTOPp->top__DOT__cpu__DOT__mem_mem_flags) 
					    >> 4U) 
					   & ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_mem_flags) 
					      >> 2U)) 
					  & vlTOPp->top__DOT__cpu__DOT__mem_result)))));
	vcdp->fullBit  (c+263,((1U & ((1U & (((IData)(vlTOPp->top__DOT__cpu__DOT__mem_mem_flags) 
					      >> 5U) 
					     & ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_mem_flags) 
						>> 3U)))
				       ? (0U != (3U 
						 & vlTOPp->top__DOT__cpu__DOT__mem_result))
				       : ((((IData)(vlTOPp->top__DOT__cpu__DOT__mem_mem_flags) 
					    >> 5U) 
					   & ((IData)(vlTOPp->top__DOT__cpu__DOT__mem_mem_flags) 
					      >> 2U)) 
					  & vlTOPp->top__DOT__cpu__DOT__mem_result)))));
	vcdp->fullBit  (c+264,((0U != (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_op))));
	vcdp->fullBus  (c+265,(vlTOPp->top__DOT__cpu__DOT__LSU__DOT__i_state),2);
	vcdp->fullBus  (c+266,(vlTOPp->top__DOT__cpu__DOT__LSU__DOT__d_state),2);
	vcdp->fullBit  (c+267,(vlTOPp->top__DOT__cpu__DOT__LSU__DOT__kill));
	vcdp->fullBit  (c+268,(((IData)(vlTOPp->top__DOT__cpu__DOT__ex_syscall_op) 
				| (IData)(vlTOPp->top__DOT__cpu__DOT__ex_break_op))));
	vcdp->fullBit  (c+269,(((IData)(vlTOPp->top__DOT__cpu__DOT__mem_syscall_op) 
				| (IData)(vlTOPp->top__DOT__cpu__DOT__mem_break_op))));
	vcdp->fullBit  (c+270,((0U != (IData)(vlTOPp->top__DOT__cpu__DOT__ex_csr_op))));
	vcdp->fullBit  (c+271,((0U != (IData)(vlTOPp->top__DOT__cpu__DOT__mem_csr_op))));
	vcdp->fullBus  (c+272,(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mstatus),32);
	vcdp->fullBus  (c+273,(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mie),32);
	vcdp->fullBus  (c+274,(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mtvec),32);
	vcdp->fullBus  (c+275,(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mscratch),32);
	vcdp->fullBus  (c+276,(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mepc),32);
	vcdp->fullBus  (c+277,(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mcause),32);
	vcdp->fullBus  (c+278,(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mtval),32);
	vcdp->fullBus  (c+279,(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mip),32);
	vcdp->fullQuad (c+280,(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mcycle),64);
	vcdp->fullQuad (c+282,(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__minstret),64);
	vcdp->fullBit  (c+284,((0U != (IData)(vlTOPp->top__DOT__cpu__DOT__wb_rs1))));
	vcdp->fullBit  (c+285,(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mstatus_mpie));
	vcdp->fullBit  (c+286,(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mstatus_mie));
	vcdp->fullBit  (c+287,(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mie_meie));
	vcdp->fullBit  (c+288,(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mie_mtie));
	vcdp->fullBit  (c+289,(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mie_msie));
	vcdp->fullBit  (c+290,(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mcause_int));
	vcdp->fullBus  (c+291,(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__mcause_exc),4);
	vcdp->fullBit  (c+292,((0x301U == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))));
	vcdp->fullBit  (c+293,((0xf14U == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))));
	vcdp->fullBit  (c+294,((0xf11U == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))));
	vcdp->fullBit  (c+295,((0xf12U == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))));
	vcdp->fullBit  (c+296,((0x300U == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))));
	vcdp->fullBit  (c+297,((0x304U == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))));
	vcdp->fullBit  (c+298,((0x305U == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))));
	vcdp->fullBit  (c+299,((0x341U == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))));
	vcdp->fullBit  (c+300,((0x342U == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))));
	vcdp->fullBit  (c+301,((0x343U == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))));
	vcdp->fullBit  (c+302,((0x344U == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))));
	vcdp->fullBit  (c+303,((0xb00U == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))));
	vcdp->fullBit  (c+304,((0xb02U == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))));
	vcdp->fullBit  (c+305,((0xb80U == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))));
	vcdp->fullBit  (c+306,((0xb82U == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))));
	vcdp->fullBit  (c+307,((0x340U == (IData)(vlTOPp->top__DOT__cpu__DOT__wb_csr_addr))));
	vcdp->fullBit  (c+308,(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__exception_stall));
	vcdp->fullBus  (c+309,((0xfffffcU & vlTOPp->top__DOT__cpu__DOT__if_pc)),24);
	vcdp->fullBus  (c+310,((0xfffffcU & vlTOPp->top__DOT__cpu__DOT__mem_result)),24);
	vcdp->fullBit  (c+311,((0x80U == (0xffU & (vlTOPp->top__DOT__cpu__DOT__if_pc 
						   >> 0x18U)))));
	vcdp->fullBit  (c+312,((0x80U == (0xffU & (vlTOPp->top__DOT__cpu__DOT__mem_result 
						   >> 0x18U)))));
	vcdp->fullBit  (c+313,(vlTOPp->clk_i));
	vcdp->fullBit  (c+314,(vlTOPp->rst_i));
	vcdp->fullBit  (c+315,((1U & (((((~ (IData)(vlTOPp->rst_i)) 
					 & (~ (IData)(vlTOPp->top__DOT__iwbm_ack))) 
					| (IData)(vlTOPp->top__DOT__cpu__DOT__LSU__DOT__kill)) 
				       | (IData)(vlTOPp->top__DOT__cpu__DOT__id_stall)) 
				      | (IData)(vlTOPp->top__DOT__cpu__DOT__HZ__DOT__ld)))));
	vcdp->fullBit  (c+316,(((IData)(vlTOPp->rst_i) 
				| (IData)(vlTOPp->top__DOT__cpu__DOT__exception_stall_req))));
	vcdp->fullBit  (c+317,((1U & (((~ (IData)(vlTOPp->rst_i)) 
				       & (~ (IData)(vlTOPp->top__DOT__iwbm_ack))) 
				      | (IData)(vlTOPp->top__DOT__cpu__DOT__LSU__DOT__kill)))));
	vcdp->fullBus  (c+318,(0U),32);
	vcdp->fullBus  (c+319,(0x80000000U),32);
	vcdp->fullBit  (c+320,(1U));
	vcdp->fullBus  (c+321,(0x1000000U),32);
	vcdp->fullBit  (c+322,(0U));
	vcdp->fullBit  (c+323,(0U));
	vcdp->fullBit  (c+324,(vlTOPp->top__DOT__cpu__DOT__csr_dependence));
	vcdp->fullBit  (c+325,(vlTOPp->top__DOT__cpu__DOT__ld_dependence));
	vcdp->fullBit  (c+326,(vlTOPp->top__DOT__cpu__DOT__exception_sel_flag));
	vcdp->fullBus  (c+327,(1U),3);
	vcdp->fullBus  (c+328,(2U),3);
	vcdp->fullBus  (c+329,(3U),3);
	vcdp->fullBus  (c+330,(4U),3);
	vcdp->fullBus  (c+331,(5U),3);
	vcdp->fullBus  (c+332,(6U),3);
	vcdp->fullBus  (c+333,(0U),3);
	vcdp->fullBus  (c+334,(0U),2);
	vcdp->fullBus  (c+335,(1U),2);
	vcdp->fullBus  (c+336,(2U),2);
	vcdp->fullBus  (c+337,(0U),32);
	vcdp->fullBus  (c+338,(0xf14U),12);
	vcdp->fullBus  (c+339,(0xf11U),12);
	vcdp->fullBus  (c+340,(0xf12U),12);
	vcdp->fullBus  (c+341,(0x300U),12);
	vcdp->fullBus  (c+342,(0x301U),12);
	vcdp->fullBus  (c+343,(0x302U),12);
	vcdp->fullBus  (c+344,(0x303U),12);
	vcdp->fullBus  (c+345,(0x304U),12);
	vcdp->fullBus  (c+346,(0x305U),12);
	vcdp->fullBus  (c+347,(0x306U),12);
	vcdp->fullBus  (c+348,(0x340U),12);
	vcdp->fullBus  (c+349,(0x341U),12);
	vcdp->fullBus  (c+350,(0x342U),12);
	vcdp->fullBus  (c+351,(0x343U),12);
	vcdp->fullBus  (c+352,(0x344U),12);
	vcdp->fullBus  (c+353,(0xb00U),12);
	vcdp->fullBus  (c+354,(0xb02U),12);
	vcdp->fullBus  (c+355,(0xb80U),12);
	vcdp->fullBus  (c+356,(0xb82U),12);
	vcdp->fullBus  (c+357,(0U),4);
	vcdp->fullBus  (c+358,(1U),4);
	vcdp->fullBus  (c+359,(2U),4);
	vcdp->fullBus  (c+360,(3U),4);
	vcdp->fullBus  (c+361,(4U),4);
	vcdp->fullBus  (c+362,(5U),4);
	vcdp->fullBus  (c+363,(6U),4);
	vcdp->fullBus  (c+364,(7U),4);
	vcdp->fullBus  (c+365,(0xbU),4);
	vcdp->fullBit  (c+366,(vlTOPp->top__DOT__cpu__DOT__CSR__DOT__undef_register));
	vcdp->fullBus  (c+367,(0x18U),32);
	vcdp->fullBus  (c+368,(0x1000000U),32);
    }
}
