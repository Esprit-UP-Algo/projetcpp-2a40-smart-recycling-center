#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "materiau.h"
#include <QInputDialog>
#include <QStringList>
#include <QDebug>
#include <QPdfWriter>
#include <QFileDialog>
#include <QPrinter>
#include <QPainter>
#include <QTextDocument>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();

    void on_pushButton_clicked();
    //void imprimerTable();

    void on_pb_pdf_clicked();

private:
    Ui::MainWindow *ui;
    Materiau M;

};

#endif // MAINWINDOW_H
