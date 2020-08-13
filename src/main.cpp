#include "Graphics/GraphicsManager.hpp"
#include "Graphics/Render/ChunkRender.hpp"
#include "World/Chunk.hpp"
#include "Debugging/Logger.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

int main(void)
{
  GraphicsManager::initialize();
  Chunk chunk;
  chunk.setBlock(0, 0, 0, 1);
  ChunkRender cr(&chunk);

  LOG("TEST");

  float cameraSpeed = 0.01f;
  glm::mat4 view;
  glm::vec3 cameraPos   = glm::vec3(0.0f, 0.0f,  0.0f);
  glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
  glm::vec3 cameraUp    = glm::vec3(0.0f, 1.0f,  0.0f);
  view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);

  while(!glfwWindowShouldClose(GraphicsManager::window))
  {
    GLFWwindow *window = GraphicsManager::window;
    const float cameraSpeed = 0.05f; // adjust accordingly
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
      cameraPos += cameraSpeed * cameraFront;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
      cameraPos -= cameraSpeed * cameraFront;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
      cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
      cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
      if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
        cameraPos -= cameraUp * cameraSpeed;
      if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
        cameraPos += cameraUp * cameraSpeed;

    view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
    ShaderStore::I->defaultShader.setMat4("view", view);

    glClearColor(0.2, 0.6, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    cr.render();
    glfwSwapBuffers(GraphicsManager::window);
    glfwPollEvents();
  }


  GraphicsManager::terminate();
  return 0;
}
