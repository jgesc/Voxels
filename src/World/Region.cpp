#include "Region.hpp"

Chunk * Region::chunkWithBlock(LOCAL_REGION_COORD x, LOCAL_REGION_COORD y, LOCAL_REGION_COORD z)
{
  return this->chunks[x % CHUNK_SIZE][y % CHUNK_SIZE][z % CHUNK_SIZE];
}

Block * Region::Region::getBlock(LOCAL_REGION_COORD x, LOCAL_REGION_COORD y, LOCAL_REGION_COORD z)
{
  Chunk * chunk = this->chunkWithBlock(x, y, z);
  return chunk->getBlock(x % CHUNK_SIZE, y % CHUNK_SIZE, z % CHUNK_SIZE);
}

void Region::setBlock(LOCAL_REGION_COORD x, LOCAL_REGION_COORD y, LOCAL_REGION_COORD z, uint32_t id)
{
  Chunk * chunk = this->chunkWithBlock(x, y, z);
  chunk->setBlock(x % CHUNK_SIZE, y % CHUNK_SIZE, z % CHUNK_SIZE, id);
}
