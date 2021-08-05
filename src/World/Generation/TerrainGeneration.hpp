#pragma once

#include "../../Vendor/PerlinNoise.hpp"
#include "../Chunk.hpp"

using namespace siv;

class TerrainGeneration
{
  private:
    PerlinNoise noise;
  public:
    TerrainGeneration();
    void generateChunk(Chunk * chunk);
};

#include "../World.hpp"
