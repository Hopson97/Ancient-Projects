#ifndef SHIP_H
#define SHIP_H

#include <memory>
#include <vector>
#include <string>

#include "../../../texturemanager.h"
#include "../room.h"
#include "../unit.h"

class Ship
{


    public:
        Ship                                (TextureManager& textures, const int width, const int height, const std::string& path);

        void            addUnit             (const sf::Texture& texture, const UnitType _type, const sf::RectangleShape& rect);
        void            addUnitToRoom       (const sf::RectangleShape& rect, std::shared_ptr<Unit> _unit);
        void            removeUnit          (const sf::RectangleShape& rect);
        bool            unitPresent         (const sf::RectangleShape& rect);

        void            addRoom             (const RoomType rt, const sf::RectangleShape& rect);      //Adds a room
        void            removeRoom          (const sf::RectangleShape& rect);     //Remove a room
        bool            roomPresent         (const sf::RectangleShape& rect);     //Check to see if room is present inside of passed in rectangle shape

        void            draw                (sf::RenderWindow& window);           //Draw the room

        sf::Texture&    getRoomTexture      (const RoomType roomT);                     //Returns the texture of the room type passed in
        sf::Vector2f    getRoomSize         (const RoomType roomT);                     //Returns the size    of the room type passed in

        sf::Texture&    getUnitTexture      (const UnitType unitT);

        void            checkForWallorDoor  (const sf::RectangleShape& rect,
                                             const WallOrDoor checkingFor,
                                             const WallOrDoor changingTo);  //Checks to see if wall/door is present, changes the type to "changingTo" if true

        void            rotateRoom          (const sf::RectangleShape& rect);

        std::string&    getTxrFilePath      ();

        std::vector<Room>& getRoomMap       ();

        void            setRooms(const std::vector<Room>& rooms);

    private://Private methods
        void            setRoomDatabase     (TextureManager& textures);             //Sets up the class std::map s
        void            setUnitDatabase     (TextureManager& textures);

    private:



        std::vector<Room>                   mRoomMap;       //std::vector of rooms

        std::map<RoomType, sf::Texture*>    roomTextures;   //std::map of RoomType -> texture
        std::map<RoomType, sf::Vector2f>    roomSizes;      //std::map of RoomType -> size

        std::map<UnitType, sf::Texture*>    unitTextures;

        std::string mFilePath;
};

#endif // SHIP_H
