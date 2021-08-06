#version 330 core

in vec2 texCoord;
out vec4 FragColor;

uniform sampler2D fontAtlas;

void main()
{
  // TODO: support for text coloring
  FragColor = vec4(texture(fontAtlas, texCoord).r);
  if(FragColor.a < 0.1)
    discard;
}
