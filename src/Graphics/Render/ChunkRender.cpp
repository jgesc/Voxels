#include "ChunkRender.hpp"
#include "../Shaders/ShaderStore.hpp"
#include "../Textures/TextureStore.hpp"
#include "BlockRenderStore.hpp"

ChunkRender::ChunkRender(Chunk * chunk) : chunk(chunk)
{
  // Generate buffer
  glGenVertexArrays(1, &this->VAO);
  glBindVertexArray(this->VAO);
  glGenBuffers(1, &this->VBO);
  glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
  glEnableVertexAttribArray(1);

  // Set flag for initial render
  this->requiresUpdate = true;
}

void ChunkRender::updateVBO()
{
  // Generate vertices
  vector<float> vertex;

  for(int x = 0; x < 16; x++)
  {
    for(int y = 0; y < 16; y++)
    {
      for(int z = 0; z < 16; z++)
      {
        BlockRenderStore::renderBlock(&vertex, this->chunk, x, y, z,
          this->chunk->getBlock(x, y, z)->getId());
      }
    }
  }

  // Update buffer
  glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
  glBufferData(GL_ARRAY_BUFFER, vertex.size() * sizeof(float), vertex.data(), GL_STATIC_DRAW);
  this->vertexCount = vertex.size() / 3;

  // Unset requiresUpdate flag
  this->requiresUpdate = false;
  this->lastUpdate = this->chunk->getLastUpdate();
}

void ChunkRender::render()
{
  // Check if chunk has been updated
  this->requiresUpdate = this->lastUpdate != this->chunk->getLastUpdate();

  // Check if VBO update is required
  if(this->shouldUpdateVBO()) this->updateVBO();

  // Render
  TextureStore::getInstance()->blockAtlas.bind();
  glBindVertexArray(this->VAO);
  ShaderStore::I->chunkShader.use();
  ShaderStore::I->chunkShader.setVec3f("chunkpos",
    this->chunk->getX() * CHUNK_SIZE,
    this->chunk->getY() * CHUNK_SIZE,
    this->chunk->getZ() * CHUNK_SIZE);
  // TODO: Use world coordinates (see Chunk.hpp)
  glDrawArrays(GL_TRIANGLES, 0, this->vertexCount);
}
