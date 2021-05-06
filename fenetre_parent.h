#ifndef FENETRE_PARENT_H
#define FENETRE_PARENT_H

#include<QString>
#include <QMainWindow>
#include <QWidget>
#include "QSqlQueryModel"

class Fenetre_Parent
{
public:
    Fenetre_Parent();
    Fenetre_Parent(int, QString, QString, QString, QString);
    void set_cin(int n);
    void set_nom(QString n);
    void set_prenom(QString n);
    void setmail(QString n);
    void setpwd(QString n);
    int get_cin();
    QString get_nom();
    QString get_prenom();
    QString get_mail();
    QString get_pwd();
    bool ajouter ();
    QSqlQueryModel* afficher();
    QSqlQueryModel* rechercher(QString);
    bool supprimer(int);
    bool modifier(int,QString ,QString ,QString ,QString);
    QSqlQueryModel* trier_parent_id();
    QSqlQueryModel* trier_parent_decroi_id();
    QSqlQueryModel* trier_parent_alpha();

private:
    int cin;
  QString nom,prenom,mail,pwd;
};

#endif // FENETRE_PARENT_H
