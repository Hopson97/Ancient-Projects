#ifndef PLAYER_H
#define PLAYER_H


#include "entity.h"
#include "comp_movetomouse.h"

class Player : public Entity
{
    public:
        Player(sf::Texture t, sf::RenderWindow &window);
    protected:
    private:
};

#endif // PLAYER_H
