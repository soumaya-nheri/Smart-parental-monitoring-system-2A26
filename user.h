#ifndef USER_H
#define USER_H
#include "fenetre_parent.h"
#include <QDialog>
#include "arduino.h"

namespace Ui {
class User;
}

class User : public QDialog
{
    Q_OBJECT

public:
    explicit User(QWidget *parent = nullptr);
    void setparent(Fenetre_Parent p);
    ~User();


private slots:
    void on_Ajouter_clicked();

    void on_Supprimer_clicked();

    void on_pushButton_clicked();

    void on_Rechercher_clicked();

    void on_Modifier_clicked();

    void on_envoyer_clicked();

    void on_export_2_clicked();

    void on_comboBox_trier_activated(const QString &arg1);

    void on_tri_croissant_clicked();

    void on_tri_decroissant_clicked();

    void on_tri_ordre_alphabetique_clicked();

    void update_label();


    void on_comboBox_activated(const QString &arg1);

private:
    Ui::User *ui;
    Fenetre_Parent P;
    Arduino A;
    QByteArray data;
};

#endif // USER_H
