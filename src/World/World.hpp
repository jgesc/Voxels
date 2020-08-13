#pragma once

#include <forward_list>
#include "Region.hpp"

#define WORLD_COORD uint64_t

class World
{
private:
  std::forward_list<Region> regions; //TODO: switch to 3D Tree
public:
  Region * regionWithBlock(WORLD_COORD x, WORLD_COORD y, WORLD_COORD z);
  Block * getBlock(WORLD_COORD x, WORLD_COORD y, WORLD_COORD z);
  void setBlock(WORLD_COORD x, WORLD_COORD y, WORLD_COORD z, uint32_t id);
};
