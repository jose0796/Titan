
module testbench ( 
		   		   
		   input  [4:0] rs1,
		   input  [4:0] rs2,
		   input  [4:0] rd,
		   input  [2:0] comparator_op,
		   input  reg_write,
		   input  mem_write,
		   input  mem_byte,
		   input  mem_halfword,
		   input  mem_read,
		   input  mem_unsigned,
		   input  [2:0] alu_op,
		   input  [31:0] imm,
		   input  portb_sel,
		   input  porta_sel,
		   input  syscall_op,
		   input  branch_op,
		   input  jump_op,
		   input  break_op,
		   output reg [31:0] pc,
		   output reg [31:0] instruction); 

	   initial begin 
		instruction = 32'h0001e2b7;
		#1 //propagation delay
		$display("--------------------------TEST 1------------------------");
		$display("instruction   = %h      lui  t0, 0x1e", instruction); 
		$display("rs1           = %d", rs1);
		$display("rs2           = %d", rs2); 
		$display("rd            = %d", rd);
		$display("comparator_op = %b", comparator_op);
		$display("reg_write     = %b", reg_write); 
		$display("mem_write     = %b", mem_write);
		$display("mem_read      = %b", mem_read);
		$display("mem_byte      = %b", mem_byte);
		$display("mem_halfword  = %b", mem_halfword);
	        $display("mem_unsigned  = %b", mem_unsigned);
		$display("alu_op        = %b", alu_op);
		$display("imm           = %h", imm);
		$display("porta_sel     = %b", porta_sel);
	       	$display("portb_sel     = %b", portb_sel);
		$display("syscall_op    = %b", syscall_op);
		$display("branch_op     = %b", branch_op);
		$display("jump_op       = %b", jump_op);
		$display("break_op      = %b", break_op);

		instruction = 32'h00001297;
		#1 //propagation delay
		$display("--------------------------TEST 2------------------------");
		$display("instruction  = %h      auipc t0,0x1", instruction); 
		$display("rs1           = %d", rs1);
		$display("rs2           = %d", rs2); 
		$display("rd            = %d", rd);
		$display("comparator_op = %b", comparator_op);
		$display("reg_write     = %b", reg_write); 
		$display("mem_write     = %b", mem_write);
		$display("mem_read      = %b", mem_read);
		$display("mem_byte      = %b", mem_byte);
		$display("mem_halfword  = %b", mem_halfword);
	        $display("mem_unsigned  = %b", mem_unsigned);
		$display("alu_op        = %b", alu_op);
		$display("imm           = %h", imm);
		$display("porta_sel     = %b", porta_sel);
	       	$display("portb_sel     = %b", portb_sel);
		$display("syscall_op    = %b", syscall_op);
		$display("branch_op     = %b", branch_op);
		$display("jump_op       = %b", jump_op);
		$display("break_op      = %b", break_op);

		instruction = 32'h30d0106f;
		#1 //propagation delay
		$display("--------------------------TEST 3------------------------");
		$display("instruction = %h      jal  x0, 1bec", instruction); 
		$display("rs1           = %d", rs1);
		$display("rs2           = %d", rs2); 
		$display("rd            = %d", rd);
		$display("comparator_op = %b", comparator_op);
		$display("reg_write     = %b", reg_write); 
		$display("mem_write     = %b", mem_write);
		$display("mem_read      = %b", mem_read);
		$display("mem_byte      = %b", mem_byte);
		$display("mem_halfword  = %b", mem_halfword);
	        $display("mem_unsigned  = %b", mem_unsigned);
		$display("alu_op        = %b", alu_op);
		$display("imm           = %h", imm);
		$display("porta_sel     = %b", porta_sel);
	       	$display("portb_sel     = %b", portb_sel);
		$display("syscall_op    = %b", syscall_op);
		$display("branch_op     = %b", branch_op);
		$display("jump_op       = %b", jump_op);
		$display("break_op      = %b", break_op);

		instruction = 32'h9d8080e7;
		#1 //propagation delay
		$display("--------------------------TEST 4------------------------");
		$display("instruction = %h      jalr -1576(ra)", instruction); 
		$display("rs1           = %d", rs1);
		$display("rs2           = %d", rs2); 
		$display("rd            = %d", rd);
		$display("comparator_op = %b", comparator_op);
		$display("reg_write     = %b", reg_write); 
		$display("mem_write     = %b", mem_write);
		$display("mem_read      = %b", mem_read);
		$display("mem_byte      = %b", mem_byte);
		$display("mem_halfword  = %b", mem_halfword);
	        $display("mem_unsigned  = %b", mem_unsigned);
		$display("alu_op        = %b", alu_op);
		$display("imm           = %h", imm);
		$display("porta_sel     = %b", porta_sel);
	       	$display("portb_sel     = %b", portb_sel);
		$display("syscall_op    = %b", syscall_op);
		$display("branch_op     = %b", branch_op);
		$display("jump_op       = %b", jump_op);
		$display("break_op      = %b", break_op);
		
		instruction = 32'h00f60863;
		#1 //propagation delay
		$display("--------------------------TEST 5------------------------");
		$display("instruction = %h      beq a2,a5, 10f4", instruction); 
		$display("rs1           = %d", rs1);
		$display("rs2           = %d", rs2); 
		$display("rd            = %d", rd);
		$display("comparator_op = %b", comparator_op);
		$display("reg_write     = %b", reg_write); 
		$display("mem_write     = %b", mem_write);
		$display("mem_read      = %b", mem_read);
		$display("mem_byte      = %b", mem_byte);
		$display("mem_halfword  = %b", mem_halfword);
	        $display("mem_unsigned  = %b", mem_unsigned);
		$display("alu_op        = %b", alu_op);
		$display("imm           = %h", imm);
		$display("porta_sel     = %b", porta_sel);
	       	$display("portb_sel     = %b", portb_sel);
		$display("syscall_op    = %b", syscall_op);
		$display("branch_op     = %b", branch_op);
		$display("jump_op       = %b", jump_op);
		$display("break_op      = %b", break_op);

		instruction = 32'h04c6a023;
		#1 //propagation delay
		$display("--------------------------TEST 6------------------------");
		$display("instruction = %h      sw    a2,64(a3)", instruction); 
		$display("rs1           = %d", rs1);
		$display("rs2           = %d", rs2); 
		$display("rd            = %d", rd);
		$display("comparator_op = %b", comparator_op);
		$display("reg_write     = %b", reg_write); 
		$display("mem_write     = %b", mem_write);
		$display("mem_read      = %b", mem_read);
		$display("mem_byte      = %b", mem_byte);
		$display("mem_halfword  = %b", mem_halfword);
	        $display("mem_unsigned  = %b", mem_unsigned);
		$display("alu_op        = %b", alu_op);
		$display("imm           = %h", imm);
		$display("porta_sel     = %b", porta_sel);
	       	$display("portb_sel     = %b", portb_sel);
		$display("syscall_op    = %b", syscall_op);
		$display("branch_op     = %b", branch_op);
		$display("jump_op       = %b", jump_op);
		$display("break_op      = %b", break_op);

		instruction = 32'h0005a783;
		#1 //propagation delay
		$display("--------------------------TEST 7------------------------");
		$display("instruction = %h      lw   a5,0(a1)", instruction); 
		$display("rs1           = %d", rs1);
		$display("rs2           = %d", rs2); 
		$display("rd            = %d", rd);
		$display("comparator_op = %b", comparator_op);
		$display("reg_write     = %b", reg_write); 
		$display("mem_write     = %b", mem_write);
		$display("mem_read      = %b", mem_read);
		$display("mem_byte      = %b", mem_byte);
		$display("mem_halfword  = %b", mem_halfword);
	        $display("mem_unsigned  = %b", mem_unsigned);
		$display("alu_op        = %b", alu_op);
		$display("imm           = %h", imm);
		$display("porta_sel     = %b", porta_sel);
	       	$display("portb_sel     = %b", portb_sel);
		$display("syscall_op    = %b", syscall_op);
		$display("branch_op     = %b", branch_op);
		$display("jump_op       = %b", jump_op);
		$display("break_op      = %b", break_op);

		instruction = 32'h3ac70713;
		#1 //propagation delay
		$display("--------------------------TEST 7------------------------");
		$display("instruction = %h      addi a4,a4, 940", instruction); 
		$display("rs1           = %d", rs1);
		$display("rs2           = %d", rs2); 
		$display("rd            = %d", rd);
		$display("comparator_op = %b", comparator_op);
		$display("reg_write     = %b", reg_write); 
		$display("mem_write     = %b", mem_write);
		$display("mem_read      = %b", mem_read);
		$display("mem_byte      = %b", mem_byte);
		$display("mem_halfword  = %b", mem_halfword);
	        $display("mem_unsigned  = %b", mem_unsigned);
		$display("alu_op        = %b", alu_op);
		$display("imm           = %h", imm);
		$display("porta_sel     = %b", porta_sel);
	       	$display("portb_sel     = %b", portb_sel);
		$display("syscall_op    = %b", syscall_op);
		$display("branch_op     = %b", branch_op);
		$display("jump_op       = %b", jump_op);
		$display("break_op      = %b", break_op);

		instruction = 32'h00156713;
		#1 //propagation delay
		$display("--------------------------TEST 7------------------------");
		$display("instruction = %h      ori  a4,a0,1", instruction); 
		$display("rs1           = %d", rs1);
		$display("rs2           = %d", rs2); 
		$display("rd            = %d", rd);
		$display("comparator_op = %b", comparator_op);
		$display("reg_write     = %b", reg_write); 
		$display("mem_write     = %b", mem_write);
		$display("mem_read      = %b", mem_read);
		$display("mem_byte      = %b", mem_byte);
		$display("mem_halfword  = %b", mem_halfword);
	        $display("mem_unsigned  = %b", mem_unsigned);
		$display("alu_op        = %b", alu_op);
		$display("imm           = %h", imm);
		$display("porta_sel     = %b", porta_sel);
	       	$display("portb_sel     = %b", portb_sel);
		$display("syscall_op    = %b", syscall_op);
		$display("branch_op     = %b", branch_op);
		$display("jump_op       = %b", jump_op);
		$display("break_op      = %b", break_op);


		instruction = 32'h00f57693;
		#1 //propagation delay
		$display("--------------------------TEST 7------------------------");
		$display("instruction = %h      andi  a3,a0,15", instruction); 
		$display("rs1           = %d", rs1);
		$display("rs2           = %d", rs2); 
		$display("rd            = %d", rd);
		$display("comparator_op = %b", comparator_op);
		$display("reg_write     = %b", reg_write); 
		$display("mem_write     = %b", mem_write);
		$display("mem_read      = %b", mem_read);
		$display("mem_byte      = %b", mem_byte);
		$display("mem_halfword  = %b", mem_halfword);
	        $display("mem_unsigned  = %b", mem_unsigned);
		$display("alu_op        = %b", alu_op);
		$display("imm           = %h", imm);
		$display("porta_sel     = %b", porta_sel);
	       	$display("portb_sel     = %b", portb_sel);
		$display("syscall_op    = %b", syscall_op);
		$display("branch_op     = %b", branch_op);
		$display("jump_op       = %b", jump_op);
		$display("break_op      = %b", break_op);

		instruction = 32'h01c59813;
		#1 //propagation delay
		$display("--------------------------TEST 7------------------------");
		$display(" = %h     slli a6,a1,0x1c", instruction); 
		$display("rs1           = %d", rs1);
		$display("rs2           = %d", rs2); 
		$display("rd            = %d", rd);
		$display("comparator_op = %b", comparator_op);
		$display("reg_write     = %b", reg_write); 
		$display("mem_write     = %b", mem_write);
		$display("mem_read      = %b", mem_read);
		$display("mem_byte      = %b", mem_byte);
		$display("mem_halfword  = %b", mem_halfword);
	        $display("mem_unsigned  = %b", mem_unsigned);
		$display("alu_op        = %b", alu_op);
		$display("imm           = %h", imm);
		$display("porta_sel     = %b", porta_sel);
	       	$display("portb_sel     = %b", portb_sel);
		$display("syscall_op    = %b", syscall_op);
		$display("branch_op     = %b", branch_op);
		$display("jump_op       = %b", jump_op);
		$display("break_op      = %b", break_op);

		instruction = 32'h41f7d793;
		#1 //propagation delay
		$display("--------------------------TEST 7------------------------");
		$display("instruction = %h     srai a5,a5,0x1f", instruction); 
		$display("rs1           = %d", rs1);
		$display("rs2           = %d", rs2); 
		$display("rd            = %d", rd);
		$display("comparator_op = %b", comparator_op);
		$display("reg_write     = %b", reg_write); 
		$display("mem_write     = %b", mem_write);
		$display("mem_read      = %b", mem_read);
		$display("mem_byte      = %b", mem_byte);
		$display("mem_halfword  = %b", mem_halfword);
	        $display("mem_unsigned  = %b", mem_unsigned);
		$display("alu_op        = %b", alu_op);
		$display("imm           = %h", imm);
		$display("porta_sel     = %b", porta_sel);
	       	$display("portb_sel     = %b", portb_sel);
		$display("syscall_op    = %b", syscall_op);
		$display("branch_op     = %b", branch_op);
		$display("jump_op       = %b", jump_op);
		$display("break_op      = %b", break_op);



		instruction = 32'h00470733;
		#1 //propagation delay
		$display("--------------------------TEST 7------------------------");
		$display("instruction = %h      add  a4,a4,tp", instruction); 
		$display("rs1           = %d", rs1);
		$display("rs2           = %d", rs2); 
		$display("rd            = %d", rd);
		$display("comparator_op = %b", comparator_op);
		$display("reg_write     = %b", reg_write); 
		$display("mem_write     = %b", mem_write);
		$display("mem_read      = %b", mem_read);
		$display("mem_byte      = %b", mem_byte);
		$display("mem_halfword  = %b", mem_halfword);
	        $display("mem_unsigned  = %b", mem_unsigned);
		$display("alu_op        = %b", alu_op);
		$display("imm           = %h", imm);
		$display("porta_sel     = %b", porta_sel);
	       	$display("portb_sel     = %b", portb_sel);
		$display("syscall_op    = %b", syscall_op);
		$display("branch_op     = %b", branch_op);
		$display("jump_op       = %b", jump_op);
		$display("break_op      = %b", break_op);
	
		instruction = 32'h40d787b3;
		#1 //propagation delay
		$display("--------------------------TEST 7------------------------");
		$display("instruction = %h      sub  a5,a5,a3", instruction); 
		$display("rs1           = %d", rs1);
		$display("rs2           = %d", rs2); 
		$display("rd            = %d", rd);
		$display("comparator_op = %b", comparator_op);
		$display("reg_write     = %b", reg_write); 
		$display("mem_write     = %b", mem_write);
		$display("mem_read      = %b", mem_read);
		$display("mem_byte      = %b", mem_byte);
		$display("mem_halfword  = %b", mem_halfword);
	        $display("mem_unsigned  = %b", mem_unsigned);
		$display("alu_op        = %b", alu_op);
		$display("imm           = %h", imm);
		$display("porta_sel     = %b", porta_sel);
	       	$display("portb_sel     = %b", portb_sel);
		$display("syscall_op    = %b", syscall_op);
		$display("branch_op     = %b", branch_op);
		$display("jump_op       = %b", jump_op);
		$display("break_op      = %b", break_op);
	
		instruction = 32'h00a86533;
		#1 //propagation delay
		$display("--------------------------TEST 7------------------------");
		$display("instruction = %h      or  a0,a6,a0", instruction); 
		$display("rs1           = %d", rs1);
		$display("rs2           = %d", rs2); 
		$display("rd            = %d", rd);
		$display("comparator_op = %b", comparator_op);
		$display("reg_write     = %b", reg_write); 
		$display("mem_write     = %b", mem_write);
		$display("mem_read      = %b", mem_read);
		$display("mem_byte      = %b", mem_byte);
		$display("mem_halfword  = %b", mem_halfword);
	        $display("mem_unsigned  = %b", mem_unsigned);
		$display("alu_op        = %b", alu_op);
		$display("imm           = %h", imm);
		$display("porta_sel     = %b", porta_sel);
	       	$display("portb_sel     = %b", portb_sel);
		$display("syscall_op    = %b", syscall_op);
		$display("branch_op     = %b", branch_op);
		$display("jump_op       = %b", jump_op);
		$display("break_op      = %b", break_op);
		
		$dumpfile("test.vcd");
		$dumpvars(0,test);	
		
		$finish; 
	   end 
endmodule 	   


		

