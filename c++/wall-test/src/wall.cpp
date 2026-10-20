#include "wall.h"

Wall::Wall(sf::RenderWindow &window)
{
    drawn = false;
    length = 50;
    sf::Vector2f size(10, length);
    wall.setSize(size);
    startPoint = sf::Mouse::getPosition(window);
    wall.setPosition(sf::Vector2f(startPoint));

    wall.setOutlineColor(sf::Color::Red);
    wall.setOutlineThickness(2);
}

void Wall::logic(sf::RenderWindow &window)
{
    Maths m;
    if(!drawn)
    {
        endPoint = sf::Mouse::getPosition(window);
        length = (m.pythag(startPoint, endPoint));

        sf::Vector2f size(10, length);
        wall.setSize(size);

        wall.setRotation((m.calculateAngle2Vec(startPoint,
                                                sf::Mouse::getPosition(window))) + 90);

    }
    if(!sf::Mouse::isButtonPressed(sf::Mouse::Left))
        drawn = true;

    for(int i = 0; i < 10; i++)
    {
        window.draw(wall);
        wall.move(0,-1);
    }
    wall.move(0,10);
}
