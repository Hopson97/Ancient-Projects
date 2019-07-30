#include "texture_m.h"

#include <iostream>

TextureManager::TextureManager()
:   texturePath ("Resources/Textures/")
{
}

/*****************************************************************************************************************************************************************
*   addWall()   return a specific texture
*   param1  :   The enum name of the texture
**************************************************************************************************************************************************************/
const sf::Texture& TextureManager::getTexture(const TextureName textureName)
{
    return mTextures[textureName];
}

/*****************************************************************************************************************************************************************
*   clearTextures() clears the std::map of textures
**************************************************************************************************************************************************************/
void TextureManager::clearTextures()
{
    mTextures.clear();
}

void TextureManager::loadTexturesAll()
{
    loadTexturesGbl();
    loadTexturesSS();
    loadTexturesMenu();
    loadTexturesNewGame();
    loadTexturesRooms();
    loadTexturesUnits();
}

void TextureManager::loadTexturesGbl()
{
    loadTexture(RES_TXR_GBL_LONG_SCROLL,    texturePath + "Menu Buttons/scroll.png");
    loadTexture(RES_TXR_GBL_SMALL_SCROLL,    texturePath + "Menu Buttons/smallscroll.png");
}

/*****************************************************************************************************************************************************************
*   loadTexturesSS()    loads the textures for the splash screen
***************************************************************************************************************************************************************/
void TextureManager::loadTexturesSS()
{
    loadTexture( RES_TXR_SPLASH_SCREEN_MH,          texturePath + "Splash Screen/MatthewHopson.png" );
}

/*****************************************************************************************************************************************************************
*   loadTexturesMenu()    loads the textures for the main menu
***************************************************************************************************************************************************************/
void TextureManager::loadTexturesMenu ()
{
    loadTexture( RES_TXR_MENU_BACKGROUND,           texturePath + "Backgrounds/TitleS.png"          );

    loadTexture( RES_TXR_LOGO_FTW,                  texturePath + "Logos/FTW.png"                   );
}

/*****************************************************************************************************************************************************************
*   loadTexturesRooms()    loads the textures for the rooms
***************************************************************************************************************************************************************/
void TextureManager::loadTexturesRooms()
{
    loadTexture( RES_TXR_SP_RM_EMPTY_SMALL      ,   texturePath + "Rooms/Empty(Small).png"          );
    loadTexture( RES_TXR_SP_RM_EMPTY_LARGE      ,   texturePath + "Rooms/Empty(Large).png"          );
    loadTexture( RES_TXR_SP_RM_EMPTY_SMALL_WIDE ,   texturePath + "Rooms/Empty(SmallWide).png"      );
    loadTexture( RES_TXR_SP_RM_EMPTY_SMALL_TALL ,   texturePath + "Rooms/Empty(SmallTall).png"      );
    loadTexture( RES_TXR_SP_RM_EMPTY_HUGE       ,   texturePath + "Rooms/Empty(Huge).png"           );
    loadTexture( RES_TXR_SP_RM_CANNON           ,   texturePath + "Rooms/Cannon(Up).png"            );

    loadTexture( RES_TXR_SP_WT_DOOR             ,   texturePath + "Walls/Door.png"                  );
    loadTexture( RES_TXR_SP_WT_WALL             ,   texturePath + "Walls/Wall.png"                  );
}

void TextureManager::loadTexturesUnits()
{
    loadTexture(RES_TXR_SP_UT_RECRUIT           ,   texturePath + "Units/Recruit.png"               );
}

/*****************************************************************************************************************************************************************
*   loadTexturesNewGame()    loads the textures for the "new game" menu aka ship yard
***************************************************************************************************************************************************************/
void TextureManager::loadTexturesNewGame()
{

    loadTexture( RES_TXR_NEWGAME_PREV_ARROW      ,   texturePath + "Menu Buttons/New Game/previous ship.png"    );
    loadTexture( RES_TXR_NEWGAME_NEXT_ARROW      ,   texturePath + "Menu Buttons/New Game/Next Ship.png"        );
    loadTexture( RES_TXR_NEWGAME_LIST_ICON       ,   texturePath + "Menu Buttons/New Game/Ship List Text.png"   );
    loadTexture( RES_TXR_NEWGAME_STONES          ,   texturePath + "Backgrounds/Ship Selector Stones.png"   );
}

/*****************************************************************************************************************************************************************
*   loadTexture() loads a texture, and adds it to the std::map of textures
***************************************************************************************************************************************************************/
void TextureManager::loadTexture ( const TextureName& name, const std::string& filePath )
{
    if(! mTextures[name].loadFromFile(filePath) ) {
        return;
    }
    mTextures[name].setSmooth(true);
}
