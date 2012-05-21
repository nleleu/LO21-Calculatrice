#include "dom.h"
#include "entier.h"
#include "reel.h"
#include "rationnel.h"
#include "complexe.h"
#include "type_factory.h"


Dom::Dom(Pile & pile): _pile(pile){}


void Dom::demande_ajout(QString n,QString t)
{
     // création de la balise "sauvegarde"
   // doc.appendChild(sauvegardes); // filiation de la balise "sauvegarde"
    file.setFileName("sauvegarde_contexte.xml");
    if (!file.open(QIODevice::WriteOnly)) // ouverture du fichier de sauvegarde
        return; // en écriture
    out.setDevice(&file); // association du flux au fichier



    // création de la balise "valeur"
    QDomElement val = doc.createElement("valeur");

    racine.appendChild(val); // filiation de la balise "sauvegarde"

    // création de la balise "type"
    //QDomElement type = doc.createElement("type");
    //sauvegarde.appendChild(type); // filiation de la balise "type"
    QDomText v = doc.createTextNode(t); // création de la donnée t1
    val.appendChild(v); // filiation du nœud "v"*/
}

void Dom::newfic()
{
    racine=doc.createElement("sauvegardes");
    doc.appendChild(racine); // filiation de la balise "sauvegarde"

}

Dom::~Dom()
{
    // insertion en début de document de <?xml version="1.0" ?>
    QDomNode noeud = doc.createProcessingInstruction("xml","version=\"1.0\"");
    doc.insertBefore(noeud,doc.firstChild());
    // sauvegarde dans le flux (deux espaces de décalage dans l'arborescence)
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
        file.close(); // établit le document XML à partir des données du fichier (hiérarchie, etc.)
        return;
    }
    file.close();

    int i=0;
    QDomNodeList tab;
    QDomElement sauvegarde;
    QDomNode n;
    QDomElement racine = doc.documentElement(); // renvoie la balise racine
    QDomNode noeud = racine.firstChild(); // renvoie la première balise « sauvegarde »
   // while(!noeud.isNull())
    //{
        // convertit le nœud en élément pour utiliser les
        // méthodes tagName() et attribute()
        sauvegarde = noeud.toElement();
        // vérifie la présence de la balise « sauvegarde »
       if (sauvegarde.tagName() == "valeur")
        {
            tab = racine.childNodes(); // crée un tableau des enfants de « racine »
            for(i=0;i<tab.length();i++)
            {
                qDebug() << "3";
                // pour chaque enfant, on extrait la donnée et on la push dans la pile
                n = tab.item(i);
                //reconnaissance du type :
              type *test=NULL;

                test=type_factory::getInstance().getType(n.firstChild().toText().data());

                qDebug() << "n.firstChild().toText().data()";
                qDebug() << noeud.toText().data();
                _pile.push(test);

            }

        }
        noeud = noeud.nextSibling(); // passe à la "sauvegarde" suivante
    //}
}
