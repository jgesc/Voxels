#include "PlayerController.hpp"

// Set static constants
const glm::vec3 PlayerController::DEFAULT_PLAYER_GRAVITY = glm::vec3(0.0, -9.81, 0.0);
const glm::vec3 PlayerController::DEFAULT_PLAYER_CAMERA_OFFSET = glm::vec3(0.0, 1.8, 0.0);

PlayerController * PlayerController::instance = NULL;

PlayerController::PlayerController()
{
  PlayerController::instance = this;
}

void PlayerController::traslate(glm::vec3 dPos)
{
  this->position += dPos;
}

void PlayerController::update()
{
  PROFILE_CPU(PlayerControllerUpdate);
  // Read movement input
  glm::vec3 inputVector = glm::normalize(Input::getMovementInputVector());
  if(glm::any(glm::isnan(inputVector))) inputVector = glm::vec3(0, 0, 0);
  inputVector *= Input::getSprint() ? 0.5 : 0.1;

  // Traslate
  this->traslate(inputVector);

  // Move camera
  Camera::getInstance()->setPos(this->position + getCamOffset());
}
