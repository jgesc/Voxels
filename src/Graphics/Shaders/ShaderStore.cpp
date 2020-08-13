#include "ShaderStore.hpp"

bool ShaderStore::isInitialized = false;
ShaderStore * ShaderStore::I = NULL;

void ShaderStore::initialize()
{
  // Check if is already initialized
  if(ShaderStore::isInitialized) return;
  ShaderStore::isInitialized = true;

  ShaderStore::I = new ShaderStore();
}

ShaderProgram makeShaderProgram(string vs, string fs)
{
  // Create shaders
  Shader defaultVShader = Shader(GL_VERTEX_SHADER, vs);
  Shader defaultFShader = Shader(GL_FRAGMENT_SHADER, fs);
  ShaderProgram sp(&defaultVShader, &defaultFShader);

  return sp;
}

ShaderStore::ShaderStore()
{
  // Create shaders
  
}
