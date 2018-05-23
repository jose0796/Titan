

module test (
		input [31:0] pc_branch_address,
		input [31:0] pc_jump_address,
		input [31:0] port_a,
		input [31:0] port_b,
		input [ 2:0] alu_op,
		input [ 4:0] waddr,
		input [31:0] wdata,
	       	input we,
		input [ 4:0] mem_access,
		input mem_ex_sel,
		input jump_op,
		input bad_jump_addr,
		input branch_op,
		input bad_branch_addr,
		input break_op,
		input syscall_op,
		input mem_unsigned,
		input [ 2:0] csr_op,
		input csr_imm_op,
		output reg [31:0] pc,
		output reg [31:0] pc_add4,
		output reg [31:0] instruction,
		output reg [31:0] wb_data, 
		output reg [ 4:0] wb_address,
		output reg wb_we ); 

	initial begin 
		$dumpfile("id_stage.vcd");
		$dumpvars(0,TEST); 
		// TEST 1
		pc 		<= 32'd0;
	        pc_add4 	<= 32'd1;
		instruction	<= 32'hfff70713;
	        wb_data		<= 32'd1;
		wb_address	<= 4'd1;
		#20;
		$finish;
	end
endmodule	
			
