#ifndef POWDER_H
#define POWDER_H

#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>

#include "globals.h"
#include "random.h"
#include <iostream>
class Powder
{
    public:
        void setXVel(float x);
        float getXVel() const;
        void setYVel(float y);
        float getYVel() const;

        float getXPos() const;
        float getYPos() const;

        void setPos(float x, float y);

        Powder(sf::RenderWindow &w);
        virtual ~Powder();
        int draw(sf::RenderWindow &w);
    protected:

    private:
        int logic();
        void update();

        float xVel;
        float yVel;

        sf::RectangleShape dot;

};

#endif // POWDER_H
