#include "Snake.h"
#include <iostream>

#include "game_info.h"

Snake :: Snake()
{
    m_segmentRectangle.setSize( { Game_Info::TILE_SIZE, Game_Info::TILE_SIZE } );
    m_segmentRectangle.setFillColor ( sf::Color::Blue );
    m_segments.push_back( { {0, 0} } );
}

void
Snake :: setDirection ( const Direction direction )
{
    std::map <Direction, Direction> oppisites
    {
        { Direction::Up,    Direction::Down  },
        { Direction::Down,  Direction::Up  },
        { Direction::Left,  Direction::Right  },
        { Direction::Right, Direction::Left },
    };

    if ( direction != oppisites.at ( m_direction ) )
    {
        m_direction = direction;
    }
}

void
Snake :: checkSelfCollide   ()
{
    sf::Vector2i nextPos = getNextPosition();
    for ( auto& segment : m_segments )
    {
        if ( nextPos == segment.position )
        {
            std::cout << "Game over " << std::endl;
            exit ( 0 );
        }
    }
}

/*
    The snake moves by adding a segment to it's next direction,
    and then removing a segment from the back of it
*/
void
Snake :: update ()
{
    checkSelfCollide();
    m_segments.push_back( { getNextPosition() } );

    if ( m_segments.size() > 5 &&
        !m_segmentsToAdd )
    {
        m_segments.erase( m_segments.begin() + 0 );
    }

    if ( m_segmentsToAdd > 0 ) m_segmentsToAdd--;
}

void
Snake :: draw ( sf::RenderWindow& window )
{
    for ( auto& segment : m_segments )
    {
        m_segmentRectangle.setPosition( (float)segment.position.x * Game_Info::TILE_SIZE,
                                        (float)segment.position.y * Game_Info::TILE_SIZE );
        window.draw( m_segmentRectangle );
    }
}

void
Snake :: addSegment ( const int amount )
{
    m_segmentsToAdd += amount;
}

const sf::Vector2i
Snake :: getNextPosition () const
{
    return m_segments.back().position + dirToVector.at ( m_direction );
}

const std::vector<Snake::Segment>&
Snake :: getSegments () const
{
    return m_segments;
}
