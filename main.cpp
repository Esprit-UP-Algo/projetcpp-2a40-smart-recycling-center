#include "mainwindow.h"

#include <QApplication>
#include<QMessageBox>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connexion c;
    bool test=c.createconnect();
    Login *loginlab = new Login;

    if(test)
    {
        loginlab->show();
         QMessageBox::information(nullptr,QObject::tr("database is open"),QObject::tr("connection successful.\n""Click cancel to exit."),QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("database is not open"),QObject::tr("connection failed.\n""Click cancel to exit."),QMessageBox::Cancel);
    }

    return a.exec();
}
