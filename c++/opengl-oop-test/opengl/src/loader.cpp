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

RawModel loadRawModel(Shader shader, const std::vector<float>& positions, const std::vector<GLuint>& indices)
{
    RawModel rawModel;
    rawModel.setShader(shader);
    shader.useProgram();

    addBufferObject(rawModel.getBufferObjectList(), positions, GL_ARRAY_BUFFER);
    addAttribPointer(0, 3);

    addBufferObject(rawModel.getBufferObjectList(), indices, GL_ELEMENT_ARRAY_BUFFER);
    rawModel.setElementNumber(indices.size());

    glBindVertexArray(0);
    return rawModel;
}



