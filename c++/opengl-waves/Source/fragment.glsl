#version 330 core

in vec2 _texCoord;
in float zPos;

out vec4 colour;

uniform sampler2D ourTexture;




void main()
{

    colour = texture(ourTexture,  _texCoord);

    float c = zPos / 90;
    colour = vec4(0, c, c, 1);

    colour = texture(ourTexture,  _texCoord) * vec4(0, c, c, 1);
    colour = texture(ourTexture,  _texCoord) * vec4(0, c * 2, c * 4, 1);
}
