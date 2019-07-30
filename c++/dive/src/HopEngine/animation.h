#ifndef ANIMATION_H
#define ANIMATION_H

#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>


class Animation
{
    public:
        Animation();
        void addFrame(sf::IntRect r);   //Add frames
        void animate(sf::Sprite &s);    //Play the animation
        void setFrameGap(int g);        //Set the speed (lower = faster)
    protected:
    private:
        std::vector<sf::IntRect> frames;    //vector list for the frames
        unsigned int frame;                 //The current frame showing
        int nextFrame, nextFrameCount;      //Counters and that
};

#endif // ANIMATION_H

