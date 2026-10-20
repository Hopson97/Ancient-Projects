#include "cube.h"

#include "loader.h"
#include "squareshader.h"

Cube::Cube(SquareShader& shader)
{
    constructCube(shader);
}

Cube::Cube(float xPos, float yPos, float zPos, SquareShader& shader)
{
    constructCube(shader);
    setPosition(xPos, yPos, zPos);
}

void Cube::constructCube(SquareShader& shader)
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
    cubeModel = loadRawModel(shader, vertices, indices);
}

void Cube::draw(SquareShader& shader, float time)
{
    shader.useProgram();
    shader.loadTime(time);

    glm::mat4 model;
    glm::mat4 view;
    glm::mat4 proj;

    doTransformations(model);


    view = glm::translate(view, glm::vec3(0.0f, -10.0f, -10));
    proj = glm::perspective(45.0f, 1280.0f / 700.0f, 0.1f, 100.0f);

    shader.loadModelMatrix(model);
    shader.loadViewMatrix(view);
    shader.loadProjectionMatrix(proj);

    cubeModel->draw(time);
    shader.unuseProgram();
}
