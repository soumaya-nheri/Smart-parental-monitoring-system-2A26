#include "site.h"
#include <QVariant>
site::site()
{

}
site::site(int id,QString nom,QString type,QString lien)
{
this->id=id;
    this->nom=nom;
    this->type=type;
    this->lien=lien;
}
bool site::ajouter()
{
    QSqlQuery q;
    q.prepare("insert into site values(:id,:nom,:type,:lien)");
    q.bindValue(":id",id);
    q.bindValue(":type",type);
    q.bindValue(":nom",nom);
    q.bindValue(":lien",lien);
    return q.exec();
}
bool site::supprimer(int id)
{
    QSqlQuery q;
    q.prepare("delete from site where id=:id");
    q.bindValue(":id",id);
    return q.exec();
}

QSqlQueryModel * site::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from site");
    return model;
}
bool site::modifier(int id)
{
    QSqlQuery q;
    q.prepare("update site set type=:type,nom=:nom,lien=:lien where id=:id");
    q.bindValue(":id",id);
    q.bindValue(":type",type);
    q.bindValue(":nom",nom);
    q.bindValue(":lien",lien);
    return q.exec();


}

QSqlQueryModel * site::tri()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from site order by nom");
    return model;
}
QSqlQueryModel * site::afficherRech(int id)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QString id_str=QString::number(id);
    model->setQuery("select * from site where id like '"+id_str+"%'");
    return model;
}

