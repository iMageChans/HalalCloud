#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "model/model.h"

class Util;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void userSend(User data);

private slots:


    void on_Loginout_clicked();

    void on_dilatation_clicked();

private:
    void setupUI();
    QString kb_to_gb(QString number);
    int progressInt(QString used, QString capacity);

    Ui::MainWindow *ui;

    Util *util;
    User user;
};

#endif // MAINWINDOW_H
