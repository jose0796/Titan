

#include <iostream>

#include "Vif_stage.h"
#include "testbench.h"


#define OK_COLOR    "\033[0;32m"
#define ERROR_COLOR "\033[0;31m"
#define NO_COLOR    "\033[m"

#define PC_BA  0
#define PC_JA  1
#define PC_SEL 0
#define INST   1
#define PC_O   2
#define PC_ADD4 3

#define INST_1 0x00001297 //auipc t0,0x1 (pc = 94)
#define INST_2 0x00b57063 //bleu a1, a0,c8
#define INST_3 0x00112223 //sw  ra,4(sp)
#define INST_4 0x00412083 //lw  ra,4(sp)
#define INST_5 0x80028293 //addi t0,t0, -2048

#define TOTAL_TESTS 5


using namespace std;

class SIMULATIONTB: public Testbench<Vif_stage> {
  public:
    // -----------------------------------------------------------------------------
    // Testbench constructor
    SIMULATIONTB(double frequency=1e6, double timescale=1e-9): Testbench(frequency, timescale) {}

    int Simulate(unsigned long max_time=1000000){
      Reset();


      //  pc_sel | id_inst    | id_pc | id_pc_add4
      unsigned int data[TOTAL_TESTS][4] = {                      //           									
	 {       0,	INST_1,	     0,           4},			//pc = pc + 4
	 {	 0,     INST_2,	     4,		  8},			
	 {	 0,	INST_3,	     8, 	  12},
	 {	 0,	INST_4,	     12,	  16},
	 {	 0,	INST_5,	     16,	  20}};

      int num_test;
      for (num_test = 0; num_test < TOTAL_TESTS; num_test++) {
        m_core->pc_sel            = data[num_test][PC_SEL];

        Tick();

	while(!m_core->id_ready_o) Tick(); 

	if ( m_core->id_instruction_o != data[num_test][INST] || m_core->id_pc_add4 != data[num_test][PC_ADD4] ||m_core->id_pc_o != data[num_test][PC_O] )
		return num_test;
      }
      return num_test;
    }
};


int main(int argc, char **argv, char **env) {
  std::unique_ptr<SIMULATIONTB> tb(new SIMULATIONTB());

  tb->OpenTrace("if_stage_test.vcd");

  int ret = tb->Simulate();

  printf("\nIF STAGE Testbench:\n");

  if(ret == TOTAL_TESTS)
    printf(OK_COLOR " Test Passed! " NO_COLOR);
  else
    printf(ERROR_COLOR  " Test Failed! " NO_COLOR);

  printf("Complete: %d/%d\n", ret, TOTAL_TESTS);

  exit(0);
}
