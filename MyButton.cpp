#include "MyButton.h"
#include <QPainter>

MyButton::MyButton(): value(-1), can_changed(true) {}

void MyButton::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    QBrush brush(QColor(17,205,174));
    painter.setBrush(brush);
    QPen pen(QColor(17,205,174), 3);
    painter.setPen(pen);
    QPen crossPen(QColor(59,67,51), 13);
    QPen zeroPen(QColor(225,249,202), 13);

    int len=0;
    if (QWidget::width()>QWidget::height()){
     len=QWidget::height();
    }
    else{
        len=QWidget::width();
    }

    painter.drawRect(QWidget::width()/2-len,QWidget::height()/2-len/2,QWidget::height()+height(), QWidget::width());

    if (value == 0) {
        painter.setPen(zeroPen);
        painter.drawEllipse(QPoint(QWidget::width()/2, QWidget::height()/2),QWidget::width()/2-len/6,QWidget::height()/2-len/6);
    } else if (value == 1) {
        painter.setPen(crossPen);
        painter.drawLine(len/6, len/6, width()-len/6, height()-len/6);
        painter.drawLine(width()-len/6, len/6, len/6, height()-len/6);
    }
}
