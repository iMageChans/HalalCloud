#include "displywidget.h"
#include <QPainter>
#include <QDebug>
#include <QResizeEvent>

DisplyWidget::DisplyWidget(QWidget *parent) : QWidget(parent)
{
    setGeometry(QRect(0,1,640,478));
    m_width = m_height = 0;
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

void DisplyWidget::SetDisplayImage(QImage image){
    m_image = image.copy(0, 0, image.width(), image.height());
    update();
}

void DisplyWidget::PaintImage(QPainter &painter){
    m_width = m_width < size().width() ? m_width : size().width();
    m_height = m_height < size().height() ? m_height : size().height();
    QRect m_imageRect = QRect(0, 0, m_width, m_height);
    painter.drawImage(m_imageRect, m_image);
}

void DisplyWidget::resizeEvent(QResizeEvent *event){
    resize(event->size().width(), event->size().height());
    m_width = event->size().width();
    m_height = event->size().height();
}

void DisplyWidget::paintEvent(QPaintEvent *){
    QPainter painter(this);
    if(!m_image.isNull()){
        PaintImage(painter);
    }
}
