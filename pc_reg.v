
module pc_reg(
		input clk_i,
		input rst_i,
		input [31:0] pc_i,
	        output reg [31:0] pc_o); 

	always @(posedge clk_i) begin
//	       $display("pc_i = %h , pc_o = %h", pc_i, pc_o); 	
		pc_o <= (rst_i)? (32'h00000000): pc_i;
	end	
endmodule 
