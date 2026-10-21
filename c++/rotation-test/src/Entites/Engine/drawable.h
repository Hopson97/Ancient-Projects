#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <iostream>
#include <cmath>

#include <SFML/Graphics.hpp>

#include "../../globals.h"
#include "animation.h"

class Drawable
{
    public:
        Drawable();
    protected:


        sf::Vector2f normaliseVector(sf::Vector2f vec);     //Normalise a vector
        void addSpeedToVector(sf::Vector2f &vec);    //Adds speed onto a vector

        float speed;    //"Speed" of a drawable thing
    private:

};

#endif // DRAWABLE_H
