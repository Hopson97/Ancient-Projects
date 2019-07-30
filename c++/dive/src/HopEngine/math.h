#ifndef MATH_H
#define MATH_H

#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>
#include <iostream>

class Math
{
    public:
        Math();
        sf::Vector2f normaliseVector(sf::Vector2f v1, sf::Vector2f v2);
        int randRange(int low, int high);	//Call this method for random numbers
        int vecAngle(sf::Vector2f v1, sf::Vector2f v2);
    protected:
    private:
};

#endif // MATH_H
