#include "squareshader.h"

SquareShader::SquareShader(const std::string& vertexFilePath, const std::string& fragmentFilePath)
:   Shader(vertexFilePath, fragmentFilePath)
{
    getUniformLocations();
}

void SquareShader::getUniformLocations()
{
    timeLocation = glGetUniformLocation(getProgramId(), "time");
    modelLocation = glGetUniformLocation(getProgramId(), "model");
    viewLocation = glGetUniformLocation(getProgramId(), "view");
    projLocation = glGetUniformLocation(getProgramId(), "projection");
}

void SquareShader::loadTime(float time)
{
    loadUniformFloat(timeLocation, time);
}

void SquareShader::loadModelMatrix(const glm::mat4& modelMatrix)
{
    loadUniformMatrix(modelLocation, modelMatrix);
}

void SquareShader::loadViewMatrix(const glm::mat4& viewMatrix)
{
    loadUniformMatrix(viewLocation, viewMatrix);
}

void SquareShader::loadProjectionMatrix(const glm::mat4& projectionMatrix)
{
    loadUniformMatrix(projLocation, projectionMatrix);
}
