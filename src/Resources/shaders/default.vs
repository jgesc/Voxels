#version 440 core
layout (location = 0) in vec3 aPos;

out vec3 posColor;

uniform mat4 view;

void main()
{
  posColor = aPos;
  gl_Position = view * vec4(aPos.x, aPos.y, aPos.z, 1.0);
}
