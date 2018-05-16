
`include "./rtl/def.v"

module decoder (
		input [31:0] instruction,
	        //IF STATE SIGNALS
//		output pc_branch_address,
		//ID STAGE SIGNALS
		output [4:0] rs1, 
		output [4:0] rs2,
		output [4:0] rd,
		output reg_write,
		output reg [2:0] comparator_op,
		//MEM STAGE CONTROL SIGNALS
		output mem_write,
		output mem_byte,
		output mem_halfword,
		output mem_read,
		output mem_ex_sel,
		output mem_unsigned,
		//EX STAGE CONTROL SIGNALS
		output reg [2:0] alu_op, 	
		output reg [31:0] imm,
		output reg portb_sel,
		output reg porta_sel,
		output syscall_op,
		output branch_op,
		output jump_op,
		output jalr_op,
		output break_op 	); 
	
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


		//ASSIGNMENTS
		assign inst 	 = instruction[31:0];
		assign opcode 	 = instruction[6:0];
		assign func3 	 = instruction[14:12]; 
		assign func7 	 = instruction[31:25]; 
		//+- EX STAGE ASSIGNMENTS
		assign rs1 	 = (lui)? 5'b0 : instruction[19:15]; 
		assign rs2 	 = instruction[24:20];
		assign rd  	 = instruction[11:7]; 
		//+- MEM STAGE ASSIGMENTS
		assign mem_write = mem_wr;
		assign mem_byte  = mem_b; 
		assign mem_halfword = mem_hw;
		assign mem_read  = mem_r;
		assign mem_ex_sel= mem_ex_s;
		
		//TYPES OF INSTRUCTIONS
		reg lui,auipc;
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
		reg is_add, is_sub, is_and, is_xor, is_or, is_sll, is_sr, is_slt; 
		reg is_wr, is_alu, is_immop, is_ldu, is_bu, is_j;
		//DECODE INSTRUCTION
		always @(*) begin
			//
			lui 	= opcode == `lui_op;
			auipc 	= opcode == `auipc_op;
			//JUMP OPERATIONS
			jal 	= opcode == `jal_op;
			jalr	= opcode == `jalr_op;
			//BRANCH OPERATIONS
			beq	= opcode == `br_op  && func3 == `beq_f3;
			bne	= opcode == `br_op  && func3 == `bne_f3;
			blt	= opcode == `br_op  && func3 == `blt_f3;
			bge	= opcode == `br_op  && func3 == `bge_f3;
			bltu	= opcode == `br_op  && func3 == `bltu_f3;
			bgeu	= opcode == `br_op  && func3 == `bgeu_f3;
			//LOAD OPERATIONS
			lb	= opcode == `ld_op  && func3 == `lb_f3;
			lh	= opcode == `ld_op  && func3 == `lh_f3;
			lw	= opcode == `ld_op  && func3 == `lw_f3;
			lbu	= opcode == `ld_op  && func3 == `lbu_f3;
			lhu	= opcode == `ld_op  && func3 == `lhu_f3;
			//STORE OPERATIONS
			sb	= opcode == `st_op  && func3 == `sb_f3;
			sh	= opcode == `st_op  && func3 == `sh_f3;
			sw	= opcode == `st_op  && func3 == `sw_f3;
			//INMEDIATE OPERATIONS
			addi	= opcode == `imm_op && func3 == `addi_f3;
			slti	= opcode == `imm_op && func3 == `slti_f3;	
			sltiu	= opcode == `imm_op && func3 == `sltiu_f3;
			xori	= opcode == `imm_op && func3 == `xori_f3;
			ori	= opcode == `imm_op && func3 == `ori_f3;
			andi	= opcode == `imm_op && func3 == `andi_f3;
			slli	= opcode == `imm_op && func3 == `slli_f3    && func7 == `slli_f7;
			srli	= opcode == `imm_op && func3 == `sr_f3      && func7 == `srli_f7;
			srai	= opcode == `imm_op && func3 == `sr_f3      && func7 == `srai_f7;
			//ALU OPERATIONS
			add	= opcode == `alu_op && func3 == `add_sub_f3 && func7 == `alu_f7;
			sub 	= opcode == `alu_op && func3 == `add_sub_f3 && func7 == `sub_f7;
			slt	= opcode == `alu_op && func3 == `slt_f3     && func7 == `alu_f7;	
			sltu	= opcode == `alu_op && func3 == `sltu_f3    && func7 == `alu_f7;
			_xor	= opcode == `alu_op && func3 == `xor_f3     && func7 == `alu_f7;
			_or	= opcode == `alu_op && func3 == `or_f3      && func7 == `alu_f7;
			_and	= opcode == `alu_op && func3 == `and_f3     && func7 == `alu_f7;
			sll	= opcode == `alu_op && func3 == `sll_f3     && func7 == `alu_f7;
			srl	= opcode == `alu_op && func3 == `sr_f3      && func7 == `alu_f7;
			sra	= opcode == `alu_op && func3 == `sr_f3      && func7 == `sra_f7;
			//SPECIAL OPERATIONS
			nop	= instruction == `nop_op;
			rw	= opcode == `sp_op  && func3 == `rw_f3; 
			rs	= opcode == `sp_op  && func3 == `rs_f3;
			rc	= opcode == `sp_op  && func3 == `rc_f3;
			rwi	= opcode == `sp_op  && func3 == `rwi_f3;
			rsi	= opcode == `sp_op  && func3 == `rsi_f3;
			rci	= opcode == `sp_op  && func3 == `rci_f3;
			call	= opcode == `sp_op  && inst[31:7]  == `syscall;
			break	= opcode == `sp_op  && inst[31:7]  == `break; 
			ret	= opcode == `sp_op  && inst[31:30] == `mret_f2 && inst[27:7] == `mret_f21; 

			is_j	    = |{jal,jalr};
			is_unsigned = |{sltu,sltiu,bgeu,bltu};
			is_ldu	    = |{lbu,lhu};//loads operations with unsigned operations
			is_bu	    = |{bgeu,bltu};
			is_b        = |{beq,bne,blt,bge,bgeu,bltu}; //branch operations flag
			is_alu	    = |{add,sub,slt,sltu,_xor,_or,_and,sll,srl,sra}; //alu operations flag
			is_st	    = |{sb, sh, sw}; //store operation flags
			is_ld	    = |{lb,lbu,lh,lhu,lw}; //loads operation flag 
			is_imm	    = |{addi,slti,sltiu,ori,andi,slli,srli,srai, xori, is_ld, jalr}; //immediates operations excluding store
			is_add	    = |{add, addi, is_st, is_ld, lui, auipc}; //add operation flag
			is_sub	    = |{sub,is_b}; //sub operation flag
			is_xor	    = |{_xor,xori};//xor operation flag
			is_and	    = |{_and,andi}; //and operation flag
			is_or	    = |{_or,ori}; //or operation flag
			is_sll      = |{sll, slli}; //shift left operations flag
			is_sr	    = |{sra, srl, srai, srli}; //shift rights operations flag
			is_immop    = |{addi,slti, sltiu, ori, andi, xori, jalr, is_st, is_ld, lui,auipc}; //operation uses immediates? 
			is_wr       = |{is_imm, is_alu, is_ld, auipc, lui}; //determines if operations is going to write 
			

		end
	

		//IMMEDIATE GENERATOR
		always @(*) begin
			case(1'b1)	
			lui || auipc	: imm <= { inst[31:12] , 12'h0}; 
			jal		: imm <= { ((inst[31])? 12'hfff   : 12'b0), inst[31], inst[19:12], inst[20], inst[30:21]}; 
			is_b 		: imm <= { ((inst[31])? 20'hfffff : 20'b0), inst[31], inst[7], inst[30:25], inst[11:8]}; 	
			is_imm 		: imm <= { ((inst[31])? 20'hfffff : 20'b0), inst[31:20]}; 
			is_st		: imm <= { ((inst[31])? 20'hfffff : 20'b0), inst[31:25], inst[11:7]};
			endcase
		end 
		
		//CONTROL SIGNALS 
		assign mem_wr 	    = is_st; 
		assign mem_r  	    = is_ld;
		assign mem_b	    = |{lb,lbu,sb};
		assign mem_hw  	    = |{lh,lhu,sh}; 
		assign mem_ex_s     = is_ld; 
		assign syscall_op   = call; 
	        assign break_op     = break;
		assign jump_op      = is_j;
		assign branch_op    = is_b; 
		assign reg_write    = is_wr;
		assign mem_unsigned = is_ldu;
		assign jalr_op      = jalr;
		//COMPARATOR OP
		
		always @(*) begin
			case(1'b1)
				is_bu: comparator_op <= 3'b110;
				beq  : comparator_op <= 3'b001;
				bne  : comparator_op <= 3'b010;
				blt  : comparator_op <= 3'b011;
				bge  : comparator_op <= 3'b100;
				default: comparator_op <= 3'b0;
			endcase
		end
				
		//ALU_OP
		
		always @(*) begin
			case(1'b1) 
				is_add : alu_op <= 3'b000; 
				is_sub : alu_op <= 3'b001;
				is_and : alu_op <= 3'b010;
				is_or  : alu_op <= 3'b011;
				is_xor : alu_op <= 3'b100;
				is_sll : alu_op <= 3'b101;
				is_sr  : alu_op <= ((sra && srai)? 3'b110 : 3'b111);
			endcase
		end 

		//ALU_PORT SELECTION
		always @(*) begin 
			portb_sel <= (is_immop) ? 1'b1 : 1'b0;
			porta_sel <= (auipc) ? 1'b1 : 1'b0;
		end
endmodule			



