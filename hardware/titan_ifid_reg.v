
module titan_ifid_reg (
			input 			clk,
			input 			rst,
			input 			id_flush,
			input 			id_stall,
			input 		[31:0]	if_pc,
			input 			if_inst_addr_misaligned,
		        input 			if_inst_access_fault,	
			input 		[31:0]	if_inst,
	       		output reg 	[31:0] 	id_pc,
			output reg 		id_inst_addr_misaligned,
			output reg 	[31:0] 	id_inst,
			output reg 		id_inst_access_fault	);

		
		always 	@(posedge clk) begin
			id_pc  	   	    	<= ((rst|id_flush)? 32'b0  :((id_stall)? id_pc   : if_pc ));  
			id_inst     	    	<= ((rst|id_flush)? 32'h33 :((id_stall)? id_inst : if_inst)); 
			id_inst_access_fault 	<= ((rst|id_flush)? 1'b0   :((id_stall)? id_inst_access_fault: if_inst_access_fault)); 
			id_inst_addr_misaligned <= ((rst|id_flush)? 1'b0   :((id_stall)? id_inst_addr_misaligned : if_inst_addr_misaligned)); 
		end
endmodule


