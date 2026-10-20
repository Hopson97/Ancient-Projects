#include "modelmanager.h"

ModelManager::ModelManager()
{

}

void ModelManager::defineCube()
{
    std::vector<GLfloat> vertices =
    {

       -0.5f, -0.5f,  0.5f,
        0.5f, -0.5f,  0.5f,
        0.5f, 0.5f,  0.5f,
        -0.5f, 0.5f,  0.5f,
        -0.5f, -0.5f,  -0.5f,
        0.5f, -0.5f,  -0.5f,
        0.5f, 0.5f,  -0.5f,
        -0.5f, 0.5f,  -0.5f
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

}
