#include "font_m.h"

#include <stdexcept>
#include <iostream>

namespace Manager
{

Font_M :: Font_M()
{
    loadFonts();
}

//Loads up all the fonts.
void
Font_M :: loadFonts ()
{
    const static std::string FontPath = "Res/Fonts/";

    loadFont( Font_Name::Instruction,   FontPath + "Instruction.ttf" );
    loadFont( Font_Name::Arial,         FontPath + "arial.ttf" );
}


// Loads a font and adds it into the std::map.
void
Font_M :: loadFont ( const Font_Name name, const std::string& path )
{
    if ( !m_fonts[ name ].loadFromFile( path ) )
    {
        throw std::runtime_error ( "Font at " + path + " does not exist." );
    }
}

// Returns a const font based on the font name passed in.
const sf::Font&
Font_M :: getFont ( const Font_Name name ) const
{
    return m_fonts.at( name );
}



}
