//`timescale 1ns/1ps
//`include "software/if_stage.v"
//`include "tests/ifid_stage_tb.v"
//`include "software/id_stage.v"
module ifid_stage( 
	input  		clk_i,
	input  		rst_i,
	output [31:0] 	ex_port_a,
	output [31:0] 	ex_port_b,
	output [ 3:0] 	ex_alu_op,
	output [ 4:0] 	ex_waddr,
	output 		ex_we,
	output [ 5:0] 	ex_mem_flags,
	output 		ex_mem_ex_sel,
	output 		ex_jump_op,
	output 		ex_bad_jump_addr,
        output 		ex_branch_op,
	output 		ex_bad_branch_addr, 
	output 		take_branch, 
	output 		ex_break_op,
	output 		ex_syscall_op,
	output [2:0] 	ex_csr_op,
	output 		ex_csr_imm_op,
	output 		ex_exc_addr_if_o,
	output 		ex_ready);

        wire if_stall;
	wire [31:0] id_pc;	
	wire [31:0] id_pc_add4;
	wire [31:0] id_instruction;
	wire id_exc_addr;
	wire id_ready_o;
	wire exc_addr_if;
	wire forward_sel; 
	wire [31:0] pc_branch_address;
	wire [31:0] pc_jump_address;
	
	assign forward_sel = 1'b0;

	if_stage IF(
			.clk_i(clk_i),
			.rst_i(rst_i),
			.id_pc_o(id_pc),
			.id_pc_add4(id_pc_add4),
			.id_instruction_o(id_instruction),
			.exc_addr_o(id_exc_addr),
			.id_ready_o(id_ready_o)	); 

	id_stage ID(
			.clk_i(clk_i),
			.rst_i(rst_i),
			.pc(id_pc),
			.pc_add4(id_pc_add4),
			.instruction(id_instruction), 
			.exc_address_if(id_exc_addr), 
			.forward_sel(forward_sel),
			.id_ready(id_ready_o),
			//OUTPUTS
			.pc_branch_address(pc_branch_address),
			.pc_jump_address(pc_jump_address),
			.ex_port_a(ex_port_a),
			.ex_port_b(ex_port_b),
			.ex_alu_op(ex_alu_op),
			.ex_waddr(ex_waddr),
			.ex_we(ex_we),
			.ex_mem_flags(ex_mem_flags),
			.ex_mem_ex_sel(ex_mem_ex_sel),
			.ex_jump_op(ex_jump_op),
			.ex_bad_jump_addr(ex_bad_jump_addr),
			.ex_branch_op(ex_branch_op),
			.ex_bad_branch_addr(ex_bad_branch_addr), 
			.take_branch(take_branch),
			.ex_break_op(ex_break_op),
			.ex_syscall_op(ex_syscall_op),
			.ex_csr_op(ex_csr_op),
			.ex_csr_imm_op(ex_csr_imm_op),
	       		.ex_exc_addr_if(ex_exc_addr_if),
			.ex_ready(ex_ready));
	
endmodule




