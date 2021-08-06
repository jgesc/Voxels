#version 440 core
layout (location = 0) in vec2 aPos;
layout (location = 1) in vec2 aTex;

out vec2 texCoord; // Texture coordinates for fragment shader

uniform float depth; // View matrix (used for camera)

void main()
{
  texCoord = aTex; // Pass input texture coords to fragment shader
  gl_Position = vec4(aPos, depth, 1.0f);
}
