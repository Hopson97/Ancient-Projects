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

        void draw(const float time);

        std::vector<GLuint>&    getBufferObjectList ();

        void                    setElementNumber    (int n)     { numElements = n; };

    private:
        std::vector<GLuint> mBufferObjectList;
        GLuint mVao;

        int numElements;

        float xRot, yRot, zRot;
};

#endif // RAWMODEL_H
