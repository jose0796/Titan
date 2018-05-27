/*
* ALU Module - TestBench
* Anderson Contreras
*/


#include <iostream>

#include "Vexu.h"
#include "testbench.h"


#define OK_COLOR    "\033[0;32m"
#define ERROR_COLOR "\033[0;31m"
#define NO_COLOR    "\033[m"

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

class SIMULATIONTB: public Testbench<Vexu> {
  public:
    // -----------------------------------------------------------------------------
    // Testbench constructor
    SIMULATIONTB(double frequency=1e6, double timescale=1e-9): Testbench(frequency, timescale) {}

    int Simulate(unsigned long max_time=1000000){
      Reset();

      //|  port_a | port_b |    ALU OP  | Output |
      int data[TOTAL_TESTS][7] = {                      //           									
 	{          5,     6,   ALU_ADD,         11},    // 5 + 6 = 11                     
        {        -20,     5,   ALU_ADD,        -15},    // -20 + 5 = -15                 
        {       -187,   187,   ALU_ADD,          0},    // -187 + 187 = 0               
        {          4,     3,   ALU_SUB,          1},    // 4 - 3 = 1                    
        {        -23,  -127,   ALU_SUB,        104},    // -23 - (-127) = 104           
        {         -1,     0,   ALU_SUB,         -1},    // -1 - 0 = -1                 
        {        120,   245,   ALU_AND,        112},    // 245 & 120 = 112                
        {        540,   540,   ALU_AND,        540},    // 540 & 540 = 540               
        {        100,    50,   ALU_OR,         118},    // 100 | 50 = 118              
        {          0,     0,   ALU_OR,           0},    // 0 | 0 = 0                      
        {        573,   215,   ALU_XOR,        746},    // 573 ^ 215 = 746                
        {       4500,  4500,   ALU_XOR,          0},    // 4500 ^ 4500 = 0                
        {       1024,     3,   ALU_SRL,        128},    // 1024 >> 4 = 128                
        {-2147483648,     5,   ALU_SRL,   67108864},    // -2147483648 >> 5 = 67108864 
        {-2147483648,     5,   ALU_SRA,  -67108864},    // -2147483648 >> 5 = -67108864   
        {       2048,     1,   ALU_SRA,       1024},    // 2048 >> 1 = 1024               
        {         64,     5,   ALU_SLL,       2048},    // 64 << 5 = 2048                 
        {         -2,     1,   ALU_SLL,         -4},    // -2 << 1 = -4                
        {          1,    10,   ALU_SLT,          1},    // 1 < 10 = true                  
        {         20,    10,   ALU_SLT,          0},    // 20 < 10 = false              
        {        -20,   -10,   ALU_SLT,          1},    // -20 < -10 = true               
        {         50,   800,   ALU_SLTU,         1},    // 50 < 800 = true (Unsigned)     
        {         30,    20,   ALU_SLTU,         0},    // 30 < 20 = false (Unsigned)     
        {        100,  -200,   ALU_SLTU,         1}};   // 100 < -200 = true (Unsigned)  

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
