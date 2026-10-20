#ifndef MATHS_H
#define MATHS_H

#include <SFML/Graphics.hpp>

#include <cmath>
#include <iostream>

class Maths
{
    public:
        Maths();
        float calculateAngle2Vec(sf::Vector2i vect1, sf::Vector2i vect2);
        float pythag(sf::Vector2i vect1, sf::Vector2i vect2);
    protected:
    private:
};

#endif // MATHS_H
