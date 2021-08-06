#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "../../Shaders/ShaderStore.hpp"
#include "../../Textures/TextureStore.hpp"

#include "../../Text.hpp"

class InterfaceText
{
private:
  GLuint VAO, VBO;
  GLuint vertexCount;
  Text text;
public:
  InterfaceText(Text text);
  void render();
};
