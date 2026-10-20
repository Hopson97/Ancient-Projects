#include "rawmodel.h"

#include <iostream>

#include "loader.h"

RawModel::RawModel()
{
    mVao = createVao();
}

RawModel::~RawModel()
{
    for (auto bufferObject : mBufferObjectList) {
        glDeleteBuffers(1, &bufferObject);
    }
    glDeleteVertexArrays(1, &mVao);
}

std::vector<GLuint>& RawModel::getBufferObjectList()
{
    return mBufferObjectList;
}

void RawModel::draw(const float time)
{
    glBindVertexArray(mVao);

    glDrawElements(GL_TRIANGLES, numElements, GL_UNSIGNED_INT, 0);

    glBindVertexArray(0);
}
