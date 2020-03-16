#include "texturemanager.h"

/*
=================================================================================================================================================================
Texture manager is a singleton class which holds most of the texture to be used
=================================================================================================================================================================
*/
TextureManager::TextureManager(const std::string& filePathShip)
{
    addTexture(filePathShip, RES_TXR_SHIP);

    loadTextures();
}

/*
=================================================================================================================================================================
loadTextures() loads the textures
=================================================================================================================================================================
*/
void TextureManager::loadTextures()
{
    addTexture("Resources/Textures/CurrSel.png",    RES_TXR_CURRENTLY_SELECTED);   //Add "currently selected scroll" texture

    addTexture("Resources/Textures/roommenu.png",   RES_TXR_ROOM_MENU);            //Add "room menu scroll" texture

    addTexture("Resources/Textures/STRM.png",       RES_TXR_BTN_SWITCH_TO_ROOM_MODE);         //Add button for switching to room mode

    addTexture("Resources/Textures/STWM.png",       RES_TXR_BTN_SWITCH_TO_WALL_MODE);       //Add button for switch to wall mode

    addTexture("Resources/Textures/STUM.png",       RES_TXR_BTN_SWITCH_TO_UNIT_MODE);

    addTexture("../ftw-game/Resources/Textures/Rooms/Empty(Small).png",     RES_TXR_ROOMS_EMPTY_SM);      //Add room texture for small room empty
    addTexture("../ftw-game/Resources/Textures/Rooms/Empty(Large).png",     RES_TXR_ROOMS_EMPTY_LG);      //Add room texture for large room empty
    addTexture("../ftw-game/Resources/Textures/Rooms/Empty(SmallWide).png", RES_TXR_ROOMS_EMPTY_SM_WD);
    addTexture("../ftw-game/Resources/Textures/Rooms/Empty(SmallTall).png", RES_TXR_ROOMS_EMPTY_SM_TL);
    addTexture("../ftw-game/Resources/Textures/Rooms/Empty(Huge).png",      RES_TXR_ROOMS_EMPTY_HG);
    addTexture("../ftw-game/Resources/Textures/Rooms/Cannon(Up).png",       RES_TXR_ROOMS_CANNON);

    addTexture("../ftw-game/Resources/Textures/Units/Recruit.png",          RES_TXR_UNITS_RECRUIT);

}

bool TextureManager::addTexture(const std::string& filePath, TextureName textureName)
{
    sf::Texture t;
    if(!t.loadFromFile(filePath)) return false;     //Load texture if it exists
    t.setSmooth(true);
    mTextures[textureName] = t;

    return true;
}

/*
=================================================================================================================================================================
getTexture() returns a texture to a caller
=================================================================================================================================================================
*/
sf::Texture& TextureManager::getTexture(TextureName textureName)
{
    return mTextures[textureName];
}
