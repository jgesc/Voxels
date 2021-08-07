#include "Graphics/GraphicsManager.hpp"
#include "Graphics/Render/ChunkRender.hpp"
#include "Graphics/RenderManager.hpp"
#include "World/Chunk.hpp"
#include "Debugging/Logger.hpp"
#include "Graphics/Camera.hpp"
#include "World/Physics/Collision/Raycast.hpp"
#include "World/Physics/Collision/BlockCollision.hpp"
#include "Player/Input.hpp"
#include "Player/PlayerController.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <random>


static BlockCollision aimBlock;
static World world;
static Camera cam;


int main(void)
{
  /// Initialization

  GraphicsManager::initialize();

  /// Player setup
  PlayerController ply;
  ply.setPos(glm::vec3(17, 68, 17));

  // Manage input
  Input::registerInputCallbacks();

  /// Main loop

  glm::vec3 lastChunk = glm::vec3(-1, -1, -1);
  while(!glfwWindowShouldClose(GraphicsManager::window))
  {
    /// World generation

    glm::vec3 currentChunk = ply.getChunk();
    if(currentChunk != lastChunk) {
      lastChunk = currentChunk;
      LOG("$ Entering Chunk " << lastChunk.x << " " << lastChunk.y << " " << lastChunk.z);
      for(int x = lastChunk.x-1; x <= lastChunk.x+1; x++)
      {
        for(int y = lastChunk.y-1; y <= lastChunk.y+1; y++)
        {
          for(int z = lastChunk.z-1; z <= lastChunk.z+1; z++)
          {
            if(!world.getChunk(x, y, z))
            {
              world.fetchChunk(x, y, z);
              RenderManager::registerChunk(world.getChunk(x, y, z));
            }
          }
        }
      }
    }

    /// Controls
    Input::inputLoop();
    ply.update();

    // TODO: move
    Raycast::intersectBlock(&world, cam.getPos(), cam.getFront(),
      5.0, &aimBlock);
    if(glfwGetMouseButton(GraphicsManager::window, GLFW_MOUSE_BUTTON_LEFT) && aimBlock.getIsSet())
    {
      aimBlock.getChunk()->setBlock(
        aimBlock.getX(),
        aimBlock.getY(),
        aimBlock.getZ(),
        0);
      LOG("Removing Block (" << aimBlock.getX() << ", " << aimBlock.getY() << ", " << aimBlock.getZ() << ")");
    }


    /// Render
    RenderManager::renderAll();
    glfwPollEvents();
  }

  /// Cleanup

  GraphicsManager::terminate();
  return 0;
}
