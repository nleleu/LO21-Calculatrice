#ifndef REEL_H
#define REEL_H

#include "type.h"
#include <sstream>
#include <QString>
#include <qDebug>
#include "nocomplex.h"

class reel:public nocomplex
{
    double data;
public:
    reel(double val=0):data(val){}
    /*reel(const std::string &s){
        std::istringstream iss1(s);//pour convertir une string en int
        iss1 >> data;
    }*/

    reel(const QString &s)//pour convertir une QString en double
    {
        QString copie(s);
        copie.replace(',', '.');
        data = copie.toDouble();
    }

    double getData(){return data;}

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
    type* sinus();
    type* pow(type & t);
    type* mod(type & t){}
    type* sign();



    /*!
    *  \brief Cosinus
    *
    *  Implementation de l'operateur unaire cosinus (methode virtuelle pure dans la classe mere)
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    type* cosinus();

    /*!
    *  \brief Tangente
    *
    *  Implementation de l'operateur unaire tangente (methode virtuelle pure dans la classe mere)
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    type* tangente();

    /*!
    *  \brief Sinush
    *
    *  Implementation de l'operateur unaire sinush (methode virtuelle pure dans la classe mere)
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    type* sinush();

    /*!
    *  \brief Cosinush
    *
    *  Implementation de l'operateur unaire cosinush (methode virtuelle pure dans la classe mere)
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    type* cosinush();

    /*!
    *  \brief Tangenteh
    *
    *  Implementation de l'operateur unaire tangenteh (methode virtuelle pure dans la classe mere)
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    type* tangenteh();


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
    *  \brief Fact
    *
    *  Implementation de l'operateur unaire fact (methode virtuelle pure dans la classe mere)
    *  \param t : Pointeur sur un type (Utilisation du polymorphisme)
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    type* fact(){}


    /*!
    *  \brief eval
    *
    *  Implementation de l'operateur unaire eval (methode virtuelle pure dans la classe mere)
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    type* eval(){}


    /*!
    *  \brief toQString
    *
    *  Transforme l'objet Qstring. Permet ensuite l'affichage dans des widget
    *  \return Qstring : chaine resultat
    */
    QString toQString();

    /*!
    *  \brief isReel
    *
    *  Methode static permettant de savoir quel type d'objet creer
    *  \return true si la chaine permet de construire un reel
    *    false sinon
    */

    static bool isReel(const QString& s){return s.contains (",");}
};

#endif // REEL_H
