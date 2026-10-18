#include "game.h"

int main()
{
    srand(time(NULL));
    Game game;

    game.runLoop();

    return 0;
}
