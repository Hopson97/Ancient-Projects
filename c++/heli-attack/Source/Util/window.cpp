#include "window.h"

#include <SFML/OpenGL.hpp>
#include <iostream>

#include "rand.h"

Window :: Window()
{
    //General window stuff
    m_window.create ( sf::VideoMode(Win_Info::WIDTH, Win_Info::HEIGHT),
                      "Window",
                      sf::Style::Default,
                      sf::ContextSettings(24) );

    m_window.setFramerateLimit( 150 );

    m_window.setPosition ( { 0, 0 } );


    m_view.setSize( m_window.getSize().x,
                    m_window.getSize().y );
}

sf::RenderWindow&
Window :: get()
{
    return m_window;
}


const sf::Vector2f&
Window :: getCenter   () const
{
    return m_view.getCenter();
}

const sf::Vector2u
Window :: getSize   () const
{
    return m_window.getSize();
}

void
Window :: clear ( const sf::Color& colour )
{
    m_window.clear( colour );
}

void
Window :: update ()
{
    m_window.display();
    winEvents();
}

bool
Window :: isOpen () const
{
    return m_window.isOpen();
}

void
Window :: turnOnShake ( const int intensity, const float timeSecs )
{
    m_shakeCamClock.restart();

    m_shakeIntensity    = intensity;
    m_shakeTime         = timeSecs;
}

void
Window :: updateView  ()
{
    if ( !m_viewOrigin )
    {
        throw std::runtime_error ( "The cameras view has not been set!" );
    }

    const int shake = m_shakeIntensity; //Short hand

    //Center the view (presume at player?)
    m_view.setCenter( *m_viewOrigin + m_viewOffset );

    //Shakes the camera if the intensity is > 0
    m_view.move( rng::num ( -shake, shake ),
                 rng::num ( -shake, shake )
               );

    //turns off the shake (if there is one) and the shake timer is ran out
    if ( m_shakeIntensity != 0 )
    {
        if ( m_shakeCamClock.getElapsedTime().asSeconds() >= m_shakeTime )
        {
            m_shakeCamClock.restart();
            m_shakeIntensity = 0;
            m_shakeTime = 0;
        }
    }

    m_window.setView( m_view );
}

void
Window :: setViewOrigin ( const sf::Vector2f& viewLoc )
{
    m_viewOrigin = &viewLoc;
}

void
Window :: setViewOffset   ( const float x, const float y )
{
    m_viewOffset = { x, y };
}

void
Window :: winEvents ()
{
    sf::Event e;

    while ( m_window.pollEvent ( e ) )
    {
        if ( e.type == sf::Event::Closed )
        {
            m_window.close();
        }
        else if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Escape ) )
        {
            m_window.close();
        }
    }
}

void
Window :: close ()
{
    m_window.close();
}
