

module clkgen( output reg clk); 
	
	initial 
		clk = 0; 

	always 
		#10 clk = ~clk; 
	endmodule
