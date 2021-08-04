#pragma once

// TODO: move to generic interface
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "../../Shaders/ShaderStore.hpp"

class Crosshair
{
private:
  GLuint VAO, VBO;
public:
  void render();
  Crosshair();
};
