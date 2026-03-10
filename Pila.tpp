#include <exception>
#include <iostream>
using std::cout;
using std::endl;

// ******** CONSTRUCTORES ******** //
template<typename T>
Pila<T>::Pila(): num_elem(0), tope(nullptr){}

template<typename T>
Pila<T>::~Pila()
{
    Vaciar();
}

template<typename T>
Pila<T>::Pila(const Pila<T>& p): num_elem(0), tope(nullptr)
{
    *this = p;
}

template<typename T>
Pila<T>& Pila<T>::operator=(const Pila<T>& p)
{
    // 1. Evitar auto-asignación
    if (this == &p) return *this;

    // 2. Limpiar la memoria actual
    this->Vaciar();

    Pila pilaAux;
    Elemento *visitado = p.tope;
    // Ciclo pa voltear los elementos por primera vez
    while(visitado != nullptr){
        pilaAux.Agregar(visitado->valor);
        visitado = visitado->siguiente;
    }

    // Ya estan volteados, ahora los des-volteamos agregandolos al que QUERIAMOS copiar originalmente
    visitado = pilaAux.tope;
    while(visitado != nullptr){
        this->Agregar(visitado->valor);
        visitado = visitado->siguiente;
    }

    return *this;
}


// **************** MÉTODOS **************** //
template<typename T>
void Pila<T>::Agregar(T n)
{
    try{
        Elemento *nuevo = new Elemento(n,tope);
        tope = nuevo; // Conectamos la pila al nuevo elemento

        ++num_elem;

    }catch(std::bad_alloc &){
        // TODO: LANZAR UNA EXCEPCIÓN PROPIA DE LA PILA
        throw "Se acabo la memoria";
    }

}
// ***************************************** //
template<typename T>
void Pila<T>::Eliminar()
{
    if(EstaVacia()) throw "La pila esta vac\242a"; // TODO: excepción propia de la pila
    Elemento *temp = tope;
    tope = tope->siguiente;
    delete temp;
    --num_elem;
}
// ***************************************** //
template<typename T>
T Pila<T>::ObtenerTope() const
{
    if(EstaVacia()) throw "La pila esta vac\242a"; // TODO: excepción propia de la pila
    return tope->valor;
}
// ***************************************** //
template<typename T>
int Pila<T>::ObtenerTam() const
{
    return num_elem;
}
// ***************************************** //
template<typename T>
bool Pila<T>::EstaVacia() const
{
    return (tope == nullptr);
}
// ***************************************** //
template<typename T>
void Pila<T>::Vaciar()
{
    while( !EstaVacia() ) Eliminar();
}
// ***************************************** //
template<typename T>
void Pila<T>::Imprimir() const
{
    Elemento *PunteroExploradorImprimidorDeValores = tope;

    cout << "Tope-> ";

    while (PunteroExploradorImprimidorDeValores != nullptr){

        cout << PunteroExploradorImprimidorDeValores->valor << ", ";
        PunteroExploradorImprimidorDeValores = PunteroExploradorImprimidorDeValores->siguiente;
    }
    if( !EstaVacia() ) cout << "\b\b ";
}
// ***************************************** //

// Constructor perron para los elementos
template<typename T>
Pila<T>::Elemento::Elemento(T n, Elemento *sig/*= nullptr*/): valor(n), siguiente(sig) {}

// ***************************************** //





