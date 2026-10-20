#version 330 core

layout (location = 0 ) in vec3 inPositions;

out float dist;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

uniform float time;

void main()
{

    //gl_Position = projection * view * model * vec4(inPositions.x, sin(time * inPositions.y), inPositions.z, 1.0f);
    gl_Position =   projection * view * model * vec4(inPositions, 1.0f);
    dist = gl_Position.z;

}

