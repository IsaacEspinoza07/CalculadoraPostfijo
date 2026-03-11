#include <iostream>
#include "Pila.hpp"
#include "Expresion.hpp"

using namespace std;

int main()
{
    try{
        Expresion e;
        cout << " === Calculadora (internamente en posfijo) ===\n\n";

        // 1- Capturación de INFIJO
        cout << "Capture una expresión en infijo: ";
        e.Capturar();

        // 2- Evaluar e imprimir.
        cout << "postifjo: "; e.ImprimirPostfijo(); cout <<endl;
        cout << e.Evaluar() << endl;




    }catch (Expresion::ExpresionInvalida &error) {
        cerr << "Error: " << error.what() << endl;

    }catch (Pila<double>::PilaVacia &error) { // Este cacha la clase PilaVacia
        cerr << "Error: " << error.what() << endl;

    }catch (Pila<char>::PilaVacia &error) { // Este cacha la clase PilaVacia
        cerr << "Error: " << error.what() << endl;

    }catch(const char* error){ // Cacha el Agregar()
        cerr << "Error: " << error << endl;

    }catch(...){
        cerr << "Ocurri\242 un error inesperado.";
    }

    return 0;
}
