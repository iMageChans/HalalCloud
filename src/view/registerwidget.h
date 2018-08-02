#ifndef REGISTERWIDGET_H
#define REGISTERWIDGET_H

#include <QWidget>

class Util;

namespace Ui {
class RegisterWidget;
}

class RegisterWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RegisterWidget(QWidget *parent = 0);
    ~RegisterWidget();

private slots:
    void on_back_clicked();

    void on_regis_clicked();

private:
    void MessageBox(const QString &code);

    Util *util;

    Ui::RegisterWidget *ui;
    void setupUI();
};

#endif // REGISTERWIDGET_H
