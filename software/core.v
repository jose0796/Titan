

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



	pc_reg PC_REG  (
			.clk_i(clk_i),
			.rst_i(rst_i),
			.stall(if_stall),
			.pc_i(pc_mux),
			


