#include "login.h"
#include "ui_login.h"
#include<QMessageBox>
#include"afterlogin.h"

login::login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}


void login::on_pushButton_clicked()
{
    if((ui->lineEdit->text()=="admin")&&(ui->lineEdit_2->text()=="admin"))
     {

           QMessageBox::information(this,"Sucess","Accee garantie");
           hide();
           afterlogin baaedlogg;
           baaedlogg.setModal(true);
           baaedlogg.exec();
     }
         else
         {
             QMessageBox::information(this,"Erreur","Verifier vos informations");

         }
}
