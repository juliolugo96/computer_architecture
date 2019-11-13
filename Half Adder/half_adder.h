#include <and.h>
#include <xor.h>

#ifndef HALF_ADDER
#define HALF_ADDER

SC_MODULE (hadd) {

  sc_in<bool> clk;
  sc_in<bool> a;
  sc_in<bool> b;
  sc_out<bool> c;
  sc_out<bool> s;

  And* ag;
  Xor* xg;

  void fun() {}

  SC_CTOR (hadd) {
    ag = new And("ag");
    ag->a(a);
    ag->b(b);
    ag->c(c);

    xg = new Xor("xg");
    xg->a(a);
    xg->b(b);
    xg->c(s);
  }

  ~hadd() {
    delete ag;
    delete xg;
  }
};

#endif//HALF_ADDER
