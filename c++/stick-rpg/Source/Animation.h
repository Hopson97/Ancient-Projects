#ifndef ANIMATION_H_INCLUDED
#define ANIMATION_H_INCLUDED

#include <SFML/Graphics.hpp>

#include <vector>

class Animation
{
    public:
        struct Frame
        {
            Frame(const sf::IntRect& frame, sf::Time timeToNextFrame)
            :   frame           (frame)
            ,   timeToNextFrame (timeToNextFrame) {}

            sf::IntRect frame;
            sf::Time    timeToNextFrame;
        };

        Animation() = default;
        Animation(std::vector<Frame> frames);

        void addFrames( const sf::Vector2i& frameSize,
                        const sf::Vector2i& firstFrame,
                        int numberOfFrames,
                        sf::Time timeDifference);




        void addFrame (const sf::IntRect& frame, sf::Time timeToNextFrame);

        const sf::IntRect& getFrame();
        const sf::IntRect& getFrame(int index) const;

    private:
        std::vector<Frame> m_frames;

        sf::Clock   m_timer;
        unsigned    m_currentFrame      = 0;
        sf::Time    m_longestFrameTime  = sf::Time::Zero;
};

#endif // ANIMATION_H_INCLUDED
