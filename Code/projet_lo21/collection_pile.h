#ifndef COLLECTION_PILE_H
#define COLLECTION_PILE_H

/*!
 * \file collection_pile.h
 * \brief Conteneur de piles
 * \author Le Feurmou/Leleu
 */



#include <vector>
#include "pile.h"
#include <QString>

/*! \class Collection_pile
   * \brief Classe conteneur de piles
   *
   *  La classe est un singleton, et derive de std::vector
 */

class Collection_pile :public std::vector<Pile *>
{
    static Collection_pile * instance;  /*!< Instance unique de la classe*/
    int actif; /*!< entier representant la position de la pile courante dans le vector*/


        /*!
        *  \brief Constructeur par recopie
        *
        *  Constructeur par recopie (prive) de la classe Collection_pile
        *  Non implemente pour le rendre inoperant
        *
        */
    Collection_pile (const Collection_pile& other);


        /*!
        *  \brief Desconstructeur
        *
        *  Destructeur (prive) de la classe Collection_pile
        *
        */
    ~Collection_pile(){}

        /*!
        *  \brief Constructeur
        *
        *  Constructeur (prive) de la classe Collection_pile
        *
        */
    Collection_pile(){}


    /*!
    *  \brief Operateur =
    *
    *  Operateur = (prive) de la classe Collection_pile
    *  Non implemente pour le rendre inoperant
    */
    Collection_pile operator =(const Collection_pile);
public:
    /*!
    *  \brief getInstance
    *   Methode retournant l'instance unique de la  classe
    *  \return Instance unique de la classe
    *
    */
    static Collection_pile& getInstance();

    /*!
    *  \brief releaseInstance
    *   Methode liberant l'instance unique de la  classe
    *
    *
    */
    static void releaseInstance();

    /*!
    *  \brief addPile
    *   Methode permettant l'ajout d'une pile dans la collection
    *  \param _pile : pile à ajouter
    *
    */
    void addPile (Pile * _pile);

    /*!
    *  \brief setActif
    *   Methode permettant de modifier la donnee membre "actif"
    *  \param a : entier representant la position de la pile à rendre active dans le vector
    *
    */
    void setActif (int a){actif=a;}

    /*!
    *  \brief getActif
    *   Methode permettant de recuperer la donnee membre "actif"
    *  \return entier representant la position de la pile à rendre active dans le vector
    *
    */
    int getActif (){return actif;}

};
#endif // COLLECTION_PILE_H
