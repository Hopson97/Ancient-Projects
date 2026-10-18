#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class Button
{
    public:
        Button(int _xSize, int _ySize, int _xPos, int _yPos, std::string text);

        bool buttonClicked(sf::RenderWindow &w);

    private:
        bool mouseOver(sf::RenderWindow &w);

    private:
        int xSize;
        int ySize;

        sf::RectangleShape theButton;
        sf::Font font;
        sf::Text text;

        sf::Color bCol;
};

#endif // BUTTON_H
