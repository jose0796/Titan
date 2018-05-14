
module testbench(
			input 		clk, 
			output reg	rst,
			//INSTRUCTION INTERFACE
			input [31:0] 	instruction,
			input 		stall,
			input 		ready,
			output reg[31:0] pc ); 
			//INSTRUCTION MEMORY PORT
	/*		output reg [31:0] idat_o,
			output reg	iack_o,
			output reg	ierr_o,
			input  [31:0] 	iaddr_i,
			input  [31:0]	idat_i,
			input 		isel_i,
			input 		icyc_i,
			input 		istb_i,
			input 		iwe_i,
	       		input 		if_stall,
			input 		xint); */
			
		initial begin
			rst <= 1; 
			repeat(5) @(posedge clk) #1;

			rst <= 0;
			//----------------------------------------
			$display("------------TEST 1 -----------"); 
			repeat(4) begin
				@(posedge ready) #1;
				$display("instruction = %h", instruction);
				#20;
			end
			$finish;
		end 
endmodule
