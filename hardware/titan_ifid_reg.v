
module titan_ifid_reg (
			input 			clk,
			input 			rst,
			input 			flush,
			input 			if_stall,
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
			id_pc  	   	    	<= ((rst|flush)? 32'b0  :((id_stall)? id_pc: ((if_stall)? 32'b0: if_pc )));  
			id_inst     	    	<= ((rst|flush)? 32'h33 :((id_stall)? id_inst: ((if_stall)? 32'h33 : if_inst))); 
			id_inst_access_fault 	<= ((rst|flush)? 1'b0   :((id_stall)? id_inst_access_fault :((if_stall)? 1'b0:  if_inst_access_fault))); 
			id_inst_addr_misaligned <= ((rst|flush)? 1'b0   :((id_stall)? id_inst_addr_misaligned :((if_stall)? 1'b0:  if_inst_addr_misaligned))); 
		end
endmodule


