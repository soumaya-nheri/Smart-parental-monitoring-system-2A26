#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "parent.h"
#include "reclamation.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_modifier_clicked();

    void on_le_recherche_textChanged(const QString &arg1);

    void on_pushButton_tri_clicked();

    void on_pb_ajoutercommande_clicked();

    void on_Ajouter_2_clicked();

    void on_id_par2_currentIndexChanged(int index);

    void on_pb_modifier_5_clicked();

    void on_i_reccombo_currentIndexChanged(int index);

    void on_pb_supprimer_2_clicked();

    void on_id_reccombosup_activated(const QString &arg1);

    void on_id_reccombosup_currentIndexChanged(int index);

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
    parentt p;
    reclamation r;
};
#endif // DIALOG_H
