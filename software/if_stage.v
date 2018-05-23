`include "software/clk_gen.v"
`include "software/pc_reg.v"
`include "software/pc_source.v"
`include "software/pc_add.v"
`include "software/ls_unit.v"
`include "software/ifid_reg.v"
`include "software/bram.v"

module if_stage (
		output clk,
		input  rst_i,
		input  pc_branch_address,
		input  pc_jump_address,
		output [31:0] id_instruction_o,
		output [31:0] id_pc_o,
		output [31:0] id_pc_add4,
		output exc_addr_o,
		output id_ready_o			); 

	wire [31:0] if_pc_mux; 
	wire 	    if_stall;
	wire [31:0] if_pc_o;
	wire [31:0] if_pc_add4;
	wire [31:0] if_instruction_o;
	//LSU SIGNALS
	wire [31:0] wbm_dat_i;
	wire [31:0] wbm_addr_o;
	wire [31:0] wbm_dat_o;
	wire 	    wbm_ack_i;
	wire 	    wbm_err_i;
	wire 	    wbm_cyc_o;
	wire 	    wbm_stb_o;
	wire 	    wbm_ready_o;
	//--------------------


	clkgen 		CLK   (	.clk(clk));

	pc_reg	     PC_REG   (	.clk_i(clk),
				.rst_i(rst_i),
				.stall(if_stall),
				.pc_i(if_pc_mux),
				.pc_o(if_pc_o) );
	pc_add 	     PC_ADD   (
				.pc(if_pc_o),
				.pc_next(if_pc_add4));
	pc_source    PC_SOURCE(
				.pc(if_pc_add4),
				.pc_reg(if_pc_mux) ); 
	
	load_store_unit LSU   (
				.clk(clk),
				.rst(rst_i),
				.pc(if_pc_o),
				.instruction(if_instruction_o),
				.idat_i(wbm_dat_i),
				.iack_i(wbm_ack_i),
				.ierr_i(wbm_err_i),
				.iaddr_o(wbm_addr_o),
				.icyc_o(wbm_cyc_o),
				.istb_o(wbm_stb_o),
				.if_stall(if_stall),
				.ready(wbm_ready_o),
				.inst_misaligned(exc_addr_o) );

	bram 		BRAM (
				.clk(clk),
				.rst(rst_i),
				.iaddr_i(wbm_addr_o),
				.icyc_i(wbm_cyc_o),
				.istb_i(wbm_stb_o),
				.idat_o(wbm_dat_i),
				.iack_o(wbm_ack_i),
				.ierr_o(wbm_err_i) );		
		
	ifid_register IF_ID (
				.clk(clk),
				.rst(rst_i),
				.stall(if_stall),
				.if_pc(if_pc_o),
				.if_pc_add4(if_pc_add4),
				.if_exc_addr(exc_addr_o),
				.if_inst(if_instruction_o),
				.id_pc(id_pc_o),
				.id_pc_add4(id_pc_add4),
				.id_inst(id_instruction_o),
				.id_exc_addr(id_exc_addr_o), 
				.id_ready(id_ready_o) ); 
endmodule 	
		
	

