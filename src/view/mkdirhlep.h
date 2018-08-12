#ifndef MKDIRHLEP_H
#define MKDIRHLEP_H

#include <QWidget>

class QTimer;

namespace Ui {
class mkdirHlep;
}

class mkdirHlep : public QWidget
{
    Q_OBJECT

public:
    explicit mkdirHlep(QWidget *parent = nullptr);
    void helpText(const QString &help);
    ~mkdirHlep();

private slots:
    void showTimelimit();

private:
    Ui::mkdirHlep *ui;

    int autoTime;
    QTimer *timer;
};

#endif // MKDIRHLEP_H
