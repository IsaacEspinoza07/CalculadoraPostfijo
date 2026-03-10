#include "Expresion.hpp"

// ==== CONSTUCTORES ==== //

// Constructor vacio y no es valido
Expresion::Expresion(): exp_infijo(""), valida(false) {}

// Constructor con un argumento (entrada de la expresion)
Expresion::Expresion(std::string exp_infijo)
{
    this->exp_infijo = exp_infijo;
    //valida = (EsValida()) ? true : false;
}


/*
// ==== MÉTODOS DE LA CLASE ==== //

Expresion Expresion::Capturar()
{


}

// ========================== //
Expresion Expresion::APostfijo()
{


}

// ========================== //

void Expresion::ImprimirInfijo()
{


}

// ========================== //

void Expresion::ImprimirPostfijo()
{


}

// ========================== //

float Expresion::Evaluar()
{


}

// ========================== //

bool Expresion::EsValida()
{


}

*/
