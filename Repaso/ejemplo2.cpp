/*!
 * @file ejemplo2.cpp
 * @author Luis Adolfo Ramírez
 * @date 23/10/2019
 *
 * @brief Ejemplo sencillo sobre herencia
*/

#include <iostream>

using namespace std;

/**
 * Aclaración: No confundan éste ejemplo con la prueba
 * diagnóstica que se les realizó.
*/

class Parte_del_cuerpo {
protected:
    string tipo;
public:
    string get_tipo() {
        return tipo;
    }
};

/**
 * La herencia es una manera de hacer que una clase "hija"
 * "herede" ciertas partes de una clase "padre"
 *
 * En éste caso, la clase Cabeza hereda de la clase Parte_del_cuerpo
 * ... Te preguntarás ¿Qué hereda?
 * Te respondo: luego de declarar la clase Cabeza, te mostraré qué es lo que hereda
*/

class Cabeza : public Parte_del_cuerpo {
public:
    Cabeza() {
        tipo = "Cabeza";
    }
};

/**
 * Tú mismo verás qué está heredando la clase cabeza... Te mostraré el equivalente
 * a la clase Cabeza heredando de la clase Parte_del_cuerpo, pero sin herencia! 

    class Cabeza {
    protected:
        string tipo;
    public:
        Cabeza() {
            tipo = "Cabeza";
        }
        string get_tipo() {
            return tipo;
        }
    };

 * Ahora como ves, con la herencia (en éste caso pública), la clase Cabeza simplemente
 * obtiene todos los atributos o funciones "protected" y "public", pero los private
 * no se heredan, los private son inaccesibles desde la clase hija.
*/


class Tronco : public Parte_del_cuerpo {
public:
    Tronco() {
        tipo = "Tronco";
    }
};

class Extremidades : public Parte_del_cuerpo {
public:
    Extremidades() {
        tipo = "Extremidades";
    }

};
class Cuerpo {
public:
    Cabeza c;
    Tronco t;
    Extremidades e;
};

int main() {
    Cuerpo c;
    /**
     * Recuerden que la manera de acceder a un miembro público de una Clase
     * es usando el operador punto "."
     *
     * Es también importante recordar que si quieren acceder a un apuntador/puntero
     * en vez de usar el operador punto, deberán usar el operador flecha "->"
    */
    cout << c.c.get_tipo() << "\n";
    cout << c.t.get_tipo() << "\n";
    cout << c.e.get_tipo() << "\n";

    return 0;
}