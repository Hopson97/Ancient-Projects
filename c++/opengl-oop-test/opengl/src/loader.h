#ifndef LOADER_H_INCLUDED
#define LOADER_H_INCLUDED

#include <GL/glew.h>
#include <vector>

#include "rawmodel.h"

GLuint      createVao();
void        addAttribPointer(const GLuint location, const GLuint dimensionPerVertex);


RawModel loadRawModel(Shader shader, const std::vector<float>& positions, const std::vector<GLuint>& indices);

template<class t>
void addBufferObject(std::vector<GLuint>& bufferObjectList, const std::vector<t>& data, const GLenum bufferObjectType)
{
    GLuint bufferObject;
    glGenBuffers(1, &bufferObject);
    glBindBuffer(bufferObjectType, bufferObject);
    glBufferData(bufferObjectType, sizeof(t) * data.size(), data.data(), GL_STATIC_DRAW);
    bufferObjectList.push_back(bufferObject);
}

#endif // LOADER_H_INCLUDED
