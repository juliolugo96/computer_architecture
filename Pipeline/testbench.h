#ifndef TESTBENCH_H
#define TESTBENCH_H

#include <systemc.h>
#include <iostream>

using namespace std;

template <class DataType>
class Testbench : public sc_module
{
private:
	void test()
    {
    	print();

        en_out = 1;
        data_out = 1234;

        wait();
        print();

        data_out.write(data_in.read());
        
        wait();
        print();

        data_out.write(data_in.read());

        wait();
        print();

        data_out.write(data_in.read());

        wait();
        print();

        data_out.write(data_in.read());

        wait();
        print();

        data_out.write(data_in.read());

        wait();
        print();

        data_out.write(data_in.read());

        wait();
        print();

        data_out.write(data_in.read());

        wait();
        print();

        data_out.write(data_in.read());

        wait();
        print();

        data_out.write(data_in.read());

        sc_stop();
    }
    
    void print()
    {
        cout << clk_in.read() << "       | "
			 << en_out.read() << "          |\n";
    }

public:
	sc_in<bool> clk_in;
	sc_out<bool> en_out;
	sc_out<DataType> data_out;
	sc_in<DataType> data_in;

	SC_CTOR(Testbench)
	{
        cout << "Pipe_1     | Pipe_2     | Pipe_3     | Tiempo  | Enable     |\n";
        cout << "------------------------------------------------------------|\n";
		SC_THREAD(test);
		sensitive << clk_in;
	}
};

#endif//TESTBENCH_H