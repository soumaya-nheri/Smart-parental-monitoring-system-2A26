#include "user.h"
#include "ui_user.h"
#include "fenetre_parent.h"
#include <QWidget>
#include "QMessageBox"
#include "QtPrintSupport/QPrinter"
#include "QtPrintSupport/QPrintDialog"

User::User(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::User)
{
    ui->setupUi(this);
    ui->tab_parents->setModel(P.afficher());
    int ret=A.connect_arduino();
    switch (ret) {
    case (0): qDebug()<<"Arduino est disponible et connectée"<<A.getarduino_port_name();
        break;
    case (1): qDebug()<<"Arduino est disponible mais elle n'est pas connectée"<<A.getarduino_port_name();
        break;
    case (-1): qDebug()<<"Arduino n'est pas disponible";
        break;
    }
    QObject::connect(A.getserial(), SIGNAL(readyRead()),this,SLOT(update_label()));
}

User::~User()
{
    delete ui;
}

void User::update_label()
{
    data=A.read_from_arduino();
        if(data=="1")
{
            ui->state->setText("ON"); // si les données reçues de arduino via la liaison série sont égales à 1
            qDebug()<<"Personne detectée";}
        // alors afficher ON

        else if (data=="0")

            ui->state->setText("OFF");   // si les données reçues de arduino via la liaison série sont égales à 0
         //alors afficher ON
}

void User::on_Ajouter_clicked()
{
    int cin=ui->cin->text().toInt();
    QString nom=ui->nom->text();
    QString prenom=ui->prenom->text();
    QString mail=ui->mail->text();
    QString mdp=ui->mdp->text();
    Fenetre_Parent p(cin,nom,prenom,mail,mdp);

    bool test=p.ajouter();
    if(test)
    {QMessageBox msgBox ;
        QMessageBox::information(this,"information","parent ajouté");
        ui->tab_parents->setModel(P.afficher());
    }

    else {QMessageBox msgBox ;
        QMessageBox::information(this,"information","echec lors de l ajout");
     }
}

void User::on_Supprimer_clicked()
{
    Fenetre_Parent P1;
    P1.set_cin(ui->Scin->text().toInt());
    bool test=P1.supprimer(P1.get_cin());
    if(test)
    {QMessageBox msgBox ;
        QMessageBox::information(this,"information","parent supprimé");
        ui->tab_parents->setModel(P.afficher());
    }
    else {QMessageBox msgBox ;
        QMessageBox::information(this,"information","erreur de suppression");
     }

}



void User::on_Modifier_clicked()
{
    int CIN=ui->MCin->text().toInt ();
            QString nom=ui->MNom->text () ;
            QString prenom=ui->Mprenom->text () ;
            QString mail=ui->MMail->text () ;
            QString mdp=ui->MMdp->text () ;
             Fenetre_Parent P(CIN,nom,prenom,mail,mdp);

        bool test1=P.modifier(CIN, nom,prenom,mail,mdp);
        if(test1)
        {
            QMessageBox::information(nullptr, QObject::tr("Modifier un Parent"),
                                     QObject::tr("parent  modifié.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tab_parents->setModel(P.afficher());

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Modifier un parent "),
                                  QObject::tr("Erreur !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);

}

void User::on_Rechercher_clicked()
{
         QString N=ui->R_CIN->text();
         Fenetre_Parent P;
         ui->tab_parents->setModel(P.rechercher(N)) ;
          ui->Rechercher_Parent->setModel(P.rechercher(N)) ;
}

void User::on_tri_croissant_clicked()
{
    Fenetre_Parent P;
    ui->tab_parents->setModel(P.trier_parent_id()) ;
     ui->Tri_Parent->setModel(P.trier_parent_id()) ;
}

void User::on_tri_decroissant_clicked()
{
    Fenetre_Parent P;
    ui->tab_parents->setModel(P.trier_parent_decroi_id()) ;
     ui->Tri_Parent->setModel(P.trier_parent_decroi_id()) ;
}

void User::on_tri_ordre_alphabetique_clicked()
{
    Fenetre_Parent P;
    ui->tab_parents->setModel(P.trier_parent_alpha()) ;
     ui->Tri_Parent->setModel(P.trier_parent_alpha()) ;
}


void User::on_comboBox_activated(const QString &arg1)
{

}

void User::on_envoyer_clicked()
{

}

void User::on_export_2_clicked()
{

}

void User::on_pushButton_clicked()
{

}

void User::on_comboBox_trier_activated(const QString &arg1)
{

}
