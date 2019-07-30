#include "play.h"

#include "../../Utilities/random.h"

namespace state {

Play_Base::Play_Base(Game* game, const Ship& ship)
:   State   (game)
,   mShip   (ship)
{
    mSelectedRect.setFillColor          ( { 0, 0, 0, 0 } );
    mSelectedRect.setOutlineColor       (  col::WATER );
    mSelectedRect.setOutlineThickness   (  2             );

    registerRecruitSelected();
}

void Play_Base::input    (const float dt)
{
    checkForUnitSelection( );
}

void Play_Base::update   (const float dt)
{
    if ( mSelectedUnit != nullptr) {
        mSelectedRect.setPosition ( mSelectedUnit->getPos( ) );
    }
}

void Play_Base::draw     (const float dt)
{
    mShip.draw( _mGame().window() );
}

void Play_Base::checkForUnitSelection (  )
{
    if ( sf::Mouse::isButtonPressed ( sf::Mouse::Left) ) {                  //If the mouse is down
        for ( unsigned int i = 0; i < mShip.getUnits().size() ; i++ ) {     //Iterate through the vector of units
            if(mShip.getUnits()[i].clicked( _mGame().window(), false ) ) {                     //If the unit the current iteration is on is clicked
                if(mSelectedUnit != nullptr) {
                    mSelectedUnit->setSelectedState ( false );
                }
                mSelectedUnit = &mShip.getUnits()[i];                       //Set the selected unit pointer to point at it.
                mSelectedUnit->setSelectedState ( true );
                RecruitSel();
            }
        }
    }
}

void Play_Base::registerRecruitSelected()
{
    mRecruitSelectedSounds.emplace_back( &_mGame().getSounds().getSound( RES_SOUND_UNIT_RECRUIT_SELECTED_1 ) );
    mRecruitSelectedSounds.emplace_back( &_mGame().getSounds().getSound( RES_SOUND_UNIT_RECRUIT_SELECTED_2 ) );
}

void Play_Base:: RecruitSel()
{
    /*
    int n = rng ::num( 0, mRecruitSelectedSounds.size() - 1 );

    mRecruitSelectedSounds[n]->play();
    */
}

}
