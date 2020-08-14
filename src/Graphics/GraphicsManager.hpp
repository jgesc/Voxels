#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "Shaders/ShaderStore.hpp"
#include "Textures/TextureStore.hpp"

class GraphicsManager
{
public:
  static GLFWwindow * window;

  // Initialize graphics
  static void initialize();
  // Terminate graphics
  static void terminate();
private:
  GraphicsManager() {}
};
