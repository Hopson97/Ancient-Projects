#ifndef RANDOM_H
#define RANDOM_H
#include <ctime>
#include <cstdlib>


class random
{
    public:
        random();
        int randRange(int low, int high);
        float randRange(float low, float high);
        virtual ~random();
    protected:
    private:
};

#endif // RANDOM_H
