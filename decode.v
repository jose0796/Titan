`include "def.v"
module decoder (
		input [31:0] instruction,
		input [31:0] pc, 
	        //IF STATE SIGNALS
		output pc_branch_address,
		//ID STAGE SIGNALS
		output [4:0] rs1, 
		output [4:0] rs2,
		output [4:0] rd,
		output reg_write,
		//MEM STAGE CONTROL SIGNALS
		output mem_write,
		output mem_byte,
		output mem_halfword,
		output mem_read,
		output mem_ex_sel,
		output [31:0] mem_data_st;
		//EX STAGE CONTROL SIGNALS
		output [3:0] alu_op, 	
		output [31:0] imm,
		output [1:0] ex_portb_sel,
		output syscall_op,
		output branch_op,
		output break_op	  ); 
	
		wire regw;	
		wire [6:0] opcode;
		wire rf_we; 
		wire mem_wr;
		wire mem_b;
		wire mem_hw;
		wire mem_r;
		wire mem_ex_s;
		wire [31:0] inst;
		wire [2:0] func3;
		wire [6:0] func7;
		reg  [31:0] _imm;


		//ASSIGNMENTS
		assign inst 	 = instruction[31:0];
		assign opcode 	 = instruction[6:0];
		assign func3 	 = instruction[14:12]; 
		assign func7 	 = instruction[31:25]; 
		//+- EX STAGE ASSIGNMENTS
		assign rs1 	 = instruction[19:15]; 
		assign rs2 	 = instruction[24:20];
		assign rd  	 = instruction[11:7]; 
		assign imm 	 = _imm; 
		//+- MEM STAGE ASSIGMENTS
		assign mem_write = mem_wr;
		assign mem_byte  = mem_b; 
		assign mem_halfword = mem_hw;
		assign mem_read  = mem_r;
		assign mem_ex_sel= mem_ex_s;

		//TYPES OF INSTRUCTIONS
		reg lui, auipc;
		reg jal, jalr; 
		reg beq, bne, blt, bge, bltu, bgeu; 
		reg lb, lh, lw, lbu, lhu;
		reg sb, sh, sw;
		reg addi, slti, sltiu, xori, ori, andi, slli, srli, srai;
		reg add, sub, sll, slt, sltu, _xor, srl, sra, _or, _and;
		reg fence; 
		reg nop;
		reg rw, rs, rc, rwi, rsi, rci;
		reg call, break, ret;
		reg is_b, is_imm, is_st, is_unsigned, is_ld;

		//DECODE INSTRUCTION
		always @(*) begin
			//
			lui 	= opcode == lui_op;
			auipc 	= opcode == auipc_op;
			//JUMP OPERATIONS
			jal 	= opcode == jal_op;
			jalr	= opcode == jalr_op;
			//BRANCH OPERATIONS
			beq	= opcode == br_op  && func3 == beq_f3;
			bne	= opcode == br_op  && func3 == bne_f3;
			blt	= opcode == br_op  && func3 == blt_f3;
			bge	= opcode == br_op  && func3 == bge_f3;
			bltu	= opcode == br_op  && func3 == bltu_f3;
			bgeu	= opcode == br_op  && func3 == bgeu_f3;
			//LOAD OPERATIONS
			lb	= opcode == ld_op  && func3 == lb_f3;
			lh	= opcode == ld_op  && func3 == lh_f3;
			lw	= opcode == ld_op  && func3 == lw_f3;
			lbu	= opcode == ld_op  && func3 == lbu_f3;
			lhu	= opcode == ld_op  && func3 == lhu_f3;
			//STORE OPERATIONS
			sb	= opcode == st_op  && func3 == sb_f3;
			sh	= opcode == st_op  && func3 == sh_f3;
			sw	= opcode == st_op  && func3 == sw_f3;
			//INMEDIATE OPERATIONS
			addi	= opcode == imm_op && func3 == addi_f3;
			slti	= opcode == imm_op && func3 == slti_f3;	
			sltiu	= opcode == imm_op && func3 == sltiu_f3;
			xori	= opcode == imm_op && func3 == xori_f3;
			ori	= opcode == imm_op && func3 == ori_f3;
			andi	= opcode == imm_op && func3 == andi_f3;
			slli	= opcode == imm_op && func3 == slli_f3    && func7 == slli_f7;
			srli	= opcode == imm_op && func3 == sr_f3      && func7 == srli_f7;
			srai	= opcode == imm_op && func3 == sr_f3      && func7 == srai_f7;
			//ALU OPERATIONS
			add	= opcode == alu_op && func3 == add_sub_f3 && func7 == alu_f7;
			sub 	= opcode == alu_op && func3 == add_sub_f3 && func7 == sub_f7;
			slt	= opcode == alu_op && func3 == slt_f3 	  && func7 == alu_f7;	
			sltu	= opcode == alu_op && func3 == sltu_f3    && func7 == alu_f7;
			_xor	= opcode == alu_op && func3 == xor_f3     && func7 == alu_f7;
			_or	= opcode == alu_op && func3 == or_f3      && func7 == alu_f7;
			_and	= opcode == alu_op && func3 == and_f3     && func7 == alu_f7;
			sll	= opcode == alu_op && func3 == sll_f3     && func7 == alu_f7;
			srl	= opcode == alu_op && func3 == sr_f3      && func7 == alu_f7;
			sra	= opcode == alu_op && func3 == sr_f3      && func7 == sra_f7;
			//SPECIAL OPERATIONS
			nop	= instruction == nop_op;
			rw	= opcode == sp_op  && func3 == rw_f3; 
			rs	= opcode == sp_op  && func3 == rs_f3;
			rc	= opcode == sp_op  && func3 == rc_f3;
			rwi	= opcode == sp_op  && func3 == rwi_f3;
			rsi	= opcode == sp_op  && func3 == rsi_f3;
			rsc	= opcode == sp_op  && func3 == rci_f3;
			call	= opcode == sp_op  && inst[31:7]  == syscall;
			break	= opcode == sp_op  && inst[31:7]  == break; 
			ret	= opcode == sp_op  && inst[31:30] == mret_f2 && inst[27:7] == mret_f21; 

			is_unsigned = |{lbu,lhu,sltu,sltiu,bgeu,bltu};
			is_b        = |{beq,bne,blt,bge,bgeu,bltu};
			is_imm	    = |{addi,slti,sltiu,ori,andi,slli,srli,srai};
			is_st	    = |{sb, sh, sw}; 
			is_ld	    = |{lb,lbu,lh,lhu,lw}; 

		end
	

		//IMMEDIATE GENERATOR
		always @(*) begin
			case(1'b1)
				
				lui && auipc	: _imm <= {12'b0, inst[31:12]}; 
				jal		: _imm <= {12'b0, inst[31], inst[21:12], inst[22], inst[30:23]}; 
				jalr		: _imm <= {20'b0, inst[31:20]};
			       	is_b 		: _imm <= {20'b0, inst[31], inst[29:25], inst[11:7], inst[30]}; 	
				is_imm || is_ld	: _imm <= {20'b0, inst[31:20]}; 
				is_st		: _imm <= {20'b0, inst[31:25], inst[11:7]};
			endcase
		end 
		
		//SIGNED EXTENSION
		always @(*) begin
			if (is_unsigned) begin 
				_imm <= $unsigned(_imm); 
			end else begin
				_imm <= $signed(_imm); 
			end 
		end 

		//CONTROL SIGNALS 
		assign mem_wr 	= (is_st)? 1'b1: 1'b0; 
		assign mem_r  	= (is_ld)? 1'b1: 1'b0;
		assign mem_b	= (|{lb,lbu,sb})? 1'b1 : 1'b0;
		assign mem_hw  	= (|{lh,lhu,sh})? 1'b1 : 1'b0; 
		assign mem_ex_s = (|{is_ld, is_st})? 1'b1
endmodule				



