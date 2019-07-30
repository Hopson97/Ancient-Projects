#ifndef GHOST_H
#define GHOST_H

#include <SFML/Graphics.hpp>

namespace ghCol
{
    const sf::Color GREEN(0, 255, 0, 170);
    const sf::Color RED  (255, 0, 0, 170);
}

enum mode
{
    wall,
    room,
    unit
};

class Ghost
{
    public:
        Ghost();
        void                logic(const sf::Vector2i mousePos,
                                  const int maxWidth, const int maxHeight,
                                  const sf::RenderWindow& window);

        bool                isOutOfBounds      (const int maxWidth, const int maxHeight);
        bool                isMouseOutOfBounds (const int maxWidth, const int maxHeight,
                                                const sf::RenderWindow& window);

        void                updateRectColour    (const sf::Color c);
        void                updateRectSize      (const sf::Vector2f s);

        void                setMode             (const mode m);

        void                rotate              ();

        sf::Vector2f        getPos()  const ;
        sf::Vector2f        getSize() const ;
        sf::RectangleShape  getRect() const;

        void                draw(sf::RenderWindow& window);

    private:
        void                snapToMap ();
        void                checkXOffset( sf::Vector2i& pos);
        void                checkYOffset( sf::Vector2i& pos);

        void                goToMouse(const sf::Vector2i mousePos, const int maxWidth, const int maxHeight,
                                      const sf::RenderWindow& window);

    private:
        mode mMode;
        int xPos;
        int yPos;

        sf::RectangleShape mGhostRect;
};

#endif // GHOST_H
