#include "BlockCollision.hpp"

void BlockCollision::set(World * world, Block * block,
  WORLD_COORD x, WORLD_COORD y, WORLD_COORD z)
{
  this->block = block;
  this->region = world->getRegionWithBlock(x, y, z);
  this->chunk = this->region->getChunkWithBlock(
    x % BLOCKS_PER_REGION, y % BLOCKS_PER_REGION, z % BLOCKS_PER_REGION);
  this->x = x;
  this->y = y;
  this->z = z;
  this->isSet = true;
}
