#include "auth.h"
#include <QApplication>
#include <QMessageBox>
#include <QDebug>
#include "connection.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Auth w;
    w.show();
    Connection c;
    bool test=c.createconnect();
    if(test)
    {w.show();
        QMessageBox::information(nullptr, QObject::tr("Bienvenue"),
                    QObject::tr("Veuillez vous connecter.\n"
                                "Appuyez Cancel pour sortir."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                    QObject::tr("Il y'a un probleme de connection.\n"
                                "Cancel pour sortir."), QMessageBox::Cancel);



    return a.exec();
}
