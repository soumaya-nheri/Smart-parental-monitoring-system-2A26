#include "dialog.h"
#include "ui_dialog.h"
#include "parent.h"
#include "reclamation.h"
#include <QMessageBox>
#include"login.h"
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Gestion hajjem");
    ui->tabpar->setModel(p.afficher());
  ui->tableView_rec->setModel(r.afficher());
    ui->id_par2->setModel(p.afficheroncombo());
    ui->i_reccombo->setModel(r.afficheroncombo());
  ui->id_reccombosup->setModel(r.afficheroncombo());
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pb_ajouter_clicked()
{
    parentt p(ui->labidp->text().toInt(),ui->labn->text(),ui->labtel->text().toInt(),ui->labnbre->text().toInt());
    p.ajouter();
    ui->tabpar->setModel(p.afficher());
}

void Dialog::on_pb_supprimer_clicked()
{
    bool test=p.supprimer(ui->idparsup->text().toInt());
    if(test)
    {   ui->tabpar->setModel(p.afficher());//actualisation taa afficher
            QMessageBox::information(nullptr,QObject::tr("ok"),
                                     QObject::tr("suppression succful .\n"),
                    QMessageBox::Cancel);
        }

        else
            QMessageBox::critical(nullptr,QObject::tr("supprimer not open"),
                                    QObject::tr("click cancel to exist"),
                                    QMessageBox::Cancel);
}

void Dialog::on_modifier_clicked()
{
    bool    test=p.modifier(ui->idparlabmod->text().toInt(),ui->tellabmod->text().toInt(),ui->nbrelabmod->text().toInt()) ;
          if (test)
          {
  ui->tabpar->setModel(p.afficher());
              QMessageBox::information(nullptr,QObject::tr("OK"),
                                   QObject::tr("modification établie"),
                                   QMessageBox::Ok);}
          else{
          QMessageBox::critical(nullptr,QObject::tr("ERROR404"),
                                  QObject::tr("modification non établie"),
                                  QMessageBox::Cancel);}
}



void Dialog::on_le_recherche_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
            QSqlQuery   *query= new QSqlQuery();
    if(ui->cb_recherche->currentText()=="id"
            ){
        query->prepare("SELECT * FROM par WHERE idp LIKE'"+arg1+"%'");
query->exec();
    model->setQuery(*query);
ui->tabpar->setModel(model);


    }
    else {
        if(ui->cb_recherche->currentText()=="nbr_enf"){
            query->prepare("SELECT * FROM par WHERE nbre LIKE'"+arg1+"%'");
    query->exec();
        model->setQuery(*query);
    ui->tabpar->setModel(model);
        }
        else{
            if(ui->cb_recherche->currentText()=="nom")
                query->prepare("SELECT * FROM par WHERE nom LIKE'"+arg1+"%'");
        query->exec();
            model->setQuery(*query);
        ui->tabpar->setModel(model);
            }

        }
}

void Dialog::on_pushButton_tri_clicked()
{
    parentt *e =new  parentt(ui->labidp->text().toInt(),ui->labn->text(),ui->labtel->text().toInt(),ui->labnbre->text().toInt());
    if(ui->asc->isChecked()){
       ui->tabpar->setModel(e->triasc());

    }
    if(ui->desc->isChecked()){
        ui->tabpar->setModel(e->trides());    }
    delete e;
}


///////////////////////////////////////
void Dialog::on_Ajouter_2_clicked()
{
    reclamation r(ui->idrec->text().toInt(),ui->id_par2->currentText().toInt(),ui->descc->text(),ui->date_pan->text());
       bool test= r.ajouter();
          ui->tableView_rec->setModel(r.afficher());

}

void Dialog::on_id_par2_currentIndexChanged(int index)
{
    ui->id_par2->currentText();
}

void Dialog::on_pb_modifier_5_clicked()
{
    bool    test=r.modifier(ui->i_reccombo->currentText().toInt(),ui->desc_mod->text(),ui->date_pan_mod->text()) ;
          if (test)
          {

                ui->tableView_rec->setModel(r.afficher());


              QMessageBox::information(nullptr,QObject::tr("OK"),
                                   QObject::tr("modification établie"),
                                   QMessageBox::Ok);}
          else{
          QMessageBox::critical(nullptr,QObject::tr("ERROR404"),
                                  QObject::tr("modification non établie"),
                                  QMessageBox::Cancel);}
}

void Dialog::on_i_reccombo_currentIndexChanged(int index)
{
      ui->i_reccombo->currentText();
}

void Dialog::on_pb_supprimer_2_clicked()
{
    bool test=r.supprimer(ui->id_reccombosup->currentText().toInt());
    if(test)
    {ui->tableView_rec->setModel(r.afficher());

        ui->id_reccombosup->setModel(r.afficheroncomboidrec());
        //actualisation taa afficher
            QMessageBox::information(nullptr,QObject::tr("ok"),
                                     QObject::tr("suppression succful .\n"),
                    QMessageBox::Cancel);
        }

        else
            QMessageBox::critical(nullptr,QObject::tr("supprimer not open"),
                                    QObject::tr("click cancel to exist"),
                                    QMessageBox::Cancel);
}


void Dialog::on_id_reccombosup_currentIndexChanged(int index)
{
     ui->id_reccombosup->currentText();
}

void Dialog::on_pushButton_2_clicked()
{
    r.genererPDFr();
}

void Dialog::on_pushButton_clicked()
{
    hide();

    login *log;
    log=new login();
    log->show();
}
