#include "texture_m.h"

namespace Manager
{

Texture_M :: Texture_M()
{
    loadTileTextures    ();
    loadEntityTextures  ();

}

void
Texture_M :: loadTileTextures()
{
    const std::string tilePath = "Res/Textures/Tiles/";
}

void
Texture_M :: loadEntityTextures  ()
{
    const std::string entityPath = "Res/Textures/Entities/";
}


const sf::Texture&
Texture_M :: getTexture( const Texture_Name name ) const
{
    return m_textureMap.at( name );
}


void
Texture_M :: loadTexture ( const Texture_Name name, const std::string& path )
{
    if ( !m_textureMap[ name ].loadFromFile( path ) )
    {
        throw std::runtime_error ( "Texture at " + path + " does not exist.");
    }
}

}
