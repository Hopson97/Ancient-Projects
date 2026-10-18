#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Ball;

class gameObject
{
    public:
        gameObject();
        virtual void logic(sf::RenderWindow &w, Ball &ball);
    protected:
    private:
};

#endif // GAMEOBJECT_H
