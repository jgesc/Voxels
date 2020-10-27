#pragma once

#include "../../Block.hpp"
#include "../../Chunk.hpp"
#include "../../Region.hpp"

class BlockCollision
{
private:
  Block * block;
  Chunk * chunk;
  Region * region;
  LOCAL_CHUNK_COORD x, y, z;
  bool isSet;
public:
  BlockCollision() : isSet(false) {}

  void set(Block * block, Chunk * chunk, Region * region,
    LOCAL_CHUNK_COORD x, LOCAL_CHUNK_COORD y, LOCAL_CHUNK_COORD z);

  Block * getBlock() {return this->block;}
  Chunk * getChunk() {return this->chunk;}
  Region * getRegion() {return this->region;}
  LOCAL_CHUNK_COORD getX() {return this->x;}
  LOCAL_CHUNK_COORD getY() {return this->y;}
  LOCAL_CHUNK_COORD getZ() {return this->z;}
  bool getIsSet() {return this->isSet;}
};
