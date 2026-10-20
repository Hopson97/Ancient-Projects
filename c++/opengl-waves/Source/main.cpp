#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <cmath>

#include <glad/glad.h>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <glm/fwd.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "shader.h"
#include "opengl_functions.h"

constexpr float WINDOW_HEIGHT = 800.0f;
constexpr float WINDOW_WIDTH  = 1300.0f;

constexpr float CUBE = 0.5f;
float vel = 0;

void input(glm::vec3& cameraPos, glm::vec3& cameraFront, glm::vec3& cameraUp, const float dt)
{
    float cameraSpeed = 5 * dt;
    bool keyDown = false;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
    {
        cameraPos += cameraSpeed * cameraFront;
        keyDown = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
    {
        cameraPos -= cameraSpeed * cameraFront;
        keyDown = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    {
        cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
        keyDown = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
        keyDown = true;
    }
    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) ||
        !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) ||
        !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) ||
        !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
    {
        keyDown = false;
    }
    if (!keyDown)
    {
    }
}

float currTime(const sf::Clock& c)
{
    return c.getElapsedTime().asSeconds();
}

GLfloat sinOfTime(const sf::Clock& c)
{
    return (GLfloat) (sin(c.getElapsedTime().asSeconds()));
}

int main()
{
    std::vector<GLuint> bufferObjectList;

    sf::ContextSettings context_settings;
    context_settings.depthBits = 24;
    context_settings.stencilBits = 8;
    context_settings.antiAliasingLevel = 4;
    context_settings.majorVersion = 4;
    context_settings.minorVersion = 6;
    context_settings.attributeFlags = sf::ContextSettings::Debug;

    sf::Window window(sf::VideoMode{{(int)WINDOW_WIDTH, (int)WINDOW_HEIGHT}},
                      "OpenGL Waves",
                      sf::Style::Default, sf::State::Windowed, context_settings);



    if (!gladLoadGL())
    {
        std::println(std::cerr, "Failed to initialise OpenGL - Is OpenGL linked correctly?");
        return EXIT_FAILURE;
    }


    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    Shader s("Source/vertex.glsl", "Source/fragment.glsl");

    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

/*
    std::vector<GLfloat> vertices =
    {

        -1.0f, -1.0f,  1.0f,
         1.0f, -1.0f,  1.0f,
         1.0f,  1.0f,  1.0f,
        -1.0f,  1.0f,  1.0f,
        -1.0f, -1.0f, -1.0f,
         1.0f, -1.0f, -1.0f,
         1.0f,  1.0f, -1.0f,
        -1.0f,  1.0f, -1.0f
    };
*/
    std::vector<GLfloat> vertices =
    {

        0.0f, 0.0f,  1.0f,
         1.0f, 0.0f,  1.0f,
         1.0f,  1.0f,  1.0f,
        0.0f,  1.0f,  1.0f,
        0.0f, 0.0f, 0.0f,
         1.0f, 0.0f, 0.0f,
         1.0f,  1.0f, 0.0f,
        0.0f,  1.0f, 0.0f
    };

    addBufferObject(bufferObjectList, vertices, GL_ARRAY_BUFFER);
    addAttribPointer(0, 3);

    std::vector<GLuint> indices =
    {
        0, 1, 2, 2, 3, 0,
        3, 2, 6, 6, 7, 3,
        7, 6, 5, 5, 4, 7,
        4, 0, 3, 3, 7, 4,
        0, 1, 5, 5, 4, 0,
        1, 5, 6, 6, 2, 1
    };
    addBufferObject(bufferObjectList, indices, GL_ELEMENT_ARRAY_BUFFER);

    std::vector<GLfloat> texCoords =
    {
        0.0f, 0.0f,
1.0f, 0.0f,
1.0f, 1.0f,
1.0f, 1.0f,
0.0f, 1.0f,
0.0f, 0.0f,

0.0f, 0.0f,
1.0f, 0.0f,
1.0f, 1.0f,
1.0f, 1.0f,
0.0f, 1.0f,
0.0f, 0.0f,

1.0f, 0.0f,
1.0f, 1.0f,
0.0f, 1.0f,
0.0f, 1.0f,
0.0f, 0.0f,
1.0f, 0.0f,

1.0f, 0.0f,
1.0f, 1.0f,
0.0f, 1.0f,
0.0f, 1.0f,
0.0f, 0.0f,
1.0f, 0.0f,

0.0f, 1.0f,
1.0f, 1.0f,
1.0f, 0.0f,
1.0f, 0.0f,
0.0f, 0.0f,
0.0f, 1.0f,

0.0f, 1.0f,
1.0f, 1.0f,
1.0f, 0.0f,
1.0f, 0.0f,
0.0f, 0.0f,
0.0f, 1.0f

    };
    GLuint texture = createTexture("water.png");
    addBufferObject(bufferObjectList, texCoords, GL_ARRAY_BUFFER);
    addAttribPointer(1, 2);

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    std::vector<glm::vec3> cubePos;
    float size = 35.0f;

    for(float x = -size; x < size; x++)
    {
        for(float z = size; z > -size; z--)
        {
            for(float y = 0; y < 1; y++)
            {


                cubePos.push_back(glm::vec3(x, -5 - y, z));
            }
        }
    }
    std::cout << cubePos.size() << std::endl;

    //glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
    sf::Clock c;
    sf::Clock dtClock;


    glm::vec3 cameraPos   = glm::vec3(0.0f, 30.0f,  55.0f);
    glm::vec3 cameraFront = glm::vec3(0.0f, -0.5f, -1.0f);
    glm::vec3 cameraUp    = glm::vec3(0.0f, 1.0f,  0.0f);

    while(window.isOpen())
    {
        float dt = dtClock.restart().asSeconds();
        glClearColor(0.2, 0.4, 0.75, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glBindTexture(GL_TEXTURE_2D, texture);
        glUseProgram(s.getProgramId());

        glm::mat4 view{1.0f};
        view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);

        input(cameraPos, cameraFront, cameraUp, dt);


        glm::mat4 projection{1.0f};
        projection = glm::perspective(90.0f, WINDOW_WIDTH/ WINDOW_WIDTH, 0.1f, 500.0f);

        GLint modelLoc = glGetUniformLocation(s.getProgramId(), "model");
        GLint viewLoc = glGetUniformLocation(s.getProgramId(), "view");
        GLint projLoc = glGetUniformLocation(s.getProgramId(), "projection");
        GLuint timeLoc = glGetUniformLocation(s.getProgramId(), "time");

        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
        glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

        glBindVertexArray(vao);

        for(auto cube : cubePos)
        {
            glUniform1f(timeLoc, currTime(c));

            glm::mat4 model{1.0f};
            glm::mat4 trans{1.0f};
            float y;

            // y = sinOfTime(c) * (2 * sin(cube.x * 100));

             //y = sin(currTime(c)  +  cube.x  / 2.0f);

            // y = sin(currTime(c) + (cube.x / 30.0f) + (cube.z / 5.0f));

             //y = 3 * sin(currTime(c) + (cube.x + (cube.z / 2)) / 3.50f);

             //y = 2.0f * (sin((currTime(c) + cube.x) / 4.0f) + cos((currTime(c) + cube.z) / 4.0f));

            float xP    = currTime(c) + cube.x;
            float yP    = currTime(c) + cube.z;
            float amp   = 0.26f;
            y     = amp * (sqrt(pow(xP, 2)+pow(yP, 2)) + 3*cos(sqrt(pow(xP, 2)+pow(yP, 2)))+5);


           // y = (pow( currTime(c) + cube.z, 2) * 2) + (pow( currTime(c)+ cube.x, 2) * 2);

            //y = amp * (sqrt(pow(xP, 2) + pow(yP, 2)) + 3 * cos(sqrt(pow(xP, 2) + pow(yP, 2))) + 5) +
            //    1.1f * (sin((currTime(c) + cube.x) / 4.0f) + cos((currTime(c) + cube.z) / 4.0f)) + 2;



            trans = glm::translate(trans, glm::vec3(            //Current one
                                                        0,
                                                        y,
                                                        0
                                                    ));

            glm::mat4 scale = glm::scale(scale, glm::vec3(0.5, 0.5, 0.5));

            model = glm::translate(model, cube);
            model = model * trans;




            glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
            glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
        }

        glBindVertexArray(0);
        window.display();


               //Show it

        while (auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }


    }

    for(auto bufferObject : bufferObjectList) {
        glDeleteBuffers(1, &bufferObject);
    }
    glDeleteVertexArrays(1, &vao);
    return 0;
}
