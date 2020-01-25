#include "pipeline.h"
#include "testbench.h"

int sc_main(int argc, char* argv[])
{
	sc_time PERIOD(10,SC_NS);
	sc_time DELAY(10,SC_NS);	
	sc_clock clock("clock",PERIOD,0.5,DELAY,true);

	Pipe_line < sc_uint<32> > pl("pl");
	Testbench < sc_uint<32> > tb("Tb");

	sc_signal< sc_uint<32> > data_in_sg, data_out_sg;
	sc_signal< bool > en_sg;

	pl.data_in(data_in_sg);
	pl.data_out(data_out_sg);
    pl.en_in(en_sg);
    pl.clk_in(clock);

	tb.clk_in(clock);

	tb.data_in(data_out_sg);
	tb.data_out(data_in_sg);
	tb.en_out(en_sg);

	sc_start();

return 0;
}