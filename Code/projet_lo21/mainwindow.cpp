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
#include "pileaddition.h"
#include <QTextStream>



using namespace std;

MainWindow::MainWindow(Pile &pile, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    r=new reglages(this);
    QObject::connect(this, SIGNAL(keyPress(QKeyEvent*)), this, SLOT(keyPressEvent(QKeyEvent*)));
    QObject::connect(this, SIGNAL(pushStack_signal(const QString&)), this, SLOT(pushStack_slot(const QString&)));
    QObject::connect(this, SIGNAL(cleanList_signal()), this, SLOT(cleanList_slot()));
    QObject::connect(this, SIGNAL(refresh_signal()), this, SLOT(refresh_slot()));

    Collection_pile::getInstance().addPile(&pile);
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

void MainWindow::on_espace_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+" ");
}


void MainWindow::on_stackButton_clicked(){
    //emit pushStack_signal(ui->lineEdit->text());
    Collection_pile::getInstance().at(Collection_pile::getInstance().getActif())->parser(ui->lineEdit->text());

    emit refresh_signal();
    ui->lineEdit->clear();

}

void MainWindow::on_affichePile_clicked(){
    for(int i=0; i<Collection_pile::getInstance().at(Collection_pile::getInstance().getActif())->size(); i++)
        qDebug()<<((Collection_pile::getInstance().at(Collection_pile::getInstance().getActif())->at(i))->toQString())<<endl;
}

void MainWindow::on_swap_clicked(){
    Collection_pile::getInstance().at(Collection_pile::getInstance().getActif())->swap(0, 1);
    emit refresh_signal();
}

void MainWindow::on_sum_clicked(){
    Collection_pile::getInstance().at(Collection_pile::getInstance().getActif())->sum(10);
    emit refresh_signal();
}

void MainWindow::on_mean_clicked(){
    Collection_pile::getInstance().at(Collection_pile::getInstance().getActif())->mean(10);
    emit refresh_signal();
}

void MainWindow::on_clear_clicked(){
    Collection_pile::getInstance().at(Collection_pile::getInstance().getActif())->clear();
    emit cleanList_signal();
}

void MainWindow::on_dup_clicked(){
    Collection_pile::getInstance().at(Collection_pile::getInstance().getActif())->dup();
    emit refresh_signal();
}

void MainWindow::on_drop_clicked(){
    Collection_pile::getInstance().at(Collection_pile::getInstance().getActif())->drop();
    emit refresh_signal();
}


//Selection du type de constante utilise
void MainWindow::pushStack_slot(const QString& t){
    ui->list->addItem(t);
}

void MainWindow::on_backspace_clicked(){
    ui->lineEdit->backspace();
}

void MainWindow::on_intRadio_clicked(){
    if(MainWindow::selectedConstType!=ENTIER){
        Collection_pile::getInstance().at(Collection_pile::getInstance().getActif())->clear();
        ui->lineEdit->clear();
        emit cleanList_signal();
        MainWindow::selectedConstType=ENTIER;
    }
}
void MainWindow::on_doubleRadio_clicked(){
    if(MainWindow::selectedConstType!=REEL){
        Collection_pile::getInstance().at(Collection_pile::getInstance().getActif())->clear();
        ui->lineEdit->clear();
        emit cleanList_signal();
        MainWindow::selectedConstType=REEL;
    }
}
void MainWindow::on_rationalRadio_clicked(){
    if(MainWindow::selectedConstType!=RATIONNEL){
        Collection_pile::getInstance().at(Collection_pile::getInstance().getActif())->clear();
        ui->lineEdit->clear();
        emit cleanList_signal();
        MainWindow::selectedConstType=RATIONNEL;
    }
}

//Selection de l'utilisation des complexes
void MainWindow::on_yesComplex_clicked(){
    if(MainWindow::selectedComplexUse!=YES){
        Collection_pile::getInstance().at(Collection_pile::getInstance().getActif())->clear();
        ui->lineEdit->clear();
        emit cleanList_signal();
        MainWindow::selectedComplexUse=YES;
    }
}
void MainWindow::on_noComplex_clicked(){
    if(MainWindow::selectedComplexUse!=NO){
        Collection_pile::getInstance().at(Collection_pile::getInstance().getActif())->clear();
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




void MainWindow::cleanList_slot(){
    ui->list->clear();
}

void MainWindow::refresh_slot(){
    ui->list->clear();
    int n=Collection_pile::getInstance().at(Collection_pile::getInstance().getActif())->getNb();
    for(int i=Collection_pile::getInstance().at(Collection_pile::getInstance().getActif())->size()-1; i>=0 && n>0; i--){
        ui->list->addItem((Collection_pile::getInstance().at(Collection_pile::getInstance().getActif())->at(i))->toQString());
        n--;
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


void MainWindow::on_addition_clicked(){
    Collection_pile::getInstance().at(Collection_pile::getInstance().getActif())->addition();
    emit refresh_signal();
}

void MainWindow::on_soustraction_clicked()
{
    Collection_pile::getInstance().at(Collection_pile::getInstance().getActif())->soustraction();
    emit refresh_signal();
}



void MainWindow::on_multiplication_clicked()
{
    Collection_pile::getInstance().at(Collection_pile::getInstance().getActif())->multiplication();
    emit refresh_signal();
}

void MainWindow::on_division_clicked()
{
    Collection_pile::getInstance().at(Collection_pile::getInstance().getActif())->division();
    emit refresh_signal();
}




void MainWindow::on_addition_2_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+ui->addition_2->text());
}



void MainWindow::on_soustraction_2_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+ui->soustraction_2->text());
}

void MainWindow::on_multiplication_2_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+ui->multiplication_2->text());
}

void MainWindow::on_division_2_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+ui->division_2->text());
}





void MainWindow::on_actionParametre_triggered()
{
    qDebug() << "test";
    r->exec();
}

void MainWindow::on_quote_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+ui->quote->text());
}

void MainWindow::on_undo_clicked(){

}

void MainWindow::on_redo_clicked(){
    Collection_pile::getInstance().at(Collection_pile::getInstance().getActif())->undo();
    emit refresh_signal();

}

void MainWindow::createOnglet()
{
    Collection_pile::getInstance().addPile(Collection_pile::getInstance().at(Collection_pile::getInstance().getActif()));

}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    if(index>=Collection_pile::getInstance().size())
    createOnglet();
    Collection_pile::getInstance().setActif(index);
    emit refresh_signal();
}

void MainWindow::on_actionNouvel_onglet_triggered()
{


}

void MainWindow::on_actionNouvel_onglet_2_triggered()
{
    createOnglet();
    QWidget *ajout = new QTabWidget(this);
    QString res;
    QTextStream ss(&res);
    ss << "Onglet "<< Collection_pile::getInstance().size();

        ui->tabWidget->addTab(ajout,res);
}

void MainWindow::on_actionAnnuler_triggered()
{
    Collection_pile::getInstance().at(Collection_pile::getInstance().getActif())->undo();
   emit refresh_signal();
}

void MainWindow::on_actionR_tablir_triggered()
{
    Collection_pile::getInstance().at(Collection_pile::getInstance().getActif())->redo();
   emit refresh_signal();
}
