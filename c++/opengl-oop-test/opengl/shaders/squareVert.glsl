#version 330 core

layout (location = 0 ) in vec3 inPositions;

//out float currtime;

//uniform mat4 model;
//uniform mat4 view;
//uniform mat4 projection;

//uniform float time;

void main()
{

    //gl_Position = projection * view * model * vec4(inPositions, 1.0f);

    gl_Position = vec4(inPositions, 1.0f);

    //gl_Position = vec4(sin(inPositions.x * time + inPositions.y),inPositions.y,inPositions.z,1);


    //currtime = time;
}

