#include <and.h>
#include <xor.h>

#ifndef HALF_ADDER
#define HALF_ADDER

SC_MODULE (hadd) {
  /*
    Así como pueden crear una puerta lógica en el main,
    pueden crearla aquí como un miembro de una clase,
    después de todo son tan solo una clase (un tipo de dato)
    y pueden componer ésta clase de otras, como hicieron en PR2.
  */

  And* ag;
  Xor* xg;
  sc_in<bool> a;
  sc_in<bool> b;
  sc_out<bool> c;
  sc_out<bool> s;

  /*
    La razón por la que creo las clases And y Xor como apuntadores es porque no
    podemos iniciar las clases con un constructor por parámetros al declarar los
    miembros de la clase y como And y Xor por seguridad no tienen constructores
    sin parámetros, declaramos mejor apuntadores y luego llamamos a los constructores

    ... ésto podría hacerse sin apuntadores, pero sería un rollo grandísimo, así que
    apliquen el principio KISS y usen apuntadores, pues es mucho más sencillo 😁👍
    ... aunque prefiero más escribir KIS (sin la s de "stupid" para no ofender a nadie)
  */

  ///Si no conocían el principio KISS, significa "Keep It Simple, Stupid!"

  SC_CTOR (hadd) {
    /*
      No sé si han usado apuntadores a clases, pero para usar la clase a través de un
      apuntador, lo que necesitan es apartar la memoria (se hace sencillamente usando new)
      de la clase que crearán (por ejemplo: And("aquicolocanloquesea") )
    */
    ag = new And("and_gate");
    ag->a(a);
    ag->b(b);
    ag->c(c);

    xg = new Xor("xor_gate");
    xg->a(a);
    xg->b(b);
    xg->c(s);

    /*
      Notarán que no he escrito "SC_METHOD(método)" porque ésta clase no hará uso de métodos,
      solo necesitará que conecten entradas y salidas 😁
    */
    /*
      Otra cosa importante a resaltar es que no usé señales (signals) y es porque no hizo falta...
      En clase les mostraré cuándo hay que usar señales
    */
  }

  ~hadd() {
    delete ag;
    delete xg;
  }
};

#endif//HALF_ADDER
