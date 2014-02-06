#ifndef OBJECTS_H
#define OBJECTS_H



#include <math.h>
#include <QString>
#include <QDebug>
#include <QPainter>
#include <QStyleOption>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsObject>






class OMoveCounter : public QGraphicsItem{
    public:
        OMoveCounter();
        QRectF boundingRect() const;
        QPainterPath shape() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);
        void setMoves(int number);


    private:
        int moves;
        QString text;
        QFont *tFont;
        QGraphicsTextItem *text_item;
};




class OMinMoveCounter : public QGraphicsItem{
    public:
        OMinMoveCounter();
        QRectF boundingRect() const;
        QPainterPath shape() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);
        void setMoves(int number);


    private:
        int moves;
        QString text;
        QFont *tFont;
        QGraphicsTextItem *text_item;

};







#endif // OBJECTS_H
