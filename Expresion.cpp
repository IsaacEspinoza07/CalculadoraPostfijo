#include "Expresion.hpp"
#include "Pila.hpp"
#include <iostream>

using std::cout, std::cin;

// ==== CONSTUCTORES ==== //

// Constructor vacio y no es valido
Expresion::Expresion(): exp_infijo(""), valida(false) {}

// Constructor con un argumento (entrada de la expresion)
Expresion::Expresion(string exp_infijo)
{
    this->exp_infijo = exp_infijo;
    APostfijo();
    // aqui ya se dice si fue valida o no, internamente en la transformación
}



// ==== MÉTODOS DE LA CLASE ==== //

void Expresion::Capturar()
{
    // capturamos todo el infijo y lo guardamos
    cout << "Capture una expresión en infijo: ";
    getline(cin, exp_infijo);
}



// ========================== //
void Expresion::APostfijo()
{
    Pila<char>  validacion, // A este solo le llegan los () [] {}
                conversion; // A este tanto ()[]{} como +-*/^

    string e = exp_infijo; // 'e' para facilitar su manejo

    // Esto recorrera de izquierda a derecha.
    // Como nomás hay que dar una pasada, aqui sucedera todo
    for(int i = 0; i < (int)e.length(); ++i){
        char c = e[i];

        if(c == ' ') continue; // ignorar espacios

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

            // Si estaba en el tope, es valido
            if(validacion.ObtenerTope() == otro){
                validacion.Eliminar();
            }
            else{
                this->valida = false;
                return;
            }

            // ahora vaciamos el de los operadores hasta la apertura
            while(conversion.ObtenerTope() != otro){
                this->exp_postfijo += conversion.ObtenerTope();
                conversion.Eliminar();
            }
            conversion.Eliminar(); // descartamos la apertura
        }
        // elseif pa que no haga cosas cuando no debe. Checar todos los operadores.
        else if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^'){
            // Detectar si es unario
            bool esUnario = false;
            if(i == 0){
                esUnario = true;
            }else{
                int j = i - 1;

                while(j >= 0 && e[j] == ' ') j--;
                if(j >= 0 && (e[j]=='(' || e[j]=='[' || e[j]=='{')){
                    esUnario = true;
                }
            }
            if(esUnario && (c=='+' || c=='-')){
                this->exp_postfijo += "0$";
            }

            // Si hay algo en conversion y NO es una apertura, vamos sacando todo:
            // tambien, checamos precedencia.
            while(!conversion.EstaVacia() && conversion.ObtenerTope() != '(' && conversion.ObtenerTope() != '['
                                          && conversion.ObtenerTope() != '{'
                                          && Precedencia(conversion.ObtenerTope()) >= Precedencia(c)
                                          && !(c == '^' && conversion.ObtenerTope() == '^')) // asociatividad derecha del ^
            {
                this->exp_postfijo += conversion.ObtenerTope();
                conversion.Eliminar();
            }
            conversion.Agregar(c);
        }
        // aqui metemos los operandos (numeros, punto decimal)
        // e ir agregando los separadores '$' al terminar cada numero
        else if(isdigit(c) || c == '.'){
            this->exp_postfijo += c;

            // El numero termino si: es el ultimo char, o el siguiente NO es digito ni punto
            if(i == (int)e.length() - 1 || (!isdigit(e[i+1]) && e[i+1] != '.')){
                this->exp_postfijo += '$';
            }
        }

        /*
        PARA DEBUGEAR O VER COMO SE VAN METIENDO
        CADA COSA A CADA PILA, DESCOMENTAR LO DE ABAJO, MUY INTERESANTE
        */
        /*
        // ===== IMPRESIONES DE VERIFICACIÓN ===== //
        cout << "\nValidación: "; validacion.Imprimir(); cout << endl;
        cout << "Conversion: "; conversion.Imprimir(); cout << endl;
        cout << "Postfijo: " << exp_postfijo << endl << endl;
        */
    }

    // por ultimo, vaciamos todo lo que quedo en conversion a la salida.
    while(!conversion.EstaVacia()){
        this->exp_postfijo += conversion.ObtenerTope();
        conversion.Eliminar();
    }

    // Si al final quedo algo sin cerrar, pues no es valida.
    if(!validacion.EstaVacia()){
        this->valida = false;
        return;
    }

    // si pase todo, entonces si fue valida!!!!!
    this->valida = true;
}



// ========================== //

void Expresion::ImprimirInfijo()
{
    cout << exp_infijo << endl;
}

// ========================== //

void Expresion::ImprimirPostfijo()
{
    cout << exp_postfijo << endl;
}

// ========================== //
/*
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
