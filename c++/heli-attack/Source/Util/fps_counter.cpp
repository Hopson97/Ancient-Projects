#include "fps_counter.h"

#include <string>
#include <iostream>

#include "colours.h"

FPS_Counter :: FPS_Counter ( const Game& game, const Window& window )
:   m_window    ( window )
{
    m_text.setFont( game.getFont(Font_Name::Arial));
    m_text.setCharacterSize( 20 );
}

void
FPS_Counter :: update ()
{
    m_text.setPosition( m_window.getCenter().x - (m_window.getSize().x / 2),
                        m_window.getCenter().y - (m_window.getSize().y / 2 )
                    );

    frameTimes +=   getFPS( fpsClock.restart() );
    fpsCount ++;

    updateText();
}

void
FPS_Counter :: draw ( sf::RenderWindow& window )
{
    window.draw( m_text );
}

float
FPS_Counter :: getFPS(const sf::Time& time)
{
    //Converts the time to seconds
    return (1000000.0f / time.asMicroseconds());
}

void
FPS_Counter :: updateText      ()
{
    static float delayForUpdate = 0.4f;

    if ( fpsClock2.getElapsedTime().asSeconds() >= delayForUpdate )
    {
        float FPS = frameTimes / fpsCount;

        updateColour( FPS );
        m_text.setString( std::to_string( FPS ) );

        frameTimes  = 0;
        fpsCount    = 0;
        fpsClock2.restart();
    }
}

void
FPS_Counter :: updateColour    ( const float fps )
{
    const static int    lowestBound = 100,
                        upperBound  = 250;

    if ( fps < lowestBound )
    {
        m_text.setColor( sf::Color::Red );
    }
    else if ( fps >= lowestBound && fps < upperBound )
    {
        m_text.setColor( Colour::Orange );
    }
    else if ( fps >= upperBound )
    {
        m_text.setColor( Colour::DarkGreen );
    }
}
