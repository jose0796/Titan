
module testbench(
       		  input clk,
	  	  output reg rst,
		  input ready,
		  input [31:0] instruction,
		  input [4:0] rs1,
		  input [4:0] rs2,
		  input [4:0] rd,
		  input reg_write,
		  input [2:0] comparator_op,
		  input mem_write,
		  input mem_byte, 
		  input mem_halfword,
		  input mem_read,
		  input mem_ex_sel,
		  input mem_unsigned,
		  input [ 2:0] alu_op,
		  input [31:0] imm,
		  input portb_sel,
		  input porta_sel,
		  input syscall_op,
		  input branch_op,
		  input jump_op,
		  input break_op      ); 

	  initial begin
		  rst <= 1;
		  repeat(2) @(posedge clk) #1; 
		  rst <= 0;
		  $display("Instruction to be fetch and decoded: "); 
		  $display("+ fff70713     addi  a4, a4,-1"); 
		  $display("+ 0016f793     andi  a5, a3, 1"); 
		  $display("+ 0001e2b7     lui   t0, 0x1e "); 
		  $display("+ 00001297     auipc t0, 0x1 "); 
		  $display("+ 0000006f     jal   x0, 18f0, pc = 18f0"); 
		  repeat(5) begin 
		  @(posedge ready) #1; 
		  $display("+++++++++++++++++++++++++++++++"); 
		  $display("instruction  = %h", instruction); 
		  $display("rs1          = %d", rs1); 
		  $display("rs2          = %d", rs2); 
		  $display("rd           = %d", rd);
		  $display("reg_write    = %b", reg_write);
		  $display("comparator_op= %b", comparator_op); 
		  $display("mem_write    = %b", mem_write); 
		  $display("mem_byte     = %b", mem_byte);
		  $display("mem_halfword = %b", mem_halfword); 
		  $display("mem_read     = %b", mem_read); 
		  $display("mem_unsigned = %b", mem_unsigned); 
		  $display("alu_op       = %b", alu_op); 
		  $display("immediate    = %h", imm);
		  $display("portb_sel    = %b", portb_sel); 
		  $display("porta_sel    = %b", porta_sel); 
		  $display("syscall_op   = %b", syscall_op);
		  $display("jump_op      = %b", jump_op);
		  $display("branch_op    = %b", branch_op); 
		  $display("break_op     = %b", break_op);
		  end 
		  $finish; 
	 end
endmodule

