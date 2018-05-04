`include "../tb.v"
`include "../pc_reg.v"
`include "../pc_add.v"
`include "../pc_source.v"
`include "../clk_gen.v"
module tb; 
	
	wire clk, rst; 
	wire [31:0] pc_i, pc_o, pc_reg; 
	clkgen  clock (clk); 

//	pc_source pc_hold ( .pc(pc_i),
//			    .pc_reg(pc_reg)); 
	pc_add pc_add4(
	       		.pc(pc_o),
			.pc_next(pc_i)); 	
			
	pc_reg pc_register(
	       		    .clk_i(clk),
			    .rst_i(rst), 
			    .pc_i (pc_reg), 
			    .pc_o (pc_o)
		    	  ); 
	testbench tbn ( .pc_i(pc_i), 
			.clk_i(clk), 
			.rst_o(rst) 
			);


	endmodule 

