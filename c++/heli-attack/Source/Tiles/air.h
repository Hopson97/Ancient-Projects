#ifndef AIR_H
#define AIR_H

#include "tile.h"

namespace Tile
{

class Air : public Tile_Base
{
    public:
        Air( const int xPos, const int yPos, Tile_Model* model );

    private:
};

}

#endif // AIR_H
