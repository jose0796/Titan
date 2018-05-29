
module testbench (
		input clk,
		input ready,
		output reg rst,
		output reg [5:0] mem_flags,
		output reg [31:0] maddr_i,
		output reg [31:0] mdat_i );

	initial begin

		$dumpfile("test.vcd"); 
		$dumpvars(0,LSU,BRAM,tb); 
		rst<= 1;
		repeat(5) @(posedge clk) #1;
		rst <= 0; 
		mem_flags <= 6'b110000;
		maddr_i   <= 32'd0;
	  	wait(ready) #1;
		mem_flags <= 6'b000000;
		#100
		@(posedge clk) #1;
		mem_flags <= 6'b010010;
		maddr_i <= 32'd0;
		mdat_i  <= 32'd7;
		wait(ready) #40;

		$finish;
	end
endmodule
