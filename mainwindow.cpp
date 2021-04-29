#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextDocument>
#include <QTextStream>
#include <QFileDialog>
#include <QtPrintSupport/QPrinter>
#include <QMessageBox>
#include <QSystemTrayIcon>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     ui->tableView->setModel(tmpm.afficher());
     ui->tableView_2->setModel(tmps.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    int id=ui->lineEdit->text().toInt();
    QString type=ui->lineEdit_2->text();
    QString nom=ui->lineEdit_3->text();
    QString description=ui->lineEdit_4->text();
    porte m(id,type,nom,description);
    bool test=m.ajouter();
    if(test)
    { ui->tableView->setModel(tmpm.afficher());//rafraishissement du table
        QSystemTrayIcon* notifier = new QSystemTrayIcon(this);

                                notifier->show();
                                notifier->showMessage("porte ajouté","Succés",QSystemTrayIcon::Information,10000);

}
    else
    {
        QSystemTrayIcon* notifier = new QSystemTrayIcon(this);
                                notifier->show();
                                notifier->showMessage("porte non ajouté","failed",QSystemTrayIcon::Critical,10000);
    }

}

void MainWindow::on_pushButton_clicked()
{
    int id=ui->lineEdit->text().toInt();
    QString type=ui->lineEdit_2->text();
    QString nom=ui->lineEdit_3->text();
    QString description=ui->lineEdit_4->text();
    porte m(id,type,nom,description);
    bool test=m.modifier(id);
    if(test)
    { ui->tableView->setModel(tmpm.afficher());
        QSystemTrayIcon* notifier = new QSystemTrayIcon(this);

                                notifier->show();
                                notifier->showMessage("porte modifié","Succés",QSystemTrayIcon::Information,10000);

}
    else
    {
        QSystemTrayIcon* notifier = new QSystemTrayIcon(this);
                                notifier->show();
                                notifier->showMessage("porte non modifié","failed",QSystemTrayIcon::Critical,10000);
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    int id=ui->lineEdit_5->text().toInt();
    bool test=tmpm.supprimer(id);
    if (test)
    {ui->tableView->setModel(tmpm.afficher());
        QSystemTrayIcon* notifier = new QSystemTrayIcon(this);
                                notifier->show();
                                notifier->showMessage("porte supprimé","Succés",QSystemTrayIcon::Information,10000);
    }
    else
    {
        QSystemTrayIcon* notifier = new QSystemTrayIcon(this);
        notifier->show();
        notifier->showMessage("porte non supprimé","Failed",QSystemTrayIcon::Critical,10000);
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    QString selon=ui->comboBox->currentText();
    ui->tableView->setModel(tmpm.tri(selon));
}

void MainWindow::on_pushButton_5_clicked()
{
    int id=ui->lineEdit_6->text().toInt();
    ui->tableView->setModel(tmpm.afficherRech(id));
}

void MainWindow::on_pushButton_6_clicked()
{
     ui->tableView->setModel(tmpm.afficher());
}

void MainWindow::on_pushButton_11_clicked()
{
    QString strStream;
                       QTextStream out(&strStream);

                        const int rowCount = ui->tableView->model()->rowCount();
                        const int columnCount = ui->tableView->model()->columnCount();
                       out <<  "<html>\n"
                       "<head>\n"
                                        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                        <<  QString("<title>%1</title>\n").arg("strTitle")
                                        <<  "</head>\n"
                                        "<body bgcolor=#ffffff link=#5000A0>\n"

                                       //     "<align='right'> " << datefich << "</align>"
                                        "<center> <H1>Liste des portes</H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                                    // headers
                                    out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                                    out<<"<cellspacing=10 cellpadding=3>";
                                    for (int column = 0; column < columnCount; column++)
                                        if (!ui->tableView->isColumnHidden(column))
                                            out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
                                    out << "</tr></thead>\n";

                                    // data table
                                    for (int row = 0; row < rowCount; row++) {
                                        out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                                        for (int column = 0; column < columnCount; column++) {
                                            if (!ui->tableView->isColumnHidden(column)) {
                                                QString data = ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
                                                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                            }
                                        }
                                        out << "</tr>\n";
                                    }
                                    out <<  "</table> </center>\n"
                                        "</body>\n"
                                        "</html>\n";

                              QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                                if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                               QPrinter printer (QPrinter::PrinterResolution);
                                printer.setOutputFormat(QPrinter::PdfFormat);
                               printer.setPaperSize(QPrinter::A4);
                              printer.setOutputFileName(fileName);

                               QTextDocument doc;
                                doc.setHtml(strStream);
                                doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                                doc.print(&printer);
}

void MainWindow::on_pushButton_8_clicked()
{
    int id=ui->lineEdit_7->text().toInt();
    QString type=ui->lineEdit_8->text();
    QString nom=ui->lineEdit_9->text();
    QString lien=ui->lineEdit_10->text();
    site s(id,nom,type,lien);
    bool test=s.ajouter();
    if(test)
    { ui->tableView_2->setModel(tmps.afficher());
        QSystemTrayIcon* notifier = new QSystemTrayIcon(this);

                                notifier->show();
                                notifier->showMessage("site ajouté","Succés",QSystemTrayIcon::Information,10000);

}
    else
    {
        QSystemTrayIcon* notifier = new QSystemTrayIcon(this);
                                notifier->show();
                                notifier->showMessage("site non ajouté","failed",QSystemTrayIcon::Critical,10000);
    }
}

void MainWindow::on_pushButton_9_clicked()
{
    int id=ui->lineEdit_11->text().toInt();
    bool test=tmps.supprimer(id);
    if (test)
    {
        ui->tableView_2->setModel(tmps.afficher());

        QSystemTrayIcon* notifier = new QSystemTrayIcon(this);
                                notifier->show();
                                notifier->showMessage("site supprimé","Succés",QSystemTrayIcon::Information,10000);
    }
    else
    {
        QSystemTrayIcon* notifier = new QSystemTrayIcon(this);
        notifier->show();
        notifier->showMessage("site non supprimé","Failed",QSystemTrayIcon::Critical,10000);
    }
}

void MainWindow::on_pushButton_10_clicked()
{
    QString strStream;
                       QTextStream out(&strStream);

                        const int rowCount = ui->tableView_2->model()->rowCount();
                        const int columnCount = ui->tableView_2->model()->columnCount();
                       out <<  "<html>\n"
                       "<head>\n"
                                        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                        <<  QString("<title>%1</title>\n").arg("strTitle")
                                        <<  "</head>\n"
                                        "<body bgcolor=#ffffff link=#5000A0>\n"

                                       //     "<align='right'> " << datefich << "</align>"
                                        "<center> <H1>Liste des portes</H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                                    // headers
                                    out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                                    out<<"<cellspacing=10 cellpadding=3>";
                                    for (int column = 0; column < columnCount; column++)
                                        if (!ui->tableView_2->isColumnHidden(column))
                                            out << QString("<th>%1</th>").arg(ui->tableView_2->model()->headerData(column, Qt::Horizontal).toString());
                                    out << "</tr></thead>\n";

                                    // data table
                                    for (int row = 0; row < rowCount; row++) {
                                        out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                                        for (int column = 0; column < columnCount; column++) {
                                            if (!ui->tableView_2->isColumnHidden(column)) {
                                                QString data = ui->tableView_2->model()->data(ui->tableView_2->model()->index(row, column)).toString().simplified();
                                                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                            }
                                        }
                                        out << "</tr>\n";
                                    }
                                    out <<  "</table> </center>\n"
                                        "</body>\n"
                                        "</html>\n";

                              QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                                if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                               QPrinter printer (QPrinter::PrinterResolution);
                                printer.setOutputFormat(QPrinter::PdfFormat);
                               printer.setPaperSize(QPrinter::A4);
                              printer.setOutputFileName(fileName);

                               QTextDocument doc;
                                doc.setHtml(strStream);
                                doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                                doc.print(&printer);
}

void MainWindow::on_pushButton_12_clicked()
{
    int id=ui->lineEdit->text().toInt();
    QString type=ui->lineEdit_2->text();
    QString nom=ui->lineEdit_3->text();
    QString description=ui->lineEdit_4->text();
    porte m(id,type,nom,description);
    bool test=m.modifier(id);
    if(test)
    { ui->tableView->setModel(tmpm.afficher());
        QSystemTrayIcon* notifier = new QSystemTrayIcon(this);

                                notifier->show();
                                notifier->showMessage("porte modifié","Succés",QSystemTrayIcon::Information,10000);

}
    else
    {
        QSystemTrayIcon* notifier = new QSystemTrayIcon(this);
                                notifier->show();
                                notifier->showMessage("porte non modifié","failed",QSystemTrayIcon::Critical,10000);
    }
}

void MainWindow::on_pushButton_7_clicked()
{
    int id=ui->lineEdit_7->text().toInt();
    QString type=ui->lineEdit_8->text();
    QString nom=ui->lineEdit_9->text();
    QString lien=ui->lineEdit_10->text();
    site s(id,nom,type,lien);
    bool test=s.modifier(id);
    if(test)
    { ui->tableView_2->setModel(tmps.afficher());
        QSystemTrayIcon* notifier = new QSystemTrayIcon(this);

                                notifier->show();
                                notifier->showMessage("site modifié","Succés",QSystemTrayIcon::Information,10000);

}
    else
    {
        QSystemTrayIcon* notifier = new QSystemTrayIcon(this);
                                notifier->show();
                                notifier->showMessage("site non modifié","failed",QSystemTrayIcon::Critical,10000);
    }
}
