#pragma once

#include "Shader.hpp"

#include <cstdio>

class ShaderProgram
{
private:
  GLuint id;
public:
  ShaderProgram();
  ShaderProgram(Shader * vertex, Shader * fragment);
  // Use shader program
  inline void use() {glUseProgram(this->id);}
};
