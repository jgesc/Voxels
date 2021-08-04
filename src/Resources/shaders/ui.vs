#version 440 core
layout (location = 0) in vec2 aPos;

uniform float depth; // View matrix (used for camera)

void main()
{
  gl_Position = vec4(aPos, depth, 1.0f);
}
