#include "Region.hpp"

// TODO: Check nulls

Chunk * Region::getChunkWithBlock(REGION_BLOCK_COORD x, REGION_BLOCK_COORD y, REGION_BLOCK_COORD z)
{
  //LOG("Region::chunkWithBlock(" << (uint32_t)x << ", " << (uint32_t)y << ", " << (uint32_t)z << ")");
  REGION_CHUNK_COORD localChunkX = SIGDIV(x, CHUNK_SIZE);
  REGION_CHUNK_COORD localChunkY = SIGDIV(y, CHUNK_SIZE);
  REGION_CHUNK_COORD localChunkZ = SIGDIV(z, CHUNK_SIZE);

  return this->chunks[localChunkX][localChunkY][localChunkZ];
}

Block * Region::getBlock(REGION_BLOCK_COORD x, REGION_BLOCK_COORD y, REGION_BLOCK_COORD z)
{
  Chunk * chunk = this->getChunkWithBlock(x, y, z);
  if(chunk)
  {
    CHUNK_BLOCK_COORD localX = Region::coordRegionToChunkBlock(x);
    CHUNK_BLOCK_COORD localY = Region::coordRegionToChunkBlock(y);
    CHUNK_BLOCK_COORD localZ = Region::coordRegionToChunkBlock(z);

    return chunk->getBlock(localX, localY, localZ);
  }

  return NULL;
}

void Region::setBlock(REGION_BLOCK_COORD x, REGION_BLOCK_COORD y, REGION_BLOCK_COORD z, uint32_t id)
{
  Chunk * chunk = this->getChunkWithBlock(x, y, z);
  if(chunk)
  {
    CHUNK_BLOCK_COORD localX = Region::coordRegionToChunkBlock(x);
    CHUNK_BLOCK_COORD localY = Region::coordRegionToChunkBlock(y);
    CHUNK_BLOCK_COORD localZ = Region::coordRegionToChunkBlock(z);

    chunk->setBlock(localX, localY, localZ, id);
  }
}

Chunk * Region::getChunk(REGION_CHUNK_COORD x, REGION_CHUNK_COORD y, REGION_CHUNK_COORD z)
{
  return this->chunks[x][y][z];
}

void Region::createEmptyChunk(REGION_CHUNK_COORD x, REGION_CHUNK_COORD y, REGION_CHUNK_COORD z)
{
  //LOG("Region::createEmptyChunk(" << (uint32_t)x << ", " << (uint32_t)y << ", " << (uint32_t)z << ")");
  CHUNK_COORD newChunkX = x + this->x * REGION_SIZE;
  CHUNK_COORD newChunkY = y + this->y * REGION_SIZE;
  CHUNK_COORD newChunkZ = z + this->z * REGION_SIZE;

  this->chunks[x][y][z] = new Chunk(newChunkX, newChunkY, newChunkZ);
}

CHUNK_BLOCK_COORD Region::coordRegionToChunkBlock(REGION_BLOCK_COORD w)
{
  return SIGMOD(w, CHUNK_SIZE);
}
