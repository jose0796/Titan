`include "./tests/id_stage_tb.v"
`include "rtl/id_stage.v"

module tb;

	wire [31:0] pc;
	wire [31:0] pc_add4,;
	wire [31:0] instruction;
	wire [31:0] wb_data;
	wire [31:0] wdata;
	wire [31:0] pc_branch_address;
	wire [31:0] pc_jump_address;
	wire [31:0] port_a;
	wire [31:0] port_b;
	wire [ 4:0] waddr;
        wire [ 4:0] wb_address;
	wire [ 4:0] mem_access;
	wire [ 4:0] alu_op;
        wire [ 2:0] csr_op;
	wire [ 1:0] forward_sel;
	wire mem_ex_sel;
	wire jump_op;
	wire bad_jump_addr;
	wire branch_op;
	wire bad_branch_addr;
	wire break_op;
	wire syscall_op;
	wire mem_unsigned;
	wire csr_imm_op;
	wire we;
	wire wb_we;

	test TEST (
		 .pc_branch_address(pc_branch_address),
		 .pc_jump_address(pc_jump_address),
		 .port_a(port_a),
		 .port_b(port_b),
		 .alu_op(alu_op),
		 .waddr(waddr),
		 .wdata(wdata),
		 .we(we),
		 .mem_access(mem_access),
		 .mem_ex_sel(mem_ex_sel),
		 .jump_op(jump_op),
		 .bad_jump_addr(bad_jump_addr),
		 .branch_op(branch_op),
		 .bad_branch_addr(bad_branch_addr),
		 .break_op(break_op),
		 .syscall_op(syscall_op),
		 .mem_unsigned(mem_unsigned),
		 .csr_op(crs_op),
		 .csr_imm_op(csr_imm_op),
		 .pc(pc),
		 .pc_add4(pc_add4),
		 .instruction(instruction), 
		 .wb_data(wb_data),
		 .wb_address(wb_address),
		 .wb_we(wb_we));
	
   id_stage  ID (
		 .pc_branch_address(pc_branch_address),
		 .pc_jump_address(pc_jump_address),
		 .port_a(port_a),
		 .port_b(port_b),
		 .alu_op(alu_op),
		 .waddr(waddr),
		 .wdata(wdata),
		 .we(we),
		 .mem_access(mem_access),
		 .mem_ex_sel(mem_ex_sel),
		 .jump_op(jump_op),
		 .bad_jump_addr(bad_jump_addr),
		 .branch_op(branch_op),
		 .bad_branch_addr(bad_branch_addr),
		 .break_op(break_op),
		 .syscall_op(syscall_op),
		 .mem_unsigned(mem_unsigned),
		 .csr_op(crs_op),
		 .csr_imm_op(csr_imm_op),
		 .pc(pc),
		 .pc_add4(pc_add4),
		 .instruction(instruction), 
		 .wb_data(wb_data),
		 .wb_address(wb_address),
		 .wb_we(wb_we));
endmodule

