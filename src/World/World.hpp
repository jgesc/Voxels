#pragma once

#include <forward_list>
#include "Region.hpp"

#define WORLD_COORD int64_t

class World
{
private:
  std::forward_list<Region> regions; //TODO: switch to 3D Tree
public:


  // Region manipulation
  Region * regionWithBlock(WORLD_COORD x, WORLD_COORD y, WORLD_COORD z);
  Region * regionWithChunk(CHUNK_COORD x, CHUNK_COORD y, CHUNK_COORD z);

  // Chunk manipulation
  Chunk * getChunk(CHUNK_COORD x, CHUNK_COORD y, CHUNK_COORD z);
  void fetchChunk(CHUNK_COORD x, CHUNK_COORD y, CHUNK_COORD z);

  // Block manipulation
  Block * getBlock(WORLD_COORD x, WORLD_COORD y, WORLD_COORD z);
  void setBlock(WORLD_COORD x, WORLD_COORD y, WORLD_COORD z, uint32_t id);
};
