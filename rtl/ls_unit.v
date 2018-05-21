

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
			output reg 	  inst_misaligned,
	       		output reg 	  abort,
			output reg 	  no_mem,
		        //DATA PORT INTERFACE
			input [31:0]      maddr_i,
			input [31:0]	  mdat_i,
			input 		  mread,
			input 		  mwrite,
			input 		  mbyte,
			input 		  mhw,
			input 		  mword,
			input 		  munsigned,
			output reg [31:0] data_o,
			output reg 	  mem_stall,
			output reg 	  mem_bus_err,
			//DATA MEMORY PORT
			input [31:0]  	  ddat_i,
			input 	      	  dack_i,
			input         	  derr_i,
			output reg [31:0] daddr_o,
			output reg [31:0] ddat_o,
			output reg [ 3:0] dsel_o,
			output reg        dcyc_o,
			output reg        dstb_o,
			output reg        dwe_o ); 

	       
		//-----INSTRUCTION PORT FSM STATES-----
	       	localparam i_str  = 2'b00;
	       	localparam i_ab	  = 2'b01;
		localparam i_err  = 2'b10;
		//--------DATA PORT FSM STATES---------
		localparam d_str  = 2'b00;
		localparam d_rx   = 2'b01;
		localparam d_tx   = 2'b10;
		localparam d_err  = 2'b11;
		//-------------------------------------
		localparam nrps   = 64'h8000000000000000;
		localparam nop    = 32'h00000033;
	       	reg [31:0]  rdata;
		reg [31:0]  wdata;
		reg [63:0]  no_rps = nrps; 
	       	reg [1:0]  i_state;
	        reg [1:0]  d_state;	


		always @(*) inst_misaligned <= ~(pc[1:0] == 0); 

		initial begin
			idat_o  <= 32'hx; 
			isel_o  <= 1'bx; 
			iwe_o   <= 1'b0;
			no_mem  <= 1'b1;
		end
		//INSTRUCTION FETCHING PROCESS	
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

			end else begin
				ready 	 <= ((ready)? 1'b0:((iack_i)? 1'b1: 1'b0));
				if_stall <= ((if_stall)? ((iack_i| ierr_i)? 1'b0: 1'b1): 1'b1);
				case (i_state)
					i_str: begin
						icyc_o  <= pc[1:0] == 0;
						iaddr_o <= pc;
						istb_o  <= pc[1:0] == 0;
						if(iack_i) begin 
							instruction <= idat_i;
							icyc_o <= 1'b0;
							istb_o <= 1'b0;
							i_state <= i_str;
							no_rps <= nrps;
						end else if(ierr_i) begin
						        icyc_o 	<= 1'b0;
							istb_o 	<= 1'b0;
							i_state <= i_err; 	
							end else begin 
							no_rps <= {no_rps[0],no_rps[63:1]};
							if(no_rps == 64'd1) begin
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
					i_err:	begin 
						i_state <= i_str;
					end

					default: begin 
						i_state <= i_str; 
						icyc_o <= 1'b0;
					end 
				endcase
			end
		end
	

		//MEMORY ACCESSING PROCESS
		//
		always @(posedge clk) begin
			if (rst) begin 
				ddat_o    <= 32'hx; 
				daddr_o   <= 32'hx;
				dsel_o    <= 1'b0; 
				dwe_o     <= 1'b0; 
				dcyc_o    <= 1'b0;
				dstb_o    <= 1'b0; 
				d_state   <= d_str;
				mem_stall <= 1'b1;
			end else begin
				mem_stall     <= ((|{mread,mwrite})? 1'b1: ((dack_i)? 1'b0: 1'b1)); 
				case(d_state)
					d_str: begin
						dcyc_o <= (|{mread,mwrite})? 1'b1: 1'b0;
						dstb_o <= (|{mread,mwrite})? 1'b1: 1'b0;
						dwe_o  <= ((mwrite)? 1'b1: 1'b0); 
						daddr_o <= maddr_i;
						d_state <=((mwrite)? d_tx:((mread)? d_rx: d_str)); 
					end 
					d_rx: begin //load state
						if(dack_i) begin
							dcyc_o 	<= 1'b0;
							dstb_o 	<= 1'b0;
							rdata  	<= ddat_i;
							d_state <= d_str;
						end else if(derr_i) begin
							mem_bus_err <= 1'b1;
							d_state <= d_err;	
							dcyc_o <= 1'b0;
							dstb_o <= 1'b0;
						end
					end
					d_tx: begin //store state 
						if(dack_i) begin
							dcyc_o <= 1'b0;
							dstb_o <= 1'b0;
							ddat_o <= wdata;
							d_state <= d_str;
						end else if(derr_i) begin
							mem_bus_err <= 1'b1;
							d_state <= d_err;
							dcyc_o  <= 1'b0;
							dstb_o  <= 1'b0;
						end
					end 
					d_err:begin
					       mem_bus_err <= 1'b0;
				       	       dcyc_o      <= 1'b0;
					       d_state 	   <= d_str;
					end
					default: begin
						dcyc_o    <= 1'b0;
						dstb_o    <= 1'b0;
						d_state   <= d_str;
					end
				endcase
			end
		end 
		

		always @(*) begin
			case(1'b1)
				mread: begin
					case(1'b1)
						mbyte	: data_o <= {((munsigned)? 24'h0: {24{rdata[7]}}), rdata[7:0]}; 
						mhw  	: data_o <= {((munsigned)? 16'h0: {16{rdata[15]}}), rdata[15:0]};
						default	: data_o <= rdata;
					endcase
				end
				mwrite: begin
					case(1'b1) 
						mbyte	: wdata  <= mdat_i[7:0];
						mhw  	: wdata  <= mdat_i[15:0];
						default	: wdata  <= mdat_i; 
					endcase
				end
			endcase
		end




endmodule
