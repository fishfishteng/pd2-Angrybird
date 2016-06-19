#ifndef WHITEBIRD_H
#define WHITEBIRD_H

#include <bird.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>

class WhiteBird : public Bird
{
public:
    WhiteBird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    virtual void SuperPower();
};

#endif // WHITEBIRD_H
