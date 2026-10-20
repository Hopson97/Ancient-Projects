#ifndef RAWMODEL_H
#define RAWMODEL_H

#include <GL/glew.h>
#include <vector>

#include "shader.h"

class RawModel
{
    public:
        RawModel();
        ~RawModel();

        void draw();

        std::vector<GLuint>&    getBufferObjectList();

        void                    setShader(Shader shader)    { mShader = shader; }
        void                    setElementNumber(int n)     { numElements = n; };

    private:
        std::vector<GLuint> mBufferObjectList;
        GLuint mVao;
        Shader mShader;

        int numElements;
};

#endif // RAWMODEL_H
