#include "World.hpp"

Region * World::regionWithBlock(WORLD_COORD x, WORLD_COORD y, WORLD_COORD z)
{
  uint64_t regionX = x / BLOCKS_PER_REGION;
  uint64_t regionY = y / BLOCKS_PER_REGION;
  uint64_t regionZ = z / BLOCKS_PER_REGION;

  for (std::forward_list<Region>::iterator region = this->regions.begin();
    region != this->regions.end(); region++) {
      if(region->getX() == regionX && region->getY() == regionY && region->getZ() == regionZ)
        return &*region;
  }

  return NULL;
}

Region * World::regionWithChunk(CHUNK_COORD x, CHUNK_COORD y, CHUNK_COORD z)
{
  // Calculate region containing chunk
  REGION_COORD regionX = x / REGION_SIZE;
  REGION_COORD regionY = y / REGION_SIZE;
  REGION_COORD regionZ = z / REGION_SIZE;

  // Check if region is loaded
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
  //LOG("World::setBlock(" << x << ", " << y << ", " << z << ")");
  Region * region = this->regionWithBlock(x, y, z);
  if(region)
  {
    uint32_t regionLocalX = x % BLOCKS_PER_REGION;
    uint32_t regionLocalY = y % BLOCKS_PER_REGION;
    uint32_t regionLocalZ = z % BLOCKS_PER_REGION;

    return region->setBlock(regionLocalX, regionLocalY, regionLocalZ, id);
  }
}

Chunk * World::getChunk(CHUNK_COORD x, CHUNK_COORD y, CHUNK_COORD z)
{
  Region * region = this->regionWithBlock(x * CHUNK_SIZE, y * CHUNK_SIZE,
    z * CHUNK_SIZE);
  if(region != NULL)
    return region->getChunk(x % REGION_SIZE, y % REGION_SIZE, z % REGION_SIZE);
  return NULL;
}

void World::fetchChunk(CHUNK_COORD x, CHUNK_COORD y, CHUNK_COORD z)
{
  // Check if corresponding region is loaded
  Region * region = this->regionWithChunk(x, y, z);
  if(region == NULL)
  {
    // If not, load region
    region = &this->regions.emplace_front(x / REGION_SIZE,
      y / REGION_SIZE, z / REGION_SIZE);
  }
  // Check if chunk is loaded in region
  if(!region->getChunk(x, y, z))
  {
    // If not, check if chunk exists in storage
      // If not, generate chunk
    // Else load from storage
    // TODO: for now just generate empty chunk
    region->createEmptyChunk(x, y, z);
  }
  // Else exit
}
