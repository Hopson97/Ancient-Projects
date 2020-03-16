#include "world.h"

#include "Util/colours.h"

World :: World( Game& game )
:   m_game      ( game )
,   m_level     ( game )
,   m_player    ( m_level, game, game.getWindow(), m_blood )
,   m_blood     ( sf::Color::Red, m_level )
,   m_dirt      ( Colour::Brown,  m_level )
{
}

void
World :: input ()
{
    m_player.input();
}

void
World :: update ( const float dt )
{
    updateEntites( dt );

    m_player.update( dt );

    m_game.getWindow().updateView();

    m_blood.update( dt );
    m_dirt .update( dt );
}

void
World :: draw ( sf::RenderWindow& window )
{
    m_level .draw    ( window, m_player.getTilePosition() );
    m_player.draw   ( window );

    m_blood .draw( window );
    m_dirt  .draw( window );

    for ( auto& bullet : m_bullets ) bullet->draw ( window );
    for ( auto& enemy : m_enemies  ) enemy ->draw ( window );
}

void
World :: addBullet ( )
{
    sf::RenderWindow& win = m_game.getGameWindow();
    sf::Vector2f pos = win.mapPixelToCoords ( sf::Mouse::getPosition( win ) );

    m_bullets.emplace_back
        ( std::make_unique<Bullet>
            (m_level, m_game, m_player, m_game.getWindow(), pos, m_dirt ) );
}

void
World :: addEye ()
{
    m_enemies.emplace_back( std::make_unique<Test_Enemy>(
                            m_game,
                            m_level,
                            m_player,
                            m_blood,
                            m_bullets ) );
}

const Player&
World :: getPlayer () const
{
    return m_player;
}

void
World :: updateEntites ( const float dt )
{
    iterateEntitiess( m_bullets, dt );
    iterateEntitiess( m_enemies, dt );
}

