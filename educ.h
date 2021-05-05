#ifndef EDUC_H
#define EDUC_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class educ
{
    QString nom;
    int ided,tel,prix,idacc;
public:
    educ(){}
    educ(int,int,QString,int,int);


    bool ajouteredu();
    QSqlQueryModel * afficheredu();
    bool modifieredu(int ided,int tel, int prix);
    QSqlQueryModel * afficheroncomboedu();
    bool  rechercheredu(int id  );
    QSqlQueryModel * trides();
       QSqlQueryModel * triasc();


    bool supprimeredu(int);
    void genererPDFedu();
      QString showoldedu(QString);

};

#endif // EDUC_H
