`include "./software/ls_unit.v"
`include "./tests/ls_unit_tb.v"
`include "./software/clk_gen.v"
`include "./software/bram.v"
`include "./software/pc_source.v"
`include "./software/pc_add.v"
`include "./software/pc_reg.v"

module tb; 


	wire clk;
	wire rst;
	wire [31:0] pc_o;
	wire [31:0] pc_i;
	wire [31:0] pc_add4;
	wire [31:0] instruction;
	wire [31:0] idat_i; 
	wire	    iack_i;
	wire 	    ierr_i;
	wire [31:0] iaddr_o; 
	wire [31:0] idat_o;
	wire 	    isel_o;
	wire        icyc_o; 
	wire 	    istb_o;
	wire 	    iwe_o;
	wire 	    if_stall;
	wire 	    ready;
	wire 	    xint;
	clkgen  	CLK (clk);  

	
	pc_source PC_SOURCE (
				.pc(pc_add4),
				.pc_reg(pc_i) );

	pc_add	    PC_ADD4 (
				.pc(pc_o), 
				.pc_next(pc_add4));


	pc_reg 	     PC_REG ( 
				.clk_i(clk),
				.rst_i(rst),
				.stall(if_stall),
				.pc_i(pc_i),
				.pc_o(pc_o) ); 
	

	load_store_unit LSU (
				.clk(clk),
				.rst(rst),
				.pc (pc_o),
				.instruction(instruction),
				.idat_i(idat_i),
				.iack_i(iack_i),
				.ierr_i(ierr_i),
				.iaddr_o(iaddr_o),
				.idat_o(idat_o),
				.isel_o(isel_o),
				.icyc_o(icyc_o),
				.istb_o(istb_o),
				.iwe_o (iwe_o),
		       		.if_stall(if_stall),
				.ready(ready),
				.xint(xint)); 
	testbench      TEST (
				.clk(clk),
				.rst(rst),
				.stall(if_stall),
				.ready(ready),
				.instruction(instruction) ); 
	bram 	       BRAM ( 
		 		.clk(clk),
				.rst(rst),
				.iaddr_i(iaddr_o),
				.idat_i(idat_o),
				.isel_i(isel_o),
				.icyc_i(icyc_o),
				.istb_i(istb_o),
				.iwe_i(iwe_o),
				.idat_o(idat_i),
				.iack_o(iack_i),
				.ierr_o(ierr_i) );
endmodule
