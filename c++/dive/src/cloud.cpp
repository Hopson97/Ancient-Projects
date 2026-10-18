#include "cloud.h"

Cloud::Cloud(sf::Texture &t)
{
    Math m;
    direction = 1;
    this->texture = t;
    this->sprite = sf::Sprite{texture};
    //this->sprite->setTexture(texture);
    this->setSpeed(10);
    this->sprite->setPosition(
        {(float)m.randRange(-120, gbl::WIN_WIDTH), (float)m.randRange(0, 400)});
    this->setSpeed(float(m.randRange(5, 12)));
    this->minHeight = 300;
    this->maxHeight = 0;

}






