
module ifid_register (
			input 			clk,
			input 			rst,
			input 			flush,
			input 			stall,
			input [31:0] 		if_pc,
			input [31:0] 		if_pc_add4,
			input 			if_exc_addr, 
			input [31:0] 		if_inst,
			input 			if_ready,
	       		output reg [31:0] 	id_pc,
			output reg [31:0] 	id_pc_add4,
			output reg 		id_exc_addr,
			output reg [31:0] 	id_inst,
			output reg 		id_ready );

		
		always 	@(posedge clk) begin
			id_pc  	    <= ((rst) ? 32'b0	:((stall)? id_pc: if_pc));  
			id_pc_add4  <= ((rst)?  32'b0 	:((stall)? id_pc_add4 : if_pc_add4));
			id_exc_addr <= ((rst)?   1'b0 	:((stall)? id_exc_addr : if_exc_addr));
			id_inst     <= ((rst) ? 32'h33 	:((stall)? id_inst: if_inst)); 
			id_ready    <= (if_ready);
		end
endmodule

