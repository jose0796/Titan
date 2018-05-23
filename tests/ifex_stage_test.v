`timescale 1ns/1ps
`include "software/if_stage.v"
`include "tests/ifex_stage_tb.v"
`include "software/id_stage.v"
`include "software/ex_stage.v"

module tb;
	wire clk;
	wire rst;
        wire if_stall;
	wire [31:0] id_pc;	
	wire [31:0] id_pc_add4;
	wire [31:0] id_instruction;
	wire id_exc_addr;
	wire id_ready;
	
	wire forward_sel; 
	wire [31:0] pc_branch_address;
	wire [31:0] pc_jump_address;
	wire [31:0] ex_port_a;
	wire [31:0] ex_port_b;
	wire [ 3:0] ex_alu_op;
	wire [ 4:0] ex_waddr;
	wire ex_we;
	wire [ 5:0] ex_mem_flags;
	wire ex_mem_ex_sel;
	wire ex_jump_op;
	wire ex_bad_jump_addr;
        wire ex_branch_op;
	wire ex_bad_branch_addr; 
	wire take_branch; 
	wire ex_break_op;
	wire ex_syscall_op;
	wire [2:0] ex_csr_op;
	wire ex_csr_imm_op;
	wire ex_exc_addr_if_o;
	wire ex_stall;
	wire [31:0] mem_result;
	wire [ 4:0] mem_waddr;
	wire 	    mem_we;
	wire [ 5:0] mem_flags;
	wire 	    mem_ex_sel;
	wire [ 2:0] mem_csr_op;
	wire 	    mem_csr_imm_op;
	wire 	    mem_exc_addr_if;


	assign forward_sel = 1'b0;
	assign ex_stall    = 1'b0;

	if_stage IF(
			.clk(clk),
			.rst_i(rst),
			.id_pc_o(id_pc),
			.id_pc_add4(id_pc_add4),
			.id_instruction_o(id_instruction),
			.exc_addr_o(id_exc_addr),
			.id_ready_o(id_ready_o) ); 

	id_stage ID(
			.clk(clk),
			.rst(rst),
			.pc(id_pc),
			.pc_add4(id_pc_add4),
			.instruction(id_instruction), 
			.exc_address_if(id_exc_addr), 
			.forward_sel(forward_sel),
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
	       		.ex_exc_addr_if(ex_exc_addr_if)	);
	ex_stage EX(
			.clk(clk),
			.rst(rst),
			.ex_stall(ex_stall),
			.port_a(ex_port_a),
			.port_b(ex_port_b),
			.alu_op(ex_alu_op),
			.waddr_i(ex_waddr),
			.we_i(ex_we),
			.mem_flags_i(ex_mem_flags),
			.mem_ex_sel_i(ex_mem_ex_sel),
			.csr_op_i(ex_csr_op),
			.csr_imm_op_i(ex_csr_imm_op),
			.exc_addr_if_i(ex_exc_addr_if),
			.result_o(mem_result),
			.waddr_o(mem_waddr),
			.we_o(mem_we),
			.mem_flags_o(mem_flags),
			.mem_ex_sel_o(mem_ex_sel),
			.csr_op_o(mem_csr_op),
			.csr_imm_op_o(mem_csr_imm_op),
			.exc_addr_if_o(mem_exc_addr_if) );

	
	test	TB(	.rst(rst) );
endmodule




