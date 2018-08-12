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

    void setName(QString &name);
    void setCapacity(long Size);
    void setTime(long time);

private slots:


private:
    Ui::FilesItemWidget *ui;
};

#endif // FILESITEMWIDGET_H
