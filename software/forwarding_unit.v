

module forward_unit (	
			input 		[ 4:0] 	id_rs1_i,
			input 		[ 4:0] 	id_rs2_i,
			input 			we,
			input 			ls_op,
		        input 		[ 4:0] 	ex_rd_i,
			input 		[ 4:0] 	mem_rd_i,
			input 		[ 4:0] 	wb_rd_i,
			output reg	[ 1:0]	fwd_sel_a,
			output reg 	[ 1:0]	fwd_sel_b,
			output 			ld_dependence ); 

		
		wire ex_fwd_a;
		wire ex_fwd_b;
		wire mem_fwd_a; 
		wire mem_fwd_b; 
		wire wb_fwd_a; 
		wire wb_fwd_b; 

		assign ex_fwd_a  	= (ex_rd_i  == id_rs1_i); 
		assign ex_fwd_b  	= (ex_rd_i  == id_rs2_i); 
		assign mem_fwd_a 	= (mem_rd_i == id_rs1_i); 
		assign mem_fwd_b 	= (mem_rd_i == id_rs2_i); 
		assign wb_fwd_a  	= (wb_rd_i  == id_rs1_i); 
		assign wb_fwd_b  	= (wb_rd_i  == id_rs2_i); 
		assign ld_dependence 	= (ex_fwd_a | ex_fwd_b | ls_op)? 1'b1: 1'b0;  

		always @(*) begin 
			case(1'b1) 
				ex_fwd_a  : fwd_sel_a = (we)? 2'b01 : 2'b0; 
				mem_fwd_a : fwd_sel_a = (we)? 2'b10 : 2'b0; 
				wb_fwd_a  : fwd_sel_a = (we)? 2'b11 : 2'b0; 
			endcase 
		end 
		
		always @(*) begin 
			case(1'b1) 
				ex_fwd_b  : fwd_sel_b = (we)? 2'b01 : 2'b0; 
				mem_fwd_b : fwd_sel_b = (we)? 2'b10 : 2'b0; 
				wb_fwd_b  : fwd_sel_b = (we)? 2'b11 : 2'b0; 
			endcase 
		end 
endmodule
