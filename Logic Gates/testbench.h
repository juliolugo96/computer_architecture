/**
 * Éste testbench es igual al de la clase, solo que imprime más bonito y centrado ^^
*/

/**
 * UPDATE: solo sirve para las compuertas de 2 entradas y 1 salida...
 * hagan su propio testbench para probar las compuertas de 1 sola entrada o modifiquen éste ^^
*/

#ifndef TESTBENCH
#define TESTBENCH

SC_MODULE(testbench) {
	sc_out<bool> a;
	sc_out<bool> b;
	sc_in<bool> c;
	sc_in<bool> clk;

	void print() {
		cout << "\t\t" <<a.read() << " | " << b.read() << " | " << c.read() << " | " << clk.read() << "\n";
	}
	void test() {
		cout << "\n\t\tA | B | C | Clk\n";
		cout << "\t\t----------------\n";

		a.write(0);
		b.write(0);

		wait();
		print();

		a.write(0);
		b.write(1);

		wait();
		print();

		a.write(1);
		b.write(0);

		wait();
		print();

		a.write(1);
		b.write(1);

		wait();
		print();

		sc_stop();
	}

	SC_CTOR(testbench) {
		SC_THREAD(test);
		sensitive<<clk;
	}
};

#endif//TESTBENCH
