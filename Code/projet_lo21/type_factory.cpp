#include "type_factory.h"
#include "entier.h"
#include "reel.h"
#include "rationnel.h"
#include "complexe.h"
#include <QDebug>
#include "expression.h"
#include "typeexception.h"

type_factory* type_factory::instance=0;

type_factory& type_factory::getInstance()
{
    if (instance==0)
        instance = new type_factory;
    return *instance;

}

void type_factory::releaseInstance()
{
    if (instance!=0)
        delete instance;
}

type* type_factory::getType(QString s)
{
        if(type::isComplexe(s))
        {
        return new complexe(s);
        }
        if(type::isEntier(s))
            return new entier(s);
        if(type::isReel(s))
            return new reel(s);
        if(rationnel::isRationnel(s))
        {
            try
        {
            type* res= new rationnel(s);
            return res;
        }catch (std::exception &e) {
            QMessageBox msgBox;
             msgBox.setText(e.what());
             msgBox.exec();
        }
        }
        if(type::isExpression(s))
            return new Expression(s);
        else
        {
            return NULL;
        }
}
