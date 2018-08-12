#ifndef FILESITEMWIDGET_H
#define FILESITEMWIDGET_H

#include <QWidget>

namespace Ui {
class FilesItemWidget;
}

class FilesItemWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FilesItemWidget(QWidget *parent = nullptr);
    ~FilesItemWidget();

private slots:
    void on_pushButton_2_clicked(bool checked);

private:
    Ui::FilesItemWidget *ui;
};

#endif // FILESITEMWIDGET_H
