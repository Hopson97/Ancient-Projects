#ifndef GRASS_H
#define GRASS_H

#include "tile.h"

#include "../game.h"

namespace Tile
{

class Grass : public Tile_Base
{
    public:
        Grass( const int xPos, const int yPos, Tile_Model* model );

    protected:

    private:
};

}

#endif // GRASS_H
