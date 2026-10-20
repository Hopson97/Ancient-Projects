#ifndef MODELMANAGER_H
#define MODELMANAGER_H

#include <map>
#include <vector>
#include <GL/glew.h>

enum ModelId
{
        MID_CUBE_VERTEX
};

enum IndexIds
{
    IID_CUBE_INDEX
};

class ModelManager
{
    public:
        ModelManager();
    private:
        void defineCube();
    private:
        std::map<ModelId, std::vector<GLfloat>>   mModels;
        std::map<ModelId, std::vector<GLuint>>   mIndices;
};

#endif // MODELMANAGER_H
