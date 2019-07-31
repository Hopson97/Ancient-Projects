#ifndef PLATFORM_H
#define PLATFORM_H

#include <SFML/Graphics.hpp>

enum Platform_Type
{
    Broken,
    Normal
};

class Platform
{
    public:
        Platform            ( const sf::Vector2f& position, Platform_Type type );

        void update         ( bool canMove, float dt );

        bool belowWindow    ( float playerPositionY ) const;

        const sf::Vector2f& getPosition () const;

        Platform_Type getType   () const;

        constexpr static int WIDTH = 128;
        constexpr static int HEIGHT = 32;

        static sf::FloatRect getBounds( const sf::Vector2f& position );

    private:
        sf::Vector2f    m_position;
        Platform_Type   m_platformType;
};

#endif // PLATFORM_H
