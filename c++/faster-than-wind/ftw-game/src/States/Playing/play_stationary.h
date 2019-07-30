#ifndef PLAY_STATIONARY_H
#define PLAY_STATIONARY_H

#include "play.h"
#include "../../Engine/game.h"

#include "../../Objects/Ship_Objects/Ship/ship.h"

namespace state
{

class Play_Stationary : public Play_Base
{
    public:
        Play_Stationary(Game* game, const Ship& ship);

        void        input                   ( const float dt )      override;
        void        update                  ( const float dt )      override;
        void        draw                    ( const float dt )      override;



    private:

};

} //Name space state

#endif // PLAY_STATIONARY_H
