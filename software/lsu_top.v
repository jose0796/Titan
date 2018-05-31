
module lsu_top (
		input 		clk_i,
		input 		rst_i,
		input 	[31:0]	maddr_i,
		input 	[31:0]	mdat_i,
		input 		mread,
		input 		mwrite,
		input 		mbyte,
		input 		mword,
		input 		munsigned,
		output	[31:0]	data_o,
		output 		mem_stall,
		output 		mem_bus_err  ); 



	load_store_unit  LSU (
				.clk(clk_i), 
					
