#ifndef PARENT_H
#define PARENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class parentt
{
    int idp,tel,nbre;
    QString nom;
public:
    parentt();
    parentt(int,QString,int,int);
    bool ajouter();
    QSqlQueryModel * afficher();
    bool modifier(int idp,int tel, int nbre);
    bool supprimer(int);
     QSqlQueryModel * afficheroncombo();
     QSqlQueryModel * trides();
        QSqlQueryModel * triasc();
};

#endif // PARENT_H
