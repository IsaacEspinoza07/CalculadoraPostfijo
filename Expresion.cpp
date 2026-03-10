#include "Expresion.hpp"
#include "Pila.hpp"
#include <iostream>

using std::cout;

// ==== CONSTUCTORES ==== //

// Constructor vacio y no es valido
Expresion::Expresion(): exp_infijo(""), valida(false) {}

// Constructor con un argumento (entrada de la expresion)
Expresion::Expresion(string exp_infijo)
{
    this->exp_infijo = exp_infijo;
    //valida = (EsValida()) ? true : false;
}


/*
// ==== MÉTODOS DE LA CLASE ==== //

Expresion Expresion::Capturar()
{


}

*/

// ========================== //
void Expresion::APostfijo()
{
    Pila<char>  validacion, // A este solo le llegan los () [] {}
                conversion; // A este tanto ()[]{} como +-*/^
    bool ultimoOperando = false; // util para agregar los $

    string e = exp_infijo; // 'e' para facilitar su manejo

    // Esto reccorrera de izquierda a derecha.
    // Como nomás hay que dar una pasada, aqui sucedera todo (creo)
    for(int i = 0; i < (int)e.length(); ++i){
        char c = e[i];

        // Validación: asegurarme que meto (, [, { y luego ya checare }, ], )
        if(c == '(' || c == '[' || c == '{'){
            validacion.Agregar(c);
            conversion.Agregar(c);
        }
        else if(c == ')' || c == ']' || c == '}'){ // buscamos pa cerrar
            // buscamos el que le corresponde
            char otro;
            if(c == ')') otro = '(';
            if(c == ']') otro = '[';
            if(c == '}') otro = '{';

            // Si estaba en el tope...
            if(validacion.ObtenerTope() == otro){
                validacion.Eliminar();
            }
            else{
                this->valida = false;
                return;
            }

            // ahora vaciamos el de los operadores
            while(conversion.ObtenerTope() != otro){
                this->exp_postfijo += conversion.ObtenerTope();
                ultimoOperando = false;
                conversion.Eliminar();
            }
            conversion.Eliminar();


        }
        // elseif pa que no haga cosas cuando no debe. Checar todos los operadores.
        else if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^'){
            // Si hay algo en la conversion y NO es una apertura, vamos scando tood:
            // tambien, checamos procedencia.
            while(!conversion.EstaVacia() && conversion.ObtenerTope() != '(' && conversion.ObtenerTope() != '['
                                          && conversion.ObtenerTope() != '{' && Precedencia(conversion.ObtenerTope()) >= Precedencia(c)
                                          && !(c == '^' && conversion.ObtenerTope() == '^'))
            {
                this->exp_postfijo += conversion.ObtenerTope();
                ultimoOperando = false;
                conversion.Eliminar();

            }
            conversion.Agregar(c);

        }
        // aqui tenemos que ir agregando todo a la expresion postfijo
        // e ir agregando los separadores '$'
        else if(c != ' '){
            if(ultimoOperando) this->exp_postfijo += '$';
            this->exp_postfijo += c;
            ultimoOperando = true;
        }


        /*
        PARA DEBUGEAR O VER COMO SE VAN METIENDO
        CADA COSA A CADA PILA, DESCOMENTAR LO DE ABAJO, MUY INTERESANTE
        */

        /*
        // ===== IMPRESIONES DE VERIFICACIÓN ===== //
        cout << "\nValidación: "; validacion.Imprimir(); cout << endl;
        cout << "Conversion: "; conversion.Imprimir(); cout << endl;
        cout << "Salida: "; salida.Imprimir(); cout << endl << endl;
        */
    }

    // y por ultimo la validación:
    // primero, vaciamos todo lo de conversion a la salida.
    while(!conversion.EstaVacia()){
        this->exp_postfijo += conversion.ObtenerTope();
        ultimoOperando = false;
        conversion.Eliminar();
    }

    // Si al final quedo algo sin cerrar, pues no es valida.
    if(!validacion.EstaVacia()){
        this->valida = false;
        return;
    }

    // si sí pase todo, etntonces si fue valida!!!!!
    this->valida = true;
    // ahora lo vaciamos en el atributo de la calse, actualmente la expresion esta volteada
    // entonces al vaciar con eliminar hasta que no quede nada, ya quedará derecha como atributo de la expresion!!!

    cout << exp_postfijo << endl;
}

/*

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



int Expresion::Precedencia(const char a)
{
    if(a == '^') return 3; // máxima precedencia
    if(a == '*' || a == '/') return 2;
    if(a == '+' || a == '-') return 1; //menor procedencia en los operadores

    return 0; // si me dan un (, [, {
}
