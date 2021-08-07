#include "Input.hpp"

glm::vec3 Input::movementVector = glm::vec3(0.0, 0.0, 0.0);
bool Input::sprint = false;
/*
void Input::keyboard_callback(GLFWwindow * window, int key, int scancode, int action, int mods)
{
  LOG("Key Event " << key << " code " << scancode << " action " << action << " mods " << mods);
}*/

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
  //glfwSetKeyCallback(GraphicsManager::window, Input::keyboard_callback);
}

void Input::inputLoop() // TODO: remove and relocate functionality
{
  movementVector = glm::vec3(0, 0, 0);

  GLFWwindow *window = GraphicsManager::window;
  Camera * cam = Camera::getInstance();

  sprint = glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS;
  if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
    movementVector += cam->getFront();
  if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
    movementVector -= cam->getFront();
  if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    movementVector -= glm::cross(cam->getFront(), glm::vec3(0, 1, 0));
  if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    movementVector += glm::cross(cam->getFront(), glm::vec3(0, 1, 0));
  if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
    movementVector -= glm::vec3(0, 1, 0);
  if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
    movementVector += glm::vec3(0, 1, 0);
  if(glm::any(glm::isnan(movementVector))) movementVector = glm::vec3(0, 0, 0);
}
