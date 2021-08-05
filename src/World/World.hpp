#pragma once

#include <forward_list>
#include "Region.hpp"
#include "Generation/TerrainGeneration.hpp"
#include "../Utils/Utils.hpp"

class World
{
private:
  std::forward_list<Region> regions; //TODO: switch to 3D Tree
  TerrainGeneration generator; // TODO: generalize generator
public:


  // Region manipulation
  Region * getRegion(REGION_COORD x, REGION_COORD y, REGION_COORD z);
  Region * getRegionWithBlock(WORLD_COORD x, WORLD_COORD y, WORLD_COORD z);
  Region * getRegionWithChunk(CHUNK_COORD x, CHUNK_COORD y, CHUNK_COORD z);

  // Chunk manipulation
  Chunk * getChunk(CHUNK_COORD x, CHUNK_COORD y, CHUNK_COORD z);
  // TODO: add create chunk
  void fetchChunk(CHUNK_COORD x, CHUNK_COORD y, CHUNK_COORD z);

  // Block manipulation
  Block * getBlock(WORLD_COORD x, WORLD_COORD y, WORLD_COORD z);
  void setBlock(WORLD_COORD x, WORLD_COORD y, WORLD_COORD z, uint32_t id);

  // Coordinate system conversion
  static REGION_BLOCK_COORD coordWorldToRegionBlock(WORLD_COORD w);
  static REGION_BLOCK_COORD coordWorldToRegionChunk(WORLD_COORD w);
};
