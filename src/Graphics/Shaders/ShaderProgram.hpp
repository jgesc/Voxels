#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <cstdio>

#include "Shader.hpp"

class ShaderProgram
{
private:
  GLuint id;
public:
  ShaderProgram();
  ShaderProgram(Shader * vertex, Shader * fragment);
  // Use shader program
  inline void use() {glUseProgram(this->id);}
  // Modify uniforms
  void setBool(const std::string &name, bool value) const
    {glUniform1i(glGetUniformLocation(this->id, name.c_str()), (int)value);}
  void setInt(const std::string &name, int value) const
    {glUniform1i(glGetUniformLocation(this->id, name.c_str()), value);}
  void setFloat(const std::string &name, float value) const
    {glUniform1f(glGetUniformLocation(this->id, name.c_str()), value);}
  void setMat4(const std::string &name, glm::mat4 value) const
    {glUniformMatrix4fv(glGetUniformLocation(this->id, name.c_str()),
      1, GL_FALSE, glm::value_ptr(value));}
};
