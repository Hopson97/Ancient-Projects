#include "blob.h"

blob::blob()
{
    name = "player";
    folder = "player";
    setSprite();

    sprite.setPosition(50,201);

    xVelocity = 0.0f;

    leftArrowDown = false;
    rightArrowDown = false;

    canJump = true;
}

void blob::logic()  //Does everything that this sprite needs to do
{
    input();

    physicsLogic();

    update();
}

void blob::physicsLogic() //Handles movements and such, also goes to "collision" method
{
    if(!isLeftButtonDown() || !isRightButtonDown()) //If the player is not pressing left or right keys
    {
        if(getXVel() < 0.0f) setXVel(getXVel() + 0.2f);    //Slow down (go right)
        else if(getXVel() > 0.0f) setXVel(getXVel() - 0.2f); //Slow down (go left)
    }
    if(sprite.getPosition().y < 200.0f) //If the above ground
    {
        setYVel(getYVel() + 0.4f);      //Go down
    }

    if(sprite.getPosition().y > 200.0f) //If it is above ground
    {
        if(!isUpButtonDown())
        {
            setYVel(0); //So they don't fall through
        }
        canJump = true;
    }

    if(getXVel() < -2.0f) setXVel(-1.8f);
    else if(getXVel() > 2.0f) setXVel(1.8f);

    collision();
}

void blob::update() //Update the location/ appearance of sprite
{
    sprite.move(xVelocity, yVelocity);

}

void blob::input()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        setXVel(getXVel() - 0.5f);
        setLeftButtonState(true);
        //sprite.setTextureRect(sf::IntRect(getXPos(),getYPos(),32,32));

    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        setXVel(getXVel() + 0.5f);
        setRightButtonState(true);
        //sprite.setTextureRect(sf::IntRect(getXPos()+32,getYPos(),32,32));
    }
    else
    {
        setLeftButtonState(false);
        setRightButtonState(false);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
            && canJump)
    {
        setYVel(getYVel() - 2.0f);
        canJump = false;
        setUpButtonState(true);
    }
    else
    {
        setUpButtonState(false);
    }

}

void blob::collision()
{
    if(getXPos() < 0 )  setXVel(5); //Right coll
    else if(getXPos() > 436) setXVel(-5);   //LEFT COLL
}

/*
           ~~~~~ GETTER AND SETTER LINE ~~~~~
*/

bool blob::isUpButtonDown() const
{
    return upArrowDown;
}
void blob::setUpButtonState(bool isDown)
{
    upArrowDown = isDown;
}

bool blob::isLeftButtonDown() const
{
    return leftArrowDown;
}
void blob::setLeftButtonState(bool isDown)
{
    leftArrowDown = isDown;
}


bool blob::isRightButtonDown() const
{
    return rightArrowDown;
}
void blob::setRightButtonState(bool isDown)
{
    rightArrowDown = isDown;
}



blob::~blob()
{
    //dtor
}
