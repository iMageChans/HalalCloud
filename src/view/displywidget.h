#ifndef DISPLYWIDGET_H
#define DISPLYWIDGET_H

#include <QWidget>

class DisplyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DisplyWidget(QWidget *parent = nullptr);

    void SetDisplayImage(QImage img);

signals:

public slots:

private:
    void resizeEvent(QResizeEvent *event);
    void paintEvent(QPaintEvent *);
    void PaintImage(QPainter &painter);

    QImage m_image;
    int m_width;
    int m_height;
};

#endif // DISPLYWIDGET_H
