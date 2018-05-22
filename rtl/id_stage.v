`include "rtl/mux21.v"
`include "rtl/dc_unit.v"
`include "rtl/def.v"
`include "rtl/reg_file.v"
`include "rtl/comparator.v"

module id_stage(
		 input clk,
		 input 	[31:0] pc,
		 input 	[31:0] pc_add4,
		 input 	[31:0] instruction,
		 input 	exc_address_if,
		 input  [31:0] wb_data,
		 input  [ 4:0] wb_address,
		 input  wb_we,
		 input  [31:0] forwardA,
		 input  [31:0] forwardB, 
		 input         forward_sel,	
		 output [31:0] pc_branch_address,
		 output [31:0] pc_jump_address,
		 output [31:0] port_a,
		 output [31:0] port_b,
		 output [ 3:0] alu_op,
		 output [ 4:0] waddr,
		 output we,
		 output [ 5:0] mem_flags,
		 output mem_ex_sel,
		 output jump_op,
		 output bad_jump_addr,
		 output branch_op,
		 output bad_branch_addr, 
		 output take_branch,
		 output break_op,
		 output syscall_op,
	 	 output [2:0] csr_op,
		 output csr_imm_op );

 	wire [31:0] muxa_i;
        wire [31:0] muxb_i;	
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

	assign _imm 		   = (jalr_op)? ($signed(imm << 1) + $signed(drs1)) : (imm<<1);
	assign pc_jump_address 	   = {_imm[31:1], 1'b0}; 
	assign pc_branch_address   = _imm + pc_add4; 
	assign bad_jump_addr       = ~(pc_jump_address[1:0] == 0);
	assign bad_branch_addr	   = ~(pc_branch_address[1:0] == 0);




	mux2_1 PORT_A_MUX (
			.in_0(muxa_i),
			.in_1(pc),
			.sel(porta_sel),
			.out(port_a) );
	
	mux2_1 PORT_B_MUX (
			.in_0(muxb_i),
			.in_1(imm),
			.sel(portb_sel),
			.out(port_b) );



	mux2_1 FORWARD_A_MUX (
			.in_0(drs1),
			.in_1(forwardA),
			.sel(forward_sel),
			.out(muxa_i) ); 

	mux2_1 FORWARD_B_MUX (
			.in_0(drs2),
			.in_1(forwardB),
			.sel(forward_sel),
			.out(muxb_i) ); 
	
	branch_predictor BP (
			.sel(comparator_op),
			.drs1(muxa_i),
			.drs2(muxb_i),
			.take_branch(take_branch));

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
			.rd(waddr),
			.reg_write(we),
			.comparator_op(comparator_op),
			.mem_flags(mem_flags),
			.mem_ex_sel(mem_ex_sel),
			.alu_op(alu_op),
			.imm(imm),
			.portb_sel(portb_sel),
			.porta_sel(porta_sel),
			.syscall_op(syscall_op),
			.branch_op(branch_op),
			.jump_op(jump_op),
			.jalr_op(jalr_op),
			.break_op(break_op), 
			.csr_op(csr_op),
			.csr_imm_op(csr_imm_op));
	

endmodule







