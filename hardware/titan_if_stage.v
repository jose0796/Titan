//`include "clk_gen.v"
//`include "pc_reg.v"
//`include "pc_source.v"
//`include "pc_add.v"
//`include "ifid_reg.v"
//`include "bram.v"

module titan_if_stage #(
		parameter [31:0] RESET_ADDR = 32'h0000_0000
		)(
		input  		clk_i,
		input  		rst_i,
		input  		if_stall,
		input 		id_stall,
		input 		if_flush,
		input  [31:0]	if_instruction_i,
		input  [31:0]	pc_branch_address_i,
		input  [31:0] 	pc_jump_address_i,
		input  [31:0]	exception_pc_i,
		input  [ 1:0] 	if_pc_sel_i,
		input 		if_inst_access_fault_i,
		output [31:0]	if_pc_o,
		output [31:0] 	id_instruction_o,
		output [31:0] 	id_pc_o,
		output 		id_inst_addr_misaligned_o,
		output 		id_inst_access_fault_o	); 

	wire [31:0] if_pc_mux; 
	wire [31:0] if_pc_add4;
	wire 	    if_inst_addr_misaligned; 
	assign 	    if_inst_addr_misaligned = ~(if_pc_o[1:0] == 0);
	

	titan_pc_reg  #(.RESET_ADDR(RESET_ADDR))
			PC_REG(.clk_i(clk_i),
				.rst_i(rst_i),
				.stall(if_stall),
				.pc_i(if_pc_mux),
				.pc_o(if_pc_o) );
	titan_pc_add PC_ADD   (
				.pc(if_pc_o),
				.pc_next(if_pc_add4));

	titan_pc_source PC_SOURCE(
				.in0(if_pc_add4),
				.in1(pc_branch_address_i),
				.in2(pc_jump_address_i),
				.in3(exception_pc_i),
				.sel(if_pc_sel_i),
				.out(if_pc_mux) ); 
	
	
	titan_ifid_reg IF_ID (
				.clk(clk_i),
				.rst(rst_i),
				.if_stall(if_stall),
				.id_stall(id_stall),
				.flush(if_flush),
				.if_pc(if_pc_o),
				.if_inst_addr_misaligned(if_inst_addr_misaligned),
				.if_inst_access_fault(if_inst_access_fault_i),
				.if_inst(if_instruction_i),
				.id_pc(id_pc_o),
				.id_inst(id_instruction_o),
				.id_inst_addr_misaligned(id_inst_addr_misaligned_o),
		       		.id_inst_access_fault(id_inst_access_fault_o)	);  
endmodule 	
		
	

