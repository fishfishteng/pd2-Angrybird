#include "yellowbird.h"

YellowBird::YellowBird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):Bird(x,y,radius,timer,pixmap,world,scene)
{

}

void YellowBird::SuperPower(){
    g_body->SetLinearVelocity(b2Vec2(g_body->GetLinearVelocity().x*25,g_body->GetLinearVelocity().y*25));
}
