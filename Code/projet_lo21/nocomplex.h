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

};

#endif // NOCOMPLEX_H
