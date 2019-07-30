#include "math.h"

#include <cmath>

Math::Math()
{
}

sf::Vector2f Math::normaliseVector(sf::Vector2f v1, sf::Vector2f v2)
{
    int dx = abs(v1.x - v2.x);
    int dy = abs(v1.y - v2.y);

    int length = sqrt((dy * dy) + (dx * dx));
    sf::Vector2f newVec((dx/length), (dy/length));

    return newVec;
}

int Math::randRange(int low, int high)	//Call this method for random numbers
{
	return rand() % (high - low + 1) + low;
}

int Math::vecAngle(sf::Vector2f v1, sf::Vector2f v2)
{
    int dx = (v1.x - v2.x);
    int dy = (v1.y - v2.y);

    float rot = (atan2(dy, dx)) * 180 / 3.14159;
    return rot;
}
