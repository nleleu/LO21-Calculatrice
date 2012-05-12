#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pile.h"
#include <QDebug>
#include "entier.h"
#include "reel.h"
#include "rationnel.h"
#include "complexe.h"
#include <QListWidget>
#include <QListWidgetItem>
#include <QString>

using namespace std;

MainWindow::MainWindow(Pile &pile, QWidget *parent) :
    _pile(pile), QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QObject::connect(this, SIGNAL(keyPress(QKeyEvent*)), this, SLOT(keyPressEvent(QKeyEvent*)));
    QObject::connect(this, SIGNAL(pushStack_signal(const QString&)), this, SLOT(pushStack_slot(const QString&)));
    QObject::connect(this, SIGNAL(cleanList_signal()), this, SLOT(cleanList_slot()));
    QObject::connect(this, SIGNAL(refresh_signal()), this, SLOT(refresh_slot()));

    ui->intRadio->setChecked(true);
    ui->noComplex->setChecked(true);
    ui->degUnit->setChecked(true);
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
    emit pushStack_signal(ui->lineEdit->text());

    type* test=NULL;

    //reconnaissance du type :
    if(entier::isEntier(ui->lineEdit->text()))
        test=new entier(ui->lineEdit->text());
    if(reel::isReel(ui->lineEdit->text()))
        test=new reel(ui->lineEdit->text());
    //if(rationnel::isRationnel(ui->lineEdit->text()))
      //  test=new rationnel(ui->lineEdit->text());
    //if(complexe::isComplexe(ui->lineEdit->text()))
        //*test=new complexe(ui->lineEdit->text().toStdString());

    _pile.push(test);
    ui->lineEdit->clear();
}

void MainWindow::on_affichePile_clicked(){
    for(int i=0; i<_pile.size(); i++)
        qDebug()<<QString::fromStdString(((_pile.at(i))->toString()))<<endl;
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
    emit cleanList_signal();
}

void MainWindow::on_dup_clicked(){
    _pile.dup();
    emit refresh_signal();
}

void MainWindow::on_drop_clicked(){
    _pile.drop();
    emit refresh_signal();
}


//Selection du type de constante utilise
void MainWindow::pushStack_slot(const QString& t){
    ui->list->addItem(t);
}
void MainWindow::on_intRadio_clicked(){
    if(MainWindow::selectedConstType!=ENTIER){
        _pile.clear();
        ui->lineEdit->clear();
        emit cleanList_signal();
        MainWindow::selectedConstType=ENTIER;
    }
}
void MainWindow::on_doubleRadio_clicked(){
    if(MainWindow::selectedConstType!=REEL){
        _pile.clear();
        ui->lineEdit->clear();
        emit cleanList_signal();
        MainWindow::selectedConstType=REEL;
    }
}
void MainWindow::on_rationalRadio_clicked(){
    if(MainWindow::selectedConstType!=RATIONNEL){
        _pile.clear();
        ui->lineEdit->clear();
        emit cleanList_signal();
        MainWindow::selectedConstType=RATIONNEL;
    }
}

//Selection de l'utilisation des complexes
void MainWindow::on_yesComplex_clicked(){
    if(MainWindow::selectedComplexUse!=YES){
        _pile.clear();
        ui->lineEdit->clear();
        emit cleanList_signal();
        MainWindow::selectedComplexUse=YES;
    }
}
void MainWindow::on_noComplex_clicked(){
    if(MainWindow::selectedComplexUse!=NO){
        _pile.clear();
        ui->lineEdit->clear();
        emit cleanList_signal();
        MainWindow::selectedComplexUse=NO;
    }
}

//Selection de l'unite des degres
void MainWindow::on_degUnit_clicked(){
    MainWindow::selectedDegUnit=DEGRE;
}
void MainWindow::on_radUnit_clicked(){
    MainWindow::selectedDegUnit=RADIANT;
}


void MainWindow::on_addition_clicked(){
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

void MainWindow::cleanList_slot(){
    ui->list->clear();
}

void MainWindow::refresh_slot(){
    ui->list->clear();
    for(int i=0; i<_pile.size(); i++){
        ui->list->addItem(QString::fromStdString((_pile.at(i))->toString()));
    }
}

void MainWindow::on_complexeButton_clicked(){
    if(selectedComplexUse==YES){
        if(!ui->lineEdit->text().contains('$'))
            ui->lineEdit->setText(ui->lineEdit->text()+'$');
    }

    else
        qDebug()<<"action impossible hors du mode utilisation des complexes";
}

void MainWindow::on_reelButton_clicked(){
    if(selectedConstType==REEL){
        if(!ui->lineEdit->text().contains('$')){
            if(!ui->lineEdit->text().section('$', 0).contains(',')){
                ui->lineEdit->setText(ui->lineEdit->text()+',');
            }
        }

        else{
            if(!ui->lineEdit->text().section('$', 1).contains(',')){
                ui->lineEdit->setText(ui->lineEdit->text()+',');
            }
        }
    }

    else
        qDebug()<<"action impossible hors du mode constante reel";
}

void MainWindow::on_rationnelButton_clicked(){
    if(selectedConstType==RATIONNEL){
        if(!ui->lineEdit->text().contains('$')){
            if(!ui->lineEdit->text().section('$', 0).contains('/')){
                 ui->lineEdit->setText(ui->lineEdit->text()+'/');
              }
         }

         else{
              if(!ui->lineEdit->text().section('$', 1).contains("/")){
                  ui->lineEdit->setText(ui->lineEdit->text()+'/');
               }
         }
     }

    else
        qDebug()<<"action impossible hors du mode constante rationnel";
}

