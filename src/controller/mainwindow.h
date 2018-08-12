#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "model/model.h"
#include "model/struct.h"

class Util;
class Model;
class QListWidgetItem;
class mkdirWidget;

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

    void on_MyFlies_itemClicked(QListWidgetItem *item);

    void on_send_itemClicked(QListWidgetItem *item);

    void on_upload_clicked();

    void on_checkBox_clicked();

    void on_mkdir_clicked();

    void receiveData(bool data);

    void on_FilesListButton_clicked();

    void on_update_clicked();

private:
    void setupUI();
    QString kb_to_gb(int number);
    void addItem(filesListData data);
    int progressInt(int used, int capacity);
    void updateListData();

    void sendButtonState();
    void fliesButtonState();

    Ui::MainWindow *ui;

    Util *util;
    Model *model;
    User user;
    mkdirWidget *mkdir;
    FilesList filesList;
    filesListData listData;
};

#endif // MAINWINDOW_H
