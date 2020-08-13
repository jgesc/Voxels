#include "Chunk.hpp"

Block * Chunk::getBlock(LOCAL_CHUNK_COORD x, LOCAL_CHUNK_COORD y, LOCAL_CHUNK_COORD z)
{
  if(x < CHUNK_SIZE && y < CHUNK_SIZE && z < CHUNK_SIZE)
    return &this->blocks[x][y][z];
  return NULL;
}

void Chunk::setBlock(LOCAL_CHUNK_COORD x, LOCAL_CHUNK_COORD y, LOCAL_CHUNK_COORD z, uint32_t id)
{
  if(x < CHUNK_SIZE && y < CHUNK_SIZE && z < CHUNK_SIZE)
    this->blocks[x][y][z].setId(id);
}
