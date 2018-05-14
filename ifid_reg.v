
module ifid_register (
			input clk,
			input rst,
			input clr,
			input stall,
			input  [31:0] pc_i,
			input  [31:0] inst_i,
			input 	ready_i,
			output reg ready_o,
	       		output reg [31:0] pc_o,
			output reg [31:0] inst_o);

		
		always 	@(posedge clk) begin
			pc_o   <= ((rst) ? 32'b0 :  pc_i);  
			inst_o <= ((rst) ? 32'b0 : inst_i ); 
			ready_o <= (ready_i);
		end
endmodule


