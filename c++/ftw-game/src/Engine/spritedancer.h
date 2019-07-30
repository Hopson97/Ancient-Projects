#ifndef SPRITEDANCER_H
#define SPRITEDANCER_H

#include <SFML/Graphics.hpp>

#include "../Utilities/random.h"

class SpriteDancer
{
    public:
        void            dance           (const float& dt, sf::Sprite& sprite);



    private:

        sf::Color      newColour       (const sf::Sprite& _sprite);
        void           changeColour    (int& colour, bool& isAdding);



        bool        isRedAdded      { (bool)   rng ::num( 0, 1 )  };
        bool        isGreenAdded    { (bool)   rng ::num( 0, 1 )  };
        bool        isBlueAdded     { (bool)   rng ::num( 0, 1 )  };
        double      danceCount      { (double) rng ::num(0, 5000) };

};

#endif // SPRITEDANCER_H
