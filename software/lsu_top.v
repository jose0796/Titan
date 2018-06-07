
module lsu_top(
		input clk_i,
		input rst_i,
		input 	[31:0]	maddr_i,
		input 	[31:0] 	mdat_i,
		input 		mread,
		input 		mwrite,
		input 		mbyte,
		input 		mhw,
		input 		mword,
		input 		munsigned,
		output 	[31:0]	dat_o,
		output 		mem_stall ); 



	wire [31:0]	ddat_i;
	wire		dack_i;
	wire		derr_i;
	wire [31:0]	daddr_o;
	wire [31:0]	ddat_o;
	wire [ 3:0]	dsel_o;
	wire		dcyc_o;
	wire 		dstb_o;
	wire		dwe_o;

	assign mem_stall = ~dack_i;

	load_store_unit LSU (
				.clk(clk_i),	
				.rst(rst_i),
				.maddr_i(maddr_i),
				.mdat_i(mdat_i),
				.mread(mread),
				.mwrite(mwrite),
				.mbyte(mbyte),
				.mhw(mhw),
				.mword(mword),
				.munsigned(munsigned),
				.data_o(dat_o),
				.ddat_i(ddat_i),
				.dack_i(dack_i),
				.derr_i(derr_i),
				.daddr_o(daddr_o),
				.ddat_o(ddat_o),
				.dsel_o(dsel_o),
				.dcyc_o(dcyc_o),
				.dstb_o(dstb_o),
				.dwe_o(dwe_o) ); 

		bram BRAM (
				.clk(clk_i),
				.rst(rst_i),
				.addr_i(daddr_o),	
				.dat_i(ddat_o),
				.sel_i(dsel_o),
				.cyc_i(dcyc_o),
				.stb_i(dstb_o),
				.we_i(dwe_o),
				.dat_o(ddat_i),
				.ack_o(dack_i),
				.err_o(derr_i) ); 

endmodule 	
