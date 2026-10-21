#include "drawable.h"

Drawable::Drawable()
{

}

sf::Vector2f Drawable::normaliseVector(sf::Vector2f vec)
{
    float length = sqrt(pow(vec.x, 2) + pow(vec.y, 2)); //Pythagoras finds length

    sf::Vector2f normVec(vec.x/ length, //Divide the X by the length
                         vec.y/ length); //Divide the Y by the length

    return normVec;     //Returns a normalised vector
}

void Drawable::addSpeedToVector(sf::Vector2f &vec)
{
    vec.x *= speed; //Speed it up
    vec.y *= speed; //Speed it up
}
