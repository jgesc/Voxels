#include "Graphics/GraphicsManager.hpp"
#include "Graphics/Render/ChunkRender.hpp"
#include "World/Chunk.hpp"
#include "Debugging/Logger.hpp"
#include "Graphics/Camera.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


#include <random>

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
  Chunk chunk;
  chunk.setBlock(0, 0, 0, 1);
  for(int i = 0; i < 16 * 16; i++)
    chunk.setBlock(std::rand() % 16, std::rand() % 16, std::rand() % 16, 1 + std::rand() % 3);
  ChunkRender cr(&chunk);


  float cameraSpeed = 0.01f;
  Camera cam;
  cam.setProjectionMatrix(glm::perspective(glm::radians((float)85.0),
    (float)800 / (float)600, 0.1f, 100.0f));
  // glm::mat4 view;
  // glm::vec3 cameraPos   = glm::vec3(0.0f, 0.0f,  0.0f);
  // glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
  // glm::vec3 cameraUp    = glm::vec3(0.0f, 1.0f,  0.0f);
  // glm::mat4 projection = glm::perspective(glm::radians((float)85.0), (float)800 / (float)600, 0.1f, 100.0f);
  // view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);

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

    //view = projection * glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
    ShaderStore::I->defaultShader.setMat4("view", cam.getViewMatrix());

    glClearColor(0.2, 0.6, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    cr.render();
    glfwSwapBuffers(GraphicsManager::window);
    glfwPollEvents();
  }


  GraphicsManager::terminate();
  return 0;
}
