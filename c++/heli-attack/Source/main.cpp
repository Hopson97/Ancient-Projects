#include "game.h"

#include "Util/rand.h"
#include <iostream>
#include <SFML/Audio/Sound.hpp>

/**

To do:
    -> Both the Entity and Particle class have the OOB collision detection.
        So we need something to avoid the DRY here!

    -> Serious need of re-factoring needed in the "Gravity Particles" class!

    ->  Glitch, particles appear inside tiles when bullets hit them




*/

int main()
{
    srand (time(NULL));

    Game game;
    game.runLoop();
    return 0;
}
