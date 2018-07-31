#include "mainwindow.h"
#include <QApplication>
#include "view/loginwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    LoginWidget Login;
    Login.show();
    w.show();

    return a.exec();
}
