#include <QApplication>
#include "view/loginwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginWidget Login;
    Login.show();

    return a.exec();
}
