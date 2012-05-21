#include "dom.h"
#include "entier.h"
#include "reel.h"
#include "rationnel.h"
#include "complexe.h"
#include "type_factory.h"


Dom::Dom(Pile & pile): _pile(pile){}


void Dom::demande_ajout(QString n,QString t)
{
     // cr�ation de la balise "sauvegarde"
   // doc.appendChild(sauvegardes); // filiation de la balise "sauvegarde"
    file.setFileName("sauvegarde_contexte.xml");
    if (!file.open(QIODevice::WriteOnly)) // ouverture du fichier de sauvegarde
        return; // en �criture
    out.setDevice(&file); // association du flux au fichier



    // cr�ation de la balise "valeur"
    QDomElement val = doc.createElement("valeur");

    racine.appendChild(val); // filiation de la balise "sauvegarde"

    // cr�ation de la balise "type"
    //QDomElement type = doc.createElement("type");
    //sauvegarde.appendChild(type); // filiation de la balise "type"
    QDomText v = doc.createTextNode(t); // cr�ation de la donn�e t1
    val.appendChild(v); // filiation du n�ud "v"*/
}

void Dom::newfic()
{
    racine=doc.createElement("sauvegardes");
    doc.appendChild(racine); // filiation de la balise "sauvegarde"

}

Dom::~Dom()
{
    // insertion en d�but de document de <?xml version="1.0" ?>
    QDomNode noeud = doc.createProcessingInstruction("xml","version=\"1.0\"");
    doc.insertBefore(noeud,doc.firstChild());
    // sauvegarde dans le flux (deux espaces de d�calage dans l'arborescence)
    doc.save(out,2);
    file.close();
}


void Dom::lire()
{
    qDebug()<<"pile1";
    QFile file("sauvegarde_contexte.xml");
    if (!file.open(QIODevice::ReadOnly)){return;}
    if (!doc.setContent(&file))
    {
        file.close(); // �tablit le document XML � partir des donn�es du fichier (hi�rarchie, etc.)
        return;
    }
    file.close();

    int i=0;
    QDomNodeList tab;
    QDomElement sauvegarde;
    QDomNode n;
    QDomElement racine = doc.documentElement(); // renvoie la balise racine
    QDomNode noeud = racine.firstChild(); // renvoie la premi�re balise � sauvegarde �
   // while(!noeud.isNull())
    //{
        // convertit le n�ud en �l�ment pour utiliser les
        // m�thodes tagName() et attribute()
        sauvegarde = noeud.toElement();
        // v�rifie la pr�sence de la balise � sauvegarde �
       if (sauvegarde.tagName() == "valeur")
        {
            tab = racine.childNodes(); // cr�e un tableau des enfants de � racine �
            for(i=0;i<tab.length();i++)
            {
                qDebug() << "3";
                // pour chaque enfant, on extrait la donn�e et on la push dans la pile
                n = tab.item(i);
                //reconnaissance du type :
              type *test=NULL;

                test=type_factory::getInstance().getType(n.firstChild().toText().data());

                qDebug() << "n.firstChild().toText().data()";
                qDebug() << noeud.toText().data();
                _pile.push(test);

            }

        }
        noeud = noeud.nextSibling(); // passe � la "sauvegarde" suivante
    //}
}
