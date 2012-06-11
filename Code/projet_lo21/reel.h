#ifndef REEL_H
#define REEL_H

#include "type.h"
#include <sstream>
#include <QString>

#include "nocomplex.h"
#include <QRegExp>

/*!
 * \file reel.h
 * \author Le Feurmou/Leleu
 */


/*! \class reel
   * \brief Classe representant un reel
   *
   *  Derive de nocomplex
   *
   *
 */


class reel:public nocomplex
{
    double data;/*!<  reel*/
public:

    /*!
    *  \brief Constructeur
    *
    *  Construit un reel a partir d'un double
    *
    */
    reel(double val=0):data(val){}


    /*!
    *  \brief Constructeur
    *
    *  Construit un reel a partir d'une QString
    *
    */
    reel(const QString &s)//pour convertir une QString en double
    {
        QString copie(s);
        copie.replace(',', '.');
        data = copie.toDouble();
    }


    /*!
    *  \brief getData
    *
    *  Accesseur de la donnee membre data
    *
    */
    double getData(){return data;}

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
    type* pow(type & t);
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
    *  \brief getDecimales
    *
    *  Methode calculant le nombre de decimales (utile pour la tranformation en fraction)
    *  \return nombre de decimales (int)
    *
    */


    int getDecimales(){
        return toQString().section('.', 1,1).size();
                      }



};

#endif // REEL_H
