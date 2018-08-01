

`include "titan_pc_reg.v"
`include "titan_pc_add.v"
`include "titan_pc_source.v"

module titan_if_stage #(
		parameter [31:0] RESET_ADDR = 32'h0000_0000
		)(
		//INPUTS
		input  		clk_i,
		input  		rst_i,
		input  		if_stall,
		input 		if_flush,
		input  [31:0]	if_inst_i,
		input  [31:0]	pc_branch_i,
		input  [31:0] 	pc_jump_i,
		input  [31:0]	pc_excep_i,
		input  [ 1:0] 	if_pc_sel_i,
		input 		if_inst_access_fault_i,
		//OUTPUTS
		output [31:0]	if_pc_o,
		output [31:0] 	id_instruction_o,
		output [31:0] 	id_pc_o,
		output [ 3:0]	if_ecode_o,
		output [31:0]	if_exc_data_o,
		output 		if_trap_valid_o	
		//-------------------------------
		); 

	localparam INST_ADDR_MISALIGNED = 4'h0;
	localparam INST_ACCESS_FAULT	= 4'h1;

	wire 	[31:0] 	pc_next; 
	wire 	[31:0] 	pc_add4;
	wire 	    	addr_misaligned;
	assign 	   	addr_misaligned = ~(if_pc_o[1:0] == 0);
	assign 		if_exc_data_o  	= if_pc_o; 
	assign	   	if_trap_valid_o	= (if_inst_access_fault_i | addr_misaligned ); 
	assign		if_ecode_o 	= (if_inst_access_fault_i)? INST_ACCESS_FAULT : ((addr_misaligned)? INST_ADDR_MISALIGNED: 4'b0);

	titan_pc_reg  #(.RESET_ADDR(RESET_ADDR)) PC_REG(
							.clk_i(clk_i),
							.rst_i(rst_i),
							.stall(if_stall),
							.flush(if_flush),
							.pc_i(pc_next),
							.pc_o(if_pc_o) );
	titan_pc_add 				PC_ADD (
							.pc(if_pc_o),
							.pc_next(pc_add4));

	titan_pc_source 			PC_SOURCE(
							.in0(pc_add4),
							.in1(pc_branch_i),
							.in2(pc_jump_i),
							.in3(pc_excep_i),
							.sel(if_pc_sel_i),
							.out(pc_next) ); 
	
	
endmodule 	
		
	

