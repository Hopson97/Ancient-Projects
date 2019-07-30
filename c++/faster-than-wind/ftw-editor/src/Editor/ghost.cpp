#include "ghost.h"

#include <iostream>
/*
=================================================================================================================================================================
Ghost is a rectangle that follows the mouse around, showing how big the item being placed is.
aka the "ghost" that shows where rooms will be placed
=================================================================================================================================================================
*/
Ghost::Ghost()
: mMode (room)
{
    mGhostRect.setFillColor(ghCol::RED);    //Set the ghost to be slightly transparent
    mGhostRect.setSize(sf::Vector2f(40, 40));
}

/*
=================================================================================================================================================================
logic() performs logical stuff on the ghost
=================================================================================================================================================================
*/
void Ghost::logic(const sf::Vector2i mousePos, const int maxWidth, const int maxHeight, const sf::RenderWindow& window)
{
    xPos = mGhostRect.getPosition().x / 40;    //Set a variable for y position that is relative to the "tile map" (1px = 40px)
    yPos = mGhostRect.getPosition().y / 40;    //Set a variable that x position  is relative to the "tile map" (1px = 40px)

    goToMouse(mousePos, maxWidth, maxHeight, window);   //Sets the sprites position to the mouse position (if possible)
    isOutOfBounds(maxWidth, maxHeight);    //Checks if the ghost somehow got out of bounds :/
    snapToMap();                                //Snaps the ghost to the tile grid

}

/*
=================================================================================================================================================================
goToMouse() moves the ghost to the mouse (if possible)
=================================================================================================================================================================
*/
void Ghost::goToMouse(const sf::Vector2i mousePos, const int maxWidth, const int maxHeight, const sf::RenderWindow& window)
{
    sf::FloatRect r = mGhostRect.getLocalBounds();
    int w = r.width / 40 - 1;
    int h = r.height / 40 - 1;

    if ((xPos + w < maxWidth ) && (!isMouseOutOfBounds(maxWidth, maxHeight, window)))  //If the xPos (defined in logic()) is less than the relative width of the ship:
    {
        mGhostRect.setPosition(mousePos.x, mGhostRect.getPosition().y);    //Set the sprites position.x to the mouse's.x.
    }
    else if (mousePos.x / 40 + w < maxWidth)                              //but, if it is not then check if the mouse is, and if it is then:
    {
        mGhostRect.move(-0.1, 0);                                        //Nudge the sprite a bit, otherwise it gets stuck.
    }

    if (yPos + h < maxHeight + 1 && (!isMouseOutOfBounds(maxWidth, maxHeight, window))) //If the yPos (defined in logic()) is less than the relative height of the ship:
    {
        mGhostRect.setPosition(mGhostRect.getPosition().x, mousePos.y);   //Set the sprites position.y to the mouse's.y.
    }
    else if (mousePos.y / 40 + h < maxHeight + 1)                            //but, if it is not then check if the mouse is, and if it is then:
    {
        mGhostRect.move(0, -0.1);                                        //Nudge the sprite a bit, otherwise it gets stuck.
    }

}

void Ghost::setMode(mode m)
{
    mMode = m;
    if (mMode == room) {
        mGhostRect.setRotation(0);
    }
    else if (mMode == unit) {
        mGhostRect.setSize(sf::Vector2f(40, 40) );
    }
}

/*
=================================================================================================================================================================
isOutOfBounds() returns true if the ghost rectangle is off the edge of the ship's bounds
=================================================================================================================================================================
*/
bool Ghost::isOutOfBounds(int maxWidth, int maxHeight)
{

    sf::FloatRect r = mGhostRect.getLocalBounds();
    int w = r.width / 40 - 1;
    int h = r.height / 40 - 1;

    if (xPos + w > maxWidth)                //If the xPos (defined in logic()) is greater than the width of the ship aka out of bounds, then:
    {
        mGhostRect.setPosition(0, 0);       //Set the ghosts position to the corner
        return true;
    }
    if (yPos + h > maxHeight + 1)           //If the yPos (defined in logic()) is greater than the height of the ship aka out of bounds, then:
    {
        mGhostRect.setPosition(0, 0);       //Set the ghosts position to the corner
        return true;
    }
    return false;
}

/*
=================================================================================================================================================================
isMouseOutOfBounds() returns true if the mouse is out of bounds
=================================================================================================================================================================
*/
bool Ghost::isMouseOutOfBounds(const int maxWidth, const int maxHeight, const sf::RenderWindow& window)
{
    sf::Vector2i vec = sf::Mouse::getPosition(window);
    if (vec.x / 40 > maxWidth)                  //If the  (defined in logic()) is greater than the width of the ship aka out of bounds, then:
    {
        return true;
    }
    if (vec.y / 40 > maxHeight + 1)             //If the (defined in logic()) is greater than the height of the ship aka out of bounds, then:
    {
        return true;
    }
    return false;
}

void Ghost::rotate()
{
    if (int(mGhostRect.getRotation()) == 270) {
        mGhostRect.setRotation(0);
    }
    else if (int(mGhostRect.getRotation()) == 0) {
        mGhostRect.setRotation(270);
    }
}

/*
=================================================================================================================================================================
updateTexture() updates the texture of the ghost
=================================================================================================================================================================
*/
void Ghost::updateRectColour(sf::Color c)
{
    mGhostRect.setFillColor(c);
}

/*
=================================================================================================================================================================
updateRectSize() updates the size of the ghosts rectangle
=================================================================================================================================================================
*/
void Ghost::updateRectSize(sf::Vector2f s)
{
    mGhostRect.setSize(s);
}

/*
=================================================================================================================================================================
getPos() returns position of ghost
=================================================================================================================================================================
*/
sf::Vector2f Ghost::getPos() const
{
    return mGhostRect.getPosition();
}

/*
=================================================================================================================================================================
getSize() returns size of the ghost rectangle
=================================================================================================================================================================
*/
sf::Vector2f Ghost::getSize() const
{
    return mGhostRect.getSize();
}

/*
=================================================================================================================================================================
getRect() returns the rectangle itself
=================================================================================================================================================================
*/
sf::RectangleShape Ghost::getRect() const
{
    return mGhostRect;
}

/*
=================================================================================================================================================================
draw() draws the ghost rectangle
=================================================================================================================================================================
*/
void Ghost::draw(sf::RenderWindow& window)
{
    window.draw(mGhostRect);
}

void Ghost::snapToMap()
{
    sf::Vector2i pos = sf::Vector2i(mGhostRect.getPosition());     //Create a variable the same as sprites position, except cast as an integer

    if ((pos.x % 40 != 0)){                 //If pos.x divided by 40 does not have a remainder of 0:
        while (pos.x % 40 != 0){            //While pos.x divided by 40 does not have a remainder of 0:
            pos.x--;                        //Change the X position by 1 (until the above is true).
        }
        checkXOffset(pos);
    }

    if(pos.y % 40 != 0){                    //If pos.y divided by 40 does not have a remainder of 0:
        while (pos.y % 40 != 0){            //While pos.y divided by 40 does not have a remainder of 0:
            pos.y--;                        //Change the  Y position by 1 (until the above is true).
        }
        checkYOffset(pos);
    }
    mGhostRect.setPosition(sf::Vector2f(pos)); //Set the sprites position to the variable just manipulated
}

void Ghost::checkXOffset(sf::Vector2i& pos)
{
    if (mMode == wall) {
        if (mGhostRect.getRotation() == 0) {
            pos.x--;
        }
        else if (mGhostRect.getRotation() == 270) {
            pos.x++;
        }
    }
}

void Ghost::checkYOffset(sf::Vector2i& pos)
{
    if (mMode == wall) {
        pos.y++;
    }
}





















