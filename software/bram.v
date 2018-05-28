
module bram(
		input 		  clk,
	       	input 		  rst,
		input [31:0] 	  addr_i,
		input [31:0] 	  dat_i,
		input [ 3:0]   	  sel_i,
		input        	  cyc_i,
		input        	  stb_i,
		input        	  we_i,
		output reg [31:0] dat_o,
		output reg        ack_o,
		output reg        err_o	); 


		reg [7:0] memory [1024:0]; 

		reg b_state;
		reg [7:0] rdat;
		reg [7:0] wdat;
	        localparam b_str = 1'b0;
		localparam b_tx  = 1'b1; 

		initial begin
			memory[0]  = 8'h00;
			memory[1]  = 8'h00;
			memory[2]  = 8'h12;
			memory[3]  = 8'h97;
			memory[4]  = 8'h00;
			memory[5]  = 8'hb5;
			memory[6]  = 8'h70;
			memory[7]  = 8'h63;
			memory[8]  = 8'h00;
			memory[9]  = 8'h11;
			memory[10] = 8'h22;
			memory[11] = 8'h23;
			memory[12] = 8'h00;
			memory[13] = 8'h41;
			memory[14] = 8'h20;
			memory[15] = 8'h83;
			memory[16] = 8'h30;
			memory[17] = 8'h02;
			memory[18] = 8'ha0;
			memory[19] = 8'h73;
//			memory[12] = 32'h00000213;
//			memory[16] = 32'h00000293;
//			memory[20] = 32'h00000313;
		/*	memory[0]  = 32'hfff70713;
			memory[4]  = 32'h0016f793;
			memory[8]  = 32'h0001e2b7;
			memory[12] = 32'h00001297;
			memory[16] = 32'h0000006f;
			memory[20] = 32'h000900e7;*/
		end

		always @(*) if (~(cyc_i & stb_i)) ack_o = 1'b0;

		always @(posedge clk) begin
			if (rst) begin
				dat_o <= 32'bx;
				ack_o <= 1'b0;
				err_o <= 1'b0; 
				b_state <= b_str;
			end else begin 
				case(b_state) 
					b_str: begin
						ack_o <= 1'b0;
						if( cyc_i && stb_i) begin
							ack_o 	<= 1'b1;
							b_state <= b_str; 
						end 

					end 
				endcase
			end
		end

	always @(*) begin
		case(we_i) 
			1'b0: begin
				case(sel_i)
					4'h1: dat_o = {4{memory[addr_i]}}; 
					4'h3: dat_o = {2{memory[addr_i],memory[addr_i+1]}};
					4'hc: dat_o = {2{memory[addr_i],memory[addr_i+1]}};
					4'hf: dat_o = {memory[addr_i], memory[addr_i+1],memory[addr_i+2], memory[addr_i + 3]};
					default: err_o = 1;
				endcase
			end
			1'b1: begin
				case(sel_i)
					4'h1: begin memory[addr_i] = dat_i[7:0]; end
					4'h3: begin memory[addr_i] = dat_i[15:8]; memory[addr_i+1] = dat_i[7:0]; end
					4'hc: begin memory[addr_i] = dat_i[31:24]; memory[addr_i+1] = dat_i[23:16]; end
				        4'hf: begin
						memory[addr_i]	 = dat_i[31:24];
						memory[addr_i+1] = dat_i[23:16];
						memory[addr_i+2] = dat_i[15:8]; 
						memory[addr_i+3] = dat_i[7:0];	
					end
				endcase
			end
		endcase
	end			



endmodule 
