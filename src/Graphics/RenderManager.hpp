#pragma once

#include "Interface/InterfaceRender.hpp"
#include "Render/ChunkRender.hpp"
#include "Camera.hpp"
#include "../World/Chunk.hpp"

#include <forward_list>
#include <chrono>

using namespace std::chrono;

#define FPS_AVG_FACTOR 0.1
#define FPS_AVG_FACTOR_INV (1-FPS_AVG_FACTOR)

class RenderManager
{
private:
  RenderManager();
  static std::forward_list<ChunkRender> chunkRenders;
  static float renderTime;
  static high_resolution_clock::time_point lastRenderTime;

public:
  // Keep track of chunks to render
  static void registerChunk(Chunk * chunk);
  static void unregisterChunk(Chunk * chunk);

  // Rendering utils
  static void renderChunksWithCamera(Camera * camera);
  static void renderInterface();

  static float getFPS() {return 1 / RenderManager::renderTime;}
};
