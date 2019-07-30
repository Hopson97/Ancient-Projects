#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include <SFML/Audio.hpp>

#include <map>
#include <string>

enum SoundName
{
        RES_SOUND_GBL_GENERIC_CLICK

    ,   RES_SOUND_UNIT_RECRUIT_SELECTED_1
    ,   RES_SOUND_UNIT_RECRUIT_SELECTED_2
};

class SoundManager
{
    public:
                            SoundManager            ();
        void                loadGlobalSounds        ();
        void                loadUnitSounds          ();

        sf::Sound&          getSound                (const SoundName& name);
        sf::SoundBuffer&    getSoundBuffer          (const SoundName& name);

        std::map<SoundName, sf::Sound>  getSoundmap ();

    protected:
    private:
        void                        loadSound               (const SoundName& name, const std::string& filePath);

        std::map<SoundName, sf::SoundBuffer>    mSoundBuffers;
        std::map<SoundName, sf::Sound>          mSounds;

        std::string soundPath { "Resources/Sounds/" };
};

#endif // SOUNDMANAGER_H
