#include "wall.h"

#include <iostream>

int Wall::idCount = 0;

Wall::Wall(const Direction d, const int xPos, const int yPos)
    : otherId(0)
    , mType(WT_WALL)

{
    otherWall = nullptr;
    mWallRectangle.setSize        (wallConst::SIZE);      //Set the wall's rectangle to be exactly 1x40pixel aka 1 tile length
    mWallRectangle.setFillColor   (wallConst::WALL); //Set the wall's rectangle's colour
    mWallRectangle.setPosition    (xPos, yPos);               //Set the wall's rectangle position

    if (d == dirHorizontal) {                       //If it needs to be horizontal
        mWallRectangle.setRotation(-90);                      //flip the wall.
    }
    else if (d == dirVertical){                     //If it needs to be vertical
        mWallRectangle.setRotation(0);                        //Keep it stationary
    }
    genId();
}

//constructor for loading ships
Wall::Wall(const Direction d,    const int xPos, const int yPos,
           const WallOrDoor wod, const int myId, const int otherId)
    : mId        (myId)
    , otherId   (otherId)
    , mType     (wod)
{
    mWallRectangle.setSize        (wallConst::SIZE);      //Set the wall's rectangle to be exactly 1x40pixel aka 1 tile length
    mWallRectangle.setFillColor   (wallConst::WALL); //Set the wall's rectangle's colour
    mWallRectangle.setPosition    (xPos, yPos);               //Set the wall's rectangle position

    if (d == dirHorizontal) {                       //If it needs to be horizontal
        mWallRectangle.setRotation(-90);                      //flip the wall.
    }
    else if (d == dirVertical){                     //If it needs to be vertical
        mWallRectangle.setRotation(0);                        //Keep it stationary
    }
    checkType();
    idCount++;
}

void Wall::draw(sf::RenderWindow& window)
{
    window.draw(mWallRectangle);
}

void Wall::setType(WallOrDoor type)
{
    mType = type;
    checkType();
}



void Wall::setOtherWall(std::shared_ptr<Wall> other)
{
    otherWall = other;
}



Wall& Wall::getOtherWall()
{
    otherId = otherWall->getId();
    return *otherWall;
}

void Wall::checkType()
{
    if (mType == WT_WALL) {
        mWallRectangle.setFillColor   (wallConst::WALL);
    }
    else if (mType == WT_DOOR) {
        mWallRectangle.setFillColor     (wallConst::DOOR);
    }
}

WallOrDoor Wall::getType() const
{
    return mType;
}

sf::RectangleShape Wall::getRect() const
{
    return mWallRectangle;
}

sf::Vector2f Wall::getPos() const
{
    return mWallRectangle.getPosition();
}

int Wall::getRot() const
{
    return mWallRectangle.getRotation();
}

void Wall::genId()
{
    mId = ++idCount;
}

int Wall::getId() const
{
    return mId;
}

int Wall::getOtherId() const
{
    return otherId;
}

void Wall::setOtherId(int _otherId)
{
    otherId = _otherId;
}
