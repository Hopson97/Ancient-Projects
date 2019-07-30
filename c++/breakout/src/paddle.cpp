#include "paddle.h"

Paddle::Paddle()
{
    this->rect.setPosition(0,500);

    sf::Vector2f size(220, 10);
    this->rect.setSize(size);
}

void Paddle::logic(sf::RenderWindow &window)
{
    window.draw(rect);
}
