#include "InterfaceRender.hpp"
Crosshair * InterfaceRender::crosshair = NULL;
void InterfaceRender::renderInterface()
{
  if(!InterfaceRender::crosshair) InterfaceRender::crosshair = new Crosshair();
  InterfaceRender::crosshair->render();
}
