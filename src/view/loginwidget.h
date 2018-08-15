#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>
#include "model/model.h"

class QLabel;
class Util;
class QTimer;

namespace Ui {
class LoginWidget;
}

class LoginWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWidget(QWidget *parent = nullptr);
    ~LoginWidget();

private slots:
    void on_Login_clicked();

    void onStateChanged(int state);

    void on_regis_clicked();

    void on_forget_clicked();

    void showTimelimit();

private:
    void MessageBox(const QString &code);
    void autoLogins();

    Util *util;
    int autoTime;
    QTimer *timer;

    Ui::LoginWidget *ui;
    void setupUI();
    void setupTitleIcon();
};

#endif // LOGINWIDGET_H
