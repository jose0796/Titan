`include "software/ls_unit.v"
`include "software/clk_gen.v"
`include "software/bram2.v"
`include "lsu_tb.v"

module tb;

	wire clk;
	wire rst;
	wire 	[31:0] 	maddr_i;  
	wire 	[31:0] 	mdat_i;
	wire 	[ 5:0] 	mem_flags;
	wire 	[31:0] 	data_o;
	wire 	[31:0]	ddat_i;
	wire 		dack_i;
	wire 		derr_i;
	wire 	[31:0]	daddr_o;
	wire 	[31:0] 	ddat_o;
	wire 	[ 3:0] 	dsel_o;
	wire 		dcyc_o;
	wire 		dstb_p;
	wire 		dwe_o;
	wire 		mem_stall;
	wire 		mem_bus_err;


	clkgen 		CLK( .clk(clk));
	
	load_store_unit LSU(
	       		.clk(clk),
			.rst(rst),
			.maddr_i(maddr_i),
			.mdat_i(mdat_i),
			.mread(mem_flags[5]),
			.mwrite(mem_flags[1]),
			.mbyte(mem_flags[2]),
			.mhw(mem_flags[3]),
			.mword(mem_flags[4]),
			.munsigned(mem_flags[0]),
			.data_o(data_o),	
			.mem_stall(mem_stall),
			.ddat_i(ddat_i),
			.dack_i(dack_i),
			.derr_i(derr_i),
			.daddr_o(daddr_o),
			.ddat_o(ddat_o),
			.dsel_o(dsel_o),
			.dcyc_o(dcyc_o),
			.dstb_o(dstb_o),
			.dwe_o(dwe_o)   );

	bram   BRAM (
		.clk(clk),
		.rst(rst),
		.addr_i(daddr_o),
		.dat_i(ddat_o),
		.sel_i(dsel_o),
		.cyc_i(dcyc_o),
		.stb_i(dstb_o),
		.we_i(dwe_o),
		.dat_o(ddat_i),
		.ack_o(dack_i),
		.err_o(derr_i)    ); 

	testbench tb( 	.clk(clk),
			.rst(rst),
			.ready(dack_i),
			.mem_flags(mem_flags),
			.maddr_i(maddr_i),
			.mdat_i(mdat_i) ); 		


	
endmodule

