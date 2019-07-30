#include "ship.h"

Ship::Ship(TextureManager& textures, const int width, const int height, const std::string& path)
:   mFilePath(path)
{
    setRoomDatabase(textures);
    setUnitDatabase(textures);
}

/*
=================================================================================================================================================================
checkForWallOrDoor()

Basically, this method checks how many walls are within the rectangle passed in. (which is the ghost rectangle)

Every time it find a wall `numWalls` gets incremented by one. Depending on the number of walls found within the range:  if less than 2, nothing happens
                                                                                                                        if 2, change both to be doors.
=================================================================================================================================================================
*/
void Ship::checkForWallorDoor(const sf::RectangleShape& rect, const WallOrDoor checkingFor, const WallOrDoor changingTo)
{
    std::shared_ptr<Wall> wall1;      //Pointer to first wall
    std::shared_ptr<Wall> wall2;      //Pointer to second wall

    int numWalls = 0;                           //Number of walls detected

    for (auto& room : mRoomMap) {               //For each room in the ship
        for (auto& wall : room.getWalls()) {       //iterate though each wall of said room

            if (wall->getType() == checkingFor)  {      //If the type of room is the room being checked for

                if(rect.getGlobalBounds().intersects(wall->getRect().getGlobalBounds() ) ) {    //and has an intersection with the "ghost"

                    numWalls++;                     //Increase the number of walls this is true to by 1
                    if (numWalls == 1) {            //If the number of walls this is true to in the loop is equal to 1
                        wall1 = wall;               //Set the wall1 pointer to point to the wall
                    }
                    else if (numWalls == 2) {       //If the number of walls this is true to in the loop is equal to 2
                        wall2 = wall;               //Set the wall2 pointer to point to the second wall
                    }
                }//Intersection check end
            }//Type of wall check end
        }//For each wall loop end
    }//For each room loop end

    if (numWalls == 2) {                //If two rooms were checked
        wall1->setType(changingTo);     //Set the first room to be a door
        wall2->setType(changingTo);     //Do for second room as well

        wall1->setOtherWall(wall2);
        wall2->setOtherWall(wall1);

        wall1->setOtherId   (wall2->getId());
        wall2->setOtherId   (wall1->getId());
    }
}

/*
=================================================================================================================================================================
draw the ship
=================================================================================================================================================================
*/
void Ship::draw(sf::RenderWindow& window)
{
    for (auto& room: mRoomMap){
        room.draw(window);
    }
}

std::string& Ship::getTxrFilePath ()
{
    return mFilePath;
}
