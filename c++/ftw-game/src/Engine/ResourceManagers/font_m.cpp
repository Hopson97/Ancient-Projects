#include "font_m.h"

FontManager::FontManager()
{
    loadFonts();
}

const sf::Font& FontManager::getFont(FontName name)
{
    return mFonts[name];
}

void FontManager::loadFont(const FontName name ,const std::string& path)
{
    mFonts[name].loadFromFile(path);
}

void FontManager::loadFonts()
{
    loadFont(RES_FONT_FANCY, fontPath + "MTCORSVA.ttf");
}
