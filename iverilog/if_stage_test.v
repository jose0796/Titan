`timescale 1ns/1ps
`include "software/if_stage.v"
`include "tests/if_stage_tb2.v"

module tb;

	wire rst;
        wire if_stall;
	wire [31:0] id_pc;	
	wire [31:0] id_pc_add4;
	wire [31:0] id_instruction;
	wire id_exc_addr;
	wire id_ready;


	if_stage IF(
			.rst_i(rst),
			.id_pc_o(id_pc),
			.id_pc_add4(id_pc_add4),
			.id_instruction_o(id_instruction),
			.exc_addr_o(id_exc_addr),
			.id_ready_o(id_ready_o) ); 

	test	TB(
			.rst(rst),
			.id_pc_i(id_pc),
			.id_instruction_i(id_instruction),
			.exc_addr_i(id_exc_addr),
			.ready_i(id_ready_o) );

endmodule




