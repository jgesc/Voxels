#pragma once

#include <vector>
#include "../../World/Block.hpp"
#include "../../World/Chunk.hpp"
#include "BlockRender.hpp"

#include "BlockRenders/DefaultBlockRender.hpp"
#include "BlockRenders/GrassBlockRender.hpp"

class BlockRenderStore
{
private:
  static bool initialized;
  static BlockRenderStore * I;

  BlockRender * renders[MAX_BLOCK_ID] = {NULL};

  BlockRenderStore();
public:
  static BlockRenderStore * getInstance() {return BlockRenderStore::I;}
  static void initialize();
  static void renderBlock(std::vector<float> * vertices, Chunk * chunk,
    uint_fast8_t lx, uint_fast8_t ly, uint_fast8_t lz, unsigned int id);
};
