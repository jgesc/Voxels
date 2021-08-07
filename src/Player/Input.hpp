#pragma once

#include "../Graphics/Camera.hpp"
#include "../Graphics/GraphicsManager.hpp"


class Input
{
private:
  static glm::vec3 movementVector;
  static void callback(GLFWwindow * window, int key, int scancode, int action, int mods);
public:
  static void registerInputCallbacks();
  static void inputLoop(); // TODO: substitute with callbacks
  static glm::vec3 getMovementInputVector() {return movementVector;};
};
