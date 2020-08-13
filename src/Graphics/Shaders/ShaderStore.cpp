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

ShaderProgram makeShaderProgram(string vsname, string fsname)
{
  // Create shaders
  string vspath = "shaders/" + vsname;
  string fspath = "shaders/" + fsname;
  Shader vs = Shader(GL_VERTEX_SHADER, vspath);
  Shader fs = Shader(GL_FRAGMENT_SHADER, fspath);
  ShaderProgram sp(&vs, &fs);

  return sp;
}

ShaderStore::ShaderStore()
{
  // Create shaders
  makeShaderProgram("default.vs", "default.fs");
}
