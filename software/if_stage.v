//`include "software/clk_gen.v"
//`include "pc_reg.v"
//`include "software/pc_source.v"
//`include "software/pc_add.v"
//`include "software/ls_unit.v"
//`include "software/ifid_reg.v"
//`include "software/bram.v"

module if_stage (
		input  		clk_i,
		input  		rst_i,
		input  		if_stall,
		input 		if_flush,
		input  [31:0]	pc_branch_address_i,
		input  [31:0] 	pc_jump_address_i,
		input  [ 1:0] 	if_pc_sel_i,
		input 		if_exc_addr_i,
		output [31:0] 	id_instruction_o,
		output [31:0] 	id_pc_o,
		output [31:0] 	id_pc_add4_o,
		output 		id_exc_addr_o		); 

	wire [31:0] if_pc_mux; 
	wire [31:0] if_pc_o;
	wire [31:0] if_pc_add4;
	wire [31:0] if_instruction_o;



	pc_reg	     PC_REG   (	.clk_i(clk_i),
				.rst_i(rst_i),
				.stall(if_stall_),
				.pc_i(if_pc_mux),
				.pc_o(if_pc_o) );
	pc_add 	     PC_ADD   (
				.pc(if_pc_o),
				.pc_next(if_pc_add4));
	pc_source    PC_SOURCE(
				.in0(if_pc_add4),
				.in1(pc_branch_address),
				.in2(pc_jump_address),
				.sel(pc_sel),
				.out(if_pc_mux) ); 
	
	
	ifid_register IF_ID (
				.clk(clk_i),
				.rst(rst_i),
				.stall(if_stall),
				.flush(if_flush),
				.if_pc(if_pc_o),
				.if_pc_add4(if_pc_add4),
				.if_exc_addr(if_exc_addr_o),
				.if_inst(if_instruction_o),
				.if_ready(wbm_ready_o),
				.id_pc(id_pc_o),
				.id_pc_add4(id_pc_add4_o),
				.id_inst(id_instruction_o),
				.id_exc_addr(id_exc_addr_o), 
				.id_ready(id_ready_o) ); 
endmodule 	
		
	

