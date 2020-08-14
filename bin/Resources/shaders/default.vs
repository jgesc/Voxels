#version 440 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTex;

out vec2 texCoord;

uniform mat4 view;

void main()
{
  texCoord = aTex;
  gl_Position = view * vec4(aPos.x, aPos.y, aPos.z, 1.0f);
}
