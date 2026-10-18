#include "zombie.h"

Zombie::Zombie(sf::Texture t,
               sf::RenderWindow &window)
{
    texture = t;
    sprite.setTexture(texture);

    this->sprite.setPosition(300,300);
}
