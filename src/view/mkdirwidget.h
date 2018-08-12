#ifndef MKDIRWIDGET_H
#define MKDIRWIDGET_H

#include <QWidget>

class Util;
class Model;

namespace Ui {
class mkdirWidget;
}

class mkdirWidget : public QWidget
{
    Q_OBJECT

public:
    explicit mkdirWidget(QWidget *parent = nullptr);
    void getPath(const QString &Pach);
    ~mkdirWidget();

signals:
    void sendClick(bool data);

private slots:
    void on_Yes_clicked();

    void on_No_clicked();

private:
    Ui::mkdirWidget *ui;
    QString pach;
    Model *model;
    Util *util;
};

#endif // MKDIRWIDGET_H
