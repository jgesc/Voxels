#pragma once

#include <vector>
#include <glad/glad.h>

#include "../../World/Chunk.hpp"

using std::vector;

class ChunkRender
{
private:
  Chunk * chunk;
  GLuint VBO, VAO;
  GLuint vertexCount;
  bool requiresUpdate;

public:
  // Constructors
  ChunkRender(Chunk * chunk);

  // Rendering methods
  inline bool shouldUpdateVBO() {return requiresUpdate;}
  void updateVBO();
  void render();
};
