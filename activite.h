#ifndef ACTIVITE_H
#define ACTIVITE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class activite
{
    QString typeact,nomact,dateact,duree;
    int idact;
public:
    activite(){}
    activite(int,QString,QString,QString,QString);
    bool ajouteract();
    QSqlQueryModel * afficheract();
    bool modifieract(int idact,QString typeact, QString nomact);
    QSqlQueryModel * afficheroncomboact();
    bool  rechercheract(int id  );
    bool supprimeract(int);
    void genererPDFact();


};

#endif // ACTIVITE_H
