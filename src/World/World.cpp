#include "World.hpp"

Region * World::getRegion(REGION_COORD x, REGION_COORD y, REGION_COORD z)
{
  for (std::forward_list<Region>::iterator region = this->regions.begin();
  region != this->regions.end(); region++) {
    if(region->getX() == x && region->getY() == y && region->getZ() == z)
    return &*region;
  }

  return NULL;
}

Region * World::getRegionWithBlock(WORLD_COORD x, WORLD_COORD y, WORLD_COORD z)
{
  REGION_COORD regionX = SIGDIV(x, BLOCKS_PER_REGION);
  REGION_COORD regionY = SIGDIV(y, BLOCKS_PER_REGION);
  REGION_COORD regionZ = SIGDIV(z, BLOCKS_PER_REGION);

  return getRegion(regionX, regionY, regionZ);
}

Region * World::getRegionWithChunk(CHUNK_COORD x, CHUNK_COORD y, CHUNK_COORD z)
{
  // Calculate region containing chunk
  REGION_COORD regionX = SIGDIV(x, REGION_SIZE);
  REGION_COORD regionY = SIGDIV(y, REGION_SIZE);
  REGION_COORD regionZ = SIGDIV(z, REGION_SIZE);
  LOG("World::regionWithChunk(" << x << ", " << y << ", " << z << ") = (" << regionX << ", " << regionY << ", " << regionZ << ")");

  return getRegion(regionX, regionY, regionZ);
}


Block * World::getBlock(WORLD_COORD x, WORLD_COORD y, WORLD_COORD z)
{
  Region * region = this->getRegionWithBlock(x, y, z);
  if(region)
  {
    // Convert to local coordinates
    REGION_BLOCK_COORD regionLocalX = World::coordWorldToRegionBlock(x);
    REGION_BLOCK_COORD regionLocalY = World::coordWorldToRegionBlock(y);
    REGION_BLOCK_COORD regionLocalZ = World::coordWorldToRegionBlock(z);

    return region->getBlock(regionLocalX, regionLocalY, regionLocalZ);
  }
  return NULL;
}

void World::setBlock(WORLD_COORD x, WORLD_COORD y, WORLD_COORD z, uint32_t id)
{
  //LOG("World::setBlock(" << x << ", " << y << ", " << z << ")");
  Region * region = this->getRegionWithBlock(x, y, z);
  if(region)
  {
    // Convert to local coordinates
    REGION_BLOCK_COORD regionLocalX = World::coordWorldToRegionBlock(x);
    REGION_BLOCK_COORD regionLocalY = World::coordWorldToRegionBlock(y);
    REGION_BLOCK_COORD regionLocalZ = World::coordWorldToRegionBlock(z);

    return region->setBlock(regionLocalX, regionLocalY, regionLocalZ, id);
  }
}

Chunk * World::getChunk(CHUNK_COORD x, CHUNK_COORD y, CHUNK_COORD z)
{
  Region * region = this->getRegionWithChunk(x, y, z);
  if(region != NULL)
    return region->getChunk(SIGMOD(x, REGION_SIZE), SIGMOD(y, REGION_SIZE),
      SIGMOD(z, REGION_SIZE));
  return NULL;
}

void World::fetchChunk(CHUNK_COORD x, CHUNK_COORD y, CHUNK_COORD z)
{
  // LOG("World::fetchChunk(" << x << ", " << y << ", " << z<< ")");

  // Check if corresponding region is loaded
  Region * region = this->getRegionWithChunk(x, y, z);
  if(region == NULL)
  {
    // If not, load region
    region = &this->regions.emplace_front(SIGDIV(x, REGION_SIZE),
      SIGDIV(y, REGION_SIZE), SIGDIV(z, REGION_SIZE));
    LOG("Creating region " << SIGDIV(x, REGION_SIZE) << " " <<
      SIGDIV(y, REGION_SIZE) << " " << SIGDIV(z, REGION_SIZE));
  }
  // Check if chunk is loaded in region
  if(!region->getChunk(x, y, z))
  {
    // If not, check if chunk exists in storage
      // If not, generate chunk
    // Else load from storage
    // TODO: for now just generate empty chunk
    region->createEmptyChunk(x, y, z);
    this->generator.generateChunk(region->getChunk(x, y, z));
  }
  // Else exit
}

REGION_BLOCK_COORD World::coordWorldToRegionBlock(WORLD_COORD w)
{
  return SIGMOD(w, BLOCKS_PER_REGION);
}
