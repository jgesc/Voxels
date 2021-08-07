#pragma once

#include "../Graphics/Camera.hpp"
#include "../Graphics/GraphicsManager.hpp"


class Input
{
private:
  static glm::vec3 movementVector;
  static bool sprint;
public:
  static void registerInputCallbacks();
  static void inputLoop(); // TODO: substitute with callbacks
  static glm::vec3 getMovementInputVector() {return movementVector;}
  static bool getSprint() {return sprint;}
};
