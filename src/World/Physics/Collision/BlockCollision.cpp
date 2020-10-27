#include "BlockCollision.hpp"

void BlockCollision::set(Block * block, Chunk * chunk, Region * region,
  LOCAL_CHUNK_COORD x, LOCAL_CHUNK_COORD y, LOCAL_CHUNK_COORD z)
{
  this->block = block;
  this->chunk = chunk;
  this->region = region;
  this->x = x;
  this->y = y;
  this->z = z;
  this->isSet = true;
}
