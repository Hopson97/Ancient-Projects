#include "maths.h"

Maths::Maths()
{
}

float Maths::calculateAngle2Vec(sf::Vector2i vect1, sf::Vector2i vect2)
{

    float dx = vect1.x - vect2.x;
    float dy = vect1.y - vect2.y;
    return atan2(dy, dx) * 180 / 3.14159;
}

float Maths::pythag(sf::Vector2i vect1, sf::Vector2i vect2)
{
    float dx = vect1.x - vect2.x;
    float dy = vect1.y - vect2.y;

    return sqrt((dx*dx)+(dy*dy));
}
