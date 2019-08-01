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

    loadTexture( Texture_Name::Grass, tilePath + "Grass.png" );
    loadTexture( Texture_Name::Dirt,  tilePath + "Dirt.png"  );
}

void
Texture_M :: loadEntityTextures  ()
{
    const std::string entityPath = "Res/Textures/Entities/";

    loadTexture(Texture_Name::Player,       entityPath + "player.png");
    loadTexture(Texture_Name::Bullet,       entityPath + "bullet.png");
    loadTexture(Texture_Name::Eye_Enemy,    entityPath + "eye_enemy.png");
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

    //m_textureMap[ name ].setSmooth( true );
}

}
