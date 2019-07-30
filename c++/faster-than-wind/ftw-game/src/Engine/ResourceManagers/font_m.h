#ifndef FONT_M_H
#define FONT_M_H

#include <SFML/Graphics.hpp>

#include <map>

enum FontName
{
    RES_FONT_FANCY //MTCORSVA.ttf
};

class FontManager
{
    public:
        FontManager();
        const   sf::Font& getFont (const FontName name);

    private:
                void loadFont   (const FontName name ,const std::string& path);
                void loadFonts  ();

        std::string fontPath { "Resources/Fonts/" };

        std::map<FontName, sf::Font> mFonts;
};

#endif // FONT_M_H
