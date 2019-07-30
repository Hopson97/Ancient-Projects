#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <SFML/Graphics.hpp>
#include <string>

enum TextureName
{
        RES_TXR_SHIP
    ,   RES_TXR_CURRENTLY_SELECTED
    ,   RES_TXR_ROOM_MENU
    ,   RES_TXR_BTN_SWITCH_TO_WALL_MODE
    ,   RES_TXR_BTN_SWITCH_TO_ROOM_MODE
    ,   RES_TXR_BTN_SWITCH_TO_UNIT_MODE

    ,   RES_TXR_ROOMS_EMPTY_SM
    ,   RES_TXR_ROOMS_EMPTY_LG
    ,   RES_TXR_ROOMS_EMPTY_SM_WD
    ,   RES_TXR_ROOMS_EMPTY_SM_TL
    ,   RES_TXR_ROOMS_EMPTY_HG
    ,   RES_TXR_ROOMS_CANNON

    ,   RES_TXR_UNITS_RECRUIT
};

class TextureManager
{
    public:
                        TextureManager  (const std::string& filePathShip);
        sf::Texture&    getTexture      (TextureName textureName);

    private:
        void            loadTextures    ();

        bool            addTexture      (const std::string& filePath, TextureName textureNode);



        std::map<TextureName, sf::Texture> mTextures;
};

#endif // TEXTUREMANAGER_H
