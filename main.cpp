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

        e.ImprimirInfijo();
        e.APostfijo();
        e.ImprimirPostfijo();
        //    {[(a+b)*c]^2/(d-c)}*(a-b)

    }catch(const char* error){
        cerr << "Error: " << error << endl;
    }

    return 0;
}
