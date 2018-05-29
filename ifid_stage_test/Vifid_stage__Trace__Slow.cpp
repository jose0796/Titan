// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vifid_stage__Syms.h"


//======================

void Vifid_stage::trace (VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback (&Vifid_stage::traceInit, &Vifid_stage::traceFull, &Vifid_stage::traceChg, this);
}
void Vifid_stage::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    Vifid_stage* t=(Vifid_stage*)userthis;
    Vifid_stage__Syms* __restrict vlSymsp = t->__VlSymsp; // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) vl_fatal(__FILE__,__LINE__,__FILE__,"Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    vcdp->scopeEscape(' ');
    t->traceInitThis (vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void Vifid_stage::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vifid_stage* t=(Vifid_stage*)userthis;
    Vifid_stage__Syms* __restrict vlSymsp = t->__VlSymsp; // Setup global symbol table
    t->traceFullThis (vlSymsp, vcdp, code);
}

//======================


void Vifid_stage::traceInitThis(Vifid_stage__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vifid_stage* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name()); // Setup signal names
    // Body
    {
	vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void Vifid_stage::traceFullThis(Vifid_stage__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vifid_stage* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vifid_stage::traceInitThis__1(Vifid_stage__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vifid_stage* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->declBit  (c+164,"clk_i",-1);
	vcdp->declBit  (c+165,"rst_i",-1);
	vcdp->declBus  (c+166,"ex_port_a",-1,31,0);
	vcdp->declBus  (c+167,"ex_port_b",-1,31,0);
	vcdp->declBus  (c+168,"ex_alu_op",-1,3,0);
	vcdp->declBus  (c+169,"ex_waddr",-1,4,0);
	vcdp->declBit  (c+170,"ex_we",-1);
	vcdp->declBus  (c+171,"ex_mem_flags",-1,5,0);
	vcdp->declBit  (c+172,"ex_mem_ex_sel",-1);
	vcdp->declBit  (c+173,"ex_jump_op",-1);
	vcdp->declBit  (c+174,"ex_bad_jump_addr",-1);
	vcdp->declBit  (c+175,"ex_branch_op",-1);
	vcdp->declBit  (c+176,"ex_bad_branch_addr",-1);
	vcdp->declBit  (c+177,"take_branch",-1);
	vcdp->declBit  (c+178,"ex_break_op",-1);
	vcdp->declBit  (c+179,"ex_syscall_op",-1);
	vcdp->declBus  (c+180,"ex_csr_op",-1,2,0);
	vcdp->declBit  (c+181,"ex_csr_imm_op",-1);
	vcdp->declBit  (c+182,"ex_exc_addr_if_o",-1);
	vcdp->declBit  (c+183,"ex_ready",-1);
	vcdp->declBit  (c+164,"ifid_stage clk_i",-1);
	vcdp->declBit  (c+165,"ifid_stage rst_i",-1);
	vcdp->declBus  (c+166,"ifid_stage ex_port_a",-1,31,0);
	vcdp->declBus  (c+167,"ifid_stage ex_port_b",-1,31,0);
	vcdp->declBus  (c+168,"ifid_stage ex_alu_op",-1,3,0);
	vcdp->declBus  (c+169,"ifid_stage ex_waddr",-1,4,0);
	vcdp->declBit  (c+170,"ifid_stage ex_we",-1);
	vcdp->declBus  (c+171,"ifid_stage ex_mem_flags",-1,5,0);
	vcdp->declBit  (c+172,"ifid_stage ex_mem_ex_sel",-1);
	vcdp->declBit  (c+173,"ifid_stage ex_jump_op",-1);
	vcdp->declBit  (c+174,"ifid_stage ex_bad_jump_addr",-1);
	vcdp->declBit  (c+175,"ifid_stage ex_branch_op",-1);
	vcdp->declBit  (c+176,"ifid_stage ex_bad_branch_addr",-1);
	vcdp->declBit  (c+177,"ifid_stage take_branch",-1);
	vcdp->declBit  (c+178,"ifid_stage ex_break_op",-1);
	vcdp->declBit  (c+179,"ifid_stage ex_syscall_op",-1);
	vcdp->declBus  (c+180,"ifid_stage ex_csr_op",-1,2,0);
	vcdp->declBit  (c+181,"ifid_stage ex_csr_imm_op",-1);
	vcdp->declBit  (c+182,"ifid_stage ex_exc_addr_if_o",-1);
	vcdp->declBit  (c+183,"ifid_stage ex_ready",-1);
	vcdp->declBit  (c+184,"ifid_stage if_stall",-1);
	vcdp->declBus  (c+127,"ifid_stage id_pc",-1,31,0);
	vcdp->declBus  (c+128,"ifid_stage id_pc_add4",-1,31,0);
	vcdp->declBus  (c+129,"ifid_stage id_instruction",-1,31,0);
	vcdp->declBit  (c+130,"ifid_stage id_exc_addr",-1);
	vcdp->declBit  (c+131,"ifid_stage id_ready_o",-1);
	vcdp->declBit  (c+185,"ifid_stage exc_addr_if",-1);
	vcdp->declBit  (c+186,"ifid_stage forward_sel",-1);
	vcdp->declBus  (c+114,"ifid_stage pc_branch_address",-1,31,0);
	vcdp->declBus  (c+123,"ifid_stage pc_jump_address",-1,31,0);
	vcdp->declBit  (c+187,"ifid_stage ex_exc_addr_if",-1);
	vcdp->declBit  (c+164,"ifid_stage IF clk_i",-1);
	vcdp->declBit  (c+165,"ifid_stage IF rst_i",-1);
	vcdp->declBus  (c+188,"ifid_stage IF pc_branch_address",-1,31,0);
	vcdp->declBus  (c+189,"ifid_stage IF pc_jump_address",-1,31,0);
	vcdp->declBus  (c+190,"ifid_stage IF pc_sel",-1,1,0);
	vcdp->declBus  (c+129,"ifid_stage IF id_instruction_o",-1,31,0);
	vcdp->declBus  (c+127,"ifid_stage IF id_pc_o",-1,31,0);
	vcdp->declBus  (c+128,"ifid_stage IF id_pc_add4",-1,31,0);
	vcdp->declBit  (c+113,"ifid_stage IF if_stall",-1);
	vcdp->declBit  (c+130,"ifid_stage IF exc_addr_o",-1);
	vcdp->declBit  (c+131,"ifid_stage IF id_ready_o",-1);
	vcdp->declBit  (c+113,"ifid_stage IF if_stall_",-1);
	vcdp->declBus  (c+132,"ifid_stage IF if_pc_mux",-1,31,0);
	vcdp->declBus  (c+133,"ifid_stage IF if_pc_o",-1,31,0);
	vcdp->declBus  (c+134,"ifid_stage IF if_pc_add4",-1,31,0);
	vcdp->declBus  (c+160,"ifid_stage IF if_instruction_o",-1,31,0);
	vcdp->declBus  (c+124,"ifid_stage IF wbm_dat_i",-1,31,0);
	vcdp->declBus  (c+135,"ifid_stage IF wbm_addr_o",-1,31,0);
	vcdp->declBus  (c+191,"ifid_stage IF wbm_dat_o",-1,31,0);
	vcdp->declBit  (c+117,"ifid_stage IF wbm_ack_i",-1);
	vcdp->declBit  (c+125,"ifid_stage IF wbm_err_i",-1);
	vcdp->declBit  (c+161,"ifid_stage IF wbm_cyc_o",-1);
	vcdp->declBit  (c+162,"ifid_stage IF wbm_stb_o",-1);
	vcdp->declBit  (c+136,"ifid_stage IF wbm_ready_o",-1);
	vcdp->declBus  (c+2,"ifid_stage IF wbm_sel_o",-1,3,0);
	vcdp->declBit  (c+137,"ifid_stage IF id_exc_addr_o",-1);
	vcdp->declBit  (c+164,"ifid_stage IF PC_REG clk_i",-1);
	vcdp->declBit  (c+165,"ifid_stage IF PC_REG rst_i",-1);
	vcdp->declBit  (c+113,"ifid_stage IF PC_REG stall",-1);
	vcdp->declBus  (c+132,"ifid_stage IF PC_REG pc_i",-1,31,0);
	vcdp->declBus  (c+133,"ifid_stage IF PC_REG pc_o",-1,31,0);
	vcdp->declBus  (c+133,"ifid_stage IF PC_ADD pc",-1,31,0);
	vcdp->declBus  (c+134,"ifid_stage IF PC_ADD pc_next",-1,31,0);
	vcdp->declBus  (c+134,"ifid_stage IF PC_SOURCE in0",-1,31,0);
	vcdp->declBus  (c+188,"ifid_stage IF PC_SOURCE in1",-1,31,0);
	vcdp->declBus  (c+189,"ifid_stage IF PC_SOURCE in2",-1,31,0);
	vcdp->declBus  (c+192,"ifid_stage IF PC_SOURCE in3",-1,31,0);
	vcdp->declBus  (c+190,"ifid_stage IF PC_SOURCE sel",-1,1,0);
	vcdp->declBus  (c+132,"ifid_stage IF PC_SOURCE out",-1,31,0);
	vcdp->declBit  (c+164,"ifid_stage IF LSU clk",-1);
	vcdp->declBit  (c+165,"ifid_stage IF LSU rst",-1);
	vcdp->declBus  (c+133,"ifid_stage IF LSU pc",-1,31,0);
	vcdp->declBus  (c+160,"ifid_stage IF LSU instruction",-1,31,0);
	vcdp->declBus  (c+124,"ifid_stage IF LSU idat_i",-1,31,0);
	vcdp->declBit  (c+117,"ifid_stage IF LSU iack_i",-1);
	vcdp->declBit  (c+125,"ifid_stage IF LSU ierr_i",-1);
	vcdp->declBus  (c+135,"ifid_stage IF LSU iaddr_o",-1,31,0);
	vcdp->declBus  (c+1,"ifid_stage IF LSU idat_o",-1,31,0);
	vcdp->declBus  (c+2,"ifid_stage IF LSU isel_o",-1,3,0);
	vcdp->declBit  (c+161,"ifid_stage IF LSU icyc_o",-1);
	vcdp->declBit  (c+162,"ifid_stage IF LSU istb_o",-1);
	vcdp->declBit  (c+113,"ifid_stage IF LSU if_stall",-1);
	vcdp->declBit  (c+136,"ifid_stage IF LSU ready",-1);
	vcdp->declBit  (c+130,"ifid_stage IF LSU inst_misaligned",-1);
	vcdp->declBit  (c+138,"ifid_stage IF LSU abort",-1);
	vcdp->declBit  (c+3,"ifid_stage IF LSU no_mem",-1);
	vcdp->declBus  (c+193,"ifid_stage IF LSU maddr_i",-1,31,0);
	vcdp->declBus  (c+194,"ifid_stage IF LSU mdat_i",-1,31,0);
	vcdp->declBit  (c+195,"ifid_stage IF LSU mread",-1);
	vcdp->declBit  (c+196,"ifid_stage IF LSU mwrite",-1);
	vcdp->declBit  (c+197,"ifid_stage IF LSU mbyte",-1);
	vcdp->declBit  (c+198,"ifid_stage IF LSU mhw",-1);
	vcdp->declBit  (c+199,"ifid_stage IF LSU mword",-1);
	vcdp->declBit  (c+200,"ifid_stage IF LSU munsigned",-1);
	vcdp->declBus  (c+4,"ifid_stage IF LSU data_o",-1,31,0);
	vcdp->declBit  (c+139,"ifid_stage IF LSU mem_stall",-1);
	vcdp->declBit  (c+140,"ifid_stage IF LSU mem_bus_err",-1);
	vcdp->declBus  (c+201,"ifid_stage IF LSU ddat_i",-1,31,0);
	vcdp->declBit  (c+202,"ifid_stage IF LSU dack_i",-1);
	vcdp->declBit  (c+203,"ifid_stage IF LSU derr_i",-1);
	vcdp->declBus  (c+141,"ifid_stage IF LSU daddr_o",-1,31,0);
	vcdp->declBus  (c+142,"ifid_stage IF LSU ddat_o",-1,31,0);
	vcdp->declBus  (c+5,"ifid_stage IF LSU dsel_o",-1,3,0);
	vcdp->declBit  (c+143,"ifid_stage IF LSU dcyc_o",-1);
	vcdp->declBit  (c+144,"ifid_stage IF LSU dstb_o",-1);
	vcdp->declBit  (c+145,"ifid_stage IF LSU dwe_o",-1);
	vcdp->declBus  (c+204,"ifid_stage IF LSU i_str",-1,1,0);
	vcdp->declBus  (c+205,"ifid_stage IF LSU i_ab",-1,1,0);
	vcdp->declBus  (c+206,"ifid_stage IF LSU i_err",-1,1,0);
	vcdp->declBus  (c+204,"ifid_stage IF LSU d_str",-1,1,0);
	vcdp->declBus  (c+205,"ifid_stage IF LSU d_rx",-1,1,0);
	vcdp->declBus  (c+206,"ifid_stage IF LSU d_tx",-1,1,0);
	vcdp->declBus  (c+207,"ifid_stage IF LSU d_err",-1,1,0);
	vcdp->declQuad (c+208,"ifid_stage IF LSU nrps",-1,63,0);
	vcdp->declBus  (c+210,"ifid_stage IF LSU nop",-1,31,0);
	vcdp->declBus  (c+146,"ifid_stage IF LSU rdata",-1,31,0);
	vcdp->declBus  (c+6,"ifid_stage IF LSU wdata",-1,31,0);
	vcdp->declQuad (c+7,"ifid_stage IF LSU no_rps",-1,63,0);
	vcdp->declBus  (c+147,"ifid_stage IF LSU i_state",-1,1,0);
	vcdp->declBus  (c+148,"ifid_stage IF LSU d_state",-1,1,0);
	vcdp->declBit  (c+149,"ifid_stage IF LSU if_stall_aux",-1);
	vcdp->declBit  (c+164,"ifid_stage IF BRAM clk",-1);
	vcdp->declBit  (c+165,"ifid_stage IF BRAM rst",-1);
	vcdp->declBus  (c+135,"ifid_stage IF BRAM addr_i",-1,31,0);
	vcdp->declBus  (c+211,"ifid_stage IF BRAM dat_i",-1,31,0);
	vcdp->declBus  (c+2,"ifid_stage IF BRAM sel_i",-1,3,0);
	vcdp->declBit  (c+161,"ifid_stage IF BRAM cyc_i",-1);
	vcdp->declBit  (c+162,"ifid_stage IF BRAM stb_i",-1);
	vcdp->declBit  (c+212,"ifid_stage IF BRAM we_i",-1);
	vcdp->declBus  (c+124,"ifid_stage IF BRAM dat_o",-1,31,0);
	vcdp->declBit  (c+117,"ifid_stage IF BRAM ack_o",-1);
	vcdp->declBit  (c+125,"ifid_stage IF BRAM err_o",-1);
	// Tracing: ifid_stage IF BRAM memory // Ignored: Wide memory > --trace-max-array ents at ../software/bram.v:16
	vcdp->declBit  (c+163,"ifid_stage IF BRAM b_state",-1);
	vcdp->declBus  (c+213,"ifid_stage IF BRAM rdat",-1,7,0);
	vcdp->declBus  (c+214,"ifid_stage IF BRAM wdat",-1,7,0);
	vcdp->declBus  (c+215,"ifid_stage IF BRAM b_str",-1,0,0);
	vcdp->declBus  (c+216,"ifid_stage IF BRAM b_tx",-1,0,0);
	vcdp->declBit  (c+164,"ifid_stage IF IF_ID clk",-1);
	vcdp->declBit  (c+165,"ifid_stage IF IF_ID rst",-1);
	vcdp->declBit  (c+217,"ifid_stage IF IF_ID flush",-1);
	vcdp->declBit  (c+113,"ifid_stage IF IF_ID stall",-1);
	vcdp->declBus  (c+133,"ifid_stage IF IF_ID if_pc",-1,31,0);
	vcdp->declBus  (c+134,"ifid_stage IF IF_ID if_pc_add4",-1,31,0);
	vcdp->declBit  (c+130,"ifid_stage IF IF_ID if_exc_addr",-1);
	vcdp->declBus  (c+160,"ifid_stage IF IF_ID if_inst",-1,31,0);
	vcdp->declBit  (c+136,"ifid_stage IF IF_ID if_ready",-1);
	vcdp->declBus  (c+127,"ifid_stage IF IF_ID id_pc",-1,31,0);
	vcdp->declBus  (c+128,"ifid_stage IF IF_ID id_pc_add4",-1,31,0);
	vcdp->declBit  (c+137,"ifid_stage IF IF_ID id_exc_addr",-1);
	vcdp->declBus  (c+129,"ifid_stage IF IF_ID id_inst",-1,31,0);
	vcdp->declBit  (c+131,"ifid_stage IF IF_ID id_ready",-1);
	vcdp->declBit  (c+164,"ifid_stage ID clk_i",-1);
	vcdp->declBit  (c+165,"ifid_stage ID rst_i",-1);
	vcdp->declBus  (c+127,"ifid_stage ID pc",-1,31,0);
	vcdp->declBus  (c+128,"ifid_stage ID pc_add4",-1,31,0);
	vcdp->declBus  (c+129,"ifid_stage ID instruction",-1,31,0);
	vcdp->declBit  (c+130,"ifid_stage ID exc_address_if",-1);
	vcdp->declBus  (c+218,"ifid_stage ID wb_data",-1,31,0);
	vcdp->declBus  (c+219,"ifid_stage ID wb_address",-1,4,0);
	vcdp->declBit  (c+220,"ifid_stage ID wb_we",-1);
	vcdp->declBit  (c+221,"ifid_stage ID mem_stall",-1);
	vcdp->declBus  (c+222,"ifid_stage ID forwardA",-1,31,0);
	vcdp->declBus  (c+223,"ifid_stage ID forwardB",-1,31,0);
	vcdp->declBit  (c+186,"ifid_stage ID forward_sel",-1);
	vcdp->declBit  (c+131,"ifid_stage ID id_ready",-1);
	vcdp->declBus  (c+114,"ifid_stage ID pc_branch_address",-1,31,0);
	vcdp->declBus  (c+123,"ifid_stage ID pc_jump_address",-1,31,0);
	vcdp->declBus  (c+166,"ifid_stage ID ex_port_a",-1,31,0);
	vcdp->declBus  (c+167,"ifid_stage ID ex_port_b",-1,31,0);
	vcdp->declBus  (c+168,"ifid_stage ID ex_alu_op",-1,3,0);
	vcdp->declBus  (c+169,"ifid_stage ID ex_waddr",-1,4,0);
	vcdp->declBit  (c+170,"ifid_stage ID ex_we",-1);
	vcdp->declBus  (c+171,"ifid_stage ID ex_mem_flags",-1,5,0);
	vcdp->declBit  (c+172,"ifid_stage ID ex_mem_ex_sel",-1);
	vcdp->declBit  (c+173,"ifid_stage ID ex_jump_op",-1);
	vcdp->declBit  (c+174,"ifid_stage ID ex_bad_jump_addr",-1);
	vcdp->declBit  (c+175,"ifid_stage ID ex_branch_op",-1);
	vcdp->declBit  (c+176,"ifid_stage ID ex_bad_branch_addr",-1);
	vcdp->declBit  (c+177,"ifid_stage ID take_branch",-1);
	vcdp->declBit  (c+178,"ifid_stage ID ex_break_op",-1);
	vcdp->declBit  (c+179,"ifid_stage ID ex_syscall_op",-1);
	vcdp->declBus  (c+180,"ifid_stage ID ex_csr_op",-1,2,0);
	vcdp->declBit  (c+181,"ifid_stage ID ex_csr_imm_op",-1);
	vcdp->declBit  (c+187,"ifid_stage ID ex_exc_addr_if",-1);
	vcdp->declBit  (c+183,"ifid_stage ID ex_ready",-1);
	vcdp->declBus  (c+118,"ifid_stage ID muxa_i",-1,31,0);
	vcdp->declBus  (c+9,"ifid_stage ID muxb_i",-1,31,0);
	vcdp->declBus  (c+119,"ifid_stage ID rs1",-1,4,0);
	vcdp->declBus  (c+150,"ifid_stage ID rs2",-1,4,0);
	vcdp->declBus  (c+224,"ifid_stage ID rd",-1,4,0);
	vcdp->declBus  (c+118,"ifid_stage ID drs1",-1,31,0);
	vcdp->declBus  (c+9,"ifid_stage ID drs2",-1,31,0);
	vcdp->declBus  (c+225,"ifid_stage ID drd",-1,31,0);
	vcdp->declBit  (c+10,"ifid_stage ID we",-1);
	vcdp->declBus  (c+11,"ifid_stage ID alu_op",-1,3,0);
	vcdp->declBus  (c+120,"ifid_stage ID comparator_op",-1,2,0);
	vcdp->declBus  (c+226,"ifid_stage ID immediate",-1,31,0);
	vcdp->declBus  (c+121,"ifid_stage ID imm",-1,31,0);
	// Tracing: ifid_stage ID _imm // Ignored: Inlined leading underscore at ../software/id_stage.v:57
	vcdp->declBus  (c+151,"ifid_stage ID waddr",-1,4,0);
	vcdp->declBit  (c+12,"ifid_stage ID portb_sel",-1);
	vcdp->declBit  (c+13,"ifid_stage ID porta_sel",-1);
	vcdp->declBus  (c+126,"ifid_stage ID port_a",-1,31,0);
	vcdp->declBus  (c+122,"ifid_stage ID port_b",-1,31,0);
	vcdp->declBit  (c+14,"ifid_stage ID jalr_op",-1);
	vcdp->declBus  (c+15,"ifid_stage ID mem_flags",-1,5,0);
	vcdp->declBit  (c+16,"ifid_stage ID mem_ex_sel",-1);
	vcdp->declBit  (c+17,"ifid_stage ID jump_op",-1);
	vcdp->declBit  (c+115,"ifid_stage ID bad_jump_addr",-1);
	vcdp->declBit  (c+18,"ifid_stage ID branch_op",-1);
	vcdp->declBit  (c+227,"ifid_stage ID bad_jump_address",-1);
	vcdp->declBit  (c+152,"ifid_stage ID break_op",-1);
	vcdp->declBit  (c+153,"ifid_stage ID syscall_op",-1);
	vcdp->declBus  (c+19,"ifid_stage ID csr_op",-1,2,0);
	vcdp->declBit  (c+20,"ifid_stage ID csr_imm_op",-1);
	vcdp->declBit  (c+116,"ifid_stage ID bad_branch_addr",-1);
	vcdp->declBit  (c+186,"ifid_stage ID ex_stall",-1);
	vcdp->declBit  (c+154,"ifid_stage ID ex_exc_address_if",-1);
	vcdp->declBus  (c+118,"ifid_stage ID PORT_A_MUX in_0",-1,31,0);
	vcdp->declBus  (c+127,"ifid_stage ID PORT_A_MUX in_1",-1,31,0);
	vcdp->declBit  (c+13,"ifid_stage ID PORT_A_MUX sel",-1);
	vcdp->declBus  (c+126,"ifid_stage ID PORT_A_MUX out",-1,31,0);
	vcdp->declBus  (c+9,"ifid_stage ID PORT_B_MUX in_0",-1,31,0);
	vcdp->declBus  (c+121,"ifid_stage ID PORT_B_MUX in_1",-1,31,0);
	vcdp->declBit  (c+12,"ifid_stage ID PORT_B_MUX sel",-1);
	vcdp->declBus  (c+122,"ifid_stage ID PORT_B_MUX out",-1,31,0);
	vcdp->declBus  (c+118,"ifid_stage ID FORWARD_A_MUX in_0",-1,31,0);
	vcdp->declBus  (c+222,"ifid_stage ID FORWARD_A_MUX in_1",-1,31,0);
	vcdp->declBit  (c+186,"ifid_stage ID FORWARD_A_MUX sel",-1);
	vcdp->declBus  (c+118,"ifid_stage ID FORWARD_A_MUX out",-1,31,0);
	vcdp->declBus  (c+9,"ifid_stage ID FORWARD_B_MUX in_0",-1,31,0);
	vcdp->declBus  (c+223,"ifid_stage ID FORWARD_B_MUX in_1",-1,31,0);
	vcdp->declBit  (c+186,"ifid_stage ID FORWARD_B_MUX sel",-1);
	vcdp->declBus  (c+9,"ifid_stage ID FORWARD_B_MUX out",-1,31,0);
	vcdp->declBus  (c+120,"ifid_stage ID BP sel",-1,2,0);
	vcdp->declBus  (c+118,"ifid_stage ID BP drs1",-1,31,0);
	vcdp->declBus  (c+9,"ifid_stage ID BP drs2",-1,31,0);
	vcdp->declBit  (c+177,"ifid_stage ID BP take_branch",-1);
	vcdp->declBus  (c+118,"ifid_stage ID BP sdrs1",-1,31,0);
	vcdp->declBus  (c+9,"ifid_stage ID BP sdrs2",-1,31,0);
	vcdp->declBus  (c+118,"ifid_stage ID BP udrs1",-1,31,0);
	vcdp->declBus  (c+9,"ifid_stage ID BP udrs2",-1,31,0);
	vcdp->declBus  (c+228,"ifid_stage ID BP beq",-1,2,0);
	vcdp->declBus  (c+229,"ifid_stage ID BP bne",-1,2,0);
	vcdp->declBus  (c+230,"ifid_stage ID BP blt",-1,2,0);
	vcdp->declBus  (c+231,"ifid_stage ID BP bge",-1,2,0);
	vcdp->declBus  (c+232,"ifid_stage ID BP bltu",-1,2,0);
	vcdp->declBus  (c+233,"ifid_stage ID BP bgeu",-1,2,0);
	vcdp->declBus  (c+234,"ifid_stage ID BP nop",-1,2,0);
	vcdp->declBit  (c+164,"ifid_stage ID RF clk",-1);
	vcdp->declBus  (c+119,"ifid_stage ID RF raddr_rs1",-1,4,0);
	vcdp->declBus  (c+150,"ifid_stage ID RF raddr_rs2",-1,4,0);
	vcdp->declBus  (c+219,"ifid_stage ID RF waddr_rd",-1,4,0);
	vcdp->declBus  (c+218,"ifid_stage ID RF wdata_rd",-1,31,0);
	vcdp->declBit  (c+220,"ifid_stage ID RF we",-1);
	vcdp->declBus  (c+118,"ifid_stage ID RF rdata_rs1",-1,31,0);
	vcdp->declBus  (c+9,"ifid_stage ID RF rdata_rs2",-1,31,0);
	{int i; for (i=0; i<32; i++) {
		vcdp->declBus  (c+21+i*1,"ifid_stage ID RF reg_file",(i+0),31,0);}}
	vcdp->declBus  (c+129,"ifid_stage ID DCU instruction",-1,31,0);
	vcdp->declBus  (c+119,"ifid_stage ID DCU rs1",-1,4,0);
	vcdp->declBus  (c+150,"ifid_stage ID DCU rs2",-1,4,0);
	vcdp->declBus  (c+151,"ifid_stage ID DCU rd",-1,4,0);
	vcdp->declBit  (c+10,"ifid_stage ID DCU reg_write",-1);
	vcdp->declBus  (c+120,"ifid_stage ID DCU comparator_op",-1,2,0);
	vcdp->declBus  (c+15,"ifid_stage ID DCU mem_flags",-1,5,0);
	vcdp->declBit  (c+16,"ifid_stage ID DCU mem_ex_sel",-1);
	vcdp->declBus  (c+11,"ifid_stage ID DCU alu_op",-1,3,0);
	vcdp->declBus  (c+121,"ifid_stage ID DCU imm",-1,31,0);
	vcdp->declBit  (c+12,"ifid_stage ID DCU portb_sel",-1);
	vcdp->declBit  (c+13,"ifid_stage ID DCU porta_sel",-1);
	vcdp->declBit  (c+153,"ifid_stage ID DCU syscall_op",-1);
	vcdp->declBit  (c+18,"ifid_stage ID DCU branch_op",-1);
	vcdp->declBit  (c+17,"ifid_stage ID DCU jump_op",-1);
	vcdp->declBit  (c+14,"ifid_stage ID DCU jalr_op",-1);
	vcdp->declBit  (c+152,"ifid_stage ID DCU break_op",-1);
	vcdp->declBit  (c+20,"ifid_stage ID DCU csr_imm_op",-1);
	vcdp->declBus  (c+19,"ifid_stage ID DCU csr_op",-1,2,0);
	vcdp->declBus  (c+155,"ifid_stage ID DCU opcode",-1,6,0);
	vcdp->declBus  (c+53,"ifid_stage ID DCU mem_access",-1,2,0);
	vcdp->declBit  (c+54,"ifid_stage ID DCU mem_wr",-1);
	vcdp->declBit  (c+235,"ifid_stage ID DCU mem_b",-1);
	vcdp->declBit  (c+236,"ifid_stage ID DCU mem_hw",-1);
	vcdp->declBit  (c+55,"ifid_stage ID DCU mem_r",-1);
	vcdp->declBit  (c+16,"ifid_stage ID DCU mem_ex_s",-1);
	vcdp->declBit  (c+56,"ifid_stage ID DCU mem_unsigned",-1);
	vcdp->declBus  (c+129,"ifid_stage ID DCU inst",-1,31,0);
	vcdp->declBus  (c+156,"ifid_stage ID DCU func3",-1,2,0);
	vcdp->declBus  (c+157,"ifid_stage ID DCU func7",-1,6,0);
	vcdp->declBit  (c+57,"ifid_stage ID DCU lui",-1);
	vcdp->declBit  (c+58,"ifid_stage ID DCU auipc",-1);
	vcdp->declBit  (c+59,"ifid_stage ID DCU jal",-1);
	vcdp->declBit  (c+14,"ifid_stage ID DCU jalr",-1);
	vcdp->declBit  (c+60,"ifid_stage ID DCU beq",-1);
	vcdp->declBit  (c+61,"ifid_stage ID DCU bne",-1);
	vcdp->declBit  (c+62,"ifid_stage ID DCU blt",-1);
	vcdp->declBit  (c+63,"ifid_stage ID DCU bge",-1);
	vcdp->declBit  (c+64,"ifid_stage ID DCU bltu",-1);
	vcdp->declBit  (c+65,"ifid_stage ID DCU bgeu",-1);
	vcdp->declBit  (c+66,"ifid_stage ID DCU lb",-1);
	vcdp->declBit  (c+67,"ifid_stage ID DCU lh",-1);
	vcdp->declBit  (c+68,"ifid_stage ID DCU lw",-1);
	vcdp->declBit  (c+69,"ifid_stage ID DCU lbu",-1);
	vcdp->declBit  (c+70,"ifid_stage ID DCU lhu",-1);
	vcdp->declBit  (c+71,"ifid_stage ID DCU sb",-1);
	vcdp->declBit  (c+72,"ifid_stage ID DCU sh",-1);
	vcdp->declBit  (c+73,"ifid_stage ID DCU sw",-1);
	vcdp->declBit  (c+74,"ifid_stage ID DCU addi",-1);
	vcdp->declBit  (c+75,"ifid_stage ID DCU slti",-1);
	vcdp->declBit  (c+76,"ifid_stage ID DCU sltiu",-1);
	vcdp->declBit  (c+77,"ifid_stage ID DCU xori",-1);
	vcdp->declBit  (c+78,"ifid_stage ID DCU ori",-1);
	vcdp->declBit  (c+79,"ifid_stage ID DCU andi",-1);
	vcdp->declBit  (c+80,"ifid_stage ID DCU slli",-1);
	vcdp->declBit  (c+81,"ifid_stage ID DCU srli",-1);
	vcdp->declBit  (c+82,"ifid_stage ID DCU srai",-1);
	vcdp->declBit  (c+83,"ifid_stage ID DCU add",-1);
	vcdp->declBit  (c+84,"ifid_stage ID DCU sub",-1);
	vcdp->declBit  (c+85,"ifid_stage ID DCU sll",-1);
	vcdp->declBit  (c+86,"ifid_stage ID DCU slt",-1);
	vcdp->declBit  (c+87,"ifid_stage ID DCU sltu",-1);
	// Tracing: ifid_stage ID DCU _xor // Ignored: Inlined leading underscore at ../software/dc_unit.v:84
	vcdp->declBit  (c+88,"ifid_stage ID DCU srl",-1);
	vcdp->declBit  (c+89,"ifid_stage ID DCU sra",-1);
	// Tracing: ifid_stage ID DCU _or // Ignored: Inlined leading underscore at ../software/dc_unit.v:84
	// Tracing: ifid_stage ID DCU _and // Ignored: Inlined leading underscore at ../software/dc_unit.v:84
	vcdp->declBit  (c+237,"ifid_stage ID DCU fence",-1);
	vcdp->declBit  (c+158,"ifid_stage ID DCU nop",-1);
	vcdp->declBit  (c+90,"ifid_stage ID DCU rw",-1);
	vcdp->declBit  (c+91,"ifid_stage ID DCU rs",-1);
	vcdp->declBit  (c+92,"ifid_stage ID DCU rc",-1);
	vcdp->declBit  (c+93,"ifid_stage ID DCU rwi",-1);
	vcdp->declBit  (c+94,"ifid_stage ID DCU rsi",-1);
	vcdp->declBit  (c+95,"ifid_stage ID DCU rci",-1);
	vcdp->declBit  (c+153,"ifid_stage ID DCU call",-1);
	// Tracing: ifid_stage ID DCU _break // Ignored: Inlined leading underscore at ../software/dc_unit.v:88
	vcdp->declBit  (c+159,"ifid_stage ID DCU ret",-1);
	vcdp->declBit  (c+18,"ifid_stage ID DCU is_b",-1);
	vcdp->declBit  (c+96,"ifid_stage ID DCU is_imm",-1);
	vcdp->declBit  (c+54,"ifid_stage ID DCU is_st",-1);
	vcdp->declBit  (c+55,"ifid_stage ID DCU is_ld",-1);
	vcdp->declBit  (c+97,"ifid_stage ID DCU is_add",-1);
	vcdp->declBit  (c+98,"ifid_stage ID DCU is_sub",-1);
	vcdp->declBit  (c+99,"ifid_stage ID DCU is_and",-1);
	vcdp->declBit  (c+100,"ifid_stage ID DCU is_xor",-1);
	vcdp->declBit  (c+101,"ifid_stage ID DCU is_or",-1);
	vcdp->declBit  (c+102,"ifid_stage ID DCU is_sll",-1);
	vcdp->declBit  (c+103,"ifid_stage ID DCU is_sr",-1);
	vcdp->declBit  (c+104,"ifid_stage ID DCU is_slt",-1);
	vcdp->declBit  (c+105,"ifid_stage ID DCU is_sltu",-1);
	vcdp->declBit  (c+106,"ifid_stage ID DCU is_wr",-1);
	vcdp->declBit  (c+107,"ifid_stage ID DCU is_alu",-1);
	vcdp->declBit  (c+108,"ifid_stage ID DCU is_immop",-1);
	vcdp->declBit  (c+56,"ifid_stage ID DCU is_ldu",-1);
	vcdp->declBit  (c+238,"ifid_stage ID DCU is_bu",-1);
	vcdp->declBit  (c+17,"ifid_stage ID DCU is_j",-1);
	vcdp->declBit  (c+109,"ifid_stage ID DCU is_csr",-1);
	vcdp->declBit  (c+20,"ifid_stage ID DCU is_csri",-1);
	vcdp->declBit  (c+110,"ifid_stage ID DCU is_word",-1);
	vcdp->declBit  (c+111,"ifid_stage ID DCU is_byte",-1);
	vcdp->declBit  (c+112,"ifid_stage ID DCU is_hw",-1);
	vcdp->declBit  (c+164,"ifid_stage ID ID_EX clk",-1);
	vcdp->declBit  (c+165,"ifid_stage ID ID_EX rst",-1);
	vcdp->declBit  (c+186,"ifid_stage ID ID_EX stall",-1);
	vcdp->declBit  (c+239,"ifid_stage ID ID_EX flush",-1);
	vcdp->declBus  (c+126,"ifid_stage ID ID_EX id_porta",-1,31,0);
	vcdp->declBus  (c+122,"ifid_stage ID ID_EX id_portb",-1,31,0);
	vcdp->declBus  (c+11,"ifid_stage ID ID_EX id_alu_op",-1,3,0);
	vcdp->declBit  (c+10,"ifid_stage ID ID_EX id_we",-1);
	vcdp->declBus  (c+15,"ifid_stage ID ID_EX id_mem_flags",-1,5,0);
	vcdp->declBit  (c+16,"ifid_stage ID ID_EX id_mem_ex_sel",-1);
	vcdp->declBit  (c+115,"ifid_stage ID ID_EX id_bad_jump_addr",-1);
	vcdp->declBit  (c+116,"ifid_stage ID ID_EX id_bad_branch_addr",-1);
	vcdp->declBit  (c+152,"ifid_stage ID ID_EX id_break_op",-1);
	vcdp->declBit  (c+153,"ifid_stage ID ID_EX id_syscall_op",-1);
	vcdp->declBus  (c+19,"ifid_stage ID ID_EX id_csr_op",-1,2,0);
	vcdp->declBit  (c+20,"ifid_stage ID ID_EX id_csr_imm_op",-1);
	vcdp->declBus  (c+151,"ifid_stage ID ID_EX id_waddr",-1,4,0);
	vcdp->declBit  (c+130,"ifid_stage ID ID_EX id_exc_addr_if",-1);
	vcdp->declBit  (c+131,"ifid_stage ID ID_EX id_ready",-1);
	vcdp->declBus  (c+166,"ifid_stage ID ID_EX ex_porta",-1,31,0);
	vcdp->declBus  (c+167,"ifid_stage ID ID_EX ex_portb",-1,31,0);
	vcdp->declBus  (c+168,"ifid_stage ID ID_EX ex_alu_op",-1,3,0);
	vcdp->declBit  (c+170,"ifid_stage ID ID_EX ex_we",-1);
	vcdp->declBus  (c+171,"ifid_stage ID ID_EX ex_mem_flags",-1,5,0);
	vcdp->declBit  (c+172,"ifid_stage ID ID_EX ex_mem_ex_sel",-1);
	vcdp->declBit  (c+174,"ifid_stage ID ID_EX ex_bad_jump_addr",-1);
	vcdp->declBit  (c+176,"ifid_stage ID ID_EX ex_bad_branch_addr",-1);
	vcdp->declBit  (c+178,"ifid_stage ID ID_EX ex_break_op",-1);
	vcdp->declBit  (c+179,"ifid_stage ID ID_EX ex_syscall_op",-1);
	vcdp->declBus  (c+180,"ifid_stage ID ID_EX ex_csr_op",-1,2,0);
	vcdp->declBit  (c+181,"ifid_stage ID ID_EX ex_csr_imm_op",-1);
	vcdp->declBus  (c+169,"ifid_stage ID ID_EX ex_waddr",-1,4,0);
	vcdp->declBit  (c+154,"ifid_stage ID ID_EX ex_exc_addr_if",-1);
	vcdp->declBit  (c+183,"ifid_stage ID ID_EX ex_ready",-1);
    }
}

void Vifid_stage::traceFullThis__1(Vifid_stage__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vifid_stage* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->fullBus  (c+1,(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__idat_o),32);
	vcdp->fullBus  (c+2,(vlTOPp->ifid_stage__DOT__IF__DOT__wbm_sel_o),4);
	vcdp->fullBit  (c+3,(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__no_mem));
	vcdp->fullBus  (c+4,(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__data_o),32);
	vcdp->fullBus  (c+5,(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__dsel_o),4);
	vcdp->fullBus  (c+6,(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__wdata),32);
	vcdp->fullQuad (c+7,(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__no_rps),64);
	vcdp->fullBus  (c+9,(vlTOPp->ifid_stage__DOT__ID__DOT__drs2),32);
	vcdp->fullBit  (c+10,(((0U != (0x1fU & (vlTOPp->ifid_stage__DOT__id_instruction 
						>> 7U))) 
			       & (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_wr))));
	vcdp->fullBus  (c+11,((((((((((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_add) 
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
					       ? 3U
					       : ((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_xor)
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
				    ? 9U : 0xfU))),4);
	vcdp->fullBit  (c+12,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_immop));
	vcdp->fullBit  (c+13,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__auipc));
	vcdp->fullBit  (c+14,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__jalr));
	vcdp->fullBus  (c+15,((((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_st) 
				<< 5U) | (((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_ld) 
					   << 4U) | 
					  (((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_word) 
					    << 3U) 
					   | (((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_hw) 
					       << 2U) 
					      | (((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_byte) 
						  << 1U) 
						 | (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_ldu))))))),6);
	vcdp->fullBit  (c+16,(((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_ld) 
			       | (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_st))));
	vcdp->fullBit  (c+17,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_j));
	vcdp->fullBit  (c+18,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_b));
	vcdp->fullBus  (c+19,((((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__rc) 
				<< 2U) | (((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__rs) 
					   << 1U) | (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__rw)))),3);
	vcdp->fullBit  (c+20,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_csri));
	vcdp->fullBus  (c+21,(vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file[0]),32);
	vcdp->fullBus  (c+22,(vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file[1]),32);
	vcdp->fullBus  (c+23,(vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file[2]),32);
	vcdp->fullBus  (c+24,(vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file[3]),32);
	vcdp->fullBus  (c+25,(vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file[4]),32);
	vcdp->fullBus  (c+26,(vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file[5]),32);
	vcdp->fullBus  (c+27,(vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file[6]),32);
	vcdp->fullBus  (c+28,(vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file[7]),32);
	vcdp->fullBus  (c+29,(vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file[8]),32);
	vcdp->fullBus  (c+30,(vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file[9]),32);
	vcdp->fullBus  (c+31,(vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file[10]),32);
	vcdp->fullBus  (c+32,(vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file[11]),32);
	vcdp->fullBus  (c+33,(vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file[12]),32);
	vcdp->fullBus  (c+34,(vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file[13]),32);
	vcdp->fullBus  (c+35,(vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file[14]),32);
	vcdp->fullBus  (c+36,(vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file[15]),32);
	vcdp->fullBus  (c+37,(vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file[16]),32);
	vcdp->fullBus  (c+38,(vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file[17]),32);
	vcdp->fullBus  (c+39,(vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file[18]),32);
	vcdp->fullBus  (c+40,(vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file[19]),32);
	vcdp->fullBus  (c+41,(vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file[20]),32);
	vcdp->fullBus  (c+42,(vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file[21]),32);
	vcdp->fullBus  (c+43,(vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file[22]),32);
	vcdp->fullBus  (c+44,(vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file[23]),32);
	vcdp->fullBus  (c+45,(vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file[24]),32);
	vcdp->fullBus  (c+46,(vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file[25]),32);
	vcdp->fullBus  (c+47,(vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file[26]),32);
	vcdp->fullBus  (c+48,(vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file[27]),32);
	vcdp->fullBus  (c+49,(vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file[28]),32);
	vcdp->fullBus  (c+50,(vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file[29]),32);
	vcdp->fullBus  (c+51,(vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file[30]),32);
	vcdp->fullBus  (c+52,(vlTOPp->ifid_stage__DOT__ID__DOT__RF__DOT__reg_file[31]),32);
	vcdp->fullBus  (c+53,((((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_word) 
				<< 2U) | (((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_hw) 
					   << 1U) | (IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_byte)))),3);
	vcdp->fullBit  (c+54,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_st));
	vcdp->fullBit  (c+55,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_ld));
	vcdp->fullBit  (c+56,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_ldu));
	vcdp->fullBit  (c+57,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__lui));
	vcdp->fullBit  (c+58,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__auipc));
	vcdp->fullBit  (c+59,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__jal));
	vcdp->fullBit  (c+60,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__beq));
	vcdp->fullBit  (c+61,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__bne));
	vcdp->fullBit  (c+62,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__blt));
	vcdp->fullBit  (c+63,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__bge));
	vcdp->fullBit  (c+64,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__bltu));
	vcdp->fullBit  (c+65,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__bgeu));
	vcdp->fullBit  (c+66,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__lb));
	vcdp->fullBit  (c+67,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__lh));
	vcdp->fullBit  (c+68,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__lw));
	vcdp->fullBit  (c+69,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__lbu));
	vcdp->fullBit  (c+70,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__lhu));
	vcdp->fullBit  (c+71,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__sb));
	vcdp->fullBit  (c+72,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__sh));
	vcdp->fullBit  (c+73,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__sw));
	vcdp->fullBit  (c+74,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__addi));
	vcdp->fullBit  (c+75,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__slti));
	vcdp->fullBit  (c+76,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__sltiu));
	vcdp->fullBit  (c+77,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__xori));
	vcdp->fullBit  (c+78,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__ori));
	vcdp->fullBit  (c+79,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__andi));
	vcdp->fullBit  (c+80,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__slli));
	vcdp->fullBit  (c+81,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__srli));
	vcdp->fullBit  (c+82,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__srai));
	vcdp->fullBit  (c+83,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__add));
	vcdp->fullBit  (c+84,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__sub));
	vcdp->fullBit  (c+85,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__sll));
	vcdp->fullBit  (c+86,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__slt));
	vcdp->fullBit  (c+87,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__sltu));
	vcdp->fullBit  (c+88,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__srl));
	vcdp->fullBit  (c+89,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__sra));
	vcdp->fullBit  (c+90,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__rw));
	vcdp->fullBit  (c+91,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__rs));
	vcdp->fullBit  (c+92,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__rc));
	vcdp->fullBit  (c+93,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__rwi));
	vcdp->fullBit  (c+94,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__rsi));
	vcdp->fullBit  (c+95,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__rci));
	vcdp->fullBit  (c+96,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_imm));
	vcdp->fullBit  (c+97,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_add));
	vcdp->fullBit  (c+98,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_sub));
	vcdp->fullBit  (c+99,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_and));
	vcdp->fullBit  (c+100,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_xor));
	vcdp->fullBit  (c+101,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_or));
	vcdp->fullBit  (c+102,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_sll));
	vcdp->fullBit  (c+103,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_sr));
	vcdp->fullBit  (c+104,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_slt));
	vcdp->fullBit  (c+105,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_sltu));
	vcdp->fullBit  (c+106,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_wr));
	vcdp->fullBit  (c+107,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_alu));
	vcdp->fullBit  (c+108,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_immop));
	vcdp->fullBit  (c+109,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_csr));
	vcdp->fullBit  (c+110,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_word));
	vcdp->fullBit  (c+111,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_byte));
	vcdp->fullBit  (c+112,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_hw));
	vcdp->fullBit  (c+113,(vlTOPp->ifid_stage__DOT__IF__DOT__if_stall_));
	vcdp->fullBus  (c+114,((vlTOPp->ifid_stage__DOT__ID__DOT___imm 
				+ vlTOPp->ifid_stage__DOT__id_pc_add4)),32);
	vcdp->fullBit  (c+115,(((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_j) 
				& (0U != (2U & vlTOPp->ifid_stage__DOT__ID__DOT___imm)))));
	vcdp->fullBit  (c+116,(((IData)(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_b) 
				& (0U != (3U & (vlTOPp->ifid_stage__DOT__ID__DOT___imm 
						+ vlTOPp->ifid_stage__DOT__id_pc_add4))))));
	vcdp->fullBit  (c+117,(vlTOPp->ifid_stage__DOT__IF__DOT__wbm_ack_i));
	vcdp->fullBus  (c+118,(vlTOPp->ifid_stage__DOT__ID__DOT__drs1),32);
	vcdp->fullBus  (c+119,(vlTOPp->ifid_stage__DOT__ID__DOT__rs1),5);
	vcdp->fullBus  (c+120,(vlTOPp->ifid_stage__DOT__ID__DOT__comparator_op),3);
	vcdp->fullBus  (c+121,(vlTOPp->ifid_stage__DOT__ID__DOT__imm),32);
	vcdp->fullBus  (c+122,(vlTOPp->ifid_stage__DOT__ID__DOT__port_b),32);
	vcdp->fullBus  (c+123,((0xfffffffeU & vlTOPp->ifid_stage__DOT__ID__DOT___imm)),32);
	vcdp->fullBus  (c+124,(vlTOPp->ifid_stage__DOT__IF__DOT__wbm_dat_i),32);
	vcdp->fullBit  (c+125,(vlTOPp->ifid_stage__DOT__IF__DOT__wbm_err_i));
	vcdp->fullBus  (c+126,(vlTOPp->ifid_stage__DOT__ID__DOT__port_a),32);
	vcdp->fullBus  (c+127,(vlTOPp->ifid_stage__DOT__id_pc),32);
	vcdp->fullBus  (c+128,(vlTOPp->ifid_stage__DOT__id_pc_add4),32);
	vcdp->fullBus  (c+129,(vlTOPp->ifid_stage__DOT__id_instruction),32);
	vcdp->fullBit  (c+130,((0U != (3U & vlTOPp->ifid_stage__DOT__IF__DOT__if_pc_o))));
	vcdp->fullBit  (c+131,(vlTOPp->ifid_stage__DOT__id_ready_o));
	vcdp->fullBus  (c+132,(((2U & (IData)(vlTOPp->ifid_stage__DOT__IF__DOT__pc_sel))
				 ? ((1U & (IData)(vlTOPp->ifid_stage__DOT__IF__DOT__pc_sel))
				     ? vlTOPp->ifid_stage__DOT__IF__DOT__PC_SOURCE__DOT__in3
				     : vlTOPp->ifid_stage__DOT__IF__DOT__pc_jump_address)
				 : ((1U & (IData)(vlTOPp->ifid_stage__DOT__IF__DOT__pc_sel))
				     ? vlTOPp->ifid_stage__DOT__IF__DOT__pc_branch_address
				     : ((IData)(4U) 
					+ vlTOPp->ifid_stage__DOT__IF__DOT__if_pc_o)))),32);
	vcdp->fullBus  (c+133,(vlTOPp->ifid_stage__DOT__IF__DOT__if_pc_o),32);
	vcdp->fullBus  (c+134,(((IData)(4U) + vlTOPp->ifid_stage__DOT__IF__DOT__if_pc_o)),32);
	vcdp->fullBus  (c+135,(vlTOPp->ifid_stage__DOT__IF__DOT__wbm_addr_o),32);
	vcdp->fullBit  (c+136,(vlTOPp->ifid_stage__DOT__IF__DOT__wbm_ready_o));
	vcdp->fullBit  (c+137,(vlTOPp->ifid_stage__DOT__IF__DOT__id_exc_addr_o));
	vcdp->fullBit  (c+138,(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__abort));
	vcdp->fullBit  (c+139,(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__mem_stall));
	vcdp->fullBit  (c+140,(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__mem_bus_err));
	vcdp->fullBus  (c+141,(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__daddr_o),32);
	vcdp->fullBus  (c+142,(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__ddat_o),32);
	vcdp->fullBit  (c+143,(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__dcyc_o));
	vcdp->fullBit  (c+144,(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__dstb_o));
	vcdp->fullBit  (c+145,(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__dwe_o));
	vcdp->fullBus  (c+146,(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__rdata),32);
	vcdp->fullBus  (c+147,(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__i_state),2);
	vcdp->fullBus  (c+148,(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__d_state),2);
	vcdp->fullBit  (c+149,(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__if_stall_aux));
	vcdp->fullBus  (c+150,((0x1fU & (vlTOPp->ifid_stage__DOT__id_instruction 
					 >> 0x14U))),5);
	vcdp->fullBus  (c+151,((0x1fU & (vlTOPp->ifid_stage__DOT__id_instruction 
					 >> 7U))),5);
	vcdp->fullBit  (c+152,(((0x73U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
				& (0x2000U == (0x1ffffffU 
					       & (vlTOPp->ifid_stage__DOT__id_instruction 
						  >> 7U))))));
	vcdp->fullBit  (c+153,(((0x73U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
				& (0U == (0x1ffffffU 
					  & (vlTOPp->ifid_stage__DOT__id_instruction 
					     >> 7U))))));
	vcdp->fullBit  (c+154,(vlTOPp->ifid_stage__DOT__ID__DOT__ex_exc_address_if));
	vcdp->fullBus  (c+155,((0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)),7);
	vcdp->fullBus  (c+156,((7U & (vlTOPp->ifid_stage__DOT__id_instruction 
				      >> 0xcU))),3);
	vcdp->fullBus  (c+157,((0x7fU & (vlTOPp->ifid_stage__DOT__id_instruction 
					 >> 0x19U))),7);
	vcdp->fullBit  (c+158,((0x33U == vlTOPp->ifid_stage__DOT__id_instruction)));
	vcdp->fullBit  (c+159,((((0x73U == (0x7fU & vlTOPp->ifid_stage__DOT__id_instruction)) 
				 & (0U == (3U & (vlTOPp->ifid_stage__DOT__id_instruction 
						 >> 0x1eU)))) 
				& (0x4000U == (0x1fffffU 
					       & (vlTOPp->ifid_stage__DOT__id_instruction 
						  >> 7U))))));
	vcdp->fullBus  (c+160,(vlTOPp->ifid_stage__DOT__IF__DOT__if_instruction_o),32);
	vcdp->fullBit  (c+161,(vlTOPp->ifid_stage__DOT__IF__DOT__wbm_cyc_o));
	vcdp->fullBit  (c+162,(vlTOPp->ifid_stage__DOT__IF__DOT__wbm_stb_o));
	vcdp->fullBit  (c+163,(vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__b_state));
	vcdp->fullBit  (c+164,(vlTOPp->clk_i));
	vcdp->fullBit  (c+165,(vlTOPp->rst_i));
	vcdp->fullBus  (c+166,(vlTOPp->ex_port_a),32);
	vcdp->fullBus  (c+167,(vlTOPp->ex_port_b),32);
	vcdp->fullBus  (c+168,(vlTOPp->ex_alu_op),4);
	vcdp->fullBus  (c+169,(vlTOPp->ex_waddr),5);
	vcdp->fullBit  (c+170,(vlTOPp->ex_we));
	vcdp->fullBus  (c+171,(vlTOPp->ex_mem_flags),6);
	vcdp->fullBit  (c+172,(vlTOPp->ex_mem_ex_sel));
	vcdp->fullBit  (c+173,(vlTOPp->ex_jump_op));
	vcdp->fullBit  (c+174,(vlTOPp->ex_bad_jump_addr));
	vcdp->fullBit  (c+175,(vlTOPp->ex_branch_op));
	vcdp->fullBit  (c+176,(vlTOPp->ex_bad_branch_addr));
	vcdp->fullBit  (c+177,(vlTOPp->take_branch));
	vcdp->fullBit  (c+178,(vlTOPp->ex_break_op));
	vcdp->fullBit  (c+179,(vlTOPp->ex_syscall_op));
	vcdp->fullBus  (c+180,(vlTOPp->ex_csr_op),3);
	vcdp->fullBit  (c+181,(vlTOPp->ex_csr_imm_op));
	vcdp->fullBit  (c+182,(vlTOPp->ex_exc_addr_if_o));
	vcdp->fullBit  (c+183,(vlTOPp->ex_ready));
	vcdp->fullBit  (c+184,(vlTOPp->ifid_stage__DOT__if_stall));
	vcdp->fullBit  (c+185,(vlTOPp->ifid_stage__DOT__exc_addr_if));
	vcdp->fullBit  (c+186,(0U));
	vcdp->fullBit  (c+187,(vlTOPp->ifid_stage__DOT__ex_exc_addr_if));
	vcdp->fullBus  (c+188,(vlTOPp->ifid_stage__DOT__IF__DOT__pc_branch_address),32);
	vcdp->fullBus  (c+189,(vlTOPp->ifid_stage__DOT__IF__DOT__pc_jump_address),32);
	vcdp->fullBus  (c+190,(vlTOPp->ifid_stage__DOT__IF__DOT__pc_sel),2);
	vcdp->fullBus  (c+191,(vlTOPp->ifid_stage__DOT__IF__DOT__wbm_dat_o),32);
	vcdp->fullBus  (c+192,(vlTOPp->ifid_stage__DOT__IF__DOT__PC_SOURCE__DOT__in3),32);
	vcdp->fullBus  (c+193,(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__maddr_i),32);
	vcdp->fullBus  (c+194,(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__mdat_i),32);
	vcdp->fullBit  (c+195,(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__mread));
	vcdp->fullBit  (c+196,(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__mwrite));
	vcdp->fullBit  (c+197,(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__mbyte));
	vcdp->fullBit  (c+198,(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__mhw));
	vcdp->fullBit  (c+199,(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__mword));
	vcdp->fullBit  (c+200,(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__munsigned));
	vcdp->fullBus  (c+201,(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__ddat_i),32);
	vcdp->fullBit  (c+202,(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__dack_i));
	vcdp->fullBit  (c+203,(vlTOPp->ifid_stage__DOT__IF__DOT__LSU__DOT__derr_i));
	vcdp->fullBus  (c+204,(0U),2);
	vcdp->fullBus  (c+205,(1U),2);
	vcdp->fullBus  (c+206,(2U),2);
	vcdp->fullBus  (c+207,(3U),2);
	vcdp->fullQuad (c+208,(VL_ULL(0x8000000000000000)),64);
	vcdp->fullBus  (c+210,(0x33U),32);
	vcdp->fullBus  (c+211,(vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__dat_i),32);
	vcdp->fullBit  (c+212,(vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__we_i));
	vcdp->fullBus  (c+213,(vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__rdat),8);
	vcdp->fullBus  (c+214,(vlTOPp->ifid_stage__DOT__IF__DOT__BRAM__DOT__wdat),8);
	vcdp->fullBus  (c+215,(0U),1);
	vcdp->fullBus  (c+216,(1U),1);
	vcdp->fullBit  (c+217,(vlTOPp->ifid_stage__DOT__IF__DOT__IF_ID__DOT__flush));
	vcdp->fullBus  (c+218,(vlTOPp->ifid_stage__DOT__ID__DOT__wb_data),32);
	vcdp->fullBus  (c+219,(vlTOPp->ifid_stage__DOT__ID__DOT__wb_address),5);
	vcdp->fullBit  (c+220,(vlTOPp->ifid_stage__DOT__ID__DOT__wb_we));
	vcdp->fullBit  (c+221,(vlTOPp->ifid_stage__DOT__ID__DOT__mem_stall));
	vcdp->fullBus  (c+222,(vlTOPp->ifid_stage__DOT__ID__DOT__forwardA),32);
	vcdp->fullBus  (c+223,(vlTOPp->ifid_stage__DOT__ID__DOT__forwardB),32);
	vcdp->fullBus  (c+224,(vlTOPp->ifid_stage__DOT__ID__DOT__rd),5);
	vcdp->fullBus  (c+225,(vlTOPp->ifid_stage__DOT__ID__DOT__drd),32);
	vcdp->fullBus  (c+226,(vlTOPp->ifid_stage__DOT__ID__DOT__immediate),32);
	vcdp->fullBit  (c+227,(vlTOPp->ifid_stage__DOT__ID__DOT__bad_jump_address));
	vcdp->fullBus  (c+228,(1U),3);
	vcdp->fullBus  (c+229,(2U),3);
	vcdp->fullBus  (c+230,(3U),3);
	vcdp->fullBus  (c+231,(4U),3);
	vcdp->fullBus  (c+232,(5U),3);
	vcdp->fullBus  (c+233,(6U),3);
	vcdp->fullBus  (c+234,(0U),3);
	vcdp->fullBit  (c+235,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__mem_b));
	vcdp->fullBit  (c+236,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__mem_hw));
	vcdp->fullBit  (c+237,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__fence));
	vcdp->fullBit  (c+238,(vlTOPp->ifid_stage__DOT__ID__DOT__DCU__DOT__is_bu));
	vcdp->fullBit  (c+239,(vlTOPp->ifid_stage__DOT__ID__DOT__ID_EX__DOT__flush));
    }
}
