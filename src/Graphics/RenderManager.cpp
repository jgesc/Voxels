#include "RenderManager.hpp"

std::forward_list<ChunkRender> RenderManager::chunkRenders;
float RenderManager::renderTime = 0.0;
high_resolution_clock::time_point RenderManager::lastRenderTime = high_resolution_clock::now();

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

  // Measure FPS
  high_resolution_clock::time_point renderTime = high_resolution_clock::now();
  duration<float> renderDuration = duration_cast<duration<float>>(renderTime - RenderManager::lastRenderTime);
  float frameTime = renderDuration.count();
  RenderManager::renderTime = RenderManager::renderTime * FPS_AVG_FACTOR_INV + frameTime * FPS_AVG_FACTOR;
  RenderManager::lastRenderTime = renderTime;
}

void RenderManager::renderInterface()
{
  InterfaceRender::renderInterface();
}
