#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>

#include <SFML/OpenGL.hpp>
#include <string>

class Shader
{
    public:
        Shader(const std::string& vertexFilePath, const std::string& fragmentFilePath);
        ~Shader();

        inline GLuint getProgramId() const { return programId; }


    private:
        GLuint programId;
        GLuint vertexShaderId;
        GLuint fragmentShaderId;
    private:
        std::string     readShaderFile(const std::string filePath);
        void            giveToOpenGl(GLuint& id, std::string& source);
        bool            isError(GLuint& id);




};

#endif // SHADER_H
