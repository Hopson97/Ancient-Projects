#include "bullet.h"

#include "../Components/points_towards_direction.h"
#include "../Components/tile_collidable.h"
#include "../Components/effected_by_gravity.h"

#include "../Util/math_funcs.h"
#include "../Components/friction.h"

#include "../Util/rand.h"

#include <iostream>

Bullet :: Bullet ( const Level& level, const Game& game, const Player& player, Window& window, const sf::Vector2f& targetLocation, Gravity_Particles& particles )
:   Entity ( {20,10}, player.getSpritePosition(), game.getTexture(Texture_Name::Bullet), level )
{

    addComponent( std::make_unique<Component::Tile_Collidable>
                ( *this, level, &particles, false, false ) );

    addComponent( std::make_unique<Component::Effected_By_Gravity>
                ( *this, level, window, particles ) );

    addComponent( std::make_unique<Component::Points_Towards_Direction>
                ( *this ) );



    float dy, dx;
    Math::getDyDx( getSpritePosition(), targetLocation, dx, dy );

    float angle = Math::getRotInDeg( dx, dy );
    angle = Math::toRads( angle );

    float xSpeed = (float) cos ( angle ) * m_speed;
    float ySpeed = (float) sin ( angle ) * m_speed;

    int randDirRange = 50;

    xSpeed = rng::numf( xSpeed - randDirRange, xSpeed + randDirRange );
    ySpeed = rng::numf( ySpeed - randDirRange, ySpeed + randDirRange );

    setVelocity( xSpeed, ySpeed );
}

void
Bullet :: uniqueUpdate ( const float dt )
{
    setAlive( !isFallen() );
}

bool
Bullet :: isFallen    () const
{
    return ( getVelocity().x == 0 || getVelocity().y == 0 );
}
