`include "./tests/pc_tb.v"
`include "./rtl/pc_reg.v"
`include "./rtl/pc_add.v"
`include "./rtl/pc_source.v"
`include "./rtl/clk_gen.v"
module tb; 
	
	wire clk, rst; 
	wire [31:0] pc;
	wire [31:0] pc_add4;
       	wire [31:0] pc_src; 	

	clkgen    CLK_GEN   (clk); 

	pc_source PC_SOURCE ( .pc(pc_add4),
			      .pc_reg(pc_src)); 
	pc_add    PC_ADD    (
		       		.pc(pc),
				.pc_next(pc_add4)); 	
			
	pc_reg    PC_REG    (
	       		    	.clk_i(clk),
				.rst_i(rst), 
			    	.pc_i (pc_src), 
			    	.pc_o (pc)
		    	  	); 

	testbench  TEST  ( 	.pc_i(pc), 
				.clk_i(clk), 
				.rst_o(rst) 
				);


	endmodule 

