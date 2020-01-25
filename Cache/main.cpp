#include "cache.h"
#include "testbench.h"

int sc_main(int argc, char* argv[])
{
	sc_time PERIOD(10,SC_NS);
	sc_time DELAY(10,SC_NS);
	sc_clock clock("clock",PERIOD,0.5,DELAY,true);

	cache ch("ch");
	testbench tb("tb");

	sc_signal< sc_uint<32> > data_in_sg, data_out_sg;
	sc_signal< sc_uint<4>  > dir_sg;
	sc_signal<bool> enable_sg;

	ch.data_in(data_in_sg);
	ch.dir(dir_sg);
	ch.data_out(data_out_sg);
	ch.enable(enable_sg);
	ch.clk(clock);
	
	tb.data_in(data_in_sg);
	tb.dir(dir_sg);
	tb.data_out(data_out_sg);
	tb.enable(enable_sg);
	tb.clk(clock);

	sc_start();

	return 0;
}
