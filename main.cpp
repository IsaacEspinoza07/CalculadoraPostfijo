#include <iostream>
#include "Pila.hpp"
#include "Expresion.hpp"

using namespace std;

int main()
{
    /*
    Por testear para funcionamiento de TemplatePilaEnlazada:
    - [x] Agregar()
    - [x] Eliminar()
    - [x] ObtenerTope()
    - [x] ObtenerTam()
    - [x] EstaVacia()
    - [x] Vaciar()
    - [x] Imprimir()

    - [x] Excepción de la clase

    - [x] DIFERENTES TIPOS DE DATO

    */
    try{
        Expresion e;
        e.Capturar();

        cout << "Infijo: "; e.ImprimirInfijo(); cout << endl;
        e.APostfijo();
        cout << "Postfijo: "; e.ImprimirPostfijo(); cout << endl;
        //    {[(a+b)*c]^2/(d-c)}*(a-b)
        cout << e.Evaluar();

    }catch(const char* error){
        cerr << "Error: " << error << endl;
    }

    return 0;
}
