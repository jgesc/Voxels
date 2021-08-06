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
  snprintf(dbgstr, 1024, "%.0f FPS\n\nRegion\n x: %d\n y: %d\n z: %d\n\nChunk\n x: %d\n y: %d\n z: %d\n\nBlock\n x: %d\n y: %d\n z: %d",
    RenderManager::getFPS(), 1, 2, 3, 1, 2, 3, 1, 2, 3);
  InterfaceRender::text->setText(dbgstr);
  InterfaceRender::text->render();
}
