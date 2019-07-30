#include "sound_m.h"

#include <iostream>

SoundManager::SoundManager()
:   soundPath   ("Resources/Sounds/")
{
    loadGlobalSounds();
    loadUnitSounds();
}

void SoundManager::loadGlobalSounds()
{
   loadSound( RES_SOUND_GBL_GENERIC_CLICK, soundPath + "click.ogg");
}

void SoundManager::loadUnitSounds()
{
    loadSound( RES_SOUND_UNIT_RECRUIT_SELECTED_1, soundPath + "Units/Recruit/sel_1.ogg");
    loadSound( RES_SOUND_UNIT_RECRUIT_SELECTED_2, soundPath + "Units/Recruit/sel_2.ogg");
}

void SoundManager::loadSound(const SoundName& name, const std::string& filePath)
{
    mSoundBuffers[name].loadFromFile(filePath);
    mSounds[name].setBuffer( mSoundBuffers[name] );
}

sf::SoundBuffer& SoundManager::getSoundBuffer (const SoundName& name)
{
    return mSoundBuffers[name];
}

sf::Sound& SoundManager::getSound (const SoundName& name)
{
    return mSounds[name];
}

std::map<SoundName, sf::Sound> SoundManager::getSoundmap()
{
    return mSounds;
}
