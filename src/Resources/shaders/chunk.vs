#version 440 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTex; // Texture coordinates

out vec2 texCoord; // Texture coordinates for fragment shader

uniform vec3 chunkpos; // Chunk position
uniform mat4 view; // Camera matrix

void main()
{
  texCoord = aTex; // Pass input texture coords to fragment shader
  // gl_Position = view * vec4(aPos, 1.0f);
  gl_Position = view * vec4(aPos + chunkpos, 1.0f);
}
