#ifndef TESTBENCH
#define TESTBENCH

#include <iomanip>

#include "macros.h"

SC_MODULE(testbench) {
  sc_out<bool> connection;
  sc_in< sc_uint<14> > instruction;
  sc_in<bool> clk;

  void print() {
    cout << "\t\t  ";
    
    for (int i = 0; i < 14; ++i)
      cout << instruction.read().range(14-(i+1),14-(i+1));
    cout << "  | " << setw(5) << instruction.read() << " | " << clk.read() << "\n";
  }
  void test() {
    cout << "\n"
         << "\t\t Instruction(BIN) | (DEC) | CLK\n"
         << "\t\t-----------------------------------\n";

    for (int i = 0; i < INSTRUCTIONS; ++i) {
      wait();
      print();
    }
    

    sc_stop();
  }

  SC_CTOR(testbench) {
      SC_THREAD(test);
      sensitive<<clk.neg();
  }
};

#endif//TESTBENCH
