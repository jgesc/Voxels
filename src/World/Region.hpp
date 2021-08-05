#pragma once

#include "Chunk.hpp"

#include "../Utils/Utils.hpp"

// Size in chunks
#define REGION_SIZE 16
// Size in blocks
#define BLOCKS_PER_REGION (REGION_SIZE * CHUNK_SIZE)
// Local chunk coordinates
#define REGION_CHUNK_COORD uint_fast8_t
// Block inside the region
// uint8_t With REGION_SIZE = 16 && CHUNK_SIZE = 16 => 256
#define REGION_BLOCK_COORD uint_fast8_t
static_assert(REGION_SIZE * CHUNK_SIZE <= 256);
// Region coordinates
#define REGION_COORD int64_t

class Region
{
private:
  Chunk * chunks[REGION_SIZE][REGION_SIZE][REGION_SIZE];
  REGION_COORD x, y, z;
public:
  Region(REGION_COORD x, REGION_COORD y, REGION_COORD z) : x(x), y(y), z(z),
    chunks{} {};

  // Chunk manipulation
  // TODO: distinguish between local chunk and block coordinates
  Chunk * getChunkWithBlock(REGION_CHUNK_COORD x, REGION_CHUNK_COORD y, REGION_CHUNK_COORD z);
  Chunk * getChunk(REGION_CHUNK_COORD x, REGION_CHUNK_COORD y, REGION_CHUNK_COORD z);
  void createEmptyChunk(REGION_CHUNK_COORD x, REGION_CHUNK_COORD y, REGION_CHUNK_COORD z);

  // Block manipulation
  Block * getBlock(REGION_BLOCK_COORD x, REGION_BLOCK_COORD y, REGION_BLOCK_COORD z);
  void setBlock(REGION_BLOCK_COORD x, REGION_BLOCK_COORD y, REGION_BLOCK_COORD z, uint32_t id);

  // Coordinate system conversion
  static CHUNK_BLOCK_COORD coordRegionToChunkBlock(REGION_BLOCK_COORD w);

  // Region properties
  inline uint64_t getX(){return this->x;}
  inline uint64_t getY(){return this->y;}
  inline uint64_t getZ(){return this->z;}
};
