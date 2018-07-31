#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>

class QLabel;
class Util;

namespace Ui {
class LoginWidget;
}

class LoginWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWidget(QWidget *parent = 0);
    ~LoginWidget();

private slots:
    void on_Login_clicked();

private:
    Util *util;
    QLabel *TitleIcon;

    Ui::LoginWidget *ui;
    void setupUI();
    void setupTitleIcon();
};

#endif // LOGINWIDGET_H
