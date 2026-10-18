#include "entity.h"

Entity::Entity()
{
    //ctor
}

void Entity::logic(sf::RenderWindow& window)
{
    for(auto &comp: components) comp->logic();

    this->uniqueLogic();

    window.draw(sprite);
}

void  Entity::uniqueLogic()
{
    //Override this VIRTUAL method in derived classes if needed
}
