`include "./rtl/ls_unit.v"
`include "./rtl/clk_gen.v"
`include "./rtl/bram.v"
`include "./rtl/pc_source.v"
`include "./rtl/pc_add.v"
`include "./rtl/pc_reg.v"
`include "./rtl/ifid_reg.v"
`include "./rtl/dc_unit.v"
`include "./tests/ifid_stage_tb.v"


module tb; 


	wire clk;
	wire rst;
	wire [31:0] pc_o;
	wire [31:0] pc_i;
	wire [31:0] pc_add4;
	wire [31:0] id_pc;
	wire [31:0] if_instruction;
	wire [31:0] id_instruction;
	wire [31:0] idat_i; 
	wire	    iack_i;
	wire 	    ierr_i;
	wire [31:0] iaddr_o; 
	wire [31:0] idat_o;
	wire 	    isel_o;
	wire        icyc_o; 
	wire 	    istb_o;
	wire 	    iwe_o;
	wire 	    if_stall;
	wire 	    if_ready;
	wire	    id_ready;
	wire 	    xint;

	wire [4:0]  rs1;
	wire [4:0]  rs2;
	wire [4:0]  rd;
	wire reg_write;
	wire [2:0] comparator_op;
	wire mem_write;
	wire mem_byte;
	wire mem_halfword;
	wire mem_read;
	wire mem_ex_sel;
	wire mem_unsigned;
	wire [2:0] alu_op;
	wire [31:0] imm;
	wire portb_sel;
	wire porta_sel;
	wire syscall_op;
	wire jump_op;
	wire branch_op;
	wire break_op;


	clkgen    CLK	     (clk);  

	
	pc_source PC_SOURCE  (
				.pc(pc_add4),
				.pc_reg(pc_i) );

	pc_add      PC_ADD4  (
				.pc(pc_o), 
				.pc_next(pc_add4));


	pc_reg 	     PC_REG  ( 
				.clk_i(clk),
				.rst_i(rst),
				.stall(if_stall),
				.pc_i(pc_i),
				.pc_o(pc_o) ); 
	bram 		RAM  ( 
		 		.clk(clk),
				.rst(rst),
				.iaddr_i(iaddr_o),
				.idat_i(idat_o),
				.isel_i(isel_o),
				.icyc_i(icyc_o),
				.istb_i(istb_o),
				.iwe_i(iwe_o),
				.idat_o(idat_i),
				.iack_o(iack_i),
				.ierr_o(ierr_i) );



	load_store_unit LSU  (
				.clk(clk),
				.rst(rst),
				.pc (pc_o),
				.instruction(if_instruction),
				.idat_i(idat_i),
				.iack_i(iack_i),
				.ierr_i(ierr_i),
				.iaddr_o(iaddr_o),
				.idat_o(idat_o),
				.isel_o(isel_o),
				.icyc_o(icyc_o),
				.istb_o(istb_o),
				.iwe_o (iwe_o),
		       		.if_stall(if_stall),
				.ready(if_ready),
				.xint(xint));

	ifid_register IF_ID (
				 .clk(clk),
			 	 .rst(rst),
				 .pc_i(pc_o),
				 .pc_o(id_pc),
				 .ready_i(if_ready),
				 .ready_o(id_ready),
				 .inst_i(if_instruction),
				 .inst_o(id_instruction));	 

	decoder	   DECODE  (
       				.instruction(id_instruction),
				.rs1(rs1),
				.rs2(rs2),
				.rd(rd),
				.reg_write(reg_write),
				.comparator_op(comparator_op),
				.mem_write(mem_write),
				.mem_halfword(mem_halfword),
				.mem_byte(mem_byte),
				.mem_read(mem_read),
				.mem_ex_sel(mem_ex_sel),
				.mem_unsigned(mem_unsigned),
				.alu_op(alu_op),
				.imm(imm),
				.portb_sel(portb_sel),
				.porta_sel(porta_sel),
				.syscall_op(syscall_op),
				.jump_op(jump_op),
				.branch_op(branch_op),
				.break_op(break_op));		
		 
			 
	testbench  TEST   (
				.clk(clk),
				.rst(rst),
				.ready(id_ready),
				.instruction(id_instruction),
				.rs1(rs1),
				.rs2(rs2),
				.rd(rd),
				.reg_write(reg_write),
				.comparator_op(comparator_op),
				.mem_write(mem_write),
				.mem_halfword(mem_halfword),
				.mem_byte(mem_byte),
				.mem_read(mem_read),
				.mem_ex_sel(mem_ex_sel),
				.mem_unsigned(mem_unsigned),
				.alu_op(alu_op),
				.imm(imm),
				.portb_sel(portb_sel),
				.porta_sel(porta_sel),
				.syscall_op(syscall_op),
				.branch_op(branch_op),
				.jump_op(jump_op),
				.break_op(break_op));		
		 

	
endmodule
