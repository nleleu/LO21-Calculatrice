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
    type* sinus(){}
    type* pow(type & t){}
    type* sign();




    /*!
    *  \brief Cosinus
    *
    *  Implementation de l'operateur unaire cosinus (methode virtuelle pure dans la classe mere)
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    type* cosinus(){}

    /*!
    *  \brief Tangente
    *
    *  Implementation de l'operateur unaire tangente (methode virtuelle pure dans la classe mere)
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    type* tangente(){}

    /*!
    *  \brief Sinush
    *
    *  Implementation de l'operateur unaire sinush (methode virtuelle pure dans la classe mere)
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    type* sinush(){}

    /*!
    *  \brief Cosinush
    *
    *  Implementation de l'operateur unaire cosinush (methode virtuelle pure dans la classe mere)
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    type* cosinush(){}

    /*!
    *  \brief Tangenteh
    *
    *  Implementation de l'operateur unaire tangenteh (methode virtuelle pure dans la classe mere)
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    type* tangenteh(){}


    /*!
    *  \brief Ln
    *
    *  Implementation de l'operateur unaire ln (methode virtuelle pure dans la classe mere)
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    type* ln(){}

    /*!
    *  \brief Log
    *
    *  Implementation de l'operateur unaire log (methode virtuelle pure dans la classe mere)
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    type* log(){}

    /*!
    *  \brief Inv
    *
    *  Implementation de l'operateur unaire inv (methode virtuelle pure dans la classe mere)
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    type* inv(){}


    /*!
    *  \brief Sqrt
    *
    *  Implementation de l'operateur unaire sqrt (methode virtuelle pure dans la classe mere)
    *  \param t : Pointeur sur un type (Utilisation du polymorphisme)
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    type* sqrt(){}


    /*!
    *  \brief Sqr
    *
    *  Implementation de l'operateur unaire sqr (methode virtuelle pure dans la classe mere)
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    type* sqr(){}

    /*!
    *  \brief Cube
    *
    *  Implementation de l'operateur unaire Cube (methode virtuelle pure dans la classe mere)
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    type* cube(){}




    /*!
    *  \brief eval
    *
    *  Implementation de l'operateur unaire eval (methode virtuelle pure dans la classe mere)
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    type* eval(){}


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
    //type& operator/(int & i){}
    //type& operator/(double & i){}

    /*!
    *  \brief toQString
    *
    *  Transforme l'objet Qstring. Permet ensuite l'affichage dans des widget
    *  \return Qstring : chaine resultat
    */
    QString toQString();

    /*!
    *  \brief isComplexe
    *
    *  Methode static permettant de savoir quel type d'objet creer
    *  \return true si la chaine permet de construire un complexe
    *    false sinon
    */
    static bool isComplexe(const QString& s){return s.contains ("$");}
};

#endif // COMPLEXE_H
