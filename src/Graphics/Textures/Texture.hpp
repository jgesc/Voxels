#pragma once

#include <string>
#include <glad/glad.h>

#include "../../ResourceManager.hpp"

class Texture
{
private:
  unsigned int width, height, nchannels;
  GLuint id;
public:
  // Constructor
  static Texture fromResource(std::string path);
  Texture(GLuint id, uint32_t width, uint32_t height, uint32_t nchannels) :
    id(id), width(width), height(height), nchannels(nchannels) {};

  // Getter
  GLuint getId() {return this->id;}
  unsigned int getWidth() {return this->width;}
  unsigned int getHeight() {return this->height;}
  unsigned int getNchannels() {return this->nchannels;}
};
