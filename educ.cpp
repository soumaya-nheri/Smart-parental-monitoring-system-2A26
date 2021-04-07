#include "educ.h"
#include "activite.h"

educ::educ(int ided,int idacc,QString nom,int tel,int prix)
{
    this->ided=ided;
        this->idacc=idacc;
        this->nom=nom;
        this->tel=tel;
        this->prix=prix;
}
bool educ::ajouteredu()
{
QSqlQuery query;
    //QString id= QString::number(ID);
    query.prepare("INSERT INTO edu (ided,idac,nom,tel,prix) "
                        "VALUES (:ided, :idac, :nom,:tel ,:prix)");
    query.bindValue(":ided",ided);
    query.bindValue(":idac",idacc);
    query.bindValue(":nom",nom);
    query.bindValue(":tel",tel);
    query.bindValue(":prix",prix);



    return    query.exec();

}
QSqlQueryModel * educ ::afficheredu()
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from edu");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ided"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("idac "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("tel "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("prix "));

        return model;
}

bool educ::modifieredu(int ided,int tel, int prix)
{

    QSqlQuery query;
//QString idc=QString::number(id);
    query.prepare("UPDATE edu SET tel= :tel, prix= :prix where ided= :ided ");
    query.bindValue(":ided", ided);
    query.bindValue(":tel", tel);
    query.bindValue(":prix",prix);

            return    query.exec();

}
QSqlQueryModel * educ ::afficheroncomboedu()
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from edu");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ided"));

        return model;
}

bool educ :: supprimeredu(int id)
{
    //QString ident1= QString ::number(idd);
    QSqlQuery query;
    query.prepare("Delete from edu where ided = :id ");
    query.bindValue(":id",id);
    return    query.exec();

}
QSqlQueryModel* educ::trides()
{
    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("select * from edu order by prix DESC");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ided"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("idac "));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom "));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("tel "));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("prix "));



            return model;
}

QSqlQueryModel * educ::triasc()
{
    QSqlQueryModel * model= new QSqlQueryModel();
       model->setQuery("select * from edu order by prix ASC");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("ided"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("idac "));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom "));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("tel "));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("prix "));

           return model;
}

