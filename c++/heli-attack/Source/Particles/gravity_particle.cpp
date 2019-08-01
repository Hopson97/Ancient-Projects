#include "gravity_particles.h"

//Particle constructor
Gravity_Particles :: Particle :: Particle ( const Level& level, const sf::Vector2f& direction )
:   m_level  ( &level )
{
    const float dy = direction.y;
    const float dx = direction.x;

    //If there is "no direction", then we give it a rng direction
    if ( dx == 0 )
        while ( m_velocity.x == 0)
            m_velocity.x = rng::numf( -2, 2 );
    if ( dy == 0 )
        while ( m_velocity.y == 0)
            m_velocity.y = rng::numf( -2, 2 );

    //We use ternary operators here because the function rng::num takes in a low and then a high number
    //If the number is positive/ negative, it would otherwise always return a positive number
    while ( m_velocity.x == 0)
        m_velocity.x = rng::numf( dx > 0 ? 1  : dx,
                                    dx > 0 ? dx : -1 );

    while ( m_velocity.y == 0)
        m_velocity.y = rng::numf( dy > 0 ? 1  : dy,
                                    dy > 0 ? dy : -1 );
    //Multiply by 50 because it is too slow otherwise (thanks to delta time )
    m_velocity.x *= 50;
    m_velocity.y *= 50;

    const int maxSpeed = 500;

    if ( m_velocity.y > maxSpeed ) m_velocity.y = maxSpeed;
    if ( m_velocity.x > maxSpeed ) m_velocity.x = maxSpeed;

    if ( m_velocity.y < -maxSpeed ) m_velocity.y = -maxSpeed;
    if ( m_velocity.x < -maxSpeed ) m_velocity.x = -maxSpeed;
}


//Particle :: onGround
const bool
Gravity_Particles :: Particle :: onGround( const sf::Vertex& vertex, const float dt )
{
    if( !isOnSolidTile(vertex) )
    {
        m_velocity.y += m_level->getGravity() * dt;
        return false;
    }
    else if ( isOnSolidTile(vertex) )
    {
        m_velocity.y = 0;
        m_velocity.x = 0;

        return true;
    }
    return false;
}

//isOnSolidTile for Particle
const bool
Gravity_Particles :: Particle :: isOnSolidTile( const sf::Vertex& vertex )
{
    int tilePositionX = vertex.position.x / Tile::TILE_SIZE;
    int tilePositionY = vertex.position.y / Tile::TILE_SIZE;

    if ( tilePositionX < 0 ) tilePositionX = 0;
    if ( tilePositionY < 0 ) tilePositionY = 0;


    return m_level->getTileAt( tilePositionX, tilePositionY )->isSolid();
}

//Particle :: getVecloity
const sf::Vector2f&
Gravity_Particles :: Particle :: getVelocity () const
{
    return m_velocity;
}
