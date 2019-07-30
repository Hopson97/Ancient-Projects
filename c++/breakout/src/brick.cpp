#include "brick.h"

Brick::Brick(int x, int y)
{
    sf::Vector2f s(50, 20);


    this->rect.setOutlineThickness(1);
    this->rect.setPosition(x, y);
    this->rect.setSize(s);

    this->rect.setOutlineColor(this->randomColour());
    this->rect.setFillColor(this->randomColour());
}

void Brick::logic(sf::RenderWindow &window)
{
    window.draw(rect);
    this->rect.setOutlineColor(this->randomColour());
    this->rect.setFillColor(this->randomColour());
}

sf::Color Brick::randomColour()
{
    Random r;
    sf::Color c;
    c.r = r.randRange(0,255);
    c.g = r.randRange(0,255);
    c.b = r.randRange(0,255);

    return c;
}


