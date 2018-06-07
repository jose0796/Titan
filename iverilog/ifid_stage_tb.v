
module test( output reg rst ); 

	initial begin
		$dumpfile("ifid_stage.vcd"); 
		$dumpvars(0,ID,IF); 
		rst <= 1;
		#200
		rst <= 0;
		#400
		$finish;
	end
endmodule
