#pragma once

#include "Interface/InterfaceRender.hpp"
#include "Render/ChunkRender.hpp"
#include "Camera.hpp"
#include "../World/Chunk.hpp"

#include <forward_list>

class RenderManager
{
private:
  RenderManager();
  static std::forward_list<ChunkRender> chunkRenders;
public:
  // Keep track of chunks to render
  static void registerChunk(Chunk * chunk);
  static void unregisterChunk(Chunk * chunk);

  // Rendering utils
  static void renderChunksWithCamera(Camera * camera);
  static void renderInterface();
};
