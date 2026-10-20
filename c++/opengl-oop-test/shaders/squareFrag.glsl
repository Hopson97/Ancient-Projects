#version 330 core

in float dist;

out vec4 outColour;

void main()
{
    float col = dist / 100;
    outColour = vec4(col, 0, 0, 1);
    //outColour = vec4(1, 0, 0, 1);
}

