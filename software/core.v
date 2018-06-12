

module core(
		input 		clk_i,
		input 		rst_i,
		//INSTRUCTION MEMORY PORT
		input	[31:0]	iwbm_dat_i,
		input		iwbm_err_i,
		input 		iwbm_ack_i,
		output 		iwbm_we_o,
		output 		iwbm_cyc_o,
		output 		iwbm_stb_o,
		output	[ 3:0]	iwbm_sel_o,
	       	output	[31:0]	iwbm_addr_o,
		output	[31:0]	iwbm_dat_o,
		//DATA MEMORY PORT
		input		dwbm_dat_i,
		input		dwbm_err_i,
		input 		dwbm_ack_i,
		output		dwbm_we_o,
		output 		dwbm_cyc_o,
		output 		dwbm_stb_o,
		output	[ 3:0]	dwbm_sel_o,
	       	output	[31:0]	dwbm_addr_o,
		output 	[31:0]	dwbm_dat_o,
		//INTERRUPTIONS
		input 		xint_meip_i,
		input		xint_mtip_i,
		input		xint_msip_i ); 	


	//IF STAGE SIGNALS 
	wire 		if_stall;
	wire 	[31:0]	if_pc_reg; 
	wire 	[31:0]	if_pc_mux; 
	wire 	[31:0]	if_pc_add4; 
	wire 	[ 1:0] 	if_pc_sel;
	wire 		if_exc_addr;

	//ID STAGE SIGNALS 
	//+IN 
	wire 	[31:0]	id_instruction;
	wire	[31:0]	id_pc;
	wire	[31:0]	id_pc_add4;
	wire		id_exc_addr;
	wire 	[31:0]	wb_data;
	wire	[ 4:0]	wb_address;
	wire		wb_we;
	wire		id_stall;
	wire 		id_flush;
	wire 	[31:0]	ex_fwd_drd;
	wire 	[31:0]	mem_fwd_drd;
	wire 	[31:0]	wb_fwd_drd;
	wire	[ 1:0]	forward_a_sel;
	wire 	[ 1:0]	forward_b_sel;
	//+OUT	
	wire 	[31:0]	pc_jump_addr; 
	wire 	[31:0]	pc_branch_addr;
       	wire 		take_branch;
	wire 	[31:0]	ex_port_a;
	wire 	[31:0]	ex_port_b;
	wire	[ 3:0]	ex_alu_op;
	wire	[ 4:0]	ex_waddr;
	wire 		ex_we;
	wire 	[ 5:0]	ex_mem_flags;
	wire 		ex_mem_ex_sel;
	wire 		ex_bad_jump_addr;
	wire		ex_bad_branch_addr;
	wire		ex_break_op;
	wire		ex_syscall_op;
	wire	[ 2:0]	ex_csr_op;
	wire		ex_csr_imm_op;
	wire	[11:0]	ex_csr_addr;
	wire		ex_exc_addr_if;

	//EX STAGE 	
	//+IN
	wire 		ex_stall;
	//+OUT
	wire	[31:0]	mem_result;
	wire	[ 4:0]	mem_waddr;
	wire		mem_we;
	wire	[ 5:0]	mem_mem_flags;
	wire		mem_mem_ex_sel;
	wire	[ 2:0]	mem_csr_op;
	wire	[11:0]	mem_csr_addr;
	wire 		mem_csr_imm_op;
	wire 		mem_exc_addr_if;


	if_stage IF (
			.clk_i(clk_i),
			.rst_i(rst_i),
			.if_stall(if_stall),
			.pc_branch_address(pc_branch_addr),
			.pc_jump_address(pc_jump_address),
			.if_pc_sel(if_pc_sel),
			.if_exc_addr_i(if_exc_addr),
			.id_instruction_o(id_instruction),
			.id_pc_o(id_pc),
			.id_pc_add4_o(id_pc_add4),
			.id_exc_addr_o(id_exc_addr) ); 

	id_stag ID (
			.clk_i(clk_i),
			.rst_i(rst_i),
			.id_pc_i(id_pc),
			.id_pc_add4_i(id_pc_add4),
			.id_exc_address_if_i(id_exc_addr_i),
			.wb_data_i(wb_data),
			.wb_address_i(wb_address),
			.wb_we_i(wb_we_i),
			.id_stall_i(id_stall),
			.id_flush_i(id_flush),
			.ex_fwd_drd_i(ex_fwd_drd),
			.mem_fwd_drd_i(ex_fwd_drd),
			.wb_fwd_drd_i(wb_fwd_drd),
			.forward_a_sel_i(forward_a_sel),
			.forward_b_sel_i(forward_b_sel),
			.pc_branch_address_o(pc_branch_addr),
			.pc_jump_address_o(pc_jump_addr),
			.take_branch(take_branch),
			.ex_port_a_o(ex_port_a),
			.ex_port_b_o(ex_port_b),
			.ex_alu_op_o(ex_alu_op),
			.ex_waddr_o(ex_waddr),
			.ex_we_o(ex_we),
			.ex_mem_flags_o(ex_mem_flags),
			.ex_mem_ex_sel_o(ex_mem_ex_sel),
			.ex_bad_jump_addr_o(ex_bad_jump_addr),
			.ex_bad_branch_addr_o(ex_bad_branch_addr),
			.ex_break_op_o(ex_break_op),
			.ex_syscall_op_o(ex_syscall_op),
			.ex_csr_op_o(ex_csr_op),
			.ex_csr_imm_op_o(ex_csr_imm_op),
			.ex_csr_addr_o(ex_csr_addr),
			.ex_exc_addr_if_o(ex_exc_addr_if) 	); 

	ex_stage EX (
			.clk_i(clk_i),
			.rst_i(rst_i),
			.ex_stall_i(ex_stall),
			.ex_port_a_i(ex_port_a),
			.ex_port_b_i(ex_port_b),
			.ex_alu_op_i(ex_alu_op),
			.ex_waddr_i(ex_waddr),
			.ex_we_i(ex_we),
			.ex_mem_flags_i(ex_mem_flags),
			.ex_mem_ex_sel_i(ex_mem_ex_sel),
			.ex_csr_addr_i(ex_csr_addr),
			.ex_csr_op_i(ex_csr_op),
			.ex_csr_imm_op_i(ex_csr_imm_op),
			.ex_exc_addr_if_i(ex_exc_addr_if),
			.ex_fwd_dat_o(ex_fwd_drd),
			.mem_result_o(mem_result),
			.mem_waddr_o(mem_waddr),
			.mem_we_o(mem_we),
			.mem_mem_flags_o(mem_mem_flags),
			.mem_mem_ex_sel_o(mem_mem_ex_sel),
			.mem_csr_op_o(mem_csr_op),
			.mem_csr_addr_o(mem_csr_addr),
			.mem_csr_imm_op_o(mem_csr_imm_op),
			.mem_exc_addr_if_o(mem_exc_addr_if) );

