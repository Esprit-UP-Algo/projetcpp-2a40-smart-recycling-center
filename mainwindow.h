#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QDialog>
#include <QMainWindow>
#include<QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include "personnel.h"
#include"server.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();

    void on_pushButton_clicked();

    void on_pb_modifier_clicked();

    void on_pb_PDF_clicked();

    void on_pb_tri_clicked();

    void on_pb_stat_clicked();

    void on_label_21_linkActivated(const QString &link);

    void on_pb_chercher_clicked();

    void on_startButton_clicked();

    void on_pushButton_4_clicked();
    void next();
    void getMessage();
    void playerConnected();

private:
    Ui::MainWindow *ui;
    Personnel P;
    Server server;
    QString text;
    QWidget wd;
};
#endif // MAINWINDOW_H
