#ifndef CONSTANTS_H_INCLUDED
#define CONSTANTS_H_INCLUDED

#include "SFML/Graphics.hpp"

namespace win
{
    constexpr int WIDTH             = 1280;
    constexpr int HEIGHT            = 700;
    constexpr int FRAME_RATE_LIMIT  =  60;
}

namespace col
{
    constexpr int MAX_COLOUR    = 255;
    constexpr int MIN_COLOUR    = 0;

    const sf::Color BLACK       (0, 0, 0, 255);

    const sf::Color YELLOWY     ( 189, 187, 95,  255    );
    const sf::Color SELECTED    ( 150, 150, 150, 255    );
    const sf::Color TEXT_COLOUR ( 255, 245, 188, 255    );
    const sf::Color WATER       ( 74, 141, 255,  255    );
}

namespace ship
{
    constexpr int TILE_SIZE     =   40;
    constexpr int WIDTH         =   600;
    constexpr int HEIGHT        =   320;

    const sf::IntRect UNIT_SIZE    (0, 0, 38, 38 );
}

namespace txtSz
{
    constexpr int large = 60;
    constexpr int small = 27;
}


#endif // CONSTANTS_H_INCLUDED
