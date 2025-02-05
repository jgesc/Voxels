#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "GraphicsManager.hpp"

#define MAX_PITCH 85.0f
#define MIN_PITCH -85.0f

class Camera
{
private:
  static Camera * instance;

  glm::vec3 pos;
  glm::vec3 front;
  glm::mat4 projection;
  float pitch, yaw;

  glm::mat4 view;

  float fov;
  float near, far;
  float ratio;
public:
  // Constructor
  Camera();

  // Utils
  glm::vec3 getFront() {return this->front;}
  static Camera * getInstance() {return Camera::instance;}

  // Pitch-Yaw
  void updateFrontVector();
  void setPitch(float newPitch) {this->pitch = newPitch; updateFrontVector();}
  void setYaw(float newYaw) {this->yaw = newYaw; updateFrontVector();}
  void modifyPitchYaw(float deltaPitch, float deltaYaw);
  inline float getPitch() {return this->pitch;}
  inline float getYaw() {return this->yaw;}

  // Position
  void setPos(glm::vec3 newPos) {pos = newPos; updateViewMatrix();}
  glm::vec3 getPos() {return this->pos;}
  void traslate(glm::vec3 deltaPos);

  // Projection
  void setProjectionMatrix(glm::mat4 newProj) {this->projection = newProj;
    this->updateViewMatrix();}
  glm::mat4 getProjectionMatrix() {return this->projection;}
  void setProjectionPerspective(float fov, float near, float far);

  // View
  void updateViewMatrix();
  glm::mat4 getViewMatrix() {return this->view;}

  // High level
  void setFOV(float fov) {this->setProjectionPerspective(fov, near, far);}
  void setNear(float near) {this->setProjectionPerspective(fov, near, far);}
  void setFar(float far) {this->setProjectionPerspective(fov, near, far);}
  void recalculateRatio();
  void recalculateProjectionPerspective();
};
