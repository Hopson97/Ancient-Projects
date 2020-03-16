#ifndef LEVEL_H
#define LEVEL_H

///Where the tile map code stuff will go I guess

#include <vector>
//#include <map>

#include "Tiles/grass.h"

enum class Model
{
    Grass
,   Dirt
,   Air
};

class Level
{
    friend class Map_Loader;

    using TilePtr = std::unique_ptr<Tile::Tile_Base>;

    public:
        Level ( const Game& game );

        void
        update  ( const float dt );

        void
        draw    ( sf::RenderWindow& window, const sf::Vector2i& playerPos );

        const TilePtr&
        getTileAt ( const int x, const int y ) const;

        const TilePtr&
        getTileAt ( const sf::Vector2i& tilePosition ) const;

        int
        getGravity      () const;

        int
        getWidth        () const;

        int
        getHeight       () const;

    private:
        void
        getScreenBounds(  int& xStart, int& yStart,
                          int& xEnd,   int& yEnd,
                          const sf::Vector2i& playerTilePos ) const;

    private:
        std::vector<TilePtr>        m_tiles;

        std::map<Model, Tile::Tile_Model> m_models;

        TilePtr                     m_errorTile; //If all else fails, the "get tile" methods returns an air tile if the entity somehow gets out of bounds :/

        int                         m_mapHeight;
        int                         m_mapWidth;

        constexpr static int        m_GRAVITY = 2000;
};

#endif // LEVEL_H
