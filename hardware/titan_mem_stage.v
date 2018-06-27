

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
		  input 	[ 4:0]	mem_rs1_i, 
		  input 		mem_we_i,
		  input 	[ 5:0]	mem_mem_flags_i,
		  input 		mem_mem_ex_sel_i,
		  input 	[31:0]	mem_csr_data_i,
		  input 	[11:0]	mem_csr_addr_i,
		  input 	[ 2:0] 	mem_csr_op_i,
		  input 		mem_inst_addr_misaligned_i,
		  input 		mem_inst_access_fault_i,
		  input 		mem_illegal_inst_i,
		  input			mem_fence_op_i,
		  input			mem_xret_op_i,
		  input			mem_break_op_i,
		  input			mem_syscall_op_i,
		  //LSU  SIGNALS
		  input 	[31:0] 	mem_data_i,
		  input 		mem_cyc_i,
		  input 		mem_ack_i,
		  input 		mem_err_i,
		  output 		mem_mread_o,
		  output		mem_mwrite_o,
		  output 		mem_mbyte_o,
		  output		mem_mhw_o,
		  output		mem_mword_o,
		  output		mem_munsigned_o,
		
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
		  output reg 	[ 4:0]	wb_rs1_o,
	 	  //EXCEPTION SIGNALS
		  output reg 		wb_inst_addr_misaligned_o,
		  output reg		wb_load_addr_misaligned_o,
		  output reg		wb_store_addr_misaligned_o,
		  output reg 		wb_inst_access_fault_o,
		  output reg 		wb_load_access_fault_o,
		  output reg 		wb_store_access_fault_o,
		  output reg 		wb_illegal_inst_o,
		  output reg		wb_fence_op_o,
		  output reg		wb_xret_op_o,
		  output reg 		wb_break_op_o,
		  output reg 		wb_syscall_op_o
		  ); 
			
		wire mem_load_addr_misaligned_i;
		wire mem_store_addr_misaligned_i;
		wire mem_load_access_fault_i;
		wire mem_store_access_fault_i;

	assign mem_load_addr_misaligned_i  = (mem_mread_o && mem_mword_o)? !(mem_result_i[1:0] == 0): ((mem_mread_o && mem_mhw_o)? !(mem_result_i[0] == 0): 1'b0);
	assign mem_store_addr_misaligned_i  = (mem_mwrite_o && mem_mword_o)? !(mem_result_i[1:0] == 0): ((mem_mwrite_o && mem_mhw_o)? !(mem_result_i[0] == 0): 1'b0);
	assign mem_load_access_fault_i	   = (mem_mem_flags_i[1])? (mem_err_i): 1'b0;
	assign mem_store_access_fault_i	   = (mem_mem_flags_i[0])? (mem_err_i): 1'b0;

	assign mem_request_stall_o 	   = mem_cyc_i & (~mem_ack_i); 
	assign mem_mwrite_o 		   = mem_mem_flags_i[5]; 
	assign mem_mread_o 		   = mem_mem_flags_i[4]; 
	assign mem_mword_o 		   = mem_mem_flags_i[3]; 
	assign mem_mhw_o   		   = mem_mem_flags_i[2]; 
	assign mem_mbyte_o 		   = mem_mem_flags_i[1]; 
	assign mem_munsigned_o 		   = mem_mem_flags_i[0]; 

	reg [31:0] mem_result; 


	assign forward_mem_dat_o = mem_result; 

	always @(*) begin 
		case(mem_mem_ex_sel_i) 
		  1'b0: mem_result = mem_result_i;
		  1'b1: mem_result = mem_data_i;
		 endcase
	end 



	always @(posedge clk_i) begin
	wb_pc_o 		  <= (rst_i | flush) ? 32'h0  : ((stall)? wb_pc_o 			: mem_pc_i); 
	wb_instruction_o 	  <= (rst_i | flush) ? 32'h33 : ((stall)? wb_instruction_o 		: mem_instruction_i); 
	wb_result_o 		  <= (rst_i | flush) ? 32'h0  : ((stall)? wb_result_o 			: mem_result); 
	wb_rs1_o 		  <= (rst_i | flush) ? 5'h0   : ((stall)? wb_rs1_o 			: mem_rs1_i); 
	wb_waddr_o 		  <= (rst_i | flush) ? 5'h0   : ((stall)? wb_waddr_o 			: mem_waddr_i); 
	wb_we_o 		  <= (rst_i | flush) ? 1'h0   : ((stall)? wb_we_o 			: mem_we_i); 
	wb_csr_data_o 		  <= (rst_i | flush) ? 32'h0  : ((stall)? wb_csr_data_o 		: mem_csr_data_i); 
	wb_csr_addr_o 		  <= (rst_i | flush) ? 12'h0  : ((stall)? wb_csr_addr_o 		: mem_csr_addr_i); 
	wb_csr_op_o 		  <= (rst_i | flush) ? 3'h0   : ((stall)? wb_csr_op_o 			: mem_csr_op_i); 
	wb_inst_addr_misaligned_o <= (rst_i | flush) ? 1'h0   : ((stall)? wb_inst_addr_misaligned_o	: mem_inst_addr_misaligned_i); 
	wb_load_addr_misaligned_o <= (rst_i | flush) ? 1'h0   : ((stall)? wb_load_addr_misaligned_o	: mem_load_addr_misaligned_i); 
	wb_store_addr_misaligned_o<= (rst_i | flush) ? 1'h0   : ((stall)? wb_store_addr_misaligned_o	: mem_store_addr_misaligned_i); 
	wb_inst_access_fault_o 	  <= (rst_i | flush) ? 1'h0   : ((stall)? wb_inst_access_fault_o 	: mem_inst_access_fault_i); 
	wb_load_access_fault_o 	  <= (rst_i | flush) ? 1'h0   : ((stall)? wb_load_access_fault_o 	: mem_load_access_fault_i); 
	wb_store_access_fault_o	  <= (rst_i | flush) ? 1'h0   : ((stall)? wb_store_access_fault_o 	: mem_store_access_fault_i); 
	wb_illegal_inst_o	  <= (rst_i | flush) ? 1'h0   : ((stall)? wb_illegal_inst_o 		: mem_illegal_inst_i); 
	wb_fence_op_o	 	  <= (rst_i | flush) ? 1'h0   : ((stall)? wb_fence_op_o 		: mem_fence_op_i); 
	wb_xret_op_o	 	  <= (rst_i | flush) ? 1'h0   : ((stall)? wb_xret_op_o 			: mem_xret_op_i); 
	wb_break_op_o	 	  <= (rst_i | flush) ? 1'h0   : ((stall)? wb_break_op_o 		: mem_break_op_i); 
	wb_syscall_op_o	 	  <= (rst_i | flush) ? 1'h0   : ((stall)? wb_syscall_op_o 		: mem_syscall_op_i); 
	end	

endmodule 








