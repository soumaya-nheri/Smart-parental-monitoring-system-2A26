#include "afterlogin.h"
#include "ui_afterlogin.h"
#include<QMessageBox>
#include"dialog.h"
#include"mainwindow.h"
#include"dialogmelek.h"
afterlogin::afterlogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::afterlogin)
{
    ui->setupUi(this);
}

afterlogin::~afterlogin()
{
    delete ui;
}

void afterlogin::on_pushButton_clicked()
{
    hide();
    Dialog baaedlogg;
    baaedlogg.setModal(true);
    baaedlogg.exec();
}

void afterlogin::on_pushButton_4_clicked()
{
    hide();
    MainWindow *log;
    log=new MainWindow();
    log->show();

}

void afterlogin::on_pushButton_3_clicked()
{

    hide();
    Dialogmelek baaedlogg;
    baaedlogg.setModal(true);
    baaedlogg.exec();
}
