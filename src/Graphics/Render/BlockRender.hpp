#pragma once

#include <vector>

#include "../../World/Chunk.hpp"

class BlockRender
{
public:
  virtual void render(std::vector<float> * vertices, Chunk * chunk,
    uint_fast8_t lx, uint_fast8_t ly, uint_fast8_t lz, unsigned int id) = 0;
};
