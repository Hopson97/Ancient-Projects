#include "edit_state.h"

void EditState::switchToRoomMode()
{
    mMode = MODE_ROOM;

    mGhost.setMode(room);
    mCurrentlySelectedUI.updateSelected(mSelectedRoom, mShip.getRoomTexture(mSelectedRoom));
    mGhost.updateRectSize(mShip.getRoomSize(mSelectedRoom));
    std::cout << "Changing to room mode \n";
}

void EditState::roomInput()
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)                                 //If left mouse button is pressed
       && !mGhost.isOutOfBounds(mShipWidth, mShipHeight)                            //and ghost is not out of bounds
       && !mGhost.isMouseOutOfBounds(mShipWidth, mShipHeight, mProgram->window()))  //and mouse is not out of bounds
    {
        mShip.addRoom(mSelectedRoom, mGhost.getRect());     //Add a room at location
    }

    if ((sf::Mouse::isButtonPressed(sf::Mouse::Right)                                //If right mouse button is pressed
       && !mGhost.isOutOfBounds(mShipWidth, mShipHeight)                            //and ghost is not out of bounds
       && !mGhost.isMouseOutOfBounds(mShipWidth, mShipHeight, mProgram->window() ) ) ) { //and mouse is not out of bounds

            mShip.removeRoom(mGhost.getRect());                                         //Remove a room at location
        }

    if (mSwToWallMdeBtn.clicked(mProgram->window())) {
        switchToWallMode();
    }
    if (mSwToUnitMdeBtn.clicked(mProgram->window())) {
       switchToUnitMode();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
         while(sf::Keyboard::isKeyPressed(sf::Keyboard::R));
         mShip.rotateRoom(mGhost.getRect());
    }
}

void EditState::roomUpdate()
{
    if (selectionHasChanged)  {
        selectionHasChanged = mCurrentlySelectedUI.updateSelected(  mSelectedRoom,
                                                                    mShip.getRoomTexture(mSelectedRoom));   //Update the "currently selected" scroll
        mGhost.updateRectSize(mShip.getRoomSize(mSelectedRoom));                                            //Update ghosts size
    }

    if (mShip.roomPresent(mGhost.getRect() ) ) {                        //If a room is present at the location of the ghost
            mGhost.updateRectColour(ghCol::RED);         //Change it's colour to red
        }
    else {                                                              //If no room is present
        mGhost.updateRectColour(ghCol::GREEN);             //Change is to green
    }
}

























