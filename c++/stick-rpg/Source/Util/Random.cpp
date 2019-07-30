#include "Random.h"

#include <ctime>

Random& Random::get()
{
    static Random r;
    return r;
}

int Random::intInRange(int low, int high)
{
    std::uniform_int_distribution<int> dist(low, high);
    return dist(m_randomNumberEngine);
}

float Random::floatInRange(float low, float high)
{
    std::uniform_real_distribution<float> dist(low, high);
    return dist(m_randomNumberEngine);
}

Random::Random()
{
    m_randomNumberEngine.seed(std::time(nullptr));

    for (int i = 0; i < 10; i++)
    {
        intInRange(0, i * floatInRange(i, i * 2));
    }
}
