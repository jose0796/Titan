/*
* ALU Module - TestBench
* Anderson Contreras
*/


#include <iostream>

#include "Vif_stage.h"
#include "testbench.h"


#define OK_COLOR    "\033[0;32m"
#define ERROR_COLOR "\033[0;31m"
#define NO_COLOR    "\033[m"

#define PA      0
#define PB      1
#define ALU_OP  2
#define OUT     3

#define TOTAL_TESTS 24


using namespace std;

class SIMULATIONTB: public Testbench<Vif_stage> {
  public:
    // -----------------------------------------------------------------------------
    // Testbench constructor
    SIMULATIONTB(double frequency=1e6, double timescale=1e-9): Testbench(frequency, timescale) {}

    int Simulate(unsigned long max_time=1000000){
      Reset();

      //|  pc_ba | pc_ja | id_instruction | id_pc | id_pc_add4 |
      int data[TOTAL_TESTS][2] = {                      //           									
	 {     0 |}
      int num_test;
      for (num_test = 0; num_test < TOTAL_TESTS; num_test++) {
        m_core->port_a = data[num_test][PA];
        m_core->port_b = data[num_test][PB];
        m_core->alu_op  = data[num_test][ALU_OP] ;

        Tick();

        if((m_core->result != data[num_test][OUT]))
          return num_test;
      }
      return num_test;
    }
};


int main(int argc, char **argv, char **env) {
  std::unique_ptr<SIMULATIONTB> tb(new SIMULATIONTB());

  tb->OpenTrace("exu_test.vcd");

  int ret = tb->Simulate();

  printf("\nEXU Testbench:\n");

  if(ret == TOTAL_TESTS)
    printf(OK_COLOR " Test Passed! " NO_COLOR);
  else
    printf(ERROR_COLOR  " Test Failed! " NO_COLOR);

  printf("Complete: %d/%d\n", ret, TOTAL_TESTS);

  exit(0);
}
