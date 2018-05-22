`include "rtl/mux21.v"
`include "rtl/dc_unit.v"
`include "rtl/def.v"
`include "rtl/reg_file.v"
`include "rtl/comparator.v"
`include "rtl/idex_register.v"

module id_stage(
		 input clk,
		 input 	[31:0] pc,
		 input 	[31:0] pc_add4,
		 input 	[31:0] instruction,
		 input 	exc_address_if,
		 input  [31:0] wb_data,
		 input  [ 4:0] wb_address,
		 input  wb_we,
		 input  mem_stall,
		 input  [31:0] forwardA,
		 input  [31:0] forwardB, 
		 input         forward_sel,	
		 output [31:0] pc_branch_address,
		 output [31:0] pc_jump_address,
		 output [31:0] ex_port_a,
		 output [31:0] ex_port_b,
		 output [ 3:0] ex_alu_op,
		 output [ 4:0] ex_waddr,
		 output ex_we,
		 output [ 5:0] ex_mem_flags,
		 output ex_mem_ex_sel,
		 output ex_jump_op,
		 output ex_bad_jump_addr,
		 output ex_branch_op,
		 output ex_bad_branch_addr, 
		 output take_branch,
		 output ex_break_op,
		 output ex_syscall_op,
	 	 output [2:0] ex_csr_op,
		 output ex_csr_imm_op );

 	wire [31:0] muxa_i;
        wire [31:0] muxb_i;	
	wire [ 4:0] rs1;
	wire [ 4:0] rs2;
	wire [ 4:0] rd;
	wire [31:0] drs1;
	wire [31:0] drs2;
	wire [31:0] drd;
	wire we;
	wire [ 3:0] alu_op;
	wire [ 2:0] comparator_op;
	wire [31:0] immediate;
	wire [31:0] imm;
	wire [31:0] _imm; 
	wire [4:0] waddr;
	wire portb_sel;
	wire porta_sel;
	wire [31:0] port_a;
	wire [31:0] port_b; 
	wire jalr_op;
	wire [5:0] mem_flags;
	wire mem_ex_sel;
	wire jump_op;
	wire bad_jump_addr;
	wire branch_op;
	wire bad_jump_address;
	wire take_branch;
	wire break_op;
	wire syscall_op;
	wire [2:0] csr_op;
	wire csr_imm_op;

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
	
	idex_reg ID_EX (
			.clk(clk),
			.rst(rst),
			.stall(mem_stall),
			.porta_i(port_a),
			.portb_i(port_b),
			.we_i(we),
			.mem_flags_i(mem_flags),
			.mem_ex_sel_i(mem_ex_sel_i),
			.bad_jump_addr_i(bad_jump_addr),
			.bad_branch_addr_i(bad_branch_addr),
			.break_op_i(break_op),
			.syscall_op_i(syscall_op),
			.csr_op_i(csr_op),
			.csr_imm_op_i(csr_imm_op),
			.waddr_i(waddr),
			.exc_addr_if_i(exc_address_if),
			//OUTPUTS
			.porta_o(ex_port_a),
			.portb_o(ex_port_b),
			.we_o(ex_we),
			.mem_flags_o(ex_mem_flags),
			.bad_jump_addr_o(ex_bad_jump_addr),
			.bad_branch_addr_o(ex_bada_branch_addr),
			.break_op_o(ex_break_op),
			.syscall_op_o(ex_syscall_op),
			.csr_op_o(ex_csr_op),
			.csr_imm_op_o(ex_csr_imm_op),
			.waddr_o(ex_waddr),
	       		.exc_addr_if_o(ex_exc_address_if)	);



endmodule







