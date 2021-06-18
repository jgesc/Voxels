#pragma once

#include "Chunk.hpp"

#define REGION_SIZE 16
#define BLOCKS_PER_REGION (REGION_SIZE * CHUNK_SIZE)
#define LOCAL_REGION_COORD uint_fast8_t

class Region
{
private:
  Chunk * chunks[REGION_SIZE][REGION_SIZE][REGION_SIZE];
  uint64_t x, y, z;
public:
  Region(uint64_t x, uint64_t y, uint64_t z) : x(x), y(y), z(z),
    chunks{} {};

  // Chunk manipulation
  Chunk * chunkWithBlock(LOCAL_REGION_COORD x, LOCAL_REGION_COORD y, LOCAL_REGION_COORD z);
  void createEmptyChunk(LOCAL_REGION_COORD x, LOCAL_REGION_COORD y, LOCAL_REGION_COORD z);

  // Block manipulation
  Block * getBlock(LOCAL_REGION_COORD x, LOCAL_REGION_COORD y, LOCAL_REGION_COORD z);
  void setBlock(LOCAL_REGION_COORD x, LOCAL_REGION_COORD y, LOCAL_REGION_COORD z, uint32_t id);

  // Region properties
  inline uint64_t getX(){return this->x;}
  inline uint64_t getY(){return this->y;}
  inline uint64_t getZ(){return this->z;}
};
