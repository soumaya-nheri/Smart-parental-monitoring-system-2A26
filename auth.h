#ifndef AUTH_H
#define AUTH_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Auth; }
QT_END_NAMESPACE

class Auth : public QMainWindow
{
    Q_OBJECT

public:
    Auth(QWidget *parent = nullptr);
    ~Auth();

private slots:
    void on_btn_connect_clicked();

private:
    Ui::Auth *ui;
};
#endif // AUTH_H
