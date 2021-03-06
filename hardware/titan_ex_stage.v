//`include "exu.v"
//`include "exmem_register.v"

module titan_ex_stage (
		 input wire	clk_i,
		 input wire	rst_i,
		 input 		mem_stall_i,
		 input 		mem_flush_i,
		 input [31:0]	ex_pc_i,
		 input [31:0]	ex_instruction_i,	
		 input [31:0] 	ex_port_a_i,
		 input [31:0]	ex_port_b_i,
		 input [ 3:0] 	ex_alu_op_i,
		 input [ 4:0]	ex_rs1_i,
		 input [31:0]	ex_store_data_i,
		 input [ 4:0]	ex_waddr_i,
		 input 	      	ex_we_i,
		 input [ 5:0] 	ex_mem_flags_i,
		 input        	ex_mem_ex_sel_i,
		 input [ 3:0]	ex_exception_i,
		 input [31:0]	ex_exc_data_i,
		 input 		ex_trap_valid_i,
		 input 		ex_xret_op_i,
		 input 		ex_fence_op_i,
		 input [31:0]	ex_csr_data_i,
		 input [11:0]	ex_csr_addr_i,
		 input [ 2:0] 	ex_csr_op_i,
		 output	[31:0]	mem_pc_o,
		 output	[31:0]	mem_instruction_o,
		 output [ 4:0]	mem_rs1_o,
		 output [31:0]	ex_fwd_dat_o,
		 output [31:0]	mem_store_data_o,
		 output [31:0] 	mem_result_o,
		 output [ 4:0] 	mem_waddr_o,
		 output        	mem_we_o,
		 output [ 5:0]  mem_mem_flags_o,
		 output 	mem_mem_ex_sel_o,
		 output [31:0]	mem_exc_data_o,
		 output [ 3:0]	mem_exception_o,
		 output 	mem_trap_valid_o,
		 output		mem_xret_op_o,
		 output		mem_fence_op_o,
		 output [31:0]	mem_csr_data_o,
		 output [ 2:0] 	mem_csr_op_o,
		 output [11:0]	mem_csr_addr_o
		 ); 

	
	wire [31:0] ex_result;

	assign ex_fwd_dat_o     = ex_result;

	titan_exu           ALU (
				.port_a(ex_port_a_i),
				.port_b(ex_port_b_i),
				.alu_op(ex_alu_op_i),
				.result(ex_result)  ); 
	
	titan_exmem_register  EX_MEM(
				.clk(clk_i),
				.rst(rst_i),
				.stall(mem_stall_i),
				.flush(mem_flush_i),
				.ex_pc(ex_pc_i),
				.ex_instruction(ex_instruction_i),
				.ex_waddr(ex_waddr_i),
				.ex_rs1(ex_rs1_i),
				.ex_we(ex_we_i),
				.ex_store_data(ex_store_data_i),
				.ex_mem_flags(ex_mem_flags_i),
				.ex_mem_ex_sel(ex_mem_ex_sel_i),
				.ex_exception(ex_exception_i),
				.ex_exc_data(ex_exc_data_i),
				.ex_trap_valid(ex_trap_valid_i),
				.ex_fence_op(ex_fence_op_i),
				.ex_xret_op(ex_xret_op_i),
				.ex_csr_data(ex_csr_data_i),
				.ex_csr_op(ex_csr_op_i),
				.ex_csr_addr(ex_csr_addr_i),
				.ex_result(ex_result),
				.mem_pc(mem_pc_o),
				.mem_instruction(mem_instruction_o),
				.mem_waddr(mem_waddr_o),
				.mem_rs1(mem_rs1_o),
				.mem_we(mem_we_o),
				.mem_mem_flags(mem_mem_flags_o),
				.mem_store_data(mem_store_data_o),
				.mem_mem_ex_sel(mem_mem_ex_sel_o),
				.mem_exception(mem_exception_o),
				.mem_exc_data(mem_exc_data_o),
				.mem_trap_valid(mem_trap_valid_o),
				.mem_fence_op(mem_fence_op_o),
				.mem_xret_op(mem_xret_op_o),
				.mem_csr_data(mem_csr_data_o),
				.mem_csr_op(mem_csr_op_o),
				.mem_csr_addr(mem_csr_addr_o),
		       		.mem_result(mem_result_o)	);

endmodule 

