
module testbench( 
		 input [31:0] pc_i,
		 input clk_i,
		 output reg rst_o); 


	 initial begin
		$dumpfile("pc_test.vcd");
		$dumpvars(0,PC_REG,PC_ADD, PC_SOURCE);
		 rst_o = 1; 
		 repeat(5)  
		 	@(posedge clk_i) #1; 
		 rst_o = 0; 
		 repeat(10) begin
			 @(posedge clk_i) #1 $display("pc = %h", pc_i);
		 end
		$finish; 
	end 

endmodule 
