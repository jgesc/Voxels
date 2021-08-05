#include "Chunk.hpp"

static uint64_t timestamp = 0;

Block * Chunk::getBlock(CHUNK_BLOCK_COORD x, CHUNK_BLOCK_COORD y, CHUNK_BLOCK_COORD z)
{
  if(x < CHUNK_SIZE && y < CHUNK_SIZE && z < CHUNK_SIZE)
    return &this->blocks[x][y][z];
  return NULL;
}

uint32_t Chunk::getBlockId(CHUNK_BLOCK_COORD x, CHUNK_BLOCK_COORD y, CHUNK_BLOCK_COORD z)
{
  if(x < CHUNK_SIZE && y < CHUNK_SIZE && z < CHUNK_SIZE)
    return this->blocks[x][y][z].getId();
  return 0;
}

void Chunk::setBlock(CHUNK_BLOCK_COORD x, CHUNK_BLOCK_COORD y, CHUNK_BLOCK_COORD z, uint32_t id)
{
  // LOG("Chunk::setBlock(" << (int)x << ", " << (int)y << ", " << (int)z << ")");
  if(x < CHUNK_SIZE && y < CHUNK_SIZE && z < CHUNK_SIZE)
  {
    this->blocks[x][y][z].setId(id);
    this->lastUpdate = timestamp++;
  }
  else
  {
    LOG("WARING: Tried to set a chunk's block out of boundaries (" << (int)x << ", " << (int)y << ", " << (int)z << ")");
  }
}
