#include "comp_movetomouse.h"

#include "component.h"

Comp_MoveToMouse::Comp_MoveToMouse(sf::Sprite& _sprite,
                                   sf::RenderWindow& _window,
                                   bool controllable):
    sprite(_sprite),
    window(_window)
{
    sf::FloatRect s = this->sprite.getLocalBounds();

    this->sprite.setOrigin(s.width/2, s.height/2);
}

void Comp_MoveToMouse::logic()
{
    float dx;
    float dy;

    getMouseVector(dx, dy);
    lookAtMouse(dx, dy);
    moveToMouse(dx, dy);
}

void Comp_MoveToMouse::getMouseVector(float& dx, float& dy)
{
    sf::Vector2f player = this->sprite.getPosition();
    sf::Vector2f mouse = sf::Vector2f(sf::Mouse::getPosition(window));

    dx = (player.x - mouse.x);
    dy = (player.y - mouse.y);
}

void Comp_MoveToMouse::lookAtMouse(float dx, float dy)
{
    float rot = (atan2(dy, dx)) * (180 / 3.14159);
    this->sprite.setRotation(rot + 180);

}

void Comp_MoveToMouse::moveToMouse(float dx, float dy)
{

    if((abs(dx) < 5) && (abs(dy) < 5)) return;

    float length = sqrt((dx * dx) + (dy * dy));

    this->sprite.move(-(dx/ length * 5), -(dy/length * 5));
}









