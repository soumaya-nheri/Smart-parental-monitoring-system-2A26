#include "porte.h"
#include <QVariant>
porte::porte()
{

}
porte::porte(int id,QString type,QString nom,QString description)
{
this->id=id;
    this->type=type;
    this->nom=nom;
    this->type=type;
    this->description=description;
}
bool porte::ajouter()
{
    QSqlQuery q;
    q.prepare("insert into porte values(:id,:type,:nom,:description)");
    q.bindValue(":id",id);
    q.bindValue(":type",type);
    q.bindValue(":nom",nom);
    q.bindValue(":description",description);
    return q.exec();
}
bool porte::supprimer(int id)
{
    QSqlQuery q;
    q.prepare("delete from porte where id=:id");
    q.bindValue(":id",id);
    return q.exec();
}

QSqlQueryModel * porte::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();//representation graphique du table sql
    model->setQuery("select * from porte");
    return model;
}
bool porte::modifier(int id)
{
    QSqlQuery q;
    q.prepare("update porte set type=:type,nom=:nom,description=:description where id=:id");
    q.bindValue(":id",id);
    q.bindValue(":type",type);
    q.bindValue(":nom",nom);
    q.bindValue(":description",description);
    return q.exec();


}

QSqlQueryModel * porte::tri(QString selon)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from porte order by "+selon+"");
    return model;
}
QSqlQueryModel * porte::afficherRech(int id)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QString id_str=QString::number(id);
    model->setQuery("select * from porte where id like '"+id_str+"%'");
    return model;
}

