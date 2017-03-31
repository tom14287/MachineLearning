#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDesktopWidget>
#include <QScreen>
#include <QMessageBox>
#include <QMetaEnum>
#include <QLabel>


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

void MainWindow::on_button_NB_clicked()
{
   this->hide();
    dialognb.show();
    dialognb.exec();
    this->show();

}



void MainWindow::on_button_EM_clicked()
{
   this->hide();
    dialogem.show();
    dialogem.exec();
    this->show();

}



void MainWindow::on_button_NB_2_clicked()
{
    this->hide();
    dialoghmm.show();
    dialoghmm.exec();
    this->show();
}

void MainWindow::on_button_CRF_clicked()
{
    this->hide();
    dialogcrf.show();
    dialogcrf.exec();
    this->show();
}
