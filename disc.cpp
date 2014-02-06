#include "disc.h"




Disc::Disc(int number){
    this->disc_number = number;
    this->disc_x = 0;
    this->disc_y = 0;
    this->disc_width = 60 + number*10;
    this->disc_height = 30;

    this->disc_color.setRgb( (disc_number*100) % 256, (disc_number*120) % 256, (disc_number*140) % 256);
    setPos(mapToParent(this->disc_x, this->disc_y));

    QFont *tFont = new QFont("Times New Roman");
    tFont->setBold(false);
    tFont->setPointSize(15);
    QString num;


    text_number_of_disc = new QGraphicsTextItem(this);
    text_number_of_disc->setFont(*tFont);
    text_number_of_disc->setPlainText( num.setNum(number) );

}




QRectF Disc::boundingRect() const{
    return QRectF(this->disc_x,
                  this->disc_y,
                  this->disc_width,
                  this->disc_height);
}

QPainterPath Disc::shape() const{
    QPainterPath path;
    path.addRect(0,0, this->disc_width, this->disc_height);
    return path;
}


int Disc::getDiscNumber(){
   return this->disc_number;
}

void Disc::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    painter->setPen(Qt::NoPen);
    painter->setBrush(this->disc_color);
    painter->drawRoundedRect(this->disc_x, this->disc_y, this->disc_width, this->disc_height, 5, 5);
    painter->setBrush(QColor("#c5c5c5"));
    qreal x = (this->disc_width - 24)/2;
    qreal y = (this->disc_height - 24)/2.0;
    painter->drawRoundedRect(x, y,24, 24, 12, 12);
    //painter->setPen(Qt::SolidLine);
    //painter->drawText(x,y,"1");

    //QFont *tFont = new QFont("Times New Roman");
    //tFont->setBold(false);
    //tFont->setPointSize(10);

    //QGraphicsTextItem *text_number_of_disc = new QGraphicsTextItem(this);
    //text_number_of_disc->setFont(*tFont);
    //text_number_of_disc->setPlainText("1");
    x =  (this->disc_width - text_number_of_disc->boundingRect().width())/2.0;
    y = (this->disc_height - text_number_of_disc->boundingRect().height() )/2.0;
    this->text_number_of_disc->setPos(x,y);


}


