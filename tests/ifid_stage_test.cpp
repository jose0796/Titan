

#include <iostream>

#include "Vifid_stage.h"
#include "testbench.h"


#define OK_COLOR    "\033[0;32m"
#define ERROR_COLOR "\033[0;31m"
#define NO_COLOR    "\033[m"

#define ALU_OP 	0
#define WADDR  	1 
#define WE	2
#define MEM_FL	3
#define X_SEL	4
#define J_OP	5 
#define BAD_JA	6
#define B_OP	7
#define BAD_BA	8
#define TK_BR	9
#define BR_OP	10
#define S_OP	11
#define CSR_OP	12
#define CSRIOP	13
#define EXCAIF	14

#define INST_1 0x00001297  / auipc t0,0x1 (pc = 94) 
#define INST_2 0x00b57063  // bleu  a1,a0,c8 (a1 = 1, a0 = 0) 
#define INST_3 0x00112223  // sw    ra,4(sp) (sp = -272)
#define INST_4 0x00412083  // lw    ra,4(sp) (sp = -272)
#define INST_5 0x80028293  // addi  t0,t0, -2048
#define INST_6 0x00a78023  // sb    a0, 0(a5)

#define TOTAL_TESTS 6

using namespace std;

class SIMULATIONTB: public Testbench<Vifid_stage> {
  public:
    // -----------------------------------------------------------------------------
    // Testbench constructor
    SIMULATIONTB(double frequency=1e6, double timescale=1e-9): Testbench(frequency, timescale) {}


    int Simulate(unsigned long max_time=1000000){
	Reset();

	int alu_op, waddr, we, mem_flags,x_se, j_op, bad_ja, b_op, bad_ba, take_branch, br_op, s_op, csr_op, csr_imm_op, exc_addr_if;
	int data[TOTAL_TESTS][15] = {            
      //|  alu_op | waddr | we | mem_flags | x_se | j_op| bja | b_op | bba | tb | br_op | s_op | csr_op | csr_imm_op | exc_addr_if |
 	 
	{  0b0000 ,   5   ,  1 , 0b000000  ,  0   ,  0  ,  0  ,  0   ,  0  ,  0 ,   0   ,   0  , 0b000  ,     0      ,      0      },
	{  0b1111 ,   0   ,  0 , 0b000000  ,  0   ,  0  ,  0  ,  1   ,  0  ,  0 ,   0   ,   0  , 0b000  ,     0      ,      0      },
	{  0b0000 ,   0   ,  0 , 0b010010  ,  0   ,  0  ,  0  ,  0   ,  0  ,  0 ,   0   ,   0  , 0b000  ,     0      ,      0      },
	{  0b0000 ,   1   ,  1 , 0b110000  ,  1   ,  0  ,  0  ,  0   ,  0  ,  0 ,   0   ,   0  , 0b000  ,     0      ,      0      },
	{  0b0000 ,   5   ,  1 , 0b000000  ,  0   ,  0  ,  0  ,  0   ,  0  ,  0 ,   0   ,   0  , 0b000  ,     0      ,      0      },
	{  0b0000 ,   0   ,  0 , 0b000110  ,  0   ,  0  ,  0  ,  0   ,  0  ,  0 ,   0   ,   0  , 0b000  ,     0      ,      0      }};

      	int num_test;
      	for (num_test = 0; num_test < TOTAL_TESTS; num_test++) {
		while (!m_core->ex_ready) Tick();

	 	alu_op 		= m_core->ex_alu_op 		== data[num_test][ALU_OP];		
	 	waddr 		= (data[num_test][WE])? m_core->ex_waddr == data[num_test][ WADDR]: 1;		
	 	we 		= m_core->ex_we     		== data[num_test][    WE];		
	 	mem_flags 	= m_core->ex_mem_flags 		== data[num_test][MEM_FL];		
	 	x_se		= m_core->ex_mem_ex_sel 	== data[num_test][ X_SEL];		
	 	j_op		= m_core->ex_jump_op    	== data[num_test][  J_OP];		
	 	bad_ja		= m_core->ex_bad_jump_addr  	== data[num_test][BAD_JA];		
	 	b_op		= m_core->ex_branch_op		== data[num_test][  B_OP];		
	 	bad_ba		= m_core->ex_bad_branch_addr	== data[num_test][BAD_BA];		
	 	take_branch	= m_core->take_branch		== data[num_test][ TK_BR];		
	 	br_op		= m_core->ex_break_op		== data[num_test][ BR_OP];		
	 	s_op 		= m_core->ex_syscall_op		== data[num_test][  S_OP];		
	 	csr_op 		= m_core->ex_csr_op		== data[num_test][CSR_OP];		
		csr_imm_op	= m_core->ex_csr_imm_op		== data[num_test][CSRIOP];
		exc_addr_if	= m_core->ex_exc_addr_if_o	== data[num_test][EXCAIF];

		if (!(alu_op || waddr || we || mem_flags || x_se || j_op || bad_ja || b_op || bad_ba || take_branch || br_op || s_op || csr_op || csr_imm_op || exc_addr_if ))
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
