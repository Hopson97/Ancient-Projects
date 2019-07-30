#include "room.h"
#include <iostream>

#include "../../Engine/constants.h"

Room::Room(const    sf::Vector2f&  position,     const RoomType   roomType,
           const    sf::Texture&   texture,      const int        rotation,
           const    sf::Vector2f&  shipPosition                             )
:   Entity      ( texture  )
,   mPosition   ( position )
,   mRoomType   ( roomType )
,   mRotation   ( rotation )
{
    centerOrigin(  sf::Vector2f(
                                shipPosition.x  + ( mPosition.x  * ship::TILE_SIZE ) + (_mSprite().getLocalBounds().width / 2)  + 1,    //X-Position
                                shipPosition.y  + ( mPosition.y  * ship::TILE_SIZE ) + (_mSprite().getLocalBounds().height / 2) + 1     //Y-Position
                                ) );

    _mSprite().setRotation(mRotation);

}

/*****************************************************************************************************************************************************************
*   draw()  draws the room and its walls
*   param1  :   the window to draw the sprites to
***************************************************************************************************************************************************************/
void    Room::draw(sf::RenderWindow& window)
{
    window.draw(_mSprite());    //Draw the room
    for( auto& wall : mWalls )   //Draw the walls
    {
        wall.draw(window);
    }
}

void Room::logic(const float dt)
{
    for( auto& wall : mWalls )
    {
        wall.logic(dt);
    }
}

/*****************************************************************************************************************************************************************
*   addWall() simply adds a wall into this room's std::vector of walls
***************************************************************************************************************************************************************/
void Room::addWall(const Wall& wall)
{
    mWalls.emplace_back( std::move( wall ) );
}

std::vector<Wall>& Room::getWalls()
{
    return mWalls;
}

/*****************************************************************************************************************************************************************
*   setToShipPos()  sets the position of the sprite relative to the ships position
*   param1  :   The position of the ship
***************************************************************************************************************************************************************/
void Room::setToShipPos(const sf::Vector2f& shipPosition)
{
        centerOrigin(  sf::Vector2f(
                                shipPosition.x  + ( mPosition.x  * ship::TILE_SIZE ) + (_mSprite().getLocalBounds().width / 2)  + 1,    //X-Position
                                shipPosition.y  + ( mPosition.y  * ship::TILE_SIZE ) + (_mSprite().getLocalBounds().height / 2) + 1     //Y-Position
                                ) );
        for (auto& wall : mWalls) {
            wall.setToShipPos( shipPosition);
        }
}
