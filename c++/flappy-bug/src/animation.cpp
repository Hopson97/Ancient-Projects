#include "animation.h"

Animation::Animation()
{
    frame = 1;
    nextFrame = 0;
}

void Animation::addFrame(sf::IntRect r)
{
    frames.push_back(r);    //Adds a frame to the sequence
}

void Animation::animate(sf::Sprite &s)
{
    if(nextFrameCount == 0)
    {
        std::cout << "NEED TO SET FRAME RATE COUNT! " << std::endl;
        return;
    }

    s.setTextureRect(frames[frame-1]);  //Sets the texture of the player to the current
                                        //frame number in the vector
    nextFrame++;                        //Counter for the next frame
    if(nextFrame >= nextFrameCount)     //If the counter reaches the "speed" of the animation
    {
        frame++;                        //Load the next frame
        nextFrame = 0;                  //Reset the counter
    }

    if(frame == frames.size()+1) frame = 1; //If the last frame is active, reset the frames

}

void Animation::setFrameGap(int g)
{
    std::cout << "Animation set." << std::endl;
    this->nextFrameCount = g;       //Sets the gap between frames
}

