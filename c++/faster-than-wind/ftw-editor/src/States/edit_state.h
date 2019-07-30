#ifndef EDITSTATE_H
#define EDITSTATE_H

#include <memory>

#include "../Editor/ShipObjects/Ship/ship.h"

#include "../texturemanager.h"
#include "../program.h"
#include "../Editor/dotmap.h"
#include "../Editor/ghost.h"
#include "../Editor/UI/currentlyselected.h"
#include "../Editor/UI/objectmenu.h"
#include "../Editor/UI/button.h"

#include "state.h"

#include <fstream>

class EditState : public State
{
    public:
                EditState           (Program* p, const std::string& filePath, const std::string& shipName, const sf::Texture& mShipTexture, const std::string& infoFile);
                EditState           (Program* p, const std::string& filePath, const std::string& shipName, const sf::Texture& mShipTexture);

        void    input               () override;
        void    update              () override;
        void    draw                () override;

    private:
        void    switchToRoomMode    ();
        void    roomInput           ();
        void    roomUpdate          ();

        void    switchToWallMode    ();
        void    wallInput           ();
        void    wallUpdate          ();

        void    switchToUnitMode    ();
        void    unitInput           ();
        void    unitUpdate          ();

//Methods up the next "private:" are to do with file handling.
        void    save                ();

        void    load                (const std::string& filePath);

        void    loadRoom            (std::ifstream& shipFile, std::vector<Room>& rooms);

        Room    addRoom             (std::ifstream& shipFile);
        void    addWall             (std::vector<std::shared_ptr<Wall>>& walls, std::ifstream& shipFile);
        void    addUnit             (std::vector<std::shared_ptr<Unit>>& units, std::ifstream& shipFile);

        void    connectDoors        (std::vector<Room>& rooms);

    private:

        sf::Sprite          mShipSprite;

        DotMap              mDotMap;
        TextureManager      mTextures;
        Ghost               mGhost;

        int                 mShipHeight, mShipWidth;

        Ship                mShip;
        CurrentlySelected   mCurrentlySelectedUI;
        ObjectMenu          mObjectMenuUI;


        UnitType            mSelectedUnit;
        RoomType            mSelectedRoom;
        bool                selectionHasChanged;

        Mode mMode;

        Button              mSwToWallMdeBtn;
        Button              mSwToRoomMdeBtn;
        Button              mSwToUnitMdeBtn;

        std::string         mShipName;



};

#endif // EDITSTATE_H
