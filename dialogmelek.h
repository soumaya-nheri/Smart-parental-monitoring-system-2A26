#ifndef DIALOGMELEK_H
#define DIALOGMELEK_H

#include <QDialog>
#include "activite.h"
#include "educ.h"
#include "stateduact.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Dialogmelek; }
QT_END_NAMESPACE

class Dialogmelek : public QDialog
{
    Q_OBJECT

public:
    Dialogmelek(QWidget *parent = nullptr);
    ~Dialogmelek();

private slots:
    void on_pushButton_ajouteract_clicked();

    void on_comboBox_2_idact_currentIndexChanged(int index);

    void on_pushButton_ajouteract_2_clicked();

    void on_comboBox_3_idact_currentIndexChanged(int index);

    void on_pushButton_ajouteract_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_ajouteredu_clicked();

    void on_pushButton_suppract_3_clicked();

    void on_comboBox_idaced_activated(const QString &arg1);

    void on_comboBox_idaced_currentIndexChanged(int index);

    void on_pushButton_modedu_clicked();

    void on_pushButton_suppedu_clicked();

    void on_pushButton_tri_clicked();

    void on_lineEdit_rech_textChanged(const QString &arg1);

    void on_pushButton_stat_clicked();

    void on_pushButton_clicked();

private:
    Ui::Dialogmelek *ui;
    activite ac;
    educ ed;
    stateduact *stat_edu;

};
#endif // DIALOGMELEK_H
