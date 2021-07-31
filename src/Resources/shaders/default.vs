#version 440 core
layout (location = 0) in vec3 aPos; // Vertex position
layout (location = 1) in vec2 aTex; // Texture coordinates

out vec2 texCoord; // Texture coordinates for fragment shader

uniform mat4 view; // View matrix (used for camera)

void main()
{
  texCoord = aTex; // Pass input texture coords to fragment shader
  gl_Position = view * vec4(aPos.x, aPos.y, aPos.z, 1.0f);
}
