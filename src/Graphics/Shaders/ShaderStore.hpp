#pragma once

#include "ShaderProgram.hpp"

class ShaderStore
{
public:
  ShaderProgram defaultShader;

  static ShaderStore * I;
  // Initialize
  static void initialize();
private:
  static bool isInitialized;
  ShaderStore();
};
