

module load_store_unit (
			input clk,
			input rst,
			//INTRUCTION INTERFACE
			input pc,
			output reg [31:0] instruction,
			//INSTRUCTION MEMORY PORT
			input [31:0]  idat_i,
			input 	      iack_i,
			input 	      ierr_i,
			output [31:0] iaddr_o,
			output [31:0] idat_o,
			output 	      isel_o,
			output        icyc_o,
			output        istb_o,
			output        iwe_o,
			//DATA MEMORY PORT
			input [31:0]  ddat_i,
			input 	      dack_i,
			input         derr_i,
			output [31:0] daddr_o,
			output [31:0] ddat_o,
			output [ 3:0] dsel_o,
			output        dcyc_o,
			output        dstb_o,
			output        dwe_o,
			input 	      if_stall ); 

		always @(posedge clk) begin
			if (rst) begin 
				//INTRUCTION MEMORY PORT RESET
				instruction <= 32'b0; 
				idat_o  <= 32'hx; 
				iaddr_o <= 32'hx;
				isel_o  <= 1'b0; 
				iwe_o   <= 1'b0; 
				icyc_o  <= 1'b0;
				istb_o  <= 1'b0; 
				//DATA MEMORY PORT RESET
				ddat_o  <= 32'hx; 
				daddr_o <= 32'hx;
				dsel_o  <= 1'b0; 
				dwe_o   <= 1'b0; 
				dcyc_o  <= 1'b0;
				dstb_o  <= 1'b0; 

			end else begin 
				idat_o  <= 32'hx;
				iaddr_o <= pc;
				isel_o  <= 1'b0;
			        iwe_o   <= 1'b1; 	
				icyc_o  <= pc[1:0] == 0; 
				istb_o  <= pc[1:0] == 0; 

				//TODO: assign memory signals 
			end
		end
endmodule
