

module titan_forwarding_unit (	
			input 		[ 4:0] 	id_rs1_i,
			input 		[ 4:0] 	id_rs2_i,
			input 			ex_we_i,
			input 			mem_we_i,
			input 			wb_we_i,
			input 			ls_op_i,
		        input 		[ 4:0] 	ex_rd_i,
			input 		[ 4:0] 	mem_rd_i,
			input 		[ 4:0] 	wb_rd_i,
			output reg	[ 1:0]	fwd_sel_a_o,
			output reg 	[ 1:0]	fwd_sel_b_o,
			output 			ld_dependence_o ); 

		
		wire ex_fwd_a;
		wire ex_fwd_b;
		wire mem_fwd_a; 
		wire mem_fwd_b; 
		wire wb_fwd_a; 
		wire wb_fwd_b; 

		assign ex_fwd_a  	= (~ls_op_i & (ex_rd_i  == id_rs1_i) & ex_we_i); 
		assign ex_fwd_b  	= ((ex_rd_i  == id_rs2_i) & ex_we_i); 
		assign mem_fwd_a 	= ((mem_rd_i == id_rs1_i) & mem_we_i); 
		assign mem_fwd_b 	= ((mem_rd_i == id_rs2_i) & mem_we_i); 
		assign wb_fwd_a  	= ((wb_rd_i  == id_rs1_i) & wb_we_i); 
		assign wb_fwd_b  	= ((wb_rd_i  == id_rs2_i) & wb_we_i); 
		assign ld_dependence_o 	= ((ex_fwd_a | ex_fwd_b) & ls_op_i & mem_we_i)? 1'b1: 1'b0;  

		always @(*) begin 
			case(1'b1) 
				ex_fwd_a  : fwd_sel_a_o =  2'b01; 
				mem_fwd_a : fwd_sel_a_o =  2'b10; 
				wb_fwd_a  : fwd_sel_a_o =  2'b11; 
				default: fwd_sel_a_o = 2'b0;
			endcase 
		end 
		
		always @(*) begin 
			case(1'b1) 
				ex_fwd_b  : fwd_sel_b_o = (ex_we_i)? 2'b01 : 2'b0; 
				mem_fwd_b : fwd_sel_b_o = (mem_we_i)? 2'b10 : 2'b0; 
				wb_fwd_b  : fwd_sel_b_o = (wb_we_i)? 2'b11 : 2'b0; 
				default : fwd_sel_b_o = 2'b0;
			endcase 
		end 
endmodule