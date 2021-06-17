#include "World.hpp"

Region * World::regionWithBlock(WORLD_COORD x, WORLD_COORD y, WORLD_COORD z)
{
  uint32_t regionX = x / BLOCKS_PER_REGION;
  uint32_t regionY = y / BLOCKS_PER_REGION;
  uint32_t regionZ = z / BLOCKS_PER_REGION;

  for (std::forward_list<Region>::iterator region = this->regions.begin();
    region != this->regions.end(); region++) {
      if(region->getX() == regionX && region->getY() == regionY && region->getZ() == regionZ)
        return &*region;
  }

  return NULL;
}

Block * World::getBlock(WORLD_COORD x, WORLD_COORD y, WORLD_COORD z)
{
  Region * region = this->regionWithBlock(x, y, z);
  if(region)
  {
    uint32_t regionLocalX = x % BLOCKS_PER_REGION;
    uint32_t regionLocalY = y % BLOCKS_PER_REGION;
    uint32_t regionLocalZ = z % BLOCKS_PER_REGION;

    return region->getBlock(regionLocalX, regionLocalY, regionLocalZ);
  }
  return NULL;
}

void World::setBlock(WORLD_COORD x, WORLD_COORD y, WORLD_COORD z, uint32_t id)
{
  Region * region = this->regionWithBlock(x, y, z);
  if(region)
  {
    uint32_t regionLocalX = x % BLOCKS_PER_REGION;
    uint32_t regionLocalY = y % BLOCKS_PER_REGION;
    uint32_t regionLocalZ = z % BLOCKS_PER_REGION;
    
    return region->setBlock(regionLocalX, regionLocalY, regionLocalZ, id);
  }
}

Chunk * World::getChunk(uint64_t x, uint64_t y, uint64_t z)
{
  Region * region = this->regionWithBlock(x * CHUNK_SIZE, y * CHUNK_SIZE,
    z * CHUNK_SIZE);
  if(region != NULL)
    return region->chunkWithBlock(x % REGION_SIZE, y % REGION_SIZE, z % REGION_SIZE);
  return NULL;
}

void World::fetchChunk(uint64_t x, uint64_t y, uint64_t z)
{
  // Check if corresponding region is loaded
  Region * region = this->regionWithBlock(x * CHUNK_SIZE, y * CHUNK_SIZE,
    z * CHUNK_SIZE);
  if(region == NULL)
  {
    // If not, load region
    region = &this->regions.emplace_front(x / REGION_SIZE,
      y / REGION_SIZE, z / REGION_SIZE);
  }
  // Check if chunk is loaded in region
  if(!region->chunkWithBlock(x % REGION_SIZE, y % REGION_SIZE, z % REGION_SIZE))
  {
    // If not, check if chunk exists in storage
      // If not, generate chunk
    // Else load from storage
    // TODO: for now just generate empty chunk
    region->createEmptyChunk(x % REGION_SIZE, y % REGION_SIZE, z % REGION_SIZE);
  }
  // Else exit
}
