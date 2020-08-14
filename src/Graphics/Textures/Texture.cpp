#include "Texture.hpp"

Texture Texture::fromResource(std::string path)
{
  int width, height, nchannels;
  // Load resource
  unsigned char *data = stbi_load((RESOURCE_PATH + path).c_str(), &width,
    &height, &nchannels, 3);
  // Generate texture
  GLuint id;
  glGenTextures(1, &id);
  // Bind loaded resource to texture
  glBindTexture(GL_TEXTURE_2D, id);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
  // Generate Mipmap
  glGenerateMipmap(GL_TEXTURE_2D);
  // Free resource
  stbi_image_free(data);
  // Set filtering to nearest
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

  LOG("Loaded resource: " + path);

  return Texture(id, width, height, nchannels);
}
