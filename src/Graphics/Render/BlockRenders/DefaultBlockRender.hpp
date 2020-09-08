#pragma once

#include "../BlockRender.hpp"
#include "../../../Debugging/Logger.hpp"

class DefaultBlockRender : public BlockRender
{
private:
  unsigned int atlasx, atlasy;

  float tl[2];
  float tr[2];
  float bl[2];
  float br[2];
public:
  void render(std::vector<float> * vertices, Chunk *chunk, uint_fast8_t lx,
    uint_fast8_t ly, uint_fast8_t lz, unsigned int id) override;
  DefaultBlockRender(unsigned int atlasx, unsigned int atlasy);
};
