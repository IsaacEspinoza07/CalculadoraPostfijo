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

    // Para dada una en postfijo, pasarla a infijo
    // Publica para que tambien se pueda meter directamente una en postfijo
    void APostfijo();

    void ImprimirInfijo();
    void ImprimirPostfijo();

    double Evaluar();

    // TODO: Crear excepcion de la clase para cuando
    // se mete una expresión no valida..


private:
    std::string exp_infijo;
    std::string exp_postfijo;
    bool valida;

    int Precedencia(const char a);


};

#endif // EXPRESION_HPP_INCLUDED
