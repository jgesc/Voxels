#include "TerrainGeneration.hpp"

TerrainGeneration::TerrainGeneration(){}

void TerrainGeneration::generateChunk(Chunk * chunk)
{
  // Calculate base world coordinates
  WORLD_COORD bx = chunk->getX() * CHUNK_SIZE;
  WORLD_COORD by = chunk->getY() * CHUNK_SIZE;
  WORLD_COORD bz = chunk->getZ() * CHUNK_SIZE;

  // Local chunk iterators
  CHUNK_BLOCK_COORD lx, ly, lz;

  for(lx = 0; lx < CHUNK_SIZE; lx++)
  {
    for(ly = 0; ly < CHUNK_SIZE; ly++)
    {
      for(lz = 0; lz < CHUNK_SIZE; lz++)
      {
        WORLD_COORD x = bx + lx;
        WORLD_COORD y = by + ly;
        WORLD_COORD z = bz + lz;

        if(y < 64)
        {
          if(y < 60) chunk->setBlock(lx, ly, lz, 1);
          else if(y < 63) chunk->setBlock(lx, ly, lz, 2);
          else chunk->setBlock(lx, ly, lz, 3);
        }
      }
    }
  }
}
