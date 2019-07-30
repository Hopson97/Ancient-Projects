#include "currentlyselected.h"

/*
=================================================================================================================================================================
This class is a small scroll that displays what room is currently selected
=================================================================================================================================================================
*/
CurrentlySelected::CurrentlySelected(const sf::Texture& t, const TextureManager& textures):
    Object(t)
{
    mSprite.setPosition(880, 0);

    selected.setSize(sf::Vector2f(100, 100));   //Set rectangle size
    selected.setPosition(sf::Vector2f(mSprite.getPosition().x + mSprite.getLocalBounds().width / 2 - 40,    //Set rectangle X position
                                      mSprite.getPosition().y + mSprite.getLocalBounds().height/ 2 - 40));  //Set rectangle Y position

    font.loadFromFile("Resources/arial.ttf");                   //Load font

    selectedText.setFont(font);                                 //Set the text's font to the font just loaded
    selectedText.setString("None Selected ");                   //Set it's display text to "none selected"

    selectedText.setPosition(selected.getPosition().x - 105,          //Set it's x Position
                             selected.getPosition().y + 105);   //set it's y Position

    selectedText.setColor(sf::Color(255, 178, 102));            //Set it's colour

    roomTextMap[RT_EMPTY_SMALL]         = "Empty Small";    //Register some textures to a map
    roomTextMap[RT_EMPTY_LARGE]         = "Empty Large";
    roomTextMap[RT_EMPTY_SMALL_WIDE]    = "Empty Small Wide";
    roomTextMap[RT_EMPTY_SMALL_TALL]    = "Empty Small Tall";
    roomTextMap[RT_EMPTY_HUGE]          = "Empty Huge";
    roomTextMap[RT_CANNON]              = "Cannon";

    unitTextMap[UT_RECRUIT]             = "Recruit";
}

/*
=================================================================================================================================================================
draw() draws the 3 things: scroll, rectangle and text.
=================================================================================================================================================================
*/
void CurrentlySelected::draw(sf::RenderWindow& window)
{
    window.draw(mSprite);       //Draw the background texture
    window.draw(selected);      //Draw the rectangle that displays the room selected
    window.draw(selectedText);  //Draw the text
}

/*
=================================================================================================================================================================
updateSelected() updates what texture is shown in the "currently selected" box.
=================================================================================================================================================================
*/
bool CurrentlySelected::updateSelected(const RoomType room, const sf::Texture& texture)
{
    selectedText.setString (roomTextMap[room]);     //Change the selected text
    setTexture(texture);                        //Change the selected texture
    return true;
}

bool CurrentlySelected::updateSelected(const UnitType unit, const sf::Texture& texture)
{
    selectedText.setString (unitTextMap[unit]);     //Change the selected text
    setTexture(texture);                        //Change the selected texture
    return true;
}

/*
=================================================================================================================================================================
setTexture() sets the texture of the rectangle
=================================================================================================================================================================
*/
void CurrentlySelected::setTexture(const sf::Texture& texture)
{
    selected.setTexture(&texture);
}
