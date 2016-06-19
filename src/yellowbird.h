#ifndef YELLOWBIRD_H
#define YELLOWBIRD_H

#include <bird.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>

class YellowBird : public Bird
{
public:
    YellowBird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    virtual void SuperPower();
};

#endif // YELLOWBIRD_H
