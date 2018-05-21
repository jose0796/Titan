
module idex_reg (
       		input clk,
	 	input rst, 
		input stall,
		input flush,
		input [31:0] porta_i,
	        input [31:0] portb_i,
		input we_i,
		input [ 5:0] mem_flags_i,
		input mem_ex_sel_i,
		input bad_jump_addr_i,
		input bad_branch_addr_i,
		input break_op_i,
		input syscall_op_i,
		input [ 2:0] csr_op_i,
		input csr_imm_op,
		output reg [31:0] porta_o,
		output reg [31:0] portb_o,
		output reg we_o,
		output reg [ 5:0] mem_flags_i,
		output reg bad_jump_addr_o,
		output reg bad_branch_addr_o,
		output reg break_op_o,
		output reg syscall_op_o,
		output reg [ 2:0] csr_op_o,
		output reg csr_imm_op ); 


	always @(*) begin
		porta_o 	  <= ((rst)? 32'b0 : ((stall)? porta_o 		  : portb_i)); 
	        portb_o 	  <= ((rst)? 32'b0 : ((stall)? portb_o 		  : portb_i)); 
		we_o    	  <= ((rst)? 1'b0  : ((stall)? we_o    		  : we_i   ));
		mem_flags_i	  <= ((rst)? 6'b0  : ((stall)? mem_flags_o	  : mem_flags_i)); 
		bad_jump_addr_o   <= ((rst)? 1'b0  : ((stall)? bad_jump_addr_o 	  : bad_jump_addr_i));
		bad_branch_addr_o <= ((rst)? 1'b0  : ((stall)? bad_branch_addr_o  : bad_branch_addr_i));
		break_op_o	  <= ((rst)? 1'b0  : ((stall)? break_op_o 	  : break_op_i));
		syscall_op_o      <= ((rst)? 1'b0  : ((stall)? syscall_op_o       : syscall_op_i));
		csr_op_o	  <= ((rst)? 3'b0  : ((stall)? csr_op_o		  : csr_op_o )); 
		csr_imm_op	  <= ((rst)? 1'b0  : ((stall)? csr_imm_op 	  : csr_imm_op)); 
	end
endmodule

			

