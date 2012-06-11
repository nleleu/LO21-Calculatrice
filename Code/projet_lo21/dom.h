#ifndef DOM_H
#define DOM_H

#include <QTextStream>
#include <QtXml/QDomDocument>
#include <QFile>
#include <QMessageBox>
#include <QString>

#include "pile.h"

/*!
 * \file dom.h
 * \author Le Feurmou/Leleu
 */


/*! \class Dom
   * \brief Classe manipulant l'XML
   *
   *  Permet la sauvegarde et le chargement
   *
   *
   *
 */

class Dom
{
public:
    /*!
    *  \brief Constructeur
    *
    *
    *  \param p : reference sur la pile a charger ou a sauvegarder
    *
    */

    Dom(Pile & p);

    /*!
    *  \brief Destructeur
    *
    */
    ~Dom(){}

    /*!
    *  \brief Ecrire
    *  Sauvegarde la pile dans un fichier xml
    *  \param filemane(QString) : Chemin du fichier de sauvegarde
    */
    void ecrire(QString fileName);

    /*!
    *  \brief Lire
    *  Charge un fichier XML dans une pile
    *  \param filemane(QString) : Chemin du fichier XML source
    */
    void lire(QString fileName);

private :
    Pile& _pile;/*!< Pile a charger ou a sauvegarder*/
};

#endif // DOM_H
