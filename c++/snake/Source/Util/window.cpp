#include "window.h"

#include "game_info.h"

Window :: Window()
{
    //General window stuff
    m_window.create ( sf::VideoMode( Game_Info::Window::WIDTH,
                                     Game_Info::Window::HEIGHT),
                      "Window",
                      sf::Style::Default,
                      sf::ContextSettings(24) );
    m_window.setFramerateLimit ( 120 );
}

sf::RenderWindow&
Window :: get()
{
    return m_window;
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

const bool
Window :: isOpen ()
{
    return m_window.isOpen();
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
