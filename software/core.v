

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
	wire 		ex_flush; 
	//+OUT
	wire	[31:0]	mem_result;
	wire	[ 4:0]	mem_waddr;
	wire		mem_we;
	wire	[ 5:0]	mem_mem_flags;
	wire		mem_mem_ex_sel;
	wire 	[31:0]	mem_csr_data;
	wire	[ 2:0]	mem_csr_op;
	wire	[11:0]	mem_csr_addr;
	wire 		mem_csr_imm_op;
	wire 		mem_exc_addr_if;

	//MEM STAGE 
	//+IN 
	wire 		mem_stall;
	wire 		mem_flush; 
	//+OUT
	wire 		mem_mread;
	wire 		mem_mwrite;
	wire 		mem_mbyte;
	wire 		mem_mhw;
	wire 		mem_mbword;
	wire 		mem_munsigned;
	wire		mem_mdat;
	wire 		mem_maddr;
	wire 		wb_pc;
	wire 		wb_instruction;
	wire 		wb_result;
	wire 		wb_waddr;
	wire 		wb_we;
	wire 		wb_csr_data;
	wire 		wb_csr_addr;
	wire 		wb_csr_op;
	wire 		wb_csr_imm_op;
	wire 		wb_exc_addr_if;
	wire 		wb_bad_jump_addr;
	wire 		wb_bad_branch_addr;
	wire 		wb_break_op;
	wire 		wb_syscall_op;

	if_stage IF (
			.clk_i(clk_i),
			.rst_i(rst_i),
			.if_stall(if_stall),
			.if_flush(if_flush),
			.pc_branch_address(pc_branch_addr),
			.pc_jump_address(pc_jump_address),
			.if_pc_sel(if_pc_sel),
			.if_exc_addr_i(if_exc_addr),
			.id_instruction_o(id_instruction),
			.id_pc_o(id_pc),
			.id_pc_add4_o(id_pc_add4),
			.id_exc_addr_o(id_exc_addr) ); 

	id_stage ID (
			//INPUTS 
			.clk_i(clk_i),
			.rst_i(rst_i),
			// ID <= CONTROL
			.id_stall_i(id_stall),
			.id_flush_i(id_flush),
			// ID <= IF
			.id_pc_i(id_pc),
			.id_pc_add4_i(id_pc_add4),
			.id_exc_address_if_i(id_exc_addr_i),
			//ID <= WB
			.wb_data_i(wb_data),		
			.wb_address_i(wb_address),	
			.wb_we_i(wb_we_i),		
			// FORWARDING STAGE => ID
			.ex_fwd_drd_i(ex_fwd_drd),	//ID <= EX
			.mem_fwd_drd_i(mem_fwd_drd),	//ID <= MEM
			.wb_fwd_drd_i(wb_fwd_drd),	//ID <= WB
			.forward_a_sel_i(forward_a_sel),//ID <= FORWARD_UNIT
			.forward_b_sel_i(forward_b_sel),//ID <= FORWARD_UNIT
			//---------------------------------------
			// ID => IF & CONTROL (JUMPS)
			.pc_branch_address_o(pc_branch_addr),
			.pc_jump_address_o(pc_jump_addr),    
			.take_branch(take_branch),	     //ID => CONTROL
			// ID => EX
			.ex_pc_o(ex_pc),
			.ex_instruction_o(ex_instruction),
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
			.ex_csr_data_o(ex_csr_data),
			.ex_csr_op_o(ex_csr_op),
			.ex_csr_imm_op_o(ex_csr_imm_op),
			.ex_csr_addr_o(ex_csr_addr),
			.ex_exc_addr_if_o(ex_exc_addr_if) 	); 

	ex_stage EX (
			//INPUTS 
			.clk_i(clk_i),
			.rst_i(rst_i),
			.ex_stall_i(ex_stall),
			.ex_flush_i(ex_flush),
			.ex_pc_i(ex_pc),
			.ex_instruction(ex_instruction),
			.ex_port_a_i(ex_port_a),
			.ex_port_b_i(ex_port_b),
			.ex_alu_op_i(ex_alu_op),
			.ex_waddr_i(ex_waddr),
			.ex_we_i(ex_we),
			.ex_mem_flags_i(ex_mem_flags),
			.ex_mem_ex_sel_i(ex_mem_ex_sel),
			.ex_exc_addr_if_i(ex_exc_addr_if),
			.ex_bad_jump_addr_i(ex_bad_jump_addr),
			.ex_bad_branch_addr_i(ex_bad_branch_addr),
			.ex_break_op_i(ex_break_op),
			.ex_syscall_op_i(ex_syscall_op),
			.ex_csr_addr_i(ex_csr_addr),
			.ex_csr_data_i(ex_csr_data),
			.ex_csr_op_i(ex_csr_op),
			.ex_csr_imm_op_i(ex_csr_imm_op),
			//OUTPUTS
			.mem_pc_o(mem_pc),
			.mem_instruction_o(mem_instruction),
			.ex_fwd_dat_o(ex_fwd_drd),
			.mem_result_o(mem_result),
			.mem_waddr_o(mem_waddr),
			.mem_we_o(mem_we),
			.mem_mem_flags_o(mem_mem_flags),
			.mem_mem_ex_sel_o(mem_mem_ex_sel),
			.mem_bad_jump_addr_o(mem_bad_jump_addr),
			.mem_bad_branch_addr_o(mem_bad_branch_addr),
			.mem_break_op_o(mem_break_op),
			.mem_syscall_op_o(mem_syscall_op),
			.mem_csr_data_o(mem_csr_data),
			.mem_csr_op_o(mem_csr_op),
			.mem_csr_addr_o(mem_csr_addr),
			.mem_csr_imm_op_o(mem_csr_imm_op),
			.mem_exc_addr_if_o(mem_exc_addr_if) );


	mem_stage MEM (
			.clk_i(clk_i),
			.rst_i(rst_i),
			.stall(mem_stall),
			.flush(mem_flush),
			.forward_mem_dat_o(mem_fwd_drd),
			.mem_pc_i(mem_pc),
			.mem_instruction_i(mem_instruction),
			.mem_result_i(mem_result),
			.mem_waddr_i(mem_waddr),
			.mem_we_i(mem_we),
			.mem_mem_flags_i(mem_mem_flags),
			.mem_mem_ex_sel_i(mem_mem_ex_sel),
			.mem_csr_data_i(mem_csr_data),
			.mem_csr_addr_i(mem_csr_addr),
			.mem_csr_op_i(mem_csr_op),
			.mem_csr_imm_op_i(mem_csr_imm),
			.mem_exc_addr_if_i(mem_exc_addr_if),
			.mem_bad_jump_addr_i(mem_bad_jump_addr),
			.mem_bad_branch_addr_i(mem_bad_branch_addr),
			.mem_break_op_i(mem_break_op_i),
			.mem_syscall_op_i(mem_syscall_op_i),
			//LSU SIGNALS
			.mem_data_i(),
			.wb_pc_o(wb_pc),
			.wb_instruction_o(wb_instruction),
			.wb_result_o(wb_result),
			.wb_waddr_o(wb_waddr),
			.wb_we_o(wb_we),
			.wb_csr_data_o(wb_csr_data),
			.wb_csr_addr_o(wb_csr_addr_o),
			.wb_csr_op_o(wb_csr_op),
			.wb_csr_imm_op_o(wb_csr_imm_op),
			.wb_exc_addr_if_o(wb_exc_addr_if),
			.wb_bad_jump_addr_o(wb_bad_jump_addr),
			.wb_bad_branch_addr_o(wb_bad_branch_addr),
			.wb_break_op_o(wb_break_op),
			.wb_syscall_op_o(wb_syscall_op) ); 


