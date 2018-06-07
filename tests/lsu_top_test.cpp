

#include <iostream>

#include "Vlsu_top.h"
#include "testbench.h"

#define ts 8

using namespace std;

class LSU_test: public Testbench<Vlsu_top> {
  public:
    
    LSU_test(double frequency=1e6, double timescale=1e-9): Testbench(frequency, timescale) {}


    int sim(unsigned long max_time=1000000){
	Reset();

	unsigned int writing[ts][8] = {
		{  0, 0xfffffff1, 0, 1, 0, 0, 1, 0 },       
		{  4, 0xfffffff2, 0, 1, 0, 0, 1, 0 },       
		{  8, 0xff00ff00, 0, 1, 0, 0, 1, 0 },       
		{ 12, 0xf0f0f0f0, 0, 1, 0, 0, 1, 0 },      
	        { 16, 0x22222222, 0, 1, 0, 0, 1, 0 },
		{ 20,       0x11, 0, 1, 1, 0, 0, 0 },
		{ 24, 	    0x0c, 0, 1, 1, 0, 0, 0 },
		{ 28, 0x00ff00ff, 0, 1, 0, 0, 1, 0 }
	};	

	unsigned int reading[ts][8] = {
		{  0, 0, 1, 0, 0, 0, 1, 0 },       
		{  4, 0, 1, 0, 0, 0, 1, 0 },       
		{  8, 0, 1, 0, 0, 0, 1, 0 },       
		{ 12, 0, 1, 0, 0, 0, 1, 0 },      
	        { 16, 0, 1, 0, 0, 0, 1, 0 },
		{ 20, 0, 1, 0, 1, 0, 0, 0 },
		{ 24, 0, 1, 0, 1, 0, 0, 0 },
		{ 28, 0, 1, 0, 0, 0, 1, 0 }

	};
	unsigned int data_o [ts] = {
		0xfffffff1,
		0xfffffff2,
		0xff00ff00,
		0xf0f0f0f0,
		0x22222222,
		0x11, 
		0x0c,
		0x00ff00ff
	}; 
	int ok = 0; 

	//writing test
	for (int i = 0; i < ts; ++i) {
		m_core->maddr_i   = writing[i][0];
		m_core->mdat_i    = writing[i][1];
		m_core->mread     = writing[i][2];
		m_core->mwrite    = writing[i][3];
		m_core->mbyte     = writing[i][4];
		m_core->mhw       = writing[i][5];
		m_core->mword     = writing[i][6];
		m_core->munsigned = writing[i][7];
		
		Tick(); 
		while(m_core->mem_stall) Tick();
		Tick();
	}

	for (int i = 0; i < ts; ++i) {
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
	if (ok == ts)
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
