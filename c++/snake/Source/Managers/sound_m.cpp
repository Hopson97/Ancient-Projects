#include "sound_m.h"

namespace Manager
{

Sound_M :: Sound_M()
{
    loadSounds();
}

const sf::SoundBuffer&
Sound_M :: getSound ( const Sound_Name name) const
{
    return m_sounds.at( name );
}

void
Sound_M :: loadSounds ()
{
    const std::string soundPath = "Res/Sounds/";
}

void
Sound_M :: loadSound ( const Sound_Name name, const std::string& filePath )
{
    if ( !m_sounds[ name ].loadFromFile( filePath ) )
    {
        throw std::runtime_error ( "Sound at " + filePath + " does not exist." );
    }
}

}
