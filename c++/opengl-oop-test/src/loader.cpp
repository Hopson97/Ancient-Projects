#include "loader.h"

GLuint createVao()
{
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    return vao;
}

void addAttribPointer(const GLuint location, const GLuint dimensionPerVertex)
{
    glVertexAttribPointer(location, dimensionPerVertex, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(location);
}

std::shared_ptr<RawModel> loadRawModel(Shader& shader, const std::vector<float>& positions, const std::vector<GLuint>& indices)
{
    auto rawModel = std::make_shared<RawModel>();
    shader.useProgram();

    addBufferObject(rawModel->getBufferObjectList(), positions, GL_ARRAY_BUFFER);
    addAttribPointer(0, 3);

    addBufferObject(rawModel->getBufferObjectList(), indices, GL_ELEMENT_ARRAY_BUFFER);
    rawModel->setElementNumber(indices.size());


    shader.unuseProgram();
    glBindVertexArray(0);
    return rawModel;
}



