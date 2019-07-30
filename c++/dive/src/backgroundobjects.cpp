#include "backgroundobjects.h"

BackgroundObjects::BackgroundObjects()
{
    //ctor
}

void BackgroundObjects::logic(sf::RenderWindow &window, bool flying, float speed)
{
    if(flying)
        this->sprite.move(this->xSpeed/10, (speed/2)*this->sprite.getScale().x);
    else
        this->sprite.move(xSpeed/10, 0);

    this->checkForReset(flying);
    if(!flying)
        this->sprite.setScale((xSpeed)/8, (xSpeed)/8);
    else if(flying)
        this->sprite.setScale((xSpeed)/15, (xSpeed)/15);

    window.draw(this->sprite);
}

void BackgroundObjects::reset(bool flying)
{
     Math m;
     this->direction = m.randRange(0, 1);
     if(!flying)
     {
        if(direction == 0) //left
        {
            this->sprite.setPosition(gbl::WIN_WIDTH, m.randRange(maxHeight, minHeight));
            this->setSpeed(float(m.randRange(-10, -24)));
        }
        else if(direction == 1) //right
        {
            this->sprite.setPosition(-200, m.randRange(maxHeight, minHeight));
            this->setSpeed(float(m.randRange(5, 12)));
        }
     }
     else if(flying)
     {
        this->sprite.setPosition(m.randRange(0, gbl::WIN_WIDTH - 100), -50);
        this->setSpeed(float(m.randRange(5, 12)));
     }
}

void BackgroundObjects::setSpeed(float s)
{
    xSpeed = s;
}

 void BackgroundObjects::checkForReset(bool flying)
 {
    if(!flying)
    {
        if(direction == 1 )
        {
            if(this->sprite.getPosition().x > gbl::WIN_WIDTH + 150)
            {
                this->reset(flying);
            }
        }
        else if(direction == 0)
        {
            if(this->sprite.getPosition().x < -150)
            {
                this->reset(flying);
            }
        }
    }
    else if(flying)
    {
        if(this->sprite.getPosition().y > gbl::WIN_HEIGHT)
        {
            this->reset(flying);
        }
    }
 }
