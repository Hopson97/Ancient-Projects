#ifndef TILE_H
#define TILE_H

#include <memory>
#include <SFML/Graphics.hpp>

#include "Util/tile_info.h"
#include "Util/tile_model.h"

namespace Tile
{

class Tile_Base
{
    public:
        Tile_Base( const int xPos, const int yPos );
        Tile_Base( const int xPos, const int yPos, Tile_Model* model );

        virtual void
        update  ( const float dt );

        virtual void
        draw                ( sf::RenderWindow& window );

        const sf::Vector2i
        getTileMapPosition  () const;

        bool
        isSolid();

    private:
        sf::Vector2i    m_tilePosition;
        Tile_Model*     m_model = nullptr;
};

}

#endif // TILE_H
