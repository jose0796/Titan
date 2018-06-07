#include <iostream>
#include "Vexu.h"
#include "testbench.h"
#define ADD   0b0000
#define SUB   0b0001
#define AND   0b0010
#define OR    0b0011
#define XOR   0b0100
#define SLL   0b0101
#define SRA   0b0110
#define SRL   0b0111
#define SLT   0b1000
#define SLTU  0b1001
#define NO_OP     0b1111


using namespace std;

class EXU: public Testbench<Vexu> {
  public:
    int ok = 0;
    EXU(double frequency=1e9, double timescale=1e-10): Testbench(frequency, timescale) {}

    int sim(unsigned long max_time=100000000){

        
	int operations[10] = { ADD, SUB, AND, OR, XOR, SLL, SRA, SRL, SLT, SLTU };
	//INPUTS
	unsigned int data_i[50][2]  = {
	{1,1},{3,7},{0x80000000,0xffff8000},{0x7ffff000,0xffff8000},{0x7ffff,1},						//add
	{1,1},{3,7},{0x80000000,0xffff8000},{0x0,0x7fff},{0x7fffffff,0x7fff},							//sub
	{0xff00ff00,0xf0f0f0f0},{0xff00f0,0xf0f0f0f0},{0xff00ff,0xf0f0f0f},{0xf00ff00f,0xf0f0f0f0},{0xff00ff00,0xf0f0f0f},	//and
	{0xff00ff00,0xf0f0f0f},{0xff00ff0,0xf0f0f0f0},{0xff00ff,0xf0f0f0f},{0xf00ff00f,0xf0f0f0f0},{0xff00ff00,0xf0f0f0f},	//or
	{0xff0f00,0xffffff0f},{0xff00ff0,0xf0},{0xff08ff,0x70f},{0xf00ff00f,0xf0},{0xff00f700,0x70f},				//xor
	{1,0},{1,1},{1,0x7},{1,0xe},{1,0x1f},											//sll
	{0x80000000,0x1},{0x80000000,0x7},{0x80000000,0xe},{0x80000001,0x1f},{0x7fffffff,1},					//sra
	{0x80000000,7},{0x80000000,14},{0x80000001,31},{0xffffffff,1},{0xffffffff,7},						//srl
	{0,0},{3,7},{7,3},{0,0xffff8000},{0x80000000,0},									//slt
	{0, 0xffff8000},{0x80000000,0},{0x80000000,0xffff8000},{0,0x7fff},{0x7fffffff,0}					//sltu
	};
	//RESULTS
	unsigned int data_o[50]= {
	  	 2,10,0x7fff8000,0x7fff7000,0x80000, 				// add op
		 0,0xfffffffc,0x80008000,0xffff8001,0x7fff8000,			// sub op
		 0xf000f000, 0xf000f0, 0xf000f,0xf000f000,0xf000f00, 		// and op 
		 0xff0fff0f, 0xfff0fff0,0xfff0fff,0xf0fff0ff,0xff0fff0f, 	// or op
		 0xff00f00f,0xff00f00,0xff0ff0,0xf00ff0ff,0xff00f00f,		// xor op
		 1,2,128,0x4000,0x80000000, 					// sll op
		 0xc0000000,0xff000000,0xfffe0000,0xffffffff,0x3fffffff, 	// sra op
		 0x1000000,0x20000,1,0x7fffffff, 0x1ffffff,			// srl op
		 0,1,0,0,1,							// slt op
		 1,0,1,1,0							// sltu op
	}; 
      for (int i  = 0; i < 50; i++) {
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
  std::unique_ptr<EXU> exu(new EXU());

  exu->OpenTrace("exu_test.vcd");

  exu->Reset();
  exu->sim();

  exit(0);
}
