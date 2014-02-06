#include "tobjects.h"





OMoveCounter::OMoveCounter(){
    tFont = new QFont("Times New Roman");
    tFont->setBold(false);
    tFont->setPointSize(20);
    moves = 0;
    text = QString("Moves: ");
    text_item = new QGraphicsTextItem(this);
    text_item->setFont(*tFont);

    setMoves(0);

}


void OMoveCounter::setMoves(int number){
    moves = number;
    QString num;
    QString tmp = text + num.setNum(moves);
    this->text_item->setPlainText(tmp);
    //int delay=100000000;
    //while(delay--);
    //this->update();
}

QRectF OMoveCounter::boundingRect() const{
    return this->text_item->boundingRect();
}



QPainterPath OMoveCounter::shape() const{
    QPainterPath path;
    path.addRect(0,0, this->text_item->boundingRect().width(), this->text_item->boundingRect().height());
    return path;
}



void OMoveCounter::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    //painter->setPen(Qt::NoPen);
    painter->setBrush(QColor("#007f7f"));
    //painter->drawRect(this->tower_x + this->boundingRect().width()/2.0 - this->tower_width/2.0, this->tower_y, this->tower_width, this->tower_height);

    //painter->setBrush(QColor(0,0,0));
    //painter->drawRect(this->tower_x, this->tower_y+this->tower_height,this->boundingRect().width(), 20);

}



















/**********OMinMoveCounter****/



OMinMoveCounter::OMinMoveCounter(){
    tFont = new QFont("Times New Roman");
    tFont->setBold(false);
    tFont->setPointSize(12);
    moves = 0;
    text = QString("Minimum Moves: ");
    text_item = new QGraphicsTextItem(this);
    text_item->setFont(*tFont);

    setMoves(0);

}


void OMinMoveCounter::setMoves(int number){
    moves = number;
    QString num;
    QString tmp = text + num.setNum(moves);
    this->text_item->setPlainText(tmp);
    //this->update();
}

QRectF OMinMoveCounter::boundingRect() const{
    return this->text_item->boundingRect();
}



QPainterPath OMinMoveCounter::shape() const{
    QPainterPath path;
    path.addRect(0,0, this->text_item->boundingRect().width(), this->text_item->boundingRect().height());
    return path;
}



void OMinMoveCounter::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    //painter->setPen(Qt::NoPen);
    painter->setBrush(QColor("#007f7f"));
    //painter->drawRect(this->tower_x + this->boundingRect().width()/2.0 - this->tower_width/2.0, this->tower_y, this->tower_width, this->tower_height);

    //painter->setBrush(QColor(0,0,0));
    //painter->drawRect(this->tower_x, this->tower_y+this->tower_height,this->boundingRect().width(), 20);

}
