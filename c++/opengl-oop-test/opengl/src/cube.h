#ifndef CUBE_H
#define CUBE_H

#include "rawmodel.h"

class Cube
{
    public:
        Cube();

        void draw();

    private:
        RawModel cubeModel;
};

#endif // CUBE_H
