#pragma once

#include "Chunk.hpp"

// Size in chunks
#define REGION_SIZE 16
// Size in blocks
#define BLOCKS_PER_REGION (REGION_SIZE * CHUNK_SIZE)
// Local chunk coordinates
#define LOCAL_REGION_COORD uint_fast8_t
// Region coordinates
#define REGION_COORD uint64_t

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
  Chunk * chunkWithBlock(LOCAL_REGION_COORD x, LOCAL_REGION_COORD y, LOCAL_REGION_COORD z);
  Chunk * getChunk(LOCAL_REGION_COORD x, LOCAL_REGION_COORD y, LOCAL_REGION_COORD z);
  void createEmptyChunk(LOCAL_REGION_COORD x, LOCAL_REGION_COORD y, LOCAL_REGION_COORD z);

  // Block manipulation
  Block * getBlock(LOCAL_REGION_COORD x, LOCAL_REGION_COORD y, LOCAL_REGION_COORD z);
  void setBlock(LOCAL_REGION_COORD x, LOCAL_REGION_COORD y, LOCAL_REGION_COORD z, uint32_t id);

  // Region properties
  inline uint64_t getX(){return this->x;}
  inline uint64_t getY(){return this->y;}
  inline uint64_t getZ(){return this->z;}
};
