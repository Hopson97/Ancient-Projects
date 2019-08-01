#ifndef TILE_INFO_H_INCLUDED
#define TILE_INFO_H_INCLUDED

#include <SFML/Graphics.hpp>

namespace Tile
{
    constexpr   int             TILE_SIZE = 60;
    const       sf::Vector2f    TILE_RECT = { TILE_SIZE, TILE_SIZE };

    struct Tile_Data
    {
        sf::Vector2i    tileMapPosition;
        bool            isSolid;
    };
}


#endif // TILE_INFO_H_INCLUDED
