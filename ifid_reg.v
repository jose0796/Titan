
module ifid_register (
			input clk,
			input rst,
			input clr,
			input id_stall,
			input  [31:0] pc_i,
			input  [31:0] inst_i,
	       		output reg [31:0] pc_o,
			output reg [31:0] inst_o);

		
		always 	@(posedge clk) begin
			pc_o   <= (rst | clr) ? 32'b0 : ((id_stall)? inst_o : inst_i);  
			inst_o <= (rst | clr)? 32'b0 : ((id_stall)? inst_o : inst_i); 
		end
endmodulee


