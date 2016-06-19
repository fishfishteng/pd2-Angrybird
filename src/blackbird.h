#ifndef BLACKBIRD_H
#define BLACKBIRD_H

#include <bird.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>


class BlackBird : public Bird
{
public:
    BlackBird(float x, float y ,float radius, QTimer *timer, QPixmap pixmap,b2World *world, QGraphicsScene *scene);
    virtual void SuperPower();
};

#endif // BLACKBIRD_H
