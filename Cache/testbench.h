#ifndef TESTBENCH_H
#define TESTBENCH_H

#include <systemc.h>
#include <iostream>

using namespace std;

SC_MODULE(testbench) {
	sc_in <sc_uint<32> > data_out;
	sc_out<sc_uint<32> > data_in;
	sc_out<sc_uint<4> > dir;

	sc_in<bool> clk;
	sc_out<bool> enable;

	void test() {
		// ... Antes de siquiera dar valores, se ejecuta todo lo que sea sensible
		// al clock en la posición 0, (en éste caso, la operación read de la cache)

		cout << "en la impresión de atrás, el clock estuvo en: " << clk.read() << "\n"; // 0
		
		// dejamos el enable en 1 porque sí xd
		// pueden cambiarlo para ver cómo se comporta si desean
		// (simplemente, al estar en 0, no dejará que se escriba nada en memoria)
		// REPASANDO: el enable sirve para PERMITIR o DENEGAR
		// la escritura en caso de que se desee escribir ...
		// ... en caso de leer, el enable no tiene una función
		enable = 1; // equivalente a: enable.write(1);


		// Preparamos los datos para la escritura
		dir = 4; // en la localidad de memoria 4 ...
		data_in = 1; // se escribirá el número 1 en binario
		wait();

		cout << "en la impresión de atrás, el clock estuvo en: " << clk.read() << "\n"; // 1
		
		// Lo siguiente es lectura, así que no se escribirá lo siguiente
		dir = 3; // en la localidad de memoria 3 ...
		data_in = 1234; // NO se escribirá el número 1234 en binario
					// más bien, se leerá lo que hay en la localidad de memoria 3
		wait();
		
		cout << "en la impresión de atrás, el clock estuvo en: " << clk.read() << "\n"; // 0

		dir = 0; // en la localidad de memoria 0 ...
		data_in = 412; // se escribirá el número 412 en binario
					// más bien, se leerá lo que hay en la localidad de memoria 0
		wait();
		
		cout << "en la impresión de atrás, el clock estuvo en: " << clk.read() << "\n"; // 1

		dir = 0; // en la localidad de memoria 0 ...
		data_in = 44; // NO se escribirá el número 44 en binario
					// más bien, se leerá lo que hay en la localidad de memoria 0
		wait();
		
		cout << "en la impresión de atrás, el clock estuvo en: " << clk.read() << "\n"; // 0

		sc_stop();
	}

	SC_CTOR(testbench) {
		cout << "\n\n";
		SC_THREAD(test);
		sensitive << clk;
	}
};

#endif//TESTBENCH_H
