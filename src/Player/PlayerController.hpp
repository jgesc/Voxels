#pragma once

#include <glm/glm.hpp>

#include "Input.hpp"

class PlayerController
{
private:
  static PlayerController * instance;
  glm::vec3 position;
  //glm::vec3 camOffset;

public:
  PlayerController();
  static const glm::vec3 DEFAULT_PLAYER_GRAVITY;
  static const glm::vec3 DEFAULT_PLAYER_CAMERA_OFFSET;

  void update();

  // Setters
  void setPos(glm::vec3 pos) {this->position = pos;}

  // Getters
  static PlayerController * getInstance() {return PlayerController::instance;}
  glm::vec3 getPos() {return this->position;}
  float getX() {return this->position.x;}
  float getY() {return this->position.y;}
  float getZ() {return this->position.z;}
  glm::vec3 getGravity() {return PlayerController::DEFAULT_PLAYER_GRAVITY;}
  glm::vec3 getCamOffset() {return PlayerController::DEFAULT_PLAYER_CAMERA_OFFSET;}
  glm::vec<3, int64_t> getChunk() {return glm::floor(this->position / 16.0f);} // TODO: use constants
  glm::vec<3, int64_t> getRegion() {return glm::floor(this->position / 256.0f);}


};
