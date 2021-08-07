#include "InterfaceRender.hpp"
Crosshair * InterfaceRender::crosshair = NULL;
InterfaceText * InterfaceRender::text = NULL;

#include "../RenderManager.hpp"
#include <stdio.h>

void InterfaceRender::renderInterface()
{
  if(!InterfaceRender::crosshair) InterfaceRender::crosshair = new Crosshair();
  InterfaceRender::crosshair->render();

  if(!InterfaceRender::text)
  {
    InterfaceRender::text = new InterfaceText(Text("This is a test text"));
  }
  char dbgstr[1024];
  PlayerController * ply = PlayerController::getInstance();
  glm::vec<3, int64_t> region = ply->getRegion();
  glm::vec<3, int64_t> chunk = ply->getChunk();
  glm::vec3 pos = ply->getPos();
  snprintf(dbgstr, 1024, "%.0f FPS\n\nRegion\n x: %d\n y: %d\n z: %d\n\nChunk\n x: %d\n y: %d\n z: %d\n\nBlock\n x: %.3f\n y: %.3f\n z: %.3f",
    RenderManager::getFPS(), region.x, region.y, region.z, chunk.x, chunk.y, chunk.z, pos.x, pos.y, pos.z);
  InterfaceRender::text->setText(dbgstr);
  InterfaceRender::text->render();
}
