/** \file Pila.hpp
 *
 * \author Isaac Espinoza Hern&aacute;ndez,
 * David Armando Angulo Gil
 *
 * \date 10/03/2026
 * \code {.cpp}
 * int main()
{
    // Aqui probamos la Pila pero con ENTEROS
    cout << "Pila de enteros: " << endl;
    try {
        Pila<int> p;
        for(int i = 0; i < 15; ++i){
            p.Agregar(i);
        }
        p.Imprimir();
        cout << p.ObtenerCapacidad() << endl;
        p.Agregar(67);
        cout << p.ObtenerCapacidad() << endl;
        for(int i = 0; i < 15; ++i){
            p.Agregar(i);
        }
        cout << p.ObtenerCapacidad();

        return 0;




    } catch (const char *error) { // Este cacha el p.agregar().
        cerr << "Error: " << error << endl;
    } catch (Pila<int>::PilaVacia &error) { // Este cacha la clase PilaVacia
        cerr << "Error: " << error.what() << endl;
    } catch (...) {
        cerr << "Ocurri\242 un error inesperado" << endl;
    }
    cout << endl;

    return 0;
 *  }
 * \endcode
 */
#ifndef EXPRESION_HPP_INCLUDED
#define EXPRESION_HPP_INCLUDED

#include <string>
using std::string;

class Expresion{
public:
    Expresion();
    Expresion(std::string exp_infijo);
    bool EsValida();
    // Para capturar en infijo
    void Capturar();
    void ImprimirInfijo();
    void ImprimirPostfijo();

    double Evaluar();


    class ExpresionInvalida : public std::exception
    {
    public:
        ExpresionInvalida(const char *msg) noexcept;
        virtual const char *what() const noexcept;
    private:
        const char *mensaje;
    };

private:
    std::string exp_infijo;
    std::string exp_postfijo;
    // Para dada una en postfijo, pasarla a infijo
    void APostfijo();
    bool valida;

    int Precedencia(const char a);


};

#endif // EXPRESION_HPP_INCLUDED
