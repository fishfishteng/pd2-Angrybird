#ifndef CATAPULT_H
#define CATAPULT_H

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>

class Catapult : public GameItem
{
public:
    Catapult(float x, float y, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
};

#endif // CATAPULT_H
