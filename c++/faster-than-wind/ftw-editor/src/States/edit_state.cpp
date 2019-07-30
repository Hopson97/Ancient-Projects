#include "edit_state.h"

#include <fstream>

/*
=================================================================================================================================================================
Edit State is a state in this program that handles everything editing

constructor for a new ship
=================================================================================================================================================================
*/
EditState::EditState(Program* p, const std::string& filePath, const std::string& shipName, const sf::Texture& mShipTexture):
    State                   (p),                                                        //Parent constructor
    mDotMap                 (mShipTexture),                                             //Constructors
    mTextures               (filePath),
    mShipHeight             (mDotMap.getDotMapDimensions().y),
    mShipWidth              (mDotMap.getDotMapDimensions().x),
    mShip                   (mTextures, mShipWidth, mShipHeight, filePath),
    mCurrentlySelectedUI    (mTextures.getTexture(RES_TXR_CURRENTLY_SELECTED), mTextures),
    mObjectMenuUI             (mTextures.getTexture(RES_TXR_ROOM_MENU), mTextures),
    mSelectedRoom           (RT_EMPTY_SMALL),
    mMode                   (MODE_ROOM),
    mSwToWallMdeBtn         (mTextures.getTexture(RES_TXR_BTN_SWITCH_TO_WALL_MODE),     sf::Vector2f(750, 0)),
    mSwToRoomMdeBtn         (mTextures.getTexture(RES_TXR_BTN_SWITCH_TO_ROOM_MODE  ),   sf::Vector2f(750, 60)),
    mSwToUnitMdeBtn         (mTextures.getTexture(RES_TXR_BTN_SWITCH_TO_UNIT_MODE  ),    sf::Vector2f(750, 120)),
    mShipName               (shipName)
{
    selectionHasChanged = false;
    mCurrentlySelectedUI.updateSelected(mSelectedRoom, mShip.getRoomTexture(mSelectedRoom));
    mShipSprite.setTexture(mTextures.getTexture(RES_TXR_SHIP));  //Set the background ship texture to the texture just loaded

    std::cout << "Editor loaded" << std::endl;
}

/*
=================================================================================================================================================================
handle input such as clicking
=================================================================================================================================================================
*/
void EditState::input  ()
{
    mObjectMenuUI        .draw(mProgram->window());          //Needs to be put here because we can't see buttons under a scroll
    selectionHasChanged = mObjectMenuUI.checkButtonInput(mSelectedRoom, mSelectedUnit, mProgram->window(), mMode); //Check if selected button has changed

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        save();
    }


    if (mMode == MODE_ROOM)
    {
        roomInput();
        return;
    }
    else if (mMode == MODE_WALL)
    {
        wallInput();
        return;
    }
    else if (mMode == MODE_UNIT)
    {
        unitInput();
    }
}

/*
=================================================================================================================================================================

=================================================================================================================================================================
*/
void EditState::update ()
{
    mGhost.logic(sf::Mouse::getPosition(mProgram->window()),                        //Do Ghost::logic()
                 mShipWidth, mShipHeight,
                 mProgram->window());

    if (mMode == MODE_ROOM)
    {
        roomUpdate();
        return;
    }
    else if (mMode == MODE_WALL)
    {
        wallUpdate();
        return;
    }
    else if (mMode == MODE_UNIT)
    {
        unitUpdate();
    }

}

/*
=================================================================================================================================================================

=================================================================================================================================================================
*/
void EditState::draw   ()
{
    mProgram->window()                       .draw(mShipSprite);         //Draw the ship
    mShip                                    .draw(mProgram->window());  //Draw the rooms on the ship
    mGhost                                   .draw(mProgram->window());  //Draw the ghost/ selection rectangle

    mDotMap                                  .draw(mProgram->window());  //Draw the dot map
    mSwToWallMdeBtn                          .draw(mProgram->window());
    mSwToRoomMdeBtn                          .draw(mProgram->window());
    mSwToUnitMdeBtn                          .draw(mProgram->window());
    mCurrentlySelectedUI                     .draw(mProgram->window());  //Draw the currently selected stuffs
}
