#ifndef WALL_H
#define WALL_H
#include <SFML/Graphics.hpp>

#include "maths.h"

class Wall
{
    public:
        Wall(sf::RenderWindow &window);
        void logic(sf::RenderWindow &window);
    protected:
    private:
        sf::RectangleShape wall;
        sf::Vector2i startPoint;
        sf::Vector2i endPoint;
        float length;

        bool drawn;

};

#endif // WALL_H
