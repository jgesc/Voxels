#version 440 core
layout (location = 0) in vec3 aPos;

uniform vec3 chunkpos; // Chunk position
uniform mat4 viewmat; // Camera matrix

void main()
{
    gl_Position = viewmat * vec4(aPos + chunkpos, 1.0f);
}
