#include "ship.h"

/*****************************************************************************************************************************************************************
*   getTexture  ()  returns the texture of the ship
***************************************************************************************************************************************************************/
const sf::Texture& Ship::getTexture() const
{
    return mCurrShipTexture;
}

/*****************************************************************************************************************************************************************
*   getTexture()    returns a texture for the rooms
*   param1  :   the RoomType texture that it will be returning
***************************************************************************************************************************************************************/
const sf::Texture* Ship::getTexture(const RoomType roomType)
{
    return roomTextures[ roomType ];
}

/*****************************************************************************************************************************************************************
*   getTexture()    returns a texture for the unit
*   param1  :   the UniType's texture that it will be returning
***************************************************************************************************************************************************************/
const sf::Texture* Ship::getTexture(const UnitType unitType)
{
    return unitTextures[ unitType ];
}

/*****************************************************************************************************************************************************************
*   setRooms()  set the wall std::vector of the room aka "build the ships rooms"
*   param1  :   the vector that the ship will be build from
**************************************************************************************************************************************************************/
void Ship::setRooms(const std::vector<Room> rooms)
{
    mRooms = rooms;
}

/*****************************************************************************************************************************************************************
*   setRooms()  set the wall std::vector of the room aka "build the ships rooms"
*   param1  :   the vector that contains info about units
***************************************************************************************************************************************************************/
void Ship::setUnits(const std::vector<Unit> units)
{
    mUnits = units;
}

std::vector<Unit>& Ship::getUnits()
{
    return mUnits;
}

/*****************************************************************************************************************************************************************
*   setTexture()    sets the background texture of the ship
*   param1  :   the texture
***************************************************************************************************************************************************************/
void Ship::setTexture(const sf::Texture& t)
{
    sf::Sprite s;               //Need to create a temporary sprite so that ship can change size, or else it just sticks to it's smallest size for some reason
    s.setPosition(mPosition);   //Set the temporary sprite's position to that of the ship
    mShipSprite = s;            //Set the ships sprite to be that of the temporary sprite.
    mCurrShipTexture = t;
    mShipSprite.setTexture(mCurrShipTexture);
}

/*****************************************************************************************************************************************************************
*   setPosition()
*   param1  :   The new position for the sprite
***************************************************************************************************************************************************************/
void Ship::setPosition (const sf::Vector2f pos, const bool moving)
{
    mShipSprite.setPosition(pos);
    mPosition = pos;

    if (moving) {
        for ( auto& room : mRooms ) {
            room.setToShipPos( mPosition );
        }
        for ( auto& unit : mUnits ) {
            unit.setToShipPos( mPosition );
        }
    }
}

/*****************************************************************************************************************************************************************
*   getPosition() returns the position of the ship
***************************************************************************************************************************************************************/
const sf::Vector2f Ship::getPosition() const
{
    return mPosition;
}

void Ship::translate(const sf::Vector2f& offset, const float dt)
{
    this->setPosition( sf::Vector2f( this->getPosition().x + offset.x * dt,
                                     this->getPosition().y + offset.y * dt),
                        true);
}

void Ship::setName(const std::string& name)
{
    shipName = name;
}

const std::string& Ship::getName() const
{
    return shipName;
}

const int Ship::getWidth() const
{
    return mShipSprite.getLocalBounds().width;
}
