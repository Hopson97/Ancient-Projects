#ifndef SHIPLOADER_H
#define SHIPLOADER_H

#include <vector>

#include "../Objects/Ship_Objects/room.h"
#include "../Objects/Ship_Objects/Unit/unit.h"
#include "../Objects/Ship_Objects/Ship/ship.h"

class ShipLoader
{
    public:
        void    loadShip    (Ship* ship, const std::string& shipPath, TextureManager& textureManager);

    private:
        void    loadRoom    (std::ifstream& loader, TextureManager& textureManager);
        void    addRoom     (std::ifstream& loader);
        Wall    addWall     (std::ifstream& loader, TextureManager& textureManager);
        void    addUnit     (std::ifstream& loader);

        void    matchUpDoors    ();


    private:
        std::vector<Room> mRooms;
        std::vector<Unit> mUnits;
        Ship* mShip;
};

#endif // SHIPLOADER_H
