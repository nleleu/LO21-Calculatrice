#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <QString>
#include "type.h"

/*!
 * \file expression.h
 * \author Le Feurmou/Leleu
 */

/*! \class Expression
   * \brief Classe representant une expression
   *
   *  La classe derive de type.
   *  Permet de representer une expression
   *
   *
 */

class Expression : public type
{
    QString exp;/*!< donnee membre representant l'expression*/
public:

    /*!
    *  \brief Constructeur
    *
    *  Constructeur a partir de Qstring
    *  \param exp1s : chaine source
    *
    */
    Expression(QString &exp1);




    /*!
    *  \brief Operateur +
    *
    *  Implementation de l'operateur binaire + (methode virtuelle dans la classe mere)
    *  \param t : Pointeur sur un type
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    type* operator +(type & t);



    /*!
    *  \brief Operateur /
    *
    *  Implementation de l'operateur binaire / (methode virtuelle dans la classe mere)
    *  \param t : Pointeur sur un type
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    type* operator /(type & t);

    /*!
    *  \brief Operateur *
    *
    *  Implementation de l'operateur binaire * (methode virtuelle dans la classe mere)
    *  \param t : Pointeur sur un type
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    type* operator*(type& t);

    /*!
    *  \brief Operateur -
    *
    *  Implementation de l'operateur binaire - (methode virtuelle dans la classe mere)
    *  \param t : Pointeur sur un type
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    type* operator-(type& t);



    /*!
    *  \brief Sinus
    *
    *  Implementation de l'operateur unaire sinus (methode virtuelle dans la classe mere)
    *  \param degre : booleen, vrai si utilisation des degre, faux si utilisation des radians
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    type* sinus(bool degre=false);

    /*!
    *  \brief Pow
    *
    *  Implementation de l'operateur binaire pow (methode virtuelle dans la classe mere)
    *  \param t : Pointeur sur un type
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    type* pow(type & t);

    /*!
    *  \brief mod
    *
    *  Implementation de l'operateur binaire modulo (methode virtuelle dans la classe mere)
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    type* mod(type & t);


    /*!
    *  \brief sign
    *
    *  Implementation de l'operateur unaire sign (methode virtuelle dans la classe mere)
    *  Inverse le signe de la constante
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    type* sign();




    /*!
    *  \brief Cosinus
    *
    *  Implementation de l'operateur unaire cosinus (methode virtuelle dans la classe mere)
    *  \param degre : booleen, vrai si utilisation des degre, faux si utilisation des radians
    *  \return Pointeur sur type, resultat de l'operation
    *
    */

    type* cosinus(bool degre=false);

    /*!
    *  \brief Tangente
    *
    *  Implementation de l'operateur unaire tangente (methode virtuelle dans la classe mere)
    *  \param degre : booleen, vrai si utilisation des degre, faux si utilisation des radians
    *  \return Pointeur sur type, resultat de l'operation
    *
    */

    type* tangente(bool degre=false);


    /*!
    *  \brief Sinush
    *
    *  Implementation de l'operateur unaire sinush (methode virtuelle dans la classe mere)
    *  \param degre : booleen, vrai si utilisation des degre, faux si utilisation des radians
    *  \return Pointeur sur type, resultat de l'operation
    *
    */

    type* sinush(bool degre=false);


    /*!
    *  \brief Cosinush
    *
    *  Implementation de l'operateur unaire cosinush (methode virtuelle dans la classe mere)
    *  \param degre : booleen, vrai si utilisation des degre, faux si utilisation des radians
    *  \return Pointeur sur type, resultat de l'operation
    *
    */

    type* cosinush(bool degre=false);

    /*!
    *  \brief Tangenteh
    *
    *  Implementation de l'operateur unaire tangenteh (methode virtuelle dans la classe mere)
    *  \param degre : booleen, vrai si utilisation des degre, faux si utilisation des radians
    *  \return Pointeur sur type, resultat de l'operation
    *
    */

    type* tangenteh(bool degre=false);



    /*!
    *  \brief Ln
    *
    *  Implementation de l'operateur unaire ln (methode virtuelle dans la classe mere)
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    type* ln();

    /*!
    *  \brief Log
    *
    *  Implementation de l'operateur unaire log (methode virtuelle dans la classe mere)
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    type* log();

    /*!
    *  \brief Inv
    *
    *  Implementation de l'operateur unaire inv (methode virtuelle dans la classe mere)
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    type* inv();


    /*!
    *  \brief Sqrt
    *
    *  Implementation de l'operateur unaire sqrt (methode virtuelle dans la classe mere)
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    type* sqrt();


    /*!
    *  \brief Sqr
    *
    *  Implementation de l'operateur unaire sqr (methode virtuelle dans la classe mere)
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    type* sqr();

    /*!
    *  \brief Cube
    *
    *  Implementation de l'operateur unaire Cube (methode virtuelle dans la classe mere)
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    type* cube();




    /*!
    *  \brief eval
    *
    *  Implementation de l'operateur unaire eval (methode virtuelle dans la classe mere)
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    QString eval();


    /*!
    *  \brief toQString
    *
    *  Transforme l'objet Qstring. Permet ensuite l'affichage dans des widget
    *  \return Qstring : chaine resultat
    */
    QString toQString(){return exp;}

    /*!
    *  \brief isExpression
    *
    *  Methode static permettant de savoir quel type d'objet creer
    *  \return true si la chaine permet de construire une expression
    *    false sinon
    */

};

#endif // EXPRESSION_H
