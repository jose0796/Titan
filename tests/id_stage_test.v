`include "./id_stage_tb.v"
`include "../id_stage.v"

module tb; 
	wire [31:0] pc;
	wire [31:0] instruction; 
	wire [ 4:0] rs1;
	wire [ 4:0] rs2;
	wire [ 4:0] rd;
	wire reg_write;
	wire mem_write;
	wire mem_byte;
	wire mem_halfword;
	wire mem_read;
	wire mem_ex_sel;
	wire [ 3:0] alu_op;
	wire [31:0] imm;
	wire ex_portb_sel;
	wire syscall_op;
	wire branch_op;
	wire break_op;

	testbench test(
			.rs1(rs1),
			.rs2(rs2),
			.rd(rd),
			.reg_write(reg_write),
			.mem_write(mem_write),
			.mem_byte(mem_byte),
			.mem_halfword(mem_halfword),
			.mem_read(mem_read),
			.mem_ex_sel(mem_ex_sel),
			.alu_op(alu_op),
			.imm(imm),
			.ex_portb_sel(ex_portb_sel),
			.syscall_op(syscall_op),
			.branch_op(branch_op),
			.break_op(break_op),
			.pc(pc),
			.instruction(instruction) ); 

	decoder decode (	
			.instruction(instruction),
			.pc(pc),
			.rs1(rs1),
			.rs2(rs2),
			.rd(rd),
			.reg_write(reg_write),
			.mem_write(mem_write),
			.mem_halfword(mem_halfword),
			.mem_read(mem_read),
			.mem_ex_sel(mem_ex_sel),
			.alu_op(alu_op),
			.imm(imm),
			.ex_portb_sel(ex_portb_sel),
			.syscall_op(syscall_op),
			.branch_op(branch_op),
			.break_op(break_op));
endmodule
