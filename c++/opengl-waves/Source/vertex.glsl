#version 330 core

layout (location = 0) in vec3 position; // The position variable has attribute position 0
layout (location = 1) in vec2 texCoord;

out vec3 ourColour;
out vec2 _texCoord;
out float zPos;

//uniform mat4 transform;
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

uniform float time;

void main()
{



    gl_Position = projection * view * model * vec4(position, 1.0f);

    zPos = gl_Position.z;

    _texCoord = texCoord;
}
