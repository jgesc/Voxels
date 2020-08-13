#include "Graphics/GraphicsManager.hpp"
//#include "World/Chunk.hpp"

int main(void)
{
  GraphicsManager::initialize();
  //Chunk chunk;

  //chunk.initRender();
  while(!glfwWindowShouldClose(GraphicsManager::window))
  {
    //chunk.render();
    glfwSwapBuffers(GraphicsManager::window);
    glfwPollEvents();
  }


  GraphicsManager::terminate();
  return 0;
}
