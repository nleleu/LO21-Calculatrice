#ifndef TYPE_FACTORY_H
#define TYPE_FACTORY_H
#include <QString>
#include "type.h"
#include <QStringList>

/*!
 * \file type_factory.h
 * \author Le Feurmou/Leleu
 */


/*! \class type_factory
   * \brief Classe creant les types
   *  Singleton, implementation du design pattern Factory
   *
   *
 */


class type_factory
{
    static type_factory * instance;/*!<  Instance unique de la factory*/
public:

    /*!
    *  \brief Constructeur par recopie
    *
    *  Constructeur par recopie (prive) de la classe Collection_pile
    *  Non implemente pour le rendre inoperant
    *
    */
    type_factory (const type_factory&);

    /*!
    *  \brief Destructeur
    *
    *  Destructeur (prive) de la classe Collection_pile
    *
    */
    ~type_factory(){}


    /*!
    *  \brief Constructeur
    *
    *  Constructeur (prive) de la classe Collection_pile
    */
    type_factory(){}

    /*!
    *  \brief Operateur =
    *
    *  Operateur = (prive) de la classe Collection_pile
    *  Non implemente pour le rendre inoperant
    */
    type_factory operator =(const type_factory);
public:

    /*!
    *  \brief getInstance
    *   Methode retournant l'instance unique de la  classe
    *  \return Instance unique de la classe
    *
    */
    static type_factory& getInstance();

    /*!
    *  \brief releaseInstance
    *   Methode liberant l'instance unique de la  classe
    *
    *
    */
    static void releaseInstance();

    /*!
    *  \brief getType
    *  Methode permettant de creer un nouveau type
    *  \param Qstring s, chaine de caractere source
    *  \return Pointeur sur type, nouveau type cree
    */
    type* getType(QString s);

};
#endif // TYPE_FACTORY_H
