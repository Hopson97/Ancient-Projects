#include "shiploader.h"

#include <fstream>

#include "ResourceManagers/texture_m.h"
#include "constants.h"

/*****************************************************************************************************************************************************************
*   loadShip()  the method to call that loads up a ship from the games Resources/Ship Data/ folder
*   param1  :   a pointer to the ship that will be changed
*   param2  :   a file path to where the ship's data is located (Resources/Ship Data/example.SHIP)
*   param3  :   texture manager singleton, so that the rooms walls can have a pointer to the texture of its type.
***************************************************************************************************************************************************************/
void ShipLoader::loadShip(Ship* ship, const std::string& shipPath, TextureManager& textureManager)
{
    mShip = ship;
    std::ifstream   loader(shipPath);       //Main loader
    std::string     reader;                 //Main "line" reader
    std::string     texturePath;            //String for the texture path

    loader >> reader;           //Ignore the first line (it is for the ship editor)
    loader >> texturePath;      //Load the texture path of the ship
    loader >> reader;           //Ignore, this is the inital "r" of the ship file.

    sf::Texture t;                  //Texture for the ship
    t.loadFromFile(texturePath);    //load it

    mShip->setTexture(t);

    while (loader >> reader) {                      //Read the second "r"
            loadRoom( loader, textureManager );     //Load a room
    }
    matchUpDoors();
    mShip->setRooms( std::move ( mRooms ) );
    mShip->setUnits( std::move ( mUnits ) );
    loader.close();
}

/*****************************************************************************************************************************************************************
*   loadRoom    does the file handling of loading up a room and loading the said room's walls
*   param1  :   the std::ifstream that will read the file
*   param2  :   the singleton texture manager, again so that walls can have pointer to the correct texture
***************************************************************************************************************************************************************/
void ShipLoader::loadRoom(std::ifstream& loader, TextureManager& textureManager)
{
    std::string reader;
    addRoom( loader );  //Add a room into the ships room vector
    while(true)
    {
        loader >> reader;                   //Read next char
        if (loader.eof()) {             //If it is the end of the file
            return;                     //Return back!
        }
        else if ( reader == "r") {      //If the next line is an "r"
            return;                     //Then a new room is ready to be loaded, so return back!
        }
        else if ( reader == "w" ) {      //If the next line is a "w"
            mRooms.back().              //A wall is ready to be loaded, so add a wall to last room added
                    addWall( addWall (loader, textureManager ) ); //
            continue;
        }
        else if ( reader == "u" ) {
            addUnit(loader);
            continue;
        }
    }
}

/*****************************************************************************************************************************************************************
*   addRoom()   Read in the room's data and then return a room that uses said data
****************************************************************************************************************************************************************/
void ShipLoader::addRoom(std::ifstream& loader)
{
    int xPos, yPos, rot, type;
    loader >> xPos >> yPos >> rot >> type;
    mRooms.emplace_back(
                                sf::Vector2f(xPos, yPos),
                                static_cast<RoomType>(type),
                                *mShip->getTexture(static_cast<RoomType>(type)),
                                rot,
                                mShip->getPosition()
                                );
}

/****************************************************************************************************************************************************************
*   addWall()   Read in the wall's data and then return a wall that uses said data
****************************************************************************************************************************************************************/
Wall ShipLoader::addWall(std::ifstream& loader, TextureManager& textureManager)
{
    int xPos, yPos, rot, id, otherId, type;
    loader >> xPos >> yPos >> rot >> id >> otherId >> type;
    return {
                textureManager,
                sf::Vector2f(xPos,
                             yPos),
                rot,
                static_cast<WallType>(type),
                id,
                otherId,
                mShip->getPosition()
                };//
}

void ShipLoader::addUnit(std::ifstream& loader)
{
    int xPos, yPos, type;
    loader >> xPos >> yPos >> type;
    mUnits.emplace_back(
                            *mShip->getTexture(static_cast<UnitType>(type)),
                            static_cast<UnitType>(type),
                            sf::Vector2f (
                                xPos,
                                yPos
                                ),
                            mShip->getPosition()

                            );
}

void ShipLoader::matchUpDoors() //o(n ^ 1000000000000000000000000) probably lol
{
    std::vector<Wall> wallInfo;

    for ( auto& room : mRooms )
    {
        for ( auto& wall : room.getWalls() )
        {
            if( wall.getType() == WT_DOOR ) {
                wallInfo.emplace_back(wall);
            }
        }
    }

    for( auto& room : mRooms )
    {
        for(auto& wall : room.getWalls())
        {
            if( wall.getOtherId() != 0 )
            {
                for( auto& wall2 : wallInfo )
                {
                    if( wall.getOtherId() == wall2.getId() )
                    {
                        wall.setOtherDoor(wall2);
                        wall2.setOtherDoor(wall);
                    }
                }
            }
        }
    }
}
