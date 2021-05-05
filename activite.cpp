#include "activite.h"
#include<QPainter>
#include<QPdfWriter>
/*activite::activite()
{

}
*/
activite::activite(int idact,QString typeact,QString nomact,QString dateact,QString duree)
{
this->idact=idact;
    this->typeact=typeact;
    this->nomact=nomact;
    this->dateact=dateact;
    this->duree=duree;

}
bool activite::ajouteract()
{
QSqlQuery query;
    //QString id= QString::number(ID);
    query.prepare("INSERT INTO ACTT (ID,typeact,duree,nomact,dateact) "
                        "VALUES (:id, :typeact, :duree,:nomact ,:dateact)");
    query.bindValue(":id",idact);
    query.bindValue(":typeact",typeact);
    query.bindValue(":duree",duree);
    query.bindValue(":nomact",nomact);
    query.bindValue(":dateact",dateact);



    return    query.exec();

}
QSqlQueryModel * activite ::afficheract()
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from ACTT");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("typeact "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("duree "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("nomact "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("dateact "));

        return model;
}

bool activite::modifieract(int idact,QString typeact, QString nomact)
{

    QSqlQuery query;
//QString idc=QString::number(id);
    query.prepare("UPDATE actt SET typeact= :typeact, nomact= :nomact where id= :id ");
    query.bindValue(":id", idact);
    query.bindValue(":typeact", typeact);
    query.bindValue(":nomact",nomact);

            return    query.exec();

}
QSqlQueryModel * activite ::afficheroncomboact()
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from actt");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));

        return model;
}

bool activite :: supprimeract(int id)
{
    //QString ident1= QString ::number(idd);
    QSqlQuery query;
    query.prepare("Delete from actt where id = :id ");
    query.bindValue(":id",id);
    return    query.exec();

}

bool activite::rechercheract(int id)
{

    QSqlQuery query;
               query.prepare("Select * from actt where ID= :ID");
               query.bindValue(":ID", id);
               query.exec();
                QSqlQueryModel * model = new QSqlQueryModel();
              model->setQuery(query);
              if(model->rowCount() == 0){ return false;}
           return  true;


}
void  activite::genererPDFact(){
                     QPdfWriter pdf("C:\\Users\\21658\\Desktop\\actedu\\p.pdf");
                     QPainter painter(&pdf);
                    int i = 4000;
                         painter.setPen(Qt::green);
                         painter.setFont(QFont("Arial", 50));
                         painter.drawText(1100,1200,"Liste Des activité");
                         painter.setPen(Qt::red);
                         painter.setFont(QFont("Arial", 15));
                         painter.drawRect(100,100,7300,2600);
                         painter.drawRect(0,3000,9600,500);
                         painter.setFont(QFont("Arial", 9));
                         painter.drawText(200,3300,"id act");
                         painter.drawText(1300,3300,"type");
                         painter.drawText(2400,3300,"nom");
                            painter.drawText(3500,3300,"date");
                               painter.drawText(4600,3300,"durée");

                         QSqlQuery query;
                         query.prepare("select * from actt");
                         query.exec();
                         while (query.next())
                         {
                             painter.drawText(200,i,query.value(0).toString());
                             painter.drawText(1300,i,query.value(1).toString());
                             painter.drawText(2400,i,query.value(2).toString());
                             painter.drawText(3500,i,query.value(3).toString());
                             painter.drawText(4600,i,query.value(4).toString());


                            i = i + 500;
                         }}
