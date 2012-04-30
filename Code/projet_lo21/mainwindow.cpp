#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stack>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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

