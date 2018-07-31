#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>

class QLabel;

namespace Ui {
class LoginWidget;
}

class LoginWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWidget(QWidget *parent = 0);
    ~LoginWidget();

private:
    QLabel *TitleIcon;

    Ui::LoginWidget *ui;
    void setupUI();
    void setupTitleIcon();
};

#endif // LOGINWIDGET_H
