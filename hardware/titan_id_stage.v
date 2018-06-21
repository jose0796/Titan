//`include "./dc_unit.v"
//`include "./mux21.v"
//`include "./mux41.v"
//`include "./def.v"
//`include "./reg_file.v"
//`include "./comparator.v"
//`include "./idex_register.v"

module titan_id_stage(
		 input 		clk_i,
		 input 		rst_i,
		 input  	id_stall_i,
		 input 		id_flush_i,
		 input 	[31:0] 	id_pc_i,
		 input 	[31:0] 	id_instruction_i,
		 input 		id_exc_address_if_i,
		 input 		id_bus_access_fault_i,
		 input  [31:0] 	wb_data_i,
		 input  [ 4:0] 	wb_address_i,
		 input  	wb_we_i,
		 input  [31:0] 	ex_fwd_drd_i,
		 input  [31:0] 	mem_fwd_drd_i,
		 input 	[31:0]  wb_fwd_drd_i,
		 input  [ 1:0]  forward_a_sel_i,
		 input 	[ 1:0]	forward_b_sel_i,	
		 output [ 4:0]	id_rs1_o,
		 output [ 4:0]	id_rs2_o, 
		 output [31:0] 	pc_branch_address_o,
		 output [31:0] 	pc_jump_address_o,
		 output 	take_branch_o,
		 output 	take_jump_o,
		 output [31:0]	ex_pc_o,
		 output [31:0]	ex_instruction_o,
		 output [31:0] 	ex_port_a_o,
		 output [31:0] 	ex_port_b_o,
		 output [ 3:0] 	ex_alu_op_o,
		 output [ 4:0] 	ex_waddr_o,
		 output 	ex_we_o,	
		 output [ 5:0] 	ex_mem_flags_o,
		 output 	ex_mem_ex_sel_o,
		 output 	ex_bad_jump_addr_o,
		 output 	ex_bad_branch_addr_o, 
		 output 	ex_break_op_o,
		 output 	ex_syscall_op_o,
		 output	[31:0]	ex_csr_data_o,
		 output [2:0] 	ex_csr_op_o,
		 output [11:0]  ex_csr_addr_o,
		 output 	ex_exc_addr_if_o,
		 output 	ex_bus_access_fault_o
		 );

	wire [31:0] 	muxa_i;
	wire [31:0] 	muxb_i;	
	wire [ 4:0] 	rs1;
	wire [ 4:0] 	rs2;
	wire [31:0] 	drs1;
	wire [31:0] 	drs2;
	wire 		we;
	wire [ 3:0] 	alu_op;
	wire [ 2:0]	comparator_op;
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
	wire [31:0]	pc_jump;
	wire 		bad_jump_addr;
	wire 		branch_op;
	wire 		bad_branch_addr;
	wire 		take_branch;
	wire 		break_op;
	wire 		syscall_op;
	wire [31:0]	csr_data;
	wire [11:0]	csr_addr;
	wire [2:0] 	csr_op;
	wire 		csr_imm_op;

	assign take_branch_o		= (branch_op)? take_branch: 1'b0;
	assign take_jump_o		= jump_op;
	assign id_rs1_o 		= rs1;
	assign id_rs2_o			= rs2;
	assign _imm 		   	= ((jalr_op)? ($signed(imm << 1) + $signed(drs1)) : (imm<<1));
	assign pc_jump			=  id_pc_i  + _imm;
	assign pc_jump_address_o 	= {pc_jump[31:1], 1'b0}; 
	assign pc_branch_address_o   	= _imm + id_pc_i; 
	assign bad_jump_addr       	= (jump_op)?(~(pc_jump_address_o[1:0] == 0)): 1'b0;
	assign bad_branch_addr		= (branch_op)?(~(pc_branch_address_o[1:0] == 0)):1'b0;
	assign csr_data			= (csr_imm_op)? port_b : port_a;  

	titan_mux21 PORT_A_MUX (
			.in_0(muxa_i),
			.in_1(id_pc_i),
			.sel(porta_sel),
			.out(port_a) );
		
	titan_mux21 PORT_B_MUX (
			.in_0(muxb_i),
			.in_1(imm),
			.sel(portb_sel),
			.out(port_b) );


	titan_mux41 FORWARD_A_MUX (
			.in_0(drs1),
			.in_1(ex_fwd_drd_i),
			.in_2(mem_fwd_drd_i),
			.in_3(wb_fwd_drd_i),
			.sel(forward_a_sel_i),
			.out(muxa_i) ); 

	titan_mux41 FORWARD_B_MUX (
			.in_0(drs2),
			.in_1(ex_fwd_drd_i),
			.in_2(mem_fwd_drd_i),
			.in_3(wb_fwd_drd_i),
			.sel(forward_b_sel_i),
			.out(muxb_i) ); 
	
	titan_comparator BP (
			.sel(comparator_op),
			.drs1(muxa_i),
			.drs2(muxb_i),
			.take_branch(take_branch));

	titan_reg_file RF  (
			.clk(clk_i),
			.raddr_rs1(rs1),
			.raddr_rs2(rs2),
			.waddr_rd(wb_address_i),
			.wdata_rd(wb_data_i),
			.we(wb_we_i),
			.rdata_rs1(drs1),
			.rdata_rs2(drs2) );

	titan_dc_unit    DCU  (	
			.instruction(id_instruction_i),
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
		        .csr_addr(csr_addr),	
			.csr_op(csr_op),
			.csr_imm_op(csr_imm_op));
	
	titan_idex_register ID_EX (
			.clk(clk_i),
			.rst(rst_i),
			.stall(id_stall_i),
			.flush(id_flush_i),
			.id_pc(id_pc_i),
			.id_instruction(id_instruction_i),
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
			.id_csr_data(csr_data),
			.id_csr_op(csr_op),
			.id_csr_addr(csr_addr),
			.id_waddr(waddr),
			.id_exc_addr_if(id_exc_address_if_i),
			.id_bus_access_fault(id_bus_access_fault_i),
			//OUTPUTS
			.ex_pc(ex_pc_o),
			.ex_instruction(ex_instruction_o),
			.ex_porta(ex_port_a_o),
			.ex_portb(ex_port_b_o),
			.ex_alu_op(ex_alu_op_o),
			.ex_we(ex_we_o),
			.ex_mem_flags(ex_mem_flags_o),
			.ex_mem_ex_sel(ex_mem_ex_sel_o),
			.ex_bad_jump_addr(ex_bad_jump_addr_o),
			.ex_bad_branch_addr(ex_bad_branch_addr_o),
			.ex_break_op(ex_break_op_o),
			.ex_syscall_op(ex_syscall_op_o),
			.ex_csr_data(ex_csr_data_o),
			.ex_csr_op(ex_csr_op_o),
			.ex_csr_addr(ex_csr_addr_o),
			.ex_waddr(ex_waddr_o),
	       		.ex_exc_addr_if(ex_exc_addr_if_o),
			.ex_bus_access_fault(ex_bus_access_fault_o)
		);



endmodule







