#pragma once

#include "../../Block.hpp"
#include "../../Chunk.hpp"
#include "../../Region.hpp"
#include "../../World.hpp"


class BlockCollision
{
private:
  Block * block;
  Chunk * chunk;
  Region * region;
  WORLD_COORD x, y, z;
  bool isSet;
public:
  BlockCollision() : isSet(false) {}

  void set(World * world, Block * block,
    WORLD_COORD x, WORLD_COORD y, WORLD_COORD z);

  Block * getBlock() {return this->block;}
  Chunk * getChunk() {return this->chunk;}
  Region * getRegion() {return this->region;}
  WORLD_COORD getX() {return this->x;}
  WORLD_COORD getY() {return this->y;}
  WORLD_COORD getZ() {return this->z;}
  bool getIsSet() {return this->isSet;}

  void reset() {this->isSet = false;}
};
