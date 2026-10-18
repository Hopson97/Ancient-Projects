#ifndef APPLE_H
#define APPLE_H

#include <SFML/Graphics.hpp>

#include "Snake.h"

class Apple
{
    public:
        Apple();
        sf::Vector2i getPosition ();

        void draw           ( sf::RenderWindow& window );

        void resetPosition  ();
        void resetPosition  ( const Snake& snake );

    private:
        sf::RectangleShape  m_shape;
};

#endif // APPLE_H
