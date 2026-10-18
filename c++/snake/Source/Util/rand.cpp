#include "rand.h"
namespace Random
{

int
integer (int low, int high)	//Call this method f
{
	return rand() % (high - low + 1) + low;
}

double
decimal  ( const double low, const double high)
{
    int accuracy = 1000;

    int newHigh  = high * accuracy;
    int newLow   = low * accuracy;

    int randomNum = integer( newLow, newHigh );

    return randomNum / accuracy;
}

}
