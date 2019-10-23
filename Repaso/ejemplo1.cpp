/*!
 * @file ejemplo1.cpp
 * @author Luis Adolfo Ramírez
 * @date 23/10/2019
 *
 * @brief Repaso sobre el uso de clases y ejemplo sencillo sobre composición
*/

#include <iostream>

using namespace std;

/**
 * Aclaración: No confundan éste ejemplo con la prueba
 * diagnóstica que se les realizó.
*/

class Cabeza {
public:
    /**
     * La siguiente función es el constructor de la clase, la cual se ejecuta
     * al momento de declarar una instancia de la clase (o para ser más sencillos,
     * cuando creas una variable como aquí: " Cabeza C; ")
     * En ese ejemplo, C es una variable de tipo Cabeza; y cuando se creó la variable C,
     * se ejecutó la función constructora por defecto "Cabeza()"
     *
     * Éste tipo de constructor en específico es el constructor por defecto,
     * el cual no recibe parámetros
     *
     * Es de suma importancia que cada constructor que crees sea público,
     * porque sino, no se pueden llamar. Lógico, no?
    */

    /* Como ven, es un constructor por defecto y no tiene parámetros dentro de los paréntesis "()" */
    Cabeza() {
        /**
         * Para entender mejor cuándo se ejecuta la función constructora,
         * presten atención cuando se vea el siguiente texto en la terminal
        */
        cout << "Cabeza creada\n";
    }
    /**
     * La siguiente función es el destructor de la clase, la cual se ejecuta
     * al momento que "muera" la clase (al momento de que la variable sea eliminada).
     *
     * Si no saben cuándo una función es eliminada, por facilidad de la explicación, pregunten en la clase.
    */
    ~Cabeza() {
        /**
         * Para entender mejor cuándo se ejecuta la función destructora,
         * presten atención cuando se vea el siguiente texto en la terminal.
        */
        cout << "Cabeza eliminada\n";
    }
};

class Tronco {
public:
    Tronco() {
        cout << "Tronco creado\n";
    }
    ~Tronco() {
        cout << "Tronco eliminado\n";
    }
};

class Extremidades {
public:
    Extremidades() {
        cout << "Extremidades creadas\n";
    }
    ~Extremidades() {
        cout << "Extremidades eliminadas\n";
    }
};

/**
 * A continuación verán de qué trata composición. Verán cómo la clase
 * Cuerpo se compone por las clases Cabeza, Tronco y Extremidades
*/

class Cuerpo {
    /**
     * Composición es un concepto muy sencillo, es básicamente declarar la instancia
     * de una clase dentro de otra.
     * Si no entendieron lo de arriba, es básicamente crear variables dentro de una clase...
     * ... variables que no son int o char por ejemplo, son clases...
     * en éste caso son las clases Cabeza, Tronco y Extremidades
     * Sencillo, no? 
    */
    Cabeza c;
    Tronco t;
    Extremidades e;

public:
    Cuerpo() {
        cout << "Cuerpo creado\n";
    }
    Cuerpo(string s) {
        cout << s << "\n";
    }
    ~Cuerpo() {
        cout << "Cuerpo eliminado\n";
    }
};

int main() {
    /**
     * Noten que al declarar una clase Cuerpo, estamos
     * declarando también las clases que la componen.
     *
     * PD: recuerden que "declarar" es simplemente "crear" una variable como a continuación.
    */
    Cuerpo c;
    return 0;
}

/**
 * Es importante aclarar que al final de la clase "main", todas las variables declaradas en todo el
 * código son destruídas para liberar memoria (excepto los punteros/apuntadores por seguridad)
*/