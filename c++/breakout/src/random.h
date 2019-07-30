#ifndef RANDOM_H
#define RANDOM_H

#include <ctime>
#include <cstdlib>

class Random
{
    public:
        Random();
        int randRange(int low, int high)	//Call this method for random numbers
        {
            return rand() % (high - low + 1) + low;
        }
    protected:
    private:
};

#endif // RANDOM_H
