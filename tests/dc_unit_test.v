`include "./tests/dc_unit_tb.v"
`include "./rtl/dc_unit.v"

module tb; 
	wire [31:0] pc;
	wire [31:0] instruction; 
	wire [ 4:0] rs1;
	wire [ 4:0] rs2;
	wire [ 4:0] rd;
	wire [ 2:0] comparator_op;
	wire reg_write;
	wire mem_write;
	wire mem_byte;
	wire mem_halfword;
	wire mem_read;
	wire mem_ex_sel;
	wire mem_unsigned;
	wire [ 2:0] alu_op;
	wire [31:0] imm;
	wire portb_sel;
	wire porta_sel;
	wire syscall_op;
	wire branch_op;
	wire jump_op;
	wire break_op;

	testbench test(
			.rs1(rs1),
			.rs2(rs2),
			.rd(rd),
			.comparator_op(comparator_op),
			.reg_write(reg_write),
			.mem_write(mem_write),
			.mem_byte(mem_byte),
			.mem_halfword(mem_halfword),
			.mem_read(mem_read),
			.mem_unsigned(mem_unsigned),
			.alu_op(alu_op),
			.imm(imm),
			.portb_sel(portb_sel),
			.porta_sel(porta_sel),
			.syscall_op(syscall_op),
			.branch_op(branch_op),
			.jump_op(jump_op),
			.break_op(break_op),
			.instruction(instruction) ); 

	decoder decode (	
			.instruction(instruction),
			.rs1(rs1),
			.rs2(rs2),
			.rd(rd),
			.comparator_op(comparator_op),
			.reg_write(reg_write),
			.mem_write(mem_write),
			.mem_byte(mem_byte),
			.mem_halfword(mem_halfword),
			.mem_read(mem_read),
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
