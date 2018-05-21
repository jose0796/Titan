
module ifid_register (
			input clk,
			input rst,
			input clr,
			input stall,
			input [31:0] pc_i,
			input [31:0] pc_add4_i,
			input exc_addr_i, 
			input [31:0] inst_i,
			input 	ready_i,
			output reg ready_o,
	       		output reg [31:0] pc_o,
			output reg [31:0] pc_add4_o,
			output reg exc_addr_i,
			output reg [31:0] inst_o);

		
		always 	@(posedge clk) begin
			pc_o  	   <= ((rst) ? 32'b0 :((stall)? pc_o: pc_i));  
			pc_add4_o  <= ((rst)? 32'b0 : ((stall) pc_add4_o : pc_add4_i));
			exc_addr_o <= ((rst)? 1'b0 : ((stall) exc_addr_o : exc_addr_i));
			inst_o 	   <= ((rst) ? 32'h33 :((stall)? inst_o: inst_i)); 
			ready_o    <= (ready_i);
		end
endmodule


