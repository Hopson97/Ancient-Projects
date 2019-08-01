#include "test.h"

#include "../Util/colours.h"


#include <iostream>

namespace State
{
    float delay = 0.1f;

Test :: Test  ( Game& game )
:   State_Base  ( game )
,   m_world     ( game )
,   m_gunSound  ( m_game.getSound( Sound_Name::Bullet_Generic ) )
{
    //Set the games view that the cameras centre is just below the player
    m_game.getWindow().setViewOrigin(  m_world.getPlayer().getSpritePosition() );
    m_game.getWindow().setViewOffset( 0, -m_world.getPlayer().getSpriteSize().y );
}

sf::Clock bulletDelay;

void
Test :: input ( const double dt )
{
    m_world.input();
    //Adding of the bullets
    if ( sf::Mouse::isButtonPressed( sf::Mouse::Left ) && bulletDelay.getElapsedTime().asSeconds() >= delay )
    {
        m_world.addBullet();

        m_gunSound.play();
        bulletDelay.restart();
    }

}

sf::Clock enemyClock;
void
Test :: update ( const double dt )
{
    if ( enemyClock.getElapsedTime().asSeconds() >= delay * 3 )
    {
        m_world.addEye();
        enemyClock.restart();
    }

    m_world.update( dt );
}

void
Test :: draw( const double dt )
{
    m_world.draw( m_game.getGameWindow() );
}

} //Namespace State
