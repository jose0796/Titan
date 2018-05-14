
module pc_reg(
		input clk_i,
		input rst_i,
		input stall,
		input [31:0] pc_i,
	        output reg [31:0] pc_o); 

	always @(posedge clk_i) begin
		pc_o <= ((rst_i)? (32'h00000000): ((stall)? pc_o : pc_i));
	end	
endmodule 
