

module control_unit (
			input 		clk_i,
			input 		rst_i,
			input 		jump_flush_req,
			input 		if_stall_req_i,
			input   	mem_stall_req_i,
			input 		fwd_stall_req_i,
	//		input 	exception,
			output 		if_stall_o, 
			output 		id_stall_o,
			output 		ex_stall_o,
			output  	mem_stall_o,
			output 	reg 	if_flush_o,
			output 	reg 	id_flush_o,
			output 	reg 	ex_flush_o,
			output 	reg 	mem_flush_o,
			output 		ex_nop_o  ); 

		
		assign 	mem_stall_o = mem_stall_req_i;
		assign 	ex_stall_o  = mem_stall_o; 
		assign  id_stall_o  = ex_stall_o; 
		assign  if_stall_o  = if_stall_reg_i | id_stall_o | fwd_stall_req_i; 
		
       		//NOPS 
		assign ex_nop_o = fwd_stall_req_i; 
		
		//FLUSHES
		always @(posedge clk_i) begin
			if(rst_i) begin
				if_flush  <= 1'b1; 
				id_flush  <= 1'b1;
				ex_flush  <= 1'b1; 
				mem_flush <= 1'b1; 
			end else begin
				if_flush   <= jump_flush_req; 
				id_flush   <= 1'b0; 
				ex_flush   <= 1'b0; 
				mem_flush  <= 1'b0;
			end
		end 
endmodule 	

