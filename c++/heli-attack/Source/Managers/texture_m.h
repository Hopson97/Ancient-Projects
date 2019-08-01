#ifndef TEXTURES_H
#define TEXTURES_H

#include <map>
#include <SFML/Graphics.hpp>

enum class Texture_Name
{
    Grass
,   Dirt

,   Bullet
,   Player

,   Eye_Enemy
};

namespace Manager
{

class Texture_M
{
    public:
        Texture_M();

        const sf::Texture&
        getTexture          ( const Texture_Name name ) const;

    private:
        void
        loadTileTextures    ();

        void
        loadEntityTextures  ();

        void
        loadTexture         ( const Texture_Name name, const std::string& path );

    private:
        std::map<Texture_Name, sf::Texture> m_textureMap;
};

}

#endif // TEXTURES_H
