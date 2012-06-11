#ifndef COMPLEXE_H
#define COMPLEXE_H

#include "type.h"
#include <sstream>
#include <QString>
#include "nocomplex.h"
#include "type_factory.h"

#include "constante.h"


/*!
 * \file complexe.h
 * \author Le Feurmou/Leleu
 */


/*! \class complexe
   * \brief Classe representant un complexe
   *
   *  La classe gere la partie reelle et la partie imaginaire des complexes
   *  et permet les operations classiques.
   *  Derive de la classe constante
   *
 */


class complexe:public constante
{
    nocomplex*  re;/*!< Partie reelle*/
    nocomplex* im;/*!< Partie imaginaire*/
public:
    /*!
    *  \brief Constructeur
    *
    *  Constructeur a partir de pointeurs sur "nocomplex"
    *  \param _re : partie relle, pointeur sur nocomplex,0 par defaut
    *  _im : partie imagianaire, pointeur sur nocomplex,0 par defaut
    */
    complexe(nocomplex* _re=0,nocomplex* _im=0):re(_re), im(_im){}



    type* conjugue();

    /*!
    *  \brief Constructeur
    *
    *  Constructeur a partir de Qstring. Parse la chaine pour construire un complexe
    *  \param s : Qstring, par reference
    *
    */
    complexe(const QString &s)//pour convertir une QString en complexe
    {
        QString copie(s);

        re=dynamic_cast<nocomplex*>(type_factory::getInstance().getType((copie.section('$', 0,0))));
        im=dynamic_cast<nocomplex*>(type_factory::getInstance().getType((copie.section('$', 1,1))));
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




    type* sign();


    /*!
    *  \brief getRe
    *
    *  Accesseur de la partie reelle
    *  \return Pointeur sur nocomplex, partie reelle de l'objet appelant
    */

    nocomplex* getRe(){return re;}


    /*!
    *  \brief getIm
    *
    *  Accesseur de la partie reelle
    *  \return Pointeur sur nocomplex, partie imaginaire de l'objet appelant
    */
    nocomplex* getIm(){return im;}

    /*!
    *  \brief toQString
    *
    *  Transforme l'objet Qstring. Permet ensuite l'affichage dans des widget
    *  \return Qstring : chaine resultat
    */
    QString toQString();



};

#endif // COMPLEXE_H
