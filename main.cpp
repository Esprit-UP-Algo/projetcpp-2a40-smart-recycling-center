#include "mainwindow.h"
#include"login.h"
#include"inter.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login *loginlab = new Login;
    loginlab->show();
    return a.exec();
}
