
//`include "./if_stage.v"
//`include "./id_stage.v"
//`include "./ex_stage.v"
//`include "./mem_stage.v"
//`include "./lsu.v"
//`include "./forwarding_unit.v"
//`include "./control_unit.v"

`timescale 1 ns / 1 ps


module titan_core #(
		parameter [31:0] HART_ID = 0,
		parameter [31:0] RESET_ADDR = 32'h0000_0000,
		parameter [0:0]  ENABLE_COUNTERS = 1,
		parameter [0:0]	 ENABLE_M_ISA = 0,
		parameter 	 UCONTROL = "ucontrol.list" 
		)(
		input 		clk_i,
		input 		rst_i,
		//INSTRUCTION MEMORY PORT
		output	[31:0]	iwbm_addr_o,
		output 		iwbm_cyc_o,
		output 		iwbm_stb_o,
		input	[31:0]	iwbm_dat_i,
		input		iwbm_err_i,
		input 		iwbm_ack_i,
		//DATA MEMORY PORT
		input	[31:0]	dwbm_dat_i,
		input		dwbm_err_i,
		input 		dwbm_ack_i,
		output	[31:0]	dwbm_addr_o,
		output 		dwbm_cyc_o,
		output 		dwbm_stb_o,
		output 	[31:0]	dwbm_dat_o,
		output		dwbm_we_o,
		output	[ 3:0]	dwbm_sel_o,
		//INTERRUPTIONS
		/*verilator lint_off UNUSED */
		input 		xint_meip_i,
		input		xint_mtip_i,
		input		xint_msip_i 
		/*verilator lint_on UNUSED */
	); 	

	//IF STAGE SIGNALS 
	wire 		if_stall;
	wire 		if_flush;
	wire 	[31:0]	if_pc; 
	wire 	[ 1:0] 	if_pc_sel;
	wire 	[31:0]	if_instruction;
	
	wire 		if_trap_valid;
	wire 	[ 3:0]	if_exception;
	wire 	[31:0]	if_exc_data;

	titan_if_stage #(
			.RESET_ADDR(RESET_ADDR[31:0])		
			) IF (
			//INPUTS
			.clk_i(clk_i),
			.rst_i(rst_i),
			// CONTROL => IF
			.if_stall(if_stall & ~if_kill & ~wb_trap_valid),
			.if_flush(if_flush),
			.id_stall(id_stall),
			.id_flush(id_flush),
			.if_pc_sel_i(if_pc_sel),
			//----------------------------------
			// LSU => IF
			.if_instruction_i(if_instruction),
			//----------------------------------	
			// ID => IF
			.pc_branch_address_i(pc_branch_addr),
			.pc_jump_address_i(pc_jump_addr),
			.exception_pc_i(exception_pc),
			.if_inst_access_fault_i(iwbm_err_i), 
			//----------------------------------
			//----------------------------------
			//OUTPUT IF => ID
			.if_pc_o(if_pc),
			.id_pc_o(id_pc),
			.id_instruction_o(id_instruction),
			.if_exception_o(if_exception),
			.if_exc_data_o(if_exc_data),
			.if_trap_valid_o(if_trap_valid)
			//----------------------------------
			); 
endmodule
