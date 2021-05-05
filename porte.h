#ifndef PORTE_H
#define PORTE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class porte
{

public:
    porte();
    porte(int,QString,QString,QString);
    bool ajouter();
    bool supprimer(int);
    QSqlQueryModel * afficher();
    QSqlQueryModel * tri(QString);
     QSqlQueryModel * afficherRech(int);
    bool modifier(int);
private:
    int id;
    QString type;
    QString nom;
    QString description;
};

#endif // PORTE_H
