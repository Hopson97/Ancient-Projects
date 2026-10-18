#include "ball.h"

Ball::Ball()
{
    ball.setPosition(400,300);

    sf::Vector2f ballSize(10,10);
    ball.setSize(ballSize);

    ball.setOutlineColor(sf::Color::Red);
    ball.setOutlineThickness(1);

    yVel = 0;
    dir = LEFT;
}

void Ball::logic(sf::RenderWindow &w)
{

    ball.move(dir * 7, yVel);
    checkBounds(w);
    w.draw(ball);
}

void Ball::checkBounds(sf::RenderWindow &w)
{
    if(ball.getPosition().y > w.getSize().y)
        yVel = -(yVel);

    if(ball.getPosition().y < 0)
        yVel = -(yVel);

}




void Ball::setDir(direction _dir)
{
    dir = _dir;
}
sf::Vector2f Ball::getPos( ) const
{
    return ball.getPosition();
}

void Ball::setYVel(float vel)
{
    if(vel >= 3) vel = 3;
    yVel = vel;
}
