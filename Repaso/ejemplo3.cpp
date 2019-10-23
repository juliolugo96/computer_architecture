/*!
 * @file ejemplo3.cpp
 * @author Luis Adolfo Ramírez
 * @date 23/10/2019
 *
 * @brief Ejemplo sobre manejo de archivos
*/

#include <iostream>
#include <fstream>

/**
 * La biblioteca #include <fstream> nos facilita el manejo de
 * archivos con el uso de clases ifstream, ofstream y fstream.
*/

using namespace std;

string file_name = "archivo.txt";

void escribir () {
    /// Con la clase ofstream manejamos un archivo en modo de ESCRITURA
    ofstream arch_out;
    /// Podemos usar la función miembro "open" de la clase ofstream para "abrir" un archivo
    arch_out.open(file_name);
    
    string s1 = "Había una vez un barquito chiquitito...";
    
    /// El operador << funciona básicamente como el operador << de cout para "imprimir"
    arch_out << s1 << "\n";
    arch_out << "Si lees ésto, es porque lo estás leyendo\n";
    arch_out << 123456;
    arch_out << "\n";
    arch_out.close();

    /**
     * También puedes usar la clase fstream la cual puede leer y escribir
     * Y le especificamos que abriremos el archivo en modo escritura con el
     * parámetro ios::out, además del parámetro ios::app para concatenar (añadir)
     * más texto en vez de sobreescribir...
     * Cuando se le pasan varios atributos de modo de lectura, se deben
     * combinar haciendo el uso del operador binario |
    */

    fstream arch;
    arch.open(file_name, ios::out | ios::app);
    arch << "Una nueva línea de texto concatenada a todo el texto anterior\n"
         << "Cabe destacar que al leer archivos, se suelen perder los espacios y los saltos de línea si no se sabe manipular bien la entrada\n";
         ;
    arch.close();
}
/**
 * Comento... Cuando se realiza una lectura por caracteres,
 * se leerá caracter por caracter (OBVIO), pero hay "caracteres"
 * que no caben en un solo "char" como las vocales con tildes
 * así que al leer caracter por acacter, verás que se imprimirán
 * "cosas raras"
 * ... Si quieres saber más sobre ésto, puedes preguntar en clase
*/
void leer_por_caracter () {
    /**
     * Con la clase ifstream manejamos un archivo en modo de LECTURA
     * Por defecto, al abrirlo, escribiremos sobre él y todo lo que
     * tenía guardado, será eliminado a menos que el archivo se abra
     * en modo de concatenación con el parámetro ios::app
    */
    ifstream arch_in;
    /// Puedes hacer uso de la función "open" para "abrir" un archivo
    arch_in.open(file_name);

    char c;
    arch_in >> c;
    while (!arch_in.eof()) {
        cout << c << "\n";
        arch_in >> c;
    }

    /**
     * Por favor no se les olvide nunca cerrar un archivo luego de abrirlo
     * Es muy importante por temas de seguridad y para evitar errores
    */

    arch_in.close();
}

void leer_por_string () {
    /**
     * En vez de usar la función open, pueden
     * hacer uso del constructor por parámetros
    */
    ifstream arch_in(file_name);

    string s;
    arch_in >> s;
    while (!arch_in.eof()) {
        cout << s << "\n";
        arch_in >> s;
    }

    arch_in.close();
}

void leer_por_linea () {
    /**
     * También puedes usar la clase fstream la cual puede leer y escribir
     * Y le especificamos que abriremos el archivo en modo lectura con el
     * parámetro ios::in
    */
    fstream arch_in(file_name, ios::in);
    string s;
    while (!arch_in.eof()) {
        getline(arch_in,s);
        cout << s << "\n";
    }

    arch_in.close();
}

void leer_de_golpe () {
    ifstream arch_in(file_name);

    /**
     * Si solo quieren mostrar el contenido del archivo,
     * pueden hacer lo siguiente
    */

    cout << arch_in.rdbuf() << "\n";

    /**
     * La función rdbuf() retorna un puntero al inicio de la cadena
     * de texto de todo el archivo. Por lo cual pueden imprimir
     * todo el texto con solo esa línea de código
    */

    arch_in.close();
}

int main() {
    
    escribir();
    leer_por_caracter();
    leer_por_string();
    leer_por_linea();
    leer_de_golpe();

    return 0;
}