#ifndef RESOURCE_IDENTIFIER_H_INCLUDED
#define RESOURCE_IDENTIFIER_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "resource_manager.h"

namespace Res
{
    inline std::string getTexture( const std::string& name )
    {
        return "Data/Textures/" + name + ".png";
    }


    inline std::string getSound( const std::string& name )
    {
        return "Data/Sounds/" + name + ".ogg";
    }


    inline std::string getFont( const std::string& name )
    {
        return "Data/Fonts/" + name + ".ttf";
    }
}

enum class Font_Name
{
	Arial
};

enum class Sound_Name
{
    Example
};

enum class Texture_Name
{
    SFML_Logo,

    Platform_Normal,
    Platform_Broken,
    Playing_Background,

    Player_Normal
};

typedef Resource_Manager<Font_Name,     sf::Font>           Font_Manager;
typedef Resource_Manager<Sound_Name,    sf::SoundBuffer>    Sound_Manager;
typedef Resource_Manager<Texture_Name,  sf::Texture>        Texture_Manager;






#endif // RESOURCE_IDENTIFIER_H_INCLUDED
