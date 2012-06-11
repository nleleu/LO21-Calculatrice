#ifndef RATIONNEL_H
#define RATIONNEL_H

#include "type.h"
#include <iostream>
#include <sstream>
#include <QString>

#include "nocomplex.h"
#include "typeexception.h"
#include <QRegExp>



/*!
 * \file rationnel.h
 * \author Le Feurmou/Leleu
 */

/*! \class rationnel
   * \brief Classe representant une fraction
   *
   *  Derive de nocomplex
   *
   *
 */


class rationnel:public nocomplex
{
    int num;/*!<  Numerateur*/
    int denum;/*!< Denominateur*/
public:

    /*!
    *  \brief Constructeur
    *
    *  Construit une fraction a partir de deux entiers : numerateur et denominateur
    *
    */
    rationnel(int _num=0,int _denum=1):num(_num),denum(_denum){if (denum==0) throw typeException("Division par 0"); simplifie();}


    /*!
    *  \brief Constructeur
    *
    *  Construit une fraction a partir d'une QString
    *
    */
    rationnel(const QString &s)//pour convertir une QString en rationnel
    {
        QString copie(s);

        num=(copie.section('/', 0,0)).toInt();
        denum=(copie.section('/', 1,1)).toInt();
         if (denum==0) throw typeException("Division par 0");
        simplifie();

    }

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
    *  \param t : Pointeur sur un type
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    type* sinus(bool degre);

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
    *  \brief sign
    *
    *  Implementation de l'operateur unaire sign (methode virtuelle dans la classe mere)
    *  Inverse le signe de la constante
    *  \param t : Pointeur sur un type
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    type* sign();




    /*!
    *  \brief Cosinus
    *
    *  Implementation de l'operateur unaire cosinus (methode virtuelle dans la classe mere)
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    type* cosinus(bool degre);

    /*!
    *  \brief Tangente
    *
    *  Implementation de l'operateur unaire tangente (methode virtuelle dans la classe mere)
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    type* tangente(bool degre);

    /*!
    *  \brief Sinush
    *
    *  Implementation de l'operateur unaire sinush (methode virtuelle dans la classe mere)
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    type* sinush(bool degre);

    /*!
    *  \brief Cosinush
    *
    *  Implementation de l'operateur unaire cosinush (methode virtuelle dans la classe mere)
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    type* cosinush(bool degre);

    /*!
    *  \brief Tangenteh
    *
    *  Implementation de l'operateur unaire tangenteh (methode virtuelle dans la classe mere)
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    type* tangenteh(bool degre);


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
    *  \param t : Pointeur sur un type
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
    *  \brief toQString
    *
    *  Transforme l'objet Qstring. Permet ensuite l'affichage dans des widget
    *  \return Qstring : chaine resultat
    */
    QString toQString();


    /*!
    *  \brief eval
    *
    *  Implementation de l'operateur unaire eval (methode virtuelle dans la classe mere)
    *  Permet d'arrondir une fraction
    *  \param t : Pointeur sur un type
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    QString eval();





    /*!
    *  \brief simplifie
    *
    *  Simplifie la fration. Utilisation du PGCD
    *
    */
    void simplifie();

    /*!
    *  \brief pgcd
    *
    *  Calcul le pgcd de deux entier
    *  \param 2 entiers
    *
    */
    int pgcd(int, int ) const;

    /*!
    *  \brief getNum
    *
    *  Accesseur du numerateur
    *  \return numerateur(entier)
    *
    */
    int getNum(){return num;}

    /*!
    *  \brief getDenum
    *
    *  Accesseur du denominateur
    *  \return denominateur(entier)
    *
    */
    int getDenum(){return denum;}


};

#endif // RATIONNEL_H
