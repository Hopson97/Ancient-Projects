#include "ball.h"

Ball::Ball()
{
    this->rect.setPosition(325, 300);
}

void Ball::logic(sf::RenderWindow &window)
{
    window.draw(rect);
}
