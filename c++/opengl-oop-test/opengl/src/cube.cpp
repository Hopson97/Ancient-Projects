#include "cube.h"

#include "loader.h"
#include "squareshader.h"

Cube::Cube()
{
    std::vector<GLfloat> vertices =
    {

        0.0f, 0.0f,  1.0f,
         1.0f, 0.0f,  1.0f,
         1.0f,  1.0f,  1.0f,
        0.0f,  1.0f,  1.0f,
        0.0f, 0.0f, 0.0f,
         1.0f, 0.0f, 0.0f,
         1.0f,  1.0f, 0.0f,
        0.0f,  1.0f, 0.0f
    };

    std::vector<GLuint> indices =
    {
        0, 1, 2, 2, 3, 0,
        3, 2, 6, 6, 7, 3,
        7, 6, 5, 5, 4, 7,
        4, 0, 3, 3, 7, 4,
        0, 1, 5, 5, 4, 0,
        1, 5, 6, 6, 2, 1
    };
    cubeModel = loadRawModel(SquareShader("shaders/squareVert.glsl", "shaders/squareFrag.glsl"), vertices, indices);
}

void Cube::draw()
{
    cubeModel.draw();
}
