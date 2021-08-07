#include "Camera.hpp"

Camera * Camera::instance = NULL;

Camera::Camera()
{
  this->instance = this;
  this->front = glm::vec3(0, 0, -1);
  this->yaw = -90.0f;
  this->pitch = 0.0f;

  this->setProjectionPerspective(85.0, 0.1f, 100.0f);
}

void Camera::updateViewMatrix()
{
  this->view = this->projection * glm::lookAt(this->pos,
    this->pos + this->front, glm::vec3(0, 1, 0));
}

void Camera::updateFrontVector()
{
  glm::vec3 direction;
  direction.x = cos(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));
  direction.y = sin(glm::radians(this->pitch));
  direction.z = sin(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));
  this->front = glm::normalize(direction);
}

void Camera::modifyPitchYaw(float deltaPitch, float deltaYaw)
{
  // Increase
  this->pitch += deltaPitch;
  this->yaw += deltaYaw;

  // Clamp
  if(this->pitch > MAX_PITCH)
    this->pitch = MAX_PITCH;
  else
    if(this->pitch < MIN_PITCH)
      this->pitch = MIN_PITCH;

  // Update front vector
  this->updateFrontVector();
  this->updateViewMatrix();
}

void Camera::traslate(glm::vec3 deltaPos)
{
  if(glm::any(glm::isnan(deltaPos))) return;
  pos += deltaPos; this->updateViewMatrix();
}

void Camera::setProjectionPerspective(float fov, float near, float far)
{
  this->fov = fov;
  this->near = near;
  this->far = far;
  this->recalculateProjectionPerspective();
}

void Camera::recalculateRatio()
{
  this->ratio = GraphicsManager::getWindowWidth() / GraphicsManager::getWindowHeight();
}

void Camera::recalculateProjectionPerspective()
{
  this->recalculateRatio();
  this->setProjectionMatrix(glm::perspective(glm::radians(fov), ratio, near, far));
}
