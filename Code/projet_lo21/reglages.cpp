#include "reglages.h"
#include "ui_reglages.h"

reglages::reglages(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::reglages)
{
    ui->setupUi(this);
}

reglages::~reglages()
{
    delete ui;
}
