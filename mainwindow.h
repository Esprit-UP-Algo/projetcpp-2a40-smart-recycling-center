#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "conteneur.h"
#include <QMainWindow>

#include <QtWidgets>
#include <QtLocation>
#include <QtPositioning>

#include <QTimer>
#include <QTime>

#include <QMediaPlayer>

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
    void on_bt_ajout_clicked();



    void on_bt_supprimer_clicked();



    void on_groupBox_9_clicked();

    void on_bb_clicked();

    void on_groupBox_10_clicked();

    void on_bt_modifier_clicked();

    void on_pushButton_clicked();

    void on_bt_modifier_2_clicked();
    void on_rechercher_editingFinished();
    void on_comboBox_currentTextChanged(const QString &arg1);
    void on_pdf_clicked();
    int countType(const QString&);

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_rechercher_returnPressed();
    void limitInputLength(const QString &text);
    void limitInputLength2(const QString &text);


    void on_pdf_2_clicked();

    void on_evoyer_mail_clicked();
void updateTimeSlot();
void on_pushButton_5_clicked();

void on_pdf_3_clicked();

void on_pushButton_3_clicked();


    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_pdf_4_clicked();

    void on_pushButton_8_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

private:
    Ui::MainWindow *ui;
    Conteneur C;
    QNetworkAccessManager *networkManager;
    QTimer *timer;
        QTime currentTime;
        QMediaPlayer *mediaPlayer;
            bool isMuted;
            int previousVolume;
            void toggleMute();


};
#endif // MAINWINDOW_H
