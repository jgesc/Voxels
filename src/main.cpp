#include "Graphics/GraphicsManager.hpp"
#include "Graphics/Render/ChunkRender.hpp"
#include "World/Chunk.hpp"

int main(void)
{
  GraphicsManager::initialize();
  Chunk chunk;
  chunk.setBlock(0, 0, 0, 1);
  ChunkRender cr(&chunk);

  while(!glfwWindowShouldClose(GraphicsManager::window))
  {
    cr.render();
    glfwSwapBuffers(GraphicsManager::window);
    glfwPollEvents();
  }


  GraphicsManager::terminate();
  return 0;
}
