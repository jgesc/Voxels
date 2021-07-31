#pragma once

#include "ShaderProgram.hpp"

class ShaderStore
{
public:
  // Shader list BEGIN
  ShaderProgram defaultShader;
  ShaderProgram chunkShader;
  // Shader list END

  static ShaderStore * I;
  // Initialize
  static void initialize();
private:
  static bool isInitialized;
  ShaderStore();
};
