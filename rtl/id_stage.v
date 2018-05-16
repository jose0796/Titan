`include "rtl/mux21.v"
`include "rtl/dc_unit.v"
`include "rtl/def.v"
`include "rtl/reg_file.v"

module id_stage(
		 input clk,
		 input rst,
		 input 	[31:0] pc,
		 input 	[31:0] pc_add4,
		 input 	[31:0] instruction,
		 input 	exc_address_if,
		 input  [31:0] wb_data,
		 input  [ 4:0] wb_address,
		 input  wb_we,
		 output [31:0] pc_branch_address,
		 output [31:0] pc_jump_address,
		 output [31:0] port_a,
		 output [31:0] port_b,
		 output [ 2:0] alu_op,
		 output [ 4:0] waddr,
		 output [31:0] wdata,
		 output we,
		 output mem_write,
		 output mem_read,
		 output mem_byte,
		 output mem_halfword,
		 output jump_op,
		 output branch_op,
		 output break_op,
		 output syscall_op,
		 output mem_unsigned );
		
	wire [ 4:0] rs1;
	wire [ 4:0] rs2;
	wire [ 4:0] rd;
	wire [31:0] drs1;
	wire [31:0] drs2;
	wire [31:0] drd;
	wire we;
	wire [ 2:0] comparator_op;
	wire [31:0] immediate;
	wire [31:0] imm;
	wire [31:0] _imm; 
	wire portb_sel;
	wire porta_sel;
	wire jalr_op;

	assign _imm 		 = (jalr_op)? ((imm << 1) + drs1) : (imm<<1);
	assign pc_jump_address 	 = {_imm[31:1], 1'b0}; 
	assign pc_branch_address = _imm + pc_add4; 



	mux2_1 PORT_A_MUX (
			.in_0(pc_add4),
			.in_1(drs1),
			.sel(porta_sel),
			.out(port_a) ); 

	mux2_1 PORT_B_MUX (
			.in_0(immediate),
			.in_1(drs2),
			.sel(portb_sel),
			.out(port_b) ); 


	register_file RF  (
			.clk(clk),
			.raddr_rs1(rs1),
			.raddr_rs2(rs2),
			.waddr_rd(wb_address),
			.wdata_rd(wb_data),
			.we(wb_we),
			.rdata_rs1(drs1),
			.rdata_rs2(drs2) );

	decoder      DCU  (	
			.instruction(instruction),
			.rs1(rs1),
			.rs2(rs2),
			.reg_write(we),
			.comparator_op(comparator_op),
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
			.jalr_op(jalr_op),
			.break_op(break_op));

endmodule







