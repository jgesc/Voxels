#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "Shaders/ShaderStore.hpp"
#include "Textures/TextureStore.hpp"

#define DEFAULT_WINDOW_WIDTH 800
#define DEFAULT_WINDOW_HEIGHT 600

class GraphicsManager
{
public:
  static GLFWwindow * window;

  // Initialize graphics
  static void initialize();
  // Terminate graphics
  static void terminate();

  // Window properties
  static int getWindowWidth() {return windowWidth;};
  static int getWindowHeight() {return windowHeight;};

private:
  GraphicsManager() {}
  static int fullScreenWindow;
  static int windowWidth;
  static int windowHeight;
};
