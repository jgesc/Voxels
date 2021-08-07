#include "PlayerController.hpp"

// Set static constants
const glm::vec3 PlayerController::DEFAULT_PLAYER_GRAVITY = glm::vec3(0.0, -9.81, 0.0);
const glm::vec3 PlayerController::DEFAULT_PLAYER_CAMERA_OFFSET = glm::vec3(0.0, 1.8, 0.0);

PlayerController * PlayerController::instance = NULL;

PlayerController::PlayerController()
{
  PlayerController::instance = this;
}
