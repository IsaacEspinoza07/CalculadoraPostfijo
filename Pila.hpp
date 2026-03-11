/** \file Pila.hpp
 *
 * \author Isaac Espinoza Hern&aacute;ndez,
 * David Armando Angulo Gil
 *
 * \date 10/03/2026
 * \code {.cpp}
 * int main()
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

 *  }
 * \endcode
 */
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
        /** \brief Constructor de la clase
         * \return Nada
         *
         */
        Pila();
        /** \brief Destructor de la clase
         * \return Nada
         *
         */
        ~Pila();
        /** \brief Constructor de Copias
         *
         * \param Pila a copiar
         *
         * \return Nada
         */
        Pila(const Pila& p);
        /** \brief Operador de asignaci&oacute;n para las pilas
         *
         * \tparam T Tipo de los elementos de la pila
         * \param Pila para copiar con el operador de asignaci&oacute;n
         * \return Pila copiada
         *
         */
        Pila& operator=(const Pila& p);

        // ==== MÉTODOS DE LA CLASE ==== //

        /** \brief Funci&oacute;n para agregarle alg &uacute;n elemento en el tope de la pila
         *
         * \tparam T Tipo de los elementos de la pila
         * \param Valor a agregar a la pila
         * \return Nada
         *
         */
        void Agregar(T n);

        /** \brief Funci&oacute;n para eliminar el elemento del tope de la pila
         *
         * \return Nada
         *
         * \warning Advertencias que puede lanzar: Pila Vac&iacute;a
         * \throw Pila Vac&iacute;a: Advertencia lanzada al querer interactuar con los elementos de una pila vac&iacute;a
         */
        void Eliminar();

        /** \brief Funci&oacute;n que le dice al usuario el elemento en el tope de la pila
         *
         * \tparam T Tipo de los elementos de la pila
         * \return Valor encontrado en el tope
         *
         * \warning Advertencias que puede lanzar: Pila Vac&iacute;a
         * \throw Pila Vac&iacute;a: Advertencia lanzada al querer interactuar con los elementos de una pila vac&iacute;a
         */
        T ObtenerTope() const;

        /** \brief Funci&oacute;n que devuelve el tama&ntilde;o entero de la pila
         *
         * \return N &uacute;mero de elementos en la pila
         *
         */
        int ObtenerTam() const;

        /** \brief Funci&oacute;n para conocer si la pila se encuentra vac&iacute;a
         *
         * \return Si la pila se encuentra vac&iacute;a o no
         *
         */
        bool EstaVacia() const;

         /** \brief Funci&oacute;n que le permite al usuario vac&iacute;ar la pila
         *
         * \return Nada
         *
         */
        void Vaciar();

        /** \brief Funci&oacute;n que permite imprimir la Pila
         *
         * \return Nada
         *
         */
        void Imprimir() const;

        /** \brief Clase para las excepciones del tipo "Pila Vac&iacute;a"
         */
        class PilaVacia : public std::exception
        {
          public:
            /** \brief Constructor de la subclase pila vac&iacute;a
             *
             * \return Nada
             *
             */
            PilaVacia() noexcept; // así le digo que PilaVacia() NO lanza
                                  // excepciones
            /** \brief Funci&oacute;n para lanzar una excepci&oacute;n para cuando la pila este vac&iacute;a
             *
             * \return Excepci&oacute;n lanzada
             *
             */
            virtual const char *what() const noexcept;
          private:
            const char *mensaje;
        };

    private:
        int num_elem;

        /** \brief Estructura para definir cada elemento en la pila
         */
        struct Elemento{
            T valor;
            Elemento *siguiente;
            /** \brief Constructor de la estructura elemento
             *
             * \return Nada
             *
             */
            Elemento(T n, Elemento *sig = nullptr);

        }*tope; // Declarar tope. ...} *tope = Elemento *tope;

};

#include "Pila.tpp"

#endif // PILA_HPP
