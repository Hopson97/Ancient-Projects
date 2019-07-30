#include "random.h"

#include <ctime>
#include <cstdlib>
#include <cmath>
#include "../Engine/constants.h"

namespace rng 
{


/*****************************************************************************************************************************************************************
*   rng ::num() returns a rng  number between param 1 and param 2
*   param1  :   The lower bound of the rng  number to be returned
*   param2  :   The upper bound of the rng  number to be returned
**************************************************************************************************************************************************************/
int num(int low, int high)
{
	return (rand() % (high - low + 1) + low); //Sorry, I don't like C++11 rng ...
}

/*****************************************************************************************************************************************************************
*   rng ::colour()    returns a RBG rng  colour
***************************************************************************************************************************************************************/
sf::Color colour()
{
    return sf::Color(
                     num(0, 255),
                     num(0, 255),
                     num(0, 255)
                     );
}

sf::Vector2f position()
{
    return sf::Vector2f (
                         num(0, win::WIDTH),
                         num(0, win::HEIGHT)
                         );
}

}//namespace rand
