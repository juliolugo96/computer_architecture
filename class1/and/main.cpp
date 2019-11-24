#include "testbench.h"
#include "and_gate.h"

int sc_main(int argc, char* argv[]){
	sc_time PERIOD(10,SC_NS);//SC_PS SC_SEC . . .	
	sc_time DELAY(10,SC_NS);	
	sc_clock clock("clock",PERIOD,0.5,DELAY,true);

	and_gate ag1("ag1");
	Testbench tb("tb");

	sc_signal<bool> a_sg,b_sg,c_sg; //los cables

	ag1.a_in(a_sg);
	ag1.b_in(b_sg);
	ag1.c_out(c_sg);

	tb.clk_in(clock);  //las conecciones
	tb.a_out(a_sg);
	tb.b_out(b_sg);
	tb.c_in(c_sg);

	sc_start();

	return 0;
}
