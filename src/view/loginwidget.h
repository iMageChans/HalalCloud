#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>
#include "model/model.h"

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

    void onStateChanged(int state);

    void on_regis_clicked();

    void on_forget_clicked();

private:
    void MessageBox(const QString &code);

    Util *util;

    Ui::LoginWidget *ui;
    void setupUI();
    void setupTitleIcon();
};

#endif // LOGINWIDGET_H
