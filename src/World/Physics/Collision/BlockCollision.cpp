#include "BlockCollision.hpp"

void BlockCollision::set(World * world, Block * block,
  WORLD_COORD x, WORLD_COORD y, WORLD_COORD z)
{
  this->block = block;
  this->region = world->getRegionWithBlock(x, y, z);
  this->chunk = this->region->getChunkWithBlock(
    World::coordWorldToRegionBlock(x),
    World::coordWorldToRegionBlock(y),
    World::coordWorldToRegionBlock(z));
  this->x = World::coordWorldToChunkBlock(x);
  this->y = World::coordWorldToChunkBlock(y);
  this->z = World::coordWorldToChunkBlock(z);
  this->isSet = true;
}
