#ifndef BALL_H
#define BALL_H

#include "gameobject.h"
#include <iostream>

enum direction
{
    LEFT = -1,
    RIGHT = 1,
};
class Ball : public gameObject
{
    public:
        Ball();
        void logic(sf::RenderWindow &w);

        void setDir(direction _dir);
        sf::Vector2f getPos( ) const;
        void setYVel(float vel);


    protected:
    private:
        void checkBounds(sf::RenderWindow &w);
    private:
        sf::RectangleShape ball;
        direction dir;

        float yVel;

    private:
};

#endif // BALL_H
