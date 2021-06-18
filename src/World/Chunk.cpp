#include "Chunk.hpp"

static uint64_t timestamp = 0;

Block * Chunk::getBlock(LOCAL_CHUNK_COORD x, LOCAL_CHUNK_COORD y, LOCAL_CHUNK_COORD z)
{
  if(x < CHUNK_SIZE && y < CHUNK_SIZE && z < CHUNK_SIZE)
    return &this->blocks[x][y][z];
  return NULL;
}

uint32_t Chunk::getBlockId(LOCAL_CHUNK_COORD x, LOCAL_CHUNK_COORD y, LOCAL_CHUNK_COORD z)
{
  if(x < CHUNK_SIZE && y < CHUNK_SIZE && z < CHUNK_SIZE)
    return this->blocks[x][y][z].getId();
  return 0;
}

void Chunk::setBlock(LOCAL_CHUNK_COORD x, LOCAL_CHUNK_COORD y, LOCAL_CHUNK_COORD z, uint32_t id)
{
  if(x < CHUNK_SIZE && y < CHUNK_SIZE && z < CHUNK_SIZE)
    this->blocks[x][y][z].setId(id);
    this->lastUpdate = timestamp++;
}
