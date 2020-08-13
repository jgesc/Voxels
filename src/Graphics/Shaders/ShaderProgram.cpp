#include "ShaderProgram.hpp"

ShaderProgram::ShaderProgram(Shader * vertex, Shader * fragment)
{
  // Allocate shader program
  this->id = glCreateProgram();
  glUseProgram(this->id);

  // Attach shaders and link
  glAttachShader(this->id, vertex->getId());
  glAttachShader(this->id, fragment->getId());
  glLinkProgram(this->id);

  // Check for errors
  int success;
  glGetProgramiv(this->id, GL_LINK_STATUS, &success);
  if(!success)
  {
      char log[512];
      glGetProgramInfoLog(this->id, 512, NULL, log);
      std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << log << std::endl;
  }
}

ShaderProgram::ShaderProgram() {}
