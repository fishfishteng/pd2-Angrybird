#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>

class Background : public GameItem
{
public:
    Background(float x, float y, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
};

#endif // BACKGROUND_H
