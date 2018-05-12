
module testbench ( 
		   				   
		   input  [4:0] rs1,
		   input  [4:0] rs2,
		   input  [4:0] rd,
		   input  reg_write,
		   input  mem_write,
		   input  mem_byte,
		   input  mem_halfword,
		   input  mem_read,
		   input  mem_ex_sel,
		   input  [3:0] alu_op,
		   input  [31:0] imm,
		   input  ex_portb_sel,
		   input  syscall_op,
		   input  branch_op,
		   input  break_op,
		   output reg [31:0] pc,
		   output reg [31:0] instruction); 

	   initial begin 
		instruction = 32'hffc78793;
		#1 //propagation delay
		$display("--------------------------TEST 1------------------------");
		$display("instruction = %h      addi a5, a5, -4", instruction); 
		$display("rs1         = %d", rs1);
		$display("rd          = %d", rd);
		$display("reg_w       = %b", reg_write); 
	        $display("imm         = %h", imm);
		$display("alu_op      = %b", alu_op);
		$display("ex_portb_sel= %b", ex_portb_sel); 

		instruction = 32'h00410133;
		#1 //propagation delay
		$display("--------------------------TEST 2------------------------");
		$display("instruction = %h      add sp, sp, tp", instruction); 
		$display("rs1         = %d", rs1);
		$display("rs2         = %d", rs2); 
		$display("rd          = %d", rd);
		$display("reg_w       = %b", reg_write); 
		$display("alu_op      = %b", alu_op);
		$display("ex_portb_sel= %b", ex_portb_sel); 

		instruction = 32'h2e90106f;
		#1 //propagation delay
		$display("--------------------------TEST 3------------------------");
		$display("instruction = %h      jal  x0, 1bc8", instruction); 
		$display("rd          = %d", rd);
		$display("reg_w       = %b", reg_write); 
	        $display("imm         = %h", imm);
		$display("alu_op      = %b", alu_op);

		instruction = 32'h00512a23;
		#1 //propagation delay
		$display("--------------------------TEST 4------------------------");
		$display("instruction = %h      sw    t0,20(sp)", instruction); 
		$display("rs1         = %d", rs1);
		$display("rs2         = %d", rs2); 
		$display("rd          = %d", rd);
		$display("reg_w       = %b", reg_write); 
	        $display("imm         = %h", imm);
		$display("alu_op      = %b", alu_op);
		
		instruction = 32'h00078463;
		#1 //propagation delay
		$display("--------------------------TEST 5------------------------");
		$display("instruction = %h      beq x0,a5, 1064", instruction); 
		$display("rs1         = %d", rs1);
		$display("rs2         = %d", rs2); 
		$display("rd          = %d", rd);
		$display("reg_w       = %b", reg_write); 
	        $display("imm         = %h", imm);
		$display("alu_op      = %b", alu_op);

		instruction = 32'h00159593;
		#1 //propagation delay
		$display("--------------------------TEST 6------------------------");
		$display("instruction = %h      slli    a1,a1,0x1", instruction); 
		$display("rs1         = %d", rs1);
		$display("rs2         = %d", rs2); 
		$display("rd          = %d", rd);
		$display("reg_w       = %b", reg_write); 
	        $display("imm         = %h", imm);
		$display("alu_op      = %b", alu_op);

		instruction = 32'h40d787b3;
		#1 //propagation delay
		$display("--------------------------TEST 7------------------------");
		$display("instruction = %h      sub a5,a5,a3", instruction); 
		$display("rs1         = %d", rs1);
		$display("rs2         = %d", rs2); 
		$display("rd          = %d", rd);
		$display("reg_w       = %b", reg_write); 
		$display("alu_op      = %b", alu_op);


		instruction = 32'hffc78793;
		#1 //propagation delay
		$display("--------------------------TEST 7------------------------");
		$display("instruction = %h      addi a5, a5, -4", instruction); 
		$display("rs1         = %d", rs1);
		$display("rd          = %d", rd);
		$display("reg_w       = %b", reg_write); 
	        $display("imm         = %h", imm);
		$display("alu_op      = %b", alu_op);




		$finish; 
	   end 
endmodule 	   


		

