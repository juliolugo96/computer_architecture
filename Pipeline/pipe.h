#ifndef PIPE_H
#define PIPE_H

#include <systemc.h>
#include <iostream>

using namespace std;

template <class DataType>
class Pipe : public sc_module
{
public:
	sc_in <DataType> data_in;
	sc_in <bool> en_in, clk_in;
	sc_out <DataType> data_out;

	SC_CTOR(Pipe)
	{
		this->data = 0;
		SC_METHOD(write_operation);
		sensitive << clk_in << data_in << en_in;
		SC_METHOD(read_operation);
		sensitive << clk_in;
	}
	~Pipe(){}
private:
	DataType data;

	void write_operation()
	{

		if (!clk_in.read() and en_in.read())
			data = data_in;
	}
	void read_operation()
	{
		if (clk_in.read()){
			data_out = data;
		}
		cout.fill(' ');
		cout.width(10);
		cout << data << " | ";
	}
};

#endif//PIPE_H