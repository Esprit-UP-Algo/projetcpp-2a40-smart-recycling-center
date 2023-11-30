#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMainWindow>
#include <QInputDialog>
#include <QStringList>
#include <QDebug>
#include <QPdfWriter>
#include <QFileDialog>
#include <QPainter>
#include <QTextDocument>
#include <QTimer>
#include <QBarSeries>
#include "materiaux.h"
#include "arduino.h"
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

    void on_pb_modifier_clicked();

    void on_pb_chercher_clicked();

    void on_pb_pdf_clicked();
    void exportToPDF();

    void on_le_stat_clicked();

    void on_pb_trier_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_imprimer_clicked();
    void exportToWord();

    void on_pb_word_clicked();

    void on_pb_inserer_clicked();

    void on_pb_envoyer_clicked();
    void update_label();
    void updateDatabase(int id, int capteur);
    void envoyerEtLire();

private:
    Ui::MainWindow *ui;
    Materiaux M;
    QTimer *timerAlerte;
    Arduino A;
    QByteArray data;
};
#endif // MAINWINDOW_H
