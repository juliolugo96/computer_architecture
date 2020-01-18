#ifndef PIPELINE_H
#define PIPELINE_H

#include "pipe.h"

template <class DataType>
class Pipe_line : public sc_module
{
private:
	Pipe<DataType> *pipe1, *pipe2, *pipe3;
	sc_signal<DataType> pipe1_sg, pipe2_sg, pipe3_sg;

public:
	sc_in<bool> en_in, clk_in;
	sc_in<DataType> data_in;
	sc_out<DataType> data_out;

	SC_CTOR(Pipe_line)
	{
		pipe1 = new Pipe<DataType>("pipe1");
		pipe2 = new Pipe<DataType>("pipe2");
		pipe3 = new Pipe<DataType>("pipe3");

		pipe1->data_in(this->data_in);
		pipe1->data_out(pipe1_sg);
		pipe1->clk_in(clk_in);
		pipe1->en_in(en_in);

		pipe2->data_in(pipe1_sg);
		pipe2->data_out(pipe2_sg);
		pipe2->clk_in(clk_in);
		pipe2->en_in(en_in);

		pipe3->data_in(pipe2_sg);
		pipe3->data_out(this->data_out);
		pipe3->clk_in(clk_in);
		pipe3->en_in(en_in);
	}
};

#endif//PIPELINE_H