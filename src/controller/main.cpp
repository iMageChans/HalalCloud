#include <QApplication>
#include "view/loginwidget.h"
#include "view/mediaplayer.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MediaPlayer Player;
//    LoginWidget Login;
    Player.show();

    return a.exec();
}


