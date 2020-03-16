#ifndef SOUND_M_H
#define SOUND_M_H

#include <SFML/Audio.hpp>
#include <map>

enum class Sound_Name
{
        Bullet_Generic
    ,   Walk1
};

namespace Manager
{

class Sound_M
{
    public:
        Sound_M();

        const sf::SoundBuffer&
        getSound    ( const Sound_Name name) const;

    private:
        void
        loadSounds  ();

        void
        loadSound   ( const Sound_Name name, const std::string& filePath );

        std::map<Sound_Name, sf::SoundBuffer> m_sounds;
};

}

#endif // SOUND_M_H
