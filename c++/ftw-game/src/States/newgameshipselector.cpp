#include "newgameshipselector.h"

#include "mainmenu.h"
#include <string>
#include <iostream>

#include "../Engine/constants.h"

#include "Playing/play_stationary.h"

namespace state {

NewGameShipSelector::NewGameShipSelector(Game* game,  TextureManager& manager)
:   State                   ( game    )
,   mCurrentShip            ( manager )
{
    _mGame().setClearColour( col::WATER);
    setUpButtons();
    setUpLabels();

    mCurrentShip.setPosition(sf::Vector2f((win::WIDTH  / 2) - ship::WIDTH,
                             (win::HEIGHT / 2) - 150),
                             false);

    addShipsToVector();
    shipString = mshipNameList[0];

    mCurrShipLabel.setUpText( "\"" + shipString + "\"", txtSz::small, _mGame().getFont( RES_FONT_FANCY ));

    addEntitysToVector();
    changeCurrentShip(-1);  //Disgusting fix to a unknown cause of a glitch

    resetShip();
}

/*****************************************************************************************************************************************************************
*   input() handle input of this class
*   param1  :   games's delta time
***************************************************************************************************************************************************************/
void NewGameShipSelector::input (const float dt)
{
    if ( mPrevShipButton.clicked ( _mGame().window(), true ) ) {
        changeCurrentShip(-1);
    }
    if ( mNextShipButton.clicked ( _mGame().window(), true ) ) {
        changeCurrentShip(1);
    }

    if ( mLayout1Button.clicked ( _mGame().window(), true ) ) {
        mCurrentLayout.setValue( 1 );
        resetShip();
    }
    if ( mLayout2Button.clicked ( _mGame().window(), true ) ) {
        mCurrentLayout.setValue( 2 );
        resetShip();
    }
    if ( mLayout3Button.clicked ( _mGame().window(), true ) ) {
        mCurrentLayout.setValue( 3 );
        resetShip();
    }
    if ( mConfirmSelectionButton.clicked( _mGame().window(), true ) ) {
        _mGame().getStates(false).changeState(std::make_shared<Play_Stationary>( &_mGame(), mCurrentShip));
    }
    if ( mBackToMainMenuButton.clicked( _mGame().window(), true ) ) {
        _mGame().getStates(false).popState();
    }
}

/*****************************************************************************************************************************************************************
*   update()    update this states objects
*   param1  :   games's delta time
***************************************************************************************************************************************************************/
void NewGameShipSelector::update (const float dt)
{
    mCurrentShip.update(dt);
    if ( mCurrentLayout.getValue() == 1 ) {
        mLayout1Button.setColour( col::SELECTED );
    }
    else if ( mCurrentLayout.getValue() == 2 ) {
        mLayout2Button.setColour( col::SELECTED );
    }
    else if ( mCurrentLayout.getValue() == 3 ) {
        mLayout3Button.setColour( col::SELECTED );
    }

    mWater.update(dt);

    if ( mCurrentShip.getPosition().x > win::WIDTH ) {
            mCurrentShip.setPosition
                                    ({(float) -mCurrentShip.getWidth(),
                                     (float) mCurrentShip.getPosition().y},
                                      true);

    }
    else mCurrentShip.translate({100.0f, 0.0f}, dt);

}

/*****************************************************************************************************************************************************************
*   draw()  draw this states sprites
*   param1  :   games's delta time
***************************************************************************************************************************************************************/
void NewGameShipSelector::draw (const float dt)
{
     mWater.draw( _mGame().window() );

    for ( auto& entity : mEntities ) {
        entity->draw( _mGame().window() );
    }
    for ( auto& unitShower : mUnitShowers ) {
        unitShower.draw( _mGame().window() );
    }
    mCurrentShip.draw( _mGame().window() );
}

/*****************************************************************************************************************************************************************
*   changeCurrentShip() changes the current ship name
*   param1  :   The amount to increment the ship number by (1 or -1)
***************************************************************************************************************************************************************/
void NewGameShipSelector::changeCurrentShip(const int increment)
{
    if ( !(increment >  -1) && !(increment < 1) ) {     //Check if increment is within range
        return;
    }

    mCurrentShipNumber += increment;                    //If it is, then increment/ decrement the amount by the argument

    if ( mCurrentShipNumber < 0 ) {             //Check if the current ship number is less than than zero
        mCurrentShipNumber = 0;                 //If it is, then it means something is wrong and resets the number and returns
        return;
    }

    if ( ( unsigned int ) mCurrentShipNumber > mshipNameList.size() - 1 ) { //Check if the current ship number is greater than the ship list size
        mCurrentShipNumber = mshipNameList.size();                          //If it is, then it means something is wrong and resets the number and returns
        return;
    }

    shipString = mshipNameList[mCurrentShipNumber]; //If all the error checks pass, then change the current ship and reset it
    mCurrentLayout.setValue( 1 );
    mCurrShipLabel.setText( "\"" + shipString + "\"" );
    resetShip();
}

/*****************************************************************************************************************************************************************
*   resetShip() resets the ship by loading a new one from the ship loader.
***************************************************************************************************************************************************************==
*/
void NewGameShipSelector::resetShip()
{
    mShipLoader.loadShip( &mCurrentShip, "Resources/Ship Info/" + shipString + std::to_string(mCurrentLayout.getValue()) + ".ship", _mGame().getTexture_m() );

    mUnitShowers.clear();
    int xPos = 0;
    for( auto& unit : mCurrentShip.getUnits() ) {
        mUnitShowers.emplace_back( ui::UnitShower ( *mCurrentShip.getTexture(unit.getType()), {float(xPos), float(600) } )  );
        xPos += 45;
    }
}

/*****************************************************************************************************************************************************************
*   setUpLayoutButtons() is a constructor only method that sets up the buttons that allow the player so choose the ship's layout
***************************************************************************************************************************************************************==
*/
void NewGameShipSelector::setUpButtons()
{
    mBackToMainMenuButton.moveTextDown ( 20 );
}

void NewGameShipSelector::setUpLabels()
{
    shipYardLogo.setPos(sf::Vector2f(win::WIDTH / 2 - shipYardLogo.getSprite().getLocalBounds().width / 2, 0) );
    shipYardLogo.setUpText( "Ship Yard", txtSz::large, _mGame().getFont( RES_FONT_FANCY ));
    shipYardLogo.moveTextDown ( 12 );

    mListButtonText.setPos( sf::Vector2f( 97, LIST_BUTTON_Y ) );

    mCurrShipLabel.setPos   (sf::Vector2f( win::WIDTH - 668 - mCurrShipLabel.getSprite().getLocalBounds().width / 2,
                                           LIST_BUTTON_Y ) );
}

/*****************************************************************************************************************************************************************
*   addShipsToVector() is a constructor only method that sets up the list of which is the ships name
***************************************************************************************************************************************************************==
*/
void NewGameShipSelector::addShipsToVector()
{
    mshipNameList.emplace_back( "StarterShip" );
    mshipNameList.emplace_back( "Ship" );
}

/*****************************************************************************************************************************************************************
*   addEntitysToVector() is a constructor only method that adds all the entities into the entity list vector (for the this->draw() )
***************************************************************************************************************************************************************/
void NewGameShipSelector::addEntitysToVector()
{
    mEntities.emplace_back( &stones          );
    mEntities.emplace_back( &shipYardLogo    );  //Add the ship yard logo to the entity list
    mEntities.emplace_back( &mCurrShipLabel  );

    mEntities.emplace_back( &mPrevShipButton );  //Add the ship selection entities to the entity list
    mEntities.emplace_back( &mNextShipButton );
    mEntities.emplace_back( &mListButtonText );

    mEntities.emplace_back( &mLayout1Button  );   //Add layout buttons to the entity list
    mEntities.emplace_back( &mLayout2Button  );
    mEntities.emplace_back( &mLayout3Button  );

    mEntities.emplace_back( &mConfirmSelectionButton);

    mEntities.emplace_back( &mBackToMainMenuButton );
}


}
