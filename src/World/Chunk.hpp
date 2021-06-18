#pragma once

#include "Block.hpp"


#define CHUNK_SIZE 16
#define LOCAL_CHUNK_COORD uint_fast8_t

class Chunk
{
private:
  Block blocks [CHUNK_SIZE][CHUNK_SIZE][CHUNK_SIZE];
  uint64_t lastUpdate;
public:
  Block * getBlock(LOCAL_CHUNK_COORD x, LOCAL_CHUNK_COORD y, LOCAL_CHUNK_COORD z);
  uint32_t getBlockId(LOCAL_CHUNK_COORD x, LOCAL_CHUNK_COORD y, LOCAL_CHUNK_COORD z); // Should be deprecated
  void setBlock(LOCAL_CHUNK_COORD x, LOCAL_CHUNK_COORD y, LOCAL_CHUNK_COORD z, uint32_t id);

  uint64_t getLastUpdate() {return this->lastUpdate;}
};
