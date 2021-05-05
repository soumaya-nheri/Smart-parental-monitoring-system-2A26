#include "dialogmelek.h"
#include "ui_dialogmelek.h"
#include "activite.h"
//#include "stateduact.h"
#include "educ.h"
#include <QFileDialog>
#include <QtDebug>
#include <QFile>
#include<QMessageBox>
#include<QPainter>
#include<QPdfWriter>
#include"login.h"
Dialogmelek::Dialogmelek(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialogmelek)
{
    ui->setupUi(this);
     ui->tableView_act->setModel(ac.afficheract());
     ui->comboBox_2_idact->setModel(ac.afficheroncomboact());
     ui->comboBox_3_idact->setModel(ac.afficheroncomboact());
     ui->comboBox_idaced->setModel(ac.afficheroncomboact());

     ui->tableView_edu->setModel(ed.afficheredu());
     ui->comboBox_edu->setModel(ed.afficheroncomboedu());
     ui->comboBox_edu_2->setModel(ed.afficheroncomboedu());


}

Dialogmelek::~Dialogmelek()
{
    delete ui;

}


void Dialogmelek::on_pushButton_ajouteract_clicked()
{
    activite a(ui->lineEdit_idact->text().toInt(),ui->comboBox_typact->currentText(),ui->lineEdit_nomact->text(),ui->dateEdit_act->text(),ui->doubleSpinBox_act->text());
       bool test= a.ajouteract();
       ui->tableView_act->setModel(ac.afficheract());
}

void Dialogmelek::on_comboBox_2_idact_currentIndexChanged(int index)
{

        ui->comboBox_2_idact->currentText();
}

void Dialogmelek::on_pushButton_ajouteract_2_clicked()
{
    bool    test=ac.modifieract(ui->comboBox_2_idact->currentText().toInt(),ui->comboBox_typact_2->currentText(),ui->lineEdit_nomact_2->text()) ;
          if (test)
          {
                  ui->tableView_act->setModel(ac.afficheract());
              QMessageBox::information(nullptr,QObject::tr("OK"),
                                   QObject::tr("modification établie"),
                                   QMessageBox::Ok);}
          else{
          QMessageBox::critical(nullptr,QObject::tr("ERROR404"),
                                  QObject::tr("modification non établie"),
                                  QMessageBox::Cancel);}
}

void Dialogmelek::on_comboBox_3_idact_currentIndexChanged(int index)
{
        ui->comboBox_3_idact->currentText();
}

void Dialogmelek::on_pushButton_suppract_3_clicked()
{
    bool test=ac.supprimeract(ui->comboBox_3_idact->currentText().toInt());
    if(test)
    {ui->tableView_act->setModel(ac.afficheract());//actualisation taa afficher
            QMessageBox::information(nullptr,QObject::tr("ok"),
                                     QObject::tr("suppression succful .\n"),
                    QMessageBox::Cancel);
        }

        else
            QMessageBox::critical(nullptr,QObject::tr("supprimer not open"),
                                    QObject::tr("click cancel to exist"),
                                    QMessageBox::Cancel);
}
/*////////////////////////////////////////*/

void Dialogmelek::on_comboBox_idaced_currentIndexChanged(int index)
{
     ui->comboBox_idaced->currentText();
}

void Dialogmelek::on_pushButton_ajouteredu_clicked()
{
    educ e(ui->lineEdit_ided->text().toInt(),ui->comboBox_idaced->currentText().toInt(),ui->lineEdit_nomed->text(),ui->lineEdit_tel->text().toInt(),ui->lineEdit_prix->text().toInt());
       bool test= e.ajouteredu();
       ui->tableView_edu->setModel(ed.afficheredu());


}



void Dialogmelek::on_pushButton_modedu_clicked()
{
    bool    test=ed.modifieredu(ui->comboBox_edu->currentText().toInt(),ui->lineEdit_tel_2->text().toInt(),ui->lineEdit_prix_2->text().toInt()) ;
          if (test)
          {
                  ui->tableView_edu->setModel(ed.afficheredu());
              QMessageBox::information(nullptr,QObject::tr("OK"),
                                   QObject::tr("modification établie"),
                                   QMessageBox::Ok);}
          else{
          QMessageBox::critical(nullptr,QObject::tr("ERROR404"),
                                  QObject::tr("modification non établie"),
                                  QMessageBox::Cancel);}
}

void Dialogmelek::on_pushButton_suppedu_clicked()
{
    bool test=ed.supprimeredu(ui->comboBox_edu_2->currentText().toInt());
    if(test)
    {ui->tableView_edu->setModel(ed.afficheredu());//actualisation taa afficher
            QMessageBox::information(nullptr,QObject::tr("ok"),
                                     QObject::tr("suppression succful .\n"),
                    QMessageBox::Cancel);
        }

        else
            QMessageBox::critical(nullptr,QObject::tr("supprimer not open"),
                                    QObject::tr("click cancel to exist"),
                                    QMessageBox::Cancel);
}

void Dialogmelek::on_pushButton_tri_clicked()
{
    educ *e =new  educ(ui->lineEdit_ided->text().toInt(),ui->comboBox_idaced->currentText().toInt(),ui->lineEdit_nomed->text(),ui->lineEdit_tel->text().toInt(),ui->lineEdit_prix->text().toInt());
    if(ui->asc->isChecked()){
       ui->tableView_edu->setModel(e->triasc());

    }
    if(ui->desc->isChecked()){
        ui->tableView_edu->setModel(e->trides());    }
    delete e;
}

void Dialogmelek::on_lineEdit_rech_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
            QSqlQuery   *query= new QSqlQuery();
    if(ui->comboBox_crit->currentText()=="idact"
            ){
        query->prepare("SELECT * FROM actt WHERE ID LIKE'"+arg1+"%'");//
query->exec();
    model->setQuery(*query);
ui->tableView_act->setModel(model);


    }
    else {
        if(ui->comboBox_crit->currentText()=="nomact"){
            query->prepare("SELECT * FROM actt WHERE nomact LIKE'"+arg1+"%'");//+tri
    query->exec();
        model->setQuery(*query);
    ui->tableView_act->setModel(model);
        }
        else{
            if(ui->comboBox_crit->currentText()=="date")
                query->prepare("SELECT * FROM actt WHERE dateact LIKE'"+arg1+"%'");//+tri
        query->exec();
            model->setQuery(*query);
        ui->tableView_act->setModel(model);
            }

        }
}

void Dialogmelek::on_pushButton_stat_clicked()
{
    stat_edu=new stateduact(this);
    stat_edu->show();
}



void Dialogmelek::on_pushButton_clicked()
{
ac.genererPDFact();
}

void Dialogmelek::on_pushButton_2_clicked()
{
    hide();
    login *log;
    log=new login();
    log->show();
}
