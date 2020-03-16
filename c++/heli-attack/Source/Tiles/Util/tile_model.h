#ifndef TILE_MODEL_H
#define TILE_MODEL_H

#include "tile_info.h"

#include <memory>

namespace Tile
{

class Tile_Model
{
    friend class Tile_Base;
    public:

        void
        setUp ( const sf::Texture& texture, const bool solid );

        void
        setUp ( const bool solid );

        void
        setPosition ( const int x, const int y );

        void
        draw        ( sf::RenderWindow& window );

    private:
        std::unique_ptr<sf::RectangleShape>     m_tile;
        Tile_Data                               m_data;

        bool hasSetUp = false; //Exists because std::map is being awkward
};

}

#endif // TILE_MODEL_H
