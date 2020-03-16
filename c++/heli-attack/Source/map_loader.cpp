#include "map_loader.h"

#include "level.h"

#include <fstream>
#include "memory"

#include "Tiles/air.h"
#include "Tiles/grass.h"
#include "Tiles/dirt.h"

void
Map_Loader :: loadMap ( Level* level, const std::string& filePath,
                        std::map<Model, Tile::Tile_Model>& models )
{
    currY = 0;
    currX = 0;

    m_level = level;
    m_models = &models;

    std::ifstream inFile ( filePath );

    if ( !inFile.is_open() )
    {
        std::runtime_error ( "Could not load map " + filePath );
    }

    //Reads each character from the map file
    std::string line;
    while ( std::getline( inFile, line ) )
    {
        for ( const auto& c : line )
        {
            switchChar( c );
            currX++;
        }
        currY++;
        currX = 0;
    }
    m_level->m_mapHeight = currY - 1;
    m_level->m_mapWidth = line.size();
}


void
Map_Loader :: switchChar ( const char c )
{
    switch ( c )
    {
    case ' ':
        m_level->m_tiles.emplace_back( std::make_unique<Tile::Air>      ( currX, currY , &m_models->at   ( Model::Air   ) ) );
        break;

    case 'g':
        m_level->m_tiles.emplace_back( std::make_unique<Tile::Grass>    ( currX, currY, &m_models->at   ( Model::Grass  ) ) );
        break;
    case 'd':
        m_level->m_tiles.emplace_back( std::make_unique<Tile::Dirt>     ( currX, currY, &m_models->at    ( Model::Dirt  ) ) );
        break;
    }
}
