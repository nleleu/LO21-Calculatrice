#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <QString>
#include "type.h"

/*!
 * \file expression.h
 * \author Le Feurmou/Leleu
 */

/*! \class expression
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


    type* evaluer();


    /*!
    *  \brief Operateur +
    *
    *  Implementation de l'operateur binaire + (methode virtuelle pure dans la classe mere)
    *  \param t : Pointeur sur un type (Utilisation du polymorphisme)
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    type* operator +(type & t);



    /*!
    *  \brief Operateur /
    *
    *  Implementation de l'operateur binaire / (methode virtuelle pure dans la classe mere)
    *  \param t : Pointeur sur un type (Utilisation du polymorphisme)
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    type* operator /(type & t);

    /*!
    *  \brief Operateur *
    *
    *  Implementation de l'operateur binaire * (methode virtuelle pure dans la classe mere)
    *  \param t : Pointeur sur un type (Utilisation du polymorphisme)
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    type* operator*(type& t);

    /*!
    *  \brief Operateur -
    *
    *  Implementation de l'operateur binaire - (methode virtuelle pure dans la classe mere)
    *  \param t : Pointeur sur un type (Utilisation du polymorphisme)
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    type* operator-(type& t);



    /*!
    *  \brief Sinus
    *
    *  Implementation de l'operateur unaire sinus (methode virtuelle pure dans la classe mere)
    *  \param t : Pointeur sur un type (Utilisation du polymorphisme)
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
<<<<<<< HEAD
    type* sinus(degUnit& selectedDegUnit){}
    type* pow(type & t){}
    type* sign(){}
=======
    type* sinus();
    type* pow(type & t);
    type* sign();
>>>>>>> ce23cc6a6cfad0843b3cb0969496e50321829ac0



    /*!
    *  \brief Cosinus
    *
    *  Implementation de l'operateur unaire cosinus (methode virtuelle pure dans la classe mere)
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
<<<<<<< HEAD
    type* cosinus(degUnit& selectedDegUnit){}
=======
    type* cosinus();
>>>>>>> ce23cc6a6cfad0843b3cb0969496e50321829ac0

    /*!
    *  \brief Tangente
    *
    *  Implementation de l'operateur unaire tangente (methode virtuelle pure dans la classe mere)
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
<<<<<<< HEAD
    type* tangente(degUnit& selectedDegUnit){}
=======
    type* tangente();
>>>>>>> ce23cc6a6cfad0843b3cb0969496e50321829ac0

    /*!
    *  \brief Sinush
    *
    *  Implementation de l'operateur unaire sinush (methode virtuelle pure dans la classe mere)
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
<<<<<<< HEAD
    type* sinush(degUnit& selectedDegUnit){}
=======
    type* sinush();
>>>>>>> ce23cc6a6cfad0843b3cb0969496e50321829ac0

    /*!
    *  \brief Cosinush
    *
    *  Implementation de l'operateur unaire cosinush (methode virtuelle pure dans la classe mere)
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
<<<<<<< HEAD
    type* cosinush(degUnit& selectedDegUnit){}
=======
    type* cosinush();
>>>>>>> ce23cc6a6cfad0843b3cb0969496e50321829ac0

    /*!
    *  \brief Tangenteh
    *
    *  Implementation de l'operateur unaire tangenteh (methode virtuelle pure dans la classe mere)
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
<<<<<<< HEAD
    type* tangenteh(degUnit& selectedDegUnit){}
=======
    type* tangenteh();
>>>>>>> ce23cc6a6cfad0843b3cb0969496e50321829ac0


    /*!
    *  \brief Ln
    *
    *  Implementation de l'operateur unaire ln (methode virtuelle pure dans la classe mere)
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    type* ln();

    /*!
    *  \brief Log
    *
    *  Implementation de l'operateur unaire log (methode virtuelle pure dans la classe mere)
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    type* log();

    /*!
    *  \brief Inv
    *
    *  Implementation de l'operateur unaire inv (methode virtuelle pure dans la classe mere)
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    type* inv();


    /*!
    *  \brief Sqrt
    *
    *  Implementation de l'operateur unaire sqrt (methode virtuelle pure dans la classe mere)
    *  \param t : Pointeur sur un type (Utilisation du polymorphisme)
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    type* sqrt();


    /*!
    *  \brief Sqr
    *
    *  Implementation de l'operateur unaire sqr (methode virtuelle pure dans la classe mere)
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    type* sqr();

    /*!
    *  \brief Cube
    *
    *  Implementation de l'operateur unaire Cube (methode virtuelle pure dans la classe mere)
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    type* cube();




    /*!
    *  \brief eval
    *
    *  Implementation de l'operateur unaire eval (methode virtuelle pure dans la classe mere)
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
