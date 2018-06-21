

module titan_exmem_register (
		  input 		clk,
		  input 		rst,
		  input 		stall,
		  input 		flush,
		  input		[31:0]	ex_pc,
		  input		[31:0]	ex_instruction,
		  input 	[31:0] 	ex_result,
		  input 	[ 4:0] 	ex_waddr,
		  input 		ex_we,
		  input 	[ 5:0]	ex_mem_flags,
		  input 	[31:0]	ex_store_data,
		  input 		ex_mem_ex_sel,
		  input			ex_bad_jump_addr,
		  input			ex_bad_branch_addr,
		  input			ex_break_op,
		  input			ex_syscall_op,
		  input		[31:0]	ex_csr_data,
		  input 	[ 2:0]  ex_csr_op,
		  input		[11:0]	ex_csr_addr,
		  input 		ex_exc_addr_if,
		  input 		ex_bus_access_fault,
		  output reg 	[31:0]	mem_pc,
		  output reg 	[31:0]	mem_instruction,
		  output reg 	[31:0] 	mem_result,
		  output reg 	[ 4:0] 	mem_waddr,
		  output reg		mem_we,
		  output reg 	[ 5:0] 	mem_mem_flags,
		  output reg 	[31:0]	mem_store_data,
		  output reg		mem_mem_ex_sel,
		  output reg 		mem_bad_jump_addr,
		  output reg 		mem_bad_branch_addr,
		  output reg 		mem_break_op,
		  output reg 		mem_syscall_op,
		  output reg 	[31:0]	mem_csr_data,
		  output reg 	[ 2:0] 	mem_csr_op,
		  output reg 	[11:0]	mem_csr_addr,
		  output reg		mem_exc_addr_if,
	 	  output reg 		mem_bus_access_fault
	 
	 	 );

	always @(posedge clk) begin
		mem_pc			<= ((rst|flush)? 32'b0 : ((stall)? mem_pc		: ex_pc)); 
		mem_instruction		<= ((rst|flush)? 32'b0 : ((stall)? mem_instruction	: ex_instruction)); 
		mem_result 		<= ((rst|flush)? 32'b0 : ((stall)? mem_result 		: ex_result)); 
		mem_waddr  		<= ((rst|flush)? 5'b0  : ((stall)? mem_waddr  		: ex_waddr));
		mem_we     		<= ((rst|flush)? 1'b0  : ((stall)? mem_we  	  	: ex_we));
		mem_mem_flags  		<= ((rst|flush)? 6'b0  : ((stall)? mem_mem_flags  	: ex_mem_flags));
		mem_store_data  	<= ((rst|flush)? 32'b0 : ((stall)? mem_store_data  	: ex_store_data));
		mem_mem_ex_sel  	<= ((rst|flush)? 1'b0  : ((stall)? mem_mem_ex_sel 	: ex_mem_ex_sel));
		mem_csr_data	   	<= ((rst|flush)? 32'b0 : ((stall)? mem_csr_data		: ex_csr_data));
		mem_csr_op		<= ((rst|flush)? 3'b0  : ((stall)? mem_csr_op 		: ex_csr_op));
		mem_csr_addr		<= ((rst|flush)? 12'b0 : ((stall)? mem_csr_addr		: ex_csr_addr));
		mem_exc_addr_if   	<= ((rst|flush)? 1'b0  : ((stall)? mem_exc_addr_if	: ex_exc_addr_if));
		mem_bad_jump_addr   	<= ((rst|flush)? 1'b0  : ((stall)? mem_bad_jump_addr	: ex_bad_jump_addr));
		mem_bad_branch_addr   	<= ((rst|flush)? 1'b0  : ((stall)? mem_bad_branch_addr	: ex_bad_branch_addr));
		mem_break_op	   	<= ((rst|flush)? 1'b0  : ((stall)? mem_break_op		: ex_break_op));
		mem_syscall_op	   	<= ((rst|flush)? 1'b0  : ((stall)? mem_syscall_op	: ex_syscall_op));
		mem_bus_access_fault	<= ((rst|flush)? 1'b0  : ((stall)? mem_bus_access_fault : ex_bus_access_fault)); 
	end
endmodule 



		
