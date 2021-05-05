#include "parent.h"
parentt::parentt()
{


}
parentt::parentt(int idp,QString nom,int tel,int nbre)
{
this->idp=idp;
    this->nom=nom;
    this->tel=tel;
    this->nbre=nbre;

}

bool parentt::ajouter()
{
QSqlQuery query;
    //QString id= QString::number(ID);
    query.prepare("INSERT INTO par (idp,nom,tel,nbre) "
                        "VALUES (:idp, :nom, :tel,:nbre)");
    query.bindValue(":idp",idp);
    query.bindValue(":nom",nom);
    query.bindValue(":tel",tel);
    query.bindValue(":nbre",nbre);


    return    query.exec();

}

QSqlQueryModel * parentt ::afficher()
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from par");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("idp"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("tel "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("nbre "));


        return model;
}

bool parentt::modifier(int idp , int tel ,int nbre)
{

    QSqlQuery query;
//QString idc=QString::number(id);
    query.prepare("UPDATE par SET tel= :tel, nbre= :nbre where idp= :idp ");
    query.bindValue(":idp", idp);
    query.bindValue(":tel", tel);
    query.bindValue(":nbre",nbre);

            return    query.exec();

}

QSqlQueryModel * parentt ::afficheroncombo()
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from par");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("idp"));

        return model;
}

bool parentt :: supprimer(int idp)
{
   // QString ident1= QString ::number(idd);
    QSqlQuery query;
    query.prepare("Delete from par where idp = :idp ");
    query.bindValue(":idp",idp);
    return    query.exec();

}
QSqlQueryModel* parentt::trides()
{
    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("select * from par order by idp DESC");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("idp"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom "));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("tel "));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("nbre "));




            return model;
}

QSqlQueryModel * parentt::triasc()
{
    QSqlQueryModel * model= new QSqlQueryModel();
       model->setQuery("select * from par order by idp ASC");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("idp"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom "));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("tel "));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("nbre "));

           return model;
}
