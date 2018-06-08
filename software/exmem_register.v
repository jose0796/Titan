

module exmem_reg (
		  input 		clk,
		  input 		rst,
		  input 		stall,
		  input 	[31:0] 	ex_result,
		  input 	[ 4:0] 	ex_waddr,
		  input 		ex_we,
		  input 	[ 5:0]	ex_mem_flags,
		  input 		ex_mem_ex_sel,
		  input 	[ 2:0]  ex_csr_op,
		  input 		ex_csr_imm_op,
		  input		[11:0]	ex_csr_addr,
		  input 		ex_exc_addr_if,
		  output reg 	[31:0] 	mem_result,
		  output reg 	[ 4:0] 	mem_waddr,
		  output reg		mem_we,
		  output reg 	[ 5:0] 	mem_mem_flags,
		  output reg		mem_mem_ex_sel,
		  output reg 	[ 2:0] 	mem_csr_op,
		  output reg 	[11:0]	mem_csr_addr,
		  output reg		mem_csr_imm_op,
		  output reg		mem_exc_addr_if );

	always @(posedge clk) begin
		mem_result 		<= ((rst)? 32'b0 : ((stall)? mem_result 	: ex_result)); 
		mem_waddr  		<= ((rst)? 5'b0  : ((stall)? mem_waddr  	: ex_waddr));
		mem_we     		<= ((rst)? 1'b0  : ((stall)? mem_we  	  	: ex_we));
		mem_mem_flags  		<= ((rst)? 1'b0  : ((stall)? mem_mem_flags  	: ex_mem_flags));
		mem_mem_ex_sel  	<= ((rst)? 1'b0  : ((stall)? mem_mem_ex_sel 	: ex_mem_ex_sel));
		mem_csr_op		<= ((rst)? 3'b0  : ((stall)? mem_csr_op 	: ex_csr_op));
		mem_csr_imm_op		<= ((rst)? 1'b0  : ((stall)? mem_csr_imm_op 	: ex_csr_imm_op));
		mem_csr_addr		<= ((rst)? 1'b0  : ((stall)? mem_csr_addr	: ex_csr_addr));
		mem_exc_addr_if   	<= ((rst)? 1'b0  : ((stall)? mem_exc_addr_if	: ex_exc_addr_if));
	end
endmodule 



		
