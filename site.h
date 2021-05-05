#ifndef site_H
#define site_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class site
{

public:
    site();
    site(int,QString,QString,QString);
    bool ajouter();
    bool supprimer(int);
    QSqlQueryModel * afficher();
    QSqlQueryModel * tri();
     QSqlQueryModel * afficherRech(int);
    bool modifier(int);
private:
    int id;
    QString nom;
    QString type;
    QString lien;
};

#endif // site_H
