#include "wall.h"
#include <iostream>

Wall::Wall(TextureManager& manager, const sf::Vector2f position, const int rotation,
           const WallType type, const int id, const int otherId, const sf::Vector2f& shipPosition )
:   mWallType       (type)
,   otherDoor       (nullptr)
,   mId             (id)
,   mOtherDoorId    (otherId)
,   WALL_WIDTH      (1)
,   WALL_HEIGHT     (40)
,   xPos            ( position.x)
,   yPos            ( position.y)
{
    _mSprite().setRotation( rotation );
    setToShipPos(shipPosition);


    if(mWallType == WT_DOOR) {// can you make a function in entity class that let's you set the texture rect given the 4 int values?
        setUpAnimation();
    }

    setTexture(manager);
}

void Wall::logic(const float dt)
{
    if(mWallType == WT_DOOR) {
        _mSprite().setTextureRect(doorOpen.currentFrame(dt));
    }
}

/*****************************************************************************************************************************************************************
*   setUpAnimation() adds all needed frames into the "open/ close" animations for the wall
***************************************************************************************************************************************************************/
void    Wall::setUpAnimation()
{
    for(int i = 0; i < 16; i++)
    {
        doorOpen.addFrame( Frame {sf::IntRect(i, 0, WALL_WIDTH, WALL_HEIGHT), 0.02f } );
    }
}

/*****************************************************************************************************************************************************************
*   setToShipPos()  sets the position of the sprite relative to the ships position
*   param1  :   The position of the ship
**************************************************************************************************************************************************************/
void Wall::setToShipPos(const sf::Vector2f& shipPosition)
{

    _mSprite().setPosition(  sf::Vector2f(  xPos + shipPosition.x,
                                            yPos + shipPosition.y) );
}

/*****************************************************************************************************************************************************************
*   setTexture()    sets the walls texture to one of texture pointers depending on the WallType of said wall (Wall or Door)
*   param1  :   the texture manager
***************************************************************************************************************************************************************/
void Wall::setTexture(TextureManager& manager)
{
    if ( mWallType == WT_DOOR ) {
       _mSprite().setTexture( manager.getTexture ( RES_TXR_SP_WT_DOOR ) );
    }
    else if( mWallType == WT_WALL ) {
        _mSprite().setTexture( manager.getTexture ( RES_TXR_SP_WT_WALL ) );
    }
}

/*****************************************************************************************************************************************************************
*   setOtherWall() sets a pointer to the relative wall, so it can "talk" to it aka open/ close it
*   param1  :   the wall to set the pointer to
***************************************************************************************************************************************************************/
void Wall::setOtherDoor(Wall& _wall)
{
    if ( _wall.getType() == WT_WALL  ) return;
    if ( _wall.getId() != mOtherDoorId ) return;

    otherDoor = &_wall;
}

const WallType Wall::getType() const
{
    return mWallType;
}

const int Wall::getId() const
{
    return mId;
}

const int Wall::getOtherId() const
{
    return mOtherDoorId;
}
