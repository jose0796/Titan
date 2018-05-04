
module testbench( 
		 input [31:0] pc_i,
		 input clk_i,
		 output reg rst_o); 


	 initial begin
		 rst_o = 1; 
		 repeat(5)  
		 	@(posedge clk_i) #5; 
//		$display("rst = %d", rst_o); 
		$display("pc_i = %h", pc_i);
		 rst_o = 0; 
//		$display("rst = %d", rst_o); 
//		@(posedge clk_i) #1; 
		 $display("pc_i (testbench) = %h", pc_i);
		 if (pc_i == 32'h00000004) begin
			 $display("test 1: passed");
		 end  else begin
			 $display("test 1: failed, pc = %h", pc_i); 
		 end
		$finish; 
	end 

endmodule 
