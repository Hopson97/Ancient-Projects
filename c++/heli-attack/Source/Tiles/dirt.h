#ifndef DIRT_H
#define DIRT_H

#include "tile.h"
#include "Util/tile_model.h"

namespace Tile
{

class Dirt : public Tile_Base
{
    public:
        Dirt( const int x, const int y, Tile_Model* model );

    protected:

    private:
};

}

#endif // DIRT_H
