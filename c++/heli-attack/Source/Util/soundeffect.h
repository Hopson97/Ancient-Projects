#ifndef SOUNDEFFECT_H
#define SOUNDEFFECT_H

#include <SFML/Audio.hpp>

class SoundEffect
{
    public:
        SoundEffect ( const sf::SoundBuffer& sfxBuffer );

        void
        play        ();

        void
        stop        ();


    private:
        sf::Sound           m_sound;
        sf::Clock           m_replayClock;

        const double        m_delay;
        bool                m_hasPlayedOnce = false;

};

#endif // SOUNDEFFECT_H
