#pragma once

#include "Block.hpp"


#define CHUNK_SIZE 16
#define LOCAL_CHUNK_COORD uint_fast8_t

class Chunk
{
private:
  Block blocks [CHUNK_SIZE][CHUNK_SIZE][CHUNK_SIZE];
  uint32_t x, y, z;
  uint64_t lastUpdate;
public:
  Chunk(uint32_t x, uint32_t y, uint32_t z) : x(x), y(y), z(z) {}

  Block * getBlock(LOCAL_CHUNK_COORD x, LOCAL_CHUNK_COORD y, LOCAL_CHUNK_COORD z);
  uint32_t getBlockId(LOCAL_CHUNK_COORD x, LOCAL_CHUNK_COORD y, LOCAL_CHUNK_COORD z); // Should be deprecated
  void setBlock(LOCAL_CHUNK_COORD x, LOCAL_CHUNK_COORD y, LOCAL_CHUNK_COORD z, uint32_t id);

  inline uint32_t getX(){return this->x;}
  inline uint32_t getY(){return this->y;}
  inline uint32_t getZ(){return this->z;}

  uint64_t getLastUpdate() {return this->lastUpdate;}
};
