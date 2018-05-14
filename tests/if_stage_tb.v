
module testbench(
			input 		clk, 
			output reg	rst,
			//INSTRUCTION INTERFACE
			input [31:0] 	instruction,
			input 		stall,
			input 		ready,
			output reg[31:0] pc ); 
		initial begin
			rst <= 1; 
			repeat(5) @(posedge clk) #1;

			rst <= 0;
			//----------------------------------------
			$display("------------TEST 1 -----------"); 
		       	$display("pc: %h", pc); 	
			repeat(4) begin

				@(posedge ready);
			        wait(ready)$display("instruction = %h", instruction);
			end
			$finish;
		end 
endmodule
