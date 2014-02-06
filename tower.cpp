#include "tower.h"




Tower::Tower(int number){
    this->tower_number = number;
    this->tower_x = 0;
    this->tower_y = 0;
    this->tower_width = 30;
    this->tower_height = 370;

    this->tower_color.setRgb(13,125,167);
    setPos(mapToParent(this->tower_x, this->tower_y));

    //Disc *ds = new Disc(12);
    //ds->setParentItem(this);
    //ds->setPos(0,0);

    disc_container = new QList <Disc *>();



}




QRectF Tower::boundingRect() const{
    qreal penWidth = 0;
    return QRectF(this->tower_x,
                  this->tower_y,
                  this->tower_width + penWidth + 150,
                  this->tower_height + penWidth + 20);
}



QPainterPath Tower::shape() const{
    QPainterPath path;
    path.addRect(this->tower_x,this->tower_y, this->boundingRect().width(), this->boundingRect().height());
    return path;
}


int Tower::getTowerNumber(){
   return this->tower_number;
}

void Tower::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    painter->setPen(Qt::NoPen);
    painter->setBrush(this->tower_color);
    painter->drawRect(this->tower_x + this->boundingRect().width()/2.0 - this->tower_width/2.0, this->tower_y, this->tower_width, this->tower_height);

    painter->setBrush(QColor(0,0,0));
    painter->drawRect(this->tower_x, this->tower_y+this->tower_height,this->boundingRect().width(), 20);

}



void Tower::addToTop(Disc * a_disc){
    this->disc_container->append(a_disc);
    a_disc->setParentItem(this);

    int total_disc = this->disc_container->count();

    qreal x = this->tower_x;
    qreal y = this->tower_height;

    for (int i = 0 ; i<total_disc;i++) {
        x = (this->boundingRect().width() - this->disc_container->at(i)->boundingRect().width() )/2.0;
        y = y - this->disc_container->at(i)->boundingRect().height();
        this->disc_container->at(i)->setPos(x,y);
    }


    this->update();
}


Disc * Tower::getTop(){
    if (this->disc_container->count()>0){
        Disc *tmp = this->disc_container->at( this->disc_container->count()-1 );
        return tmp;
    }

    return NULL;

}




int Tower::getTotalDisc(){return this->disc_container->count();}


bool Tower::hasDisc(){
    return this->disc_container->count()>0;
}


Disc * Tower::removeTop(){
    if (this->disc_container->count()>0){
        Disc *tmp = this->disc_container->at( this->disc_container->count()-1 );

        this->disc_container->removeLast();
        return tmp;
    }

    return NULL;
}



void Tower::RemoveAll(){
    for (int i = 0;i<this->disc_container->count();i++)
    {
        this->disc_container->at(i)->setEnabled(false);
        delete this->disc_container->at(i);
    }
    this->disc_container->clear();
}




