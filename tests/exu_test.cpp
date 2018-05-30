/*
* ALU Module - TestBench
* Anderson Contreras
*/


#include <iostream>

#include "Vexu.h"
#include "testbench.h"



#define PA      0
#define PB      1
#define ALU_OP  2
#define OUT     3

#define ALU_ADD   0b0000
#define ALU_SUB   0b0001
#define ALU_AND   0b0010
#define ALU_OR    0b0011
#define ALU_XOR   0b0100
#define ALU_SLL   0b0101
#define ALU_SRA   0b0110
#define ALU_SRL   0b0111
#define ALU_SLT   0b1000
#define ALU_SLTU  0b1001
#define NO_OP     0b1111

#define TOTAL_TESTS 24


using namespace std;

class TB: public Testbench<Vexu> {
  public:
    int ok = 0;
    TB(double frequency=1e9, double timescale=1e-10): Testbench(frequency, timescale) {}

    int Simulate(unsigned long max_time=100000000){

      //|  port_a | port_b |    ALU OP  | Output |
      
	int operations[10] = { ALU_ADD, ALU_AND, ALU_OR, ALU_SUB, ALU_XOR, ALU_SLL, ALU_SRA, ALU_SRL, ALU_SLT, ALU_SLTU };
	unsigned int data_i[20][2]  = {
	{1,1},{3,7},{0x80000000,0xffff8000},{0x7ffff000,0xffff8000},{0x7ffff,1},
	{0xff00ff00,0xf0f0f0f0},{0xff00f0,0xf0f0f0f0},{0xff00ff,0xf0f0f0f},{0xf00ff00f,0xf0f0f0f0},{0xff00ff00,0xf0f0f0f},
	{0xff00ff00,0xf0f0f0f},{0xff00ff0,0xf0f0f0f0},{0xff00ff,0xf0f0f0f},{0xf00ff00f,0xf0f0f0f0},{0xff00ff00,0xf0f0f0f},
	{1,1},{3,7},{0x80000000,0xffff8000},{0x7fff,0xffff8},{0x7fffffff,0xf777}	};

	unsigned int data_o[20]= {
	  	 2,10,0x7fff8000,0x7fff7000,0x80000, // add op
		 0xf000f000, 0xf000f0, 0xf000f,0xf000f000,0xf000f00, // and op 
		 0xff0fff0f, 0xfff0fff0,0xfff0fff,0xf0fff0ff,0xff0fff0f, //or op
		 0,0xfffffffb,0x80008000,0xffff8001,0x7fff8 //sub op
	}; 
      for (int i  = 0; i < 10; i++) {
        m_core->port_a = data_i[i][0];
        m_core->port_b = data_i[i][1];
        m_core->alu_op = operations[int(i/5)];

        Tick();

        if((m_core->result != data_o[i])) {
          	 ok = -1;
		 break;
	}
      }
	if ( ok == 0){
		printf("\nEXU Testbench:\n");
		printf("Test Passed! ");
	}
  	else{
	  	printf("Test Failed! ");
	}
    }
};


int main(int argc, char **argv, char **env) {
  std::unique_ptr<TB> tb(new TB());

  tb->OpenTrace("exu_test.vcd");

  tb->Reset();
  int n = tb->Simulate();

  exit(0);
}
