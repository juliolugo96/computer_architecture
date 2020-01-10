#include <fstream>
#include <string>

using namespace std;

#ifndef HALF_ADDER
#define HALF_ADDER

#define MI_filename "inst.txt"

SC_MODULE (fetch) {
  ifstream MI;
  sc_in<bool> clk, connection;
  sc_out< sc_uint<14> > instruction;

  void Fetch() {
    string line;
    getline(MI,line);
    sc_uint<14> temp;
    for (int i = 0; i < 14; ++i)
      temp[i] = line[14-(i+1)]-'0';
    instruction = temp;
  }

  SC_CTOR (fetch) {
    MI.open(MI_filename);
    SC_METHOD(Fetch);
    sensitive<<clk.neg();
  }

  ~fetch() {
    MI.close();
  }
};

#endif//HALF_ADDER
