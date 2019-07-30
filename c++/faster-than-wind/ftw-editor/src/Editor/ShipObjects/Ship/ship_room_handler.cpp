#include "ship.h"

/*
=================================================================================================================================================================
setRoomDatabase() registers room sizes and textures into an std::map
=================================================================================================================================================================
*/
void Ship::setRoomDatabase(TextureManager& textures)
{
    roomTextures[RT_EMPTY_SMALL]        = &textures.getTexture(RES_TXR_ROOMS_EMPTY_SM);
    roomSizes   [RT_EMPTY_SMALL]        = sf::Vector2f(40, 40);

    roomTextures[RT_EMPTY_LARGE]        = &textures.getTexture(RES_TXR_ROOMS_EMPTY_LG);
    roomSizes   [RT_EMPTY_LARGE]        = sf::Vector2f(80, 80);

    roomTextures[RT_EMPTY_SMALL_WIDE]   = &textures.getTexture(RES_TXR_ROOMS_EMPTY_SM_WD);
    roomSizes   [RT_EMPTY_SMALL_WIDE]   = sf::Vector2f(80, 40);

    roomTextures[RT_EMPTY_SMALL_TALL]   = &textures.getTexture(RES_TXR_ROOMS_EMPTY_SM_TL);
    roomSizes   [RT_EMPTY_SMALL_TALL]   = sf::Vector2f(40, 80);

    roomTextures[RT_EMPTY_HUGE]         = &textures.getTexture(RES_TXR_ROOMS_EMPTY_HG);
    roomSizes   [RT_EMPTY_HUGE]         = sf::Vector2f(160, 160);

    roomTextures[RT_CANNON]             = &textures.getTexture(RES_TXR_ROOMS_CANNON);
    roomSizes   [RT_CANNON]             = sf::Vector2f(80, 80);
}

/*
=================================================================================================================================================================
addRoom() takes in a room type and a set of x and y co-ordinates and then places a room there (if possible)
=================================================================================================================================================================
*/
void Ship::addRoom(const RoomType rt, const sf::RectangleShape& rect)
{
    int xPos = rect.getPosition().x / 40;
    int yPos = rect.getPosition().y / 40;

    if (mRoomMap.empty()){                                                 //If the map is empty
        mRoomMap.emplace_back(getRoomTexture(rt), rt, xPos, yPos, getRoomSize(rt), 0);    //Add room
        return;
    }

    if (roomPresent(rect)){
        return;
    }

    mRoomMap.emplace_back(getRoomTexture(rt), rt, xPos, yPos, getRoomSize(rt), 0);
}

/*
=================================================================================================================================================================
removeRoom() removes a room (if there is one) at the location of the ghost/ mouse
=================================================================================================================================================================
*/
void Ship::removeRoom(const sf::RectangleShape& rect)
{
    for (unsigned int tId = 0; tId < mRoomMap.size(); tId++){                  //Go through each room
        if (mRoomMap[tId].getSprite().getGlobalBounds().intersects(rect.getGlobalBounds())){   //If intersecting between room and selection rectangle
            for(auto& wall : mRoomMap[tId].getWalls()) {           //Go through the walls of the room
                if (wall->getType() == WT_DOOR) {                  //If the wall is a door
                    wall->getOtherWall().setType(WT_WALL);        //Set it's neighbouring door into a wall
                    wall->getOtherWall().setOtherId(0);            //Set it's "other ID" to 0, as it no longer has a neighbour door
                }//if
            }//for
            mRoomMap.erase(mRoomMap.begin() + tId);                 //Remove it.
        }//if
    }//for
}

/*
=================================================================================================================================================================
roomPresent() returns true if there is a room intersecting the rectangle passed in
=================================================================================================================================================================
*/
bool Ship::roomPresent(const sf::RectangleShape& rect)
{
    for(auto& room : mRoomMap)
    {
        if(room.getSprite().getGlobalBounds().intersects(rect.getGlobalBounds())){
            return true;
        }
    }

    return false;
}

void Ship::rotateRoom(const sf::RectangleShape& rect)
{
    for (auto& room : mRoomMap) {
        if(room.getSprite().getGlobalBounds().intersects(rect.getGlobalBounds())) {
            room.rotate();
        }
    }
}

sf::Texture& Ship::getRoomTexture(const RoomType roomT)
{
    return *roomTextures[roomT];
}

sf::Vector2f Ship::getRoomSize(const RoomType roomT)
{
    return roomSizes[roomT];
}


std::vector<Room>& Ship::getRoomMap()
{
    return mRoomMap;
}

void Ship::setRooms(const std::vector<Room>& rooms)
{
    mRoomMap = rooms;
}
