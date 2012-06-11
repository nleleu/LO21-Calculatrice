#ifndef PILE_H
#define PILE_H

#include <QStack>
#include "type.h"
#include <QString>
#include <sstream>
#include <QStringList>
#include "type_factory.h"

#include "gardien.h"



/*!
 * \file pile.h
 * \author Le Feurmou/Leleu
 */

/*! \class Pile
   * \brief Classe representant une pile
   *
   *  Derive de Qstack
   *
   *
 */



class Dom;
class Pile : public QStack <type *>
{

    int  nbElt;/*!< Nombre d'elements a afficher*/
    gardien* g;/*!< Gardien de la pile*/
    bool degre;/*!< true si on travaille en degré, false sinon*/

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

    /*!
    *  \brief getDegre
    *
    *  Accesseur de la donnee membre degre
    *   \return degre (bool)
    */
    bool getDegre() const {return degre;}

    /*!
    *  \brief setDegre
    *
    *   Modifie la donnee membre degre
    *   \param deg (bool)
    */
    void setDegre(bool deg){degre=deg;}

    /*!
    *  \brief sauvegarder
    *
    *   Sauvegarde la pile dans un fichier XML
    *   \param filename (QString) : nom du fichier
    */
    void sauvegarder(QString fileName);

    /*!
    *  \brief charger
    *
    *   Restaure une pile sauvegardee au format XML
    *   \param filename (QString) : nom du fichier
    */
    void charger(QString fileName);


    /*!
    *  \brief Clone
    *
    *  Permet de creer une nouvelle pile a partir d'une pile source.
    *  Le gardien sera un nouveau gardien.
    *  Pour dupliquer une pile en conservant son gardien, voir duplique().
    *   \return Nouvelle pile
    */
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


    /*!
    *  \brief swap
    *  Permet d'echanger la position des elements en x et y
    *  \param x: entier,y:entier
    *
    */





    void swap(unsigned int x,unsigned int y);

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
    *  \brief redo
    *  Restaure (si c'est possible) l'etat suivant de la pile
    */
    void redo(){Pile *tmp=g->redo();if(tmp!=0)*this=*tmp;}


    /*!
    *  \brief pow
    *  Declenche l'operateur pow
    */
    void pow();


    /*!
    *  \brief mod
    *  Declenche l'operateur mod
    */
    void mod();


    /*!
    *  \brief sign
    *  Declenche l'operateur sign
    */
    void sign();


    /*!
    *  \brief sinus
    *  \param degre : true si utilisation des degres, false si utilisation des radians
    *  Declenche l'operateur sinus
    */
    void sinus(bool degre=false);
    /*!
    *  \brief cosinus
    *  \param degre : true si utilisation des degres, false si utilisation des radians
    *  Declenche l'operateur cosinus
    */
    void cosinus(bool degre=false);
    /*!
    *  \brief tangente
    *  \param degre : true si utilisation des degres, false si utilisation des radians
    *  Declenche l'operateur tangente
    */
    void tangente(bool degre=false);
    /*!
    *  \brief sinush
    *  \param degre : true si utilisation des degres, false si utilisation des radians
    *  Declenche l'operateur sinush
    */
    void sinush(bool degre=false);
    /*!
    *  \brief cosinush
    *  \param degre : true si utilisation des degres, false si utilisation des radians
    *  Declenche l'operateur cosinush
    */
    void cosinush(bool degre=false);
    /*!
    *  \brief tangenteh
    *  \param degre : true si utilisation des degres, false si utilisation des radians
    *  Declenche l'operateur tangenteh
    */
    void tangenteh(bool degre=false);


    /*!
    *  \brief ln
    *  Declenche l'operateur ln
    */
    void ln();

    /*!
    *  \brief log
    *  Declenche l'operateur log
    */
    void log();

    /*!
    *  \brief inv
    *  Declenche l'operateur inv
    */
    void inv();

    /*!
    *  \brief sqrt
    *  Declenche l'operateur sqrt
    */
    void sqrt();

    /*!
    *  \brief sqr
    *  Declenche l'operateur sqr
    */
    void sqr();

    /*!
    *  \brief cube
    *  Declenche l'operateur cube
    */
    void cube();

    /*!
    *  \brief fact
    *  Declenche l'operateur fact
    */
    void fact();

    /*!
    *  \brief eval
    *  Declenche l'operateur eval
    */
    void eval();


};

#endif // PILE_H
