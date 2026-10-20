#ifndef ENTITY_H
#define ENTITY_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Entity
{
    public:
        Entity();

                void    setRotation (float x, float y, float z);
                void    setPosition (float x, float y, float z);
    protected:
                void    doTransformations   (glm::mat4& modelMatrix);

    private:
        float   xRot,
                yRot,
                zRot;

        float   xPos,
                yPos,
                zPos;
};

#endif // ENTITY_H
