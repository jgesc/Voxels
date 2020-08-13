#include "World.hpp"

Region * World::regionWithBlock(WORLD_COORD x, WORLD_COORD y, WORLD_COORD z)
{
  uint32_t regionX = x % BLOCKS_PER_REGION;
  uint32_t regionY = y % BLOCKS_PER_REGION;
  uint32_t regionZ = z % BLOCKS_PER_REGION;

  for (std::forward_list<Region>::iterator region = this->regions.begin();
    region != this->regions.end(); region++) {
      if(region->getX() == regionX && region->getY() == regionY && region->getZ() == regionZ)
        return &*region;
  }

  return NULL;
}
