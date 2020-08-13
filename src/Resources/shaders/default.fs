#version 330 core

in vec3 posColor;
out vec4 FragColor;

void main()
{
    FragColor = vec4(mod(posColor, 1.0), 1.0);
}
