#include <iostream>
#include "Pila.hpp"

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

        string prueba = "Hola Mundo";

        cout << prueba[5];


    }catch(const char* error){
        cerr << "Error: " << error << endl;
    }

    return 0;
}
