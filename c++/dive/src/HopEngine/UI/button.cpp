#include "button.h"

Button::Button(int _xSize, int _ySize, int _xPos, int _yPos, std::string _text):
    xSize(_xSize),
    ySize(_ySize)
{
    std::string path = "fonts/arial.ttf";
    if(!font.loadFromFile(path));

    int textLength = _text.length();

    text.setFont(font);
    text.setString(_text);
    text.setPosition((_xPos + _xSize/2) - textLength*6,
                      _yPos + _ySize/2 - 20);
    text.setColor(sf::Color::Yellow);

    bCol.r = 5;
    bCol.g = 5;
    bCol.b = 5;

    sf::Vector2f size(xSize, ySize);
    theButton.setSize(size);

    theButton.setOutlineColor(sf::Color::Blue);
    theButton.setOutlineThickness(5);


    theButton.setPosition(_xPos, _yPos);
}

bool Button::buttonClicked(sf::RenderWindow &w)
{
    theButton.setFillColor(bCol);
    w.draw(theButton);
    w.draw(text);

    if(mouseOver(w))
    {
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            return true;
        }
        else{
            return false;
        }
    }

    return false;
}

bool Button::mouseOver(sf::RenderWindow &w)
{
    sf::Vector2f mPos(sf::Mouse::getPosition(w)); // Mouse pos
    sf::Vector2f bPos(theButton.getPosition()); //Button pos
    sf::Vector2f bSiz(theButton.getSize());

    if (mPos.x > bPos.x &&          //If mouse is RIGHT
        mPos.x < bPos.x + bSiz.x    //If mouse is LEFT
        &&
        mPos.y > bPos.y &&          //If mouse is BELOW
        mPos.y < bPos.y + bSiz.y)   //If mouse is ABOVE
    {
        bCol.a = 215;
        return true;
    }
    else
    {
        bCol.a = 100;
        return false;
    }
    return false;
}



















