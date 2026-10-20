#include "rawmodel.h"

#include <iostream>

#include "loader.h"

RawModel::RawModel()
{
    std::cout << "VAO made for raw model." << std::endl;
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

void RawModel::draw()
{
    glBindVertexArray(mVao);
    mShader.useProgram();
    std::cout << mBufferObjectList.size() << std::endl;
    std::cout << numElements << std::endl;
    glDrawElements(GL_TRIANGLES, numElements, GL_UNSIGNED_INT, 0);
    //glDrawArrays(GL_TRIANGLES, 0, 3);

    mShader.unuseProgram();
    glBindVertexArray(0);

}


