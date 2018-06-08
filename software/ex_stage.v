`include "exu.v"
`include "exmem_register.v"

module ex_stage (
		 input 		clk_i,
		 input 		rst_i,
		 input 		ex_stall_i,
		 input [31:0] 	ex_port_a_i,
		 input [31:0]	ex_port_b_i,
		 input [ 3:0] 	ex_alu_op_i,
		 input [ 4:0]	ex_waddr_i,
		 input 	      	ex_we_i,
		 input [ 5:0] 	ex_mem_flags_i,
		 input        	ex_mem_ex_sel_i,
		 input [11:0]	ex_csr_addr_i,
		 input [ 2:0] 	ex_csr_op_i,
		 input 	      	ex_csr_imm_op_i,
		 input 	      	ex_exc_addr_if_i,
		 output 	ex_fwd_dat_o,
		 output [31:0] 	mem_result_o,
		 output [ 4:0] 	mem_waddr_o,
		 output        	mem_we_o,
		 output [ 5:0]  mem_mem_flags_o,
		 output 	mem_mem_ex_sel_o,
		 output [ 2:0] 	mem_csr_op_o,
		 output [11:0]	mem_csr_addr_o,
		 output 	mem_csr_imm_op_o,
		 output 	mem_exc_addr_if_o ); 

	
	wire [31:0] ex_result;

	assign ex_fwd_dat_o = ex_result;

	exu           ALU (
				.port_a(ex_port_a_i),
				.port_b(ex_port_b_i),
				.alu_op(ex_alu_op_i),
				.result(ex_result)  ); 
	
	exmem_reg  EX_MEM(
				.clk(clk_i),
				.rst(rst_i),
				.stall(ex_stall_i),
				.ex_waddr(ex_waddr_i),
				.ex_we(ex_we_i),
				.ex_mem_flags(ex_mem_flags_i),
				.ex_mem_ex_sel(ex_mem_ex_sel_i),
				.ex_csr_op(ex_csr_op_i),
				.ex_csr_addr(ex_csr_addr_i),
				.ex_csr_imm_op(ex_csr_imm_op_i),
				.ex_exc_addr_if(ex_exc_addr_if_i),
				.ex_result(ex_result),
				.mem_waddr(mem_waddr_o),
				.mem_we(mem_we_o),
				.mem_mem_flags(mem_mem_flags_o),
				.mem_mem_ex_sel(mem_mem_ex_sel_o),
				.mem_csr_op(mem_csr_op_o),
				.mem_csr_addr(mem_csr_addr_o),
				.mem_csr_imm_op(mem_csr_imm_op_o),
				.mem_exc_addr_if(mem_exc_addr_if_o),
		       		.mem_result(mem_result_o)	);

endmodule 

