#include "dotmap.h"

/*
=================================================================================================================================================================

=================================================================================================================================================================
*/
DotMap::DotMap(const sf::Texture& mShipTexture):
    mShipWidth  (0),
    mShipHeight (0)
{
    sf::Sprite mShip;
    mShip.setTexture(mShipTexture);
    sf::FloatRect shipPoint = mShip.getLocalBounds();

    mShipWidth  = shipPoint.width  /40 - 2; //How many "tiles" across the ships tile map will be. (-2 due to the dots on the end)
    mShipHeight = shipPoint.height / 40 - 2;//How many "tile" down ^

    for(int y = 0; y < 35; y++)     //For loop for the dot map
    {
        for(int x = 0; x < 64; x++)
        {
            sf::Vector2f point(x  * 40, y * 40); //Position of the point

            if (dotInShipBounds(mShip, point))  //If the point is within the ships bounds
            {
                sf::Vertex p;                   //Create a vertex
                p.color = sf::Color::White;     //Colour it white
                p.position = point;             //Set it's position
                mDotMap.append(p);              //Add it to the vertex array
            }
            else                                //If the point is not within the ships bounds
            {
                continue;                       //Continue the loop
            }
        }
    }
}

/*
=================================================================================================================================================================

=================================================================================================================================================================
*/
bool DotMap::dotInShipBounds(const sf::Sprite& mShip, const sf::Vector2f& point) //returns a boolean whether ship is in bounds
{
    sf::FloatRect shipPoint = mShip.getLocalBounds();

    if (point.x > mShip.getPosition().x                     //If point is to the left of the right side of the ship
        &&
        point.x < mShip.getPosition().x + shipPoint.width   //and to the right of the left side of the ship
        &&
        point.y > mShip.getPosition().y                    //and above the bottom of the ship
        &&
        point.y < mShip.getPosition().y + shipPoint.height) //and below the top of the ship
        {
            return true;                                    //Woo, it is within bounds
        }
    else return false;
}

/*
=================================================================================================================================================================

=================================================================================================================================================================
*/
sf::Vector2i DotMap::getDotMapDimensions() const
{
    return sf::Vector2i(mShipWidth, mShipHeight);
}

/*
=================================================================================================================================================================

=================================================================================================================================================================
*/
void DotMap::draw(sf::RenderWindow& window)
{
    window.draw(mDotMap);
}




























