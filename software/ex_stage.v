`include "rtl/exu.v"
`include "rtl/exmem_register.v"

module ex_stage (
		 input 		clk,
		 input 		rst,
		 input 		ex_stall,
		 input [31:0] 	port_a,
		 input [31:0]	port_b,
		 input [ 3:0] 	alu_op,
		 input [ 4:0]	waddr_i,
		 input 	      	we_i,
		 input [ 5:0] 	mem_flags_i,
		 input        	mem_ex_sel_i,
		 input [ 2:0] 	csr_op_i,
		 input 	      	csr_imm_op_i,
		 input 	      	exc_addr_if_i,
		 output [31:0] 	result_o,
		 output [ 4:0] 	waddr_o,
		 output        	we_o,
		 output [ 5:0]  mem_flags_o,
		 output 	mem_ex_sel_o,
		 output [ 2:0] 	csr_op_o,
		 output 	csr_imm_op_o,
		 output 	exc_addr_if_o ); 

	
	wire [31:0] result;
	exu           ALU (
				.port_a(port_a),
				.port_b(port_b),
				.alu_op(alu_op),
				.result(result)  ); 
	
	exmem_reg  EX_MEM(
				.clk(clk),
				.rst(rst),
				.stall(ex_stall),
				.ex_waddr(waddr_i),
				.ex_we(we_i),
				.ex_mem_flags(mem_flags_i),
				.ex_mem_ex_sel(mem_ex_sel_i),
				.ex_csr_op(csr_op_i),
				.ex_csr_imm_op(csr_imm_op_i),
				.ex_exc_addr_if(exc_addr_if_i),
				.ex_result(result),
				.mem_waddr(waddr_o),
				.mem_we(we_o),
				.mem_mem_flags(mem_flags_o),
				.mem_mem_ex_sel(mem_ex_sel_o),
				.mem_csr_op(csr_op_o),
				.mem_csr_imm_op(csr_imm_op_o),
				.mem_exc_addr_if(exc_addr_if_o),
		       		.mem_result(result_o)	);

endmodule 

