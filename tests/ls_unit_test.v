`include "../ls_unit.v"
`include "ls_unit_tb.v"
`include "../clk_gen.v"
module tb; 


	wire clk;
	wire rst;
	wire [31:0] pc;
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
	wire 	    xint;
	clkgen   	clkg (clk);  

	load_store_unit LSU (
				.clk(clk),
				.rst(rst),
				.pc (pc),
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
				.xint(xint)); 
	testbench 	test(
				.clk(clk),
				.rst(rst),
				.instruction(instruction),
				.pc (pc),
				.idat_o(idat_i),
				.iack_o(iack_i),
				.ierr_o(ierr_i),
				.iaddr_i(iaddr_o),
				.idat_i(idat_o),
				.isel_i(isel_o),
				.icyc_i(icyc_o),
				.istb_i(istb_o),
				.iwe_i(iwe_o),
				.if_stall(if_stall),
				.xint(xint));
endmodule
