#include "room.h"

/*
=================================================================================================================================================================
Rooms make up the area of the ship that the crew can move around in
=================================================================================================================================================================
*/
Room::Room(const sf::Texture& t, const RoomType newRt,     const int xPos,
           const int yPos,       const sf::Vector2f& size, const int rotation)
:   Object      (t)
,   xPos        (xPos)
,   yPos        (yPos)
,   mWidth      (size.x)
,   mHeight     (size.y)
,   mRoomType   (newRt)
{
    int w = mWidth  / 40;
    int h = mHeight / 40;
    for (int i = 0; i != w; i++){
        mWalls.emplace_back(std::make_shared<Wall>(dirHorizontal, (xPos + i) * 40 , yPos * 40 + 1));          //Create walls for top of room
        mWalls.emplace_back(std::make_shared<Wall>(dirHorizontal, (xPos + i) * 40 , (yPos + h) * 40));      //Create walls for bottom of room
    }
    for (int i = 0; i != h; i++){
        mWalls.emplace_back(std::make_shared<Wall>(dirVertical, xPos * 40          , (yPos + i) * 40 - 1));  //Create walls for left of room
        mWalls.emplace_back(std::make_shared<Wall>(dirVertical, (xPos + w) * 40 - 1  , (yPos + i) * 40));        //Create walls for right of room
    }

    setUp(rotation);
}

Room::Room(   const sf::Texture& t,  const RoomType newRt,        const int xPos,
              const int yPos,        const sf::Vector2f& size,    const int rotation, bool loaded)
:   Object      (t)
,   xPos        (xPos)
,   yPos        (yPos)
,   mWidth      (size.x)
,   mHeight     (size.y)
,   mRoomType   (newRt)
{
    setUp(rotation);
}
void Room::setUp(const int rotation)
{
    for(int i = rotation; i != 0; i -= 90)
        rotate();

    mSprite.setPosition(xPos * 40 + 1, yPos * 40 + 1);

    mSprite.setOrigin(mWidth / 2, mHeight / 2);
    mSprite.move(mWidth / 2, mHeight / 2);
}


void Room::draw(sf::RenderWindow& window)
{

    window.draw(mSprite);
    for (auto& wall : mWalls) {
        wall->draw(window);
    }

    for (auto& unit : mUnits) {
        unit->draw(window);
    }
}

void Room::addUnit(std::shared_ptr<Unit> _unit)
{
    mUnits.emplace_back(_unit);
}

void Room::rotate()
{

    if(!isRotatable()) return;

    mSprite.rotate(90);

    if ((int)mSprite.getRotation() == 90) {         //Disgusting code to rotate room to actual position
        mSprite.move(-2,0);
    }
    else if ((int)mSprite.getRotation() == 180) {
        mSprite.move(0, -2);
    }
    else if ((int)mSprite.getRotation() == 270) {
         mSprite.move(2,0);
    }
    else if ((int)mSprite.getRotation() == 0) {
        mSprite.move(0, 2);
    }

}

bool Room::isRotatable() const
{
    return (mWidth == mHeight) ? true : false;  //Return true if the width = height
}

std::vector<std::shared_ptr<Wall>>& Room::getWalls()
{
    return mWalls;
}

std::vector<std::shared_ptr<Unit>>& Room::getUnits ()
{
    return mUnits;
}

void Room::setWalls(std::vector<std::shared_ptr<Wall>>& walls)
{
    mWalls = walls;
}

void Room::setUnits(std::vector<std::shared_ptr<Unit>>& units)
{
    mUnits = units;
    std::cout << "untis set " << mUnits.size() << std::endl;
}

RoomType Room::getType() const
{
    return mRoomType;
}

sf::Vector2f Room::pos() const
{
    return sf::Vector2f(xPos, yPos);
}

sf::Vector2f Room::size() const
{
    return sf::Vector2f(mWidth, mHeight);
}

