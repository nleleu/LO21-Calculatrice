#ifndef PILE_H
#define PILE_H

#include <QStack>
#include "type.h"
#include <QString>
#include <sstream>
#include <QStringList>
#include "type_factory.h"
#include <QDebug>
#include "gardien.h"

<<<<<<< HEAD

/*!
 * \file pile.h
 * \author Le Feurmou/Leleu
 */

/*! \class pile
   * \brief Classe representant une pile
   *
   *  Derive de Qstack
   *
   *
 */
=======
enum degUnit{DEGRE, RADIANT};
>>>>>>> d96136695f89b27500092935a79da598e51d34db

class Dom;
class Pile : public QStack <type *>
{
<<<<<<< HEAD
    int  nbElt;/*!< Nombre d'elements a afficher*/
    gardien* g;/*!< Gardien de la pile*/
=======
    int  nbElt;
    QString fileName;
    gardien* g;
>>>>>>> d96136695f89b27500092935a79da598e51d34db
public:
    /*!
    *  \brief Destructeur
    *
    *  Destructeur de la classe Pile
    *
    */
    ~Pile();

    /*!
    *  \brief Constructeur
    *
    *  Constructeur de la classe Pile
    *
    */
    Pile();
<<<<<<< HEAD

    /*!
    *  \brief Clone
    *
    *  Permet de creer une nouvelle pile a partir d'une pile source.
    *  Le gardien sera un nouveau gardien.
    *  Pour dupliquer une pile en conservant son gardien, voir duplique().
    *   \return Nouvelle pile
    */
=======
    void setFileName(QString name){fileName = name;}
    static degUnit selectedDegUnit;
    void sauvegarde();
    void charger();
>>>>>>> d96136695f89b27500092935a79da598e51d34db
    Pile& clone() const;

    /*!
    *  \brief Duplique
    *
    *  Permet de creer une nouvelle pile a partir d'une pile source.
    *   Le gardien sera conserve.
    *   \return Nouvelle pile
    */
    Pile& duplique()const;

    /*!
    *  \brief setGardien
    *  Permet de modifier le gardien de la pile
    *
    * \param g : gardien *
    *
    *
    */
    void setGardien(gardien* _g){g=_g;}

    /*!
    *  \brief setNbElt
    *  Permet de modifier le nombre d'element a afficher de la pile
    *
    * \param nb : nombre d'element
    *
    *
    */
    void setNbElt(int nb){nbElt=nb;}

    /*!
    *  \brief getGardien
    *  Permet de recuperer le gardien de la pile
    *
    * \return gardien*
    *
    *
    */
    gardien* getGardien()const{return g;}

<<<<<<< HEAD
    /*!
    *  \brief swap
    *  Permet d'echanger la position des elements en x et y
    *  \param x: entier,y:entier
    *
    */
=======

    //selection de l'unite des degres
    void on_degUnit_clicked();
    void on_radUnit_clicked();


>>>>>>> d96136695f89b27500092935a79da598e51d34db
    void swap(const unsigned int x, const unsigned int y);

    /*!
    *  \brief sum
    *  Permet de sommer les x premiers elements de la pile
    *  \param x: entier
    *
    */
    void sum(const unsigned int x);

    /*!
    *  \brief mean
    *  Permet de calculer la moyenne des x premiers elements de la pile
    *  \param x: entier
    *
    */
    void mean(const unsigned int x);


    /*!
    *  \brief dup
    *  Duplique le dernier element de la pile
    *
    *
    */
    void dup(){if(!isEmpty()){push(top());}} //todo : modifier pour eviter les pb de pointeurs de la pile

    /*!
    *  \brief drop
    *  Supprime le premier element de la pile
    *
    *
    */
    void drop(){if(!isEmpty()){pop();}}

    /*!
    *  \brief addition
    *  Additionne les deux premiers elements de la pile
    *
    *
    */
    void addition();

    /*!
    *  \brief soustraction
    *  Soustrait les deux premiers elements de la pile
    *
    *
    */
    void soustraction();

    /*!
    *  \brief division
    *  Divise les deux premiers elements de la pile
    *
    *
    */
    void division();

    /*!
    *  \brief multiplication
    *  Multiplie les deux premiers elements de la pile
    *
    *
    */
    void multiplication();

    /*!
    *  \brief parser
    *  Utilise les regexp pour parser la chaine s
    *  Creer ensuite les types dans la pile,  ou execute les operations
    *   \param s: Qstring source
    */
    void parser(QString s);

    /*!
    *  \brief getNb
    *  Retourne la donnee membre NbElt
    *   \return Nombre d'element a afficher pour la pile
    */
    int getNb(){return nbElt;}

    /*!
    *  \brief undo
    *  Restaure (si c'est possible) l'etat precedent de la pile
    */
    void undo(){Pile *tmp=g->undo();if(tmp!=0)*this=*tmp;}

    /*!
    *  \brief undo
    *  Restaure (si c'est possible) l'etat suivant de la pile
    */
    void redo(){Pile *tmp=g->redo();if(tmp!=0)*this=*tmp;}

    void pow();
    void mod();

    void sign();

    void sinus();
    void cosinus();
    void tangente();
    void sinush();
    void cosinush();
    void tangenteh();

    void ln();
    void log();
    void inv();
    void sqrt();
    void sqr();
    void cube();
    void fact();
    void eval();


};

#endif // PILE_H
