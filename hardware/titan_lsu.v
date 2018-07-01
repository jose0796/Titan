

module titan_lsu (
			input clk_i,
			input rst_i,
			//INTRUCTION INTERFACE
			input [31:0]      pc,
			output reg [31:0] instruction,
			//INSTRUCTION MEMORY PORT
			input wire	  ikill_i,
			input wire [31:0] idat_i,
			input wire        iack_i,
			input 	          ierr_i,
			output reg [31:0] iaddr_o,
			output reg        icyc_o,
			output reg        istb_o,
			output	 	  istall_o,
		        //DATA PORT INTERFACE

			input [31:0]      maddr_i,
			input [31:0]	  mdat_i,
			input 		  mread_i,
			input 		  mwrite_i,
			input 		  mbyte_i,
			input 		  mhw_i,
			input 		  mword_i,
			input 		  munsigned_i,
			output 		  dstall_o,
			output reg [31:0] data_o,
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
		localparam i_kill = 2'b10;
		//--------DATA PORT FSM STATES---------
		localparam d_str  = 2'b00;
		localparam d_trx   = 2'b01;
		//-------------------------------------
	       	reg [31:0] rdata;
		reg [31:0] wdata;
		reg [ 3:0] wsel_o;
		reg [ 3:0] rsel_o;
		reg  	   runsigned; 
	       	reg [1:0]  i_state;
	        reg [1:0]  d_state;	
		reg 	   kill;

		assign istall_o = (~rst_i & ~iack_i | kill);

		always @(*) begin
			iaddr_o = pc;
			instruction = idat_i;
		end 

		//INSTRUCTION FETCHING PROCESS	
		always @(posedge clk_i) begin
			if (rst_i) begin 
				//INTRUCTION MEMORY PORT RESET
				i_state  <= i_str;
				icyc_o   <= 1'b0;
				istb_o   <= 1'b0;
				kill 	 <= 1'b1; 
			end else begin
				case (i_state)
					i_str: begin
						icyc_o  <= pc[1:0] == 0;
						istb_o  <= pc[1:0] == 0;
						kill	<= 1'b0; 
						if (ikill_i) begin
							i_state <= i_kill;
							kill <= 1'b1; 
						end else if(iack_i) begin 
							istb_o <= 1'b0;
							i_state <= i_str;
						end else if(ierr_i) begin
							istb_o 	<= 1'b0;
							i_state <= i_str; 	
						end
					end
					i_kill: begin
						i_state  <= i_str;
						kill 	 <= 1'b0;
					end		

					default: begin 
						i_state <= i_str; 
						icyc_o 	<= 1'b0;
					end 
				endcase
			end
		end
	

		assign dstall_o = (^{mread_i,mwrite_i} & ~dack_i);


		always @(*) begin
			daddr_o = maddr_i;
			rdata	= ddat_i;
		end


		//MEMORY ACCESSING PROCESS
		always @(posedge clk_i) begin
			if (rst_i) begin 
				ddat_o    <= 32'hx; 
				dwe_o     <= 1'b0; 
				dcyc_o    <= 1'b0;
				dstb_o    <= 1'b0; 
				d_state   <= d_str;
			end else begin
				case(d_state)
					d_str: begin
						dcyc_o <= ((^{mread_i,mwrite_i})? 1'b1: 1'b0);
						dstb_o <= (^{mread_i,mwrite_i})? 1'b1: 1'b0;
						dwe_o  <= ((mwrite_i)? 1'b1: 1'b0); 
						d_state <= d_str; 
						ddat_o  <= wdata;
						dsel_o  <= wsel_o;
						if(dack_i) begin
							dcyc_o 	<= 1'b0;
							dstb_o 	<= 1'b0;
							d_state <= d_str;
							dwe_o	<= 1'b0;
						end else if(derr_i) begin
							dcyc_o <= 1'b0;
							dstb_o <= 1'b0;
							d_state <= d_str; 
							dwe_o	<= 1'b0;
						end
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
				mbyte_i: wsel_o = 4'h1 << maddr_i[1:0];
				mhw_i  : wsel_o = (maddr_i[1])? 4'b1100: 4'b0011;
				mword_i: wsel_o = 4'hf;
			endcase
		end

		always @(*) begin
			if(mread_i) begin
				case(1'b1)
					mword_i: rsel_o = 4'hf;
					mhw_i  : rsel_o = (maddr_i[1])? 4'b1100: 4'b0011;
					mbyte_i: rsel_o = 4'b1 << maddr_i[1:0];
				endcase
				runsigned = munsigned_i; 
			end 
		end


		always @(*) begin
				case(1'b1)
					mread_i: begin
						case(rsel_o)
							4'h1	: data_o = {((runsigned)? 24'h0: {24{rdata[7]}}), rdata[7:0]}; 
							4'h2	: data_o = {((runsigned)? 24'h0: {24{rdata[15]}}), rdata[15:8]}; 
							4'h4	: data_o = {((runsigned)? 24'h0: {24{rdata[23]}}), rdata[23:16]}; 
							4'h8	: data_o = {((runsigned)? 24'h0: {24{rdata[31]}}), rdata[31:24]}; 
							4'h3  	: data_o = {((runsigned)? 16'h0: {16{rdata[15]}}), rdata[15:0]};
							4'hc	: data_o = {((runsigned)? 16'h0: {16{rdata[31]}}), rdata[31:16]};
							default	: data_o = rdata;
						endcase
					end
					mwrite_i: begin
						case(wsel_o)
						       /* verilator lint_off WIDTH */
							4'h1 : begin wdata  = {4{mdat_i[7:0]}};   end
							4'h2 : begin wdata  = {4{mdat_i[7:0]}};   end
							4'h4 : begin wdata  = {4{mdat_i[7:0]}};   end
							4'h8 : begin wdata  = {4{mdat_i[7:0]}};   end
							4'h3 : begin wdata  = {2{mdat_i[15:0]}};   end
							4'hc : begin wdata  = {2{mdat_i[15:0]}};   end
							default	: begin wdata  = mdat_i[31:0];  end
							/*verilator lint_on WIDTH */
						endcase
					end
				endcase
		end

endmodule
