#include "edit_state.h"

void EditState::switchToUnitMode()
{
    mMode = MODE_UNIT;
    mGhost.updateRectSize(sf::Vector2f(40, 40) );
    mGhost.setMode(unit);
    mCurrentlySelectedUI.updateSelected(mSelectedUnit, mShip.getUnitTexture(mSelectedUnit));
}

void EditState::unitInput()
{
    if (mSwToWallMdeBtn.clicked(mProgram->window())) {
        switchToWallMode();
    }
    if (mSwToRoomMdeBtn.clicked(mProgram->window() ) ) {
        switchToRoomMode();
    }

    if ( mShip.roomPresent(mGhost.getRect() ) ) {
        mGhost.updateRectColour(ghCol::GREEN);
        if ( mShip.unitPresent(mGhost.getRect() ) ) {
            mGhost.updateRectColour(ghCol::RED);
        }

        if ( sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            mShip.addUnit(mShip.getUnitTexture(mSelectedUnit), mSelectedUnit, mGhost.getRect());
        }
        else if ( sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
            mShip.removeUnit(mGhost.getRect());
        }
    }
    else {
         mGhost.updateRectColour(ghCol::RED);
    }

}

void EditState::unitUpdate()
{
    if (selectionHasChanged ) {
        selectionHasChanged = mCurrentlySelectedUI.updateSelected(mSelectedUnit,
                                                                  mShip.getUnitTexture(mSelectedUnit));
    }
}


















