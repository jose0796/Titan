
module bram(
		input 		  clk,
	       	input 		  rst,
		input [31:0] 	  iaddr_i,
		input [31:0] 	  idat_i,
		input 	     	  isel_i,
		input        	  icyc_i,
		input        	  istb_i,
		input        	  iwe_i,
		output reg [31:0] idat_o,
		output reg        iack_o,
		output reg        ierr_o ); 


		reg [31:0] memory [31:0]; 

		reg b_state;
	        localparam b_str = 1'b0;
		localparam b_tx  = 1'b1; 

		initial begin
			memory[0] = 32'hfff70713;
			memory[4] = 32'h0016f793;
			memory[8] = 32'hDEADF00D;
			memory[12] = 32'hDEADCADD;
		end

		always @(posedge clk) begin
			if (rst) begin
				idat_o <= 32'bx;
				iack_o <= 1'b0;
				ierr_o <= 1'b0; 
				b_state <= b_str;
			end else begin 
				case(b_state) 
					b_str: begin
						iack_o <= 1'b0;
						if( icyc_i && istb_i) begin
							iack_o <= 1'b1;
							idat_o  = memory[iaddr_i]; 
							b_state <= b_str; 
						end 

					end 
				endcase
			end
		end
endmodule 
