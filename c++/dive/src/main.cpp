#include <iostream>

#include "game.h"

using namespace std;

int main()
{
    srand(time(NULL));

    try{
        Game game;
    }
    catch(exception e){
        e.what();
    }

    return 0;
}
