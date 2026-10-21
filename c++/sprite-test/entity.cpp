#include "entity.h"

Entity::Entity()
{
    //ctor
}

float Entity::getXVel()
{
    return xVelocity;
}
void Entity::setXVel(float x)
{
    xVelocity = x;
}

float Entity::getYVel()
{
    return yVelocity;
}
void Entity::setYVel(float y)
{
    yVelocity = y;
}

Entity::~Entity()
{
    //dtor
}
