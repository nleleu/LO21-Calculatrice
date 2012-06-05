#ifndef NOCOMPLEX_H
#define NOCOMPLEX_H

#include "constante.h"

/*!
 * \file nocomplex.h
 * \author Le Feurmou/Leleu
 */

/*! \class nocomplex
   * \brief Classe representant les types de constantes non complexes
   *
   *  La classe derive de constante.
   *  Permet d'obtenir un arbre de classe coherent
   *
   *
 */

class nocomplex : public constante
{
public:
    /*!
    *  \brief Constructeur
    *
    */
    nocomplex(){}

    /*!
    *  \brief Operateur +
    *   Methode virtuelle pure, permet de profiter du polymorphisme (interet pour les complexes)
    *
    */
    virtual type* operator+(type & t)=0;

    /*!
    *  \brief Operateur /
    *   Methode virtuelle pure, permet de profiter du polymorphisme (interet pour les complexes)
    *
    */
    virtual type* operator/(type & t)=0;
    /*!
    *  \brief Operateur *
    *   Methode virtuelle pure, permet de profiter du polymorphisme (interet pour les complexes)
    *
    */
    virtual type* operator*(type & t)=0;
    /*!
    *  \brief Operateur -
    *   Methode virtuelle pure, permet de profiter du polymorphisme (interet pour les complexes)
    *
    */
    virtual type* operator-(type & t)=0;

    virtual type* pow(type & t)=0;
    virtual type* sign()=0;

    virtual type* sinus()=0;
    virtual type* cosinus()=0;
    virtual type* tangente()=0;
    virtual type* sinush()=0;
    virtual type* cosinush()=0;
    virtual type* tangenteh()=0;

    virtual type* ln()=0;
    virtual type* log()=0;
    virtual type* inv()=0;
    virtual type* sqrt()=0;
    virtual type* sqr()=0;
    virtual type* cube()=0;
    virtual type* eval()=0;

};

#endif // NOCOMPLEX_H
