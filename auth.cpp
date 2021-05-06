#include "auth.h"
#include "ui_auth.h"
#include "connection.h"
#include "fenetre_parent.h"
#include "user.h"
#include <QDebug>

Auth::Auth(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Auth)
{
    ui->setupUi(this);
}

Auth::~Auth()
{
    delete ui;
}

void Auth::on_btn_connect_clicked()
{
        QString mail = ui->mail->text();
        QString  pwd = ui->pwd->text();
        QSqlQuery qry;
            qry.prepare("SELECT MAIL, MOT_DE_PASSE from PARENT WHERE MAIL = :username AND MOT_DE_PASSE = :password");
            qry.bindValue(":username", mail);
            qry.bindValue(":password", pwd);
            qry.exec();
            int counter = 0;
            while (qry.next()){
                counter++;
            }
            if(counter==1)
            {
                qDebug() << "success login.";
            User u;
            u.exec();
            }
            if(counter<1)
                qDebug() << "failed while login.";
}
