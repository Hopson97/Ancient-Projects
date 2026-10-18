#include "player.h"

Player::Player(sf::Texture t, sf::RenderWindow &window)
{
    this->texture = t;
    sprite.setTexture(texture);

    std::unique_ptr<Comp_MoveToMouse> mtm(new Comp_MoveToMouse(sprite, window));
    this->components.push_back(std::move(mtm));
}
