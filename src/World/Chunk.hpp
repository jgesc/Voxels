#pragma once

#include "Block.hpp"

// Size in blocks
#define CHUNK_SIZE 16
// Local block coordinates
#define LOCAL_CHUNK_COORD uint_fast8_t
// Chunk coordinates
#define CHUNK_COORD int64_t

class Chunk
{
private:
  Block blocks [CHUNK_SIZE][CHUNK_SIZE][CHUNK_SIZE];
  CHUNK_COORD x, y, z; // TODO: include world coordinates for better performance
  uint64_t lastUpdate;
public:
  Chunk(CHUNK_COORD x, CHUNK_COORD y, CHUNK_COORD z) : x(x), y(y), z(z) {}

  Block * getBlock(LOCAL_CHUNK_COORD x, LOCAL_CHUNK_COORD y, LOCAL_CHUNK_COORD z);
  uint32_t getBlockId(LOCAL_CHUNK_COORD x, LOCAL_CHUNK_COORD y, LOCAL_CHUNK_COORD z); // Should be deprecated
  void setBlock(LOCAL_CHUNK_COORD x, LOCAL_CHUNK_COORD y, LOCAL_CHUNK_COORD z, uint32_t id);

  inline CHUNK_COORD getX(){return this->x;}
  inline CHUNK_COORD getY(){return this->y;}
  inline CHUNK_COORD getZ(){return this->z;}

  uint64_t getLastUpdate() {return this->lastUpdate;}
};
