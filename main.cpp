#include "dialogmelek.h"
#include "connexion.h"
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    connexion c;
    bool test=c.create_cnx();

    Dialogmelek w;
    if(test)
    {    w.show();
        QMessageBox::information(nullptr,QObject::tr("database is open"),
                                 QObject::tr("connection succful .\n"),
                QMessageBox::Ok);
    }

    else
        //qDebug()<<"connexion echouer";
        QMessageBox::critical(nullptr,QObject::tr("database is not open"),
                                QObject::tr("non connecter"),
                                QMessageBox::Cancel);
         //qDebug()<<"connexion echouer";




    w.show();
    return a.exec();
}
