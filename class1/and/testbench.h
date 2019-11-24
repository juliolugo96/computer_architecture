#ifndef TESTBENCH_H
#define TESTBENCH_H

#include <systemc.h>	//libreria systemc
#include <iostream>
using namespace std;
class Testbench : public sc_module{	

	public:	
		sc_in<bool> clk_in;	//variables de entrada (reloj)	(siempre de entraada)	
		sc_in<bool> c_in;	// por cada variables de salida del modulo hay una de
		sc_out<bool> a_out;	//entrada en el testbench 
		sc_out<bool> b_out;

		SC_CTOR(Testbench);	//construtor de modulo
		~Testbench();
	private:
		void test();
};

#endif
