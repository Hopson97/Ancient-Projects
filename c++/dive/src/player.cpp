#include "player.h"

Player::Player()
{
    std::string path = "res/rocketShip2.png";
    if(!this->texture.loadFromFile(path));

    this->sprite.setTexture(texture);
    this->texture.setSmooth(true);
    this->sprite.setPosition(180, gbl::WIN_HEIGHT - 98);
    this->sprite.setScale(0.91, 1);
    this->sprite.setRotation(-90);
    this->yVel = 0.3;
}

void Player::logic(sf::RenderWindow &window)
{
    input(window);
    this->sprite.move(xVel, 0);
    window.draw(this->sprite);
}

void Player::input(sf::RenderWindow &window)
{
    this->handleRotation(window);
    this->handleTranslations(window);

    if(this->sprite.getPosition().x < -50)
    {
        this->sprite.setPosition(-45, this->sprite.getPosition().y);
        this->xVel = 2;
    }
    else if(this->sprite.getPosition().x > gbl::WIN_WIDTH + 50)
    {
        this->sprite.setPosition(gbl::WIN_WIDTH + 45, this->sprite.getPosition().y);
        this->xVel = -2;
    }

}

void Player::handleRotation(sf::RenderWindow &window)
{
    if(sf::Mouse::getPosition().y < this->sprite.getPosition().y + 90)
    {
        Math m;
        float rotation = m.vecAngle(this->sprite.getPosition(), sf::Vector2f(sf::Mouse::getPosition(window)));
        this->sprite.setRotation(rotation + 180);

        if(this->sprite.getRotation() > 270 + 60 )
            this->sprite.setRotation(270 + 59);
        else if(this->sprite.getRotation() < 270 - 60)
            this->sprite.setRotation(270 - 59);
    }
}

void Player::handleTranslations(sf::RenderWindow &window)
{
    int playerX = this->sprite.getPosition().x;
    int mouseX = sf::Mouse::getPosition(window).x;

    if((playerX > mouseX + 30) && (playerX < mouseX - 30))
    {
        xVel = 0;
    }
    else
    {
        if(mouseX < playerX)
        {
            xVel -= 0.1;
        }
        else if(mouseX > playerX)
        {
            xVel += 0.1;
        }
    }
}


bool Player::moveUp()
{
    this->yVel *= 1.01;
    this->sprite.move(0, -yVel);
    if(this->sprite.getPosition().y < 447)
        return true;
    else return false;
}

float Player::getYVel() const
{
    return yVel;
}



void Player::initPlay()
{
    this->sprite.setRotation(0);
    this->sprite.setOrigin(228,115);
    this->sprite.setPosition(gbl::WIN_WIDTH/2 - 115, 500);
    this->sprite.setScale(0.3,0.3);
}
