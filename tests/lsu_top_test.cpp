

#include <iostream>

#include "Vlsu_top.h"
#include "testbench.h"

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
#define INST_2 0x00b57063  // bleu  a1,a0,c8 (a1 = 1, a0 = 0) 
#define INST_3 0x00112223  // sw    ra,4(sp) (sp = -272)
#define INST_4 0x00412083  // lw    ra,4(sp) (sp = -272)
#define INST_5 0x80028293  // addi  t0,t0, -2048
#define INST_6 0x00a78023  // sb    a0, 0(a5)

#define TOTAL_TESTS 6

using namespace std;

class LSU_test: public Testbench<Vlsu_top> {
  public:
    // -----------------------------------------------------------------------------
    // Testbench constructor
    LSU_test(double frequency=1e6, double timescale=1e-9): Testbench(frequency, timescale) {}


    int sim(unsigned long max_time=1000000){
	Reset();

	unsigned int writing[6][8] = {
		{  0, 0xfffffff1, 0, 1, 0, 0, 1, 0 },       
		{  4, 0xfffffff2, 0, 1, 0, 0, 1, 0 },       
		{  8, 0xff00ff00, 0, 1, 0, 0, 1, 0 },       
		{ 12, 0xf0f0f0f0, 0, 1, 0, 0, 1, 0 },      
	        { 16, 0x11111111, 0, 1, 0, 0, 1, 0 },
		{ 20,       0x11, 0, 1, 1, 0, 0, 0 }
	};	

	unsigned int reading[6][8] = {
		{  0, 0, 1, 0, 0, 0, 1, 0 },       
		{  4, 0, 1, 0, 0, 0, 1, 0 },       
		{  8, 0, 1, 0, 0, 0, 1, 0 },       
		{ 12, 0, 1, 0, 0, 0, 1, 0 },      
	        { 16, 0, 1, 0, 0, 0, 1, 0 },
		{ 20, 0, 1, 0, 1, 0, 0, 0 }

	};
	unsigned int data_o [6] = {
		0xfffffff1,
		0xfffffff2,
		0xff00ff00,
		0xf0f0f0f0,
		0x11111111,
		0x11
	}; 
	int ok = 0; 

	//writing test
	for (int i = 0; i < 6; ++i) {
		m_core->maddr_i   = writing[i][0];
		m_core->mdat_i    = writing[i][1];
		m_core->mread     = writing[i][2];
		m_core->mwrite    = writing[i][3];
		m_core->mbyte     = writing[i][4];
		m_core->mhw       = writing[i][5];
		m_core->mword     = writing[i][6];
		m_core->munsigned = writing[i][7];
		
		Tick(); 
		/*for( ok = 0; ok < 10; ++ok){
			if(m_core->dat_o == INST_1)
			       break; 	
			Tick();
		}*/
		while(m_core->mem_stall) Tick();
		Tick();
	}

	for (int i = 0; i < 6; ++i) {
		m_core->maddr_i   = reading[i][0];
		m_core->mdat_i    = reading[i][1];
		m_core->mread     = reading[i][2];
		m_core->mwrite    = reading[i][3];
		m_core->mbyte     = reading[i][4];
		m_core->mhw       = reading[i][5];
		m_core->mword     = reading[i][6];
		m_core->munsigned = reading[i][7];
		
		Tick();	

		while(m_core->mem_stall) Tick();
		Tick();
		if (m_core->dat_o == data_o[i])
			++ok; 
		else 
			break;	
	}
	Tick();
	if (ok == 6)
		printf("TEST PASSED !!\n"); 
	else 
		printf("TEST FAILED !!\n");
    }
};


int main(int argc, char **argv, char **env) {
  std::unique_ptr<LSU_test> lsu(new LSU_test());

  lsu->OpenTrace("lsu_top_test.vcd");
  lsu->sim();
  exit(0);
}
