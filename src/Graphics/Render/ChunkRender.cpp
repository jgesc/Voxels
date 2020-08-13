#include "ChunkRender.hpp"
#include "../Shaders/ShaderStore.hpp"

ChunkRender::ChunkRender(Chunk * chunk) : chunk(chunk)
{
  // Generate buffer
  glGenVertexArrays(1, &this->VAO);
  glBindVertexArray(this->VAO);
  glGenBuffers(1, &this->VBO);
  glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  // Set flag for initial render
  this->requiresUpdate = true;
}

void ChunkRender::updateVBO()
{
  // Generate vertices
  vector<float> vertex;
  this->vertexCount = 0;

  for(int x = 0; x < 16; x++)
  {
    for(int y = 0; y < 16; y++)
    {
      for(int z = 0; z < 16; z++)
      {
        if(this->chunk->getBlock(x, y, z)->getId() != 0)
        {
          this->vertexCount += 36;

          // Left face
          vertex.insert(vertex.end(), {
            (float)x, (float)y, (float)z,
            (float)x, (float)y + 1, (float)z,
            (float)x, (float)y, (float)z + 1,
            (float)x, (float)y + 1, (float)z,
            (float)x, (float)y + 1, (float)z + 1,
            (float)x, (float)y, (float)z + 1
          } );

          // Right face
          vertex.insert(vertex.end(), {
            (float)x + 1, (float)y, (float)z,
            (float)x + 1, (float)y, (float)z + 1,
            (float)x + 1, (float)y + 1, (float)z,
            (float)x + 1, (float)y + 1, (float)z,
            (float)x + 1, (float)y, (float)z + 1,
            (float)x + 1, (float)y + 1, (float)z + 1
          } );

          // Top face
          vertex.insert(vertex.end(), {
            (float)x, (float)y + 1, (float)z,
            (float)x + 1, (float)y + 1, (float)z,
            (float)x + 1, (float)y + 1, (float)z + 1,
            (float)x, (float)y + 1, (float)z,
            (float)x + 1, (float)y + 1, (float)z + 1,
            (float)x, (float)y + 1, (float)z + 1
          } );

          // Bottom face
          vertex.insert(vertex.end(), {
            (float)x, (float)y, (float)z,
            (float)x + 1, (float)y, (float)z + 1,
            (float)x + 1, (float)y, (float)z,
            (float)x, (float)y, (float)z,
            (float)x, (float)y, (float)z + 1,
            (float)x + 1, (float)y, (float)z + 1
          } );

          // Back face
          vertex.insert(vertex.end(), {
            (float)x, (float)y, (float)z,
            (float)x + 1, (float)y, (float)z,
            (float)x + 1, (float)y + 1, (float)z,
            (float)x, (float)y, (float)z,
            (float)x + 1, (float)y + 1, (float)z,
            (float)x, (float)y + 1, (float)z
          } );

          // Front face
          vertex.insert(vertex.end(), {
            (float)x, (float)y, (float)z + 1,
            (float)x + 1, (float)y + 1, (float)z+ 1,
            (float)x + 1, (float)y, (float)z + 1,
            (float)x, (float)y, (float)z + 1,
            (float)x, (float)y + 1, (float)z + 1,
            (float)x + 1, (float)y + 1, (float)z + 1
          } );
        }
      }
    }
  }

  // Update buffer
  glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
  glBufferData(GL_ARRAY_BUFFER, vertex.size() * sizeof(float), vertex.data(), GL_STATIC_DRAW);

  // Unset requiresUpdate flag
  this->requiresUpdate = false;
}

void ChunkRender::render()
{
  // Check if VBO update is required
  if(this->shouldUpdateVBO()) this->updateVBO();

  // Render
  glBindVertexArray(this->VAO);
  ShaderStore::I->defaultShader.use();
  glDrawArrays(GL_TRIANGLES, 0, this->vertexCount);
}
