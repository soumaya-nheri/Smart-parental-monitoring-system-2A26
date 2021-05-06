#include "enfant.h"


enfant::enfant()
{
    Id=0;
    nom="";
    prenom="";
    Date="";
    Origine="";
    Devoir="";
}
enfant::enfant(int Id, QString nom, QString prenom, QString Date, QString Origine, QString Devoir)
{
    this->Id=Id;
    this->nom=nom;
    this->prenom=prenom;
    this->Date=Date;
    this->Origine=Origine;
    this->Devoir=Devoir;
}
bool enfant::Ajouter()
{
    QSqlQuery querry;
    QString res=QString::number(Id);
    querry.prepare("INSERT INTO ENFANT(ID,NOM,COLUMN2,D_NAIS,COLUMN4,COLUMN5)""VALUES(:Id,:nom,:prenom,:Date,:Origine,:Devoir)");
    querry.bindValue(":Id",res);
    querry.bindValue(":nom",nom);
    querry.bindValue(":prenom",prenom);
    querry.bindValue(":Date",Date);
    querry.bindValue(":Origine",Origine);
    querry.bindValue(":Devoir",Devoir);

    return querry.exec();
}
QSqlQueryModel * enfant::afficher()
{
    QSqlQueryModel *model= new QSqlQueryModel();

    model->setQuery("select * from ENFANT");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("Date"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("Origine"));
    model->setHeaderData(5, Qt::Horizontal,QObject::tr("Devoir"));
      return model;
}

bool enfant::Modifier(int Id)
{

    QSqlQuery query;
    QString res= QString::number(Id);
    query.prepare("UPDATE ENFANT SET NOM=:nom,PRENOM=:prenom,DATE=:Date,ORIGINE=:Origine,DEVOIR=:Devoir WHERE Id=:Id");
    query.bindValue(":Id", res);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":Date", Date);
    query.bindValue(":Origine", Origine);
    query.bindValue(":Devoir", Devoir);

    return    query.exec();
}

bool enfant::Supprimer(int Id)
{
QSqlQuery query;
query.prepare("Delete from Enfant where Id = :id");
query.bindValue(":ID", Id);
return    query.exec();
}
QSqlQueryModel * enfant::trier_Id()
{
    QSqlQueryModel * model=new QSqlQueryModel() ;
        model->setQuery("select * from ENFANT order by Id ASC");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
        model->setHeaderData(2, Qt::Horizontal,QObject::tr("Prenom"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Origine"));
        model->setHeaderData(5, Qt::Horizontal,QObject::tr("Devoir"));


            return model;
}
QSqlQueryModel * enfant::trier_nom()
{
    // trier nbre
    QSqlQueryModel * model=new QSqlQueryModel() ;
    model->setQuery("select * from ENFANT order by nom ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("Prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Origine"));
    model->setHeaderData(5, Qt::Horizontal,QObject::tr("Devoir"));


        return model;
}
QSqlQueryModel * enfant::trier_Origine()
{
    // trier nbre
    QSqlQueryModel * model=new QSqlQueryModel() ;
    model->setQuery("select * from ENFANT order by Origine ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("Prenom")); model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("Origine"));
    model->setHeaderData(5, Qt::Horizontal,QObject::tr("Devoir"));



        return model;
}
