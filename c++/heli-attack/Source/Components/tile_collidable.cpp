#include "tile_collidable.h"

#include "../Tiles/Util/tile_info.h"

#include "Funcs/tile_map_component_funcs.h"

namespace Component
{

Tile_Collidable :: Tile_Collidable( Entity& entity, const Level& level, Gravity_Particles* dirt,
                                    const bool collideDown, const bool bounceOnCollide )
:   m_entity            ( entity )
,   m_level             ( level )
,   m_dirtParticles     ( dirt )
,   m_isCollideDown     ( collideDown)
,   m_isBounceOnCollide ( bounceOnCollide)
{
}

Tile_Collidable :: Tile_Collidable( Entity& entity, const Level& level, const bool collideDown, const bool bounceOnCollide )
:   m_entity            ( entity )
,   m_level             ( level )
,   m_isCollideDown     ( collideDown)
,   m_isBounceOnCollide ( bounceOnCollide)
{
}


Tile_Collidable :: Tile_Collidable( Entity& entity, const Level& level, Gravity_Particles* dirt )
:   m_entity        ( entity )
,   m_level         ( level )
,   m_dirtParticles ( dirt )
{
}

void
Tile_Collidable :: update ( const float dt )
{
   if ( m_level.getTileAt( m_entity.getTilePosition())->isSolid() ) m_entity.setAlive( false );

    checkLeftCollide    ( dt );
    checkRightCollide   ( dt);
    checkUpCollide      ( dt);

    if ( m_isCollideDown ) checkDownCollide( dt );
}

float slowDownMultiplier = 0.93;

void
Tile_Collidable :: checkXTile ( const sf::Vector2f& newPos )
{
    if ( tileSolid ( m_level, newPos ) )
    {
        addParticles();
        if ( m_isBounceOnCollide )
        {
            m_entity.setVelocity( -m_entity.getVelocity().x * slowDownMultiplier,
                                  -m_entity.getVelocity().y * ( slowDownMultiplier / 2 ) );
        }
        else
        {
            m_entity.resetXVelocity();
        }
    }
}

void
Tile_Collidable :: checkYTile ( const sf::Vector2f& newPos )
{
    if ( tileSolid ( m_level, newPos ) )
    {
        addParticles();
        if ( m_isBounceOnCollide )
        {
            m_entity.setVelocity( -m_entity.getVelocity().x * ( slowDownMultiplier / 2 ),
                                  -m_entity.getVelocity().y * slowDownMultiplier );
        }
        else
        {
            m_entity.resetYVelocity();
        }
    }
}

void
Tile_Collidable :: checkLeftCollide    ( const float dt )
{
    sf::Vector2f newPos = getNextPosition ( m_entity, dt );

    if ( m_entity.getVelocity().x < 0 )
    {
        checkXTile( newPos );

        newPos.y += m_entity.getSpriteSize().y - 1;

        checkXTile( newPos );
    }
}

void
Tile_Collidable :: checkRightCollide   ( const float dt )
{
    sf::Vector2f newPos = getNextPosition ( m_entity, dt );

    newPos.x += m_entity.getSpriteSize().x;

    if ( m_entity.getVelocity().x > 0 )
    {
        checkXTile( newPos );

        newPos.y += m_entity.getSpriteSize().y - 1;

        checkXTile( newPos );
    }
}

void
Tile_Collidable :: checkUpCollide      ( const float dt )
{
    sf::Vector2f newPos = getNextPosition ( m_entity, dt );

    if ( m_entity.getVelocity().y < 0 )
    {
        checkYTile( newPos );

        newPos.x += m_entity.getSpriteSize().x - 1;

        checkYTile( newPos );
    }
}

void
Tile_Collidable :: checkDownCollide      ( const float dt )
{
    sf::Vector2f newPos = getNextPosition ( m_entity, dt );

    newPos.y += m_entity.getSpriteSize().y;

    if ( m_entity.getVelocity().y > 0 )
    {
        checkYTile( newPos );

        newPos.x += m_entity.getSpriteSize().x - 1;

        checkYTile( newPos );
    }
}

void
Tile_Collidable :: addParticles ()
{
    if ( m_dirtParticles )
    {
        m_dirtParticles->addParticles(  5,
                                       {m_entity.getSpritePosition().x + m_entity.getSpriteSize().x / 2,
                                        m_entity.getSpritePosition().y + m_entity.getSpriteSize().y / 2 },
                                       {-m_entity.getVelocity().x * 2,
                                       ( m_entity.getVelocity().y > 0) ? //The ternary operators here guarntee the particle to go up
                                        -m_entity.getVelocity().y / 10 :
                                         m_entity.getVelocity().y / 10 } );
    }
}

} //Namespace Component
