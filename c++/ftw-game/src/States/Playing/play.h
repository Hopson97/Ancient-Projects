#ifndef PLAY_H
#define PLAY_H


#include "../state.h"
#include "../../Engine/game.h"

#include "../../Engine/constants.h"

#include "../../Objects/Ship_Objects/Ship/ship.h"

namespace state
{

class Play_Base : public State
{
    public:
        Play_Base(Game* game, const Ship& ship);

        void        checkForUnitSelection   ( );

        void        input                   ( const float dt )      override;
        void        update                  ( const float dt )      override;
        void        draw                    ( const float dt )      override;

    protected:
        Ship                mShip;
        Unit*               mSelectedUnit   { nullptr };
        sf::RectangleShape  mSelectedRect   { {(float) ship::TILE_SIZE, (float) ship::TILE_SIZE } };

        std::vector<sf::Sound*> mRecruitSelectedSounds;

        void RecruitSel   ();

    private:
        void registerRecruitSelected();

};

} //Name space state



#endif // PLAY_H
