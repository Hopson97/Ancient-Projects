#include "animation.h"

#include <iostream>

/*****************************************************************************************************************************************************************
*   addFrame()  add a frame into the std::vector of type "Frame" (struct declared in animation.h)
*   param1  :   The frame to be added into the std::vector
***************************************************************************************************************************************************************/
void    Animation::addFrame(const Frame& frame)
{
    mFrames.emplace_back(frame);
}

/*****************************************************************************************************************************************************************
*   currentFrame()  returns the current frame of which the animation is on.
*   param1  :   delta time of which to base the animation timings on
***************************************************************************************************************************************************************/
sf::IntRect Animation::currentFrame( const float dt)
{
    if ( mFrames.size() == 0 ) {
        std::cout << "No animation set up, animation cannon play. \n";
        exit(-1);
    }
    mTime += dt;

    if ( mTime > mFrames[mCurrFrame].timeToNextFrame ) {

        mTime = 0;
        mCurrFrame++;
        if ( mCurrFrame > (mFrames.size() - 1) ) {
            mCurrFrame = 0;
        }
    }
   return mFrames[mCurrFrame].frameRectangle;
}

/*****************************************************************************************************************************************************************
*   getCurrentFrameNumber() returns whatever frame the current animation is on
***************************************************************************************************************************************************************/
const unsigned int Animation::getCurrentFrameNumber() const
{
    return mCurrFrame;
}
