#ifndef TYPEEXCEPTION_H
#define TYPEEXCEPTION_H

#include <stdexcept>
#include <string>
#include <QString>

/*!
 * \file typeexception.h
 * \author Le Feurmou/Leleu
 */


/*! \class typeException
   * \brief Classe d'exception pour les types
   *
   *  Derive de std::exception
   *
   *
 */


class typeException :public std::exception
{
    std::string info;/*!<  Description de l'exception*/
public:


    /*!
    *  \brief Constructeur
    *
    *  Construit une exception a partir d'une chaine de caractere
    *
    */
    typeException(const char * s=""):info(s){}


    /*!
    *  \brief what
    *
    *  Permet d'en savoir plus sur la cause de l'erreur
    *  \return information sur l'erreur (char *)
    */
    const char* what() const throw(){return info.c_str();}

    /*!
    *  \brief Destructeur
    *
    *
    */
    ~typeException() throw(){}
};

#endif // TYPEEXCEPTION_H
