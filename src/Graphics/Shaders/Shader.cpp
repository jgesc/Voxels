#include "Shader.hpp"

using namespace std;

Shader::Shader(GLenum type, string path)
{
  // Load shader source
  const char * source;
  std::ifstream sourceFile = ResourceManager::getResourceStream(path);
  std::stringstream sourceStream;
  std::string sourceString;
  sourceStream << sourceFile.rdbuf();
  sourceFile.close();
  sourceString = sourceStream.str();
  source = sourceString.data();
  delete sourceFile;

  // Store type and ID
  this->id = glCreateShader(type);

  // Compile shader
  glShaderSource(this->id, 1, &source, NULL);
  int success;
  char log[512];
  glCompileShader(this->id);

  // Print errors
  glGetShaderiv(this->id, GL_COMPILE_STATUS, &success);
  if(!success)
  {
      glGetShaderInfoLog(this->id, 512, NULL, log);
      cout << log << endl;

      throw 0; // TODO
  };
}

Shader::~Shader()
{
  LOG("Destroyed shader");
  glDeleteShader(this->id);
}

GLenum detectShaderType(string path)
{
  // Check if ends with 's'
  if(path[path.length() - 1] == 's')
  {
    // Check type of shader
    switch(path[path.length() - 2])
    {
      case 'f':
        //Shader(GL_FRAGMENT_SHADER, path);
        return GL_FRAGMENT_SHADER;
      case 'v':
        //Shader(GL_VERTEX_SHADER, path);
        return GL_VERTEX_SHADER;
    }
  }

  throw 20; // TODO
}

Shader::Shader(string path): Shader(detectShaderType(path), path) {}
