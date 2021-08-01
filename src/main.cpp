#include "Graphics/GraphicsManager.hpp"
#include "Graphics/Render/ChunkRender.hpp"
#include "Graphics/RenderManager.hpp"
#include "World/Chunk.hpp"
#include "Debugging/Logger.hpp"
#include "Graphics/Camera.hpp"
#include "World/Physics/Collision/Raycast.hpp"
#include "World/Physics/Collision/BlockCollision.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


#include <random>


static BlockCollision aimBlock;
static World world;
static Camera cam;

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
  static double lastx = 0;
  static double lasty = 0;

  float xoffset = xpos - lastx;
  float yoffset = lasty - ypos;
  lastx = xpos;
  lasty = ypos;

  float sensitivity = 0.1f;
  xoffset *= sensitivity;
  yoffset *= sensitivity;

  Camera::getInstance()->modifyPitchYaw(yoffset, xoffset);
}


int main(void)
{
  GraphicsManager::initialize();
  //Chunk chunk;
  //world.fetchChunk(0, 0, 0);
  for(int x = 0; x < 4; x++)
  {
    for(int y = 0; y < 4; y++)
    {
      for(int z = 0; z < 4; z++)
      {
        world.fetchChunk(x, y, z);
        RenderManager::registerChunk(world.getChunk(x, y, z));
      }
    }
  }

  world.setBlock(0, 0, 0, 1);
  for(int i = 0; i < 64 * 64; i++)
    world.setBlock(std::rand() % 64, std::rand() % 64, std::rand() % 64, 1 + std::rand() % 3);
  //ChunkRender cr(world.getChunk(0, 0, 0));
  // RenderManager::registerChunk(world.getChunk(0, 0, 0));
  float cameraSpeed = 0.01f;
  //Camera cam;
  cam.setProjectionMatrix(glm::perspective(glm::radians((float)85.0),
    (float)800 / (float)600, 0.1f, 100.0f));
  cam.setPos(glm::vec3(4, 2, 5));

  glfwSetInputMode(GraphicsManager::window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
  glfwSetCursorPosCallback(GraphicsManager::window, mouse_callback);

  while(!glfwWindowShouldClose(GraphicsManager::window))
  {
    glm::vec3 movementVector(0, 0, 0);

    GLFWwindow *window = GraphicsManager::window;
    const float cameraSpeed = 0.1f; // adjust accordingly
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
      movementVector += cameraSpeed * cam.getFront();
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
      movementVector -= cameraSpeed * cam.getFront();
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
      movementVector -= glm::normalize(glm::cross(cam.getFront(), glm::vec3(0, 1, 0))) * cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
      movementVector += glm::normalize(glm::cross(cam.getFront(), glm::vec3(0, 1, 0))) * cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
      movementVector -= glm::vec3(0, 1, 0) * cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
      movementVector += glm::vec3(0, 1, 0) * cameraSpeed;
    movementVector = glm::normalize(movementVector) * cameraSpeed;

    cam.traslate(movementVector);

    Raycast::intersectBlock(&world, cam.getPos(), cam.getFront(),
      5.0, &aimBlock);
    if(glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) && aimBlock.getIsSet())
    {
      LOG("Removing at"); LOG(aimBlock.getX()); LOG(aimBlock.getY()); LOG(aimBlock.getZ());
      aimBlock.getChunk()->setBlock(aimBlock.getX() % CHUNK_SIZE, aimBlock.getY() % CHUNK_SIZE, aimBlock.getZ() % CHUNK_SIZE, 0);
    }

    // ShaderStore::I->defaultShader.setMat4("view", cam.getViewMatrix());
    ShaderStore::I->chunkShader.setMat4("view", cam.getViewMatrix());


    glClearColor(0.2, 0.6, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    RenderManager::renderChunksWithCamera(NULL);

    glfwSwapBuffers(GraphicsManager::window);
    glfwPollEvents();
  }


  GraphicsManager::terminate();
  return 0;
}
