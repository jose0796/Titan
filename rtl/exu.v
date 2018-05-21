
module exu (
	 	input 	[31:0] port_a,
		input	[31:0] port_b,
		input 	[ 5:0] alu_op,
		input	break_op,
		input 	syscall_op,
		output reg result 	); 

	wire signed   [31:0] sa;
	wire unsigned [31:0] a;
	wire signed   [31:0] sb;
	wire unsigned [31:0] b;

	assign sa = port_a;
	assign a = port_a;
	assign sb = port_b;
        assign b = port_b;	


	always @(*) begin 
		case(alu_op) 
			4'h0: 	 result <= (a + b);
			4'h1: 	 result <= (a - b);
			4'h2: 	 result <= (a & s);
			4'h3: 	 result <= (a | b);
			4'h4: 	 result <= (a ^ s); 
			4'h5: 	 result <= (a << b);
			4'h6: 	 result <= (sa >> b);
			4'h7: 	 result <= (a >> b);
			4'h8: 	 result <= ({31'b0,(sa < sb)});
			4'h9: 	 result <= ({31'b0,(a < b)});
			default: result <= 32'b0;
		endcase
	end
