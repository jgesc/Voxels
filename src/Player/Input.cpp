#include "Input.hpp"

glm::vec3 Input::movementVector = glm::vec3(0.0, 0.0, 0.0);

void Input::callback(GLFWwindow * window, int key, int scancode, int action, int mods)
{
  LOG("Key Event " << key << " code " << scancode << " action " << action << " mods " << mods);
}

// TODO: make class method
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

void Input::registerInputCallbacks()
{
  glfwSetInputMode(GraphicsManager::window, GLFW_CURSOR, GLFW_CURSOR_DISABLED); // TODO: move
  glfwSetCursorPosCallback(GraphicsManager::window, mouse_callback);
  glfwSetKeyCallback(GraphicsManager::window, Input::callback); // TODO: set real keyboard callback
}

void Input::inputLoop() // TODO: remove and relocate functionality
{
  movementVector = glm::vec3(0, 0, 0);

  GLFWwindow *window = GraphicsManager::window;
  Camera * cam = Camera::getInstance();

  const float cameraSpeed = 0.1f * (1 + (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)*5); // adjust accordingly
  if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
    movementVector += cameraSpeed * cam->getFront();
  if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
    movementVector -= cameraSpeed * cam->getFront();
  if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    movementVector -= glm::normalize(glm::cross(cam->getFront(), glm::vec3(0, 1, 0))) * cameraSpeed;
  if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    movementVector += glm::normalize(glm::cross(cam->getFront(), glm::vec3(0, 1, 0))) * cameraSpeed;
  if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
    movementVector -= glm::vec3(0, 1, 0) * cameraSpeed;
  if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
    movementVector += glm::vec3(0, 1, 0) * cameraSpeed;
  movementVector = glm::normalize(movementVector) * cameraSpeed;
  if(glm::any(glm::isnan(movementVector))) movementVector = glm::vec3(0, 0, 0);
}
