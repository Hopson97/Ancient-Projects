#include <iostream>
#include "game.h"

/*
This is a test to use components to define the logic of objects
*/

using namespace std;

int main()
{
    try
    {
        Game startGame;
    }
    catch(std::exception e)
    {
        e.what();
    }
    return 0;
}
