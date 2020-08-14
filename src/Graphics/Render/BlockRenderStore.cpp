#include "BlockRenderStore.hpp"

bool BlockRenderStore::initialized = false;
BlockRenderStore * BlockRenderStore::I = NULL;

void BlockRenderStore::initialize()
{
  if(BlockRenderStore::initialized) return;

  BlockRenderStore::I = new BlockRenderStore();
  BlockRenderStore::initialized = true;
}

BlockRenderStore::BlockRenderStore()
{
  // Register renders
}

void BlockRenderStore::renderBlock(std::vector<float> * vertices, Chunk * chunk,
  uint_fast8_t lx, uint_fast8_t ly, uint_fast8_t lz, unsigned int id)
{
  // Check if can render
  if(id == 0 || BlockRenderStore::I->renders[id] == NULL) return;

  // Delegate render
  BlockRenderStore::I->renders[id]->render(vertices, chunk, lx, ly, lz, id);
}
