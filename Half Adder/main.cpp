#include <systemc.h>
#include <half_adder.h>
#include <testbench.h>

int sc_main(int argv, char* argc[]) {
  sc_time PERIOD(10,SC_NS);
  sc_time DELAY(10,SC_NS);
  sc_clock clock("clock",PERIOD,0.5,DELAY,true);

  hadd ha("ha");
  testbench tb("tb");

  sc_signal<bool> a_sg,b_sg,c_sg,s_sg;

  ha.a(a_sg);
  ha.b(b_sg);
  ha.c(c_sg);
  ha.s(s_sg);

  tb.a(a_sg);
  tb.b(b_sg);
  tb.c(c_sg);
  tb.s(s_sg);

  ha.clk(clock);
  tb.clk(clock);

  sc_start();
  return 0;
}
