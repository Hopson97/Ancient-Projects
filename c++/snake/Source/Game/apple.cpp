#include "apple.h"

#include "game_info.h"
#include "rand.h"

#include <iostream>

Apple :: Apple()
{
    m_shape.setSize ( { Game_Info::TILE_SIZE, Game_Info::TILE_SIZE } );
    m_shape.setFillColor( sf::Color::Red );
    resetPosition();
}

sf::Vector2i
Apple :: getPosition ()
{
    return sf::Vector2i( m_shape.getPosition().x / Game_Info::TILE_SIZE,
                         m_shape.getPosition().y / Game_Info::TILE_SIZE);
}

void
Apple :: draw ( sf::RenderWindow& window )
{
    window.draw ( m_shape );
}

void
Apple :: resetPosition ()
{
    int x = Random::integer(0, (Game_Info::Window::WIDTH  ) );
    int y = Random::integer(0, (Game_Info::Window::HEIGHT ) );

    while ( x % Game_Info::TILE_SIZE )
    {
        x--;
    }
    while (y  % Game_Info::TILE_SIZE )
    {
        y--;
    }

    m_shape.setPosition( x, y );
}

void
Apple :: resetPosition ( const Snake& snake )
{
    resetPosition();
    for ( auto& segment : snake.getSegments() )
    {
        if ( segment.position == getPosition() ) resetPosition();
    }
}
