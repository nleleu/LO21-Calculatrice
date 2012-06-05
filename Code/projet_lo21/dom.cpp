#include "dom.h"
#include "entier.h"
#include "reel.h"
#include "rationnel.h"
#include "complexe.h"
#include "type_factory.h"


Dom::Dom(Pile & pile): _pile(pile){}


void Dom::ecrire(QString fileName)
{
    doc.clear();
    racine=doc.createElement("sauvegardes");
    doc.appendChild(racine); // filiation de la balise "sauvegarde"

    file.setFileName(fileName);
    if (!file.open(QIODevice::WriteOnly)) // ouverture du fichier de sauvegarde
        return; // en écriture
    out.setDevice(&file); // association du flux au fichier


    for(int i=0; i<_pile.size(); i++){
        sauvegarde=doc.createElement("sauvegarde");
        sauvegarde.setAttribute("valeur", _pile.at(i)->toQString());
        racine.appendChild(sauvegarde);
    }
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


void Dom::lire(QString fileName)
{
    file.setFileName(fileName);
    if (!file.open(QIODevice::ReadOnly)){return;}
    if (!doc.setContent(&file))
    {
        file.close(); // établit le document XML à partir des données du fichier (hiérarchie, etc.)
        return;
    }
    file.close();


    QDomElement root = doc.documentElement();
    QDomNode n = root.firstChild();
    while( !n.isNull() )
    {
      QDomElement e = n.toElement();
      if( !e.isNull() )
      {
        if( e.tagName() == "sauvegarde" )
        {
            type *t;
            t=type_factory::getInstance().getType(e.attribute( "valeur", "" ));

            _pile.push(t);

        }
      }

      n = n.nextSibling();
    }
}
