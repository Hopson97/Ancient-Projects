#include "random.h"

random::random()
{
    //ctor
}

int random::randRange(int low, int high)
{
     return rand() % (high - low + 1) + low;
}


random::~random()
{
    //dtor
}
