#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "ui_dialog.h"
#include "pile.h"
#include <QDebug>
#include "entier.h"
#include "reel.h"
#include "rationnel.h"
#include "complexe.h"



MainWindow::MainWindow(Pile &pile, QWidget *parent) :
    _pile(pile), QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(this, SIGNAL(keyPress(QKeyEvent*)), this, SLOT(keyPressEvent(QKeyEvent*)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Connexion des pushButton 0 à 9
void MainWindow::on_pushButton0_clicked(){
    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton0->text());
}
void MainWindow::on_pushButton1_clicked(){
    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton1->text());
}
void MainWindow::on_pushButton2_clicked(){
    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton2->text());
}
void MainWindow::on_pushButton3_clicked(){
    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton3->text());
}
void MainWindow::on_pushButton4_clicked(){
    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton4->text());
}
void MainWindow::on_pushButton5_clicked(){
    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton5->text());
}
void MainWindow::on_pushButton6_clicked(){
    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton6->text());
}
void MainWindow::on_pushButton7_clicked(){
    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton7->text());
}
void MainWindow::on_pushButton8_clicked(){
    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton8->text());
}
void MainWindow::on_pushButton9_clicked(){
    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton9->text());
}

void MainWindow::on_stackButton_clicked(){
    emit ajouterStack(ui->lineEdit->text());

    //reconnaissance du type :
    //if(type::isEntier(ui->lineEdit->text()))
      //  entier *test=new entier(ui->lineEdit->text().toInt());
    if(type::isReel(ui->lineEdit->text()))
        reel *test=new reel(ui->lineEdit->text().toDouble());
    //if(type::isRationnel(ui->lineEdit->text()))
      //  rationnel *test=new entier(ui->lineEdit->text().toInt());
    /*if(type::isComplexe(ui->lineEdit->text()))
        complexe *test=new entier(ui->lineEdit->text().toInt());*/


    //_pile.push(test);
    ui->lineEdit->clear();
}

void MainWindow::on_affichePile_clicked(){
    //for(int i=0; i<_pile.size(); i++)
        //qDebug()<<QString::number(_pile.at(i), 10); //revoir
}

void MainWindow::on_swap_clicked(){
    _pile.swap(0, 1);
    emit refresh_signal();
}

void MainWindow::on_sum_clicked(){
    _pile.sum(10);
    emit refresh_signal();
}

void MainWindow::on_mean_clicked(){
    _pile.mean(10);
    emit refresh_signal();
}

void MainWindow::on_clear_clicked(){
    _pile.clear();
    emit nettoyerList();
}

void MainWindow::on_dup_clicked(){
    _pile.dup();
    emit refresh_signal();
}

void MainWindow::on_drop_clicked(){
    _pile.drop();
    emit refresh_signal();
}

