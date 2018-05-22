
module test(
		output reg rst,
		input [31:0] id_pc_i,
		input [31:0] id_instruction_i,
		input exc_addr_i,
		input ready_i );

	initial begin
		$dumpfile("if_stage.vcd"); 
		$dumpvars(0,IF); 
		rst <= 1;
		#200
		rst <= 0;
		#400
		$finish;
	end
endmodule
