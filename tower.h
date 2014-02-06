#ifndef TOWER_H
#define TOWER_H


#include <QList>
#include <math.h>
#include <QDebug>
#include <QPainter>
#include <QStyleOption>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsObject>

#include "disc.h"


class Tower : public QGraphicsItem{
    public:
        Tower(int number);
        QRectF boundingRect() const;
        QPainterPath shape() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);
        int getTowerNumber();
        Disc * removeTop();

        Disc * getTop();

        bool hasDisc();
        int getTotalDisc();

        void addToTop(Disc * a_disc);
        void RemoveAll();

    private:
        int tower_number;
        int tower_x;
        int tower_y;
        int tower_width;
        int tower_height;
        QColor tower_color;
        QList <Disc *> *disc_container;




};

#endif // TOWER_H
