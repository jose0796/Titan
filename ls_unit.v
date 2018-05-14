

module load_store_unit (
			input clk,
			input rst,
			//INTRUCTION INTERFACE
			input [31:0]      pc,
			output reg [31:0] instruction,
			//INSTRUCTION MEMORY PORT
			input [31:0]      idat_i,
			input 	          iack_i,
			input 	          ierr_i,
			output reg [31:0] iaddr_o,
			output reg [31:0] idat_o,
			output reg        isel_o,
			output reg        icyc_o,
			output reg        istb_o,
			output reg        iwe_o,
			output reg 	  if_stall,
			output reg	  ready,
			output reg 	  xint,
	       		output reg 	  abort,
			output reg 	  no_mem	); 
			//DATA MEMORY PORT
/*			input [31:0]  ddat_i,
			input 	      dack_i,
			input         derr_i,
			output [31:0] daddr_o,
			output [31:0] ddat_o,
			output [ 3:0] dsel_o,
			output        dcyc_o,
			output        dstb_o,
			output        dwe_o,
			input 	      if_stall ); */

	       

	       	localparam i_str  = 2'b00;
	       	localparam i_rx	 = 2'b01;
	       	localparam i_ab	 = 2'b10;
	       	reg [9:0]  no_rps = 10'b1000000000; 
	       	reg [1:0]  i_state; 
		

		always @(*) xint <= ~(pc[1:0] == 0); 

		initial begin
			idat_o  <= 32'hx; 
			isel_o  <= 1'bx; 
			iwe_o   <= 1'b0;
		end
	
		always @(negedge iack_i) begin
		 	if_stall = ~if_stall;
		end 

		always @(posedge clk) begin
			if (rst) begin 
				//INTRUCTION MEMORY PORT RESET

				if_stall <= 1'b1;
				i_state  <= i_str;
				iaddr_o  <= 32'hx;
				icyc_o   <= 1'b0;
				istb_o   <= 1'b0; 
				abort    <= 1'b0;
				ready    <= 1'b0;
				//DATA MEMORY PORT RESET
/*				ddat_o  <= 32'hx; 
				daddr_o <= 32'hx;
				dsel_o  <= 1'b0; 
				dwe_o   <= 1'b0; 
				dcyc_o  <= 1'b0;
				dstb_o  <= 1'b0; */

			end else begin
				case (i_state)
					i_str: begin
						ready   <= 1'b0;
						icyc_o  <= pc[1:0] == 0;
						iaddr_o <= pc;
						istb_o  <= pc[1:0] == 0; 
						if(iack_i) begin 
							instruction <= idat_i;
							icyc_o <= 1'b0;
							istb_o <= 1'b0;
							ready  <= 1'b1;
							i_state <= i_str;
						end 
						else begin 
							no_rps <= {no_rps[0],no_rps[9:1]};
							if(no_rps == 10'd1) begin
								abort  <= 1'b1;
								icyc_o <= 1'b0; 
								istb_o <= 1'b0;
								no_mem <= 1'b1;
								i_state <= i_ab; 
							end	
						end
					end
					i_ab: begin
						i_state <= i_ab;
					end
					default: begin 
						i_state <= i_str; 
						icyc_o <= 1'b0;
					end 
				endcase
				//TODO: assign memory signals 
			end
		end
endmodule
