#include "button.h"


/*
=================================================================================================================================================================
Button is class that is a.. well a button that can be clicked.
=================================================================================================================================================================
*/
Button::Button(const sf::Texture& texture, const sf::Vector2f pos):
    Object(texture)
{
    mSprite.setPosition(pos);   //Set position
}

/*
=================================================================================================================================================================
clicked() returns true if the button is clicked
=================================================================================================================================================================
*/
bool Button::clicked(sf::RenderWindow& window)


{
    window.draw(mSprite);
    if (touchingMouse(window) && sf::Mouse::isButtonPressed(sf::Mouse::Left))   // If clicked
    {
        mSprite.setColor(sf::Color(200, 200, 200, 255));                        //Change colour
        return true;                                                            //Return true;
    }
    else if (touchingMouse(window))                                 //If mouse rolled over
    {
        mSprite.setColor(sf::Color(220, 220, 220, 255));            //Change colour
        return false;                                               //But as not clicked, return false
    }
    else                                                            //If no events
    {
        mSprite.setColor(sf::Color(255, 255, 255, 255));            //Go to default colour
        return false;                                               //Return false
    }
}


/*
=================================================================================================================================================================
touchingMouse() returns true if the button is touching the mouse
=================================================================================================================================================================
*/
bool Button::touchingMouse(sf::RenderWindow& window)
{
    sf::IntRect bound(mSprite.getLocalBounds());            //For getting button size
    sf::Vector2i mouse(sf::Mouse::getPosition(window));     //Location of mouse relative to window

    if (mouse.x > mSprite.getPosition().x                   //If mouse is to the right of the button
        &&                                                  //and
        mouse.x < mSprite.getPosition().x + bound.width     //If mouse is to the left of the button
        &&                                                  //and
        mouse.y > mSprite.getPosition().y                   //If mouse is below of the button
        &&                                                  //and
        mouse.y < mSprite.getPosition().y + bound.height)   //If mouse is above the button
        {
            return true;                                    //Return true
        }
        else
        {
            return false;                                   //Else, return false
        }
}
