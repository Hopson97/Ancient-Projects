#include "ResourceHolder.h"

ResourceHolder::ResourceHolder() noexcept
:   textures        ("res/txrs/",   "png")
,   fonts           ("res/fonts/",      "ttf")
,   soundBuffers    ("res/sfx",         "ogg")
{ }

ResourceHolder& ResourceHolder::get()
{
    static ResourceHolder res;
    return res;
}

const sf::Texture& ResourceHolder::getTexure(const std::string& name)
{
    return get().textures.get(name);
}

const sf::Font& ResourceHolder::getFont(const std::string& name)
{
    return get().fonts.get(name);
}

const sf::SoundBuffer& ResourceHolder::getSoundBuff(const std::string& name)
{
    return get().soundBuffers.get(name);
}
