#include "play_stationary.h"

namespace state {

Play_Stationary::Play_Stationary(Game* game, const Ship& ship)
:   Play_Base   (game, ship)
{
    mShip.setTexture( ship.getTexture() );
    mShip.setPosition({0.0f, 0.0f}, true);
}

void Play_Stationary::input( const float dt )
{
    Play_Base::checkForUnitSelection( );
}

void Play_Stationary::update( const float dt )
{
    Play_Base::update( dt );
}

void Play_Stationary::draw( const float dt )
{
    Play_Base::draw( dt );
}

} //Name space state
