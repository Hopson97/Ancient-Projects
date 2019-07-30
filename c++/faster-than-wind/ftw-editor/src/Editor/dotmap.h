#ifndef DOTMAP_H
#define DOTMAP_H

#include <SFML/Graphics.hpp>
#include <iostream>

class DotMap
{
    public:
        DotMap(const sf::Texture& mShipTexture);

        void            draw(sf::RenderWindow& window); //Draw the dots

        sf::Vector2i    getDotMapDimensions() const;          //Returns size of ship
    private:
        bool            dotInShipBounds(const sf::Sprite&, const sf::Vector2f&); //Checks if point is within ships's bounds (links with constructor)

    private:
        sf::VertexArray mDotMap;

        int mShipWidth, mShipHeight;

};

#endif // DOTMAP_H
