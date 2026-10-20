#ifndef OPENGL_FUNCTIONS_H_INCLUDED
#define OPENGL_FUNCTIONS_H_INCLUDED

#include <vector>
#include <iostream>

#include <SFML/Graphics.hpp>

#include <glad/glad.h>

template<typename t>
void addBufferObject(std::vector<GLuint>& bufferObjectList, const std::vector<t>& data, const GLenum BUFFER_TYPE)
{
    GLuint bufferObject;
    glGenBuffers(1, &bufferObject);

    glBindBuffer(BUFFER_TYPE, bufferObject);
    glBufferData(BUFFER_TYPE, sizeof(t) * data.size(),
                 data.data(), GL_STATIC_DRAW);

    bufferObjectList.push_back(bufferObject);
}

void addAttribPointer(GLuint location, GLuint dimensionPerVertex)
{
    glVertexAttribPointer(location, dimensionPerVertex, GL_FLOAT, GL_FALSE, 0, (GLvoid*)0); //well, im not sure anymore
    glEnableVertexAttribArray(location);
}

GLuint createTexture(const std::string& texturePath)
{
    sf::Image image;
    image.loadFromFile(texturePath);
    image.flipVertically();

    GLuint texturevbo;
    glGenTextures(1, &texturevbo);
    glBindTexture(GL_TEXTURE_2D, texturevbo);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.getSize().x, image.getSize().y, 0, GL_RGBA, GL_UNSIGNED_BYTE, image.getPixelsPtr());

    glGenerateMipmap(GL_TEXTURE_2D);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

    glBindTexture(GL_TEXTURE_2D, 0);

    return texturevbo;
}

#endif // OPENGL_FUNCTIONS_H_INCLUDED//umm, can i try something? go for it
