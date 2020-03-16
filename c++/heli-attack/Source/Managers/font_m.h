#ifndef FONT_M_H
#define FONT_M_H

#include <map>
#include <SFML/Graphics.hpp>


enum class Font_Name
{
        Instruction
    ,   Arial
};

namespace Manager
{

class Font_M
{
    public:
        Font_M();

        const sf::Font&
        getFont ( const Font_Name name ) const;

    private:
        void
        loadFonts ();

        void
        loadFont    ( const Font_Name name, const std::string& path );

        std::map<Font_Name, sf::Font> m_fonts;
};

}

#endif // FONT_M_H
