
#include "Animation.h"

#include <iostream>

Animation::Animation(std::vector<Frame> frames)
:   m_frames (std::move(frames))
{ }

void Animation::addFrames( const sf::Vector2i& frameSize,
                           const sf::Vector2i& firstFrame,
                           int numberOfFrames,
                           sf::Time timeDifference)

{
    auto width  = frameSize.x;
    auto height = frameSize.y;

    auto x = firstFrame.x;
    auto y = firstFrame.y;

    for (int f = 0; f < numberOfFrames; f++, x += width)
    {
        addFrame({x, y, width, height}, timeDifference);
    }
}

void Animation::addFrame(const sf::IntRect& frame, sf::Time timeToNextFrame)
{
    if (timeToNextFrame > m_longestFrameTime)
    {
        m_longestFrameTime = timeToNextFrame;
    }

    m_frames.emplace_back(frame, timeToNextFrame);
}

const sf::IntRect& Animation::getFrame()
{
    if (m_timer.getElapsedTime() >= m_frames[m_currentFrame].timeToNextFrame)
    {
        m_currentFrame++;
        if (m_currentFrame == m_frames.size())
        {
            m_currentFrame = 0;
        }
        m_timer.restart().asSeconds();
    }

    return  m_frames[m_currentFrame].frame;
}

const sf::IntRect& Animation::getFrame(int index) const
{
    return m_frames[index].frame;
}

