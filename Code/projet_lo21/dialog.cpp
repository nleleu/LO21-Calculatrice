#include "dialog.h"
#include "ui_dialog.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QListWidget>
#include <QListWidgetItem>
#include <QString>
#include <QtDebug>
#include "pile.h"



Dialog::Dialog(Pile &pile, QWidget *parent) :
    _pile(pile), QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    QObject::connect(parent, SIGNAL(ajouterStack(const QString&)), this, SLOT(stocke(const QString&)));
    QObject::connect(parent, SIGNAL(nettoyerList()), this, SLOT(listNettoye()));
    QObject::connect(parent, SIGNAL(refresh_signal()), this, SLOT(refresh_slot()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::stocke(const QString& t){
    ui->list->addItem(t);
}

void Dialog::on_addition_clicked(){
    QListWidgetItem *pt1 = new QListWidgetItem;
    QListWidgetItem *pt2 = new QListWidgetItem;

    pt1 = ui->list->takeItem(ui->list->count()-1);
    pt2 = ui->list->takeItem(ui->list->count()-1);


    if(pt1!=NULL && pt2!=NULL){
        type *op1 = _pile.pop();
        type *op2 = _pile.pop();
        type *res;
        *op1=*op1+*op2;
        _pile.push(res);

       // pt1->setText(QString::number(op1, 10));
    }

    ui->list->addItem(pt1);
    delete pt2;
}

void Dialog::listNettoye(){
    ui->list->clear();
}

void Dialog::refresh_slot(){
    ui->list->clear();
    for(int i=0; i<_pile.size(); i++){
        ui->list->addItem("QString::number(_pile.at(i), 10)");
    }
}
