#ifndef SQUARESHADER_H
#define SQUARESHADER_H

#include "shader.h"


class SquareShader : public Shader
{
    public:
        SquareShader(const std::string& vertexFilePath, const std::string& fragmentFilePath);


        void    loadTime               (float time);
        void    loadModelMatrix        (const glm::mat4& modelMatrix);
        void    loadViewMatrix         (const glm::mat4& viewMatrix);
        void    loadProjectionMatrix   (const glm::mat4& projectionMatrix);

    private:
        GLuint  timeLocation;
        GLuint  modelLocation;
        GLuint  viewLocation;
        GLuint  projLocation;

    private:
        void    getUniformLocations     () override;
};

#endif // SQUARESHADER_H
