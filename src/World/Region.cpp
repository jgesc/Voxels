#include "Region.hpp"

// TODO: Check nulls

Chunk * Region::chunkWithBlock(LOCAL_REGION_COORD x, LOCAL_REGION_COORD y, LOCAL_REGION_COORD z)
{
  return this->chunks[x / CHUNK_SIZE][y / CHUNK_SIZE][z / CHUNK_SIZE];
}

Block * Region::getBlock(LOCAL_REGION_COORD x, LOCAL_REGION_COORD y, LOCAL_REGION_COORD z)
{
  Chunk * chunk = this->chunkWithBlock(x, y, z);
  if(chunk)
    return chunk->getBlock(x % CHUNK_SIZE, y % CHUNK_SIZE, z % CHUNK_SIZE);
  else
    return NULL;
}

void Region::setBlock(LOCAL_REGION_COORD x, LOCAL_REGION_COORD y, LOCAL_REGION_COORD z, uint32_t id)
{
  Chunk * chunk = this->chunkWithBlock(x, y, z);
  chunk->setBlock(x % CHUNK_SIZE, y % CHUNK_SIZE, z % CHUNK_SIZE, id);
}

void Region::createEmptyChunk(LOCAL_REGION_COORD x, LOCAL_REGION_COORD y, LOCAL_REGION_COORD z)
{
  this->chunks[x][y][z] = new Chunk();
}
