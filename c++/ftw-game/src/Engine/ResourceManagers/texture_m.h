#ifndef Texture_H
#define Texture_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <memory>
#include <string>
#include <map>



enum TextureName
{
        RES_TXR_LOGO_FTW                    //Texture, logo

    ,   RES_TXR_SPLASH_SCREEN_MH            //Texture, for splash screen, of type: "matthew hopson"

    ,   RES_TXR_GBL_LONG_SCROLL
    ,   RES_TXR_GBL_SMALL_SCROLL

    ,   RES_TXR_MENU_BACKGROUND             //Texture, for menu screen, of type: background

    ,   RES_TXR_NEWGAME_PREV_ARROW
    ,   RES_TXR_NEWGAME_NEXT_ARROW
    ,   RES_TXR_NEWGAME_LIST_ICON
    ,   RES_TXR_NEWGAME_STONES

    ,   RES_TXR_SP_RM_EMPTY_SMALL           //Texture, for ship, of room type: empty small
    ,   RES_TXR_SP_RM_EMPTY_LARGE           //Texture, for ship, of room type: empty large
    ,   RES_TXR_SP_RM_EMPTY_SMALL_WIDE      //Texture, for ship, of room type: empty wide
    ,   RES_TXR_SP_RM_EMPTY_SMALL_TALL      //Texture, for ship, of room type: empty tall
    ,   RES_TXR_SP_RM_EMPTY_HUGE            //Texture, for ship, of room type: empty huge
    ,   RES_TXR_SP_RM_CANNON                //Texture, for ship, of room type: cannon

    ,   RES_TXR_SP_WT_WALL                  //Texture, for ship, of wall type: wall
    ,   RES_TXR_SP_WT_DOOR                  //Texture, for ship, of wall type: door

    ,   RES_TXR_SP_UT_RECRUIT               //Texture, for the ship, of a unit of type: Recruit

};

class TextureManager
{
    public:
                                TextureManager      ();

        void                    clearTextures       ();
        void                    loadTexturesAll     ();
        void                    loadTexturesGbl     ();
        void                    loadTexturesSS      (); //Splash screen textures
        void                    loadTexturesMenu    ();
        void                    loadTexturesNewGame ();

        void                    loadTexturesRooms   ();
        void                    loadTexturesUnits   ();

        const sf::Texture&            getTexture          (const TextureName textureName);

    private:
        void                    loadTexture         (const TextureName& name, const std::string& filePath);

        std::map<TextureName, sf::Texture> mTextures;
        std::string texturePath;
};



#endif // Texture_H
