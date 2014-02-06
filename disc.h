#ifndef DISC_H
#define DISC_H



#include <math.h>
#include <QDebug>
#include <QPainter>
#include <QStyleOption>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsObject>



class Disc : public QGraphicsItem{

    public:
        Disc(int number);
        QRectF boundingRect() const;
        QPainterPath shape() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);
        int getDiscNumber();
    private:
        int disc_number;
        int disc_x;
        int disc_y;
        int disc_width;
        int disc_height;
        QColor disc_color;
        QGraphicsTextItem *text_number_of_disc;
};












#endif // DISC_H
