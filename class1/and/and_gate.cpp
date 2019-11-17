#include "and_gate.h"
//And_Gate g1("g1");
//metodos del modulo And_Gate

void and_gate::operation(){ //declaracion de la operacion(proceso) privada de 
		//.write() escribe valores sobrelos puertos de
		//salida o entrada-salida
		//.read() lee valores de cualquier puerto
		c_out.write( a_in.read() and  b_in.read() ); // lee los valores de los puertos de entrada
																								//a_in y b_in identificadores
}



