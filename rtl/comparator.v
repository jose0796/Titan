
module branch_predictor (
		   input [2:0] sel, 
		   input [31:0] drs1,
		   input [31:0] drs2, 
		   output reg branch_taken ); 

	reg [31:0] result; 
	localparam beq 	= 3'h1;
	localparam bne 	= 3'h2;
	localparam blt	= 3'h3;
	localparam bge 	= 3'h4;
	localparam bltu = 3'h5;
	localparam bgeu = 3'h6; 
	localparam nop  = 3'h0;

	always @(*) begin
		case(sel)
			beq: 

		   

