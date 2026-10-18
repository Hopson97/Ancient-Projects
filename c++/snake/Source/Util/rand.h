#ifndef RANDOM_H_INCLUDED
#define RANDOM_H_INCLUDED

#include <ctime>
#include <cstdlib>

namespace Random
{

    int integer     ( const int low, const int high);

    double decimal  ( const double low, const double high);

}

#endif // RANDOM_H_INCLUDED
