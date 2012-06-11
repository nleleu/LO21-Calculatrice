#ifndef TYPE_H
#define TYPE_H

#include <sstream>
#include <QString>
#include <QTextStream>
#include "typeexception.h"
#include <QMessageBox>


/*!
 * \file type.h
 * \author Le Feurmou/Leleu
 */


/*! \class type
   * \brief Classe representant un type
   *
   *  Super Classe Abstraite utilise pour le polymorphisme
   *
   *
 */



class type
{

public:
    /*!
    *  \brief Constructeur
    *
    *
    */
    type(){}
    /*!
    *  \brief Destructeur (virtuel)
    *
    *
    */
    virtual ~type(){}

    /*!
    *  \brief Operateur +
    *  Operateur binaire +
    *  Methode virtuelle pure
    *  \param t : Pointeur sur un type
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    virtual type* operator+(type & t)=0;


    /*!
    *  \brief Operateur /
    *  Operateur binaire /
    *  Methode virtuelle pure
    *  \param t : Pointeur sur un type
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    virtual type* operator/(type & t)=0;


    /*!
    *  \brief Operateur *
    *  Operateur binaire *
    *  Methode virtuelle pure
    *  \param t : Pointeur sur un type
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    virtual type* operator*(type & t)=0;



    /*!
    *  \brief Operateur -
    *  Operateur binaire -
    *  Methode virtuelle pure
    *  \param t : Pointeur sur un type
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    virtual type* operator-(type & t)=0;


    /*!
    *  \brief Pow
    *  Operateur binaire Pow
    *  Methode virtuelle pure
    *  \param t : Pointeur sur un type
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    virtual type* pow(type & t){throw typeException("erreur pow");}

    /*!
    *  \brief Mod
    *  Operateur binaire Modulo
    *  Methode virtuelle
    *  \param t : Pointeur sur un type
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    virtual type* mod(type & t){throw typeException("erreur mod");}

    /*!
    *  \brief sign
    *  Operateur unaire sign
    *  Methode virtuelle
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    virtual type* sign(){throw typeException("erreur sign");}


    /*!
    *  \brief sinus
    *  Operateur unaire sinus
    *  Methode virtuelle
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    virtual type* sinus(bool degre=false){throw typeException("erreur sinus");}

    /*!
    *  \brief cosinus
    *  Operateur unaire cosinus
    *  Methode virtuelle
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    virtual type* cosinus(bool degre=false){throw typeException("erreur cosinus");}

    /*!
    *  \brief tangente
    *  Operateur unaire tangente
    *  Methode virtuelle
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    virtual type* tangente(bool degre=false){throw typeException("erreur tangente");}

    /*!
    *  \brief sinush
    *  Operateur unaire sinush
    *  Methode virtuelle
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    virtual type* sinush(bool degre=false){throw typeException("erreur sinush");}

    /*!
    *  \brief cosinush
    *  Operateur unaire cosinush
    *  Methode virtuelle
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    virtual type* cosinush(bool degre=false){throw typeException("erreur cosinush");}

    /*!
    *  \brief tangenteh
    *  Operateur unaire tangenteh
    *  Methode virtuelle
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    virtual type* tangenteh(bool degre=false){throw typeException("erreur tangenteh");}

    /*!
    *  \brief ln
    *  Operateur unaire ln
    *  Methode virtuelle
    *  \return Pointeur sur type, resultat de l'operation
    *
    */

    virtual type* ln(){throw typeException("erreur ln");}

    /*!
    *  \brief log
    *  Operateur unaire log
    *  Methode virtuelle
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    virtual type* log(){throw typeException("erreur log");}


    /*!
    *  \brief inv
    *  Operateur unaire inv
    *  Methode virtuelle
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    virtual type* inv(){throw typeException("erreur inv");}


    /*!
    *  \brief sqrt
    *  Operateur unaire sqrt
    *  Methode virtuelle
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    virtual type* sqrt(){throw typeException("erreur sqrt");}

    /*!
    *  \brief sqr
    *  Operateur unaire sqr
    *  Methode virtuelle
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    virtual type* sqr(){throw typeException("erreur sqr");}


    /*!
    *  \brief cube
    *  Operateur unaire cube
    *  Methode virtuelle
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    virtual type* cube(){throw typeException("erreur cube");}

    /*!
    *  \brief fact
    *  Operateur unaire fact
    *  Methode virtuelle
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    virtual type* fact(){throw typeException("erreur fact");}


    /*!
    *  \brief sign
    *  Operateur unaire sign
    *  Methode virtuelle
    *  \return Pointeur sur type, resultat de l'operation
    *
    */
    virtual QString eval(){throw typeException("erreur eval");}


    /*!
    *  \brief isEntier
    *  Methode statique permettant de determiner le type (Utiisation de regexp)
    *  \param Qstring s, chaine de caractere source
    *  \return true si la chaine ressemble a un entier,
    *   false sinon
    */
    static bool isEntier(const QString& s){QRegExp rx("^\\d+$"); return s.contains (rx);}


    /*!
    *  \brief isReel
    *  Methode statique permettant de determiner le type (Utiisation de regexp)
    *  \param Qstring s, chaine de caractere source
    *  \return true si la chaine ressemble a un reel,
    *   false sinon
    */
    static bool isReel(const QString& s){
        QString copie(s);
        copie.replace(',', '.');
        QRegExp rx("^-?\\d*\\.?\\d*$");
        return copie.contains(rx);}

    /*!
    *  \brief isRationnel
    *  Methode statique permettant de determiner le type (Utiisation de regexp)
    *  \param Qstring s, chaine de caractere source
    *  \return true si la chaine ressemble a un rationnel,
    *   false sinon
    */
    static bool isRationnel(const QString& s){QRegExp rx("^-?\\d*/-?\\d*$");  return s.contains (rx);}


    /*!
    *  \brief isExpression
    *  Methode statique permettant de determiner le type (Utiisation de regexp)
    *  \param Qstring s, chaine de caractere source
    *  \return true si la chaine ressemble a une expression,
    *   false sinon
    */
    static bool isExpression(const QString& s){return s.contains ('\'');}


    /*!
    *  \brief isComplexe
    *  Methode statique permettant de determiner le type (Utiisation de regexp)
    *  \param Qstring s, chaine de caractere source
    *  \return true si la chaine ressemble a un complexe,
    *   false sinon
    */
    static bool isComplexe(const QString& s){
        QString copie(s);
        copie.replace(',', '.');
        QRegExp rx("^-?\\d*(/|\\.)?.?\\$-?\\d*(/|\\.)?.?$");return copie.contains (rx);}


    /*!
    *  \brief toQString
    *  Methode virtuelle pure
    *  \return chaine de caractere
    */
    virtual QString toQString()=0;
};

#endif // TYPE_H
