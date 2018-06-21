

module titan_mem_stage( 
		  input 		clk_i, 
		  input 		rst_i,
		  input 		stall,
		  input 		flush,
		  //MEM => ID FORWARDING 
		  output 	[31:0] forward_mem_dat_o,
	          //EX => MEM SIGNALS 
		  input 	[31:0]	mem_pc_i,
		  input 	[31:0]	mem_instruction_i,
		  input		[31:0]	mem_result_i, 
		  input 	[ 4:0] 	mem_waddr_i, 
		  input 		mem_we_i,
		  input 	[ 5:0]	mem_mem_flags_i,
		  input 		mem_mem_ex_sel_i,
		  input 	[31:0]	mem_csr_data_i,
		  input 	[11:0]	mem_csr_addr_i,
		  input 	[ 2:0] 	mem_csr_op_i,
		  input 		mem_exc_addr_if_i,
		  input 		mem_bus_access_fault_i,
		  input 		mem_mbus_access_fault_i,
		  input			mem_bad_jump_addr_i,
		  input 		mem_bad_branch_addr_i,
		  input			mem_break_op_i,
		  input			mem_syscall_op_i,
		  //LSU  SIGNALS
		  input 	[31:0] 	mem_data_i,
		  input 		mem_cyc_i,
		  input 		mem_ack_i,
		  output 		mem_mread_o,
		  output		mem_mwrite_o,
		  output 		mem_mbyte_o,
		  output		mem_mhw_o,
		  output		mem_mword_o,
		  output		mem_munsigned_o,
		  //CONTROL SIGNALS 
		
		  output 		mem_request_stall_o,
		  

		  //MEM => WB SIGNALS
		  
		  output reg 	[31:0] 	wb_pc_o,
		  output reg 	[31:0] 	wb_instruction_o,
	 	  output reg 	[31:0]	wb_result_o,
	 	  output reg 	[ 4:0]	wb_waddr_o,
		  output reg 		wb_we_o,
		  //CSR SIGNALS
		  output reg 	[31:0]	wb_csr_data_o,
		  output reg 	[11:0]	wb_csr_addr_o,
		  output reg 	[ 2:0]	wb_csr_op_o,
	 	  //EXCEPTION SIGNALS
		  output reg 		wb_exc_addr_if_o,
		  output reg 		wb_bad_jump_addr_o,
		  output reg 		wb_bad_branch_addr_o,
		  output reg 		wb_break_op_o,
		  output reg 		wb_syscall_op_o,
		  output reg		wb_bus_access_fault_o,
		  output reg		wb_mbus_access_fault_o
		  ); 
			

		assign mem_request_stall_o 	= mem_cyc_i & (~mem_ack_i); 
		assign mem_mwrite_o 		= mem_mem_flags_i[0]; 
		assign mem_mread_o 		= mem_mem_flags_i[1]; 
		assign mem_mword_o 		= mem_mem_flags_i[2]; 
		assign mem_mhw_o   		= mem_mem_flags_i[3]; 
		assign mem_mbyte_o 		= mem_mem_flags_i[4]; 
		assign mem_munsigned_o 		= mem_mem_flags_i[5]; 

		reg [31:0] mem_result; 

		assign forward_mem_dat_o = mem_result; 

		always @(*) begin 
			case(mem_mem_ex_sel_i) 
			  1'b0: mem_result = mem_result_i;
			  1'b1: mem_result = mem_data_i;
			 endcase
		end 



		always @(posedge clk_i) begin
			wb_pc_o 		<= (rst_i | flush) ? 32'h0  : ((stall)? wb_pc_o 		: mem_pc_i); 
			wb_instruction_o 	<= (rst_i | flush) ? 32'h33 : ((stall)? wb_instruction_o 	: mem_instruction_i); 
			wb_result_o 		<= (rst_i | flush) ? 32'h0  : ((stall)? wb_result_o 		: mem_result); 
			wb_waddr_o 		<= (rst_i | flush) ? 5'h0   : ((stall)? wb_waddr_o 		: mem_waddr_i); 
			wb_we_o 		<= (rst_i | flush) ? 1'h0   : ((stall)? wb_we_o 		: mem_we_i); 
			wb_csr_data_o 		<= (rst_i | flush) ? 32'h0  : ((stall)? wb_csr_data_o 		: mem_csr_data_i); 
			wb_csr_addr_o 		<= (rst_i | flush) ? 12'h0  : ((stall)? wb_csr_addr_o 		: mem_csr_addr_i); 
			wb_csr_op_o 		<= (rst_i | flush) ? 3'h0   : ((stall)? wb_csr_op_o 		: mem_csr_op_i); 
			wb_exc_addr_if_o 	<= (rst_i | flush) ? 1'h0   : ((stall)? wb_exc_addr_if_o 	: mem_exc_addr_if_i); 
			wb_bus_access_fault_o 	<= (rst_i | flush) ? 1'h0   : ((stall)? wb_bus_access_fault_o 	: mem_bus_access_fault_i); 
			wb_mbus_access_fault_o 	<= (rst_i | flush) ? 1'h0   : ((stall)? wb_mbus_access_fault_o 	: mem_mbus_access_fault_i); 
			wb_bad_jump_addr_o 	<= (rst_i | flush) ? 1'h0   : ((stall)? wb_bad_jump_addr_o 	: mem_bad_jump_addr_i); 
			wb_bad_branch_addr_o 	<= (rst_i | flush) ? 1'h0   : ((stall)? wb_bad_branch_addr_o 	: mem_bad_branch_addr_i); 
			wb_break_op_o	 	<= (rst_i | flush) ? 1'h0   : ((stall)? wb_break_op_o 		: mem_break_op_i); 
			wb_syscall_op_o	 	<= (rst_i | flush) ? 1'h0   : ((stall)? wb_syscall_op_o 	: mem_syscall_op_i); 
		end	

endmodule 








