#include "catapult.h"

Catapult::Catapult(float x, float y, QPixmap pixmap, b2World *world, QGraphicsScene *scene):GameItem(world)
{
    // Set pixmap
    g_pixmap.setPixmap(pixmap);
    g_pixmap.setTransformOriginPoint(g_pixmap.boundingRect().width()/2,g_pixmap.boundingRect().height()/2);
    g_pixmap.setPos(x+70,y+407);
    g_size = QSize(x*2,y*2);

    scene->addItem(&g_pixmap);
}
