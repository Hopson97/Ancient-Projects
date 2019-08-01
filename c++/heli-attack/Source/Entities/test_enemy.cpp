#include "test_enemy.h"

#include "../Components/points_towards_direction.h"
#include "../Components/tile_collidable.h"
#include "../Components/effected_by_gravity.h"

#include "../Util/math_funcs.h"
#include <iostream>

static int count = 0;

Test_Enemy :: Test_Enemy( const Game& game, const Level& level, const Player& player,
                         Gravity_Particles& blood, std::vector<BulletPtr>& bullets )
:   Entity      ( { 20, 20 }, game.getTexture(Texture_Name::Eye_Enemy), level )
,   m_player    ( player )
,   m_blood     ( blood )
,   m_bullets   ( bullets )
{
    spawnInrngAirTile();

    addComponent( std::make_unique<Component::Points_Towards_Direction>
                ( *this ) );

    addComponent( std::make_unique<Component::Tile_Collidable>
                ( *this, level, true, true ) );


    //lol
    //addComponent( std::make_unique<Component::Effected_By_Gravity>
    //            ( *this, level ) );

   centerSpriteOrigin();
}

void
Test_Enemy :: uniqueUpdate( const float dt )
{
    float dy, dx;

    Math::getDyDx( getSpritePosition(), m_player.getSpritePosition(), dx, dy );

    float angle = Math::getRotInDeg( dx, dy );
    angle = Math::toRads( angle );

    float xSpeed = (float) cos ( angle ) * m_accleration;
    float ySpeed = (float) sin ( angle ) * m_accleration;

    setVelocity( getVelocity().x + xSpeed, getVelocity().y + ySpeed );

    for ( auto& bullet : m_bullets )
    {
        if ( intersects( *bullet ) )
        {
            std::cout << "Number dead: " << ++count << std::endl;
            setAlive( false );
            m_blood.addParticles( 30, getSpritePosition(), { 0, 0} );
            bullet->setAlive ( false );
        }
    }

    //if ( getVelocity().x > m_maxVel ) setVelocity (  m_maxVel, getVelocity().y );
    //if ( getVelocity().x < m_maxVel ) setVelocity ( -m_maxVel, getVelocity().y );

    //if ( getVelocity().y > m_maxVel ) setVelocity ( getVelocity().x, m_maxVel );
    //if ( getVelocity().y < m_maxVel ) setVelocity ( getVelocity().x, -m_maxVel );

}


