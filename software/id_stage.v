//`include "software/mux21.v"
//`include "software/dc_unit.v"
//`include "software/def.v"
//`include "software/reg_file.v"
//`include "software/comparator.v"
//`include "software/idex_register.v"

module id_stage(
		 input clk_i,
		 input rst_i,
		 input 	[31:0] 	pc,
		 input 	[31:0] 	pc_add4,
		 input 	[31:0] 	instruction,
		 input 		exc_address_if,
		 input  [31:0] 	wb_data,
		 input  [ 4:0] 	wb_address,
		 input  	wb_we,
		 input  	mem_stall,
		 input  [31:0] 	forwardA,
		 input  [31:0] 	forwardB, 
		 input         	forward_sel,	
		 input 		id_ready,
		 output [31:0] 	pc_branch_address,
		 output [31:0] 	pc_jump_address,
		 output [31:0] 	ex_port_a,
		 output [31:0] 	ex_port_b,
		 output [ 3:0] 	ex_alu_op,
		 output [ 4:0] 	ex_waddr,
		 output 	ex_we,	
		 output [ 5:0] 	ex_mem_flags,
		 output 	ex_mem_ex_sel,
		 output 	ex_jump_op,
		 output 	ex_bad_jump_addr,
		 output 	ex_branch_op,
		 output 	ex_bad_branch_addr, 
		 output 	take_branch,
		 output 	ex_break_op,
		 output 	ex_syscall_op,
	 	 output [2:0] 	ex_csr_op,
		 output 	ex_csr_imm_op,
		 output [11:0]  ex_csr_addr,
		 output 	ex_exc_addr_if,
		 output 	ex_ready );

 	wire [31:0] 	muxa_i;
        wire [31:0] 	muxb_i;	
	wire [ 4:0] 	rs1;
	wire [ 4:0] 	rs2;
	wire [ 4:0] 	rd;
	wire [31:0] 	drs1;
	wire [31:0] 	drs2;
	wire [31:0]	drd;
	wire 		we;
	wire [ 3:0] 	alu_op;
	wire [ 2:0]	comparator_op;
	wire [31:0] 	immediate;
	wire [31:0] 	imm;
	wire [31:0] 	_imm; 
	wire [4:0] 	waddr;
	wire 		portb_sel;
	wire		porta_sel;
	wire [31:0] 	port_a;
	wire [31:0] 	port_b; 
	wire 		jalr_op;
	wire [5:0] 	mem_flags;
	wire 		mem_ex_sel;
	wire 		jump_op;
	wire 		bad_jump_addr;
	wire 		branch_op;
	wire 		bad_jump_address;
	wire 		take_branch;
	wire 		break_op;
	wire 		syscall_op;
	wire [2:0] 	csr_op;
	wire 		csr_imm_op;

	assign _imm 		   = ((jalr_op)? ($signed(imm << 1) + $signed(drs1)) : (imm<<1));
	assign pc_jump_address 	   = {_imm[31:1], 1'b0}; 
	assign pc_branch_address   = _imm + pc_add4; 
	assign bad_jump_addr       = (jump_op)?(~(pc_jump_address[1:0] == 0)): 1'b0;
	assign bad_branch_addr	   = (branch_op)?(~(pc_branch_address[1:0] == 0)):1'b0;
	assign ex_stall	   = 1'b0;

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
			.clk(clk_i),
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
	
	idex_reg ID_EX (
			.clk(clk_i),
			.rst(rst_i),
			.stall(ex_stall),
			.id_alu_op(alu_op),
			.id_porta(port_a),
			.id_portb(port_b),
			.id_we(we),
			.id_mem_flags(mem_flags),
			.id_mem_ex_sel(mem_ex_sel),
			.id_bad_jump_addr(bad_jump_addr),
			.id_bad_branch_addr(bad_branch_addr),
			.id_break_op(break_op),
			.id_syscall_op(syscall_op),
			.id_csr_op(csr_op),
			.id_csr_imm_op(csr_imm_op),
			.id_csr_addr(csr_addr),
			.id_waddr(waddr),
			.id_exc_addr_if(exc_address_if),
			.id_ready(id_ready),
			//OUTPUTS
			.ex_porta(ex_port_a),
			.ex_portb(ex_port_b),
			.ex_alu_op(ex_alu_op),
			.ex_we(ex_we),
			.ex_mem_flags(ex_mem_flags),
			.ex_mem_ex_sel(ex_mem_ex_sel),
			.ex_bad_jump_addr(ex_bad_jump_addr),
			.ex_bad_branch_addr(ex_bad_branch_addr),
			.ex_break_op(ex_break_op),
			.ex_syscall_op(ex_syscall_op),
			.ex_csr_op(ex_csr_op),
			.ex_csr_imm_op(ex_csr_imm_op),
			.ex_csr_addr(ex_csr_addr),
			.ex_waddr(ex_waddr),
	       		.ex_exc_addr_if(ex_exc_address_if),
			.ex_ready(ex_ready));



endmodule







