
module test( output reg rst ); 

	initial begin
		$dumpfile("ifex_stage.vcd"); 
		$dumpvars(0,ID,IF,EX); 
		rst <= 1;
		#200
		rst <= 0;
		#400
		$finish;
	end
endmodule
