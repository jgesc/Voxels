#pragma once

#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdio>
#include "../../ResourceManager.hpp"
#include "../../Debugging/Logger.hpp"

using std::string;

class Shader
{
private:
  GLuint id;
  GLenum type;
public:
  // Constructors
  Shader(GLenum type, string path);
  Shader(string path);
  // Destructors
  ~Shader();

  // Getters
  inline GLuint getId() {return this->id;}
};
