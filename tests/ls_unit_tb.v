
module testbench(
			input 		clk, 
			output reg	rst,
			//INSTRUCTION INTERFACE
			input [31:0] 	instruction,
			output reg[31:0] pc,
			//INSTRUCTION MEMORY PORT
			output reg [31:0] idat_o,
			output reg	iack_o,
			output reg	ierr_o,
			input  [31:0] 	iaddr_i,
			input  [31:0]	idat_i,
			input 		isel_i,
			input 		icyc_i,
			input 		istb_i,
			input 		iwe_i,
	       		input 		if_stall,
			input 		xint); 
		
		initial begin
			rst <= 1; 
			repeat(5) @(posedge clk) #1;

			$display("----------RESET TEST--------- "); 
			$display("instruction = %h", instruction); 
			$display("idat_i = %h", idat_i); 
			$display("isel_i = %h", isel_i); 
			$display("icyc_i = %h", icyc_i); 
			$display("istb_i = %h", istb_i); 
			$display("iwe_i = %h", iwe_i); 
			rst <= 0;
			//----------------------------------------
			$display("------------TEST 1 -----------"); 
			pc = 32'b0; 
			wait(icyc_i & istb_i) begin
				idat_o = 32'h11111111;
				iack_o = 1'b1; 
			end
			@(posedge clk) begin
				$display("pc = %h", pc);
				$display("instruction = %h", instruction);
					
			end
			$display("------------TEST 2 -----------"); 
			pc = 32'd4; 
			wait(icyc_i & istb_i) begin
				idat_o = 32'h23647862;
				iack_o = 1'b1; 
			end
			@(posedge clk) begin
				$display("pc = %h", pc);
				$display("instruction = %h", instruction);
					
			end
			//---------------------------------------
			//ILEGAL INSTRUCTION TEST
			repeat(5) @(posedge clk) #1;
			$display("------------TEST 3------------"); 
			pc = 32'd2;
			repeat(2) begin
			@(posedge clk) begin
				if (xint) begin
					$display("pc = %h", pc); 
					$display("Instruction misaligned."); 
				end
			end
		end
				
			$finish;
		end 
endmodule
