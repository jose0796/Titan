

module mux2_1 (
		input 	[31:0] in_1,
		input 	[31:0] in_2,
		input    	sel,
		output	[31:0] out  ); 

	always @(*) begin
		case(sel):
			1'b0: out<= in_1; 
			1'b1: out<= in_2;
		endcase
	end
endmodule
		
