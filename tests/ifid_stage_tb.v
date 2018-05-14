
module testbench(
       		  input clk,
	  	  output reg rst,
		  input ready,
		  input [31:0] pc,
		  input [31:0] instruction,
		  input [4:0] rs1,
		  input [4:0] rs2,
		  input [4:0] rd,
		  input reg_write,
		  input mem_write,
		  input mem_byte, 
		  input mem_halfword,
		  input mem_read,
		  input mem_ex_sel,
		  input [ 3:0] alu_op,
		  input [31:0] imm,
		  input ex_portb_sel,
		  input syscall_op,
		  input branch_op,
		  input break_op      ); 

	  initial begin
		  rst <= 1;
		  repeat(2) @(posedge clk) #1; 
		  rst <= 0;
		  repeat(4) begin 
		  @(posedge ready) #1;
		  $display("+++++++++++++++++++++++++++++++"); 
		  $display("instruction  = %h", instruction); 
		  $display("rs1          = %d", rs1); 
		  $display("rs2          = %d", rs2); 
		  $display("rd           = %d", rd);
		  $display("reg_write    = %b", reg_write); 
		  $display("mem_write    = %b", mem_write); 
		  $display("mem_byte     = %b", mem_byte);
		  $display("mem_halfword = %b", mem_halfword); 
		  $display("mem_read     = %b", mem_read); 
		  $display("alu_op       = %b", alu_op); 
		  $display("immediate    = %h", imm);
		  $display("ex_portb_sel = %b", ex_portb_sel); 
		  $display("syscall_op   = %b", syscall_op);
		  $display("branch_op    = %b", branch_op); 
		  $display("break_op     = %b", break_op);
	  end
		  $finish; 
	 end
endmodule

