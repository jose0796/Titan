
module testbench( 
		 input [31:0] pc_i,
		 input clk_i,
		 output reg rst_o); 


	 initial begin
		 rst_o = 1; 
		 repeat(5)  
		 	@(posedge clk_i) #5; 
		 rst_o = 0; 
		 repeat(4) begin
			 @(posedge clk_i) $display("pc = %h", pc_i);
		 end
//		 if (pc_i == 32'h00000008) begin
//			 $display("test 1: passed");
//		 end  else begin
//			 $display("test 1: failed, pc = %h", pc_i); 
//		 end
//		 repeat(2) begin
//			 @(posedge clk_i) $display("pc_i = %d", pc_i); 
//		 end
//		 if (pc_i == 32'd8) begin 
//			 $display("test 2: passed"); 
//		end else begin 
//			$display("test 2: failed, pc = %h", pc_i); 
//		end
		$finish; 
	end 

endmodule 
