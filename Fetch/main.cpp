#include <systemc.h>
#include <string>

#include "fetch.h"
#include "testbench.h"


int sc_main(int argv, char* argc[]) {
  sc_time PERIOD(10,SC_NS);
  sc_time DELAY(10,SC_NS);
  sc_clock clock("clock",PERIOD,0.5,DELAY,true);

  fetch ft("fetch");
  testbench tb("tb");

  sc_signal< sc_uint<14> > instruction_sg;
  sc_signal<bool> connection_sg;

  ft.instruction(instruction_sg);
  ft.clk(clock);
	ft.connection(connection_sg);

  tb.instruction(instruction_sg);
  tb.clk(clock);
  tb.connection(connection_sg);

  sc_start();
  return 0;
}
