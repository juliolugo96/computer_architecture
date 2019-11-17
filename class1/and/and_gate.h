#ifndef AND_GATE_H
#define AND_GATE_H

#include <systemc.h>

class and_gate : public sc_module{	//Declaracion del modulo "class And_Gate" y heredamos 
																		//las funciones de sc_module
	public:
		sc_in<bool> a_in;		//puerto de entrada del modulo padre sc_in<T>
		sc_in<bool> b_in;		//puerta de entrada del modulo padre
		sc_out<bool> c_out;	//puerto de salida sc_out<T>

					//And_Gate();
		SC_CTOR(and_gate)
		{
			SC_METHOD(operation);		//este es el proceso (operacion)
			sensitive<<a_in<<b_in; //lista de sensibilidad (siempre debajo el proceso)
		}	//Constructor SystemC
		~and_gate(){};				//Destructor
	private:
		void operation();	// este es el proceso (no recibe ni retorna nada
											// es sencible a una lista de sensibilidad
};										// se activa cuando cualquiera de los parametros cambia
											//esta funcion se declara en el .cpp

#endif
