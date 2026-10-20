#include "entity.h"

Entity::Entity()
:   xRot(0)
,   yRot(0)
,   zRot(0)

,   xPos(0)
,   yPos(0)
,   zPos(0)
{

}

void Entity::setRotation(float x, float y, float z)
{
    xRot    =   x;
    yRot    =   y;
    zRot    =   z;
}

void Entity::setPosition(float x, float y, float z)
{
    xPos    =   x;
    yPos    =   y;
    zPos    =   z;
}

void Entity::doTransformations(glm::mat4& modelMatrix)
{
    modelMatrix = glm::translate(modelMatrix,   glm::vec3(xPos, yPos, zPos));

    modelMatrix = glm::rotate(modelMatrix,      glm::radians(zRot), glm::vec3(0, 0, 1));
    modelMatrix = glm::rotate(modelMatrix,      glm::radians(yRot), glm::vec3(0, 1, 0));
    modelMatrix = glm::rotate(modelMatrix,      glm::radians(xRot), glm::vec3(1, 0, 0));
}


