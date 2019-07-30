#ifndef STATS_H_INCLUDED
#define STATS_H_INCLUDED

struct Levels
{
    int intelligence;
    int charm;
    int strength;

    void reset()
    {
        intelligence = 0;
        charm = 0;
        strength = 0;
    }
};

struct Stats
{
    Levels levels;

    int health = 100;
    int engery = 100;
};

#endif // STATS_H_INCLUDED
