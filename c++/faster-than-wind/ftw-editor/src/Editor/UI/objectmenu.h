#ifndef OBJECTMENU_H
#define OBJECTMENU_H


#include "../ShipObjects/room.h"
#include "../ShipObjects/unit.h"

#include "../../texturemanager.h"

#include "../object.h"

#include "../UI/button.h"

enum Mode
{
    MODE_WALL,
    MODE_ROOM,
    MODE_UNIT
};


class ObjectMenu : public Object
{
    public:
        ObjectMenu(const sf::Texture& bottomMenuTexture, TextureManager& textures);

        bool checkButtonInput(RoomType& rS, UnitType& uT, sf::RenderWindow& window, const Mode inputMode);  //Check to see if any of the buttons are pressed

    private:
        int x, y;
        Button emptyRoomSmButton;
        Button emptyRoomLgButton;
        Button emptyRoomSmWdButton;
        Button emptyRoomSmTlButton;
        Button emptyRoomHugeButton;
        Button cannonRoomUpButton;

        Button recruitButton;
};

#endif // OBJECTMENU_H
