
module test(
		output reg rst,
		input [31:0] pc_branch_address,
		input [31:0] pc_jump_address,
		input [31:0] porta,
		input [31:0] portb,
		input [4:0]  waddr,
		input 	     we,
		input 	     mem_flags,
		input 	     mem_ex_sel,
		input 	     jump_op,
		input 	     bad_jump_addr,
		input 	     branch_op,
		input        bad_branch_addr,
		input 	     take_branch,
		input 	     break_op,
		input 	     syscall_op,
		input [2:0]  csr_op,
		input 	     csr_imm_op ); 

	initial begin
		$dumpfile("ifid_stage.vcd"); 
		$dumpvars(0,ID,IF); 
		rst <= 1;
		#200
		rst <= 0;
		#400
		$finish;
	end
endmodule
