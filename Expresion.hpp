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
    Expresion Capturar();

    // Para dada una en postfijo, pasarla a infijo
    // Publica para que tambien se pueda meter directamente una en postfijo
    void APostfijo();

    void ImprimirInfijo();
    void ImprimirPostfijo();

    float Evaluar();

    /*
    Flujo:
    1- Capturar -> APostfijo -> guardar en atributo

    2- Evaluar (usando pilas)

    Listo!
    */



private:
    std::string exp_infijo;
    std::string exp_postfijo;
    bool valida;

    int Precedencia(const char a);

};

#endif // EXPRESION_HPP_INCLUDED
