#ifndef FPS_COUNTER_H
#define FPS_COUNTER_H


#include <SFML/Graphics.hpp>

#include "window.h"
#include "../game.h"

class FPS_Counter
{
    public:
        FPS_Counter     ( const Game& game, const Window& window );

        void
        update          ();

        void
        draw            ( sf::RenderWindow& window );

    private:
        float
        getFPS          ( const sf::Time& time );

        void
        updateText      ();

        void
        updateColour    ( const float fps );

    private:
        sf::Clock fpsClock;
        sf::Clock fpsClock2;

        int     fpsCount  = 0;
        float   frameTimes  = 0;

        sf::Text m_text;

        const   Window& m_window;
};

#endif // FPS_COUNTER_H
