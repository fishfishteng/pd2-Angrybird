#include "blackbird.h"
#include <iostream>

BlackBird::BlackBird(float x, float y ,float radius, QTimer *timer, QPixmap pixmap,b2World *world, QGraphicsScene *scene):Bird(x,y,radius,timer,pixmap,world,scene)
{

}

void BlackBird::SuperPower(){
    //std::cout<<"Super Power!!"<<std::endl;
    g_body->SetLinearVelocity(b2Vec2(0,-100));
}
