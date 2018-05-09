
module testbench( 
		 input [31:0] pc_i,
		 input clk_i,
		 output reg rst_o); 


	 initial begin
		 rst_o = 1; 
		 repeat(5)  
		 	@(posedge clk_i) #5; 
		 rst_o = 0; 
		 repeat(10) begin
			 @(posedge clk_i) $display("pc = %h", pc_i);
		 end
		$finish; 
	end 

endmodule 
