#include "entity.h"

Entity::Entity()
{
    //ctor
}

void Entity::logic(sf::RenderWindow &window)
{
    window.draw(this->sprite);
}

void Entity::draw(sf::RenderWindow &window)
{
    window.draw(this->sprite);
}
