#include "glewinitiliser.h"

#include "GL/glew.h"

glewInitiliser::glewInitiliser()
{
    glewExperimental = GL_TRUE;
    GLenum error = glewInit();
}
