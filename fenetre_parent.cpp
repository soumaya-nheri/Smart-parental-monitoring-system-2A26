#include "fenetre_parent.h"
#include <QSqlQuery>
#include<QDebug>
#include<QObject>

Fenetre_Parent::Fenetre_Parent()
{
  cin=0; nom="";prenom=""; mail=""; pwd="";
}
Fenetre_Parent::Fenetre_Parent(int cin,QString nom,QString prenom,QString mail,QString pwd)
{this->cin=cin; this->nom=nom; this->prenom=prenom; this->mail=mail; this->pwd=pwd;}

void Fenetre_Parent::set_cin(int n){cin=n;}
void Fenetre_Parent::set_nom(QString n){nom=n;}
void Fenetre_Parent::set_prenom(QString n){prenom=n;}
void Fenetre_Parent::setmail(QString n){mail=n;}
void Fenetre_Parent::setpwd(QString n){pwd=n;}

int Fenetre_Parent::get_cin(){return cin;}
QString Fenetre_Parent::get_nom(){return nom;}
QString Fenetre_Parent::get_prenom(){return prenom;}
QString Fenetre_Parent::get_mail(){return mail;}
QString Fenetre_Parent::get_pwd(){return pwd;}

bool Fenetre_Parent::ajouter()
{
    QSqlQuery query;

    QString id_string = QString::number(cin);
    query.prepare("INSERT INTO PARENT (CIN,NOM,PRENOM,MAIL,MOT_DE_PASSE)""VALUES(:cin, :forename, :surname, :mail, :pwd)");
    query.bindValue(":cin",id_string);
    query.bindValue(":forename",nom);
    query.bindValue(":surname",prenom);
    query.bindValue(":mail",mail);
    query.bindValue(":pwd",pwd);
    return query.exec();
}

bool Fenetre_Parent::supprimer(int id)
{
    QSqlQuery query;

    query.prepare("DELETE FROM PARENT WHERE cin=:id");
    query.bindValue(":id", id);
    return query.exec();
}

QSqlQueryModel* Fenetre_Parent::afficher()
{
     QSqlQueryModel* model=new QSqlQueryModel();
     model->setQuery("SELECT* FROM PARENT");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("mail"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("password"));

     return model;
}

bool Fenetre_Parent::modifier(int cin,QString nom,QString prenom,QString mail,QString mdp)
{
    QSqlQuery query;
    QString res= QString::number(cin);

    query.prepare("update PARENT set CIN=:ID, NOM=:nom, PRENOM=:prenom, MAIL=:mail ,MOT_DE_PASSE=:mdp  where CIN =:ID");
    query.bindValue(":ID",res);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":mail",mail);
    query.bindValue(":mdp",mdp);
    return    query.exec();

}

QSqlQueryModel* Fenetre_Parent::rechercher(QString N)
{
    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("SELECT * FROM PARENT WHERE CIN ='"+N+"' ;");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("MAIL"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("MOT DE PASSE"));
        return model ;
}

QSqlQueryModel* Fenetre_Parent::trier_parent_id()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from PARENT ORDER BY CIN ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("MAIL"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("MOT DE PASSE"));
    return model;
}

QSqlQueryModel* Fenetre_Parent::trier_parent_decroi_id()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from PARENT ORDER BY CIN DESC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("MAIL"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("MOT DE PASSE"));
    return model;
}

QSqlQueryModel* Fenetre_Parent::trier_parent_alpha()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from PARENT ORDER BY NOM");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("MAIL"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("MOT DE PASSE"));
    return model;
}


