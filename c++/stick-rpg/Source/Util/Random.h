#ifndef RANDOM_H_INCLUDED
#define RANDOM_H_INCLUDED

#include <random>

class Random
{
    public:
        static Random& get();

        int     intInRange      (int low, int high);
        float   floatInRange    (float low, float high);

    private:
        Random();

        std::mt19937 m_randomNumberEngine;
};


#endif // RANDOM_H_INCLUDED
