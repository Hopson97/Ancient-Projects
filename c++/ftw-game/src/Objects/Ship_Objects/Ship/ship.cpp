#include "ship.h"

#include <iostream>

#include "../../../Engine/constants.h"

Ship::Ship(TextureManager& textures)
{
    registerRoomsToTextures( textures );
    registerUntisToTextures( textures );
}

/*****************************************************************************************************************************************************************
*   registerRoomsToTextures()   sets up the std::map<room type, texture>
*   param1  :   the texture manager for the textures to point to
***************************************************************************************************************************************************************/
void Ship::registerRoomsToTextures(TextureManager& textures)
{
    roomTextures[ RT_EMPTY_SMALL ]          = &textures.getTexture( RES_TXR_SP_RM_EMPTY_SMALL        );
    roomTextures[ RT_EMPTY_LARGE ]          = &textures.getTexture( RES_TXR_SP_RM_EMPTY_LARGE        );
    roomTextures[ RT_EMPTY_SMALL_WIDE ]     = &textures.getTexture( RES_TXR_SP_RM_EMPTY_SMALL_WIDE   );
    roomTextures[ RT_EMPTY_SMALL_TALL ]     = &textures.getTexture( RES_TXR_SP_RM_EMPTY_SMALL_TALL   );
    roomTextures[ RT_EMPTY_HUGE ]           = &textures.getTexture( RES_TXR_SP_RM_EMPTY_HUGE         );
    roomTextures[ RT_CANNON ]               = &textures.getTexture( RES_TXR_SP_RM_CANNON             );

}

void Ship::registerUntisToTextures(TextureManager& textures)
{
    unitTextures[ UT_RECRUIT ]      = &textures.getTexture( RES_TXR_SP_UT_RECRUIT);
}

/*****************************************************************************************************************************************************************
*   draw()      draws the ships background texture and the rooms within
*   param1  :   window to draw the sprites to
***************************************************************************************************************************************************************/
void Ship::draw(sf::RenderWindow& window)
{
    window.draw(mShipSprite);
    for (auto& room : mRooms)   //Draw the rooms
    {
        room.draw(window);
    }
    for (auto& unit : mUnits)   //Draw the units
    {
        unit.draw(window);
    }
}

/*****************************************************************************************************************************************************************
*   update()    update the ship eg the doors open/ closed state
*   param 1 :   the game's delta time
***************************************************************************************************************************************************************/
void Ship::update(const float dt)
{
    for(auto& room : mRooms)
    {
        room.logic(dt);
    }
    for(auto& unit : mUnits)
    {
        unit.update(dt);
    }
}
