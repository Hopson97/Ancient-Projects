#ifndef CUBE_H
#define CUBE_H

#include "rawmodel.h"
#include "squareshader.h"
#include "../entity.h"

#include <memory>

class Cube : public Entity
{
    public:
        Cube(SquareShader& shader);
        Cube(float xPos, float yPos, float zPos, SquareShader& shader);

        void draw(SquareShader& shader, const float time);

    private:
        void constructCube(SquareShader& shader);


    private:
        std::shared_ptr<RawModel> cubeModel;
};

#endif // CUBE_H
