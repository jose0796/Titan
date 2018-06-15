
`include "./if_stage.v"
`include "./id_stage.v"
`include "./ex_stage.v"
`include "./mem_stage.v"
`include "./lsu.v"
`include "./forwarding_unit.v"
`include "./control_unit.v"

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
		input	[31:0]	dwbm_dat_i,
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
	wire 	[31:0]	if_pc; 
	wire 	[31:0]	if_pc_mux; 
	wire 	[31:0]	if_pc_add4; 
	wire 	[ 1:0] 	if_pc_sel;
	wire 		if_exc_addr_if;
	wire 	[31:0]	if_instruction;

	//ID STAGE SIGNALS 
	//+IN 
	wire 	[31:0]	id_instruction;
	wire	[31:0]	id_pc;
	wire	[31:0]	id_pc_add4;
	wire		id_exc_addr_if;
	wire	[ 4:0]	wb_waddr;
	wire		wb_we;
	wire		id_stall;
	wire 		id_flush;
	wire 	[31:0]	ex_fwd_drd;
	wire 	[31:0]	mem_fwd_drd;
	wire 	[31:0]	wb_fwd_drd;
	wire	[ 1:0]	forward_a_sel;
	wire 	[ 1:0]	forward_b_sel;
	//+OUT
	wire 	[ 4:0]	id_rs1;
	wire 	[ 4:0]	id_rs2;	
	wire 	[31:0]	pc_jump_addr; 
	wire 	[31:0]	pc_branch_addr;
       	wire 		take_branch;
	wire 	[31:0]	ex_pc;
	wire 	[31:0]	ex_instruction;
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
	wire 	[31:0]	ex_csr_data;
	wire	[11:0]	ex_csr_addr;
	wire		ex_exc_addr_if;

	//EX STAGE 	
	//+IN
	wire 		ex_stall;
	wire 		ex_flush;	
	//+OUT
	wire 	[31:0]	mem_pc;
	wire 	[31:0]	mem_instruction;
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
	//+OUT
	wire 		mem_mread;
	wire 		mem_mwrite;
	wire 		mem_mbyte;
	wire 		mem_mhw;
	wire 		mem_mbword;
	wire 		mem_munsigned;
	wire	[31:0]	mem_mdat;
	wire 	[31:0]	mem_maddr;
	wire 	[31:0]	wb_pc;
	wire 	[31:0]	wb_instruction;
	wire 	[31:0]	wb_result;
	wire 		csr_sel;
	wire 	[31:0]	wb_csr_data;
	wire 	[11:0]	wb_csr_addr;
	wire 	[ 2:0]	wb_csr_op;
	wire 		wb_csr_imm_op;
	wire 		wb_exc_addr_if;
	wire 		wb_bad_jump_addr;
	wire 		wb_bad_branch_addr;
	wire 		wb_break_op;
	wire 		wb_syscall_op;
	wire 		ld_dependence;
	wire 	[31:0]	csr_rdata;
	wire 	[31:0]	wb_wdata;

	//control signals
	wire		jump_flush_req;
	wire		if_stall_req;
	wire 		mem_stall_req;
	wire 		fwd_stall_req;
	wire 		ex_nop;


	reg		_mem_stall;
	reg 		_if_stall;

	always @(negedge dwbm_ack_i, posedge dwbm_cyc_o) begin
		if (dwbm_cyc_o) begin			
			_mem_stall = 1'b1;
		end else if(dwbm_ack_i) begin
			 _mem_stall = 1'b0;
		end else begin
			_mem_stall = _mem_stall; 
		end
		// control for stalls in MEM STAGE
	end 

	always @(negedge iwbm_ack_i, posedge iwbm_cyc_o) begin
		if (iwbm_cyc_o) begin
			_if_stall = 1'b1;
		end else if(iwbm_ack_i) begin 
			_if_stall = 1'b0;
		end else begin 
			_if_stall = _if_stall;
		end
		// control for stalls in IF STAGE
	end 


	assign jump_flush_req 	= take_branch;
	assign mem_stall_req  	= _mem_stall; 
	assign if_stall_req	= _if_stall;
	assign fwd_stall_req  	= ld_dependence; 
	assign wb_wdata		= (csr_sel)? csr_rdata : wb_result; 

	if_stage IF (
			//INPUTS
			.clk_i(clk_i),
			.rst_i(rst_i),
			// CONTROL => IF
			.if_stall(if_stall),
			.if_flush(if_flush),
			.if_pc_sel_i(if_pc_sel),
			//----------------------------------
			// LSU => IF
			.if_instruction_i(if_instruction),
			//----------------------------------	
			// ID => IF
			.pc_branch_address_i(pc_branch_addr),
			.pc_jump_address_i(pc_jump_addr),
			.if_exc_addr_if_i(if_exc_addr_if),
			//----------------------------------
			//----------------------------------
			//OUTPUT IF => ID
			.if_pc_o(if_pc),
			.id_pc_o(id_pc),
			.id_instruction_o(id_instruction),
			.id_pc_add4_o(id_pc_add4),
			.id_exc_addr_if_o(id_exc_addr_if) 
			//----------------------------------
			); 

	id_stage ID (
			//INPUTS 
			.clk_i(clk_i),
			.rst_i(rst_i),
			// ID <= CONTROL
			.id_stall_i(id_stall),
			.id_flush_i(id_flush),
			//--------------------------------------
			// ID <= IF
			.id_pc_i(id_pc),
			.id_pc_add4_i(id_pc_add4),
			.id_exc_address_if_i(id_exc_addr_i),
			//---------------------------------------
			//ID <= WB
			.wb_data_i(wb_result),		
			.wb_address_i(wb_waddr),	
			.wb_we_i(wb_we),		
			//---------------------------------------
			// FORWARDING STAGE => ID
			.ex_fwd_drd_i(ex_fwd_drd),	//ID <= EX
			.mem_fwd_drd_i(mem_fwd_drd),	//ID <= MEM
			.wb_fwd_drd_i(wb_fwd_drd),	//ID <= WB
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
			.take_branch(take_branch),	     
			//---------------------------------------
			//---------------------------------------
			// OUTPUTS
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
			.ex_csr_addr_o(ex_csr_addr),
			.ex_exc_addr_if_o(ex_exc_addr_if) 	
			//---------------------------------------
			); 

	ex_stage EX (
			//INPUTS 
			.clk_i(clk_i),
			.rst_i(rst_i),
			// CONTROL => ID 
			.ex_stall_i(ex_stall),
			.ex_flush_i(ex_flush | ex_nop),
			// ID => EX
			.ex_pc_i(ex_pc),
			.ex_instruction_i(ex_instruction),
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
			//OUTPUTS
			.mem_pc_o(mem_pc),
			.mem_instruction_o(mem_instruction),	
			.ex_fwd_dat_o(ex_fwd_drd),		// EX => FWD
			.mem_store_data_o(mem_store_data), 	//from port B of ALU
			.mem_result_o(mem_result),		//RESULT from ALU
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
			.mem_exc_addr_if_o(mem_exc_addr_if) );


	mem_stage MEM (
			//INPUTS 
			.clk_i(clk_i),
			.rst_i(rst_i),
			//CONTROL => MEM
			.stall(mem_stall),
			.flush(mem_flush),
			//-----------------------------------------
			//MEM => FORWARDING UNIT
			.forward_mem_dat_o(mem_fwd_drd),
			//-----------------------------------------
			//LSU => MEM
			.mem_cyc_i(dwbm_cyc_i),
			.mem_ack_i(dwbm_ack_i),
			.mem_mread_o(mread),
			.mem_mwrite_o(mwrite),
			.mem_mbyte_o(mbyte),
			.mem_mhw_o(mhw),
			.mem_mword_o(mword),
			.mem_munsigned_o(munsigned),
			.mem_load_data_i(mem_load_data),
			//-----------------------------------------
			// EX => MEM
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
			.mem_exc_addr_if_i(mem_exc_addr_if),
			.mem_bad_jump_addr_i(mem_bad_jump_addr),
			.mem_bad_branch_addr_i(mem_bad_branch_addr),
			.mem_break_op_i(mem_break_op_i),
			.mem_syscall_op_i(mem_syscall_op_i),
			//----------------------------------------
			// MEM => CONTROL
			.mem_request_stall_o(mem_request_stall),
			//----------------------------------------
			// MEM => WB 
			.wb_result_o(wb_result),
			.wb_waddr_o(wb_waddr),
			.wb_we_o(wb_we),
			//----------------------------------------
			// MEM => CSRs 
			.wb_pc_o(wb_pc),
			.wb_instruction_o(wb_instruction),
			.wb_csr_data_o(wb_csr_data),
			.wb_csr_addr_o(wb_csr_addr),
			.wb_csr_op_o(wb_csr_op),
			// MEM => EXCEPTION UNIT 
			.wb_exc_addr_if_o(wb_exc_addr_if),
			.wb_bad_jump_addr_o(wb_bad_jump_addr),
			.wb_bad_branch_addr_o(wb_bad_branch_addr),
			.wb_break_op_o(wb_break_op),
			.wb_syscall_op_o(wb_syscall_op)
	       		//---------------------------------------
			); 
	
	forward_unit FWD (
			// ID => FWDU
			.id_rs1_i(id_rs1), 
			.id_rs2_i(id_rs2),
			.ex_we_i(ex_we),
			.mem_we_i(mem_we),
			.wb_we_i(wb_we_i),
			// EX => FWDU 
			.ls_op_i(ex_mem_ex_sel), //this is to know if it's a memory instruction
			.ex_rd_i(ex_waddr),
			// MEM => FWU
			.mem_rd_i(mem_waddr),
			// WB  => FWU
			.wb_rd_i(wb_waddr),
			//forward selectors FWDU => ID 
			.fwd_sel_a_o(forward_a_sel),
			.fwd_sel_b_o(forward_b_sel),
			.ld_dependence_o(ld_dependence) //for hazard control, you
	       		); 


	load_store_unit LSU (
			.clk_i(clk_i),
			.rst_i(rst_i),
			//INSTRUCTION MEMORY PORT 
			.pc(if_pc),		
			.instruction(if_instruction),
			.idat_i(iwbm_dat_i),
			.iack_i(iwbm_ack_i),
			.ierr_i(iwbm_err_i),
			.iaddr_o(iwbm_addr_o),
			.idat_o(iwbm_dat_o),
			.isel_o(iwbm_sel_o),
			.icyc_o(iwbm_cyc_o),
			.istb_o(iwbm_stb_o),
			.iwe_o(iwbm_we_o),
			//DATA PORT INTERFACE 
			.maddr_i(mem_result),
			.mdat_i(mem_store_data),
			.mwrite_i(mwrite),
			.mread_i(mread),
			.mword_i(mword),
			.mhw_i(mhw),
			.mbyte_i(mbyte),
			.munsigned_i(munsigned),
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
	


	control_unit CU (
			.clk_i(clk_i),
			.rst_i(rst_i),
			.jump_flush_req_i(jump_flush_req),
			.if_stall_req_i(if_stall_req),
			.mem_stall_req_i(mem_stall_req),
			.fwd_stall_req_i(fwd_stall_req),
			.if_stall_o(if_stall),
			.id_stall_o(id_stall),
			.ex_stall_o(ex_stall),
			.mem_stall_o(mem_stall),
			.if_flush_o(if_flush),
			.id_flush_o(id_flush),
			.ex_flush_o(ex_flush),
			.mem_flush_o(mem_flush),
			.ex_nop_o(ex_nop) 		); 
	

endmodule
