#include "edit_state.h"

void EditState::switchToWallMode()
{
    mMode = MODE_WALL;
    mGhost.updateRectSize(sf::Vector2f(2,38));
    mGhost.setMode(wall);
    std::cout << "Changing to wall mode. \n";
}

void EditState::wallInput()
{
    if (mSwToRoomMdeBtn.clicked(mProgram->window() ) ) {
        switchToRoomMode();
    }
    if (mSwToUnitMdeBtn.clicked(mProgram->window())) {
       switchToUnitMode();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
        while(sf::Keyboard::isKeyPressed(sf::Keyboard::R));
        mGhost.rotate();

    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        mShip.checkForWallorDoor(mGhost.getRect(), WT_WALL, WT_DOOR);
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
        mShip.checkForWallorDoor(mGhost.getRect(), WT_DOOR, WT_WALL);
    }

}

void EditState::wallUpdate()
{

}
