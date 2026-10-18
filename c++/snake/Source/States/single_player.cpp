#include "Single_Player.h"

#include "test.h"

#include <iostream>

#include "game_info.h"

namespace State
{

Single_Player :: Single_Player  ( Game& game )
:   State_Base ( game )
{

}

void
Single_Player :: input ( const double dt )
{
    sf::Event e;
    if ( sf::Keyboard::isKeyPressed( sf::Keyboard::W ) )
    {
        snake.setDirection( Direction::Up );
    }
    else if ( sf::Keyboard::isKeyPressed( sf::Keyboard::S ) )
    {
        snake.setDirection( Direction::Down );
    }
    else if ( sf::Keyboard::isKeyPressed( sf::Keyboard::A ) )
    {
        snake.setDirection( Direction::Left );
    }
    else if ( sf::Keyboard::isKeyPressed( sf::Keyboard::D ) )
    {
        snake.setDirection( Direction::Right );
    }
}

void
Single_Player :: update ( const double dt )
{
    snake.update();
    testAppleCollide();
}

void
Single_Player :: draw( const double dt )
{
    snake.draw  ( getWindow() );
    m_apple.draw( getWindow() );
}

void
Single_Player :: testAppleCollide ()
{
    if ( snake.getNextPosition() == m_apple.getPosition() )
    {
        snake.addSegment(5);
        m_apple.resetPosition( snake );
    }
}

} //Namespace State
