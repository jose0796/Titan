`include "pc_tb.v"
`include "../pc_reg.v"
`include "../pc_add.v"
`include "../pc_source.v"
`include "../clk_gen.v"
module tb; 
	
	wire clk, rst; 
	wire [31:0] pc, pc_add4, ia_pc; 
	clkgen  clock (clk); 

	pc_source pc_hold ( .pc(pc_add4),
			    .pc_reg(ia_pc)); 
	pc_add pc_plus4(
	       		.pc(pc),
			.pc_next(pc_add4)); 	
			
	pc_reg pc_register(
	       		    .clk_i(clk),
			    .rst_i(rst), 
			    .pc_i (ia_pc), 
			    .pc_o (pc)
		    	  ); 
	testbench tbn ( .pc_i(pc), 
			.clk_i(clk), 
			.rst_o(rst) 
			);


	endmodule 

