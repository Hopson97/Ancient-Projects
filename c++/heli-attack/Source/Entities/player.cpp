#include "player.h"

#include "../Tiles/Util/tile_info.h"

#include "../Components/tile_collidable.h"
#include "../Components/effected_by_gravity.h"
#include "../Components/friction.h"
#include "../Components/points_towards_direction.h"

sf::Sound s;

Player :: Player(  const Level& level, const Game& game, Window& window, Gravity_Particles& bloodParticles )
:   Entity  ( { Tile::TILE_SIZE / 2, Tile::TILE_SIZE * 1.5 }, { 1000, 350 }, game.getTexture ( Texture_Name::Player ), level  )
,   m_level     ( level )
,   m_window    ( window )
{
    updateTilePosition();

    addComponent( std::make_unique<Component::Tile_Collidable>
                ( *this, m_level ) );

    addComponent( std::make_unique<Component::Effected_By_Gravity>
                ( *this, m_level, m_window, bloodParticles ) );

    addComponent( std::make_unique<Component::Friction>
                ( *this, m_level ) );

    s.setBuffer( game.getSound( Sound_Name::Walk1 ) );

    s.setVolume( 10 );


    //Set up animations
    const float m_time = 0.03; //Time between animation frames
    const int frameHeight = 70; //The frames are of equal size, so we can use these constants
    const int frameWidth  = 30;

    sf::IntRect standing = {0,              0, frameWidth, frameHeight };
    sf::IntRect walk1    = {frameWidth,     0, frameWidth, frameHeight };
    sf::IntRect walk2    = {frameWidth * 2, 0, frameWidth, frameHeight };

    m_walkAnim.addFrame( { standing, m_time } );
    m_walkAnim.addFrame( { walk1, m_time    } );
    m_walkAnim.addFrame( { standing, m_time } );
    m_walkAnim.addFrame( { walk2, m_time    } );

}

void
Player :: input ()
{
    if ( sf::Keyboard::isKeyPressed( sf::Keyboard::W ) && isOnGround() )
    {
        changeVelocity (  0, -m_jumpSpeed );
    }
    if ( sf::Keyboard::isKeyPressed( sf::Keyboard::A ) )
    {
        changeVelocity ( -m_walkSpeed, 0 );
        if ( isOnGround() )
        {
            s.play();
        }
    }
    if ( sf::Keyboard::isKeyPressed( sf::Keyboard::D ) )
    {
        changeVelocity ( m_walkSpeed, 0 );
        if ( isOnGround() )
        {
            s.play();
        }
    }
}

void
Player :: uniqueUpdate ( const float dt )
{
    if ( isMoving() && isOnGround() )
    {
        setTextureRect( m_walkAnim.currentFrame( dt ) );
    }
    else if ( !isOnGround())
    {   //The "walk1" texture rectangle of the players sprite sheet for when standing
        setTextureRect({30, 0, 30, 70 });
    }
    else
    {
        setTextureRect({0, 0, 30, 70 });
    }
}
