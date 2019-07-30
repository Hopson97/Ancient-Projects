#ifndef PLAYER_H
#define PLAYER_H

#include "HopEngine/HopsonEngine.h"

class Player : public Entity
{
    public:
        Player();
        bool moveUp();
        float getYVel() const;
        void initPlay();

        void logic(sf::RenderWindow &w) override;
    protected:
    private:
        void input(sf::RenderWindow &window);

        void handleRotation(sf::RenderWindow &w);
        void handleTranslations(sf::RenderWindow &window);

        float yVel;
        float xVel;

};

#endif // PLAYER_H
