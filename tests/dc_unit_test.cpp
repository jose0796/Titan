

#include <iostream>

#include "Vdc_unit.h"
#include "testbench.h"


#define OK_COLOR    "\033[0;32m"
#define ERROR_COLOR "\033[0;31m"
#define NO_COLOR    "\033[m"

#define ALU_OP 	0
#define WADDR  	1 
#define WE	2
#define MEM_FL	3
#define X_SEL	4
#define BAD_JA	5
#define BAD_BA	6
#define BR_OP	7
#define S_OP	8
#define CSR_OP	9
#define CSRIOP	10
#define EXCAIF	11


#define INST_1 0x00001297  // auipc t0,0x1 (pc = 94) 
#define INST_2 0x0001e2b7  // lui   t0, 0x1e 
#define INST_3 0x7e8010ef  // jal   ra, 1958
#define INST_4 0x000900e7  // jal   s2
#define INST_5 0x2f878663  // beq   a5,s8,1758
#define INST_6 0xfd7a12e3  // bne   s4,s7,178c 
#define INST_7 0xfed746e3  // blt   a4,a3,1070
#define INST_8 0x020a5e63  // bge   s4, a0, 17c4
#define INST_9 0x00b7ea63  // bltu  a5,a1,1884
#define INST_10 0x00410083 // lb    ra,4(sp)
#define INST_11 0x00411083 // lb    ra,4(sp)
#define INST_12 0x00412083 // lw    ra,4(sp)
#define INST_13 0x00074683 // lbu   a3,0(a4)
#define INST_14 0x00075683 // lhu   a3,0(a4)
#define INST_15 0x000700a3 // sb    x0,1(a4)
#define INST_16 0x00d79023 // sh    a3,0(a5)
#define INST_17 0xeb010113 // sw    s10,288(sp)
#define INST_18 0xfffd0793 // addi  a5,s10,-1
#define INST_19 0xfffd2793 // slti  a5,s10,-1
#define INST_20 0xfffd3793 // sltiu a5,s10,-1
#define INST_21 0x00154713 // xori  a4,a0,1
#define INST_22 0x00156713 // ori   a4,a0,1
#define INST_23 0x00f57693 // andi  a3,a0,15
#define INST_24 0x01c59813 // slli  a6,a1,0x1c
#define INST_25 0x00455513 // srli  a0,a0,0x4
#define INST_26 0x41f7d793 // srai  a5,a5,0x1f
#define INST_27 0x01478a33 // add   s4,a5,0x2
#define INST_28 0x40d78c33 // sub   s8,a5,a3
#define INST_29 0x00d79c33 // sll   s8,a5,a3
#define INST_28 0x00d7ac33 // slt   s8,a5,a3
#define INST_29 0x00d7bc33 // sltu  s8,a5,a3
#define INST_30 0x00d7cc33 // xor   s8,a5,a3
#define INST_31 0x00d7dc33 // srl   s8,a5,a3
#define INST_32 0x40d7dc33 // sra   s8,a5,a3
#define INST_33 0x00c5e7b3 // or    a5,a1,a2
#define INST_34 0x00b6f6b3 // and   a3,a3,a1
#define INST_35 0x0ff0000f // fence.i  = nop
#define INST_36 0x00000073 // ecall 
#define INST_37 0x00000013 // nop = addi x0,x0,0
#define INST_38 0x34002573 // csrr  a0, mscratch
#define INST_39 0x3400f5f3 // csrrci a1, mscratch, 1
#define INST_40 0x34026673 // csrrs1 a2, mscratch, 4
#define INST_41 0x340156f3 // csrrwi a3, mscratch, 2
#define INST_42 0x340515f3 // csrrw  a1, mscratch, a0
#define INST_43 0x34053573 // csrrc  a0, mscratch, a0
#define INST_44 0x34052573 // csrrs  a0, mscratch, a0 


#define TOTAL_TESTS 44

using namespace std;

class SIMULATIONTB: public Testbench<Vdc_unit> {
  public:
    // -----------------------------------------------------------------------------
    // Testbench constructor
    SIMULATIONTB(double frequency=1e6, double timescale=1e-9): Testbench(frequency, timescale) {}


    int Simulate(unsigned long max_time=1000000){
	Reset();

	int alu_op, waddr, we, mem_flags,x_se, j_op, bad_ja, b_op, bad_ba, take_branch, br_op, s_op, csr_op, csr_imm_op, exc_addr_if;
	int data[TOTAL_TESTS][15] = {            
      //|rs1|rs2|rd|alu_op|we|cmp_op|mem_flags|x_se|pa_se|pb_se|j_op|bja|b_op|bba|br_op|s_op|csr_op|csr_imm_op|csr_addr|exc_addr_if|
 	 
	{ 0 , 0 ,5, 0b0000 ,1,0b000 ,0b000000 , 0 ,  0  ,  1  ,  0 , 0 ,  0 , 0 ,  0  ,  0 , 0b000,     0    , 0x000  ,    0      },
	{ 0 , 0 ,5, 0b0000 ,1,0b000 ,0b000000 , 0 ,  0  ,  1  ,  0 , 0 ,  0 , 0 ,  0  ,  0 , 0b000,     0    , 0x000  ,    0      },
	{ 0 , 0 ,5, 0b0000 ,1,0b000 ,0b000000 , 0 ,  0  ,  0  ,  1 , 0 ,  0 , 0 ,  0  ,  0 , 0b000,     0    , 0x000  ,    0      },
	{ 0 , 0 ,5, 0b0000 ,1, 0b000000 , 0 ,  0  ,  0  ,  0 , 0 ,  0 , 0 ,  0  ,  0 , 0b000,     0    , 0x000  ,    0      },
	{ 0 , 0 ,5,0b0000 ,1, 0b000000 ,  0 ,  0  ,  0  ,  0 , 0 ,  0 , 0 ,  0  ,  0 , 0b000,     0    , 0x000  ,    0      },
	{ 0 , 0 ,5,0b0000 ,1, 0b000000 ,  0 ,  0  ,  0  ,  0 , 0 ,  0 , 0 ,  0  ,  0 , 0b000,     0    , 0x000  ,    0      },
	{ 0 , 0 ,5,0b0000 ,1, 0b000000 ,  0 ,  0  ,  0  ,  0 , 0 ,  0 , 0 ,  0  ,  0 , 0b000,     0    , 0x000  ,    0      },
	{ 0 , 0 ,5,0b0000 ,1, 0b000000 ,  0 ,  0  ,  0  ,  0 , 0 ,  0 , 0 ,  0  ,  0 , 0b000,     0    , 0x000  ,    0      },
	{ 0 , 0 ,5,0b0000 ,1, 0b000000 ,  0 ,  0  ,  0  ,  0 , 0 ,  0 , 0 ,  0  ,  0 , 0b000,     0    , 0x000  ,    0      },
	{ 0 , 0 ,5,0b0000 ,1, 0b000000 ,  0 ,  0  ,  0  ,  0 , 0 ,  0 , 0 ,  0  ,  0 , 0b000,     0    , 0x000  ,    0      },
	{ 0 , 0 ,5,0b0000 ,1, 0b000000 ,  0 ,  0  ,  0  ,  0 , 0 ,  0 , 0 ,  0  ,  0 , 0b000,     0    , 0x000  ,    0      },
	{ 0 , 0 ,5,0b0000 ,1, 0b000000 ,  0 ,  0  ,  0  ,  0 , 0 ,  0 , 0 ,  0  ,  0 , 0b000,     0    , 0x000  ,    0      },
	{ 0 , 0 ,5,0b0000 ,1, 0b000000 ,  0 ,  0  ,  0  ,  0 , 0 ,  0 , 0 ,  0  ,  0 , 0b000,     0    , 0x000  ,    0      },
	{ 0 , 0 ,5,0b0000 ,1, 0b000000 ,  0 ,  0  ,  0  ,  0 , 0 ,  0 , 0 ,  0  ,  0 , 0b000,     0    , 0x000  ,    0      },
	{ 0 , 0 ,5,0b0000 ,1, 0b000000 ,  0 ,  0  ,  0  ,  0 , 0 ,  0 , 0 ,  0  ,  0 , 0b000,     0    , 0x000  ,    0      },
	{ 0 , 0 ,5,0b0000 ,1, 0b000000 ,  0 ,  0  ,  0  ,  0 , 0 ,  0 , 0 ,  0  ,  0 , 0b000,     0    , 0x000  ,    0      },
	{ 0 , 0 ,5,0b0000 ,1, 0b000000 ,  0 ,  0  ,  0  ,  0 , 0 ,  0 , 0 ,  0  ,  0 , 0b000,     0    , 0x000  ,    0      },
	{ 0 , 0 ,5,0b0000 ,1, 0b000000 ,  0 ,  0  ,  0  ,  0 , 0 ,  0 , 0 ,  0  ,  0 , 0b000,     0    , 0x000  ,    0      },
	{ 0 , 0 ,5,0b0000 ,1, 0b000000 ,  0 ,  0  ,  0  ,  0 , 0 ,  0 , 0 ,  0  ,  0 , 0b000,     0    , 0x000  ,    0      },
	{ 0 , 0 ,5,0b0000 ,1, 0b000000 ,  0 ,  0  ,  0  ,  0 , 0 ,  0 , 0 ,  0  ,  0 , 0b000,     0    , 0x000  ,    0      },
	{ 0 , 0 ,5,0b0000 ,1, 0b000000 ,  0 ,  0  ,  0  ,  0 , 0 ,  0 , 0 ,  0  ,  0 , 0b000,     0    , 0x000  ,    0      },
	{ 0 , 0 ,5,0b0000 ,1, 0b000000 ,  0 ,  0  ,  0  ,  0 , 0 ,  0 , 0 ,  0  ,  0 , 0b000,     0    , 0x000  ,    0      },
	{ 0 , 0 ,5,0b0000 ,1, 0b000000 ,  0 ,  0  ,  0  ,  0 , 0 ,  0 , 0 ,  0  ,  0 , 0b000,     0    , 0x000  ,    0      },
	{ 0 , 0 ,5,0b0000 ,1, 0b000000 ,  0 ,  0  ,  0  ,  0 , 0 ,  0 , 0 ,  0  ,  0 , 0b000,     0    , 0x000  ,    0      },
	{ 0 , 0 ,5,0b0000 ,1, 0b000000 ,  0 ,  0  ,  0  ,  0 , 0 ,  0 , 0 ,  0  ,  0 , 0b000,     0    , 0x000  ,    0      },
	{ 0 , 0 ,5,0b0000 ,1, 0b000000 ,  0 ,  0  ,  0  ,  0 , 0 ,  0 , 0 ,  0  ,  0 , 0b000,     0    , 0x000  ,    0      },
	{ 0 , 0 ,5,0b0000 ,1, 0b000000 ,  0 ,  0  ,  0  ,  0 , 0 ,  0 , 0 ,  0  ,  0 , 0b000,     0    , 0x000  ,    0      },
	{ 0 , 0 ,5,0b0000 ,1, 0b000000 ,  0 ,  0  ,  0  ,  0 , 0 ,  0 , 0 ,  0  ,  0 , 0b000,     0    , 0x000  ,    0      },
	{ 0 , 0 ,5,0b0000 ,1, 0b000000 ,  0 ,  0  ,  0  ,  0 , 0 ,  0 , 0 ,  0  ,  0 , 0b000,     0    , 0x000  ,    0      },
	{ 0 , 0 ,5,0b0000 ,1, 0b000000 ,  0 ,  0  ,  0  ,  0 , 0 ,  0 , 0 ,  0  ,  0 , 0b000,     0    , 0x000  ,    0      },
	{ 0 , 0 ,5,0b0000 ,1, 0b000000 ,  0 ,  0  ,  0  ,  0 , 0 ,  0 , 0 ,  0  ,  0 , 0b000,     0    , 0x000  ,    0      },
	{ 0 , 0 ,5,0b0000 ,1, 0b000000 ,  0 ,  0  ,  0  ,  0 , 0 ,  0 , 0 ,  0  ,  0 , 0b000,     0    , 0x000  ,    0      },
	{ 0 , 0 ,5,0b0000 ,1, 0b000000 ,  0 ,  0  ,  0  ,  0 , 0 ,  0 , 0 ,  0  ,  0 , 0b000,     0    , 0x000  ,    0      },
	{ 0 , 0 ,5,0b0000 ,1, 0b000000 ,  0 ,  0  ,  0  ,  0 , 0 ,  0 , 0 ,  0  ,  0 , 0b000,     0    , 0x000  ,    0      },
	{ 0 , 0 ,5,0b0000 ,1, 0b000000 ,  0 ,  0  ,  0  ,  0 , 0 ,  0 , 0 ,  0  ,  0 , 0b000,     0    , 0x000  ,    0      },
	{ 0 , 0 ,5,0b0000 ,1, 0b000000 ,  0 ,  0  ,  0  ,  0 , 0 ,  0 , 0 ,  0  ,  0 , 0b000,     0    , 0x000  ,    0      },
	{ 0 , 0 ,5,0b0000 ,1, 0b000000 ,  0 ,  0  ,  0  ,  0 , 0 ,  0 , 0 ,  0  ,  0 , 0b000,     0    , 0x000  ,    0      },
	{ 0 , 0 ,5,0b0000 ,1, 0b000000 ,  0 ,  0  ,  0  ,  0 , 0 ,  0 , 0 ,  0  ,  0 , 0b000,     0    , 0x000  ,    0      },
	{ 0 , 0 ,5,0b0000 ,1, 0b000000 ,  0 ,  0  ,  0  ,  0 , 0 ,  0 , 0 ,  0  ,  0 , 0b000,     0    , 0x000  ,    0      },
	{  0b1111 ,   0   ,  0 , 0b000000  ,  0   ,  0  ,  0  ,   0   ,   0  , 0b000  ,     0      ,      0      },
	{  0b0000 ,   0   ,  0 , 0b101000  ,  0   ,  0  ,  0  ,   0   ,   0  , 0b000  ,     0      ,      0      },
	{  0b0000 ,   1   ,  1 , 0b011000  ,  1   ,  0  ,  0  ,   0   ,   0  , 0b000  ,     0      ,      0      },
	{  0b0000 ,   5   ,  1 , 0b000000  ,  0   ,  0  ,  0  ,   0   ,   0  , 0b000  ,     0      ,      0      },
	{  0b0000 ,   0   ,  0 , 0b100010  ,  0   ,  0  ,  0  ,   0   ,   0  , 0b000  ,     0      ,      0      }};

      	int num_test;
      	for (num_test = 0; num_test < TOTAL_TESTS; num_test++) {
		Tick();
		while (!m_core->ex_ready) Tick();
		//Tick();
	 	alu_op 		= m_core->ex_alu_op 		== data[num_test][ALU_OP];		
	 	waddr 		= m_core->ex_waddr 		== data[num_test][ WADDR];		
	 	we 		= m_core->ex_we     		== data[num_test][    WE];		
	 	mem_flags 	= m_core->ex_mem_flags 		== data[num_test][MEM_FL];		
	 	x_se		= m_core->ex_mem_ex_sel 	== data[num_test][ X_SEL];		
	 	bad_ja		= m_core->ex_bad_jump_addr  	== data[num_test][BAD_JA];		
	 	bad_ba		= m_core->ex_bad_branch_addr	== data[num_test][BAD_BA];		
	 	br_op		= m_core->ex_break_op		== data[num_test][ BR_OP];		
	 	s_op 		= m_core->ex_syscall_op		== data[num_test][  S_OP];		
	 	csr_op 		= m_core->ex_csr_op		== data[num_test][CSR_OP];		
		csr_imm_op	= m_core->ex_csr_imm_op		== data[num_test][CSRIOP];
		exc_addr_if	= m_core->ex_exc_addr_if_o	== data[num_test][EXCAIF];


		
		if (!(alu_op &&  waddr && we && mem_flags && x_se && bad_ja && bad_ba && br_op && s_op && csr_op && csr_imm_op && exc_addr_if ))
			return num_test;
      	}
      	return num_test;
    	}
};


int main(int argc, char **argv, char **env) {
  std::unique_ptr<SIMULATIONTB> tb(new SIMULATIONTB());

  tb->OpenTrace("ifid_stage_test.vcd");

  int ret = tb->Simulate();

  printf("\nIF-ID STAGE Testbench:\n");

  if(ret == TOTAL_TESTS)
    printf(OK_COLOR "Test Passed! " NO_COLOR);
  else
    printf(ERROR_COLOR  "Test Failed! " NO_COLOR);

  printf("Complete: %d/%d\n", ret, TOTAL_TESTS);

  exit(0);
}
