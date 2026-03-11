/** \file Expresion.hpp
 *
 * \author Isaac Espinoza Hern&aacute;ndez,
 * David Armando Angulo Gil
 *
 * \date 10/03/2026
 */
#ifndef EXPRESION_HPP_INCLUDED
#define EXPRESION_HPP_INCLUDED

#include <string>
using std::string;

class Expresion{
public:
    /** \brief Constructor de la clase
     *  \return Nada
     *
     */
    Expresion();

    /** \brief Constructor que recibe una expresi&oacute;n en infijo y la valida
     *
     * \param exp_infijo expresi&oacute;n en infijo
     *
     */
    Expresion(std::string exp_infijo);

    /** \brief Dice si una expresi&oacute;n es v&aacute;lida
     *
     * \return bool true si es v&aacute;lida, false si no es v&aacute;lida.
     *
     */
    bool EsValida();
    // Para capturar en infijo
    /** \brief Captura una cadena de caracteres que represente una expresi&oacute;n en infijo
     *
     * \return Nada
     *
     */
    void Capturar();

    /** \brief Imprime la expresi&oacute;n en infijo
     *
     * \return Nada
     *
     */
    void ImprimirInfijo();
    /** \brief Imprime la expresi&oacute;n en postfijo
     *
     * \return Nada
     *
     */
    void ImprimirPostfijo();

    /** \brief Evalua la expresi&oacute;n capturada solo si es valida
     *
     * \return double
     * \warning Da un error de tipo ExpresionInvalida.
     * \throw Menciona que la expresi&oacute;n no fue posible de evaluar.
     */
    double Evaluar();


    /** \brief Clase para las excepciones de tipo "ExpresionInvalida"
     */
    class ExpresionInvalida : public std::exception
    {
    public:

        /** \brief Constructor de la subclase ExpresionInvalida
         *
         * \param msg mensaje personalizado
         * \return Nada
         */
        ExpresionInvalida(const char *msg) noexcept;

        /** \brief Funcion para lanzar la excepci&oacute;n con un mensaje personalizado
         *
         * \return Excepci&oacute;n lanzada
         *
         */
        virtual const char *what() const noexcept;
    private:
        const char *mensaje;/**< Mensaje personalizado */
    };

private:
    std::string exp_infijo;/**< Expresion en Infijo */
    std::string exp_postfijo;/**< Expresion en Postfijo */
    // Para dada una en postfijo, pasarla a infijo
    /** \brief Funcion que transforma una expresion infijo a postfijo.
     *
     * \return Nada
     */
    void APostfijo();
    bool valida;/**< true si la funcion es valida para la evaluaci&oacute;n y false si no lo es */

    /** \brief Calcula la precedencia de los operadores: - + * / ^ y de los signos de agrupaci&oacute;n: ( [ {
     *
     * \param a caracter del operador o signo de agrupaci&oacute;n
     * \return Entero: 3 de mayor precedencia, 2 media, 1 baja, y 0 si es signo de agrupaci&oacute;n
     *
     */
    int Precedencia(const char a);


};

#endif // EXPRESION_HPP_INCLUDED
