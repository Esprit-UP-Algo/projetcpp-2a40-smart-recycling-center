#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QSerialPort>
#include <QByteArray>

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
     void on_pb_seconnecter_clicked();
    void on_pushButtonConnect_clicked();
    void on_pushButtonReadRFID_clicked();
     QString serialReceived1();
     void write_to_arduino( QByteArray d);



    // void on_led_clicked();

private:
    Ui::MainWindow *ui;
    QSerialPort *arduino;
    QByteArray serialData;
    QPair<QString, QString> result;
     QString serialData1;


};
#endif // MAINWINDOW_H
