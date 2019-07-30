#ifndef BIRD_H
#define BIRD_H

#include <SFML/Graphics.hpp>
#include "animation.h"

#include <string>
#include <iostream>

class Bird
{
    public:
        Bird();
        void logic(sf::RenderWindow &window);
        void preLogic(sf::RenderWindow &window);
    protected:
    private:
        sf::Sprite bird;
        sf::Texture texture;
        Animation fly;

        float yVel;

    private:
        void setUpAnim();

        void input();
        void update();
        int inputted;




};

#endif // BIRD_H
