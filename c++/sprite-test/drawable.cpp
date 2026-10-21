#include "drawable.h"

Drawable::Drawable()
{

}
void Drawable::logic()
{

}

void Drawable::update()
{

}

void Drawable::setSprite()
{
    std::string filePath = "resources/images/"
                            + getFolder()
                            + "/"
                            + getName()
                            + ".png";

    std::cout << filePath << std::endl;
    texture.loadFromFile(filePath);
    sprite.setTexture(texture);
}

void Drawable::render(sf::RenderWindow &window)
{
    logic();
    window.draw(sprite);
}

float Drawable::getXPos()
{
    return sprite.getPosition().x;
}

float Drawable::getYPos()
{
    return sprite.getPosition().y;
}



std::string Drawable::getName() const
{
    return name;
}

std::string Drawable::getFolder() const
{
    return folder;
}



Drawable::~Drawable()
{
    //dtor
}
