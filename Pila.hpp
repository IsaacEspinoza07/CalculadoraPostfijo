#ifndef PILA_HPP
#define PILA_HPP

struct Elemento;
// Estructura de datos 1000% dinámica!!!
// Crece cuando se agregan, disminuye cuando se borran.
template<typename T>
class Pila
{
    public:
        // ==== CONSTRUCTORES ====//
        Pila();
        ~Pila();
        Pila(const Pila& p);
        Pila& operator=(const Pila& p);

        // ==== MÉTODOS DE LA CLASE ==== //

        void Agregar(T n);
        void Eliminar();
        T ObtenerTope() const;
        int ObtenerTam() const;
        bool EstaVacia() const;
        void Vaciar();
        void Imprimir() const;

        // TODO: Hacer una excepcion propia de la clase: "EstaVacia";

    private:
        int num_elem;

        struct Elemento{
            T valor;
            Elemento *siguiente;
            Elemento(T n, Elemento *sig = nullptr);

        }*tope; // Declarar tope. ...} *tope = Elemento *tope;

};

#include "Pila.tpp"

#endif // PILA_HPP
