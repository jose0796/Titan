`timescale 1ns/1ps
module idex_reg (
       		input 			clk,
	 	input 			rst, 
		input 			stall,
		input 			flush,
		input 		[31:0]	id_pc,
		input 		[31:0]	id_instruction,
		input 		[31:0] 	id_porta,
	        input 		[31:0] 	id_portb,
		input 		[ 3:0] 	id_alu_op,
		input 			id_we,
		input 		[ 5:0]	id_mem_flags,
		input 			id_mem_ex_sel,
		input 			id_bad_jump_addr,
		input 			id_bad_branch_addr,
		input 			id_break_op,
		input 			id_syscall_op,
		input 		[31:0]	id_csr_data,
		input 		[ 2:0] 	id_csr_op,
		input 		[11:0]	id_csr_addr,	
		input 		[4:0] 	id_waddr,
		input 			id_exc_addr_if,
		output reg	[31:0]	ex_pc,
		output reg 	[31:0]	ex_instruction,
		output reg 	[31:0] 	ex_porta,
		output reg 	[31:0] 	ex_portb,
		output reg 	[ 3:0] 	ex_alu_op,
		output reg 		ex_we,
		output reg 	[ 5:0] 	ex_mem_flags,
		output reg 		ex_mem_ex_sel,
		output reg 		ex_bad_jump_addr,
		output reg 		ex_bad_branch_addr,
		output reg 		ex_break_op,
		output reg 		ex_syscall_op,
		output reg 	[31:0]	ex_csr_data,
		output reg 	[11:0]	ex_csr_addr,
		output reg 	[ 2:0] 	ex_csr_op,
       		output reg 	[ 4:0] 	ex_waddr,
		output reg 		ex_exc_addr_if
	); 


	always @(posedge clk) begin
		ex_instruction 	   <= ((rst|flush)? 32'b0 : ((stall)? ex_instruction 			: id_instruction)); 
		ex_pc 	   	   <= ((rst|flush)? 32'b0 : ((stall)? ex_pc 			: id_pc)); 
		ex_porta 	   <= ((rst|flush)? 32'b0 : ((stall)? ex_porta 			: id_porta)); 
	        ex_portb 	   <= ((rst|flush)? 32'b0 : ((stall)? ex_portb 			: id_portb)); 
		ex_alu_op	   <= ((rst|flush)? 4'b0  : ((stall)? ex_alu_op			: id_alu_op));
		ex_we    	   <= ((rst|flush)? 1'b0  : ((stall)? ex_we    			: id_we   ));
		ex_mem_flags	   <= ((rst|flush)? 6'b0  : ((stall)? ex_mem_flags	  	: id_mem_flags)); 
		ex_mem_ex_sel	   <= ((rst|flush)? 1'b0  : ((stall)? ex_mem_ex_sel	  	: id_mem_ex_sel)); 
		ex_bad_jump_addr   <= ((rst|flush)? 1'b0  : ((stall)? ex_bad_jump_addr 		: id_bad_jump_addr));
		ex_bad_branch_addr <= ((rst|flush)? 1'b0  : ((stall)? ex_bad_branch_addr  	: id_bad_branch_addr));
		ex_break_op	   <= ((rst|flush)? 1'b0  : ((stall)? ex_break_op 	  	: id_break_op));
		ex_syscall_op      <= ((rst|flush)? 1'b0  : ((stall)? ex_syscall_op       	: id_syscall_op));
		ex_csr_op	   <= ((rst|flush)? 3'b0  : ((stall)? ex_csr_op			: id_csr_op )); 
		ex_csr_addr	   <= ((rst|flush)? 3'b0  : ((stall)? ex_csr_addr		: id_csr_addr )); 
		ex_csr_data	   <= ((rst|flush)? 1'b0  : ((stall)? ex_csr_data 	  	: id_csr_data)); 
		ex_waddr 	   <= ((rst|flush)? 4'b0  : ((stall)? ex_waddr			: id_waddr)); 
		ex_exc_addr_if     <= ((rst|flush)? 1'b0  : ((stall)? ex_exc_addr_if      	: id_exc_addr_if));
	end
endmodule

			

