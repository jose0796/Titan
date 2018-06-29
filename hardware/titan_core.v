
//`include "./if_stage.v"
//`include "./id_stage.v"
	//`include "./ex_stage.v"
	//`include "./mem_stage.v"
	//`include "./lsu.v"
	//`include "./forwarding_unit.v"
	//`include "./control_unit.v"

	`timescale 1 ns / 1 ps


	module titan_core #(
			parameter [31:0] HART_ID = 0,
			parameter [31:0] RESET_ADDR = 32'h0000_0000,
			parameter [0:0]  ENABLE_COUNTERS = 1,
			parameter [0:0]	 ENABLE_M_ISA = 0,
			parameter 	 UCONTROL = "ucontrol.list" 
			)(
			input 		clk_i,
			input 		rst_i,
			//INSTRUCTION MEMORY PORT
			output	[31:0]	iwbm_addr_o,
			output 		iwbm_cyc_o,
			output 		iwbm_stb_o,
			input	[31:0]	iwbm_dat_i,
			input		iwbm_err_i,
			input 		iwbm_ack_i,
			//DATA MEMORY PORT
			input	[31:0]	dwbm_dat_i,
			input		dwbm_err_i,
			input 		dwbm_ack_i,
			output	[31:0]	dwbm_addr_o,
			output 		dwbm_cyc_o,
			output 		dwbm_stb_o,
			output 	[31:0]	dwbm_dat_o,
			output		dwbm_we_o,
			output	[ 3:0]	dwbm_sel_o,
			//INTERRUPTIONS
			/*verilator lint_off UNUSED */
			input 		xint_meip_i,
			input		xint_mtip_i,
			input		xint_msip_i 
			/*verilator lint_on UNUSED */
		); 	


		//IF STAGE SIGNALS 
		wire 		if_stall;
		wire 		if_flush;
		wire 	[31:0]	if_pc; 
		wire 	[ 1:0] 	if_pc_sel;
		wire 	[31:0]	if_instruction;
		

		//ID STAGE SIGNALS 
		//+IN 
		wire 	[31:0]	id_instruction;
		wire	[31:0]	id_pc;
		wire	[ 4:0]	wb_waddr;
		wire		wb_we;
		wire		id_stall;
		wire 		id_flush;
		wire 	[31:0]	ex_fwd_drd;
		wire 	[31:0]	mem_fwd_drd;
		wire	[ 1:0]	forward_a_sel;
		wire 	[ 1:0]	forward_b_sel;
		wire 		id_inst_addr_misaligned;
		wire 		id_inst_access_fault;
	
		//+OUT
		wire 	[ 4:0]	id_rs1;
		wire 	[ 4:0]	id_rs2;
		wire 		id_syscall_op;
		wire 		id_break_op;
		wire 	[ 4:0]	ex_rs1;	
		wire 	[31:0]	pc_jump_addr; 
		wire 	[31:0]	pc_branch_addr;
		wire 		take_branch;
		wire 		take_jump;
		wire 	[31:0]	ex_pc;
		wire 	[31:0]	ex_instruction;
		wire 	[31:0]	ex_port_a;
		wire 	[31:0]	ex_port_b;
		wire	[ 3:0]	ex_alu_op;
		wire	[ 4:0]	ex_waddr;
		wire 		ex_we;
		wire 	[ 5:0]	ex_mem_flags;
		wire 		ex_mem_ex_sel;
		wire		ex_break_op;
		wire		ex_syscall_op;
		wire	[ 2:0]	ex_csr_op;
		wire 	[31:0]	ex_csr_data;
		wire	[11:0]	ex_csr_addr;

		//EX STAGE 	
		//+IN
		wire 		ex_stall;
		wire 		ex_flush;
		wire 		ex_fence_op;
		wire 		ex_xret_op;
		wire 		ex_inst_addr_misaligned;
		wire 		ex_inst_access_fault;
		wire 		ex_illegal_inst;
		wire 	[31:0]	ex_store_data;

		//+OUT
		wire 	[31:0]	mem_pc;
		wire 	[31:0]	mem_instruction;
		wire	[31:0]	mem_result;
		wire	[ 4:0]	mem_waddr;
		wire 	[ 4:0]	mem_rs1;
		wire		mem_we;
		wire	[ 5:0]	mem_mem_flags;
		wire		mem_mem_ex_sel;
		wire 	[31:0]	mem_csr_data;
		wire	[ 2:0]	mem_csr_op;
		wire	[11:0]	mem_csr_addr;
		wire 		mem_break_op;
		wire 		mem_syscall_op;

		//LSU
		wire 		mwrite; 
		wire 		mread;
		wire 		mword;
		wire 		mhw;
		wire 		mbyte;
		wire 		munsigned;

		//MEM STAGE 
		//+IN 
		wire 		mem_stall;
		wire 		mem_flush; 
		wire 	[31:0]	mem_store_data;
		wire 	[31:0]	mem_load_data;
		wire 		mem_fence_op;
		wire 		mem_xret_op;
		wire 		mem_inst_addr_misaligned;
		wire 		mem_inst_access_fault;
		wire 		mem_illegal_inst;
	
		//+OUT
		
		/* verilator lint_off UNUSED */ 
		wire 		wb_stall;
		wire 		wb_flush;
		wire 	[31:0]	wb_result_mem;
		wire 	[31:0]	wb_pc;
		wire 	[31:0]	wb_instruction;
		wire 	[31:0]	wb_result;
		wire 	[ 4:0]	wb_rs1;
		wire 	[31:0]	wb_csr_data;
		wire 	[11:0]	wb_csr_addr;
		wire 	[ 2:0]	wb_csr_op;
		wire 		wb_break_op;
		wire 		wb_syscall_op;
		/* verilator lint_off UNDRIVEN */ 
		wire 		wb_fence_op;
		wire 		wb_xret_op;
		wire 		wb_inst_addr_misaligned;
		wire 		wb_inst_access_fault;
		wire 		wb_illegal_inst;
		wire 		wb_load_addr_misaligned;
		wire 		wb_store_addr_misaligned;
		wire 		wb_load_access_fault;
		wire 		wb_store_access_fault;
		wire 		csr_dependence; 
		wire 		ld_dependence;

		//control signals
		wire		jump_flush_req;
		wire 		branch_flush_req;
		wire		if_stall_req;
		wire 		mem_stall_req;
		wire 		fwd_stall_req;
		wire 		ex_nop;
		wire 		if_kill;
		wire 		illegal_stall_req;

		wire 	hazard; 
		wire	en_fwd;
		wire 	csr_stall_req;
		wire 	ld_stall_req;
		wire 	xcall_break_stall_req;

		//CSR signals 
		//
		wire 	[31:0]	exception_pc;
		wire 		exception_stall_req;
		wire 		exception_sel_flag;
		wire 	[31:0]	csr_data_o;	

		assign branch_flush_req = take_branch;
		assign jump_flush_req 	= take_jump;
		assign fwd_stall_req  	= ld_dependence; 

		titan_if_stage #(
				.RESET_ADDR(RESET_ADDR[31:0])		
				) IF (
				//INPUTS
				.clk_i(clk_i),
				.rst_i(rst_i),
				// CONTROL => IF
				.if_stall(if_stall & ~if_kill),
				.if_flush(if_flush),
				.id_stall(id_stall),
				.id_flush(id_flush),
				.if_pc_sel_i(if_pc_sel),
				//----------------------------------
				// LSU => IF
				.if_instruction_i(if_instruction),
				//----------------------------------	
				// ID => IF
				.pc_branch_address_i(pc_branch_addr),
				.pc_jump_address_i(pc_jump_addr),
				.exception_pc_i(exception_pc),
				.if_inst_access_fault_i(iwbm_err_i), 
				//----------------------------------
				//----------------------------------
				//OUTPUT IF => ID
				.if_pc_o(if_pc),
				.id_pc_o(id_pc),
				.id_instruction_o(id_instruction),
				.id_inst_addr_misaligned_o(id_inst_addr_misaligned),
				.id_inst_access_fault_o(id_inst_access_fault)
				//----------------------------------
				); 

		titan_id_stage ID (
				//INPUTS 
				.clk_i(clk_i),
				.rst_i(rst_i),
				// ID <= CONTROL
				.ex_stall_i(ex_stall),
				.ex_flush_i(ex_flush | ex_nop),
				//--------------------------------------
				// ID <= IF
				.id_pc_i(id_pc),
				.id_instruction_i(id_instruction),
				.id_inst_addr_misaligned_i(id_inst_addr_misaligned),
				.id_inst_access_fault_i(id_inst_access_fault),
				//---------------------------------------
				//ID <= WB
				.wb_data_i(wb_result),		
				.wb_address_i(wb_waddr),	
				.wb_we_i(wb_we),		
				//---------------------------------------
				// FORWARDING STAGE => ID
				.ex_fwd_drd_i(ex_fwd_drd),	//ID <= EX
				.mem_fwd_drd_i(mem_fwd_drd),	//ID <= MEM
				.wb_fwd_drd_i(wb_result),	//ID <= WB
				.forward_a_sel_i(forward_a_sel),//ID <= FORWARD_UNIT
				.forward_b_sel_i(forward_b_sel),//ID <= FORWARD_UNIT
				//---------------------------------------
				// ID => FORWARDING UNIT
				.id_rs1_o(id_rs1),
				.id_rs2_o(id_rs2),
				//---------------------------------------
				// ID => IF & CONTROL (JUMPS)
				.pc_branch_address_o(pc_branch_addr),
				.pc_jump_address_o(pc_jump_addr),    
				.take_branch_o(take_branch),	     
				.take_jump_o(take_jump),
				.id_syscall_op_o(id_syscall_op),
				.id_break_op_o(id_break_op),
				//---------------------------------------
				//---------------------------------------
				// OUTPUTS
				.ex_pc_o(ex_pc),
				.ex_instruction_o(ex_instruction),
				.ex_port_a_o(ex_port_a),
				.ex_port_b_o(ex_port_b),
				.ex_alu_op_o(ex_alu_op),
				.ex_rs1_o(ex_rs1),
				.ex_store_data_o(ex_store_data),
				.ex_waddr_o(ex_waddr),
				.ex_we_o(ex_we),
				.ex_mem_flags_o(ex_mem_flags),
				.ex_mem_ex_sel_o(ex_mem_ex_sel),
				//EXCEPTIONS SIGNALS
				.ex_illegal_inst_o(ex_illegal_inst),
				.ex_inst_addr_misaligned_o(ex_inst_addr_misaligned),
				.ex_inst_access_fault_o(ex_inst_access_fault),
				.ex_fence_op_o(ex_fence_op),
				.ex_xret_op_o(ex_xret_op),
				.ex_break_op_o(ex_break_op),
				.ex_syscall_op_o(ex_syscall_op),
				//CSR SIGNALS
				.ex_csr_data_o(ex_csr_data),
				.ex_csr_op_o(ex_csr_op),
				.ex_csr_addr_o(ex_csr_addr)
				//---------------------------------------
				); 

		titan_ex_stage EX (
				//INPUTS 
				.clk_i(clk_i),
				.rst_i(rst_i),
				// CONTROL => ID 
				.mem_stall_i(mem_stall),
				.mem_flush_i(mem_flush),
				// ID => EX
				.ex_pc_i(ex_pc),
				.ex_instruction_i(ex_instruction),
				.ex_port_a_i(ex_port_a),
				.ex_port_b_i(ex_port_b),
				.ex_alu_op_i(ex_alu_op),
				.ex_store_data_i(ex_store_data),
				.ex_waddr_i(ex_waddr),
				.ex_rs1_i(ex_rs1),
				.ex_we_i(ex_we),
				.ex_mem_flags_i(ex_mem_flags),
				.ex_mem_ex_sel_i(ex_mem_ex_sel),
				.ex_illegal_inst_i(ex_illegal_inst),
				.ex_inst_addr_misaligned_i(ex_inst_addr_misaligned),
				.ex_inst_access_fault_i(ex_inst_access_fault),
				.ex_fence_op_i(ex_fence_op),
				.ex_xret_op_i(ex_xret_op),
				.ex_break_op_i(ex_break_op),
				.ex_syscall_op_i(ex_syscall_op),
				.ex_csr_addr_i(ex_csr_addr),
				.ex_csr_data_i(ex_csr_data),
				.ex_csr_op_i(ex_csr_op),
				//OUTPUTS
				.ex_fwd_dat_o(ex_fwd_drd),		// EX => FWD
				.mem_pc_o(mem_pc),
				.mem_instruction_o(mem_instruction),	
				.mem_store_data_o(mem_store_data), 	//from port B of ALU
				.mem_result_o(mem_result),		//RESULT from ALU
				.mem_waddr_o(mem_waddr),
				.mem_rs1_o(mem_rs1),
				.mem_we_o(mem_we),
				.mem_mem_flags_o(mem_mem_flags),
				.mem_mem_ex_sel_o(mem_mem_ex_sel),
				//EXCEPTIONS
				.mem_illegal_inst_o(mem_illegal_inst),
				.mem_inst_addr_misaligned_o(mem_inst_addr_misaligned),
				.mem_inst_access_fault_o(mem_inst_access_fault),
				.mem_fence_op_o(mem_fence_op),
				.mem_xret_op_o(mem_xret_op),
				.mem_break_op_o(mem_break_op),
				.mem_syscall_op_o(mem_syscall_op),
				//CSR signals
				.mem_csr_data_o(mem_csr_data),
				.mem_csr_op_o(mem_csr_op),
				.mem_csr_addr_o(mem_csr_addr)
			);


		titan_mem_stage MEM (
				//INPUTS 
				.clk_i(clk_i),
				.rst_i(rst_i),
				//CONTROL => MEM
				.wb_stall(wb_stall),
				.wb_flush(wb_flush),
				//-----------------------------------------
				//MEM => FORWARDING UNIT
				.forward_mem_dat_o(mem_fwd_drd),
				//-----------------------------------------
				//LSU => MEM
				.mem_err_i(dwbm_err_i),
				.mem_mread_o(mread),
				.mem_mwrite_o(mwrite),
				.mem_mbyte_o(mbyte),
				.mem_mhw_o(mhw),
				.mem_mword_o(mword),
				.mem_munsigned_o(munsigned),
				.mem_data_i(mem_load_data),
				//-----------------------------------------
				// EX => MEM
				.mem_pc_i(mem_pc),
				.mem_instruction_i(mem_instruction),
				.mem_result_i(mem_result),
				.mem_waddr_i(mem_waddr),
				.mem_rs1_i(mem_rs1),
				.mem_we_i(mem_we),
				.mem_mem_flags_i(mem_mem_flags),
				.mem_mem_ex_sel_i(mem_mem_ex_sel),
				//CSR signals
				.mem_csr_data_i(mem_csr_data),
				.mem_csr_addr_i(mem_csr_addr),
				.mem_csr_op_i(mem_csr_op),
				//EXCEPTION signals
				.mem_illegal_inst_i(mem_illegal_inst),
				.mem_inst_addr_misaligned_i(mem_inst_addr_misaligned),
				.mem_inst_access_fault_i(mem_inst_access_fault),
				.mem_fence_op_i(mem_fence_op),
				.mem_xret_op_i(mem_xret_op),
				.mem_break_op_i(mem_break_op),
				.mem_syscall_op_i(mem_syscall_op),
				//----------------------------------------
				// MEM => CONTROL
				//----------------------------------------
				// MEM => WB
				.wb_result_o(wb_result_mem),
				.wb_waddr_o(wb_waddr),
				.wb_we_o(wb_we),
				//----------------------------------------
				// MEM => CSRs 
				.wb_pc_o(wb_pc),
				.wb_instruction_o(wb_instruction),
				.wb_csr_data_o(wb_csr_data),
				.wb_csr_addr_o(wb_csr_addr),
				.wb_csr_op_o(wb_csr_op),
				.wb_rs1_o(wb_rs1),
				// MEM => EXCEPTION UNIT
				.wb_illegal_inst_o(wb_illegal_inst), 
				.wb_inst_addr_misaligned_o(wb_inst_addr_misaligned),
				.wb_inst_access_fault_o(wb_inst_access_fault),
				.wb_load_access_fault_o(wb_load_access_fault),
				.wb_store_access_fault_o(wb_store_access_fault),
				.wb_load_addr_misaligned_o(wb_load_addr_misaligned),
				.wb_store_addr_misaligned_o(wb_store_addr_misaligned),
				.wb_fence_op_o(wb_fence_op),
				.wb_xret_op_o(wb_xret_op),
				.wb_break_op_o(wb_break_op),
				.wb_syscall_op_o(wb_syscall_op)
				/* verilator lint_on UNUSED */
				//---------------------------------------
				); 

		titan_mux21 mux21 (
				   .in_0(wb_result_mem),
				   .in_1(csr_data_o),
				   .sel(~(wb_csr_op == 0)),
				   .out(wb_result)	); 
		
		titan_forwarding_unit FWD (
				// ID => FWDU
				.id_rs1_i(id_rs1), 
				.id_rs2_i(id_rs2),
				.ex_we_i(ex_we),
				.mem_we_i(mem_we),
				.wb_we_i(wb_we),
				// EX => FWDU 
				.ex_rd_i(ex_waddr),
				// MEM => FWU
				.mem_rd_i(mem_waddr),
				// WB  => FWU
				.wb_rd_i(wb_waddr),
				//forward selectors FWDU => ID 
				.enable_fwd_i(en_fwd),
				.fwd_sel_a_o(forward_a_sel),
				.fwd_sel_b_o(forward_b_sel),
				.hazard_o(hazard)
				); 


		titan_lsu LSU (
				.clk_i(clk_i),
				.rst_i(rst_i),
				//INSTRUCTION MEMORY PORT 
				.pc(if_pc),		
				.instruction(if_instruction),
				.ikill_i(if_kill),
				.idat_i(iwbm_dat_i),
				.iack_i(iwbm_ack_i),
				.ierr_i(iwbm_err_i),
				.iaddr_o(iwbm_addr_o),
				.icyc_o(iwbm_cyc_o),
				.istb_o(iwbm_stb_o),
				.istall_o(if_stall_req),
				//DATA PORT INTERFACE 
				.maddr_i(mem_result),
				.mdat_i(mem_store_data),
				.mwrite_i(mwrite),
				.mread_i(mread),
				.mword_i(mword),
				.mhw_i(mhw),
				.mbyte_i(mbyte),
				.munsigned_i(munsigned),
				.dstall_o(mem_stall_req),
				.data_o(mem_load_data),
				//DATA MEMORY PORT 
				.ddat_i(dwbm_dat_i),
				.dack_i(dwbm_ack_i),
				.derr_i(dwbm_err_i),
				.daddr_o(dwbm_addr_o),
				.ddat_o(dwbm_dat_o),
				.dsel_o(dwbm_sel_o),
				.dcyc_o(dwbm_cyc_o),
				.dstb_o(dwbm_stb_o),
				.dwe_o(dwbm_we_o) 		);
	

		titan_hazard_unit HZ (
				.id_illegal_i(id_illegal_inst),
				.ex_illegal_i(ex_illegal_inst),
				.mem_illegal_i(mem_illegal_inst),
				.id_xcall_break_i(id_syscall_op|id_break_op),
				.ex_xcall_break_i(ex_syscall_op|ex_break_op),
				.mem_xcall_break_i(mem_syscall_op|mem_break_op),
				.ex_csr_op_i(|ex_csr_op),
				.mem_csr_op_i(|mem_csr_op),
				.ex_ld_op_i(ex_mem_ex_sel),
				.mem_ld_op_i(mem_mem_ex_sel),
				.hazard_i(hazard),
				.enable_fwd_o(en_fwd),
				.illegal_stall_req_o(illegal_stall_req),
				.csr_stall_req_o(csr_stall_req),
				.ld_stall_req_o(ld_stall_req),
				.xcall_break_stall_req_o(xcall_break_stall_req)); 

		titan_control_unit CU (
				.rst_i(rst_i),
				.if_pc_sel_o(if_pc_sel),
				.if_stall_req_i(if_stall_req),
				.mem_stall_req_i(mem_stall_req),
				.csr_stall_req_i(csr_stall_req),
				.ld_stall_req_i(ld_stall_req),
				.illegal_stall_req_i(illegal_stall_req),
				.xcall_break_stall_req_i(xcall_break_stall_req),
				.branch_flush_req_i(branch_flush_req),
				.jump_flush_req_i(jump_flush_req),
				.exception_stall_req_i(exception_stall_req),
				.if_stall_o(if_stall),
				.id_stall_o(id_stall),
				.ex_stall_o(ex_stall),
				.mem_stall_o(mem_stall),
				.wb_stall_o(wb_stall),
				.if_kill_o(if_kill),
				.if_flush_o(if_flush),
				.id_flush_o(id_flush),
				.ex_flush_o(ex_flush),
				.mem_flush_o(mem_flush),
				.wb_flush_o(wb_flush),
				.ex_nop_o(ex_nop) 		); 

		titan_csr_exception_unit # (	
			
				.ENABLE_COUNTERS(ENABLE_COUNTERS),
				.RESET_ADDR(RESET_ADDR) 	
		) CSR (
				//INPUTS
				.clk_i(clk_i),
				.rst_i(rst_i),
				.csr_addr_i(wb_csr_addr),
				.csr_dat_i(wb_csr_data),
				.csr_op_i(wb_csr_op),
				.csr_rs1_i(wb_rs1),
				.xint_meip_i(xint_meip_i),
				.xint_mtip_i(xint_mtip_i),
				.xint_msip_i(xint_msip_i),
				.exception_pc_i(wb_pc),
				.exception_inst_i(wb_instruction),
				.xcall_i(wb_syscall_op),
				.xbreak_i(wb_break_op),
				.inst_addr_misaligned_i(wb_inst_addr_misaligned),
				.inst_access_fault_i(wb_inst_access_fault),
				.illegal_inst_i(wb_illegal_inst),
				.load_addr_misaligned_i(wb_load_addr_misaligned),
				.load_access_fault_i(wb_load_access_fault),
				.store_addr_misaligned_i(wb_store_addr_misaligned),
				.store_access_fault_i(wb_store_access_fault),
				.inst_fence_i(wb_fence_op),
				.inst_xret_i(wb_xret_op),
				//OUTPUTS
				.exception_stall_req_o(exception_stall_req),
				.exception_pc_o(exception_pc),
				.exception_sel_flag_o(exception_sel_flag),
				.csr_dat_o(csr_data_o)	); 


endmodule
