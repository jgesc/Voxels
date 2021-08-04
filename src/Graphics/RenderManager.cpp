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
  // Set chunk shader
  ShaderStore::I->chunkShader.use();
  // Get camera view matrix
  ShaderStore::I->chunkShader.setMat4("view", camera->getViewMatrix());

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
