#include <systemc.h>
#include <and.h>
#include <testbench.h>

int sc_main(int argv, char* argc[]) {
	sc_time PERIOD(10,SC_NS);
	sc_time DELAY(10,SC_NS);	
	sc_clock clock("clock",PERIOD,0.5,DELAY,true);

	And and1("and1");
	testbench tb("tb");

	sc_signal<bool> a_sg,b_sg,c_sg; 

	and1.a(a_sg);
	and1.b(b_sg);
	and1.c(c_sg);

	tb.a(a_sg);
	tb.b(b_sg);
	tb.c(c_sg);

	tb.clk(clock);

	sc_start();
	return 0;
}
