#include "RenderManager.hpp"

std::forward_list<ChunkRender> RenderManager::chunkRenders;

void RenderManager::registerChunk(Chunk * chunk)
{
  // TODO: check if chunk already registered
  // Create new chunk render
  RenderManager::chunkRenders.emplace_front(chunk);
}


void RenderManager::renderChunksWithCamera(Camera * camera)
{
  // TODO: Enable camera

  // TODO: Remember to set uniform

  // Call 'render()' method for all registered chunk renders
  for (std::forward_list<ChunkRender>::iterator cr = RenderManager::chunkRenders.begin();
    cr != RenderManager::chunkRenders.end(); cr++) {
      cr->render();
  }
}

void RenderManager::renderInterface()
{
  InterfaceRender::renderInterface();
}
